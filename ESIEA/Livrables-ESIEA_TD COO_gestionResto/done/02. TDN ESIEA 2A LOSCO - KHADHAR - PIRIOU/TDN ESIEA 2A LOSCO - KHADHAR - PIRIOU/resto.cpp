#include <iostream>
#include <string>
#include "vector"



#include "resto.hpp"
#include "client.hpp"
#include "product.hpp"
#include "command.hpp"

using namespace std;



const string Printable::to_string()
{
    const type_info &t = typeid(this);
    return t.name();
}







vector<Pizza> Pizzatab;
vector<PDJ> PDJtab;
vector<PV> PVtab;
vector<Dessert> Desserttab;
vector<Boisson> Boissontab;

vector<Client> tabClient;
vector<Command> tabCommand;




int date;


void add_client()
{

    string firstname;
    string lastname;
    float gender;

    cout << "Prenom ?" << endl;
    cin >> firstname;

    cout << "Nom?" << endl;
    cin >> lastname;

    cout << "0 pour Homme, 1 pour Femme";
    cin >> gender;





    tabClient.push_back(*(new Client(firstname, lastname, gender)));

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

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < Pizzatab.size())
                {
                    Pizzatab.erase(Pizzatab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < PDJtab.size())
                {
                    PDJtab.erase(PDJtab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < PVtab.size())
                {
                    PVtab.erase(PVtab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < Desserttab.size())
                {
                    Desserttab.erase(Desserttab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < Boissontab.size())
                {
                    Boissontab.erase(Boissontab.begin()+id);
                    system("cls");
                }
                else
                {
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a modifier" << endl;
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
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a modifier" << endl;
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
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a modifier" << endl;
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
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a modifier" << endl;
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
                    cout << "ID non reconnu" << endl;
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

                cout << "Tapez l'identifiant du plat a modifier" << endl;
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
                    cout << "ID non reconnu" << endl;
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
    cout << "Plat non disponible / erreur de saisie" << endl;
    system("pause");
    system("cls");

}




void add_command()
{

    string plat;
    int result;

    system("cls");


    /*Client clienta = *(new Client("test", "lol" , 0));
    cout << "ok" << endl;
    Product pizzaa = Pizzatab.back();
    Command commanda = *(new Command(clienta, pizzaa));
    cout << "presque" << endl;
    commanda.affichage();
    system("pause");*/


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






void bilan()
{

    system("cls");
    system("color 0a");
    cout << "|******************************************************************************|" << endl;
    cout << "|                                  HISTORIQUE                                  |" << endl;
    cout << "|******************************************************************************|" << endl;
    cout << "\n" << endl;

    int i;
    float total = 0;
    float nbf = 0;

    for(i = 0 ; i < tabCommand.size() ; i++)
    {

        Client clienthisto = tabCommand.at(i).get_client();
        Product producthisto = tabCommand.at(i).get_product();
        total += tabCommand.at(i).get_cost();
        if(clienthisto.get_gender() == 1) nbf++;

        cout << clienthisto.to_string() << ", le " <<date / 1000000 << "/" << (date % 10000) / 10000 << "/" << date % 10000 << endl;
        cout << "a commande : ";
        producthisto.affichage();
        cout << "\n" << endl;

    }


    float nbf2 = (nbf / tabClient.size()) * 100;
    float nbh = 100 - nbf2;

    cout << "\n" << "Total : " << total << " euro(s)" << endl;
    cout << "\n" << nbf2 << "% des clients sont des femmes (" << nbf << ")" << endl;
    cout << nbh << "% des clients sont des hommes (" << tabClient.size() - nbf << ")\n" << endl;
    system("pause");
    system("color 07");

}














int main()
{


    int choice = -1;

    system("color 0a");
    cout << "Initialisation : creez un menu, reglez la date pour pouvoir commencer" << endl;
    system("pause");
    system("color 07");
    system("cls");

    gestion_product();
    cout << "Entrez la date (ex : 23/04/2015 -> 23042015)" << endl;
    cin >> date;
    system("cls");

    while(choice != 4)
    {
        system("cls");
        cout << "Entrez 0 pour prendre une commande" << endl;
        cout << "Entrez 1 pour gerer les produits" << endl;
        cout << "Entrez 2 pour changer la date" << endl;
        cout << "Entrez 3 pour acceder au bilan/historique" << endl;
        cout << "Entrez 4 pour quitter" << endl;

        cin >> choice;

        if(choice == 0)	add_command();
        if(choice == 1) gestion_product();
        if(choice == 2)
        {

            cout << "Entrez la date (ex : 23/04/2015 -> 23042015)" << endl;
            cin >> date;
            system("cls");

        }
        if(choice == 3) bilan();
    }






}













