#include <iostream>
#include <string>

class Produit
{
	public:
		Produit(std::string name, int prix);
		void setPrix(int prix);
		void setName(std::string name);
		int getPrix();
		std::string getName();
		void afficherInfo();
	private:
		std::string m_nameProduit;
		int m_prix;

};

/**********PIZZA***********/

class Pizza : public Produit
{
	public:

		Pizza(std::string name, int prix, int x);
	private:
		int m_spec;
};

/**********VEGETARIENr***********/

class Vegetarien : public Produit
{
	public:
		Vegetarien(std::string name, int prix, int x);
	private:
		int m_spec;
};

/**********PLATDUJOUR***********/

class Plat : public Produit
{
	public:
		Plat(std::string name, int prix, int x);
	private:
		int m_spec;
};

/**********BOISSON***********/

class Boisson : public Produit
{
	public:
		Boisson(std::string name, int prix, int x);
	private:
		int m_spec;
};

/**********DESSERT***********/

class Dessert : public Produit
{
	public:
		Dessert(std::string name, int prix, int x);
	private:
		int m_spec;
};
