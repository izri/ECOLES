#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

using namespace std;

class Client{
    //attributs
    public:
    string FirstName;
    string LastName;
    string PhoneNumber;

    //Constructeurs
    public:
    Client();

    //méthodes
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    void affichage();
    //void date();
};

#endif // CLIENT_H
