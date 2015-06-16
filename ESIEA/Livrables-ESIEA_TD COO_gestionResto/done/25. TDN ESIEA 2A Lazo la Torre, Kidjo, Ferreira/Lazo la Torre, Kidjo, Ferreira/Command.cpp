#include "Command.h"

using namespace std;

Command::Command(int const nbPlat, Client const client) : m_nbPlat(nbPlat), m_client(client)
{
    prixTotal = 0;
    int i(0);
    for (i = 0; i < m_nbPlat; i ++)
    {
        m_product.push_back (setProduct());
        prixTotal += m_product[i].getPrice();
    }
}

Client Command :: getClient() const
{
    return m_client;
}

Product Command :: getProduct (int const index) const
{
    if (index < 0 || index > m_nbPlat)
        return m_product[index];
    return m_product[0];
}


Command setCommmand ()
{
    int nbProd;
    cout << "Nombre de Produit : " << endl;
    cin >> nbProd;
    cout << "Client : " << endl;
    Client client (setClient());
    Command command (nbProd, client);
    return command;
}




