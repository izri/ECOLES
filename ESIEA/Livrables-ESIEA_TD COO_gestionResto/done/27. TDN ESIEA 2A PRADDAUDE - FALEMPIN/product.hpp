#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "main.hpp"

class Product : public Printable
{
    private :
        string name;
        float price;
    public :
        Product(const string name, const float price);
        const string get_name();
        const float get_price();
        const string to_string();
};


class Pizza : public Product
{
    private :
        int nbChampignon;
        int nbPeperoni;
        bool sauceTomate;
    public :
        Pizza(const string name, const float price, const int nbChampignon, const int nbPeperoni, const bool sauceTomate);
        const string to_string();
};

class PlatJour : public Product
{
    private :
        bool dispoAjd;
    public :
        PlatJour(const string name, const float price, const bool dispoAjd);
        const string to_string();
};

class PlatVege : public Product
{
    private :
        int nbSalade;
        int nbBrocolis;
    public :
        PlatVege(const string name, const float price, const int nbSalade, const int nbBrocolis);
        const string to_string();
};

class Dessert : public Product
{
    private :
        int nbBoule;
        int nbCrepe;
    public :
        Dessert(const string name, const float price, const int nbBoule, const int nbCrepe);
        const string to_string();
};

class Boisson : public Product
{
    private :
        int quantiteCl;
    public :
        Boisson(const string name, const float price, const int quantiteCl);
        const string to_string();
};


#endif // PRODUCT_HPP
