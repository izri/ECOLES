#ifndef CARTEFI_H_INCLUDED
#define CARTEFI_H_INCLUDED

#include <string>
#include "Client.h"

class CarteFi : public Client ///Héritage de CarteFi vers Client
{
    unsigned int m_fidelite;

    public:
        CarteFi();

        void pointDeFidelite();
        /*
        Cette fonction permet de vérifier si l'utilisateur a sa carte de fidelite ou non
        elle retourne 1 si c'est true, sinon false
        */
        void changeCarte();


} ;


#endif // CARTEFI_H_INCLUDED
