#include "Grammaire.h"
#include <iostream>

using namespace std;

string Grammaire::getNom()
{
     return nom;
}

void Grammaire::setNom(string c)
{
    nom = c;
}

vector<string> Grammaire::getAllProduction()
{
    return production;
}

void Grammaire::setProduction(string a, int i)
{
    production[i] = a;
}

void Grammaire::addProduction(string a)
{
    production.push_back(a);
}

Grammaire::Grammaire()
{

}

Grammaire::~Grammaire()
{

}

int Grammaire::tailleProduction()
{
    return production.size();
}

string Grammaire::getProduction(int i)
{
    return production[i];
}

void Grammaire::SupprProduction()
{
    production.clear();
}

int Grammaire::tailleAlpha()
{
    return alpha.size();
}

void Grammaire::addAlpha(string a)
{
    alpha.push_back(a);
}

void Grammaire::addBeta(string a)
{
    beta.push_back(a);
}

string Grammaire::getAlpha(int a)
{
    return alpha[a];
}

string Grammaire::getBeta(int a)
{
    return beta[a];
}

int Grammaire::tailleBeta()
{
    return beta.size();
}
