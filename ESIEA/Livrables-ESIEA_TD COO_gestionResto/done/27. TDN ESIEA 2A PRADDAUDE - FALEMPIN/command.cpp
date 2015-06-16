#include "command.hpp"

Command::Command(Client client, Product product) : client(client), product(product)
{
}

const Client Command::get_client()
{
    return client;
}

const Product Command::get_product()
{
    return product;
}

const string Command::to_string()
{
    return product.to_string() + " - " + client.to_string();
}

const float Command::get_totalPrice()
{
    int i;
    float t;

        t += product.get_price();

    return t;
}
