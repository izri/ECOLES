/*
**  GUICHARD Benjamin
**  TP noté SDD
**  Exercice n°1
**  18/11/2014
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int nombre;
    struct node * succ;
} node;
typedef node * LSCnode;

LSCnode initialiser_liste(int N);
LSCnode remplir_liste(int i);
LSCnode filtre_premier(LSCnode liste);
void parcourir_liste(LSCnode liste);

int main()
{
    int liste = initialiser_liste(150);

    parcourir_liste(liste);
    filtre_premier(liste);
    parcourir_liste(liste);

    return 0;
}

LSCnode initialiser_liste(int N)
{
    printf(" Initialisation de la liste ...\n\n");

    LSCnode liste = malloc(sizeof(liste));

    LSCnode actuel = liste;

    int i;
    for (i=2;i<=N;i++)
    {
        actuel->succ = remplir_liste(i);
        actuel = actuel->succ;
    }

    return liste;
}

LSCnode remplir_liste(int i)
{
    LSCnode new_node = malloc(sizeof(new_node));

    new_node->nombre = i;
    new_node->succ = NULL;

    return new_node;
}

LSCnode filtre_premier(LSCnode liste)
{
    printf("\n Filtrage des nombres premiers ...\n");

    LSCnode actuel = liste->succ;
    LSCnode precc = actuel;

    int x;

    if (actuel == NULL)
        printf("La liste est vide !\n\n");

    while (actuel != NULL)
    {

        for(x=2;x<actuel->nombre;x++)
        {
            if(actuel->nombre%(x) == 0)
            {
                x = actuel->nombre;
                precc->succ = actuel->succ;

            }
        }

        actuel = actuel->succ;
        precc=precc->succ;
    }
}

void parcourir_liste(LSCnode liste)
{
    printf(" Affichage de la liste : \n\n");
    LSCnode actuel = liste;

    if (actuel == NULL)
        printf("La liste est vide !\n\n");

    while (actuel != NULL)
    {
        printf(" %d ->", actuel->nombre);
        actuel = actuel->succ;
    }
}
