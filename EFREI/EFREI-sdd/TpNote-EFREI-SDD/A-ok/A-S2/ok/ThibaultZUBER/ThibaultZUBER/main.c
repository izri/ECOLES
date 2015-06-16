#include <stdio.h>
#include <stdlib.h>
#include "exercice1.h"

void creer_liste(maillon **liste, int n);

int main()
{
    maillon *liste=NULL, *l;

    creer_liste(&liste, 50);
    l=liste;
    printf("Liste des datas premiers jusqu'a 500:\n");
    while(l!=NULL)
    {
        printf("%d\n", l->data);
        l = l->next;
    }

    return 0;
}

