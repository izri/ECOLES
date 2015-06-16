#include <iostream>
#include <string>
#include <fstream>

#include "Restaurant.h"

using namespace std;


Client::Client()
{
 cout << endl << "Nom :";
 cin >> m_nom ;
 cout << endl << "Prenom :";
 cin >> m_prenom ;
}
string Client::getnom() const
{
    return m_nom;
}
string Client::getprenom() const
{
    return m_prenom;
}


Restaurant::Restaurant()
{
    cout << "Entrez les plat que votre restaurent propose" << endl << "menu 1 :" << endl;
    Menu menu1;
    cout << "menu 2" << endl;
    Menu menu2;
    carte[0]=menu1.getEntree();
    carte[1]=menu1.getPlatPrincipal();
    carte[2]=menu1.getDessert();
    carte[3]=menu1.getBoisson();
    carte[4]=menu2.getEntree();
    carte[5]=menu2.getPlatPrincipal();
    carte[6]=menu2.getDessert();
    carte[7]=menu2.getBoisson();
}

Menu Restaurant::getMenu1() const
{
    return menu1;
}

Menu Restaurant::getMenu2() const
{
    return menu2;
}

Menu::Menu()
{
cout << endl << "entree : ";
Plat entree;
cout << endl << "Plat principal : ";
Plat principal;
cout << endl << "dessert : ";
Plat dessert;
cout << endl << "Boisson : ";
Plat boisson;
prix = (entree.getPrix() + principal.getPrix() + dessert.getPrix() + boisson.getPrix())*0.9;
}

void Menu::consulterMenu() const
{
     cout << "Voici le menu proposé :" << endl;
     cout << entree.lirePlat() << endl << principal.lirePlat() << endl << dessert.lirePlat() << endl << boisson.lirePlat() << endl << prix << endl;
}

int Menu::getPrix() const
{
    return prix;
}

Plat::Plat()
{
    cout << endl << "Nom :";
    cin >> m_nom;
    cout << endl << "Prix :";
    cin >> prix ;
}

Plat Menu::getEntree() const
{
    return entree;
}
Plat Menu::getPlatPrincipal() const
{
    return principal;
}
Plat Menu::getBoisson() const
{
    return boisson;
}
Plat Menu::getDessert() const
{
    return dessert;
}

string Plat::lirePlat() const
{
    return m_nom;
}
double Plat::getPrix() const
{
    return prix;
}
