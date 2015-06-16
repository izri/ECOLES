#include "produit.h"

using namespace std;

Produit::Produit(string name,float price) :m_nom(name),m_prix(price){
}

const string Produit::get_name() {
    return m_nom;
}

const float Produit::get_price() {
    return m_prix;
}

void Produit::afficher(){

    cout << "Vous avez commande un(e) : " << m_nom << " cela coute : " << m_prix << "euros" << endl;
}
