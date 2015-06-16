#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
#include <string>

using namespace std;


class Product{
	private :
	string type;
	string name;
	float price;
	int nombre;
	public :
		Product(const string  name, const float price);
		const string get_name();
		const float get_price();
		const int get_nombre();
		void change_nombre(int new_nombre);
		const string to_string();
		void print();
};
class Pizza : public Product{
	public :
		Pizza(const string  name, const float price);
};
class Boisson : public Product{
	public :
		Boisson(const string  name, const float price);
};
class Salade : public Product{
	public :
		Salade(const string  name, const float price);
};
class Plat_jour : public Product{
	public :
		Plat_jour(const string  name, const float price);
};
class Dessert : public Product{
	public :
		Dessert(const string  name, const float price);
};
#endif