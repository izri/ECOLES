#ifndef TABLEANALYSE_H
#define TABLEANALYSE_H
#include "etat.h"
#include <string>
#include <vector>
#include <queue>
#include "regle.h"
#include "grammaire.h"
#include "automate.h"

using namespace std;

class tableAnalyse
{
    public:
        tableAnalyse(grammaire maGrammaire, automate monAutomate);
        void affichage();
        int numeroColonne(string transition);
        void majShift();
        void majReduce();
        bool appartientAuLangage(queue<string> mot, vector<string> pileSymbole, vector<int> pileEtat); // Priorité aux shifts
        void affichageMot (queue<string> mot);
        int** tabShift;
        int** tabReduce;
        grammaire maGrammaire;
        automate monAutomate;
};

#endif // TABLEANALYSE_H
