#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>
#include <string>
#include "commande.hpp"

using namespace std;

class client{

    private :
        string cl_nom;
        commande* cl_commande;
        
        client* cl_suivant;

    public :
        client(const string cl_nom);
        ~client();
        void ajouterCommande(commande Comm);
        int prixTotalClient();
        void afficherListeCommande();
        void nouveauClient(string nom);
        bool recherchClient(string nom);
        /*

        client revoiClient(string nom);
        client dernierClient();
        client cl_avancer();
        */
        client* cl_avancer();
        client* revoiClient(string nom);
        client* dernierClient();
        //void changerClient();
        //client* recherchClient(string nom);
    
};
#endif