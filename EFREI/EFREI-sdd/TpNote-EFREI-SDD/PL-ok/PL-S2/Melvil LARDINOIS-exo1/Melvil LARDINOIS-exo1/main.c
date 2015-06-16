#include <stdio.h>
#include <stdlib.h>
#include "nbr.h"

int main()
{
    int n;
    lsc liste;
    printf ("Saisir votre nombre \n");
    scanf("%d",&n);
    while (n<2)
    {
        printf ("Saisir votre nombre \n");
        scanf("%d",&n);
    }
    create(&liste, n);
    afficher(&liste);
    return 0;
}

lsc creationcellule()
{
    int init=2;
    lsc maillon = NULL;
    maillon=(lsc)malloc(sizeof(nombre));
    maillon -> nbr = init;
    maillon -> next = NULL;
    return maillon;
}

lsc premierelt(lsc *liste)
{
    lsc e;
    e=creationcellule();
    *liste=e;
    return e;
}

void create(lsc *liste,int n)
{
    int cpt = 2;
    int cpt1 = 1;
    lsc p,t;
    t = premierelt(liste);
    while(cpt<n)
    {
        p = creationcellule();
        t -> next = p;
        p->nbr = p->nbr+cpt1;
        t = p;
        cpt++;
        cpt1++;
    }
}

void afficher(lsc *liste)
{
    int temp;
    lsc tmp;
    tmp = *liste;
    while(tmp != NULL)
    {
        printf ("\n%d", tmp->nbr);
        tmp =tmp->next;
    }
}
