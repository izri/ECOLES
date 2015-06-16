#include "product.hpp"


Product::Product() {}

Product::Product(const string name, const float price) : name(name), price(price) {}

const string Product::get_name()
{
    return name;
}

const float Product::get_price()
{
    return price;
}

/*const string Product::to_string() {
	string s_price = "nimportequoi";
	//s_price = s_price.substr(0, s_price.length() - 4);
	return name + " (" + s_price + " €)";
}*/

void Product::print()
{
   cout<<"Product : "<<this->get_name()<<endl;
   cout<<"Product : "<<this->get_name()<<endl;

}

Pizza::Pizza(const string name, float price):Product(name, price) { }
