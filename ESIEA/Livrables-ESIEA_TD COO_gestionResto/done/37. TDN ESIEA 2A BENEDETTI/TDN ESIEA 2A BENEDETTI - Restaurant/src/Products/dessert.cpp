#include "dessert.h"

Dessert::Dessert(const unsigned int &price, const double &tva) :
    Produit(price, tva)
{
}

Dessert::~Dessert()
{
}

std::string Dessert::getName() const
{
    return "Dessert";
}
