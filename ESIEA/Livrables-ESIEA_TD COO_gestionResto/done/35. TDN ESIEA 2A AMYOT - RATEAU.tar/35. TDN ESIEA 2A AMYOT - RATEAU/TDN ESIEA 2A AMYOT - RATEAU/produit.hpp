#include <iostream>
#include <string>

class Produit
{
	public:
		//Accessible de n'importe ou dans le code
		Produit(std::string name, int prix);
		void setPrix(int prix);
		void setName(std::string name);
		int getPrix();
		std::string getName();
		void afficherInfo();
	private:
		//Espace restreint aux méthodes de la classe
		std::string m_nameProduit; // std aussi devant string aussi
		int m_prix; //Attributs -> varibales

};

/**********PIZZA***********/

class Pizza : public Produit
{
	public:
		//Accessible de n'importe ou dans le code
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

/*class Dessert : public Produit
{
	public:
		Dessert(std::string name, int prix);
};*/
