#include <iostream>
#include <string>

#include "Produit.h"

using namespace std;

Produit::Produit() : m_nom(""),m_marque("")
{

}

Produit::Produit(string c,int nb) : m_nom(""),m_marque("")
{

}

void Produit::afficher()
{
    cout << "Donnez le nom du produit : " << endl;
    //cin >> m_nom >> endl;
    getline(cin,m_nom);
    cout << "Donnez le nombre de produit : " << endl;
    //cin >> m_marque >> endl;
    getline(cin,m_marque);


    cout << "---Resume de la commande---" << endl;
    cout << " " << endl;
    cout << "Nom : " << m_nom << endl;
    cout << "Marque : " << m_marque << endl;




}









