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
		Product(string name, float price);
		string get_name();
		float get_price();
		//const string to_string();
		void print();
		void modify();
};



class Pizza : public Product {
	public :
		Pizza(const string name, float price);
};

#endif // PRODUCT_HPP
