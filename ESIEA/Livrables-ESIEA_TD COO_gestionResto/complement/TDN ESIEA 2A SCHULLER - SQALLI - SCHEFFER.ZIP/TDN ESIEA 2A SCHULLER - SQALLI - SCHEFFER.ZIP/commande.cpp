#include "command.hpp"

using namespace std;

Command::Command(Client client, produit produit, int date, float prix) : client(client), produit(produit), date(date), prix(prix) {}
const Client Command::get_client()
void Command::affichage()
{

    client.affichage();

}
{
    return client;
}
const produit Command::get_produit()
{
    return produit;
}
const int Command::get_date()
{
    return date;
}
const float Command::get_prix()
{
    return prix;
}









