#ifndef GRAMMAIRE_H
#define GRAMMAIRE_H
#include <list>
#include <queue>
#include "regle_MM.h"

using namespace std;

class Grammar
{
    public:
        vector<string> non_terminaux;


        //Affichage
        void display();
        void refreshNonTerm();
        bool isNoTerminal(string symbole);

        //First
        vector<string> first(vector<string> *Firsts, string nonTerminal);
        bool doubleFirst(vector<string> Firsts, string Terminal);

        //Follow
        bool doubleFollow(vector<string> Follows, string Terminal);
        bool is_present(vector<string> Firsts, string c);
        vector<string> follows(vector<string> *Follows, string nonTerminal, vector<string> *Firsts);


        //Automate
        void add_starter();

        //Constructeurs
        Grammar();
        Grammar(vector<regle>);


    protected:
    private:
        vector<regle> regles;
};

#endif // GRAMMAIRE_H
