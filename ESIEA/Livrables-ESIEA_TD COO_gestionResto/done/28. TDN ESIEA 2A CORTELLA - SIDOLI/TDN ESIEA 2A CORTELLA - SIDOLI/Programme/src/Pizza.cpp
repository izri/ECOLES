#include "Pizza.hh"

Pizza::Pizza()
{

}

void		Pizza::ajout_boisson(std::string const &type)
{
  ajout_produit(type, DRINK_PRICE);
}

Pizza::~Pizza()
{

}
