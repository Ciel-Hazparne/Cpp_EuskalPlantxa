#include "appli.h"

void CHttpReq::requetePOST(String requete, String serveur)
{
	Serial.print("URL: "); 
	Serial.println(serveur);

	addHeader("Content-Type", "application/json");
	if(!begin(m_clientWifi, serveur))
		Serial.print("ECHEC DE LA CONNEXION REST");

	int httpCode = POST(requete);
	Serial.print("CODE HTTP REPONSE : "); 
	Serial.println(httpCode);

	if (httpCode == HTTP_CODE_OK) 
	{
		Serial.println(getString());    
		Serial.println("OK");
	}
	end();
}

String CHttpReq::requetePOST(String requete, unsigned long intervalle)
{
	if(millis()>m_top_envoi) m_top_envoi+= intervalle;
	else return "";
	String recu;
	
	Serial.print("URL: "); 
	Serial.println(m_serveur);

	addHeader("Content-Type", "application/json");
	if(!begin(m_clientWifi, m_serveur))
		Serial.print("ECHEC DE LA CONNEXION REST");

	int httpCode = POST(requete);
	Serial.print("CODE HTTP REPONSE : "); 
	Serial.println(httpCode);

	if (httpCode == HTTP_CODE_OK) 
	{
		recu = getString();
		Serial.println(recu);    
		Serial.println("OK");
	}
	end();
	recu += "\n";
	return recu;
}

//Inspiré de :
//https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient/examples/BasicHttpClient
String CHttpReq::Get(String url)
{
	String reponse = "";

	if (begin(m_clientWifi, url)) 
	{  	
		//Initialise la connexion HTTP avec l'URL spécifiée
		//Affiche un message de requête GET
		Serial.printf("GET1"); 

		//Démarre la connexion et envoie l'en-tête HTTP
		int httpCode = GET();

		// httpCode sera négatif en cas d'erreur
		if (httpCode > 0) 
		{
			// L'en-tête HTTP a été envoyé et la réponse du serveur a été gérée
			Serial.printf("GET Code: %d\n", httpCode);

			// Fichier trouvé sur le serveur
			if (httpCode == HTTP_CODE_OK || 
				httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
			{
				// Récupère la réponse HTTP sous forme de chaîne de caractères
				reponse = getString();
				// Affiche la réponse 
				Serial.println(reponse); 
			}
		} 
		// Affiche le message d'erreur correspondant au code d'erreur
		else Serial.printf(	"GET ko: %s\n", 
							errorToString(httpCode).c_str()); 
		// Ferme la connexion HTTP
		end(); 
	} 
	// Affiche un message d'erreur si la connexion n'a pas pu être établie
	else 		Serial.printf("GET begin KO!"); 
	//Renvoi la réponse
	return reponse;
}


String CHttpReq::Put(String url, String requete)
{
	String reponse = "";
	begin(m_clientWifi, url);
	addHeader("Content-Type", "application/json");            

	int code_reponse = PUT(requete);   

	if(code_reponse>0)
	{
		reponse = getString();   
		Serial.println(reponse);          
	}
	else
	{
		Serial.print("Échec:");
		Serial.println(code_reponse);
	}
	end();
	return reponse;
}

String CHttpReq::Put(int user, String requete)
{
	String reponse = "";
	begin(m_clientWifi, m_serveur + String(user));
	addHeader("Content-Type", "application/json");            

	int code_reponse = PUT(requete);   

	if(code_reponse>0)
	{
		reponse = getString();   
		Serial.println(reponse);          
	}
	else
	{
		Serial.print("Échec:");
		Serial.println(code_reponse);
	}
	end();
	return reponse;
}
