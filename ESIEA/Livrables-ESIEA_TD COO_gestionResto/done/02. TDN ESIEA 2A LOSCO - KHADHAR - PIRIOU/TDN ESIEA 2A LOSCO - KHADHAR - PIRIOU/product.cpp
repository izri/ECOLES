#include "product.hpp"
#include "vector"
#include <iostream>
#include <string>


using namespace std;

Product::Product(const string name, const float price) : name(name), price(price) {}
const string Product::get_name()
{
    return name;
}
const float Product::get_price()
{
    return price;
}
void Product::affichage()
{
    cout << name << "  " << price << " euros" << endl;
}
const string Product::to_string(float price)
{
    string s_price = to_string(price);
    s_price = s_price.substr(0, s_price.length() - 4);
    return name + " (" + s_price + " €)";

}







Pizza::Pizza(const string namepizza, const float pricepizza) : Product(namepizza, pricepizza) {}
PDJ::PDJ(const string namepdj, const float pricepdj) : Product(namepdj, pricepdj) {}
PV::PV(const string namepv, const float pricepv) : Product(namepv, pricepv) {}
Dessert::Dessert(const string namedessert, const float pricedessert) : Product(namedessert, pricedessert) {}
Boisson::Boisson(const string nameboisson, const float priceboisson) : Product(nameboisson, priceboisson) {}


