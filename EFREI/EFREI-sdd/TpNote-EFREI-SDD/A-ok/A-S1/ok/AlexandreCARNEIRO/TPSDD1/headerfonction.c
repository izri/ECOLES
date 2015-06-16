#include "header.h"

LSCc premierElt(LSCc *lst)
{
    LSCc l;
    l = creationCellule(2);
    *lst = l;
    return l;
}

void construireliste(LSCc *lst,int n)
{
    LSCc p,l;
    int i,j = 2;
    p = premierElt(lst);
    for(i = 0; i<n-1; i++)
    {
        j++;
        l = creationCellule(j);
        p->suivant = l;
        p=l;
    }
}

LSCc creationCellule(int n)
{
    LSCc p;
    p = (LSCc) malloc(sizeof(maillon));
    p->data = n;
    p->suivant = NULL;
    return p;
}

void afficher(LSCc lst)
{
    LSCc element = lst;
    if(element == NULL)
    {
        printf("Liste Vide \n");
    }
    else
    {
        estpremier(element);
    }
}

void estpremier(LSCc lst) //test pour savoir si il est premier, s'il l'est on affiche sinon on passe au maillon suivant
{
    LSCc test = lst;
    int boolean = 0,i = 2;
    do
    {
        boolean = 0;
        for(i = 2; i < test->data; i++)
        {
            if(test->data % i == 0)
            {
                boolean = 1;
            }
        }

        if (boolean == 0)
        {
            printf("%d",test->data);
            printf("\n");
        }
        test = test->suivant;
    }
    while(test != NULL);
}
