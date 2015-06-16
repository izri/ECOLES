#include "Products/pizza.h"

Pizza::Pizza(const unsigned int &price, const double &tva) :
    Produit(price, tva)
{
}

Pizza::~Pizza()
{
}

std::string Pizza::getName() const
{
    return "Pizza";
}
