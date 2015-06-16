#ifndef BOISSON_H_INCLUDED
#define BOISSON_H_INCLUDED

#include <string>
#include "Produit.h"

class Boisson : public Produit ///Heritage Produit
{
        std::string m_gazeux;
        std::string m_nonGazeux;
        std::string m_eau;
        std::string m_jus;
        std::string m_soda;
        std::string m_alcool;

    public:
        Boisson();
        Boisson(std::string c, int nb);
        /*
        Fonction qui permet de savoir si c'est chaud ou froid
        Elle ne retourne rien
        */
        void temperature();
        /*
        Fonction qui fait un menu des boissons
        l'utilisateur pourra en choisir
        */
        void choixBoisson();

};

#endif // BOISSON_H_INCLUDED
