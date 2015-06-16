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


Pizza::Pizza(const string name) { super(name, 10.00); }