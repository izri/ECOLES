#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <iostream>// Output/Input
#include <string>  // string
//#include <cmath>   // Fonction mathématique
#include <vector>  // tableau dynamique
#include <fstream> // Flux
//1#include <ctime>   // Aléatoire
//#include <cstdlib> // Aléatoire
#include <typeinfo>


class Produit
{
	std::string m_nom;
	int m_prix;

	public:

	int magic = 1;

	Produit(std::string nom, int prix);
	int getprix() const;
	std::string getnom() const;
	
	//virtual std::string get_class_name();

};
class Pate : public Produit
{
	public:

	Pate(std::string nom);
};
class Vegetarien : public Produit
{
	public:

	Vegetarien(std::string nom);
};
class Boisson : public Produit
{
	public:

	Boisson(std::string nom);
};
/*class Orangina : public Boisson
{
	public:

	Orangina();
};
class Vodka : public Boisson
{
	public:

	Vodka();
};
class Eau : public Boisson
{
	public:

	Eau();
};*/
class Pizza : public Produit
{
	public:
	//int magic = 2;
	Pizza(std::string nom);
};
/*class Romantica : public Pizza
{
	public:

	Romantica();
};
class Marguerita : public Pizza
{
	public:

	Marguerita();
};
class Reine : public Pizza
{
	public:

	Reine();
};*/


class Commande
{
	std::vector<Produit>m_produitVendu;

	public:

	Commande(Produit produitVendu);
	void setproduitVendu(Produit nouveauProduit);
	int getnbproduitVendu() const;
	int getprixTotal();
	void incrementeProduit(Produit enplus);
	int fgetprix(int j);
	int fgetsize();
	//std::string getClass(int j);
	std::string getNomCommande(int j) const;

};



class Client
{
    std::vector<Commande> m_commandefaite;
	std::string m_nom;

	public:

	Client(std::string nom, Commande commandefaite);
	std::string getNom() const;
	void setcommandefaite(Commande nouvelleCommande);
	double depenceTotal();
};




#endif
