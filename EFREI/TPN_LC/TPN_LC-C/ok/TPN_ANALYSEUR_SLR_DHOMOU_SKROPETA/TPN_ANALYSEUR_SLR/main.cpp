#include <iostream>
#include <string>

#include "scanner.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    char* fileToRead = argv[1];

    cout << "== PROJET LANGAGE ET COMPILATION ==" << endl;
    cout << "== Donald DHOMOU ET Axel SKROPETA ==" << endl << endl;

    // Lecture du fichier
    readFile(fileToRead);

    // Creation de la table
    // d'analyse
    createAnalyseTable();

    // Creation de la table des
    // terminaux et non terminaux
    checkTerminaux();

    // Creation des first
    // et des follows
    createFirstAndFollow();


    display();


    return 0;
}
