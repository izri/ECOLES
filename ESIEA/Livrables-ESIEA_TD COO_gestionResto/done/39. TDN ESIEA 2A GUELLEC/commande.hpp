#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#include <iostream>
#include <string>
#include "produit.hpp"

using namespace std;

class commande{

    private :
        int c_quantite;
        produit c_conso;
        
        commande* c_suivante;
        //int c_prix;
    public :

		commande(produit c_conso, int c_quantite);
		int prixTotal();
        void afficher();
        commande* avancer();
        void nouvelleCommande(produit conso, int quantite);
        produit getConso();
        int getQuantite();
        commande* retournerCommande();

    

};





#endif // COMMANDE_H_INCLUDED
