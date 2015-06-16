//
//  Index.cpp
//  LangageEtCompil
//
//  Created by DESVAUX Lou-Evans on 18/01/2015.
//  Copyright (c) 2015 DESVAUX Lou-Evans. All rights reserved.
//

#include "Index.h"

using namespace std;

    
Index::Index(){
    previousletter = "Inconnu";
    previousindex = "Inconnu";
    nom = "Inconnu";
    }

string& Index::getPreviousletter(){
    return this->previousletter;
}

string& Index::getPreviousindex(){
    return this->previousindex;
}

string& Index::getNom(){
    return this->nom;
}

string& Index::getI(int cpt)
{
    return I[cpt];
}

int Index::getTaille(){
    return (int)I.size();
}

void Index::setNom(string pNom)
{
    this->nom = pNom;
}

void Index::setI(string p)
{
    I.push_back(p);
}

void Index::setPreviousindex(string p)
{
    this->previousindex = p;
}

void Index::setPreviousletter(string p)
{
    this->previousletter = p;
}

void Index::clear()
{
    previousletter = "Inconnu";
    previousindex = "Inconnu";
    nom = "Inconnu";
    I.clear();
}

void Index::clear2(int cpt)
{
    I[cpt].erase();
}