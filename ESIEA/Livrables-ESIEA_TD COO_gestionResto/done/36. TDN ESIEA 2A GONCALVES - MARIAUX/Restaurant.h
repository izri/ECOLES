#ifndef DEF_RESTAURANT
#define DEF_RESTAURANT

#include <string>
#include <vector>

class Client
{
private:
	std::string m_nom;
	std::string m_prenom;
public:
	Client();
	std::string getnom() const;
	std::string getprenom() const;
};

class Plat
{
private:
	std::string m_nom;
	int TypePlat;
	int prix;
public:
	Plat();
	std::string lirePlat() const;
	double getPrix() const;

};

class Menu
{
private:
	Plat entree;
	Plat principal;
	Plat dessert;
	Plat boisson;
	int prix;
public:
	Menu();
	Plat getEntree() const;
	Plat getPlatPrincipal() const;
	Plat getBoisson() const;
	Plat getDessert() const;
	int getPrix() const;
	void consulterMenu() const;
};

class Restaurant
{
private :
	Menu menu1;
	Menu menu2;
	Plat carte[8];
public:
    Menu getMenu1() const;
    Menu getMenu2() const;
	Restaurant();
};

#endif
