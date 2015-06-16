#include <iostream>
#include <string>
#include "vector"



#include "resto.h"
#include "ficheClient.h"
#include "produit.h"
#include "commande.h"

using namespace std;



const string Printable::to_string()
{
    const type_info &f = typeid(this);
    return f.name();
}

vector<Pizza> Pizzatab;
vector<PDJ> PDJtab;
vector<PV> PVtab;
vector<Boisson> Boissontab;
vector<Dessert> Desserttab;
vector<Client> tabClient;
vector<Command> tabCommand;

int date;


void add_client()
{

    string prenom;
    string nom;
    float d;

    cout << "Prenom ?" << endl;
    cin >> prenom;

    cout << "Nom?" << endl;
    cin >> nom;

    cout << "0 pour Homme, 1 pour Femme";
    cin >> d;
    
    tabClient.push_back(*(new Client(prenom, nom, d)));

    tabClient.back().affichage();

    system("pause");

}


void gestion_product()
{



    string nom;
    float prix;
    int i;
    int id;
    int choix = 6;
    int choix0;
    int choix1;
    int choix2;
    int choix3;

    system("cls");

    while(choix !=4)
    {

        cout << "Tapez 0 pour lister les produits" << endl;
        cout << "Tapez 1 pour ajouter un produit" << endl;
        cout << "Tapez 2 pour supprimer un produit" << endl;
        cout << "Tapez 3 pour modifier un produit" << endl;
        cout << "Tapez 4 pour quitter" << endl;
        cin >> choix;
        system("cls");

        if(choix == 0)
        {

            cout << "Tapez 0 pour lister tous les produits" << endl;
            cout << "Tapez 1 pour lister toutes les pizzas" << endl;
            cout << "Tapez 2 pour lister tous les plats du jour" << endl;
            cout << "Tapez 3 pour lister tous les plats vegetariens" << endl;
            cout << "Tapez 4 pour lister tous les desserts" << endl;
            cout << "Tapez 5 pour lister toutes les boissons" << endl;

            cin >> choix0;

            system("cls");

            if(choix0 == 0)
            {


                cout << "Pizzas" << endl;
                cout << endl;
                for(i = 0 ; i < Pizzatab.size() ; i++)
                {

                    Pizzatab.at(i).affichage();

                }
                cout << endl;
                cout << "Plats du jour" << endl;
                cout << endl;
                for(i = 0 ; i < PDJtab.size() ; i++)
                {

                    PDJtab.at(i).affichage();

                }
                cout << endl;
                cout << "Plats vegetariens" << endl;
                cout << endl;
                for(i = 0 ; i < PVtab.size() ; i++)
                {

                    PVtab.at(i).affichage();

                }
                cout << endl;
                cout << "Desserts" << endl;
                cout << endl;
                for(i = 0 ; i < Desserttab.size() ; i++)
                {

                    Desserttab.at(i).affichage();

                }
                cout << endl;
                cout << "Boissons" << endl;
                cout << endl;
                for(i = 0 ; i < Boissontab.size() ; i++)
                {

                    Boissontab.at(i).affichage();

                }
                cout << endl;

                system("pause");
                system("cls");

            }

            if(choix0 == 1)
            {

                cout << "Pizzas" << endl;
                cout << endl;

                for(i = 0 ; i < Pizzatab.size() ; i++)
                {

                    Pizzatab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }

            if(choix0 == 2)
            {

                cout << "Plats du jours" << endl;
                cout << endl;

                for(i = 0 ; i < PDJtab.size() ; i++)
                {

                    PDJtab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }

            if(choix0 == 3)
            {

                cout << "Plats vegetariens" << endl;
                cout << endl;

                for(i = 0 ; i < PVtab.size() ; i++)
                {

                    PVtab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }

            if(choix0 == 4)
            {

                cout << "Desserts" << endl;
                cout << endl;

                for(i = 0 ; i < Desserttab.size() ; i++)
                {

                    Desserttab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }

            if(choix0 == 5)
            {

                cout << "Boissons" << endl;
                cout << endl;

                for(i = 0 ; i < Boissontab.size() ; i++)
                {

                    Boissontab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }

        }

        if(choix == 1)
        {

            cout << "Tapez 0 pour ajouter une pizza" << endl;
            cout << "Tapez 1 pour ajouter un plat du jour" << endl;
            cout << "Tapez 2 pour ajouter un plat vegetarien" << endl;
            cout << "Tapez 3 pour ajouter un dessert" << endl;
            cout << "Tapez 4 pour ajouter une boisson" << endl;

            cin >> choix1;

            system("cls");

            if(choix1 == 0)
            {

                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                Pizzatab.push_back(*(new Pizza(nom, prix)));
                Pizzatab.back().affichage();


            }

            if(choix1 == 1)
            {

                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                PDJtab.push_back(*(new PDJ(nom, prix)));
                PDJtab.back().affichage();

            }

            if(choix1 == 2)
            {

                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                PVtab.push_back(*(new PV(nom, prix)));
                PVtab.back().affichage();

            }

            if(choix1 == 3)
            {

                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                Desserttab.push_back(*(new Dessert(nom, prix)));
                Desserttab.back().affichage();

            }

            if(choix1 == 4)
            {
                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                Boissontab.push_back(*(new Boisson(nom, prix)));
                Boissontab.back().affichage();

            }

            system("cls");

        }

        if(choix == 2)
        {
            cout << "Tapez 0 pour supprimer une pizza" << endl;
            cout << "Tapez 1 pour supprimer un plat du jour" << endl;
            cout << "Tapez 2 pour supprimer un plat vegetarien" << endl;
            cout << "Tapez 3 pour supprimer un dessert" << endl;
            cout << "Tapez 4 pour supprimer une boisson" << endl;

            cin >> choix2;
            system("cls");

            if(choix2 == 0)
            {

                cout << "Pizzas" << endl;
                cout << endl;

                for(i = 0 ; i < Pizzatab.size() ; i++)
                {

                    Pizzatab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a supprimer" << endl;
                cin >> id;
                if(id < Pizzatab.size())
                {
                    Pizzatab.erase(Pizzatab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix2 == 1)
            {
                cout << "Plats du jour" << endl;
                cout << endl;

                for(i = 0 ; i < PDJtab.size() ; i++)
                {

                    PDJtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a supprimer" << endl;
                cin >> id;
                if(id < PDJtab.size())
                {
                    PDJtab.erase(PDJtab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix2 == 2)
            {
                cout << "Plats vegetariens" << endl;
                cout << endl;

                for(i = 0 ; i < PVtab.size() ; i++)
                {

                    PVtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a supprimer" << endl;
                cin >> id;
                if(id < PVtab.size())
                {
                    PVtab.erase(PVtab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix2 == 3)
            {

                cout << "Desserts" << endl;
                cout << endl;

                for(i = 0 ; i < Desserttab.size() ; i++)
                {

                    Desserttab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a supprimer" << endl;
                cin >> id;
                if(id < Desserttab.size())
                {
                    Desserttab.erase(Desserttab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix2 == 4)
            {

                cout << "Boissons" << endl;
                cout << endl;

                for(i = 0 ; i < Boissontab.size() ; i++)
                {

                    Boissontab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a supprimer" << endl;
                cin >> id;
                if(id < Boissontab.size())
                {
                    Boissontab.erase(Boissontab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "Non non reconnu" << endl;
                    system("cls");
                }

            }

        }


        if(choix == 3)
        {
            cout << "Tapez 0 pour modifier une pizza" << endl;
            cout << "Tapez 1 pour modifier un plat du jour" << endl;
            cout << "Tapez 2 pour modifier un plat vegetarien" << endl;
            cout << "Tapez 3 pour modifier un dessert" << endl;
            cout << "Tapez 4 pour modifier une boisson" << endl;

            cin >> choix3;
            system("cls");

            string newname;
            float newprice;

            if(choix3 == 0)
            {

                cout << "Pizzas" << endl;
                cout << endl;

                for(i = 0 ; i < Pizzatab.size() ; i++)
                {

                    Pizzatab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a modifier" << endl;
                cin >> id;
                if(id < Pizzatab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> newname;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> newprice;
                    Pizzatab.at(id).name = newname;
                    Pizzatab.at(id).price = newprice;
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix3 == 1)
            {
                cout << "Plats du jour" << endl;
                cout << endl;

                for(i = 0 ; i < PDJtab.size() ; i++)
                {

                    PDJtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a modifier" << endl;
                cin >> id;
                if(id < PDJtab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> newname;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> newprice;
                    PDJtab.at(id).name = newname;
                    PDJtab.at(id).price = newprice;
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix3 == 2)
            {
                cout << "Plats vegetariens" << endl;
                cout << endl;

                for(i = 0 ; i < PVtab.size() ; i++)
                {

                    PVtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }
                cout << "Tapez le nom du plat a modifier" << endl;
                cin >> id;
                if(id < PVtab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> newname;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> newprice;
                    PVtab.at(id).name = newname;
                    PVtab.at(id).price = newprice;
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

            if(choix3 == 3)
            {
                cout << "Desserts" << endl;
                cout << endl;

                for(i = 0 ; i < Desserttab.size() ; i++)
                {

                    Desserttab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a modifier" << endl;
                cin >> id;
                if(id < Desserttab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> newname;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> newprice;
                    Desserttab.at(id).name = newname;
                    Desserttab.at(id).price = newprice;
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }


            if(choix3 == 4)
            {
                cout << "Boissons" << endl;
                cout << endl;

                for(i = 0 ; i < Boissontab.size() ; i++)
                {

                    Boissontab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez le nom du plat a modifier" << endl;
                cin >> id;
                if(id < Boissontab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> newname;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> newprice;
                    Boissontab.at(id).name = newname;
                    Boissontab.at(id).price = newprice;
                    system("cls");
                }
                else
                {
                    cout << "Nom non reconnu" << endl;
                    system("cls");
                }

            }

        }

    }

}


int in_menu(string plat)
{

    int i;


    for(i = 0 ; i < Pizzatab.size() ; i++)
    {

        if(plat.compare(Pizzatab.at(i).get_name()) == 0)
            return i;

    }

    for(i = 0 ; i < PDJtab.size() ; i++)
    {

        if(plat.compare(PDJtab.at(i).get_name()) == 0)
            return 100 + i;

    }

    for(i = 0 ; i < PVtab.size() ; i++)
    {

        if(plat.compare(PVtab.at(i).get_name()) == 0)
            return 200 + i;

    }

    for(i = 0 ; i < Desserttab.size() ; i++)
    {

        if(plat.compare(Desserttab.at(i).get_name()) == 0)
            return 300 + i;

    }

    for(i = 0 ; i < Boissontab.size() ; i++)
    {

        if(plat.compare(Boissontab.at(i).get_name()) == 0)
            return 400 + i;

    }



    return -1;
    cout << "Plat indisponible / erreur de saisie" << endl;
    system("pause");
    system("cls");

}




void add_command()
{

    string plat;
    int result;

    system("cls");

    add_client();
    system("cls");
    cout << "Quel plat ?" << endl;
    cin >> plat;

    cout << endl;

    result = in_menu(plat);

    if(result > -1 )
    {

        system("cls");
        cout << plat << " ajoute à la commande" << endl;
        system("pause");




        if(result < 100)
        {

            Product dish = Pizzatab.at(result);
            tabCommand.push_back(*(new Command(tabClient.back(), dish, date, dish.get_price())));

        }

        if(result >= 100 && result < 200)
        {

            Product dish = PDJtab.at(result % 100);
            tabCommand.push_back(*(new Command(tabClient.back(), dish, date, dish.get_price())));

        }

        if(result >= 200 && result < 300)
        {

            Product dish = PVtab.at(result % 100);
            tabCommand.push_back(*(new Command(tabClient.back(), dish, date, dish.get_price())));

        }

        if(result >= 300 && result < 400)
        {

            Product dish = Desserttab.at(result % 100);
            tabCommand.push_back(*(new Command(tabClient.back(), dish, date, dish.get_price())));

        }

        if(result >= 400)
        {

            Product dish = Boissontab.at(result % 100);
            tabCommand.push_back(*(new Command(tabClient.back(), dish, date, dish.get_price())));

        }

    }

    else
    {

        cout << plat << " non disponible / erreur de saisie" << endl;

        system("pause");
        system("cls");

    }


}


int main()
{

    int choix = -1;

    cout << "Initialisation : creez un menu, reglez la date pour pouvoir commencer" << endl;
    system("pause");
    system("cls");
    gestion_product();
    cout << "Entrez la date (ex : 12/08/1994 -> 12081994)" << endl;
    cin >> date;
    system("cls");

    do
    {
        system("cls");
        cout << "Entrez 0 pour prendre une commande" << endl;
        cout << "Entrez 1 pour gerer les produits" << endl;
        cout << "Entrez 2 pour changer la date" << endl;
        cout << "Entrez 4 pour quitter" << endl;

        cin >> choix;

        if(choix == 0)  add_command();
        if(choix == 1) gestion_product();
        if(choix == 2)
        {
            cout << "Entrez la date (ex : 01/01/2013 -> 0101013" << endl;
            cin >> date;
            system("cls");

        }
    }
    while(choix!=4);






}