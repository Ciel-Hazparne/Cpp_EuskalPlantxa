#ifndef MATRICE_H
#define MATRICE_H

//Pour l'afficheur matrice 16x16
//https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library
#include <WEMOS_Matrix_LED.h>

class  CMatrice : public MLED		//Classe matrice heritière MLED
{
public :

	CMatrice();									//Constructeur
	~CMatrice();								//Destructeur
	void Affiche (int num, bool unit);			//Fonction Affiche
	void Affiche (int num);						//Surcharge de la fonction Affiche
};
#endif
