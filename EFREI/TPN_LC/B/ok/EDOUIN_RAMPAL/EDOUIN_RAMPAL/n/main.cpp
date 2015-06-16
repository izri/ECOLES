#include <iostream>
#include <fstream>
#include<string>
#include "grammaire.h"
#include "etat.h"
#include "automate.h"
#include "tableAnalyse.h"
#include <vector>

using namespace std;

int main()
{
    grammaire maGrammaire("grammaire");
    automate monAutomate(maGrammaire);
    tableAnalyse tab(maGrammaire, monAutomate);
    tab.affichage();

    vector<string> pileSymbole;
    vector<int> pileEtat;
    pileEtat.push_back(0);
    // On charge le mot étudié "à la main"
    queue<string> mot;
    mot.push("a");
    mot.push("a");
    mot.push("b");
    mot.push("a");
    mot.push("b");
    mot.push("b");
    mot.push("$");

    if(!tab.appartientAuLangage(mot, pileSymbole, pileEtat)) // On appelle ici l'execution du parser
        cout << endl << "Le mot n'appartient pas au langage"<< endl << endl;

    return 0;
}
