#include "Commande.h"
Commande::Commande(){
    this->nomClient="toto";
}

Commande::Commande(string c){
    this->nomClient=c;
}

unsigned int Commande::prixTotal(){
    unsigned int somme =0;
    for(int i=0; i<5; i++){
        somme+=this->prix[i]*this->qteRepas[i];
    }
    return somme;
}

void Commande::afficher(){
    //historique
    cout << "Client " << this->nomClient << endl;
    cout << "Commande : " << endl;
    cout << "Pizza(s) " << this->qteRepas[0] <<endl;
    cout << "PJ(s) " << this->qteRepas[1] <<endl;
    cout << "Dessert(s) " << this->qteRepas[2] <<endl;
    cout << "Boisson(s) " << this->qteRepas[3] <<endl;
    cout << "RV(s) " << this->qteRepas[4] <<endl;
    cout << "Prix total " << this->prixTotal() << endl;
}

void Commande::ajoutPizza(unsigned int p){
    this->qteRepas[0]+=p;
}
void Commande::ajoutPJ(unsigned int p){
    this->qteRepas[1]+=p;
}
void Commande::ajoutDessert(unsigned int p){
    this->qteRepas[2]+=p;
}
void Commande::ajoutBoisson(unsigned int p){
    this->qteRepas[3]+=p;
}
void Commande::ajoutRV(unsigned int p){
    this->qteRepas[4]+=p;
}

void Commande::setNomClient(string c){
        this->nomClient=c;
}

string Commande::getNomClient(){
    return this->nomClient;
}
