#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>

#include "client.h"
#include "stock.h"

class Restaurant
{
public:
    Restaurant(const std::string &name);
    ~Restaurant();

    std::string getName() const;
    void setName(const std::string &name);

    std::vector<Client*> getClients() const;

    Stock& getStock() const;

private:
    std::string name;
    std::vector<Client*> clients;

    Stock *stock;

    friend Client::Client(const std::string &name, Restaurant &restaurant);
};

#endif // RESTAURANT_H
