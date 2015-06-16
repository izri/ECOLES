#include "produit.h"

Produit::Produit(const unsigned int &price, const double &tva) :
    price(price),
    tva(tva)
{
}

Produit::~Produit()
{
}

unsigned int Produit::getPrice() const
{
    return price;
}

void Produit::setPrice(const unsigned int &price)
{
    this->price = price;
}

double Produit::getTva() const
{
    return tva;
}

void Produit::setTva(const double &tva)
{
    this->tva = tva;
}
