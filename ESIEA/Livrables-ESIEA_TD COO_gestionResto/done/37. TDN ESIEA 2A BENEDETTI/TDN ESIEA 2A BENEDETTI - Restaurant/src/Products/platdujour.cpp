#include "platdujour.h"

PlatDuJour::PlatDuJour(const unsigned int &price, const double &tva) :
    Produit(price, tva)
{
}

PlatDuJour::~PlatDuJour()
{
}

std::string PlatDuJour::getName() const
{
    return "Plat du jour";
}
