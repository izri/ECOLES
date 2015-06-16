#include "Client.h"
#include "Historique.h"
//Constructeurs

Client::Client(){
    string prenom, nom, num;
    cout << "Entrer le prenom du nouveau client: ";
    cin >> prenom;
    cout << "Entrer le nom du nouveau client: ";
    cin >> nom;
    cout << "Entrer le numero de telephone du nouveau client: ";
    cin >> num;
    cout <<endl;
    this->FirstName=prenom;
    this->LastName=nom;
    this->PhoneNumber=num;
}

//Méthodes

string Client::getFirstName(){
    return this->FirstName;
}

string Client::getLastName(){
    return this->LastName;
}

string Client::getPhoneNumber(){
    return this->PhoneNumber;
}

void Client::affichage(){
    cout << "Nouvelle fiche Client: " << endl << endl;
    cout << "Prenom: " << this->FirstName <<endl;
    cout << "Nom: " << this->LastName << endl;
    cout << "Tel.: " << this->PhoneNumber << endl << endl;
}

