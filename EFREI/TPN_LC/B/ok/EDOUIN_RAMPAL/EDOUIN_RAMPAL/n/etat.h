#ifndef ETAT_H
#define ETAT_H
#include <string>
#include<vector>
#include "regle.h"
#include<iostream>
#include "grammaire.h"

using namespace std;


class etat
{
    public:
        etat();
        void creationEtat0(grammaire maGrammaire);
        etat goTo(string trans, grammaire maGrammaire);
        void affichage();
        bool operator==(etat a);
        bool aUneTransition(string trans);
        bool etatTerminal();

        int indice;
        vector<regle> regles;
};


#endif // ETAT_H
