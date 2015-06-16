#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int profondeur;
    struct node *sag;
    struct node *sad;
}node;

typedef node *arbre;

void creationArbre(arbre abr, int n, int profActuelle)
{
    abr->profondeur = profActuelle;
    if (n == 0)
    {
        abr->sag = NULL;
        abr->sad = NULL;
        return;
    }
    abr->sag = malloc(sizeof(abr->sag));
    abr->sad = malloc(sizeof(abr->sad));
    return creationArbre(abr->sag, n-1, profActuelle+1);
    return creationArbre(abr->sad, n-1, profActuelle+1);
}

int main()
{
    int n = 0;
    int profActuelle = 0;
    arbre arbreParfait = malloc(sizeof(arbreParfait));
    printf("Valeur de la profondeur n?\n");
    scanf("%d", &n);
    creationArbre(arbreParfait, n, profActuelle);
    return 0;
}
