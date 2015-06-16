#ifndef PLATVEGETARIEN_H
#define PLATVEGETARIEN_H

#include "produit.h"

class PlatVegetarien : public Produit
{
public:
    PlatVegetarien(const unsigned int &price = 7, const double &tva = 10.0);
    ~PlatVegetarien();

    std::string getName() const;
};

#endif // PLATVEGETARIEN_H
