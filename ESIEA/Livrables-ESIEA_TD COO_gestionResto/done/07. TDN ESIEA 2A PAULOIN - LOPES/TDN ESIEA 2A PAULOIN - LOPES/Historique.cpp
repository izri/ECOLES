#include "Historique.h"
#include "Client.h"

//Constructeurs

Historique::Historique(){
    this->numberclient=0;
}

//Méthodes

void Historique::AddFicheClient(string FirstName, string LastName, string PhoneNumber){
    this->tabFirstName[this->numberclient]=FirstName;
    this->tabLastName[this->numberclient]=LastName;
    this->tabNum[this->numberclient]=PhoneNumber;
    this->numberclient++;
}

void Historique::AffichageHistorique(){
    cout << "--------HISTORIQUE CLIENT--------" <<endl<<endl;
    int i=0;
    while(i<this->numberclient){
    cout << "Prenom: " << tabFirstName[i] <<endl;
    cout << "Nom: " << tabLastName[i] << endl;
    cout << "Tel.: " << tabNum[i] << endl << endl;
    i++;
    }
}
