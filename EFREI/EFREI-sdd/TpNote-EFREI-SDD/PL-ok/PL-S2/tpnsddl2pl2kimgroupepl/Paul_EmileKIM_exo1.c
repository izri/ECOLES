#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *suiv;
}node;

typedef node *chaine;
void creationChaine(chaine chaineEntier, int n);
void affichagePremier(chaine chaineEntier, int n);

void creationChaine(chaine chaineEntier, int n)
{
    int cpt = 3;
    node *curr;
    chaineEntier->info = 2;
    curr = chaineEntier;
    while(cpt <= n)
    {
        node *maillon = malloc(sizeof(*maillon));
        maillon->info = cpt;
        curr->suiv = maillon;
        curr = curr->suiv;
        cpt = cpt+1;
    }
    curr->suiv = NULL ;
}

void affichagePremier(chaine chaineEntier, int n)
{
    if(chaineEntier == NULL)
    {
        printf("Chaine vide\n");
    }
    else
    {
        printf("Liste des nombres premiers de 2 a %d:\n", n);
        node *parcours;
        parcours = chaineEntier;
        printf("%d\n", parcours->info); // on sait que 2 est un nombre premier, on l'affiche en premier
        parcours = parcours->suiv;
        while(parcours != NULL)
        {
            int nbr = 2;
            int res = 0;
            int verifSortie = 0;
            while(nbr != parcours->info && verifSortie == 0)
            {
                res = parcours->info%nbr;
                if(res == 0)
                {
                    verifSortie = 1; // on sort de la boucle si parcours->info est divisible par autre chose que lui-même
                }
                nbr = nbr+1;
            }
            if(verifSortie == 0)
            {
                printf("%d\n", parcours->info);
            }
            parcours = parcours->suiv;
        }
    }
}

int main()
{
    int n = 0;
    chaine chaineEntier = malloc(sizeof(chaineEntier));
    printf("Valeur de n?\n");
    scanf("%d", &n);
    creationChaine(chaineEntier, n);
    affichagePremier(chaineEntier, n);
    return 0;
}
