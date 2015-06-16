//
//  main.cpp
//  L3 GP TP LC 2 AUBARD - MAUREL
//
//  Created by Valentin on 14/01/2015.
//  Copyright (c) 2015 Valentin. All rights reserved.
//


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

///////////////////////////////////////////////////////// declaration des fonctions:



bool lectureGrammaire(map<string, vector< vector<string> > > &, vector<string> &, vector<string> &,string &);
void afficheGrammaire(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux);
void constructionGraphe(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux);
void first (map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, vector<string> &first);
void follow (map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, vector<string> &first, vector<string> &follow);


bool appAb(string &a, vector<string> &b);
bool appAb(vector<string> &a, vector <vector<string> > &b);
bool appAb(vector<string> &a, vector<string> &b);

void analyseurSLR(string name);

//void guillotineDeGrammaire(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux);



//////////////////////////////////////////////////////// main


int main()
{

    string grammaireFichier;

    grammaireFichier = "grammaire.txt";

    analyseurSLR(grammaireFichier);



    return 0;
}


//////////////////////////////////////////////////////////   Fonctions



bool lectureGrammaire(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, string &name)
{
    map<string, bool> existanceNonTerminal;
    map<string, bool> existanceTerminal;

    vector<string> vide;

    ifstream fichier(name.c_str(), ios::in);
    //ifstream fichier2(name.c_str(), ios::in);
    if(!fichier) return false;

    string contenu;
    string a, b;
    vector <string> tmp;
    unsigned i;

    while(getline(fichier,contenu) && contenu.size()>0)
    {
        a.erase();
        b.erase();
        for(i=0 ; contenu[i]!= ' ' && i<contenu.size() ; i++)
        {
            a = a + contenu[i];
        }
        //cout << a << " : " ;
        for(i=i+1 ; i<contenu.size() ; i++)
        {
            if(contenu[i] == ' ')
            {
                //cout << b << " " ;
                if(b.size() > 0)
                {
                    if (existanceTerminal[b]){}
                    else
                    {
                        existanceNonTerminal[b] = true;
                        terminaux.push_back(b);
                    }
                }
                tmp.push_back(b);
                b.clear();
            }
            else
            {
                b = b + contenu[i];
            }
        }
        if(a.size()>0)
        {
            if(b.size() > 0)
            {
                if (existanceTerminal[b]){}
                else
                {
                    existanceNonTerminal[b] = true;
                    terminaux.push_back(b);
                }
            }

            if (existanceTerminal[a]){}
            else
            {
                existanceTerminal[a] = true;
                non_terminaux.push_back(a);
            }
            //cout << b << endl;
            if(b.size() == 0) b = " ";
            tmp.push_back(b);
            if( !appAb(tmp, grammaire[a]))
            {
                grammaire[a].push_back(tmp);
            }
        }
        a.erase();
        b.erase();
        tmp.clear();
        //cout << endl;
    }
    for(int i=terminaux.size()-1 ; i>=0 ; i--)
    {
        if(appAb(terminaux[i], non_terminaux)) terminaux.erase(terminaux.begin()+i);
    }
    return true;

}

void afficheGrammaire(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux)
{
    unsigned i,j,k;
    cout << "Les etats terminaux sont :" << endl << "{";
    for( i=0 ; i<terminaux.size() ; i++)
    {
        if (i != terminaux.size()-1) cout << terminaux[i] << ", ";
        else cout << terminaux[i];
    }
    cout << "}" << endl;
    cout << endl << "Les etats non-terminaux sont :" << endl << "{";
    for( i=0 ; i<non_terminaux.size() ; i++)
    {
        if (i != non_terminaux.size()-1) cout << non_terminaux[i] << ", ";
        else cout << non_terminaux[i];
    }
    cout  << "}" << endl;
    cout << endl << "La grammaire est : " << endl;
    for( i=0 ; i<non_terminaux.size() ; i++)
    {
        cout << non_terminaux[i] << " : ";
        for( j=0 ; j<grammaire[non_terminaux[i]].size() ; j++)
        {

            for ( k=0 ; k<grammaire[non_terminaux[i]][j].size() && grammaire[non_terminaux[i]][j].size() != 0; k++)
            {
                if(grammaire[non_terminaux[i]][j][k]!= " ") cout << grammaire[non_terminaux[i]][j][k] << " " ;
                else cout << "!" << " ";
            }
            if(j != grammaire[non_terminaux[i]].size()-1) cout << " | ";
        }
        cout << endl;
    }
    cout << endl;

    system("pause");
}

