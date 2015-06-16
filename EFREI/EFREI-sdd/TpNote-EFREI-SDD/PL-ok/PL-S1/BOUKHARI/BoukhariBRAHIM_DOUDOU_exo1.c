#include <stdio.h>
#include <stdlib.h>


typedef struct node
    {
        int ent;
        struct node *next;

    }node;


node *tab_entier(int N)
{
    node *tete = (node*)malloc(sizeof(node));
    tete->ent = 2;
    tete->next = NULL;
    node *temp = tete;

    int i = 0;
    if(N > 2)
    {

        for(i = 3; i <= N; i++)
        {
            node *nouveau = (node*)malloc(sizeof(node));
            nouveau->ent = i;
            nouveau->next = NULL;

            temp->next = nouveau;
            *temp = *nouveau;

        }
    }

    while((tete->next =! NULL))
    {
        printf("%d\n", tete->ent);
        tete = tete->next;
    }

    return tete;
}

node primes(node *liste)
{
    node *l = liste;
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while((liste->next =! NULL))
    {
        int i = 0;
        for(i = 3; i < liste->ent; i++)
        {
            node *temp = liste;
            if(liste->ent % i == 0)
            {
                liste=liste->next;
                free(temp);
            }
            else
            {
                liste=liste->next;
            }
        }

    }

    while((l->next =! NULL))
    {
        printf("%d \n", l->ent);
        l = l->next;
    }
}


int main()
{
    primes(tab_entier(150));
    return 0;
}























