#include "commande.hpp"

using namespace std;

int main()
{
    // Variables necessaires

    int recommander=0;
    std::string nameClient;
    int day;
    int month;
    int year;
    uint IDplat;
    uint Quantite;
    int option;
    int answ;

    //Affichage du menu


    cout <<"\n     *** Bienvenue dans notre programme de gestion de restaurant ! ***" << endl;

do
{
    cout <<"\n\n     *** Merci de choisir l'operation que vous voulez effectuer ***\n" << endl;

    cout <<"       ------------------------------------------------------------\n";
    cout <<"      |                                                            |\n";
    cout <<"      |  1: Commande      2: Frequence Plat    3: Clear Historique |\n";
    cout <<"      |                                                            |\n";
    cout <<"      |  4: Quitter                                                |\n";
    cout <<"      |                                                            |\n";
    cout << "       ------------------------------------------------------------\n" << endl;

    do
    {
        cout << "     Merci de choisir votre option : ";
        cin >> option;
    } while (option < 1 || option > 4);

    if(option == 1)
    {

    //Demande du nom du client & check fidelity

            cout << "\n        *** Quel est votre nom ? ***" << endl;
            cout << "\n    Nom : ";
            cin >> nameClient;

            addEntrance(nameClient);

    Client currentClient = Client(nameClient);

// Creation de la commande

    cout << "\n\n               *** Veuillez passer votre commande ***\n\n" << endl;
    cout << "    Merci d'entrer la date :" << endl;
    cout << "       Jour (JJ) : ";
    cin >> day;
    cout << "       Mois (MM) : ";
    cin >> month;
    cout << "       Annee (AAAA) : ";
    cin >> year;

    cout << "\n\n Quel plat voulez-vous (1: Pizza, 2: PDJ, 3: Poisson, 4: Boisson, 5: Dessert) ?" << endl;
    cout << "    Identifiant du plat: ";
    cin >> IDplat;

    cout << "\n\n    Combien en voulez-vous? " << endl;
    cout << "       Quantite : ";
    cin >> Quantite;

    Plat meal = Plat(IDplat);

    addPlat(IDplat, Quantite);

    Commande poney = Commande(meal, Quantite, day, month, year);

    ClearScreen();

    cout << "\n    Voulez-vous commander autre chose ? (0/1)" << endl;
    cout << "     Recommander : ";
    cin >> recommander;

    while(recommander == 1)
    {
        cout << "\n\n Quel plat voulez-vous (1: Pizza, 2: PDJ, 3: Poisson, 4: Boisson, 5: Dessert) ?" << endl;
        cout << "    Identifiant du plat: ";
        cin >> IDplat;

        cout << "\n\n    Combien en voulez-vous? " << endl;
        cout << "       Quantite : ";
        cin >> Quantite;

        meal = Plat(IDplat);

        poney.addMeal(meal, Quantite);
        addPlat(IDplat, Quantite);
        ClearScreen();

        cout << "\n    Voulez-vous commander autre chose ? (0/1)" << endl;
        cout << "     Recommander : ";
        cin >> recommander;
    }

    poney.affichage(nameClient);

    currentClient.addCommande(poney);

    poney.fichierEspion(nameClient);

    //Retour au menu initial

    }

    if(option == 2)
    {
        freqPlat();
    }

    if(option == 3)
    {
        cout << "\n\n  Etes-vous sur ? Il n'y a pas de retour en arriere (Oui : 1, Non : 0) : ";
        cin >> answ;

        if(answ == 1)
        {

        clearHisto();

        }

        ClearScreen();

    }


}while (option!=4);

    cout << endl << "       *** Arigato gosaimasu. Itadekimasu ! ***" << endl;
    return 0;
}
