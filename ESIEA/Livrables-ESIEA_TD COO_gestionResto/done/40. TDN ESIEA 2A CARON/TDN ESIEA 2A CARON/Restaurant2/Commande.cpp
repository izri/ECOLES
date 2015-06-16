#include "Commande.h"

using namespace std;

Commande::Commande(int const nbPlat, Client const client) : m_nbPlat(nbPlat), m_client(client)
{
    prixTotal = 0;
    int i(0);
    for (i = 0; i < m_nbPlat; i ++)
    {

        m_produit.push_back (setProduit());
        prixTotal += (m_produit[i].getPrix());

    }
}

Client Commande :: getClient() const
{
     return m_client;
}

Produit Commande :: getProduit (int const index) const
{
    if ((index < 0)  ||  (index > m_nbPlat) )

        return m_produit[index];

    return m_produit[0];
}


Commande setCommmande ()
{
    int nbrProd;

    cout << "Nombre de Produit : " << endl;

    cin >> nbrProd;

    cout << "Client : " << endl;
    Client client (setClient());

    Commande commande (nbrProd, client);
    return commande;
}


