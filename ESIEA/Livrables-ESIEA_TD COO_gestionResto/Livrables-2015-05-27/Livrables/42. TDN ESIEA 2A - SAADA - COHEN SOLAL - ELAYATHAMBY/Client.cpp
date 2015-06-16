#include "Plat.h"
#include "Client.h"

void Client::commande (Plat p) {

    sommeDue += p.getPrix();
    // aff();
}


Client :: Client (string _nom, short unsigned _table) {

    nom = _nom;
    table = _table;

    sommeDue = 0;
}


void   Client :: aff () {

    cout << "Client : " << nom  << " table " << table << endl << "Vous devez payer : " << sommeDue << "€ " <<endl;
}
