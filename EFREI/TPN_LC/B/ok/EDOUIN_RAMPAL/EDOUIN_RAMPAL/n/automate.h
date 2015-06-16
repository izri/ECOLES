#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <string>
#include<vector>
#include "regle.h"
#include<iostream>
#include "grammaire.h"
#include "etat.h"
#include "transition.h"

using namespace std;

class automate
{
    public:
        automate();
        automate(grammaire maGrammaire);
        bool etatDejaPresent(etat etatEtudie);
        int etatIdentique(etat etatEtudie); // Retourne l'etat de l'indice
        vector<etat> etats;
        vector<transition> transitions;
};

#endif // AUTOMATE_H
