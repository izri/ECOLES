#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Restaurant;

class Client
{
public:
    Client(const std::string &name, Restaurant &restaurant);
    ~Client();

    std::string getName() const;
    void setName(const std::string &name);

    Restaurant& getRestaurant() const;

private:
    std::string name;
    Restaurant &restaurant;
};

#endif // CLIENT_H
