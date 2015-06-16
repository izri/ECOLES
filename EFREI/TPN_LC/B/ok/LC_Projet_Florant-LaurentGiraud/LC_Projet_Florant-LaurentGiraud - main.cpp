#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct gram{
    int num;
    int taille;
    int gch;
    int drt[20];
};



int main(){

    ifstream fichier( "LC_Projet_Florant-LaurentGiraud - test.txt" );
    string ligne;
    vector<string> grammaire;
    vector<string> symboles;
    vector<string> symboles_diff;
    vector<string> non_terminaux;
    vector<string> non_terminaux_diff;
    vector<string> terminaux;

    /*
    ***
    LECTURE DU GRAPHE
    ***
    */
    if (fichier)
    {
        cout << "> Voici la grammaire Lg a tester : " << endl;
        cout << endl;

        while ( getline( fichier, ligne, '\n' ) )
        {
            cout << ligne << endl; // on affiche la ligne sur la console

            istringstream nt(ligne); // on recupere le premier symbole de chaque ligne
            string snt;
            nt >> snt;
            non_terminaux.push_back(snt);
            grammaire.push_back(ligne); // on remplit le tableau de grammaire pour chaque ligne
        }
    }

    // On recupere tous les symboles
    for(int i=0;i<grammaire.size();i++)
    {
        istringstream iss(grammaire[i]);
        while (iss)
        {
            string s;
            iss >> s;
            //cout << "* " << s << endl;
            symboles.push_back(s);
        }
    }
    cout << endl;
    cout << endl;

    // Remplissage de la liste des symboles non terminaux différents
    for(int i=0;i<non_terminaux.size();i++)
    {
        bool NT_existe_deja=0;
        for(int j=0;j<non_terminaux_diff.size();j++)
        {
            if (non_terminaux.at(i)== non_terminaux_diff.at(j))
            {
                NT_existe_deja=1;
            }
        }
        if (NT_existe_deja==0)
        {
            non_terminaux_diff.push_back(non_terminaux.at(i));
        }
    }

    // Remplissage de la liste des symboles différents
    for(int i=0;i<symboles.size();i++)
    {
        bool Symb_existe_deja=0;
        for(int j=0;j<symboles_diff.size();j++)
        {
            if (symboles.at(i)== symboles_diff.at(j))
            {
                Symb_existe_deja=1;
            }
        }
        if (Symb_existe_deja==0)
        {
            symboles_diff.push_back(symboles.at(i));
        }
    }

    // Remplissage de la liste des terminaux
    for(int i=0;i<symboles_diff.size();i++)
    {
        bool T_existe_deja=0;
        for(int j=0;j<non_terminaux_diff.size();j++)
        {
            if (symboles_diff.at(i)== non_terminaux_diff.at(j))
            {
                T_existe_deja=1;
            }
        }
        if (T_existe_deja==0)
        {
            terminaux.push_back(symboles_diff.at(i));
        }
    }

    // Affichage de la liste des symboles différents
    cout << ">> Liste des symboles differents:" << endl;
    for(int i=0;i<symboles_diff.size();i++)
    {
        cout<<symboles_diff.at(i)<<" ";
    }
    cout << endl;
    cout << endl;


    // Affichage de la liste des symboles non terminaux différents
    cout << ">> Liste des symboles non terminaux differents:" << endl;
    for(int i=0;i<non_terminaux_diff.size();i++)
    {
        cout<<non_terminaux_diff.at(i)<<" ";
    }
    cout << endl;
    cout << endl;

    // Affichage de la liste des terminaux
    cout << ">> Liste des symboles terminaux differents:" << endl;
    for(int i=0;i<terminaux.size();i++)
    {
        cout<<terminaux.at(i)<<" ";
    }
    cout << endl;
    cout << endl;



    /*
    ***
    CALCUL DES FIRSTS AND FOLLOWS
    ***
    */

    string epsilon;
    string dollar;
    vector<string> first;
    vector<string> follow;


    /*if ((grammaire.left[ligne]==non_terminaux) && grammaire.right[ligne])
    {
        for(unsigned int i=0;i<first.size();i++)
            for(unsigned int j=0;j<first.size();j++)
                if (first[j]!=epsilon)
                    first[i]=first[j];
        if(first[j]==epsilon)
            first[i]=first[j];
        if (first[j]!=epsilon)
                first[i]=epsilon;
    }

    if ((grammaire.left[ligne]==non_terminaux) && (grammaire.right[ligne]==epsilon)
        first[ligne]=epsilon;

    if(grammaire.left[ligne]==terminaux[ligne])
            first[i]=terminal[ligne]
    */


}

