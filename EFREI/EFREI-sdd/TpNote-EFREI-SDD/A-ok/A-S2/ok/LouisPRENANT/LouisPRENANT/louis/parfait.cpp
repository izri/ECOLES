#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "parfait.h"

using namespace std;



LSCMonome Nouvel_element(LSCMonome lst, int valeur)
{
    lst=(LSCMonome)malloc(sizeof(LSCMonome));
    lst->valeur=valeur;
    lst->suivant=NULL;

    return lst;
}

void Remplissage_LSC(LSCMonome lst)
{
    int n=0;

    lst=Nouvel_element(lst,n);
    LSCMonome l=lst;    //Variable de parcourt de la liste


    cout<<"Combien voulez vous d'elements?";
    cin>>n;


    for(int i=2; i<=n; i++)
    {
        l=Nouvel_element(l,i);
        cout<< " \t" <<l->valeur;
        l=l->suivant;
    }




}

