#ifndef CLASSPRODUIT_HPP
#define CLASSPRODUIT_HPP
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class produits
{
	public :
		//attributs
		std::string P_name;
		int price;
		//methodes
		void pirnt_P();
		produits(std::string name,int prix);
};

class pizza : public produits
{
	public :
		pizza(std::string name);
};

class vegeta : public produits
{
	public :
		vegeta(std::string name);
};

class jour: public produits
{
	public :
		jour(std::string name);
};

class boisson : public produits
{
	public :
	boisson(std::string name);
};

class dessert : public produits
{
	public :
	dessert(std::string name);
};


#endif