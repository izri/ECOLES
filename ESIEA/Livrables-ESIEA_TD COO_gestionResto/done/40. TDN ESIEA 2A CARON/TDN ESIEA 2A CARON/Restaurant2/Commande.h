#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>
#include "Produit.h"
#include "Client.h"


class Commande
{

    private:

        Client m_client;
        float prixTotal;
        int m_nbPlat;
        std :: vector <Produit> m_produit;


    public:

        Commande(int const nbPlat, Client const client);
        Produit getProduit (int const index) const;
        Client getClient () const;

};

Commande setCommmande ();

#endif // COMMAND_H_INCLUDED