void constructionGraphe(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux)
{
        unsigned l,m,n;
        // rajouter l'état S' => .S

        // calcul du graphe :

        /*
        Construire C = {I0 , I1 , ... ,In } ensembles pour G’.

    Si[A=>α·aβ](avec a terminal)est dans Ii et Transition(Ii,A)=Ij, remplir Action[i,a] avec « d ́ecaler j ».
    Si [A => α·] (A ̸= S ) est dans Ii , remplir Action[i , a] avec « reduire » par A → α pour tous les a de Suivant(A).
    Si [S => S ·] est dans Ii , remplir Action[i , $] avec « accepter ».

    siTransition(Ii,a)=Ij alors Successeur[i,A] = j.
    Toutes les entrees non definies par les regles 2 et 3 sont positionnees à « erreur ».
    L’etat initial de l’analyseur est celui qui est construit à partir de [S′ => ·S].

        */
}

void first (map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, vector<string> &first)
{
    /*
    Si X est un terminal alors First(X) = X!
    Si il y a une Production X => (espilon) alors ajouter (epsilon) à first(X)
    Si il y a une Production X → Y1Y2..Yk alors ajouter first(Y1Y2..Yk) aux first(X)
    First(Y1Y2..Yk) est aussi First(Y1) (si First(Y1) ne contiens pas epsilon)
    Ou (si First(Y1) contiens epsion) alors First (Y1Y2..Yk) prends toutes les valeurs de First(Y1) <sauf pour ε > de même que pour First(Y2..Yk)
    Si First(Y1) First(Y2)..First(Yk) contiennent tous epsilon lors l'ajouter à First(Y1Y2..Yk)


    */
}

void follow (map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, vector<string> &first, vector<string> &follow)
{
    /*
    Metter $ dans Follow(S) (avec S Start Symbol)
    Si il y a  A => aBb, alors tous les FIRST(b) sauf pour epsilon est placé dans FOLLOW(B).
    Si il y  A => aB, alors tous les FOLLOW(A) sont aussi mis dans les FOLLOW(B)
    Si il y a A => aBb, où FIRST(b) contiens epsilon, alors tous les FOLLOW(A) sont aussi mis dans les FOLLOW(B)
*/
}

bool appAb(string &a, vector<string> &b)
{
    for(unsigned i=0 ; i<b.size() ; i++)
    {
        if(a==b[i]) return true;
    }
    return false;
}
bool appAb(vector<string> &a, vector <vector<string> > &b)
{
    bool test=true;
    for(unsigned i=0 ; i<b.size() ; i++)
    {
        if(a.size() == b[i].size())
        {
            test = true;
            for(unsigned j=0 ; j< a.size() ; j++)
            {
                if(a[j] != b[i][j]) test = false;
            }
            if(test) return true;
        }
    }
    return false;
}
bool appAb(vector<string> &a, vector<string> &b)
{
    bool test=true;
    if(a.size() == b.size())
    {
        test = true;
        for(unsigned j=0 ; j< a.size() ; j++)
        {
            if(a[j] != b[j]) test = false;
        }
        if(test) return true;
    }
    return false;
}

void analyseurSLR(string name)
{
    vector<string> terminaux;
    vector<string> non_terminaux;
    map<string, vector< vector<string> > > grammaire;

    cout << "ouverture du fichier : " << name << endl << endl;
    if (!lectureGrammaire(grammaire, terminaux, non_terminaux, name))
    {
        cerr << "ERREUR LECTURE : ouverture fichier" << endl;
        return ;
    }


    afficheGrammaire(grammaire, terminaux, non_terminaux);
    constructionGraphe(grammaire, terminaux, non_terminaux);

   // first(grammaire, terminaux, non_terminaux, first);
   // follow(grammaire, terminaux, non_terminaux, first, follow);
}
