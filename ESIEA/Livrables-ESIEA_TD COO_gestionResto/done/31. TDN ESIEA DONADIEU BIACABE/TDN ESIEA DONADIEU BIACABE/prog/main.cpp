#include <iostream>
#include "Client.h"
#include "Product.h"
#include "Commande.h"

using namespace std;

int main()
{

    Commande*Commande1=new Commande;
    Client*Client1=new Client;
    Client1.SetNomclient();
    Client1.Setadresse();
    Commande1.setcommande();
    Commande1.progcommande();

    return 0;
}
