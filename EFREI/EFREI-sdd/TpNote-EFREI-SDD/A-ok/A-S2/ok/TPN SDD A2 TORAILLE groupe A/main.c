#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    struct maillon *next;
    int data;
}Maillon;

void creer_liste_entiers(Maillon **liste, int n);

int main()
{
    Maillon *liste=NULL, *m;

    creer_liste_entiers(&liste, 500);
    m=liste;
    printf("Liste des nombres parfaits jusqu'a 500:\n");


    return 0;
}



void creer_liste_entiers(Maillon **liste, int n)
{
    int cpt;
    Maillon *m=NULL;

    *liste = (Maillon*)malloc(sizeof(Maillon));
    m = *liste;
    m->data = 2;
    for(cpt=3; cpt<=n; cpt++)
    {
        m->next = (Maillon*)malloc(sizeof(Maillon));
        m = m->next;
        m->data = cpt;
    }
    m->next = NULL;
}
