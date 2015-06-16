#ifndef DEF_HISTORIQUE
#define DEF_HISTORIQUE

#include <iostream>
#include <string>

class Classement
{
    public:

    int ClassementClientPrix(std::string NomClient,int PrixTotalClient,int tabClientPrix[]);
    int ClassementClientValorisation(std::string NomClient,int PointdeFidelitesClient,int m_nbPersonnesInvites,int tabClientValorisation[])
    int ClassementProduit(std::string NomProduit,int PopulariteProduit, int tabProduit[])

    private:

    Client m_Client;
    int m_nbClient;
    int tabClientPrix[m_nbClient];
    Produit m_Produit;
    int m_nbProduit;


};

#endif
