#include "grammaire.h"
#include <fstream>
#include <vector>
#include "regle.h"
#include <iostream>
#include <queue>

using namespace std;

grammaire::grammaire(string nomFichier) {
    ifstream sourceGrammaire ("grammaire.txt");
    string line;

    if (sourceGrammaire) {
        while (!sourceGrammaire.eof()) {
            getline(sourceGrammaire,line);
            regle buffer(line);
            regles.push_back(buffer);
        }
        majAlphabet();
    }


    else cout << "Fichier introuvable.";
}

grammaire::grammaire(vector <regle> ensembleRegles) {
    regles = ensembleRegles;
    majAlphabet();
}
grammaire grammaire::grammaireRecursGauche(vector<string> recursif) {
    if (recursif.empty()) return *this; // Si il n'y a pas de récursivité gauche
    vector<string> nouvelleDeriv;

    //Initialisation d'un tableau qui nous dira quelle règle n'ont pas été modifiée et seront à réajouter
    grammaire nouvelleGrammaire;
    bool* regleModifiee = new bool[regles.size()];
    for (int cpt =0; cpt < regles.size(); cpt++) {
        regleModifiee[cpt] = false;
    }

    // Recuperation des alpha et beta
    for (int cpt2=0; cpt2 < recursif.size(); cpt2++) {
        for(int cpt1 =0; cpt1 < regles.size(); cpt1++) {
            if (regles[cpt1].nonTerminal == recursif[cpt2]) { // Si on est face à une règle qui sera changé
                regleModifiee[cpt1] = true;
                if (regles[cpt1].nonTerminal != regles[cpt1].derivation[0]) {
                    for (int cpt3 = 0; cpt3 < regles[cpt1].derivation.size(); cpt3++) {
                        nouvelleDeriv.push_back(regles[cpt1].derivation[cpt3]);
                    }
                    regle nouvelleRegle(regles[cpt1].nonTerminal,nouvelleDeriv);
                    nouvelleRegle.derivation.push_back(regles[cpt1].nonTerminal+"'");
                    //cout << "Creation de la regle : ";
                    //nouvelleRegle.affichage();
                    nouvelleGrammaire.regles.push_back(nouvelleRegle);
                    nouvelleDeriv.clear();
                }


                else  { // Si on est dans le cas R -> R*alpha
                    for (int cpt3 = 1; cpt3 < regles[cpt1].derivation.size(); cpt3++) { //Dans le cas alpha
                        nouvelleDeriv.push_back(regles[cpt1].derivation[cpt3]);
                    }
                    regle nouvelleRegle(regles[cpt1].nonTerminal+"'",nouvelleDeriv);
                    nouvelleRegle.derivation.push_back(regles[cpt1].nonTerminal+"'");
                    //cout << "Creation de la regle : ";
                    //nouvelleRegle.affichage();
                    nouvelleGrammaire.regles.push_back(nouvelleRegle);
                    nouvelleDeriv.clear();
                }
            }
        }
    }
    // Ajout du mot vide pour recursif'
    for (int cpt=0; cpt < recursif.size(); cpt++) {
        regle nouvelleRegle(recursif[cpt]+"'", nouvelleDeriv);
        //cout << "Creation de la regle : ";
        //nouvelleRegle.affichage();
        nouvelleGrammaire.regles.push_back(nouvelleRegle);
    }

    //AJout des règles inchangées
    for (int cpt =0; cpt < regles.size(); cpt++) {
        if (!regleModifiee[cpt]) {
            //cout << "Rajout de la regle : ";
            //regles[cpt].affichage();
            nouvelleGrammaire.regles.push_back(regles[cpt]);
        }
    }
    nouvelleGrammaire.majAlphabet();
    return nouvelleGrammaire;
}

vector<string> grammaire::aRecursGauche() {
    vector<string> recursif;
    //Test d'une récursivité à gauche
    for (int cpt =0; cpt < regles.size(); cpt++) {
        if (regles[cpt].nonTerminal == regles[cpt].derivation[0]) {
            cout << "Recursivite a gauche sur " << regles[cpt].nonTerminal << endl;
            recursif.push_back(regles[cpt].nonTerminal);
        }
    }
    cout << endl;
    return recursif;
}

void grammaire::affichage() {
    for (int cpt = 0; cpt < regles.size(); cpt++) {
        regles[cpt].affichage();
    }
    cout << endl;
}

void grammaire::majNonTerminaux() {
    nonTerminaux.clear();
    //cout << endl << "Non terminaux : ";
    list<string> nonTerm;

    for(int cpt =0; cpt < regles.size(); cpt++) {
        nonTerm.remove(regles[cpt].nonTerminal);
        nonTerm.push_back(regles[cpt].nonTerminal);
    }

    while (!nonTerm.empty()) {
        nonTerminaux.push_back(nonTerm.front());
        //cout << nonTerm.front() << " ";
        nonTerm.pop_front();
    }
    //cout << endl << endl;
}

