
#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "resto.hpp"


using namespace std;

class Product : public Printable {
	private :
		string name;
		float price;
		float marge;
		int nbproduits;
	public :
	    //float price;
		Product(const string name, const float price, const float marge, int nbproduits);
		const string get_name();
		const float get_price();
		const float get_marge();
		const float calculAddition(const float price, int nbproduits);
		const float calculMarge(const float marge, int nbproduits);
		const string to_string();
};


class Boisson : public Product {
	public :
		Boisson(const string name);
};

class PlatDuJour : public Product {
	public :
		PlatDuJour(const string name);
};

class PlatVegetarien : public Product {
	public :
		PlatVegetarien(const string name);
};

class Pizza : public Product {
	public :
		Pizza(const string name);
        const string TransformeEnString(float numb);
};

class Dessert : public Product {
	public :
		Dessert(const string name);
};
#endif // PRODUCT_HPP
