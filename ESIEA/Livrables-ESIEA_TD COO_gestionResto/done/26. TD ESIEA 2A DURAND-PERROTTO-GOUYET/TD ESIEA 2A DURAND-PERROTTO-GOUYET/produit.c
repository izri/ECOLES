#include "produit.h"
#include "vector"
#include <iostream>
#include <string>


using namespace std;

Produit::Produit(const string nom, const float prix) : nom(nom), prix(prix) {}
const string Produit::get_nom()
{
    return nom;
}
const float Produit::get_prix()
{
    return prix;
}
void Produit::affichage()
{
    cout << nom << "  " << prix << " euros" << endl;
}
const string Produit::to_string(float prix)
{
    string s_prix = to_string(prix);
    s_prix = s_prix.substr(0, s_prix.length() - 4);
    return nom + " (" + s_prix + " €)";

}







Pizza::Pizza(const string nomPizza, const float prixPizza) : Produit(nomPizza, prixPizza) {}
PDJ::PDJ(const string nomPdj, const float prixPdj) : Produit(namePdj, prixPdj) {}
PV::PV(const string nomPv, const float prixPv) : Produit(nomPv, prixPv) {}
Dessert::Dessert(const string nomDessert, const float prixDessert) : Produit(nomDessert, prixDessert) {}
Boisson::Boisson(const string nomBoisson, const float prixBoisson) : Produit(nomBoisson, prixBoisson) {}


