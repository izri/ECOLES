#include <string>
#include <iostream>

#include "Reservation.h"

using namespace std;

Reservation::Reservation() : m_date(""),m_heure(""),m_tableReserve("")
{

}

Reservation::Reservation(string c) : m_date(""),m_heure(""),m_tableReserve("")
{

}

void Reservation::horaireReservation()
{
    Client coor;
        cout << "------------------------------------BIENVENUE-----------------------------------" << endl;
        cout << "---------------------------Au Service des Reservations--------------------------" << endl;


        coor.afficher();
        cout << "date de réservation: " << endl;
        getline(cin,m_date);

        cout << " heure de réservation:" << endl;
        getline(cin,m_heure);

        cout << "table reservee: " << endl;
        getline(cin,m_tableReserve);

        cout << " " << endl;
        cout << "----------------------------Resume de votre reservation-------------------------:" << endl;
        cout << "La date : " << m_date << endl;
        cout << "L'heure : " << m_heure << endl;
        cout << "La nom de la table reserve : " << m_tableReserve << endl;
        cout << " " << endl;
        cout << "----------------------------------------------------------------------------------" << endl;

}



