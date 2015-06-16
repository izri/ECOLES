
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>

#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"


using namespace std;

// STEP 5 :
//   1) surcharge de l'opérateur << pour éviter de devoir utiliser explicitement to_string()
//   2) séparation cpp / hpp cf. c (prototypes) / h (definitions) en C
//      occasion de revenir sur la distinction interface / implémentation pour qui ne l'a pas comprise
//   3) introduction d'un héritage très simple en définissant une classe parente Printable simple
//   de toutes les classes de ce TP qui comporte deux méthodes const string to_string avec une impl
//   par défaut surchargée ensuite et une méthode print qui ne sera pas surchargée
//   4) mais sait découvrir dynamiquement le nom de la classe concrète dérivée
//    (introduction de la notion de virtualité)

//  STEP 6 : compléter avec les classes concrète de Produit - modulariser le programme en le découpant
//  en plusieurs fichiers, chacun spécialisé suivant un module (module produits, module client (profiling marketing))
//  ...

//  STEP 7 (TP suivant post examen de progr) : Introduction de l'historisation de la relation client (historique des commandes)
//  Le but est, en séance de TD de conception de reproduire de manière plus autonome
//  le travail de conception du diagramme de classe tel qu'au premier TD, puis d'en réaliser l'implémentation en TP.
//     le livrable à rendre sera d'une part un A4 comportant le diagramme de classe
//      (un scan PDF ou une simple photo d'un manuscrit suffiront)
//       d'autre part un projet CPP + makefile + README.txt qui réalise ce qui a été défini par le diagramme de classe
//       travail à réaliser par binôme ou trinôme.. très probablement noté.


const string Printable::to_string() {
	const type_info &t = typeid(this);
	return t.name();
}


// Une friandise : la surcharge d'opérateurs !
ostream& operator<<(ostream& s, Client c) { return s << c.to_string(); }
ostream& operator<<(ostream& s, Product o) { return s << o.to_string(); }
ostream& operator<<(ostream& s, Command o) { return s << o.to_string(); }

void AffichageListe(liste l)
{

    while(l!=NULL)
    {
        cout << "Client numéro : " << l->IdClient << "  dépenses: " << l->sum <<endl <<endl <<endl;
        l=l->succ;
    }
}

//On définit le prix minimum pour qu'un client soit considéré comme faisant partie des meilleurs clients
liste triMeilleursClients(liste l, float minimumprice)
{
       liste t_tri = NULL;
       liste tri = NULL;
       bool test = false;

       t_tri = new node;



    /** cas de la tête de lisre **/


    while(l!=NULL && test==false)
    {
        if(l->sum >= minimumprice){t_tri=l;
                            test =true;
                           }
        l=l->succ;

    }
    t_tri->succ = tri;

    while(l!=NULL)
    {
        tri = new node;
        if(l->sum >= minimumprice){tri=l;
                           }
        tri = tri->succ = NULL;
        l=l->succ;

    }


    return t_tri;
}
int main() {

    liste Clients = NULL;
    liste tClients = NULL;
    liste tri = NULL;
    tri = new node;

	tClients = new node;
	//tClients->succ=NULL;

	Client jane("Jane", "DOE", true,37,12,1450,0);
	jane.HistoriqueClients(tClients,jane);
    //tClients->succ = Clients;
	Client john("John", "DOE", false,30,8,2000,1);
	Clients = new node;
  tClients->succ = Clients;
    john.HistoriqueClients(Clients,john);
   // Clients->prec=	tClients;0
    Clients->succ = NULL;




	Product pizza("Pizza", 10.00,3.00, 1);
	Product chianti("Chianti classico", 10.00, 7.00, 2);
	Command cmd_jane_pizza(jane, pizza,1), cmd_john_chianti(john, chianti,2);


    //Addition additionjane(pizza,1);

/**
	cout << jane << endl;
	cout << john << endl;**/

    cout << "-----Historique des clients----- " << endl;
    AffichageListe(tClients);


	tri = triMeilleursClients(tClients,2000);
	  cout << "-----Tri des meilleurs clients----- " << endl;
	AffichageListe(tri);

    cout << "****Commande**** " << endl;
	cout << pizza << endl;
	cout << chianti << endl<< endl << endl;

	cout << cmd_jane_pizza << endl;
	cout << cmd_john_chianti << endl;



	//cout << typepizza("Regina") << endl;
}






