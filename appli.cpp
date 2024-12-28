#include "appli.h"

void CAppli::Init()
{
	Serial.begin(115200);
	while (!Serial);
	delay(500);
	Serial.println(VERSION);
	m_ihm.Init();
	//Pour tirage aléatoire
	randomSeed(micros());
	//Connexion Wifi
	m_reseau_wifi.Connexion(2000);
	//Pour le relais
	pinMode(D1, OUTPUT);

}
  
void CAppli::RunProcess(int delai)
{
	if (millis() > m_instant_run ) 
	{
		m_instant_run += delai;
		//Ajout de(s) fonction(s)
		//Au départ on initialise le process
		if (m_ihm.GetDepart())
		{
			m_instant_run = millis() + delai;
			m_ihm.ActivationRelais();
		}
		
	}
	
}

void CAppli::RunIhm()
{
	m_ihm.MajIdentifiants();
	m_ihm.GetStop();
}

//Fonction pour extraire un nombre de chiffres: 'nb_digit'
//depuis une chaîne de caractères: 'texte'
//Juste après une chaîne donnée: 'extract'
//Les chiffres sont convertis et retournés en entier 
int GetInt2txt(String& texte, String extract, int nb_digit)
{
	int index = texte.indexOf(extract);
	index += extract.length();
	String resultxt = texte.substring(index, index+nb_digit);
	return resultxt.toInt();
}
