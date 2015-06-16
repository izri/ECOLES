#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED

#include <string>


class Produit
{
    public:
        Produit();
        /*
        SURCHARGE DU CONSTRUCTEUR
        NB devient facultatif, on peut le mettre si on veut
        */
        Produit(std::string c,int nb=0);

        void afficher();


    private:
        std::string m_nom,m_marque;




};




#endif // PRODUIT_H_INCLUDED
