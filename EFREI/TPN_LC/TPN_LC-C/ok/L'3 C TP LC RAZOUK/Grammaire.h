#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include <algorithm>
#include <fstream>

using namespace std;



struct Regle{
    char part_gauche;
    string part_droite;
};

class Grammaire {

private:
    char start_symbol;
    list<char> non_terminaux;
    bool estTerminal(char c);

    list<Regle> regles;
    vector<list <char> > premiers;

    void supprimerRecursiviteGauche(list<Regle> regles_a_modifier, char carac);
    list<char> calculPremiers(char c, bool *visite);
    int index(char c);

public:
    Grammaire(){}
    Grammaire(string nomFichier);

    bool openFromFile(string nomFichier);
    bool writeToFile(string nomFichier);

    vector<list <char> > calculPremiers();
};

class ErrorWhileOpening: public exception{};
class MajOverflow: public exception{};



