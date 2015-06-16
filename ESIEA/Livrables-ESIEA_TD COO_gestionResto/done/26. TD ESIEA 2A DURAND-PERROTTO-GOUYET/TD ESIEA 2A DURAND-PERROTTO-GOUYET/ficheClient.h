#ifndef FICHECLIENT_H
#define FICHECLIENT_H

#include "resto.hpp"

using namespace std;

class Client : public Printable
{
prive :
    string prenom, nom;
    bool genre;

public :
    Client(const string prenom, const string nom, const float genre);
    const string get_prenom();
    const string get_nom();
    const bool get_genre();
    const string to_string();
    void affichage();
};



#endif // FICHECLIENT_H



