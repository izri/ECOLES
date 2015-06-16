#include "Commande.h"
#include <time.h>
#include <stdio.h>

//Constructeurs

Commande::Commande(){
    this->nomClient="Inconnu";
    for(int i=0;i<5;i++){
        qteRepas[i]=0;
    }
    prix[0] =6;
    prix[1] =8;
    prix[2] =10;
    prix[3] =5;
    prix[4] =2;
}
Commande::Commande(string c){
    this->nomClient=c;
    for(int i=0;i<5;i++){
        qteRepas[i]=0;
    }
    prix[0] =6;
    prix[1] =8;
    prix[2] =10;
    prix[3] =5;
    prix[4] =2;
}

//Méthodes

void time(){ //fonction internet -http://openclassrooms.com/courses/time-h-et-ses-fonctions

    time_t temps;
    struct tm datetime;
    char  format[32];
    time(&temps);
    datetime = *localtime(&temps);
    strftime(format, 32, "%H:%M, le %d/%m/%Y", &datetime);
    cout << "\nCommande a ";
    cout << format << endl;
}


void Commande::ajout(unsigned int qte, unsigned int id){ //gère toute la commande
    int a=1;
    do {
        cout << "Quel Plat voulez vous commandez ?\n" <<endl;
        affichageCarte();
        do
        {
            cout << "Veuillez selectionner 0,1,2,3 ou 4" <<endl;
            cin >> id;
        } while (id!=0 && id!=1 && id!=2 && id!=3 && id!=4);
        cout << "Vous avez choisi le plat numero " << id << endl;
        cout << "En quel quantite ? " <<endl;
        cin >> qte;
        cout << "Vous avez choisi d'en prendre " << qte << endl;
        ajoutQte(qte,id);

        cout << "Voulez vous commandez un autre produit ?\nOUI = 1  NON = 0" <<endl;
        cin >> a;

    }while(a==1);
}
void Commande::ajoutQte(unsigned int qte, unsigned int id){ //ajoute une unite dans le produit
    this->qteRepas[id]=qte;
}

unsigned int Commande::prixTotal(){//calcul prix total
    int somme=0;
    for(int i=0;i<5;i++){
        somme+=this->prix[i]*this->qteRepas[i];
    }
    return somme;
}

void Commande::affichage(){ //affiche recapitulatif
    cout << "\nRecapitulatif de la commande\nClient " << this->nomClient << " a commande " << endl;
    cout << this->qteRepas[0] << " Pizza(s)" << endl;
    cout << this->qteRepas[1] << " Plat(s) du jour"<< endl;
    cout << this->qteRepas[2] << " Plat(s) vegetarien(s)"<< endl;
    cout << this->qteRepas[3] << " Dessert(s)" << endl;
    cout << this->qteRepas[4] << " Boisson(s)" << endl;

    time();
}

void Commande::affichageCarte(){ //affiche carte

    cout << "Voici notre carte:" << endl;
    cout << " 0- Pizza(s) 6 Euros" << endl;
    cout << " 1- Plat(s) du jour 8 Euros"<< endl;
    cout << " 2- Plat(s) vegetarien(s) 10 Euros"<< endl;
    cout << " 3- Dessert(s) 5 Euros" << endl;
    cout << " 4- Boisson(s) 2 Euros" << endl << endl;

}
