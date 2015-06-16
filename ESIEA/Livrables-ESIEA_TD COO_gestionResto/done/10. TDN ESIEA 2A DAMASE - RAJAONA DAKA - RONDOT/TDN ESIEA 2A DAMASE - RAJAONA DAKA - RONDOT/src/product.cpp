#include <iostream>
#include <string>
#include <vector>

#include "product.hpp"
using namespace std;



Product::Product(const string name, const float price) : name(name), price(price) {}
const string Product::get_name() { return name; }
const float Product::get_price() { return price; }
const string Product::to_string() {
	string s_price = ::to_string(price);
	s_price = s_price.substr(0, s_price.length() - 4); 
	return name + " (" + s_price + " €)";
}
void Product::print() { cout << "Product : " << to_string() << endl;}

Pizza::Pizza (string name, float price) : Product::Product(name, price) {}
Boisson::Boisson (string name, float price) : Product::Product(name, price) {}
Salade::Salade (string name, float price) : Product::Product(name, price) {}
Plat_jour::Plat_jour (string name, float price) : Product::Product(name, price) {}
Dessert::Dessert (string name, float price) : Product::Product(name, price) {}