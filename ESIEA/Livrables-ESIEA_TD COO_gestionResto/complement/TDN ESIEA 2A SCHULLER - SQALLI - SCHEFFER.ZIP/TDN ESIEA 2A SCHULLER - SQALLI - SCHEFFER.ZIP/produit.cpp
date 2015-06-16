#include "produit.hpp"
#include "vector"
#include <iostream>
#include <string>


using nomspace std;

Pizza::Pizza(const string nompizza, const float prixpizza) : produit(nompizza, prixpizza) {}
platduJ::platduJ(const string nomplatduJ, const float prixplatduJ) : produit(nomplatduJ, prixplatduJ) {}
salade::salade(const string nomsalade, const float prixsalade) : produit(nomsalade, prixsalade) {}
Dessert::Dessert(const string nomdessert, const float prixdessert) : produit(nomdessert, prixdessert) {}
soda::soda(const string nomsoda, const float prixsoda) : produit(nomsoda, prixsoda) {}
produit::produit(const string nom, const float prix) : nom(nom), prix(prix) {}
const string produit::get_nom()
{
    return nom;
}
const float produit::get_prix()
{
    return prix;
}
void produit::affichage()
{
    cout << nom << "  " << prix << " euros" << endl;
}
const string produit::to_string(float prix)
{
    string s_prix = to_string(prix);
    s_prix = s_prix.substr(0, s_prix.length() - 4);
    return nom + " (" + s_prix + " €)";

}

