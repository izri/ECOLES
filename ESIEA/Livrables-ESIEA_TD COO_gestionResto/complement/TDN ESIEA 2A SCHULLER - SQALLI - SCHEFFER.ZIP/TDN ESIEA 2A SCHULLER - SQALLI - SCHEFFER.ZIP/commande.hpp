#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "resto.hpp"
#include "client.hpp"
#include "produit.hpp"

using namespace std;

class Command : public coupon
{
private :
    Client client;
    produit produit;
    int date;
    float prix;
public :
    Command(Client client, produit produit, int date, float prix);
    const Client get_client();
    const produit get_produit();
    const int get_date();
    const float get_prix();
    void affichage();
};

#endif
