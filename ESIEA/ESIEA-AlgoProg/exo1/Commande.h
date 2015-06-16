#ifndef COMMANDE_H
#define COMMANDE_H
#include <iostream>
#include <string>

using namespace std;

class Commande{
 public : //modificateur
    //attributs
    string nomClient;
    unsigned int prix[5]={7,8,9,10,11};
    unsigned int qteRepas[5]={0,0,0,0,0};
    //constructeurs
    Commande(); //par défaut
    Commande(string c);

    //méthodes
    void afficher();
    unsigned int prixTotal();
    //setters
    void ajoutPizza(unsigned int p);
    void ajoutPJ(unsigned int p);
    void ajoutDessert(unsigned int p);
    void ajoutBoisson(unsigned int p);
    void ajoutRV(unsigned int p);

    //setter NOM
    void setNomClient(string c);
    //Getter Nom
    string getNomClient();
};
#endif
