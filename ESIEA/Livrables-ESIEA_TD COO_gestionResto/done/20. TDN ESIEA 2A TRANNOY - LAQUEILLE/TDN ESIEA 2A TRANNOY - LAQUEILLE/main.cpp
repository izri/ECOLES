#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "vector"
#include "Client.h"
#include "Product.h"
#include "Command.h"
#include "Date.h"
#include "Evaluation.h"

using namespace std;

vector<Client> cliente;
vector<Command> commando;
vector<Pizza> pizzza;
vector<Pj> policejudiciaire;
vector<Pv> procesverbal;
vector<Dessert> desert;
vector<Boisson> poisson;
vector<Date> calendar;
vector<Evaluation> eval;


void newClient(){
    string first_n;
    string last_n;
    int age;
    int telephone;

    cout << "Prenom ?" << endl;
    cin >> first_n;

    cout << "Nom ? " << endl;
    cin >> last_n;

    cout << "Age ?" << endl;
    cin >> age;

    cout << "Numero de telephone ? " << endl;
    cin >> telephone;


    cliente.push_back(*(new Client(first_n, last_n, age , telephone)));

    cliente.back().affichage();

}

int jour, mois, annee;

void changehour(){
cout << "Date du jour : " << endl;
cout << "Jour : " ; cin >> jour;
cout << "Mois : " ; cin >> mois;
cout << "Annee : " ; cin >> annee;
calendar.push_back(*(new Date(jour, mois , annee)));

}

void Product_choice(){
    string name;
    float price;
    int ajout;
    int produit;

    while(ajout!=0){
        cout << "0 : Commande finie" << endl;
        cout << "1 : Ajouter un produit" << endl;
        cin >> ajout;

        system("cls");

if(ajout==1){

        cout << "1 : Pizza" << endl;
        cout << "2 : Plat du jour" << endl;
        cout << "3 : Plat vegetarien" << endl;
        cout << "4 : Dessert" << endl;
        cout << "5 : Boisson" << endl;
        cout << "0 : Retour" << endl;
        cin >> produit;
        system("cls");



        if(produit == 1){

            cout << "Nom ?" << endl;
            cin >> name;

            cout << "Prix ?" << endl;
            cin >> price;

            pizzza.push_back(*(new Pizza(name, price)));
            pizzza.back().affichage();


        }

        if(produit == 2){

            cout << "Nom ?" << endl;
            cin >> name;

            cout << "Prix ?" << endl;
            cin >> price;

            policejudiciaire.push_back(*(new Pj(name, price)));
            policejudiciaire.back().affichage();

        }



        if(produit == 3){

            cout << "Nom ?" << endl;
            cin >> name;

            cout << "Prix ?" << endl;
            cin >> price;

            procesverbal.push_back(*(new Pv(name, price)));
            procesverbal.back().affichage();


        }

        if(produit == 4){

            cout << "Nom ?" << endl;
            cin >> name;

            cout << "Prix ?" << endl;
            cin >> price;

            desert.push_back(*(new Dessert(name, price)));
            desert.back().affichage();

    }


        if(produit == 5){

            cout << "Nom ?" << endl;
            cin >> name;

            cout << "Prix ?" << endl;
            cin >> price;

            poisson.push_back(*(new Boisson(name, price)));
            poisson.back().affichage();

    }


}

    }

}



void commande(){

    newClient();
    system("pause");
    system("cls");
    Product_choice();


}


void evaluation_client(){
    int acc, serv, cuis, prop;

    cout << "Donnez une note pour l'accueil :" << endl;
    cin >> acc;
    cout << "Donnez une note pour le service  :" << endl;
    cin >> serv;
    cout << "Donnez une note pour la cuisine :" << endl;
    cin >> cuis;
    cout << "Donnez une note pour la proprete :" << endl;
    cin >> prop;

    eval.push_back(*(new Evaluation(acc, serv, cuis , prop)));

    eval.back().affichage();
}





int main() {

int menu;

changehour();


while(menu!=0){
        system("cls");
calendar.back().affichage();
cout << " Que souhaitez vous faire ?" << endl;
cout << " 1 : Commande" << endl;
cout << " 2 : Changement de date" << endl;
cout << " 3 : Evaluation du restaurant" << endl;
cin >> menu;

if(menu == 1){
    commande();
    system("pause");
}

if(menu == 2){
    changehour();
    system("pause");
}

if(menu == 3){
    evaluation_client();
    system("pause");
}


}

return 0;
}
