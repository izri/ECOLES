#ifndef CONSOMABLE_HPP_INCLUDED
#define CONSOMABLE_HPP_INCLUDED


#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Consomable{
private :
    string type;
    string nom;
    unsigned int qte;
    unsigned int prix_cout;
    unsigned int id;
public :
    Consomable();
    Consomable(string t, string n, unsigned int q, unsigned int p);

    void set_cout(unsigned int p);
    void set_nom(string n);
    void set_type(string t);

    void new_consomable();

    string get_type();
    string get_nom();
    unsigned int get_cout();
    unsigned int get_id();
};


#endif // CONSOMABLE_HPP_INCLUDED
