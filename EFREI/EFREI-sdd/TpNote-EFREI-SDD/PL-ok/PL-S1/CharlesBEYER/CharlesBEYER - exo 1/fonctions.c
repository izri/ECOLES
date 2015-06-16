#include <stdio.h>
#include <stdlib.h>
#include "header.h"

LSC nouvelE(int i)
{
    LSC nouveau;
    nouveau = (LSC)malloc(sizeof(elem));
    nouveau->suivant = NULL;

    nouveau->val = i;

    return nouveau;
}

void constrL1 (LSC *liste, int nb)
{
    int cpt;
    cpt = 0;
    int i;
    i = 2;
    *liste = nouvelE(i);
    i++;
    cpt++;
    LSC tmp;
    tmp = *liste;

    LSC nouveau;

    while (cpt < nb)
    {
        nouveau = nouvelE(i);
        tmp->suivant = nouveau;
        tmp = nouveau;
        cpt++;
        i++;
    }

}


void affichage1 (LSC *liste)
{
    LSC tmp;
    tmp = *liste;

    if (!tmp)
    {
        printf("\n   La liste est vide.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (tmp)
        {
            printf("%d\n",tmp->val);
            tmp = tmp->suivant;
        }
    }
}

// Modification de la liste ne stockant que le s nombres premiers.
void nbP(LSC *liste)
{
    LSC tmp;
    tmp = *liste;
    LSC tmp2;

    if (!tmp)
    {
        printf("\n   La liste est vide.\n");
        exit(EXIT_FAILURE);
    }

    while (tmp->suivant)
    {
        tmp2 = tmp;
        tmp = tmp->suivant;
        // if (((tmp->val%1)!=0)&&((tmp->val%tmp->val) == 0))
        if ((verifP(tmp->val) == 0))
        {
            tmp2->suivant = tmp->suivant;
            // free(tmp);
        }
    }
}


// Verification si la valeur envoyé est un nombre premier.
int verifP(int nb)
{
    int s;
    int num,i,count=0;
    num = nb;
    for(i=2; i<=num/2; i++)
    {
        if(num%i==0)
        {
            count++;
            // return;
            // break;
        }
    }
    if(count==0 && num!= 1)
    {
        s = 1;
    }
    else
    {
        s = 0;
    }
    return s;
}



/*
// Création d'une liste contenant l'ensemble des nombres premiers de la première liste.
LSC nbP2(LSC *liste)
{
    LSC nbp;
    // nbp = nouvelE(2);
    nbp = (LSC)malloc(sizeof(elem));
    nbp->suivant = NULL;
    LSC tmp;
    tmp = *liste;

    if (!tmp)
    {
        printf("\n   La liste est vide.\n");
        exit(EXIT_FAILURE);
    }

    while (tmp->suivant)
    {
        if ((verifP(tmp->val))==1)
        {
            LSC nouveau;
            nouveau = nouvelE(tmp->val);
            // nouveau->suivant = NULL;
            // nouveau->val = tmp->val;

            nbp->suivant = nouveau;
            // nbp = nouveau;
        }
        tmp = tmp->suivant;
    }
    return nbp;
}*/
