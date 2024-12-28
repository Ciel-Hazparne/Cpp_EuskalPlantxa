#ifndef IHM
#define IHM

//Pour HttpReq
#include "httpReq.h"
#include <Arduino.h>

#define CLIENTHTTP 		"http://10.0.102.250/api/users/"

//Déclaration de la classe CIhm
class CIhm
{
	//Données membres et fonctions privées accessibles seulement via des fonctions publiques
    private:
		////////////////////////
		CMatrice  	m_matrice;
		CEntree   	m_chx_plantxa;
		CEntree   	m_chx_user;
		CEntree   	m_on_off;
		int   		m_num_user=0;
		int   		m_num_plantxa=0;
		int			m_credit_temps=0;
		CHttpReq 	m_clientHttp {CLIENTHTTP};	
		bool 		m_depart = false;
		
    protected:
		////////////////////////
		//
		
	//Données membres et fonctions publiques
	public:
		////////////////////////
		//Constructeur par défaut
		CIhm();
		CIhm(int port_pltxa, int port_on_off, int port_user);
		//Initialisation d'une CIhm
		void Init();
		//Procédure de relevé des identifiants
		//Retourne vrai si les identifiants sont différents de 0
		//Pour les renvoyer vers le serveur
		bool MajIdentifiants();
		int GetIdUser();
		int GetIdPlantxa();
		int GetCredit();
		bool GetDepart();
		void GetStop();
		void ActivationRelais();
		
};
#endif
