#include <iostream>
#include <string>
#include "produit.hpp"
using namespace std;

produit::produit(string nom, int prix):p_nom(nom),p_prix(prix){}

void produit::afficherdetailles(){
cout<<"nom du produit : "<<p_nom<<"  prix : "<<p_prix<<"euros"<<endl;

}
void produit::afficher(){
cout<<p_nom<<endl;

}

int produit::getPrix(){
return p_prix;
}
