#include "resto..h"
#include <iostream>


using namespace std;


Commande::Commande()
{
    this->m_prix[1]=7;
    this->m_prix[2]=8;
    this->m_prix[3]=9;
    this->m_prix[4]=10;
    this->m_prix[5]=11;
    this->m_qteRepas[1]=0;
    this->m_qteRepas[2]=0;
    this->m_qteRepas[3]=0;
    this->m_qteRepas[4]=0;
    this->m_qteRepas[5]=0;
    this->m_nomClient="toto";

}

Commande::Commande(string c)
{
    this->m_prix[1]=7;
    this->m_prix[2]=8;
    this->m_prix[3]=9;
    this->m_prix[4]=10;
    this->m_prix[5]=11;
    this->m_qteRepas[1]=0;
    this->m_qteRepas[2]=0;
    this->m_qteRepas[3]=0;
    this->m_qteRepas[4]=0;
    this->m_qteRepas[5]=0;
    this->m_nomClient=c;
}

unsigned int Commande::prixTotal()
{
    unsigned int somme = 0;
    for(int i=0; i<5; i++)
    {
        somme += this->m_prix[i]*this->m_qteRepas[i];
    }
    return somme;
}

void Commande::afficher()
{
    // historique
    cout << "Client " << this->m_nomClient << endl;
    cout << "Commande : " << endl;
    cout << "Pizza(s): " << this->m_qteRepas[0] << endl;
    cout << "PJ(s): " << this->m_qteRepas[1] << endl;
    cout << "Dessert(s): " << this->m_qteRepas[2] << endl;
    cout << "Boisson(s): " << this->m_qteRepas[3] << endl;
    cout << "RV(s): " << this->m_qteRepas[4] << endl;
    cout << "Prix total(s): " << this->prixTotal() << endl;

}

void Commande::ajouterPizza(unsigned int p)
{
    this->m_qteRepas[0] +=p;
}

void Commande::ajouterPJ(unsigned int p)
{
    this->m_qteRepas[1] +=p;
}

void Commande::ajouterDessert(unsigned int p)
{
    this->m_qteRepas[2] +=p;
}

void Commande::ajouterBoisson(unsigned int p)
{
    this->m_qteRepas[3] +=p;
}

void Commande::ajouterRV(unsigned int p)
{
    this->m_qteRepas[4] +=p;
}

void Commande::setNomClient(string c)
{
    this->m_nomClient=c;
}

string Commande::getNomClient()
{
    return this->m_nomClient;
}

Client::Client()
{
    this->m_nomClient="toto";
}

Client::Client(string c)
{
    this->m_nomClient=c;
}



void Client::Commander(Produit produit1)
{
    Commande Commande1;
    cout << this->m_nomClient << ", Veillez passer votre commande." << endl;
    produit1.Selectionner(Commande1);
}

void Client::Payer()
{
    Commande Commande1;
    cout << "Le client " << this->m_nomClient << " doit payer: " << Commande1.prixTotal() << endl;
}

Produit::Produit(string e)
{
    this->m_nomProduit=e;
}

void Produit::Selectionner(Commande commande1)
{
    unsigned int choice;
    cout << "Faite votre choix :" << endl;
    cout << "1. Pizza" << endl;
    cout << "2. Plat du Jour" << endl;
    cout << "3. Dessert" << endl;
    cout << "4. Boisson" << endl;
    cout << "5. Recette vegetarienne" << endl;
    cout << "6. Valider la commande" << endl;

    cin >> choice;




        switch(choice)
        {

            case 1 :  commande1.ajouterPizza(7); commande1.afficher();
            break;

            case 2 :  commande1.ajouterPJ(8);
            break;

            case 3 :  commande1.ajouterDessert(9);
            break;

            case 4 :  commande1.ajouterBoisson(10);
            break;

            case 5 :  commande1.ajouterRV(11);
            break;

            case 6 :  cout << "commande enregistrée" << endl;
        }

        commande1.afficher();




}

