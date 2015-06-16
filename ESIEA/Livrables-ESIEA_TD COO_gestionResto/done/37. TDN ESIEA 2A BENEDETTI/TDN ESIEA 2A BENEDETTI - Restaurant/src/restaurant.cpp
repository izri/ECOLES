#include "restaurant.h"

Restaurant::Restaurant(const std::string &name) :
    name(name)
{
    this->stock = new Stock(0);
}

Restaurant::~Restaurant()
{
    delete this->stock;
}

std::string Restaurant::getName() const
{
    return this->name;
}

void Restaurant::setName(const std::string &name)
{
    this->name = name;
}

std::vector<Client*> Restaurant::getClients() const
{
    return this->clients;
}

Stock& Restaurant::getStock() const
{
    return *stock;
}
