#include "product.hpp"


Product::Product() {}

Product::Product( string name, float price) : name(name), price(price) {}

string Product::get_name()
{
    return name;
}

float Product::get_price()
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
   cout<<"Price : "<<this->get_price()<<endl;

}

void Product::modify()
{
    char choice;

    cout<<"Change price ? (y/n) : "<< this->get_price()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->price;
    }

    cout<<"Change name ? (y/n) : "<< this->get_name()<< endl;
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout<< "Enter the new "<<endl;
        cin>> this->name;
    }
}

Pizza::Pizza(const string name, float price):Product(name, price) { }
