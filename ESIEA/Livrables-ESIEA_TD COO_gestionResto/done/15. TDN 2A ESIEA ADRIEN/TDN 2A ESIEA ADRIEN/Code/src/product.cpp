
#include "product.hpp"
#include "client.hpp"
#include <sstream>`
#include <stdio.h>
using namespace std;

Product::Product(const string name, const float price, const float marge, const int nbproduits) : name(name), price(price), marge(marge), nbproduits(nbproduits) {}
const string Product::get_name()
{
    return name;
}
const float Product::get_price()
{
    return price;
}

const string Product::to_string()
{
 char chaineprice[256];
 char chainemarge[256];
 price = calculAddition(price,nbproduits);
 marge = calculMarge(marge, nbproduits);
 sprintf(chaineprice,"%f",price);
 sprintf(chainemarge,"%f",marge);
 return name + " " + "prix total " + chaineprice + "€ " + " marge " + chainemarge + " €" ;

};

const float Product::calculAddition(const float price, int nbproduits) { return nbproduits * price;}
const float Product::calculMarge(const float marge, int nbproduits) { return nbproduits * marge;}

const string Pizza::TransformeEnString(float numb)
{
char truc[256];
sprintf(truc,"%f",numb);
return truc;
}

/**
Pizza::Pizza(const string name)
{

}
**/