void grammaire::majTerminaux() {
    terminaux.clear();
    //cout << endl << "Terminaux : ";
    list<string> term;

    for(int cpt =0; cpt < regles.size(); cpt++) {
        for(int cpt2 = 0; cpt2 < regles[cpt].derivation.size(); cpt2++) {
            if(!estNonTerminal(regles[cpt].derivation[cpt2])) {
                term.remove(regles[cpt].derivation[cpt2]);
                term.push_back(regles[cpt].derivation[cpt2]);
            }
        }
    }

    while (!term.empty()) {
        terminaux.push_back(term.front());
        //cout << term.front() << " ";
       term.pop_front();
    }
    //cout << endl << endl;
}

void grammaire::majAlphabet() {
    alphabet.clear();

    majNonTerminaux();
    majTerminaux();
    alphabet = terminaux;
    alphabet.insert(alphabet.end(), nonTerminaux.begin(), nonTerminaux.end());

    /*cout << "Alphabet : ";
    for (int cpt = 0; cpt < alphabet.size(); cpt++) {
        cout << alphabet[cpt] << " ";
    }
    cout << endl << endl;*/
}


bool grammaire::estNonTerminal(string symbole) {
    for(int cpt =0; cpt < nonTerminaux.size(); cpt++) {
        if(nonTerminaux[cpt] == symbole) return true;
    }
    return false;
}

vector<string> grammaire::CalculFirstFollow(string nonTerminal) {
    vector<string> VectorFF;
    VectorFF = suivant(&VectorFF, nonTerminal);

    return VectorFF;
}

bool grammaire::DoublonVector(vector<string> Vector, string Terminal) {
    for (unsigned int cpt = 0 ; cpt < Vector.size() ; cpt++) {
        if (Vector[cpt] == Terminal) return true; //SI VRAI, ALORS DOUBLON
    }

    return false;
}

vector<string> grammaire::premier(vector<string> *VecPremier, string nonTerminal) {

    string tmp;

    for (unsigned int cpt = 0 ; cpt < regles.size() ; cpt++) {
        if ((nonTerminal == regles[cpt].nonTerminal) && (nonTerminal != regles[cpt].derivation[0])) {
            if (!regles[cpt].derivation[0].empty()) { //SI C'EST PAS LE MOT VIDE
                if ((!estNonTerminal(regles[cpt].derivation[0])) && (!DoublonVector(*VecPremier, regles[cpt].derivation[0]))) {
                    VecPremier->push_back(regles[cpt].derivation[0]);
                }
                else {
                    premier(VecPremier,regles[cpt].derivation[0]); //ON RECHERCHE LES PREMIERS DU NON TERMINAL
                }
            }
            else {
                VecPremier->push_back("e");
            }
        }
    }

    return *VecPremier;
}

bool grammaire::contientMotVide(vector<string> VecPremier) {
    for (unsigned int cpt = 0 ; cpt < VecPremier.size() ; cpt++) {
        if (VecPremier[cpt] == "e") return true; //SI VRAI, ALORS CONTIENT LE MOT VIDE
    }
}

void grammaire::popEpsilon(vector<string> *VecTor) {
    vector<string>::iterator it;
    for(it = VecTor->begin() ; it != VecTor->end(); it++) {
        if (*it == "e")
            VecTor->erase(it);
    }

    if (*it == "e")
        VecTor->erase(it); //S'IL RESTE UN DERNIER EPSILON

}

vector<string> grammaire::suivant(vector<string> *VecSuivant, string nonTerminal) {

    vector<string> tmpVector;

    if (nonTerminal == regles[0].nonTerminal) //ON PUSH LE DOLLAR CAR C'EST LE START SYMBOL
        VecSuivant->push_back("$");

    for (unsigned int cpt = 0 ; cpt < regles.size() ; cpt++) {
        for (unsigned int cpt2 = 0 ; cpt2 < (regles[cpt].derivation.size() - 1) ; cpt2++) {
            if (nonTerminal == regles[cpt].derivation[cpt2]) {
                if (!estNonTerminal(regles[cpt].derivation[cpt2 + 1]) && (!DoublonVector(*VecSuivant, regles[cpt].derivation[cpt2 + 1]))) { //SI LE FOLLOW EST TERMINAL
                    VecSuivant->push_back(regles[cpt].derivation[cpt2 + 1]);
                }
                else if (estNonTerminal(regles[cpt].derivation[cpt2 + 1])) { //SI IL EST NON TERMINAL
                    if (!contientMotVide(premier(&tmpVector, regles[cpt].derivation[cpt2 + 1]))) { //SI LES PREMIERS DU SUIVANT NE CONTIENT PAS LE MOT VIDE
                        premier(VecSuivant, regles[cpt].derivation[cpt2 + 1]); //ON INSERE LES PREMIERS DU SUIVANTS
                    }
                    else {
                        premier(VecSuivant, regles[cpt].derivation[cpt2 + 1]); //ON INSERE LES PREMIERS DU SUIVANTS
                        if ((regles[cpt].derivation[cpt2+1] != regles[cpt].nonTerminal) && (cpt2 + 1 > regles[cpt].derivation.size())) {
                            suivant(VecSuivant, regles[cpt].nonTerminal); //ON INSERE AUSSI LES SUIVANTS DU SUIVANTS
                        }
                    }
                }
                else {
                    VecSuivant->push_back("$");
                }
            }
        }
    }

    popEpsilon(VecSuivant);
    return *VecSuivant;
}
