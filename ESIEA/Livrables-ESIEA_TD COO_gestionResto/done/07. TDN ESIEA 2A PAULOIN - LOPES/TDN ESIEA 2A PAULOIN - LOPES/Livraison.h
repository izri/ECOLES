#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <iostream>
#include <string>

using namespace std;

class Livraison{

    //attributs

    string Number;
    string StreetName;
    string CityName;
    int NumberCommande;

    //Constructeurs
    public:
    Livraison();

    //Methodes
    int nbCommande();
    void affichage();
    /*string getNumber();
    string getStreetName();
    string getCityName();
    void setNumber(string c);
    void setStreetName(string c);
    void setCityName(string c);*/
};

#endif // LIVRAISON_H
