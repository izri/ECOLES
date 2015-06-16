#include <stdio.h>
#include <stdlib.h>


/** Déclarations structures et prototypes des fonctions  Exercice 1 */

typedef struct cellule
{
    int nbr;
    struct cellule* next;
}cellule;

cellule* creer_cellule_liste(int cpt);

cellule* ajouter_tete_liste(cellule* tete, cellule* cellule_a_ajouter);

cellule* parcourir_liste(cellule* tete);

void ajouter_queue_liste (cellule*, cellule*);

void afficher_liste(cellule* tete);

void nbr_parfaits_liste(cellule* tete);













/**Code des fonctions  Exercice 1*/

cellule* creer_cellule_liste(int cpt)
{
    cellule* new;

    new = malloc(sizeof(cellule));
    new -> nbr = cpt + 1;
    new -> next = NULL;

    return new;
}

cellule* ajouter_tete_liste (cellule* tete, cellule* cellule_a_ajouter)
{
    cellule_a_ajouter -> next = tete;

    tete = cellule_a_ajouter;

    return tete;

}

cellule* parcourir_liste (cellule* tete)
{
    cellule* tmp = NULL;

    tmp = malloc(sizeof(cellule));

    tmp = tete;

    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }

    return tmp;
}


void ajouter_queue_liste(cellule* tete, cellule* cellule_a_ajouter)
{
    cellule* tampon = NULL;

    tampon = parcourir_liste (tete);

    tampon -> next = cellule_a_ajouter;

    return;
}



void afficher_liste (cellule* tete)
{
    int nbr;

    if (tete == NULL)
    {
        printf("Votre liste est vide  \n");

    }

    else
    {
        printf("Votre liste : \n");
        while (tete != NULL)
        {
            nbr = tete -> nbr;
            printf("%d \n", nbr);
            tete = tete -> next;
        }
    }
}


void nbr_parfaits_liste(cellule* tete)
{
    //Etablir la liste des diviseurs d'un nombre grace a l'opérateur modulo
    //Stocker la liste des diviseurs établie  dans l'ordre croissant dans un tableau
    //Faire la somme des diviseurs jusqu'à l'indice N-2
    //Si cette somme est égale au nombre lui-même alors il s'agit d'un nombre parfai
//for (i=2; i>N; i++)
//{
//}
}















/** Fonction principale Main Exercice 1*/
int main()
{
    int N, cpt, outil ;

    cellule* liste = NULL;
    cellule* current;

    printf("Entrez une valeur N correspondant a la longueur de votre liste \n");
N=15;
/*
    do
    {
        printf("N = ");
        outil = scanf("%d", &N);
        scanf ("%*[^\n]");
        getchar ();
        printf("\n");
    }
    while ((outil != 2) || (N < 2));
*/
    for (cpt = 2 ; cpt <= N ; cpt = cpt + 1)
    {
        current = creer_cellule_liste(cpt);

        if (current == NULL)
        {
            printf("La creation de votre programme a echoue \n Verifier votre capacite memoire \n");
            return -1;
        }

        if (liste == NULL)
        {
            liste = ajouter_tete_liste(liste, current);
        }

        else
        {
            ajouter_queue_liste(liste, current);
        }
    }

    afficher_liste(liste);

    printf("\n");

    nbr_parfaits_liste(liste);

    afficher_liste(liste);

    free(liste);
    free(current);

    return 0;
}
