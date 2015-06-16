#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "DERBOUX_CACCIATORE_Langage.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Interfa{

protected :
    //string nom;
     vector<vector<char> >relation ; //tab des relation
     vector<int> radius; //le num du radiu
     vector<vector<char> >intersuivante;
     int nbrelation;

     //Langage *l;

public :
    //Interfa(Langage *g);
    void afficher();
    void setrelation(char r, int indice);
    void setRelation (vector<char>colonne, int a);
    //void construireI0();
    int construireIn(char lecture);
    //void suivant();
    void setRelation(vector<char>colonne); // ATTENTION PERMUTE EGALEMENT . ET char SUIVANT
    void ajouterNonTerm();
    bool equal(Interfa inter);
    int getnbrelation();
    int getnbrelation(int indice); // de la dimmension 2
    char getrelation(int i1, int i2);
    vector <char> getrelation(int i1);
    void setintersuivante(char cara, int indice);
};

#endif // INTERFACE_H_INCLUDED
