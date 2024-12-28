#include "appli.h"

CMatrice::CMatrice(){}//Constructeur
CMatrice::~CMatrice(){}//Destructeur
	
void CMatrice::Affiche (int num, bool unit)			//Fonction Affiche
{ 
	if (unit) 	num=num%10;//Calcul unité
	else 		num=num/10;//calcul dizaine
	int decal=unit*4;//Décalage 

	switch (num)
	{
		case 0:
			disBuffer[0+decal]=0xFF;								//Affichage 0 + décalage
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=129;
		break;

		case 1:	//Affichage 1 + décalage
			disBuffer[0+decal]=0;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=0;
		break;

		case 2://Affichage 2 + décalage
			disBuffer[0+decal]=0xF0;
			disBuffer[3+decal]=0x0F;
			disBuffer[1+decal]=disBuffer[2+decal]=137;
		break; 

		case 3://Affichage 3 + décalage
			disBuffer[0+decal]=0;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=137;   
		break;

		case 4://Affichage 4 + décalage
			disBuffer[0+decal]=0x0F;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=8;
		break;

		case 5://Affichage 5 + décalage
			disBuffer[0+decal]=0x0F;
			disBuffer[3+decal]=0xF0;
			disBuffer[1+decal]=disBuffer[2+decal]=137;
		break;

		case 6://Affichage 6 + décalage
			disBuffer[0+decal]=0xFF;
			disBuffer[3+decal]=0xF0;
			disBuffer[1+decal]=disBuffer[2+decal]=137;
		break;

		case 7://Affichage 7 + décalage
			disBuffer[0+decal]=0;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=1;
		break;

		case 8://Affichage 8 + décalage
			disBuffer[0+decal]=0xFF;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=137;
		break;

		case 9://Affichage 9 + décalage
			disBuffer[0+decal]=0x0F;
			disBuffer[3+decal]=0xFF;
			disBuffer[1+decal]=disBuffer[2+decal]=137;
		break;
	}
}

void CMatrice::Affiche(int num)
{
	Affiche (num, true);
	Affiche(num, false);
	Serial.println(num);	
	display();//Affichage
}
