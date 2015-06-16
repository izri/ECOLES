#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include "classclients.hpp"
#include "classproduit.hpp"


using namespace std;

class basedonne
{
    public:
        vector <client> liste;
        basedonne (string nom){liste.push_back(client(nom));}
        basedonne(){};
        void afficher ();
        int chercherNOM(string nom);
        void ajouter (string nom);
};


void basedonne::afficher ()
{
    unsigned int i;
    for (i = 0; i < liste.size(); i++)
    {
        (liste.at(i)).print_cl();
        cout << endl;
    }
}


int basedonne::chercherNOM (string nom)
{
    unsigned int i;
    for (i = 0; i < liste.size(); i++)
    {
        if (nom == (liste.at(i).name))
        {
                return i;
        }
    }
    return -1;
}


void basedonne::ajouter (string nom)
{
        if ((basedonne::chercherNOM(nom))!=-1) cout << "Le client existe deja" << endl;
        else liste.push_back(client(nom));
}




int main ()
{
    //fonction pour les couleurs de la console
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //debut de programe


    string nom, date, secure;
    basedonne entite;
    int choix = 0;

    SetConsoleTextAttribute(hConsole, 10);
    cout << "*******************************************************************************\n";
    cout << "*******************************************************************************\n";
    cout << "***************";
    SetConsoleTextAttribute(hConsole, 11);
    cout << " Bienvenue dans le systeme de restauration";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " *********************\n";
    cout << "*******************************************************************************\n";
    cout << "*******************************************************************************\n";
    SetConsoleTextAttribute(hConsole, 15);




    cout << "\n\n\tVeuillez saisir la date d'aujourd'hui\n\t(jj/mm/aaaa)\n\t";
    getline(cin, date);


    while (choix != 5)
    {
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n\n==============================================================================\n";
        SetConsoleTextAttribute(hConsole, 11);
        cout << "||\tMenu principal\n||\t1.Ajouter une commande\n||\t2.Aficher l'ensemble des clients\n||\t3.Chercher un client dans la base de donnee\n||\t4.Obtenir les infos d'un client\n||\t5.Quitter\n";
        SetConsoleTextAttribute(hConsole, 9);
        cout << "==============================================================================\n";
        SetConsoleTextAttribute(hConsole, 15);
        getline(cin, secure);
        std::istringstream is(secure);
        is >> choix;
        //cin.clear();
        is.clear();

        switch (choix)
        {

            case 1:
            {
                string namme;
                commande neuve(date);
                int val = 0, fini = 0, i = 0;
                bool prob = false;

                cout << "Merci de saisir le nom du client" << endl;//on récupère le nom du client pour voir si il est enregistrer dans la base de donnée
                SetConsoleTextAttribute(hConsole, 12);
                getline(cin, nom);
                SetConsoleTextAttribute(hConsole, 15);

                if (entite.chercherNOM(nom)==-1)//si il est nouveau
                {
                    entite.ajouter(nom);
                    do
                    {
                        prob = false;
                        cout << endl << "\nVeuillez choisir un produit\n1.Pizza\n2.Salade\n3.Plat du jour\n4.Dessert\n5.Boissons\n\n";
                        getline(cin, secure);
                        std::istringstream is(secure);
                        is >> val;
                        is.clear();
                        switch (val)
                        {
                            case 1:
                                cout << "Entrez le nom de la pizza\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(pizza(namme));
                                break;

                            case 2:
                                cout << "Entrez le nom de la salade\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(vegeta(namme));
                                break;

                            case 3:
                                neuve.ajouterpo(jour("Plat du jour"));
                                break;

                            case 4:
                                cout << "Entrez le nom du dessert\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(dessert(namme));
                                break;

                            case 5:
                                cout << "Entrez le nom de la boisson\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(boisson(namme));
                                break;

                            default :
                                cout << "Probleme de saisi\nVeuillez recommencer\n";
                                prob = true;
                        }
                        if(!prob)
                        {
                            do
                            {
                                cout << "Voulez-vous ajouter un autre produit ?(y/n):";
                                getline(cin, secure);
                            } while (secure.compare("y") != 0 && secure.compare("n") != 0);

                            if (secure.compare("y") == 0) fini = 1;
                            else fini = 0;
                        }
                        else fini = 1;
                    } while (fini);
                    entite.liste.at((entite.liste.size()-1)).historisque.push_back(neuve);
                    entite.liste.at((entite.liste.size()-1)).frequence ++;
                    entite.liste.at((entite.liste.size()-1)).recette += neuve.total();
                    cout << "\n";
                    neuve.afficherCMD();
                    break;
                }
                else //s'il est déjà connu
                {
                    while (nom != entite.liste.at(i).name) i++;
                    entite.liste.at(i).frequence ++;
                    do
                    {
                        prob = false;
                        cout << endl << "\nVeuillez choisir un produit\n1.Pizza\n2.Salade\n3.Plat du jour\n4.Dessert\n5.Boissons\n\n";
                        getline(cin, secure);
                        std::istringstream is(secure);
                        is >> val;
                        switch (val)
                        {
                            case 1:
                                cout << "Entrez le nom de la pizza\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(pizza(namme));
                                break;

                            case 2:
                                cout << "Entrez le nom de la salade\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(vegeta(namme));
                                break;

                            case 3:
                                neuve.ajouterpo(jour("Plat du jour"));
                                break;

                            case 4:
                                cout << "Entrez le nom du dessert\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(dessert(namme));
                                break;

                            case 5:
                                cout << "Entrez le nom de la boisson\n";
                                SetConsoleTextAttribute(hConsole, 10);
                                getline(cin, namme);
                                SetConsoleTextAttribute(hConsole, 15);
                                neuve.ajouterpo(boisson(namme));
                                break;

                            default :
                                cout << "Probleme de saisi\nVeuillez recommencer\n";
                                prob = true;
                        }
                        if(!prob)
                        {
                            do
                            {
                                cout << "Voulez-vous ajouter un autre produit ?(y/n):";
                                getline(cin, secure);
                            } while (secure.compare("y") != 0 && secure.compare("n") != 0);

                            if (secure.compare("y") == 0) fini = 1;
                            else fini = 0;
                        }
                        else fini = 1;
                    } while(fini);
                    entite.liste.at(i).historisque.push_back(neuve);
                    cout << "\n";
                    neuve.afficherCMD();
                    entite.liste.at(i).recette += neuve.total();
                }
                break;
            }

            case 2:
            {
                entite.afficher();
                break;
            }

            case 3:
            {
                cout << "Merci de saisir le nom du client" << endl;
                getline(cin, nom);

                if (entite.chercherNOM(nom)==-1) cout << "Le client n'est pas connu de la base de donnee" << endl;
                else cout << "Le client est enregistre" << endl;
                break;
            }

            case 4 :
            {
                string nomme;
                unsigned int i = 0, conteur;
                cout << "Saisir le nom du client souhaite\n";
                SetConsoleTextAttribute(hConsole, 12);
                getline(cin, nomme);
                SetConsoleTextAttribute(hConsole, 15);

                while (i < entite.liste.size() && entite.liste.at(i).name != nomme) i++;
                if (i >= entite.liste.size()) cout << "Le client n'est jamais venu\n\n";
                else
                {
                    entite.liste.at(i).print_cl();
                    cout << "Ce client a " << entite.liste.at(i).historisque.size() << " commandes\n";
                    for (conteur = 0; conteur < entite.liste.at(i).historisque.size(); conteur ++) entite.liste.at(i).historisque.at(conteur).afficherCMD();
                }
                break;
            }

            case 5:
            {
                break;
            }

            default :
            {
                cout << "Probleme de saisi\nVeuillez recommencer\n";
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    return 0;
}
