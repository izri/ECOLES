#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void initA (arbre *liste)
{
    arbre tmp;
    tmp = *liste;
    tmp->droite = NULL;
    tmp->gauche = NULL;
    tmp->val = 0;
}

void constrA(arbre *liste)
{
    int i[15]= {25,21,18,16,15,13,11,9,8,7,6,5,4,3,1};
    int cpt;
    cpt = 0;
    arbre tmparbre;
    tmparbre = *liste;
    arbre tmpnoeud;


    while (tmparbre)
    {
        arbre element;
        element = (arbre)malloc(sizeof(elem));
        element->droite = NULL;
        element->gauche = NULL;
        element->val = i[cpt];


        tmpnoeud = tmparbre;

        if(i[cpt] > tmparbre->val)
        {
            tmparbre = tmparbre->droite;
            if (!tmparbre)
            {
                tmpnoeud->droite = element;
            }
        }

        else
        {
            tmparbre = tmparbre->gauche;
            if (!tmparbre)
            {
                tmpnoeud->gauche = element;
            }

        }
        cpt++;
    }
}

void affichageA(arbre *liste)
{
    arbre tmp;
    tmp = *liste;

    if (tmp->gauche)
    {
        affichageA(&tmp->gauche);
    }
    printf("\n%d",tmp->val);
    if (tmp->droite)
    {
        affichageA(&tmp->droite);
    }

}
