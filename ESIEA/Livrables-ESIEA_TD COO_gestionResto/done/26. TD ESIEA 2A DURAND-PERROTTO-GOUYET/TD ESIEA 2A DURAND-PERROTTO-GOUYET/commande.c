#include "commande.h"

using namespace std;

Commande::Commande(Client client, Produit produit, int date, float cout) : client(client), produit(produit), date(date), cout(cout) {}
const Client Commande::get_client()
{
    return client;
}
const Produit Commande::get_produit()
{
    return produit;
}
const int Commande::get_date()
{
    return date;
}
const float Commande::get_cout()
{
    return cout;
}






void Commande::affichage()
{

    client.affichage();

}










