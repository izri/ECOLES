#include <iostream>
#include <string>
#include <vector>

#include "Commande.h"
#include "Client.h"

using namespace std;

int choixIdClients(vector<Client> const& clients) {
    if(clients.size()==0)
        return -1;
    cout << endl << "Choisir un client :" << endl;

    unsigned int i;

    unsigned int input;

    for(i=0; i < clients.size() ; i++)
        cout << i+1 << " : " << clients[i].getIdClient() << endl;

    do {
        cout << "Pour quel client ? ";
        cin >> input;
    } while(input < 1 || input > i+1);

    return i;
}

void afficherClients(vector<Client> const& clients) {
    cout << endl << "Liste clients :" << endl;

    for(unsigned int i(0); i < clients.size() ; i++)
        cout << clients[i];
}

int main()
{
    cout << "Bienvenue dans le gestionnaire de restaurant ! Choisissez une action a effectuer dans le menu." << endl << endl;

    int input;

    vector<Client> clients;

    bool flag = true;

    do {
        do {
            cout << endl << "++++++++++++++++ MENU ++++++++++++++++" << endl << endl;
            cout << "1 : Ajouter un client" << endl;
            cout << "2 : Ajouter une commande" << endl;
            cout << "3 : Ajouter une visite" << endl;
            cout << "4 : Liste des clients" << endl;
            cout << "5 : QUITTER" << endl;

            cout << endl << "Votre choix : ";
            cin >> input;
        } while(input < 1 || input > 5);

        switch(input) {
        case 1 : {
            Client client;
            clients.push_back(client);
            break;
        }
        case 2 :
            input = choixIdClients(clients);
            if(input == -1) {
                cout << "Pas de clients !" << endl;
                break;
            }
            clients[input].nouvelleCommande();
            break;
        case 3 :
            input = choixIdClients(clients);
            if(input == -1) {
                cout << "Pas de clients !" << endl;
                break;
            }
            clients[input].nouvelleVisite();
            break;
        case 4 :
            afficherClients(clients);
            break;
        case 5 :
            flag = false;
            break;
        }

    } while(flag);

    return 0;
}
