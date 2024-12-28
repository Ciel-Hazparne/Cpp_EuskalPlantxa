#ifndef CENTREE
#define CENTREE

//Déclaration de la classe CEntree générique.
class CEntree
{
	//Données membres et fonctions privées accessibles seulement via des fonctions publiques
    private:
		////////////////////////
		//Butée analogique
		float 	m_val_max; 	
		
    protected:
		////////////////////////
		//Port de lecture
		int 	m_port;
		
	//Données membres et fonctions publiques
	public:
		////////////////////////
		//Constructeur d'une entrée par défaut
		CEntree();
		//Initialisation d'une entrée avec butée max
		void Init(int port, float val_max);
		//Obtention valeur selon butée
		float GetValeur();
		//Obtention d'une valeur entière
		int GetValeur(int nb_index, bool index0);
		//Obtention état logique
		bool GetOn();
		//Valeur entière
		int GetValeur(int val_prem);
		int ArrondiSup(float nombre);
};
#endif
