#ifndef DESSERT_H_INCLUDED
#define DESSERT_H_INCLUDED

#include <string>
#include "Produit.h"

class Dessert : public Produit ///Heritage
{
    std::string m_froid;

    public:
        Dessert();
        Dessert(std::string c);

        void gele();

};

#endif // DESSERT_H_INCLUDED
