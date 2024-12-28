#ifndef HTTP
#define HTTP

//Pour la classe HTTPClient
#include <ESP8266HTTPClient.h>

class CHttpReq : public HTTPClient    
{
	private :
		WiFiClient m_clientWifi;
		String m_serveur;
		unsigned long m_top_envoi = millis();
	public :
		CHttpReq(){};  
		CHttpReq(String serveur){m_serveur=serveur;};  
		void requetePOST(String requete, String serveur);
		String requetePOST(String requete, unsigned long intervalle);
		String Get(String url);
		String Put(String url, String requete);
		String Put(int user, String requete); 
};

#endif
