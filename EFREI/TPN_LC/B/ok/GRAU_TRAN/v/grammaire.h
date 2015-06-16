#ifndef _GRAMMAIRE_H_
#define _GRAMMAIRE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
struct grammaire
{
    string** production; //contient toutes les r�gles de la grammaire, [0][*] correspond au mot qui produit la r�gle, deuxi�me dimension ne contiendra que deux cases
    int nombre_ligne; //nombre de ligne dans le fichier grammaire.txt
    vector<string> elt_grammaire ;
};

string supprimerespace(string a);
void lecturefichier(grammaire* g);
void lecturegrammaire(grammaire g);
void creationvariable_first_follow(grammaire g,vector <string*>* first_follow);
void calculfirst(grammaire g,string ** first_follow);


#endif // _GRAMMAIRE_H
