#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"

using namespace std;

class Command : public Printable
{
private :
    Client client;
    Product product;
    int date;
    float cost;
public :
    Command(Client client, Product product, int date, float cost);
    const Client get_client();
    const Product get_product();
    const int get_date();
    const float get_cost();
    void affichage();
};

#endif // COMMAND_HPP
