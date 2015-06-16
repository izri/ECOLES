#include "tableAnalyse.h"
#include "etat.h"
#include <string>
#include <vector>
#include <queue>
#include "regle.h"
#include "grammaire.h"
#include "automate.h"
#include "transition.h"

using namespace std;

string test;

tableAnalyse::tableAnalyse(grammaire g, automate a) {
    maGrammaire = g;
    monAutomate = a;
    //Allocation des tableaux dynamiques
    tabShift = new int*[maGrammaire.alphabet.size() + 1] ; // Notre tableau à un nombre de colonne égal à l'alphabet + le $
    tabReduce = new int*[maGrammaire.alphabet.size() + 1] ;
    for (unsigned int cpt = 0; cpt < (maGrammaire.alphabet.size() + 1); cpt++) {
        tabShift[cpt] = new int[monAutomate.etats.size()]; // Autant de lignes que d'état dans l'automate
        tabReduce[cpt] = new int[monAutomate.etats.size()];
    }

    //Initialisation des tableaux
    for (unsigned int cpt1 = 0; cpt1 < (maGrammaire.alphabet.size() + 1); cpt1++) {
        for (unsigned int cpt2 = 0; cpt2 < monAutomate.etats.size(); cpt2++) {
            tabShift[cpt1][cpt2] = -1;
            tabReduce[cpt1][cpt2] = -1;
        }
    }

    // Mise à jour des deux tableaux
    majShift();
    majReduce();
}

