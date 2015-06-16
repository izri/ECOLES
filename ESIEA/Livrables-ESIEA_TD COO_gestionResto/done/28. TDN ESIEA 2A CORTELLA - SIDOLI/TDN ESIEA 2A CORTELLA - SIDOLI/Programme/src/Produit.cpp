#include "Produit.hh"

Produit::Produit()
{

}

void		Produit::ajout_produit(std::string const &type, int price)
{
  _type = type;
  _price = price;
}

Produit::~Produit()
{

}
