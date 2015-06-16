#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "client.h"
#include "historique.h"
#include "livraison.h"
#include "commande.h"

using namespace std;

int main(int argc, char **argv){

cout << "Ce programme a ete realise par deux etudiants de l'ESIEA:\nBrandon LOPES & Maxime PAULOIN, classe 2B2.\nProfesseur: Mme Izri." <<endl<<endl;

    int variable;
    Historique *historique=new Historique();
do{
    cout << "Que faire ?" <<endl;
    cout << "Entrer 1 pour uniquement ajouter une fiche client" <<endl;
    cout << "Entrer 2 pour passer une commande en enregistrant une fiche client" <<endl;
    cout << "Entrer 3 pour une livraison de commande sans enregistrement de fiche client" <<endl;
    cout << "Entrer 4 pour avoir l'historique de fiches client" <<endl;
    cout << "Entrer 5 pour fermer le programme" <<endl;
    cin >> variable;

    if(variable==1){
        system("cls");
        Client *client1=new Client();
        historique->AddFicheClient(client1->FirstName, client1->LastName, client1->PhoneNumber);
        client1->affichage();
        variable=1;
    }

    else if(variable==2){
        system("cls");

        Client *client1=new Client();
        historique->AddFicheClient(client1->FirstName, client1->LastName, client1->PhoneNumber);
        Commande *commande1 = new Commande(client1->FirstName + " " + client1->LastName);
        commande1->ajout(1,0);
        commande1->affichage();
        unsigned int s=commande1->prixTotal();
        cout << "Prix total menu : " << s << " euro(s)" <<endl<<endl;
        variable=1;
    }

    else if(variable==3){
        system("cls");
        Client *client1=new Client();
        Livraison *livraison1=new Livraison();
        int liv=livraison1->nbCommande();
        while(liv!=0){
        Commande *commande1 = new Commande(client1->FirstName + " " + client1->LastName);
        commande1->ajout(1,0);
        commande1->affichage();
        unsigned int s=commande1->prixTotal();
        cout << "Prix total menu : " << s << " euro(s)" <<endl<<endl;
        liv--;
        }
        livraison1->affichage();
        variable=1;
    }

    else if(variable==4){
        system("cls");
        historique->AffichageHistorique();
        variable=1;
    }

    else{
        variable=0;
    }

    }while(variable==1);

    return EXIT_SUCCESS;
}
