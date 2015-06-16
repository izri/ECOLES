#include "Commande.h"

using namespace std;

Commande::Commande(std::string NomProduit,int PopulariteProduit,int prixProduit):m_NomClient("Mr le Client"),m_produit(NomProduit,prixProduit,PopulariteProduit),m_prixCommande(0);
{

}

int Commande::getPrixCommande() const
{
    return m_prixCommande;
}

void Commande::Ajout_Commande(std::string NomClient,std::string NomProduit,int PopulariteProduit,int prixProduit, int prixCommande)
{
    m_NomClient=NomClient;
    m_Produit.ajoutProduit(NomProduit,PrixProduit,Popularite+1)
    m_prixCommande=prixCommande+PrixProduit;
}

void affich() const
{
    cout << "Mr " << m_NomClient <<" a commande: "<< endl;
    count << m_Produit.getNomProduit() << " valant: " << m_Produit.getPrixProduit << endl;
    count << "Pour un total d'une commande a : " << m_prixCommande<<endl;
}
