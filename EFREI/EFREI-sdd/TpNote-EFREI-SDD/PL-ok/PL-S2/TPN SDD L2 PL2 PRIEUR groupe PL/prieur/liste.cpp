
#include "liste.h"



void init_liste(fifo* liste)
{
    liste->head=NULL;
    liste->queue=NULL;
    liste->lenght=0;
}

int isEmpty_liste(fifo* liste) // Renvoie 1 si la liste est vide, 0 sinon
{
    if (liste->head==NULL)
    {
        return 1;
    }
    return 0;
}

int push_liste(int val, fifo* liste) //retourne 0 si erreur, 1 sinon
{
    cell* temp;
    temp=(cell*)malloc(sizeof(cell));
    temp->info=val;
    temp->next=NULL;

    if(isEmpty_liste(liste)==1) // cas de la liste vide
    {
        liste->head=temp;
        liste->queue=temp;
        liste->lenght++;
        return 1;
    }
    else // il y au moins un élément dans la liste
    {
        liste->queue->next=temp;
        liste->queue=temp;
        liste->lenght++;
        return 1;
    }
    return 0;
}

int pop(fifo* liste) // retourne 0 si erreur, sinon 1.
{
      if (liste->head==liste->queue) // 1 seul élément dans la file
      {
          free(liste->head);
          liste->head=liste->queue=NULL;
          return 1;
      }
      else
      {
          cell* boite;
          boite = liste->head;
          liste->head=liste->head->next; // On met à jour la tête de file
          free(boite); // on libère l'élément qui était en tête
          return 1;
      }
      return 0;
}

void print_liste(fifo * liste) // affiche le contenu de la liste
{
    cell* temp;
    temp=(cell*)malloc(sizeof(cell));
    temp=liste->head;
    int i=0;

    if (isEmpty_liste(liste)==1) printf("Liste vide.\n");
    else
    {
        printf("Liste complete : \n");
        for (i=0; i<liste->lenght;i++)
        {
            printf("Valeur : %d\n", temp->info);
            temp=temp->next;
        }
    }
}

int test_premier(int val) //test si une nombre est premier, renvoie 1 s'il l'est, 0 sinon.
{
    int i;

    for (i = 2; i < val; i++)
    if (val % i == 0)
    {
        return 0;
    }
    return 1;
}

void filtrage_liste (fifo* liste) // supprime les non premiers
{
    cell* temp;
    temp=(cell*)malloc(sizeof(cell));
    temp=liste->head;
    if (test_premier(temp->info)==0)
    {
        // supprimer l'élément
    }
}

