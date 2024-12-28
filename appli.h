#ifndef APPLI
#define APPLI

#define VERSION 		"PLANTXA.VERSION.FINAL"
#include <Arduino.h>

//Pour CWifi
#include "wifi.h"
//Pour CMatrice
#include "matrice.h"
//Pour CEntree
#include "entree.h"
//Pour CIhm
#include "ihm.h"

//IHM
#define PORT_PLANTXA	A0
#define PORT_USER		D3
#define PORT_ON_OFF		D4

//WIFI 
#define RESEAU_WIFI		"SNIR"
#define CLEF_WIFI		"bts-snir" 
#define PREFIXE_ID 		"ESP8266Client-" 
#define PIN_RELAIS 		D1

//Fonctions accessibles
int GetInt2txt(String& texte, String extract, int nb_digit);

class CAppli
{
	private:
		CIhm		m_ihm{PORT_PLANTXA, PORT_ON_OFF, PORT_USER};
		CWifi 		m_reseau_wifi{RESEAU_WIFI, CLEF_WIFI};	
		CHttpReq	m_clientHttp;
		long 		m_instant_run=0;
		bool 		m_old_etat;

	public:
		CAppli(){};
		~CAppli(){};
		
		void Init();
		void RunIhm();
		void RunProcess(int delai);
};

#endif
