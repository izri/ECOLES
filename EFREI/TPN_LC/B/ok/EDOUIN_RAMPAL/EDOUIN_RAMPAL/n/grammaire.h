#ifndef GRAMMAIRE_H
#define GRAMMAIRE_H
#include <list>
#include "regle.h"
#include <queue>

using namespace std;

class grammaire
{
    public:
        grammaire(){};
        grammaire(string nomFichier); //pour l'instant uniquement pour grammaire.txt
        grammaire(vector<regle>);
        grammaire grammaireRecursGauche(vector<string> recursif);
        vector<string> aRecursGauche();
        void affichage();
        void majNonTerminaux();
        void majTerminaux();
        void majAlphabet();
        bool estNonTerminal(string symbole);
        /**< PARTIE DEDIEE AU CALCUL DES FIRST ET FOLLOW */
        vector<string> CalculFirstFollow(string nonTerminal); // Englobe les first et follow pour renvoyer un simple vecteur des suivants
        vector<string> premier(vector<string> *VecPremier, string nonTerminal);
        bool DoublonVector(vector<string> Vector, string Terminal);
        bool contientMotVide(vector<string> VecPremier) ;
        vector<string> suivant(vector<string> *VecSuivant, string nonTerminal);
        void popEpsilon(vector<string> *VecTor);

        vector<regle> regles;
        vector<string> nonTerminaux;
        vector<string> terminaux;
        vector<string> alphabet;
};
#endif // GRAMMAIRE_H
