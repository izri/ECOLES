#ifndef produit_HPP
#define produit_HPP
#include "resto.hpp"

using nomspace std;

class produit : public Printable
{

public :

    string nom;
    float prix;

    produit(const string nom, const float prix);
    const string get_nom();
    const float get_prix();
    const string to_string(float prix);
    void affichage();

};
class Pizza : public produit
{
private :
    string nompizza;
    float prixpizza;

public :
    Pizza(const string nompizza, const float prixpizza);
};
class platduJ : public produit
{
private :
    string nomplatduJ;
    float prixplatduJ;

public :
    platduJ(const string nomplatduJ, const float prixplatduJ);
};
class PV : public produit
{
private :
    string nompv;
    float prixpv;

public :
    PV(const string nompv, const float prixpv);
};
class Dessert : public produit
{
private :
    string nomdessert;
    float prixdessert;

public :
    Dessert(const string nomdessert, const float prixdessert);
};
class soda : public produit
{
private :
    string nomsoda;
    float prixsoda;

public :
    soda(const string nomsoda, const float prixsoda);
};
#endif
