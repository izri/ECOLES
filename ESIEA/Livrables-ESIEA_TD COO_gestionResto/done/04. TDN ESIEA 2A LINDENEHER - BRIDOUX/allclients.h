#ifndef ALLCLIENTS_H
#define ALLCLIENTS_H

#include <iostream>
#include <vector>
#include <ctime>

#include "client.h"

using namespace std;

class AllClients {

private:
    vector<Client*> clients;

    void fillProdPopularity(int products[]);

public:
    /// === Constructors ===
    AllClients() {} // ne fait rien de special

    /// === Methods ===
    Client* addClient(); // ajoute client
    bool deleteClient(Client *cl); // supprime client
    void showClients(); // affiches les clients

    float calcAverageNote(); // calcul moyenne note
    float calcAveragePrice(); // calcul moyenne prix
    string calcBestProduct(); // meilleur produit
    string calcWorseProduct(); // pire produit
    vector<string> sortProduct(); // classe produits

    /// === getter / isStatut ===
    bool isEmpty() {return (this->clients.size() == 0)? 1:0;}

    Client* getClientAt(int i) {return (i >= 0 && i < (signed) this->clients.size())? this->clients.at(i):NULL;}
};

#endif // ALLCLIENTS_H


