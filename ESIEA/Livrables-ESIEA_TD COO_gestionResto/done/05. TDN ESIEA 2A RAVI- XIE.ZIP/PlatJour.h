#ifndef PLATJOUR_H_INCLUDED
#define PLATJOUR_H_INCLUDED

#include <string>
#include <iostream>

#include "Produit.h"


class PlatJour : public Produit /// Héritage avec produit
{
    public:
        PlatJour();
        /*
        Renvoie true or false
        fonction qui permet d'avoir un plat chaud ou froid
        petit problème : par rapport au caractère envoye par l'utilisateur
        */
        bool temperature();

    private:
        /*int m_froid;
        int m_chaud;*/
        std::string m_repas;

};



#endif // PLATJOUR_H_INCLUDED
