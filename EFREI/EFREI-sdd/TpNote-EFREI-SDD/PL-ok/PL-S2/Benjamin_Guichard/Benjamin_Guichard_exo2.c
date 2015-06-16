/*
**  GUICHARD Benjamin
**  TP noté SDD
**  Exercice n°2
**  18/11/2014
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int nombre;
    struct node * gauche;
    struct node * droite;
} node;
typedef node * Arbre;

void parcourir(Arbre noeud);

int main()
{
    return 0;
}

void parcourir(Arbre noeud)
{
    if(noeud != NULL)
    {
        printf("%d", noeud->nombre);
        parcourir(noeud->gauche);
        parcourir(noeud->droite);
    }
}
