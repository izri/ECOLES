#include <iostream>
#include "Client.h"
#include "Client.cpp"
#include "Commande.cpp"
#include "Commande.h"
#include "Produit.h"
#include "Produit.cpp"
#include <string>


using namespace std;


int main()
{
    cout << "Prendre une commande :\n\n" << endl;
    Client Client1("Flavien","Caron", 0);
    Client1.afficher();




















    return 0;
}
