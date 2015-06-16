#include <iostream>
#include <string>
#include "classcommande.hpp"
#include <windows.h>
using namespace std;


commande::commande(produits premier,string anne)
{
    date = anne;
    liste.push_back(premier);
}

commande::commande(string anne)
{
    date = anne;
}




void commande::afficherCMD()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned int i, recette=0;
    cout<< "------------------------------------------------------------------------------\n";
    SetConsoleTextAttribute(hConsole, 13);
    cout<< "\t\t\tCOMMANDE\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout<< "Faite le "<< date << "\nelle est composee de :\n\n";
    for (i = 0; i < liste.size(); i++)
    {
        recette += liste.at(i).price;
        (liste.at(i)).pirnt_P();
    }
    cout<< "Soit un total de " << recette << " euros\n\n";
    cout<< "------------------------------------------------------------------------------\n";
}


void commande::ajouterpo(produits a)
{
    liste.push_back(a);
}


int commande::total()
{
    unsigned int i,recette =0;
    for (i=0;i<liste.size();i++)
    {
        recette += liste.at(i).price;
    }
    return recette;
}