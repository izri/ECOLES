#ifndef BOISSON_H
#define BOISSON_H

#include "produit.h"

class Boisson : public Produit
{
public:
    Boisson(const unsigned int &price = 3, const double &tva = 10.0);
    ~Boisson();

    std::string getName() const;
};

#endif // BOISSON_H
