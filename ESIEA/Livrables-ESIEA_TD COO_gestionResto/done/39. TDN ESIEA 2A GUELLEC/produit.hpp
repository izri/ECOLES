#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class produit{

	private :
		string p_nom;
		int p_prix;
	
	public :
		produit(string nom, int prix);
        void afficher();
        void afficherdetailles();
        int getPrix();

    
};


#endif // PRODUIT_H_INCLUDED
