#include "appli.h"

//Constructeur
CIhm::CIhm(){}

//Constructeur
CIhm::CIhm(int port_pltxa, int port_on_off, int port_user)
{
	m_chx_plantxa.Init(port_pltxa,4.0);
	m_chx_user.Init(port_user, 0);
	m_on_off.Init(port_on_off, 0);
	m_num_plantxa = 0;
	m_num_user = 0;
	m_matrice.Affiche(0);
}

//Initialisation entrée
void CIhm::Init()
{
	m_num_plantxa = 0;
	m_num_user = 0;
}

int CIhm::GetCredit()
{
	return m_credit_temps;
}

//Contrôle identification déjà réalisée => id >0
	//retourne faux si identification réalisée
//Tant que pas de pression sur BP USER 
	//On peut sélectionner la plantxa en déplaçant le sélecteur
	//Affiche m_num_plantxa 
	//Mise à jour m_num_plantxa
//Tant que pas de pression sur BP ON/OFF
	//On sélectionne l'utilisateur par pressions successives
	//Contrôle num >10
	//Affiche m_num_user 
	//Mise à jour m_num_user
//Retourne vrai 
bool CIhm::MajIdentifiants()
{
	//Identification déjà réalisée
	if(m_num_user) return false;
	//Tant que pas de pression sur BP USER 
	while(m_chx_user.GetOn())
	{
		//On peut sélectionner la plantxa en déplaçant le potentiomètre
		//Mise à jour m_num_plantxa
		if (m_num_plantxa != m_chx_plantxa.GetValeur(1))
		{
			m_num_plantxa = m_chx_plantxa.GetValeur(1);
			Serial.print("plantxa:");
			m_matrice.Affiche(m_num_plantxa);
		}
	}
	Serial.print("user:");
	m_matrice.Affiche(m_num_user);
	//Tant que pas de pression sur BP ON/OFF
	while(m_on_off.GetOn())
	{
		//On sélectionne l'utilisateur par pressions successives
		if(!m_chx_user.GetOn())
		{
			//Mise à jour m_num_user
			m_num_user++;
			if(m_num_user>10) m_num_user=1;
			Serial.print("user :");	
			m_matrice.Affiche(m_num_user);
		}
	}
	//Demande crédit temps par Get http
	String url = CLIENTHTTP;
	url += String(m_num_user);
	String info = m_clientHttp.Get(url);
	m_credit_temps = GetInt2txt(info, "Time\":", 2);
	Serial.print("Crédit : ");
	Serial.println(m_credit_temps);
	if(m_credit_temps)	m_depart = true;
	return true;
}

bool CIhm::GetDepart()
{
	if(m_depart) 
	{	
		m_depart = false;
		Serial.print("Crédit : ");
		m_matrice.Affiche(m_credit_temps);
		return true;
	}
	if(m_credit_temps) 
	{
		Serial.print("Crédit : ");
		m_matrice.Affiche(--m_credit_temps);
	}
	return m_depart;
}

void CIhm::GetStop()
{
	if(!m_num_user) return;
	if(!m_credit_temps || !m_on_off.GetOn())
	{	
		//Envoi PUT(crédit & user)
		//Envoi crédit par Put http
		String requete = "{\"remainingTime\":";
		requete += String(m_credit_temps);
		requete += "}";
		String reponse = m_clientHttp.Put(m_num_user, requete);
		Serial.print("Réponse Put : ");
		Serial.println(reponse);
		
		//Mettre le numéro de plantxa, le numéro d'utilisateur,
		//le crédit temps à 0
		//Désdactiver le relais
		m_num_plantxa = m_num_user = m_credit_temps = 0;
		digitalWrite(D1, LOW);

	}
}

void CIhm::ActivationRelais()
{
	if (m_credit_temps)
		digitalWrite(D1, HIGH);
	
	else
		digitalWrite(D1, LOW);
	
	if (!m_credit_temps || !m_on_off.GetOn())
		digitalWrite(D1, LOW);
}



