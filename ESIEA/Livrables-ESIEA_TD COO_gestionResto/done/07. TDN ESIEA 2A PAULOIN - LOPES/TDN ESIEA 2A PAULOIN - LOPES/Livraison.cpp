#include "Livraison.h"

Livraison::Livraison(){
    string num;
    string street, city;
    cout << "Entrer la ville de livraison: ";
    cin >> city;
    cout << "Entrer la rue de livraison: ";
    cin >> street;
    cout << "Entrer le numero de la rue de livraison: ";
    cin >> num;
    cout <<endl;
    this->Number=num;
    this->StreetName=street;
    this->CityName=city;
}

//Méthodes

int Livraison::nbCommande(){

    cout << "Combien commande separe ?" <<endl;
    cin >> NumberCommande;
    return NumberCommande;
}
/*
string Livraison::getNumber(){
    return this->Number;
}

void Livraison::setNumber(string c){
    this->Number;
}

string Livraison::getStreetName(){
    return this->StreetName;
}

void Livraison::setStreetName(string c){
    this->StreetName;
}

string Livraison::getCityName(){
    return this->CityName;
}

void Livraison::setCityName(string c){
    this->CityName;
}*/

void Livraison::affichage(){
    cout << "Adresse de livraison: " << this->Number + ", rue " + this->StreetName + ", " + this->CityName <<endl<<endl;
}
