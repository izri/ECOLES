#include <iostream>
#include <string>
//#include "resto.h"
#include "produit.hpp"
#include "commande.hpp"
#include "client.hpp"
using namespace std;

int main() {


produit pizza("pizza",10);
produit veget("repas vegetarien",8);
produit jour("plat du jour",10);
produit dessert("dessert",6);
produit boisson("boisson",1);

int choix=-1;
int nombre=-1;
client *a;

cout<<"comment vous appelez vous?"<<endl;
string nom;
cin>>nom;
client Base(nom);

string nom2;

cout<<"combien de produit voulez vous?"<<endl;
while(nombre<0){

    cin>>nombre;
}


cout<<"que voulez vous:"<<endl;
cout<<"1) pizza"<<endl;
cout<<"2) repas vegetarien"<<endl;
cout<<"3) plat du jour"<<endl;
cout<<"4) dessert"<<endl;
cout<<"5) boisson"<<endl;


while(choix<1||choix>5){
cin>>choix;

}
    if(choix==1)Base.ajouterCommande(commande(pizza,nombre));
    if(choix==2)Base.ajouterCommande(commande(veget,nombre));
    if(choix==3)Base.ajouterCommande(commande(jour,nombre));
    if(choix==4)Base.ajouterCommande(commande(dessert,nombre));
    if(choix==5)Base.ajouterCommande(commande(boisson,nombre));

    Base.afficherListeCommande();
    cout<<Base.prixTotalClient()<<endl;
    choix=-1;
    nombre=-1;

while(1){
    cout<<"comment vous appelez vous?"<<endl;
    cin>>nom;
if (Base.recherchClient(nom)==true){
    cout<<"re bonjours"<<endl;
    a=Base.revoiClient(nom);

}
else{
    Base.dernierClient()->nouveauClient(nom);
    a=Base.dernierClient();
}

cout<<"combien de produit voulez vous?"<<endl;
while(nombre<0){

    cin>>nombre;
}


cout<<"que voulez vous:"<<endl;
cout<<"1) pizza"<<endl;
cout<<"2) repas vegetarien"<<endl;
cout<<"3) plat du jour"<<endl;
cout<<"4) dessert"<<endl;
cout<<"5) boisson"<<endl;


while(choix<1||choix>5){
cin>>choix;

}
    if(choix==1)a->ajouterCommande(commande(pizza,nombre));
    if(choix==2)a->ajouterCommande(commande(veget,nombre));
    if(choix==3)a->ajouterCommande(commande(jour,nombre));
    if(choix==4)a->ajouterCommande(commande(dessert,nombre));
    if(choix==5)a->ajouterCommande(commande(boisson,nombre));

    a->afficherListeCommande();
    cout<<a->prixTotalClient()<<"euros"<<endl;
    choix=-1;
    nombre=-1;


}


	return 0;
}
