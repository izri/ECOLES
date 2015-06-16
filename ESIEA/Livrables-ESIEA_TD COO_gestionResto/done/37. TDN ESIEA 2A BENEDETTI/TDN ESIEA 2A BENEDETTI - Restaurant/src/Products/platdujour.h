#ifndef PLATDUJOUR_H
#define PLATDUJOUR_H

#include "produit.h"

class PlatDuJour : public Produit
{
public:
    PlatDuJour(const unsigned int &price = 7, const double &tva = 10.0);
    ~PlatDuJour();

    std::string getName() const;
};

#endif // PLATDUJOUR_H
