#include "client.h"
#include "restaurant.h"

Client::Client(const std::string &name, Restaurant &restaurant) :
    name(name),
    restaurant(restaurant)
{
    restaurant.clients.push_back(this);
}

Client::~Client()
{
}

std::string Client::getName() const
{
    return this->name;
}

void Client::setName(const std::string &name)
{
    this->name = name;
}

Restaurant& Client::getRestaurant() const
{
    return this->restaurant;
}

