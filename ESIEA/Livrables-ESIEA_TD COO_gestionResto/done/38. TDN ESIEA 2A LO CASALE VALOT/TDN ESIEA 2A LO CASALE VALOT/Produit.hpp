#ifndef PRODUIT_HPP_INCLUDED
#define PRODUIT_HPP_INCLUDED


#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Produit{
private :
    string type;
    string nom;
    unsigned int prix;
    unsigned int * id_consomable;
    unsigned int id;
public :
    Produit();
    Produit(string t, string n);

    void set_prix(unsigned int p);
    void set_nom(string n);
    void set_type(string t);

    void add_consomable();
    void new_produit();

    string get_type();
    string get_nom();
    unsigned int get_prix();
    unsigned int get_id();
};


#endif // PRODUIT_HPP_INCLUDED
