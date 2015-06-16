#ifndef PIZZA_H_INCLUDED
#define PIZZA_H_INCLUDED

#include <string>
#include <iostream>

#include "Produit.h"

class Pizza : public Produit
{
    public:
    ///CONSTRUCTEURS
    Pizza();
    Pizza(std::string nom);
    /// METHODES
    ///void afficher();
    /*
    Rajout de Piment
    Ne peut pas dépasser le niveau 5
    */

    /*
    Rajout de fromage
    Ne peut pas dépasser 10 fromages
    */



    private:
    std::string m_nomPizza;
    std::string m_vegetarien;
    std::string m_nonVegetarien;
    //std::string m_4Fromages;
};


#endif // PIZZA_H_INCLUDED
