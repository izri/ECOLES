#include "Index.h"
#include <iostream>

using namespace std;

Index::Index()
{

}

Index::~Index()
{

}

int Index::getNom()
{
    return nom;
}

void Index::setNom(int n)
{
    nom = n;
}

void Index::addRegles(string r)
{
    regles.push_back(r);
}

string Index::getRegles(int i)
{
    return regles[i];
}

int Index::tailleRegles()
{
    return regles.size();
}

Arc Index::getArc(int i)
{
    return arc[i];
}

int Index::tailleArcs()
{
    return arc.size();
}

void Index::addArc(Arc a)
{
    arc.push_back(a);
}
