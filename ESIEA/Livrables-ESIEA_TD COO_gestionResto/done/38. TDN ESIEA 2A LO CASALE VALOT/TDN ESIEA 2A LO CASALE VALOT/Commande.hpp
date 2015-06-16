#ifndef COMMANDE_HPP_INCLUDED
#define COMMANDE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include "Menu.hpp"
#include "Date.hpp"

using namespace std;


class Commande{
private:
    Date date;
    Menu * menu;
    unsigned int id_client;
    unsigned int id;
    unsigned int * id_produit;
    unsigned int * id_menu;

private:
    void get_date();


};

#endif // COMMANDE_HPP_INCLUDED
