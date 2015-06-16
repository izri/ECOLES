#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <iostream>
#include <string>

using namespace std;

class Historique{

    //attributs
    string tabFirstName[100];
    string tabLastName[100];
    string tabNum[100];
    int numberclient;

    //Constructeurs
    public:
    Historique();

    //méthodes
    void AddFicheClient(string FirstName, string LastName, string PhoneNumber);
    void AffichageHistorique();

};

#endif // HISTORIQUE_H
