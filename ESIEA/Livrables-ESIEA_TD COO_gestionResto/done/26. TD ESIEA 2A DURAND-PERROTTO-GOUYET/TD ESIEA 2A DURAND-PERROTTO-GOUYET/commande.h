#ifndef COMMANDE_H
#define COMMANDE_H

#include "resto.h"
#include "client.h"
#include "produit.h"

using namespace std;

class Commande : public Printable
{
prive :
    Client client;
    Produit produit;
    int date;
    float cout;
public :
    Command(Client client, Produit produit, int date, float cout);
    const Client get_client();
    const Product get_produit();
    const int get_date();
    const float get_cout();
    void affichage();
};

#endif // COMMANDE_H
