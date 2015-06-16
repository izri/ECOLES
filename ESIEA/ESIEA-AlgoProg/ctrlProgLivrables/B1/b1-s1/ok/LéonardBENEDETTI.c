#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    unsigned int info;
    struct maillon *succ;
} maillon;

typedef maillon* liste;

liste createCircularList(unsigned int n)
{
    if(n < 2)
        return NULL;

    liste l;
    maillon *a, *b;

    a = malloc(sizeof(maillon));
    l = a; 

    a->info = 2;
    a->succ = a;

    if(n == 2)
        return l;

    unsigned int i;
    for(i = 3 ; i <= n ; ++i)
    {
        b = malloc(sizeof(maillon));
        b->info = i;

        a->succ = b;
        b->succ = l;
        a = b;
    }

    return l;
}

void freeList(liste *l)
{
    maillon *i, *n;
    i = *l;

    do
    {
        n = i->succ;
        free(i);
        i = n;
    } while(i != *l);
}

void showList(liste l)
{
    maillon *i;
    i = l;

    do
    {
        printf("%d -> ", i->info);
        i = i->succ;
    } while(i != l);

    printf("NULL\n");
}

void showListInf150(liste l)
{
    maillon *i;
    i = l;

    do
    {
        if(i->info <= 150)
            printf("%d -> ", i->info);
        else
            break;

        i = i->succ;
    } while(i != l);

    printf("NULL\n");
}

void cubize(liste l)
{
    maillon *i;

    unsigned int c;

    i = l;

    do
    {
        c = i->info;
        i->info = (c * c * c);
        i = i->succ;
    } while(i != l);
}

int main()
{
    int n = 0;

    printf("N ? ");
    if(scanf("%d", &n) && n >= 2)
    {
        liste nQuelconque;

        nQuelconque = createCircularList(n);
        printf("On affiche la liste : ");
        showList(nQuelconque);
        cubize(nQuelconque);
        printf("On affiche la liste \"cubisée\" : ");
        showList(nQuelconque);
        printf("On affiche la liste avec les valeurs des cubes inférieures à 150 : ");
        showListInf150(nQuelconque);
        freeList(&nQuelconque);

        return 0;
    }
    else
    {
        printf("n doit être un entier naturel supérieur ou égal à 2");
        return 1;
    }
}
