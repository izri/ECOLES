#ifndef LC_H_INCLUDED
#define LC_H_INCLUDED

typedef struct nombre
{
    int nbr;
    struct nombre *next;
} nombre;

typedef nombre* lsc;

lsc creationcellule();

lsc premierelt(lsc *liste);

void create(lsc *liste,int nb);

void afficher(lsc *liste);



#endif // LC_H_INCLUDED
