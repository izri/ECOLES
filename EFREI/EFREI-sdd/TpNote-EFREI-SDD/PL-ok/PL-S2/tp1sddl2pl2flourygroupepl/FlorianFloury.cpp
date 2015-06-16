#include <iostream>
#include "FlorianFloury.h"


using namespace std;

element creaCellule(int cpt)
{
    element boite = NULL;
    boite = (element)malloc(sizeof(Elem));
    boite -> numero = cpt;
    boite -> suivant = NULL;
    return boite;
}

element premierElt(element *lst, int cpt)
{
    element p;
    p = creaCellule(cpt);
    *lst = p;
    //p=*lst;
    return p;
}

void construireListe (element *lst ,int nb)
{
        int cpt=1;
        element p, t;
        t = premierElt(lst, cpt);

        while(cpt < nb)
        {
            cpt++;
            p = creaCellule (cpt);
            p -> suivant = t -> suivant;  // permet de mettre tout les suivnat a NULL
            t -> suivant = p;
            t = p;
        }

}

void Afficher(element lst)
{
    element boite = lst;

    int compt;
    int i;

    if (boite == NULL) printf("Liste Vide \n");
    else
    while(boite != NULL)
    {

    compt=0;/////////N'affiche que les nombre premier

        for (i=1; i<=boite->numero; i++)
        {
            if(boite->numero%i==0)
            {
                compt++;
            }
        }
        if(compt==2)
        {
            printf("Le numero est : %d \n", boite->numero);
        }
            /////////Fin test premier

    boite = boite->suivant;
    }

}


////Supprime les elements non premier
/*

void suppasprem(element boite)
{
    element cell = boite;
    cell->suivant = cell;
    boite->suivant = cell->suivant
    cell = free
}

*/


