#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
#include "resto.hpp"

using namespace std;

class Product : public Printable {
	private :
		string name;
		float price;
	public :
	    Product();
		Product(const string name, const float price);
		const string get_name();
		const float get_price();
		//const string to_string();
		void print();
};



class Pizza : public Product {
	public :
		Pizza(const string name, float price);
};

#endif // PRODUCT_HPP
