#include "Produit.h"

using namespace std;

Produit::Produit()
{
    m_NomProduit="Produit";
    m_prixProduit=0;
    m_Popularite=0;
}

string Produit::getNomProduit() const
{
    return m_NomProduit;
}

int Produit::getprixProduit() const
{
    return m_prixProduit;
}

int Produit::getPopularite() const
{
    return m_Popularite;
}

void Produit::ajoutProduit(std::string NomProduit,int prixProduit,int Popularite)
{
    m_NomProduit=NomProduit
    m_prixProduit=prixProduit;
    m_Popularite=Popularite;

}

void Produit::afficher() const
{
    cout << "Produit : " << m_NomProduit << " (Prix : " << m_prixProduit << " ,Popularite : " << m_Popularite << ")" << endl;
}
