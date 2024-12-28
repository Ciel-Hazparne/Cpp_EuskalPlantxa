#include "appli.h"
               
CWifi::CWifi(	String	reseau_wifi,
				String	clef_wifi	)
{                                             
	mode(WIFI_STA);
	begin(reseau_wifi.c_str(), clef_wifi.c_str());
}

void CWifi::Connexion(int delai_reconnexion)
{
	while (status() != WL_CONNECTED) 
	{
		Serial.print("Attente connexion Wifi : ");
		Serial.println(SSID());
		delay(delai_reconnexion);
	}
	Serial.print("Connecté à :");
	Serial.print(SSID());
	Serial.print(" - @:");
	Serial.println(localIP());
	Serial.print(" - Signal :");
	Serial.print(RSSI());
	Serial.println("(dBm)");
}
