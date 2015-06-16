#ifndef TICKETCAISSE_H_INCLUDED
#define TICKETCAISSE_H_INCLUDED

#include <string>
#include "Client.h"

class TicketCaisse : public Client ///Heritage
{
    std::string m_nomResto,m_telResto,m_nomServeur,m_chiffreServeur;
    public:
        TicketCaisse();
        TicketCaisse(std::string c);
        void faireStock();
        void Ticket();
        /*
        Calcul le total des depenses en aliments
        Petit probleme : là il ne calcul que le nb d'aliment
        Solution envisagé : creer un tableau avec leur prix et afficher le prix finale
        */
        unsigned int resumeTicket();


} ;


#endif // TICKETCAISSE_H_INCLUDED
