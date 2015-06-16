#include <stdio.h>
#include <stdlib.h>
typedef struct Maillon Maillon;
struct Maillon
{
    int nombre;
    Maillon *next;
};

typedef struct List List;
struct List
{
    Maillon *premier;
};


List * Init()
{
    List *list= malloc(sizeof(*list));
    Maillon*maillon = malloc(sizeof(*maillon));
    if (list==NULL || maillon==NULL)
    {
        exit(EXIT_FAILURE);
    }
    maillon->nombre=0;
    maillon->next=NULL;
    list->premier=maillon;

    return list;
}


void Ajouter(List*list, int nombre)
{
    Maillon*nouveau= malloc(sizeof(*nouveau));
    nouveau->nombre=0;
    nouveau->next=NULL;
    if (list==NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre= nombre;
    nouveau->next=list->premier;
    list->premier=nouveau;
}

void Afficher_list (List*list)
{
    Maillon*provis=malloc(sizeof(*provis));
    provis=list->premier;
    while(provis!= NULL)
    {
        printf("%d->", provis->nombre);
        provis=provis->next;
    }
    printf("NULL\n");
}

void List_N_nombre (List*list, int N)
{
    int i=0;
    Ajouter(list,2);
    for(i=2; i<N+1; i++)
    {
            Ajouter(list,i);

    }
}

int main()
{
 List*list= Init();
 int i;
 int N;
 List*listNnombre= Init();
 printf("Veuillez entrer un nombre! N\n");
 scanf("%d",&N);
 List_N_nombre(listNnombre,N);
 printf("LSC contenant des entiers de 2 à N");
 Afficher_list(listNnombre);
 Ajouter(list,2);
 for (i=2; i<N;i++)
 {
     if(i%2==1)
     {
         Ajouter(list,i);
     }

 }
 printf("Les nombres premiers compris entre 2 et N :");
 Afficher_list(list);
 return 0;
}
