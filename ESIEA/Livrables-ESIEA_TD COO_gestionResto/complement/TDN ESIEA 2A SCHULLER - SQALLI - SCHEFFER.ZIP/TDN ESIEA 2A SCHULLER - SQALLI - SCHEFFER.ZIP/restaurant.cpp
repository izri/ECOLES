#include <iostream>
#include <string>
#include "vector"
#include "resto.hpp"
#include "client.hpp"
#include "produit.hpp"
#include "commande.hpp"

using nomspace std;
const string coupon::to_string()
{
    const type_info &t = typeid(this);
    return t.nom();
}
vector<Pizza> Pizzatab;
vector<platduJ> platduJtab;
vector<salade> saladetab;
vector<Dessert> Desserttab;
vector<soda> sodatab;
vector<Client> tabClient;
vector<commande> tabcommande;
int date;
void add_client()
{
    string prenom;
    string nom;
    float sex;
    cout << "Prenom ?" << endl;
    cin >> prenom;
    cout << "Nom?" << endl;
    cin >> nom;
    cout << "0 pour Homme, 1 pour Femme";
    cin >> sex;
    tabClient.push_back(*(nouveau Client(prenom, nom, sex)));
    tabClient.back().affichage();
    system("pause");
}
void gestion_produit()
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
            cout << "Tapez 5 pour lister toutes les sodas" << endl;

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
                for(i = 0 ; i < platduJtab.size() ; i++)
                {

                    platduJtab.at(i).affichage();

                }
                cout << endl;
                cout << "Plats vegetariens" << endl;
                cout << endl;
                for(i = 0 ; i < saladetab.size() ; i++)
                {

                    saladetab.at(i).affichage();

                }
                cout << endl;
                cout << "Desserts" << endl;
                cout << endl;
                for(i = 0 ; i < Desserttab.size() ; i++)
                {

                    Desserttab.at(i).affichage();

                }
                cout << endl;
                cout << "sodas" << endl;
                cout << endl;
                for(i = 0 ; i < sodatab.size() ; i++)
                {

                    sodatab.at(i).affichage();

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

                for(i = 0 ; i < platduJtab.size() ; i++)
                {

                    platduJtab.at(i).affichage();

                }

                system("pause");
                system("cls");
            }





            if(choix0 == 3)
            {

                cout << "Plats vegetariens" << endl;
                cout << endl;

                for(i = 0 ; i < saladetab.size() ; i++)
                {

                    saladetab.at(i).affichage();

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

                cout << "sodas" << endl;
                cout << endl;

                for(i = 0 ; i < sodatab.size() ; i++)
                {

                    sodatab.at(i).affichage();

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
            cout << "Tapez 4 pour ajouter une soda" << endl;

            cin >> choix1;

            system("cls");

            if(choix1 == 0)
            {



                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                Pizzatab.push_back(*(nouveau Pizza(nom, prix)));
                Pizzatab.back().affichage();


            }

            if(choix1 == 1)
            {



                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                platduJtab.push_back(*(nouveau platduJ(nom, prix)));
                platduJtab.back().affichage();


            }


            if(choix1 == 2)
            {



                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                saladetab.push_back(*(nouveau salade(nom, prix)));
                saladetab.back().affichage();


            }

            if(choix1 == 3)
            {



                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                Desserttab.push_back(*(nouveau Dessert(nom, prix)));
                Desserttab.back().affichage();


            }

            if(choix1 == 4)
            {



                cout << "Nom ?" << endl;
                cin >> nom;

                cout << "Prix ?" << endl;
                cin >> prix;

                sodatab.push_back(*(nouveau soda(nom, prix)));
                sodatab.back().affichage();


            }


            system("cls");



        }




        if(choix == 2)
        {




            cout << "Tapez 0 pour supprimer une pizza" << endl;
            cout << "Tapez 1 pour supprimer un plat du jour" << endl;
            cout << "Tapez 2 pour supprimer un plat vegetarien" << endl;
            cout << "Tapez 3 pour supprimer un dessert" << endl;
            cout << "Tapez 4 pour supprimer une soda" << endl;

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

                for(i = 0 ; i < platduJtab.size() ; i++)
                {

                    platduJtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < platduJtab.size())
                {
                    platduJtab.erase(platduJtab.begin()+id);
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

                for(i = 0 ; i < saladetab.size() ; i++)
                {

                    saladetab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < saladetab.size())
                {
                    saladetab.erase(saladetab.begin()+id);
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




                cout << "sodas" << endl;
                cout << endl;

                for(i = 0 ; i < sodatab.size() ; i++)
                {

                    sodatab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a supprimer" << endl;
                cin >> id;
                if(id < sodatab.size())
                {
                    sodatab.erase(sodatab.begin()+id);
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
            cout << "Tapez 4 pour modifier une soda" << endl;

            cin >> choix3;
            system("cls");

            string nouveaunom;
            float nouveauprix;

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
                    cin >> nouveaunom;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> nouveauprix;
                    Pizzatab.at(id).nom = nouveaunom;
                    Pizzatab.at(id).prix = nouveauprix;
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

                for(i = 0 ; i < platduJtab.size() ; i++)
                {

                    platduJtab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a modifier" << endl;
                cin >> id;
                if(id < platduJtab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> nouveaunom;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> nouveauprix;
                    platduJtab.at(id).nom = nouveaunom;
                    platduJtab.at(id).prix = nouveauprix;
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

                for(i = 0 ; i < saladetab.size() ; i++)
                {

                    saladetab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a modifier" << endl;
                cin >> id;
                if(id < saladetab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> nouveaunom;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> nouveauprix;
                    saladetab.at(id).nom = nouveaunom;
                    saladetab.at(id).prix = nouveauprix;
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
                    cin >> nouveaunom;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> nouveauprix;
                    Desserttab.at(id).nom = nouveaunom;
                    Desserttab.at(id).prix = nouveauprix;
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




                cout << "sodas" << endl;
                cout << endl;

                for(i = 0 ; i < sodatab.size() ; i++)
                {

                    sodatab.at(i).affichage();
                    cout << "id : " << i << endl;
                    cout << endl;

                }

                cout << "Tapez l'identifiant du plat a modifier" << endl;
                cin >> id;
                if(id < sodatab.size())
                {
                    cout << "Entrez un nouveau nom" << endl;
                    cin >> nouveaunom;
                    cout << "Entrez un nouveau prix" << endl;
                    cin >> nouveauprix;
                    sodatab.at(id).nom = nouveaunom;
                    sodatab.at(id).prix = nouveauprix;
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
        if(plat.compare(Pizzatab.at(i).get_nom()) == 0)
            return i;
    }
    for(i = 0 ; i < platduJtab.size() ; i++)
    {
        if(plat.compare(platduJtab.at(i).get_nom()) == 0)
            return 100 + i;
    }
    for(i = 0 ; i < saladetab.size() ; i++)
    {
        if(plat.compare(saladetab.at(i).get_nom()) == 0)
            return 200 + i;
    }
    for(i = 0 ; i < Desserttab.size() ; i++)
    {
        if(plat.compare(Desserttab.at(i).get_nom()) == 0)
            return 300 + i;
    }
    for(i = 0 ; i < sodatab.size() ; i++)
    {
        if(plat.compare(sodatab.at(i).get_nom()) == 0)
            return 400 + i;
    }
    return -1;
    cout << "Plat non disponible / erreur de saisie" << endl;
    system("pause");
    system("cls");
}
void add_commande()
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
        cout << plat << " ajoute à la commandee" << endl;
        system("pause");
        if(result < 100)
        {
            produit dish = Pizzatab.at(result);
            tabcommande.push_back(*(nouveau commande(tabClient.back(), dish, date, dish.get_prix())));
        }
        if(result >= 100 && result < 200)
        {
            produit dish = platduJtab.at(result % 100);
            tabcommande.push_back(*(nouveau commande(tabClient.back(), dish, date, dish.get_prix())));
        }

        if(result >= 200 && result < 300)
        {
            produit dish = saladetab.at(result % 100);
            tabcommande.push_back(*(nouveau commande(tabClient.back(), dish, date, dish.get_prix())));
        }
        if(result >= 300 && result < 400)
        {
            produit dish = Desserttab.at(result % 100);
            tabcommande.push_back(*(nouveau commande(tabClient.back(), dish, date, dish.get_prix())));
        }
        if(result >= 400)
        {
            produit dish = sodatab.at(result % 100);
            tabcommande.push_back(*(nouveau commande(tabClient.back(), dish, date, dish.get_prix())));
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
    for(i = 0 ; i < tabcommande.size() ; i++)
    {
        Client clienthisto = tabcommande.at(i).get_client();
        produit produithisto = tabcommande.at(i).get_produit();
        total += tabcommande.at(i).get_cost();
        if(clienthisto.get_sex() == 1) nbf++;
        cout << clienthisto.to_string() << ", le " <<date / 1000000 << "/" << (date % 10000) / 10000 << "/" << date % 10000 << endl;
        cout << "a commandee : ";
        produithisto.affichage();
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
    gestion_produit();
    cout << "Entrez la date (ex : 23/04/2015 -> 23042015)" << endl;
    cin >> date;
    system("cls");
    while(choice != 4)
    {
        system("cls");
        cout << "Entrez 0 pour prendre une commandee" << endl;
        cout << "Entrez 1 pour gerer les produits" << endl;
        cout << "Entrez 2 pour changer la date" << endl;
        cout << "Entrez 3 pour acceder au bilan/historique" << endl;
        cout << "Entrez 4 pour quitter" << endl;
        cin >> choice;
        if(choice == 0)	add_commande();
        if(choice == 1) gestion_produit();
        if(choice == 2)
        {
            cout << "Entrez la date (ex : 23/04/2015 -> 23042015)" << endl;
            cin >> date;
            system("cls");
        }
        if(choice == 3) bilan();
    }

}













