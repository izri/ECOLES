#include <iostream>
#include <string>
#include "client.hpp"
#include "commande.hpp"
using namespace std;


client::client(const string cl_nom):cl_nom(cl_nom), cl_commande(0), cl_suivant(0){}

void client::ajouterCommande(commande Comm){

    if(cl_commande){
        commande *a=cl_commande;

    //if(a->retournerCommande){
        if(a){
            a=a->avancer();
            if(a){
                while(a->retournerCommande()){
                    a=a->avancer();
                }
            }
        }
        a->nouvelleCommande(Comm.getConso(),Comm.getQuantite());
    //commande a(Comm.getConso(),Comm.getQuantite());
    }
    else{

    cl_commande=new commande(Comm.getConso(),Comm.getQuantite());

    }
}

void client::afficherListeCommande(){

    if(cl_commande){
    commande *a=cl_commande;

    while(a){
    a->afficher();
    a=a->avancer();
    }
    }}


int client::prixTotalClient(){
    int p=0;
if(cl_commande){
    commande *a=cl_commande;

    while(a){
    p=p+a->getConso().getPrix();
    a=a->avancer();
    }
    }
    return p;
    }


void client::nouveauClient(string nom){

//cl_suivant=new client(nom);
client cl_suivant(nom);
}


client* client::cl_avancer(){
return cl_suivant;
}

bool client::recherchClient(string nom){
    if (nom==cl_nom)return true;
client*a=cl_suivant;
while(a){
    if (nom==a->cl_nom)return true;
    a->cl_avancer();


}
return false;
}
client* client::revoiClient(string nom){
client*a=cl_suivant;
while(a){
    if (nom==cl_nom)return a;
    a->cl_avancer();


}

return NULL;

}
client* client::dernierClient(){
client*a=cl_suivant;

if(a){
while(a->cl_suivant){
    a->cl_avancer();


}}

return a;



}

client::~client(){}
//client* client::recherchClient(std::string nom)[]



