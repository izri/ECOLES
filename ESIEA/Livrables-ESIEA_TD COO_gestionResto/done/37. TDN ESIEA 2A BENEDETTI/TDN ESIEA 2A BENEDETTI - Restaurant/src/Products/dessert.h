#ifndef DESSERT_H
#define DESSERT_H

#include "produit.h"

class Dessert : public Produit
{
public:
    Dessert(const unsigned int &price = 6, const double &tva = 10.0);
    ~Dessert();

    std::string getName() const;
};

#endif // DESSERT_H
