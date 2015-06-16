#ifndef VENTE_H_INCLUDED
#define VENTE_H_INCLUDED

#include <string>
#include "TicketCaisse.h"

class Vente : public TicketCaisse
{
    unsigned int m_nbPizza,m_nbPv,m_nbPj,m_nbBoisson,m_nbDessert;

    public:

        Vente();
        Vente(std::string c, int nb);
            void vente();
        ///unsigned int venteTotal();
       /* void bestVente();
        void worstVente(); */

} ;

#endif // VENTE_H_INCLUDED
