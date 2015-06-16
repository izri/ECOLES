#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED


#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Menu{
private :
    string nom;
    unsigned int prix;
    unsigned int * id;
public :
    Menu();
    Menu(string n, unsigned int p);

    void set_prix(unsigned int p);
    void set_nom(string n);

    void get_menu();
    void new_menu();

    string get_nom();
    unsigned int get_prix();
    unsigned int get_id();
};



#endif // MENU_HPP_INCLUDED
