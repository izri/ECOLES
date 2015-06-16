#include "produit.hpp"

using namespace std;
//méthode -> fonction
//Nom de la classe :: methode

Produit::Produit(std::string name, int prix) //Constructeur ne retourne rien
{
	m_nameProduit = name;
	m_prix = prix;
}

/*void Produit::afficherInfo()
{
	//cout << "Nom du produit : " << m_nameProduit << endl;
	//cout << "Prix : " << m_prix << endl;
	//cout << "Prix : " << m_prix << "€" << endl;
}*/

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

	//cout << m_spec << endl;
}
/**********VEGET6ARIEN**********/
Vegetarien::Vegetarien(std::string name, int prix, int spec) : Produit(name, prix)
{
	m_spec = spec;
	//cout << m_spec << endl;
}
/**********PLAT DU JOUR*********/
Plat::Plat(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;

	//cout << m_spec << endl;
}
/**********BOISSON*********/
Boisson::Boisson(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;

	//cout << m_spec << endl;
}
/**********DESSERT*********/
Dessert::Dessert(std::string name, int prix, int spec) : Produit(name, prix)//herite
{
	m_spec = spec;

	//cout << m_spec << endl;
}


/*Dessert::Dessert(std::string name, int prix) : Produit(name, prix)
{

}*/
