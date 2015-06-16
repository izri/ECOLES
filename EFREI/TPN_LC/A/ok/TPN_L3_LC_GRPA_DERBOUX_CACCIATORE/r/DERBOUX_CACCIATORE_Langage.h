#ifndef LANGAGE_H_INCLUDED
#define LANGAGE_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Langage{
private :
         char axiome;
     vector<vector<char> >tab ; //tab des relation
     vector<vector<char> >first;
     int nbrelation;

    public :
         char getAxiome();
       vector<char> getRelation(int indice); // INDICE EST la ligne
         int getNbRelation();
     Langage(string nom);
    void afficher();
    void firstf();




};

#endif // LANGAGE_H_INCLUDED
