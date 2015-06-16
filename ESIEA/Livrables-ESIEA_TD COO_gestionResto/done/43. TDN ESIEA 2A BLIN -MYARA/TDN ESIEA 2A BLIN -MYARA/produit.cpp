#include "produit.hpp"

using namespace std;

Produit::Produit(std::string name, int prix)
{
	m_nameProduit = name;
	m_prix = prix;
}

void Produit::setPrix(int prix)
{
	m_prix = prix;
}

void Produit::setName(std::string name)
{
	m_nameProduit = name;
}

int Produit::getPrix()
{
	return m_prix;
}

std::string Produit::getName()
{
	return m_nameProduit;
}
/**********PIZZA**********/
Pizza::Pizza(std::string name, int prix, int spec) : Produit(name, prix)//herite de produit
{
	m_spec = spec;
}
/**********VEGETARIEN**********/
Vegetarien::Vegetarien(std::string name, int prix, int spec) : Produit(name, prix)
{
	m_spec = spec;
}
/**********PLAT DU JOUR*********/
Plat::Plat(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;
}
/**********BOISSON*********/
Boisson::Boisson(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;
}
/**********DESSERT*********/
Dessert::Dessert(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;
}