void tableAnalyse::affichage() {
    cout << "Table des shift : " << endl << endl;
    // Affichage des entêtes des colonnes
    cout << "   ";
    for (unsigned int cpt = 0; cpt < maGrammaire.terminaux.size(); cpt++) {
        cout << maGrammaire.terminaux[cpt] << " ";
    }
    cout << "$ ";

    for (unsigned int cpt = 0; cpt < maGrammaire.nonTerminaux.size(); cpt++) {
        cout << maGrammaire.nonTerminaux[cpt] << " ";
    }
    cout << endl << endl;

    for (unsigned int cpt2 = 0; cpt2 < monAutomate.etats.size(); cpt2++) {
        cout << cpt2 << " ";
        if (cpt2 <10) cout << " ";
        for (unsigned int cpt1 = 0; cpt1 < (maGrammaire.alphabet.size() + 1); cpt1++) {
            if (tabShift[cpt1][cpt2] != -1)
                cout << tabShift[cpt1][cpt2] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "Table des reduce : " << endl << endl;
    // Affichage des entêtes des colonnes
    cout << "   ";
    for (unsigned int cpt = 0; cpt < maGrammaire.terminaux.size(); cpt++) {
        cout << maGrammaire.terminaux[cpt] << " ";
    }
    cout << "$ ";

    for (unsigned int cpt = 0; cpt < maGrammaire.nonTerminaux.size(); cpt++) {
        cout << maGrammaire.nonTerminaux[cpt] << " ";
    }
    cout << endl << endl;

    for (unsigned int cpt2 = 0; cpt2 < monAutomate.etats.size(); cpt2++) {
        cout << cpt2 << " ";
        if (cpt2 <10) cout << " ";
        for (unsigned int cpt1 = 0; cpt1 < (maGrammaire.alphabet.size() + 1); cpt1++) {
            if (tabReduce[cpt1][cpt2] != -1)
                cout << tabReduce[cpt1][cpt2] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int tableAnalyse::numeroColonne(string trans){ // Prend un symbole de l'alphabet pour donner la colonne à laquel il corresponf
    int position;
    if (trans == "$") {
        return maGrammaire.terminaux.size();
    }

    //On trouve sa position dans l'alphabet
    for (unsigned int cpt = 0; cpt < maGrammaire.alphabet.size(); cpt++) {
        if (maGrammaire.alphabet[cpt] == trans) position = cpt;
    }

    // Si le symbole est nonTerminal il sera après la colonne du $ donc on rajoute 1
    if(maGrammaire.estNonTerminal(trans)) {
        position++;
    }
    return position;
}

void tableAnalyse::majShift() { // Utilise les transitions de l'automate pour construire la table des shifts
    for (unsigned int cpt = 0; cpt < monAutomate.transitions.size(); cpt++) {
        int positionCol = numeroColonne(monAutomate.transitions[cpt].symbole);
        tabShift[positionCol][monAutomate.transitions[cpt].origine] = monAutomate.transitions[cpt].destination;
    }
}

void tableAnalyse::majReduce() { //Detecte les règles finales pour construire la table des reduces
    vector<string> derivationAxiome;
    derivationAxiome.push_back(maGrammaire.regles[0].nonTerminal);
    regle regleAxiome(maGrammaire.regles[0].nonTerminal+"'",derivationAxiome);

    for (unsigned int cpt1 = 0; cpt1 < monAutomate.etats.size(); cpt1++) {
        for (unsigned int cpt2 = 0; cpt2 < monAutomate.etats[cpt1].regles.size(); cpt2++) {
            if (monAutomate.etats[cpt1].regles[cpt2].pointFinal()) {// Si la règle étudié est avec un point final
                monAutomate.etats[cpt1].regles[cpt2].derivation.pop_back(); // On enlève le point
                if (monAutomate.etats[cpt1].regles[cpt2] == regleAxiome) { // Si il s'agit de la règle rajouté avec le nouvel axiome
                    tabReduce[maGrammaire.terminaux.size()][cpt1] = 1;
                }
                else {
                    for (unsigned int cpt3 = 0; cpt3 < maGrammaire.regles.size(); cpt3++) { // On cherche à savoir de quelle règle il s'agit
                        if(maGrammaire.regles[cpt3] == monAutomate.etats[cpt1].regles[cpt2]) { // Si c'est la même règle
                            vector<string> suivants; // On rajoute les suivants en dur dans le code
                            if (cpt3 < 2) {
                                suivants.push_back("a");// ICI
                                suivants.push_back("b");// LES SUIVANTS
                                suivants.push_back("$");// SONT AJOUTES A LA MAIN
                            }
                            else suivants.push_back("a");// DE MEME

                            //vector<string> suivants = maGrammaire.suivant(maGrammaire.regles[cpt3].nonTerminal);
                            for (unsigned int cpt4 = 0; cpt4 < suivants.size(); cpt4++) { // On parcoure les suivants du nonTerminal de la règle pour placer les reduce
                                int positionCol = numeroColonne(suivants[cpt4]);
                                tabReduce[positionCol][cpt1] = (cpt3 + 2); // On rajoute deux pour obtenir un décompte à partir de 1 avec la règle du nouvel axiome
                            }
                        }
                    }
                }
            }
        }
    }

}

bool tableAnalyse::appartientAuLangage(queue<string> mot, vector<string> pileSymbole, vector<int> pileEtat) { // GESTION DE L'EXECUTION DU PARSER POUT UN MOT
    queue<string> motCopie = mot;
    vector<string> pileSymboleCopie = pileSymbole;
    vector<int> pileEtatCopie = pileEtat;
    cout << "- - - - - - - - - - - - - - -" << endl << endl;
    cout << "Pile : ";
    for (unsigned int cpt = 0; cpt < pileSymbole.size(); cpt++) {
        cout << pileEtat[cpt] << " " << pileSymbole[cpt] << " ";
    }
    cout << pileEtat[pileEtat.size()-1] << endl;

    cout << "Entree :";
    affichageMot(mot);
    cout << endl;

    cout << "Sortie : ";
    int positionCol = numeroColonne(mot.front());

    // LES SHIFTS PASSENT EN PRIORITE

    if (tabShift[positionCol][pileEtat.back()] != -1) { // SHIFT
        cout << "s" << tabShift[positionCol][pileEtat.back()] << endl << endl;
        pileSymbole.push_back(mot.front());
        pileEtat.push_back(tabShift[positionCol][pileEtat.back()]);
        mot.pop();
        if(appartientAuLangage(mot, pileSymbole, pileEtat))
            return true;
        else { // Ici on fait comme si le shift n'avait pas été appliquer
            pileSymbole = pileSymboleCopie;
            pileEtat = pileEtatCopie;
            mot = motCopie;
            queue<string> motCopie = mot;
            vector<string> pileSymboleCopie = pileSymbole;
            vector<int> pileEtatCopie = pileEtat;
            cout << "- - - - - - - - - - - - - - -" << endl << endl;
            cout << "Pile : ";
            for (unsigned int cpt = 0; cpt < pileSymbole.size(); cpt++) {
                cout << pileEtat[cpt] << " " << pileSymbole[cpt] << " ";
            }
            cout << pileEtat[pileEtat.size()-1] << endl;

            cout << "Entree :";
            affichageMot(mot);
            cout << endl;

            cout << "Sortie : ";
        }
    }

    if (tabReduce[positionCol][pileEtat.back()] != -1) { // REDUCE
        if (tabReduce[positionCol][pileEtat.back()] == 1) {
            cout << "Acceptable. Le mot appartient au langage." << endl << endl;
            return true;
        }
        else {
            int numeroRegle = tabReduce[positionCol][pileEtat.back()] - 2;
            cout << "r" << tabReduce[positionCol][pileEtat.back()] << " : ";
            maGrammaire.regles[numeroRegle].affichage();
            cout << endl << endl;
            for (unsigned int cpt = 0; cpt < maGrammaire.regles[numeroRegle].derivation.size(); cpt++) {
                pileSymbole.pop_back();
                pileEtat.pop_back();
            }

            pileSymbole.push_back(maGrammaire.regles[numeroRegle].nonTerminal);
            positionCol = numeroColonne(pileSymbole.back());
            pileEtat.push_back(tabShift[positionCol][pileEtat.back()]);
            if(appartientAuLangage(mot, pileSymbole, pileEtat))
                return true;
            else {
                pileSymbole = pileSymboleCopie;
                pileEtat = pileEtatCopie;
                mot = motCopie;
            }
        }
    }

    if ((tabShift[positionCol][pileEtat.back()] == -1) && (tabReduce[positionCol][pileEtat.back()] == -1)) { //IMPASSE
        cout << "IMPASSE" << endl << endl;
        return false;
    }
    return false;
}

void tableAnalyse::affichageMot (queue<string> mot) {
    queue<string> copieMot;
    copieMot = mot;

    while (!copieMot.empty()) {
        cout << copieMot.front() << " ";
        copieMot.pop();
    }
}
