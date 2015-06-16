#include "platvegetarien.h"

PlatVegetarien::PlatVegetarien(const unsigned int &price, const double &tva) :
    Produit(price, tva)
{
}

PlatVegetarien::~PlatVegetarien()
{
}

std::string PlatVegetarien::getName() const
{
    return "Plat végétarien";
}
