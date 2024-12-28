#include "appli.h"

//Constructeur d'un objet entrée
CEntree::CEntree(){}

//Initialisation entrée
void CEntree::Init(int port, float val_max)
{
	m_port 	= port;
	m_val_max = val_max;
	pinMode(m_port, INPUT);
}

//Obtention valeur selon butée
//lecture entrée en 0pt=>0.0 & 1023pts=>butée
float CEntree::GetValeur()
{
	return (m_val_max * analogRead(m_port)/1023.0);
}

//Obtention état logique
bool CEntree::GetOn()
{
	bool val =  digitalRead(m_port);
	delay(100);
	return val;
}

int CEntree::GetValeur(int val_prem)
{
	return ArrondiSup(GetValeur())+ val_prem;
}

int CEntree::ArrondiSup(float nombre) 
{
	return (int)nombre + (int)(nombre-(int)nombre>0.5); 
}
