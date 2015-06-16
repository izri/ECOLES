#ifndef PRODUIT_H
#define PRODUIT_H

#include "resto.h"

using namespace std;

class Produit : public Printable
{

public :

    string nom;
    float prix;

    Product(const string nom, const float prix);
    const string get_nom();
    const float get_prix();
    const string to_string(float prix);
    void affichage();

};



class Pizza : public Produit
{
prive :
    string nomPizza;
    float prixPizza;

public :
    Pizza(const string nomPizza, const float prixPizza);
};

class PDJ : public Produit
{
prive :
    string nomPdj;
    float prixPdj;

public :
    PDJ(const string nomPdj, const float prixPdj);
};

class PV : public Produit
{
prive :
    string nomPv;
    float prixPv;

public :
    PV(const string nomPv, const float prixPv);
};

class Dessert : public Produit
{
prive :
    string nomDessert;
    float prixDessert;

public :
    Dessert(const string nomDessert, const float prixDessert);
};

class Boisson : public Produit
{
prive :
    string nomBoisson;
    float prixBoisson;

public :
    Boisson(const string nomBoisson, const float prixBoisson);
};

#endif // PRODUIT_H  
