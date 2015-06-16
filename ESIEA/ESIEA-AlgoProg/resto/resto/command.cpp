#include "command.hpp"
#include "client.hpp"
#include "product.hpp"

using namespace std;

Command::Command(Client client, Product product) : client(client), product(product) {}

const Client Command::get_client()
{
    return client;
}

const Product Command::get_product()
{
    return product;
}

/* const string Command::to_string()
{
    return product.to_string() + " - " + client.to_string();
} */

void Command::print()
{
    this->client.Client::print();
    this->product.Product::print();
}
