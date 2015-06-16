#include "command.hpp"

using namespace std;

Command::Command(Client client, Product product, int date, float cost) : client(client), product(product), date(date), cost(cost) {}
const Client Command::get_client()
{
    return client;
}
const Product Command::get_product()
{
    return product;
}
const int Command::get_date()
{
    return date;
}
const float Command::get_cost()
{
    return cost;
}






void Command::affichage()
{

    client.affichage();

}










