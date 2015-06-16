#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <string>
#include "Client.h"

class Reservation : public Client ///Heritage
{
    std::string m_date;
    std::string m_heure;
    std::string m_tableReserve;

    public:
        Reservation();
        Reservation(std::string c);
        /*
        Fonction qui permet de deamnder quand la reservation a ete faite
        A la fin : un resume de la reservation
        */
        void horaireReservation();


};

#endif // RESERVATION_H_INCLUDED
