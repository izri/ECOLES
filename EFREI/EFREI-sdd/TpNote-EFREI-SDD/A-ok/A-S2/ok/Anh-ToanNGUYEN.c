#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    struct cellule *next;
    int data;
}cellule;

void creation_liste(cellule **liste, int n)
{
    int cpt;
    cellule *l=NULL;

    *liste = (cellule*)malloc(sizeof(cellule));
    l = *liste;
    l->data = 1;
    for(cpt=1; cpt<=n; cpt++)
    {
        l->next = (cellule*)malloc(sizeof(cellule));
        l = l->next;
        l->data = cpt;
    }
    l->next = NULL;
}

void creation_liste(cellule **liste, int n);
int main()
{
    int choix=0;
    printf ("Que voulez vous faire ?\n");
    printf ("1. Nombre parfait.\n");
    printf ("2. Arbre binaire parfait.\n");
    printf ("3. Sortir.\n");
    scanf ("%d",&choix);
    if (choix==1)
    {
        cellule *liste=NULL, *l;
        int parcour;
        printf ("Saisir le nombre xxx a parcourir de 0 a xxx: \n");
        scanf("%d", &parcour);
        creation_liste(&liste, parcour);
        l=liste;
        printf("Les nombres parfait jusqu'a %d sont :\n",parcour);

        while(l!=NULL)
        {
            int i,somme=0;

            for (i=1;i<= (l->data/2);i++)
        {
            if ((l->data%i)==0)
            {
                somme=somme+i;
            }
        }
        if (somme==l->data)
        {
            printf("%d est parfait\n",l->data);
        }

        l = l->next;
        }
    }
    if (choix ==2)
    {
        printf ("Non Fait.\n");
        return 0;
    }
    else
    return 0;
}






