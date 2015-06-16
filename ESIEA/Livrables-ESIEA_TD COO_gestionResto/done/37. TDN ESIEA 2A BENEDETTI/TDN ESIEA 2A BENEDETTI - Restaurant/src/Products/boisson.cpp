#include "boisson.h"

Boisson::Boisson(const unsigned int &price, const double &tva) :
    Produit(price, tva)
{

}

Boisson::~Boisson()
{

}

std::string Boisson::getName() const
{
    return "Boisson";
}
