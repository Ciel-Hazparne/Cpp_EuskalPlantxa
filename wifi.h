#ifndef WIFI
#define WIFI

//Pour la connexion WIFI : Objet : Wifi
#include <ESP8266WiFi.h>

class CWifi: public ESP8266WiFiClass 
{
	private:
	public:
		CWifi(	String reseau_wifi, 
				String clef_wifi		);
		~CWifi(){};
		
	void Connexion(int delai_reconnexion); 
};

#endif
