#include "etat.h"
#include <string>
#include<vector>
#include "regle.h"

using namespace std;

etat::etat()
{

}


etat etat::goTo(string trans, grammaire maGrammaire) {

        etat etatSuivant;
        int positionPoint;
        bool etatComplet = false;

        // Un vector qui nous dit si un non terminal a déjà été redétaillé
        vector<bool> nonTerminauxComplet;
        for (unsigned int cpt=0; cpt < maGrammaire.nonTerminaux.size(); cpt++) {
            nonTerminauxComplet.push_back(false);
        }

        //Ajout des règles où le point avance
        for(unsigned int cpt = 0; cpt < regles.size(); cpt++) {
            if (!regles[cpt].pointFinal()) {
                if(regles[cpt].apresLePoint() == trans) {
                    positionPoint = regles[cpt].positionPoint();
                    vector<string> nouvelleDeriv = regles[cpt].derivation;
                    //cout << nouvelleDeriv[0] << nouvelleDeriv[1] << nouvelleDeriv[2] << endl;
                    nouvelleDeriv[positionPoint] = nouvelleDeriv[positionPoint+1];
                    nouvelleDeriv[positionPoint+1] = ".";
                    regle nouvelleRegle(regles[cpt].nonTerminal, nouvelleDeriv);
                    //nouvelleRegle.affichage();
                    etatSuivant.regles.push_back(nouvelleRegle);
                }
            }
        }
        while(!etatComplet) {
            etatComplet = true;
            for (unsigned int cpt1 = 0; cpt1 < etatSuivant.regles.size(); cpt1++) {
                for(unsigned int cpt2 = 0; cpt2 < maGrammaire.nonTerminaux.size(); cpt2++) {
                    if (!etatSuivant.regles[cpt1].pointFinal()) {
                        if(etatSuivant.regles[cpt1].apresLePoint() == maGrammaire.nonTerminaux[cpt2]) {
                            if (!nonTerminauxComplet[cpt2]) { // On teste si ce non terminal a déjà été redétaillé
                                nonTerminauxComplet[cpt2] = true;
                                for (unsigned int cpt3 = 0; cpt3 < maGrammaire.regles.size(); cpt3++) {
                                    if (maGrammaire.regles[cpt3].nonTerminal == maGrammaire.nonTerminaux[cpt2]) { // Si la règle de la matière va devoir être recopié
                                        vector<string> nouvelleDeriv;
                                        nouvelleDeriv.push_back(".");
                                        nouvelleDeriv.insert(nouvelleDeriv.end(), maGrammaire.regles[cpt3].derivation.begin(), maGrammaire.regles[cpt3].derivation.end());

                                        regle nouvelleRegle(maGrammaire.nonTerminaux[cpt2], nouvelleDeriv);
                                        etatSuivant.regles.push_back(nouvelleRegle);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return etatSuivant;
}

void etat::affichage() {
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Etat " << indice << " :" << endl << endl;
    for (unsigned int cpt = 0; cpt < regles.size(); cpt++) {
        regles[cpt].affichage();
    }
    cout << endl;
}

void etat::creationEtat0(grammaire maGrammaire) {
    vector<string> derivationAxiome; // On rajoute le nouvel axiome
    derivationAxiome.push_back(".");
    derivationAxiome.push_back(maGrammaire.regles[0].nonTerminal);
    regle regleAxiome(maGrammaire.regles[0].nonTerminal+"'", derivationAxiome);
    regles.push_back(regleAxiome);

    for(unsigned int cpt = 0; cpt < maGrammaire.regles.size(); cpt++) { // On copie les règles de la grammaire en rajoutant la tête de lecture
        vector<string> nouvelleDerivation;
        nouvelleDerivation.push_back(".");
        nouvelleDerivation.insert(nouvelleDerivation.end(), maGrammaire.regles[cpt].derivation.begin(), maGrammaire.regles[cpt].derivation.end());
        regle nouvelleRegle(maGrammaire.regles[cpt].nonTerminal, nouvelleDerivation);
        regles.push_back(nouvelleRegle);
    }
    indice = 0;
}

bool etat::operator==(etat a) { // Ne compare pas l'indice volontairement
    if (a.regles.size() != regles.size()) return false;
    for (unsigned int cpt = 0; cpt < a.regles.size(); cpt++) {
        if (a.regles[cpt] != regles[cpt]) return false;
    }
    return true;
}

bool etat::aUneTransition(string trans) { // Indique si il existe on peut avancer la tête de lecture avec un caractère spécifique
    string comparateur;
    for(unsigned int cpt = 0; cpt < regles.size(); cpt++) {
        if (!regles[cpt].pointFinal()) { // On vérifie si le point n'est pas à la fin
            comparateur = regles[cpt].apresLePoint();
            if (comparateur == trans) return true;
        }
    }
    return false;
}

bool etat::etatTerminal() { // Un etat terminal est un etat qui n'a plus de transitions possibles
    for (unsigned int cpt = 0; cpt < regles.size(); cpt++) {
        if (!regles[cpt].pointFinal()) return false; // Toutes les règles qui le compose se finissent par un point
    }
    return true;
}
