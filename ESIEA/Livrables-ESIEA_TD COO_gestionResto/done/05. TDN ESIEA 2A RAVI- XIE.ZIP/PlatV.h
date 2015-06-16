#ifndef PLATV_H_INCLUDED
#define PLATV_H_INCLUDED

#include <string>
#include "Produit.h"

class PlatV : public Produit ///Héritage
{
    unsigned int m_legume; /// par défaut les attributs à l'extérieur de public se mettent en "private"

    public:
    PlatV();
    PlatV(std::string c, unsigned int legume);

    unsigned int ajoutLegume(unsigned int legume);

};

#endif // PLATV_H_INCLUDED
