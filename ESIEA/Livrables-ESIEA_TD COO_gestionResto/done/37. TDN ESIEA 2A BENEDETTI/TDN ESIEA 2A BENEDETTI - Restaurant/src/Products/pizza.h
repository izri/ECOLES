#ifndef PIZZA_H
#define PIZZA_H

#include "produit.h"

class Pizza : public Produit
{
public:
    Pizza(const unsigned int &price = 9, const double &tva = 10.0);
    ~Pizza();

    std::string getName() const;
};

#endif // PIZZA_H
