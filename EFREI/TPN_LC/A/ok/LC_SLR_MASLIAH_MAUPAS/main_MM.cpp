#include <iostream>
#include <fstream>
#include<string>
#include "grammar_MM.h"

using namespace std;

int main()
{
    cout << "======================================================" << endl << "=== Projet realise par Robin Masliah & Paul Maupas ===" << endl << "======================================================" << endl << endl;


    vector<string> firsts1;
    vector<string> firsts2;

    vector<string> follow1;
    vector<string> follow2;


    Grammar grammaire; ///crée un élément de type grammaire et lit le fichier
    grammaire.display();    ///affiche la grammaire


    cout << "=== PREMIERS === " << endl;
    for (int cpt = 0 ; cpt < grammaire.non_terminaux.size() ; cpt++)
    {
        string tmp = grammaire.non_terminaux[cpt];
        firsts1.clear();
        firsts2 = grammaire.first(&firsts1, tmp);

        cout << "Les premiers de " << tmp << " sont : " << endl;
        for (int cpt2 = 0 ; cpt2 < firsts2.size() ; cpt2++) {
            cout << " - F(" << tmp <<") = " << firsts2[cpt2] << endl;
        }
    }


    cout << endl << "=== SUIVANTS ===" << endl;
   for(int cpt2 = 0; cpt2 < grammaire.non_terminaux.size() ; cpt2++)
    {
        string tmp = grammaire.non_terminaux[cpt2];
        follow1.clear();
        follow2 = grammaire.follows(&follow1, tmp, &firsts2);

        cout << "Les suivants de " << tmp << " sont : " << endl;
        for(int cpt3 = 0 ; cpt3 < follow2.size() ; cpt3++)
        {
            cout << " - S (" << tmp <<") = " << follow2[cpt3] << endl;
        }
    }



    return 0;
}
