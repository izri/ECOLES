#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>


class Product
{

	public :
		Product(std::string name, float price);
        const std::string get_name();
        const float get_price();
		void affichage();


    private :
		std::string m_name;
		float m_price;
};


class Pizza : public Product
{
    public :
        Pizza(const std::string n_pizza, const float p_pizza);

    private :
        std::string n_pizza;
        float p_pizza;

};

class Pj : public Product
{
    public :
        Pj(const std::string n_pj, const float p_pj);

    private :
        std::string n_pj;
        float p_pj;
};

class Pv : public Product
{
    private :
        std::string n_pv;
        float p_pv;

    public :
        Pv(const std::string n_pv, const float p_pv);
};

class Dessert : public Product
{
    public :
        Dessert(const std::string n_dessert, const float p_dessert);

    private :
        std::string n_dessert;
        float p_dessert;

};

class Boisson : public Product
{
    public :
        Boisson(const std::string n_boisson, const float p_boisson);

    private :
        std::string n_boisson;
        float p_boisson;

};

#endif // PRODUCT_H
