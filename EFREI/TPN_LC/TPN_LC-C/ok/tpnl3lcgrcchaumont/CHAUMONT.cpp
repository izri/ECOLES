#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>

/*
*   Guillaume CHAUMONT
*   Promo 2017
*   Groupe C
*/

using namespace std;

int main()
{
    // On charge la grammaire
    ifstream fichier("CHAUMONT.txt", ios::in);

    // On définit un vecteur de vecteur gram, qui contiendra la grammaire mise en forme
    int nbLignes = 0;
    vector< vector<string> > gram;

    if(fichier) {
        string ligne;
        string contenu = "";
        string charToString;

        // On parcourt chaque ligne du fichier
        while(!fichier.eof()) {
            getline(fichier, ligne);
            charToString = "";
            charToString += ligne[0]; // On convertit le premier caractère de la ligne en string, puis on l'ajoute à gramL
            vector<string> gramL; // Vecteur qui sera ajouté à
            gramL.push_back(charToString);

            contenu = "";

            string test; // Utilisé pour permettre des tests sur le caractère en cours d'étude

            for(int i = 1; i < ligne.length(); i++) { // On lit chaque caractère de la ligne
                //cout << ligne[i] << endl;
                test = ligne[i]; // On stocke le caractère en cours d'étude dans test

                if((test != " ") && (test != "-") && (test != ">")) { // Si le caractère n'est pas un espace ou un morceau de flèche
                    if(test == "|") { // Si le caractère est une barre verticale...
                        gramL.push_back(contenu);
                        gram.push_back(gramL); // On ajoute gramL à gram
                        nbLignes++;
                        gramL.clear(); // On réinitialise gramL
                        gramL.push_back(gram[nbLignes-1][0]); // On ajoute à nouveau à gramL le premier caractère de la ligne
                        contenu = ""; // On réinitialise contenu
                    } else {
                        contenu += ligne[i]; // On ajoute le caractère en cours d'étude à contenu
                    }
                }
            }
            //cout << "Fin de ligne";
            //cout << "Contenu : " << contenu << endl;

            // Arrivé à la fin de la ligne, on ajoute gramL à gram
            gramL.push_back(contenu);
            gram.push_back(gramL);
            nbLignes++;
        }

    } else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }

    // On affiche la grammaire en parcourant le tableau
    cout << "Grammaire" << endl;
    for(int i =0; i<nbLignes; i++) {
        cout << gram[i][0] << "   " << gram[i][1] << endl;
    }

    // On fait une copie de la grammaire à laquelle on ajoute les points
    vector< vector<string> > copie;
    int nbLignesCopie = nbLignes;
    vector<string> ligne;
    string car = gram[0][0];
    car += "'";
    ligne.push_back(car);
    car = ".";
    car += gram[0][0];
    ligne.push_back(car);
    copie.push_back(ligne);
    nbLignesCopie++;

    string test;

    for(int i = 0; i < nbLignes; i++) {
            car = ".";
            test = gram[i][1];
            if(test != "e") {
                car += gram[i][1];
            }
            ligne.clear();
            ligne.push_back(gram[i][0]);
            ligne.push_back(car);
            copie.push_back(ligne);
    }

    cout << endl << endl;
    for(int i =0; i<nbLignesCopie; i++) {
        cout << copie[i][0] << "   " << copie[i][1] << endl;
    }
    cout << endl << endl;



    // On calcule les premiers
    int nbLignesP = 0;
    vector< vector<string> > premiers;
    ligne.clear();
    car = gram[0][0];
    car += "'";
    ligne.push_back(car);
    car = gram[0][0];
    ligne.push_back(car);
    premiers.push_back(ligne);
    nbLignesP++;

    // On parcourt le tableau, à chaque fois on ajoute le premier caractère à la liste des premiers. On ne crée de nouvelle entrée que si elle n'existe pas déjà
    bool ajoute = false;
    bool dejaPresent = false;
    string car2;
    string car3;
    for (int i=0; i < nbLignes; i++) {
        ajoute = false;
        for(int j = 0; j < nbLignesP; j++) {
            if(premiers[j][0] == gram[i][0]) {
                ajoute = true;
                car = gram[i][1][0];
                car2 = premiers[j][1];
                dejaPresent = false;
                for(int k = 0; k < car2.length(); k++)   {
                    car3 = car2[k];
                    if(car3 == car) {
                        dejaPresent = true;
                    }
                }
                if(!dejaPresent) {
                    premiers[j][1] += car;
                }
            }
        }

        if(!ajoute) {
            ligne.clear();
            car = gram[i][0];
            ligne.push_back(car);
            car = gram[i][1][0];
            ligne.push_back(car);
            premiers.push_back(ligne);
            nbLignesP++;
        }
    }

    /*cout << "Premiers" << endl;
    for(int i =0; i<nbLignesP; i++) {
        cout << premiers[i][0] << "   " << premiers[i][1] << endl;
    }*/

    // On reparcourt tous les premiers en remplacant les majuscules par leurs premiers
    char cara;
    char cara2;
    bool maj = false;
    do {
        maj = false;
        for(int i =0; i<nbLignesP; i++) {
            car = premiers[i][1];
            for(int j = 0; j < car.length(); j++)   {
                cara = car[j];
                if(isupper(cara)) {
                    maj = true;
                    if((premiers[i][0][0] == premiers [i][1][j]) && (premiers[i][0][1] != '\'')) {
                       premiers[i][1][j] = ' ';
                    } else {
                        premiers[i][1][j] = ' ';
                        for(int k =0; k<nbLignesP; k++) {
                            cara2 = premiers[k][0][0];
                            if(cara2 == cara) {
                                premiers[i][1] += premiers[k][1];
                            }
                        }
                    }
                }
            }
        }
    } while(maj);

    /*cout << "Premiers" << endl;
    for(int i =0; i<nbLignesP; i++) {
        cout << premiers[i][0] << "   " << premiers[i][1] << endl;
    }*/

    // On affiche en supprimant espaces et doublons
    cout << "Premiers" << endl;
    vector< char > dejaAffiche;
    int nbDejaAffiche = 0;
    bool dejaAff = false;
    for(int i =0; i<nbLignesP; i++) {
        dejaAffiche.clear();
        nbDejaAffiche = 0;
        cout << premiers[i][0] << "   ";
        for(int j = 0; j < premiers[i][1].length(); j++)   {
            dejaAff = false;
            cara = premiers[i][1][j];
            for(int k = 0; k < nbDejaAffiche; k++) {
                if(dejaAffiche[k] == cara) {
                    dejaAff = true;
                }
            }

            if(!dejaAff) {
                dejaAffiche.push_back(cara);
                nbDejaAffiche++;
                cout << cara;
            }
        }
        cout << endl;
    }

    return 0;
}
