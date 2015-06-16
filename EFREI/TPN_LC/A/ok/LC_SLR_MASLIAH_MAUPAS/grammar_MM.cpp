#include "grammar_MM.h"
#include "regle_MM.h"

#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

Grammar::Grammar()
{
    ifstream file ("grammaire.txt");
    string line;

    if (file) {
        while (!file.eof()) {
            getline(file,line);
            regle buffer(line);
            regles.push_back(buffer);
        }
        refreshNonTerm();
    }
    else
        cout << "Fichier introuvable." << endl;
}

vector<string> Grammar::first(vector<string> *Firsts, string nonTerminal)
{

    ///Balayage de toutes les regles
    for (int cpt = 0 ; cpt < regles.size() ; cpt++) {
        ///si
        if ((nonTerminal == regles[cpt].noTerm) && (nonTerminal != regles[cpt].derivations[0]))
        {
            if (!regles[cpt].derivations[0].empty()) /// n'est pas un mot vide
            {
                ///S'il est terminal et qu'il n'est pas déjà présent dans les premiers, on l'ajoute
                if ((!isNoTerminal(regles[cpt].derivations[0])) && (!doubleFirst(*Firsts, regles[cpt].derivations[0])))
                {
                    Firsts->push_back(regles[cpt].derivations[0]);
                }
                else
                {
                    first(Firsts,regles[cpt].derivations[0]); /// recherche des premiers dans les non terminaux
                }
            }
            else
            {
                Firsts->push_back("e");
            }
        }
    }
    return *Firsts;
}


bool Grammar::is_present(vector<string> First, string c)
{
    for (int cpt = 0; cpt < First.size(); cpt ++)
    {
        if(First[cpt] == c)
            return true;
    }

}


vector<string> Grammar::follows(vector<string> *Follows, string noTerm, vector<string> *First)
{


    if(noTerm == regles[0].noTerm)
    {
        Follows->push_back("$");
    }
   for (int cpt = 0 ; cpt < regles.size() ; cpt++)
    {
        for(int cpt2 = 0; cpt2 < regles[cpt].derivations.size() -1; cpt2++)
        {

            if(noTerm == regles[cpt].derivations[cpt2] )
            {;
                if(!isNoTerminal(regles[cpt].derivations[cpt2+1]))
                    Follows->push_back(regles[cpt].derivations[cpt2+1]);
            }

            else
            {
                ///If there is a production, A -> aB Bt, then (FIRST(Bt) - e) = FOLLOW(B).
                if(!is_present(*First,"e"))
                {
                    //Follows = Firsts;
                }
                else
                {
                    ///if there is a production, A-> aB, or a production A -> aB Bt ou e appartient à first(Bt), Follow(A) = Follow(B)
                    follows(Follows, regles[cpt].noTerm, First);
                }
            }

            //if

        }
    }
    return *Follows;
}


//Affichage d'une grammaire
void Grammar::display()
{
    cout << "=== AFFICHAGE DE LA GRAMMAIRE ===" << endl;
    for (int cpt = 0; cpt < regles.size(); cpt++) {
        regles[cpt].display();
    }
    cout << endl;
}

//test si le symbole est terminal ou non
bool Grammar::isNoTerminal(string symbole)
{
    for(int cpt =0; cpt < non_terminaux.size(); cpt++) {
        if(non_terminaux[cpt] == symbole)
            return true;
    }
    return false;
}


//Mise à jour des non terminaux
void Grammar::refreshNonTerm()
{
    non_terminaux.clear();
    list<string> nonTerm;

    for(int cpt =0; cpt < regles.size(); cpt++) {
        nonTerm.remove(regles[cpt].noTerm);
        nonTerm.push_back(regles[cpt].noTerm);
    }

    while (!nonTerm.empty()) {
        non_terminaux.push_back(nonTerm.front());
        nonTerm.pop_front();
    }
}


//Détection d'un doublon
bool Grammar::doubleFirst(vector<string> Firsts, string Terminal)
{
    for (int cpt = 0 ; cpt < Firsts.size() ; cpt++) {
        if (Firsts[cpt] == Terminal)
            return true;
    }
}
