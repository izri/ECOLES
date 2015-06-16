#include "regle.h"
#include <iostream>

using namespace std;

regle::regle(string line)
{
    unsigned int cpt = 0;

    nonTerminal = "";
    while (( line[cpt] != 32 && line[cpt] !=  9 && line[cpt] && 13) && (cpt <= line.length())) {
        nonTerminal += line[cpt];
        cpt++;
    }
    cout << nonTerminal << " -> ";
    cpt++; // On "saute" l'espace
    while (cpt <= line.length()) {
        string sBuffer ="";
        while( line[cpt] != 32 && line[cpt] !=  9 && line[cpt] && 13) {
            sBuffer += line[cpt];
            cpt++;
        }
        derivation.push_back(sBuffer);
        cout << sBuffer << " ";
        cpt++; // On "saute" l'espace
    }
    cout << endl << endl;
}

void regle::affichage() {
    cout << nonTerminal << " -> ";
    for (unsigned int cpt = 0; cpt < derivation.size(); cpt++) {
        cout << derivation[cpt] << " ";
    }
    cout << endl;
}

string regle::apresLePoint(){
    for(unsigned int cpt = 0; cpt < derivation.size(); cpt++) {
        if (derivation[cpt] == ".") {
            return derivation[cpt+1];
        }
    }
    return "";
}

bool regle::pointFinal(){
    if (derivation[derivation.size() - 1] == ".") return true;
    else return false;
}

int regle::positionPoint() {
    for(unsigned int cpt = 0; cpt < derivation.size(); cpt++) {
        if (derivation[cpt] == ".") {
            return cpt;
        }
    }
}

bool regle::operator==(regle a) {
    if (a.derivation.size() != derivation.size()) return false;
    if (a.nonTerminal != nonTerminal) return false;
    for (unsigned int cpt = 0; cpt < a.derivation.size(); cpt++) {
        if (a.derivation[cpt] != derivation[cpt]) return false;
    }
    return true;
}

bool regle::operator!=(regle a) {
    if (a.derivation.size() != derivation.size()) return true;
    if (a.nonTerminal != nonTerminal) return true;
    for (unsigned int cpt = 0; cpt < a.derivation.size(); cpt++) {
        if (a.derivation[cpt] != derivation[cpt]) return true;
    }
    return false;
}
