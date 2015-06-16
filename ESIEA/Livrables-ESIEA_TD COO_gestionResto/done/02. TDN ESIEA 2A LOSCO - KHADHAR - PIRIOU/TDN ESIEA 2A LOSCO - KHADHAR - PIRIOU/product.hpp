#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "resto.hpp"

using namespace std;

class Product : public Printable
{

public :

    string name;
    float price;

    Product(const string name, const float price);
    const string get_name();
    const float get_price();
    const string to_string(float price);
    void affichage();

};



class Pizza : public Product
{
private :
    string namepizza;
    float pricepizza;

public :
    Pizza(const string namepizza, const float pricepizza);
};

class PDJ : public Product
{
private :
    string namepdj;
    float pricepdj;

public :
    PDJ(const string namepdj, const float pricepdj);
};

class PV : public Product
{
private :
    string namepv;
    float pricepv;

public :
    PV(const string namepv, const float pricepv);
};

class Dessert : public Product
{
private :
    string namedessert;
    float pricedessert;

public :
    Dessert(const string namedessert, const float pricedessert);
};

class Boisson : public Product
{
private :
    string nameboisson;
    float priceboisson;

public :
    Boisson(const string nameboisson, const float priceboisson);
};

#endif // PRODUCT_HPP
