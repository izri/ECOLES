#include "product.hpp"

Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}

Product::Product(const Product& other)
{
    //copy ctor
}

Product& Product::operator=(const Product& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
