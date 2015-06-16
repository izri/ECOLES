#include <iostream>
#include "GABBAI - BENET - Grammaire.h"

using namespace std;

int main()
{
    Grammaire g2 = lireFichier();
    Grammaire g(g2);
    cout << "----- Grammaire d'origine -----" << endl << endl;
    g.afficher();
    cout << endl << endl << "----- Nouvelles Regles -----" << endl << endl;
    g.modifierRegles();
    g.afficher();
    cout << endl << endl << "----- Calcul des Items -----" << endl << endl;
    vector<Grammaire> listeItems;
    listeItems.push_back(g);
    vector<Regle> reglesI0 = g.getRegles();
    listeItems = g.calculItems(listeItems, reglesI0);
    unsigned int i = 0;
    for(vector<Grammaire>::iterator it = listeItems.begin(); it != listeItems.end(); ++it)
    {
        cout << "I" << i << ":" << endl;
        cout << endl << endl << "Successeurs : ";
        vector <unsigned int> succ = it->getSucc();
        for(vector<unsigned int>::iterator it2 = succ.begin(); it2 != succ.end(); ++it2) cout << *it2 << " ";
        cout << endl << *it << endl << endl << "-------" << endl << endl;
        i++;
    }
    cout << endl << endl << "----- Calcul des First -----" << endl << endl;
    vector<Ensemble> premier = g2.calculPremiers();
    for(vector<Ensemble>::iterator it = premier.begin(); it != premier.end(); ++it)
    {
        cout << "Premier de " << *it << endl;
    }

    cout << endl << endl << "----- Calcul des Follow -----" << endl << endl;
    vector<Ensemble> suivants = g2.calculSuivants(premier);
    for(vector<Ensemble>::iterator it = suivants.begin(); it != suivants.end(); ++it)
    {
        cout << "Suivant de " << *it << endl;
    }
    return 0;
}
