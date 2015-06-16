#ifndef HISTORIQUE_HPP_INCLUDED
#define HISTORIQUE_HPP_INCLUDED


#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Historique{
private:
    unsigned int * id_commande;
    unsigned int id;
public:
    Historique();
    Historique(int n);
    void new_commande();
    void show();

};

#endif // HISTORIQUE_HPP_INCLUDED
