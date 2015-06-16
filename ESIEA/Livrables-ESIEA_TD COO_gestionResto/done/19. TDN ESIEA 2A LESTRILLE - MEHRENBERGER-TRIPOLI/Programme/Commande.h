#ifndef DEF_COMMANDE
#define DEF_COMMANDE

#include <iostream>
#include <string>
#include "Produit.h"

class Commande
{
    public:

    Commande(std::string NomProduit,int prixProduit,int Popularite);
    int getPrixCommande() const;
    void Ajout_Commande(std::string NomClient,std::string NomProduit,int PopulariteProduit,int prixProduit, int prixCommande)
    void affich() const;

    private:

    std::string m_NomClient;
    Produit m_Produit;
    int m_prixCommande;


};

#endif
