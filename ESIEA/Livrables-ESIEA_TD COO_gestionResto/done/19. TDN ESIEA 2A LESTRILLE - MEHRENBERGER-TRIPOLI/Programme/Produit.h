#ifndef DEF_PRODUIT
#define DEF_PRODUIT

#include <iostream>
#include <string>

class Produit
{
    public:

    Produit();
    string getNomProduit() const;
    int getPrixProduit() const;
    int getPopularite() const;
    void ajoutProduit(std::string NomProduit,int prixProduit,int Popularite);
    void afficher() const;

    private:

    std::string m_NomProduit;
    int m_prixProduit;
    int m_Popularite;

};

#endif
