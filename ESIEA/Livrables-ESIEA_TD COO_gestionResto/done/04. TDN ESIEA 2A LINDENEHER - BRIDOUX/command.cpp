#include "command.h"

/**
 | Initialise une commande : date actuelle, prix nul et note moyenne
*/
Command::Command() {
    this->date = time(0); // date-time actuelle
    this->totalPrice = 0;
    this->userNote = 2.5;
}

/**
 | Supprime une commande : libere chaque produit de la mémoire
*/
Command::~Command() {
    for(unsigned int i=0; i < this->products.size(); i++) { // pour chaque produit
        delete this->products.at(i); // liberation de la memoire
        this->products.erase(this->products.begin() + i); // et du tableau
    }
}

/**
 | Ajoute un produit prod a une commande
 | @param   prod Un pointeur sur un produit
 | @return  true si le produit a ete ajoute, false sinon
*/
bool Command::addProducts(Product *prod) {
    if(prod == NULL) return 0; // produit NULL

    this->products.push_back(prod); // ajout
    this->totalPrice += prod->getPrice(); // mise a jour du prix
    return 1;
}

/**
 | Supprime le produit a la position index
 | @param   index La position du produit a supprimer
 | @return  true si le produit a ete supprime, false sinon
*/
bool Command::deleteProduct(int index) {
    if(index < 0 || index >= (signed) this->products.size()) return 0; // position hors du tableau

    delete this->products.at(index); // liberation de la memoire
    this->products.erase(this->products.begin() + index); // suppression du tableau
    this->computePrice(); // mise a jour du prix
    return 1;
}

/**
 | Met a jour le prix total de la commande
 | @return  le nouveau prix total de la commande
*/
float Command::computePrice() {
    this->totalPrice = 0;

    for(unsigned int i=0; i < this->products.size(); i++) { // parcours chaque produit
        this->totalPrice += this->products.at(i)->getPrice(); // et ajoute le prix du produit courant
    }

    return this->totalPrice;
}

/**
 | Affiche l'addition d'une commande : date, produits commandes et prix total
*/
void Command::showInfo() {
    Product *p = NULL;
    struct tm *now = localtime(&this->date);

    cout << "Addition de la commande du "
         << now->tm_mday << "/" << now->tm_mon+1 << "/" << now->tm_year+1900
         << " a " << now->tm_hour << ":" << now->tm_min
         << endl << endl; // affichage de la date
    cout << "Detail de la commande" << endl;

    for(unsigned int i=0; i < this->products.size(); i++) { // pour chaque produit
        p = this->products.at(i);

        cout << i+1 << ". "
             << p->getName() << p->getPrice() << "e" << endl; // affiche le prix et le nom du produit
    }

    cout << "\nTotal a payer " << this->totalPrice << "e" << endl; // addition
}
