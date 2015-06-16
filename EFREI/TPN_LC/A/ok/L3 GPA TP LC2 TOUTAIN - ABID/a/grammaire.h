#ifndef GRAMMAIRE_H
#define GRAMMAIRE_H
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Regle
{
    string gauche;
    string droite;
    public:
    Regle(string,string);
    Regle();
    string getGauche();
    string getDroite();
};

class Grammaire
{
    vector<Regle> regles;
    public:
    Grammaire();
    Grammaire(vector<Regle> r);
    Regle getRegle(int);
    int getnbregle();
    vector<Regle> getRegle();
};
class Automate
{
    Grammaire regles;
    vector<int>curseur;
    vector<int> suivant;
    vector<string> strsuivant;
    string fin;
public:
    Automate();
    Automate(Grammaire);
    Automate(Grammaire G,vector<int> c);
    void Addnext(int,string);
    string Getnext(int);
    int Getnext(string);
    vector<string> Getnext();
    Grammaire getGrammaire();
    int getCursor(int);
    void setfin(string);
    string getfin();
};
class PremSuiv
{
    vector<char>Premier;
    vector<char>Suivant;
public:
    PremSuiv();
    void addPremier(char);
    void addSuivant(char);
    vector<char> getPremier();
    vector<char> getSuivant();
    char getPremier(int);
    char getSuivant(int);
};
vector<Regle> nonterm(Grammaire grammaire,string gauche);
vector<Automate> creationautomate(vector<Automate>automate,Grammaire grammaire,string axiome,Automate automateprec,int nbfind);
#endif

