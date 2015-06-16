#include "resto.hpp"

Printable::Printable()
{
    //ctor
}

Printable::~Printable()
{
    //dtor
}

Printable::Printable(const Printable& other)
{
    //copy ctor
}

Printable& Printable::operator=(const Printable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
