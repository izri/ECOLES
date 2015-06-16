#include "Product.h"

using namespace std;

Product::Product(string name,float price) :m_name(name),m_price(price){
}

const string Product::get_name()
{
    return m_name;
}
const float Product::get_price()
{
    return m_price;
}

void Product::affichage(){

    cout << "Commande : " << m_name << "  Cout : " << m_price << "Euros" << endl;
}

Pizza::Pizza(const string n_pizza, const float p_pizza) : Product(n_pizza, p_pizza) {

}

Pj::Pj(const string n_pj, const float p_pj) : Product(n_pj, p_pj) {

}

Pv::Pv(const string n_pv, const float p_pv) : Product(n_pv, p_pv) {

}

Boisson::Boisson(const string n_boisson, const float p_boisson) : Product(n_boisson, p_boisson) {

}

Dessert::Dessert(const string n_dessert, const float p_dessert) : Product(n_dessert, p_dessert) {

}




