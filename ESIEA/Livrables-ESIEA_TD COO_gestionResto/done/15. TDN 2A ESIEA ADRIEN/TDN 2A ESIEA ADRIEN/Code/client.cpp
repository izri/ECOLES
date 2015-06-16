#include "client.hpp"

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

Client::Client(const Client& other)
{
    //copy ctor
}

Client& Client::operator=(const Client& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
