#include "client.h"

/**
 | Initialise un client
 | @param   firstName Prenom du client
 | @param   name      Nom de famille du client
*/
Client::Client(string firstName, string name) {
    this->firstName = firstName;
    this->name = name;
    this->nbVisit = 0;
    this->lastVisit = time(0); // on considere qu'a la creation du client, celui-ci est dans le restaurant a l'instant present
}

/**
 | Supprime un client : libere chaque commande de la mémoire
*/
Client::~Client() {
    for(unsigned int i=0; i < this->commands.size(); i++) { // pour chaque commande
        delete this->commands.at(i); // liberation de la memoire (par extension libere chaque produit d'une commande)
        this->commands.erase(this->commands.begin() + i); // et du tableau
    }
}

/**
 | Ajoute une commande cmd a un client
 | @param   cmd Un pointeur sur une commande
 | @return  true si la commande a ete ajoutee, false sinon
*/
bool Client::addCmd(Command *cmd) {
    if(cmd == NULL) return 0; // commade NULL

    this->commands.push_back(cmd); // ajout
    this->lastVisit = cmd->getDate(); // derniere visite : aujourd'hui
    this->nbVisit++; // +1 visite
    return 1;
}

/**
 | Supprime la commande a la position index
 | @param   index La position de la commande a supprimer
 | @return  true si la commande a ete supprimee, false sinon
*/
bool Client::deleteCmd(int index) {
    if(index < 0 || index >= (signed) this->commands.size()) return 0; // hors du tableau

    delete this->commands.at(index); // liberation de la memoire (par extension liberation des produits)
    this->commands.erase(this->commands.begin() + index); // suppression du tableau
    this->nbVisit--;
    return 1;
}

/**
 | Affiche les commandes d'un client
*/
void Client::showCmd() {
    Command *c = NULL;
    struct tm *now = NULL;
    time_t date;
    cout << "Liste des commandes de " << this->firstName << " " << this->name << endl; // nom du client
    cout << "-------------------------------------------------" << endl;

    if(this->commands.size() == 0) cout << "Aucune commande trouvee" << endl;
    for(unsigned int i=0; i < this->commands.size(); i++) { // pour chaque commande
        c = this->commands.at(i);
        date = c->getDate();
        now = localtime(&date);

        cout << i+1 << ". commande du " << now->tm_mday << "/" << now->tm_mon+1 << "/" << now->tm_year+1900; // affiche la date

        // et le nombre de produit de la commande, et son prix
        cout << " pour un total de " << c->getTotalPrice() << "e (" << c->getNbProd() << " produit(s)) - note : " << c->getUserNote() << "/5" << endl;
    }
}

/**
 | Affiche les infos de bases d'un client : identite, nombre de visite et derniere visite
*/
void Client::showInfo() {
    struct tm *now = localtime(&this->lastVisit);

    cout << this->firstName << " " << this->name << " a mange " << this->nbVisit << " fois dans le restaurant" << endl;
    cout << "Sa derniere visite remonte au "
         << now->tm_mday << "/" << now->tm_mon+1 << "/" << now->tm_year+1900
         << " a " << now->tm_hour << ":" << now->tm_min
         << endl << endl; // affichage de la date
}
