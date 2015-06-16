#include "regle_MM.h"
#include <iostream>

using namespace std;


//creation d'une regle à partir de deux chaines de caractères
regle::regle(string nT, string deri)
{
    this->noTerm = nT;
    this->derivations.push_back(deri);
}


//Création d'une regle
regle::regle(string l)
{
    int cpt = 0;

    noTerm = "";
    while (( l[cpt] != 32 && l[cpt] !=  9 && l[cpt] && 13) && (cpt <= l.length()))
        {
        noTerm += l[cpt];
        cpt++;
    }

    cpt++;
    while (cpt <= l.length()) {
        string sBuffer ="";
        while( l[cpt] != 32 && l[cpt] !=  9 && l[cpt] && 13) {
            sBuffer += l[cpt];
            cpt++;
        }
        derivations.push_back(sBuffer);
        cpt++;
    }
}


//Affichage d'une regle avec ses derivations
void regle::display() {
    cout << noTerm << " -> ";
    for (int cpt = 0; cpt < derivations.size(); cpt++) {
        cout << derivations[cpt] << " ";
    }
    cout << endl;
}


