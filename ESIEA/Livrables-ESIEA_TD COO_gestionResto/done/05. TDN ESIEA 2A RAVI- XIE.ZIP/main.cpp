#include <iostream>
#include <string>
#include "Commande.h"
#include "Pizza.h"
#include "Produit.h"
#include "PlatJour.h"
#include "PlatV.h"
#include "Boisson.h"
#include "Dessert.h"
#include "Client.h"
#include "CarteFi.h"
#include "Reservation.h"
#include "TicketCaisse.h"
#include "MajStock.h"
#include "Vente.h"

using namespace std;

int main()
{
     int menu;
    int arret;
do{
arret =0;
    cout << " " << endl;
    cout << "------------------------------------BIENVENUE-----------------------------------" << endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout << "-------------------------------Que voulez-vous faire----------------------------" << endl;
    cout<<" "<<endl;
    cout << "1.entrer les coordonees du client" << endl;
    cout<<" "<<endl;
    cout << "2.Prendre la reservation d'un client" << endl;
    cout<<" "<<endl;
    cout << "3.carte de fidelite" << endl;
    cout<<" "<<endl;
    cout << "4.prendre la commande d'un client/l'addition/stock/ recette de la journee" << endl;
    cout<<" "<<endl;

    cin >> menu;

    Client jack;
    Reservation frere;
    CarteFi gentilMr;
    TicketCaisse mathan;
    Vente recette;
    switch(menu)
    {
        case 1:


                jack.afficher();
                break;
        case 2:

                frere.horaireReservation();
                break;
        case 3:


            gentilMr.changeCarte();

            break;

        case 4:
                   mathan.resumeTicket();

                    break;

        default:
                cout << "Veuillez entrer un nombre entre 1 et 4" <<endl;
                break;
        }


cout << "si vous voulez retourner au menu tapez 1 " <<endl;
cin>>arret;

}while(arret==1);


    return 0;
}
