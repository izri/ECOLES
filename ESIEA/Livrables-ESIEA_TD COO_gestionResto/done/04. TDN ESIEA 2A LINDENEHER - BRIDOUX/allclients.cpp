#include "allclients.h"

/**
 | Demande prenom et nom d'un client et l'ajoute dans la base
 | @return l'adresse du client nouvellement cree
*/
Client* AllClients::addClient() {
    string firstName, name;

    cout << "Prenom du nouveau client " << endl; // demande le prenom
    cin >> firstName;
    cout << "Nom de famille du nouveau client " << endl; // demande le nom
    cin >> name;

    Client *newClient = new Client(firstName, name); // creer le nouveau client en memoire
    this->clients.push_back(newClient); // l'ajoute a la base de donnees

    return newClient;
}

/**
 | Supprime un client en fonction de son adresse
 | @param   cl Un pointeur sur le client a supprimer
 | @return  true si le client a ete supprime, false sinon
*/
bool AllClients::deleteClient(Client *cl) {
    for(unsigned int i = 0; i < this->clients.size(); i++) {
        if(this->clients.at(i) == cl) { // recherche de l'adresse du client dans le vector d'adresse
            delete this->clients.at(i); // supprime donc ses commandes et les produits de chaque commandes
            this->clients.erase(this->clients.begin() + i);
            return 1;
        }
    }

    return 0;
}

/**
 | Affiche tous les clients
*/
void AllClients::showClients() {
    for(unsigned int i = 0; i < this->clients.size(); i++) { // pour chaque client
        cout << i+1 << ". ";
        this->clients.at(i)->printNames(); // affiche son identite
        cout << endl;
    }
}

/**
 | Calcul la note moyenne de toutes les commandes
 | @return  la note moyenne
*/
float AllClients::calcAverageNote() {
    Client *cl;
    unsigned int i, j, div = 0;
    float average = 0;

    for(i = 0; i < this->clients.size(); i++) { // pour chaque client
        cl = this->clients.at(i);

        for(j = 0; j < cl->getCmds().size(); j++) { // pour chaque commande de chaque client
            average += cl->getCmds().at(j)->getUserNote(); // ajoute la note
            div++;
        }
    }

    return (div!=0) ? average/div : 0;
}

/**
 | Calcul le prix moyen de toutes les commandes
 | @return  le prix moyen
*/
float AllClients::calcAveragePrice() {
    Client *cl;
    unsigned int i, j, div = 0;
    float average = 0;

    for(i = 0; i < this->clients.size(); i++) {
        cl = this->clients.at(i);

        for(j = 0; j < cl->getCmds().size(); j++) {
            average += cl->getCmds().at(j)->getTotalPrice(); // meme chose qu'avant mais pour le prix
            div++;
        }
    }

    return (div!=0) ? average/div : 0;
}

/**
 | Retourne le nom d'un produit a partir de son id
 | @param   id L'id du produit (de 0 à 12)
 | @return  le nom du produit
*/
string idToName(int id) {
    switch(id) {
        case 0: return "Pizza 4 fromages";
        case 1: return "Salade d'ete";
        case 2: return "Cafe noir";
        case 3: return "Frite McDo";
        case 4: return "Big Mac";
        case 5: return "Coca";
        case 6: return "Gateau yaourt";
        case 7: return "Fruit au choix";
        case 8: return "Tartare de saumon";
        case 9: return "Nems chinois";
        case 10: return "Cristaline";
        case 11: return "Omelette d'oeufs de dragon";
    }

    return "Produit inconnu";
}

/**
 | Rempli un tableau d'entier avec le nombre de fois qu'un produit a ete choisi
 | @param   products[] Un tableau d'entier
*/
void AllClients::fillProdPopularity(int products[]) {
    Client *cl;
    Command *cmd;
    unsigned int i, j, k;

    for(i = 0; i < this->clients.size(); i++) { // pour chaque client
        cl = this->clients.at(i);

        for(j = 0; j < cl->getCmds().size(); j++) { // pour chaque commande
            cmd = cl->getCmds().at(j);

            for(k = 0; k < cmd->getProds().size(); k++) { // pour chaque produit de chaque commande de chaque client
                products[cmd->getProds().at(k)->getId()]++; // on ajoute +1 dans le case correspondant a l'id
            }
        }

    }
}

/**
 | Retourne le nom du produit le plus populaire
 | @return le nom du meilleur produit
*/
string AllClients::calcBestProduct() {
    int products[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    fillProdPopularity(products); // recupere la popularite de chaque produit
    int i, higher = products[0], indexHigh = 0;

    for(i = 1; i < 12; i++) {
        if(products[i] > higher) { // recherche le meilleur produit
            higher = products[i];
            indexHigh = i;
        }
    }

    return idToName(indexHigh);
}

/**
 | Retourne le nom du produit le moins populaire
 | @return le nom du pire produit
*/
string AllClients::calcWorseProduct() {
    int products[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    fillProdPopularity(products); // recupere la popularite de chaque produit
    int i, lower = products[0], indexLow = 0;

    for(i = 1; i < 12; i++) {
        if(products[i] <= lower) { // recherche le pire produit
            lower = products[i];
            indexLow = i;
        }
    }

    return idToName(indexLow);
}

/**
 | Retourne un tableau contenant le nom des produits par ordre de popularite
 | @return un vetor de nom de produit
*/
vector<string> AllClients::sortProduct() {
    int products[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    fillProdPopularity(products); // popularite de chaque produit
    int j, higher, indexHigh;
    vector<string> result;

    for(int i = 0; i < 12; i++) {
        higher = products[0], indexHigh = 0;
        for(j = 1; j < 12; j++) {
            if(products[j] > higher) { // recherche le meilleur
                higher = products[j];
                indexHigh = j;
            }
        }
        result.push_back(idToName(indexHigh));
        products[indexHigh] = -1; // le meilleur a ete utilise, on le met a -1 pour trouver le second meilleur
    }

    return result;
}

