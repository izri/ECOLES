#include <iostream>
#include "Produit.hpp"


using namespace std;

void Produit::set_nom(string n){
    nom=n;
}

void Produit::set_prix(unsigned int p){
    prix=p;
}

void Produit::set_type(string t){
    type=t;
}

void Produit::add_consomable(){

}

void Produit::new_produit(){

}


string Produit::get_nom(){
    return nom;
}

string Produit::get_type(){
    return type;
}

unsigned int Produit::get_prix(){
    return prix;
}

unsigned int Produit::get_id(){
    return id;
}
