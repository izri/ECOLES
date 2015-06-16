#ifndef COMMANDE_h
#define COMMANDE_h
#include <string>
#include <iostream>

using namespace std;

class Commande {
    //attributs
    string nomClient;
    unsigned int qteRepas[5];
    unsigned int prix[5];


    //constructeurs
    public:
    Commande();
    Commande(string c);
    //méthodes
    void affichage();
    void affichageCarte();
    void ajoutQte(unsigned int a, unsigned int b);
    void ajout(unsigned int a, unsigned int b);
    unsigned int prixTotal();
};
#endif
