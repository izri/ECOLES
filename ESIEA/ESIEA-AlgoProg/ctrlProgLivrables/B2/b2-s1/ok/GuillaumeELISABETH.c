#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int number;
    Element *next;
};

typedef struct Liste Liste;
struct Liste
{
    Element *first;
};

Liste *init()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if(liste == NULL || element ==  NULL)
    {
        exit(EXIT_FAILURE);
    }

    element -> number = 2;
    element -> next = element;
    liste -> first = element;

    return liste;
}


void add(Liste *liste, int newnb)
{
    Element *new = malloc(sizeof(*new));
    if(liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new -> number = newnb;
    new -> next = liste ->first;

    Element  *next = new;
}

void Show(Liste *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *now = liste -> first;

    while(now != NULL)
    {
        printf("%d  ",now -> number);
        now = now -> next;
    }
}
void Perfect(Liste *liste)
{
    int compteur = 1;

    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *now = liste -> first;



}




int main()
{
    Liste *Mylist = init();

    int i,N;

    for(i=2; i<=N;i++)
    {
        add(Mylist,i);
    }
    Show(Mylist);
    return 0;
}
