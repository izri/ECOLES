#include <stdio.h>
#include <stdlib.h>
#include "exercice1.h"

void creer_liste(maillon **liste, int n)
{
    int cpt;
    maillon *l=NULL;

    *liste = (maillon*)malloc(sizeof(maillon));
    l = *liste;
    l->data = 1;
    for(cpt=2; cpt<=n; cpt++)
    {
        l->next = (maillon*)malloc(sizeof(maillon));
        l = l->next;
        l->data = cpt;
    }
    l->next = NULL;
}
