// my first string
#include <iostream>
#include <string>

#include "Client.hpp"
#include "Historique.hpp"
#include "Produit.hpp"
#include "Consomable.hpp"
#include "Commande.hpp"


using namespace std;


int main (){
    Historique Historique(1);
    Client * clients=NULL;

    clients->new_client();
    //clients->new_client();

    cout << clients->get_email() << endl;
    clients->show_client();

}
