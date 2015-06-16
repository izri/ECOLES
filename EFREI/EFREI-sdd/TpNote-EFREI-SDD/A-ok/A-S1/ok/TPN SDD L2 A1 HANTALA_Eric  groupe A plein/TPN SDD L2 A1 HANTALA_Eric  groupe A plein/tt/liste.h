
#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef struct cell{
int val;
struct cell*next;
}cell;

typedef struct liste{
cell* head;
cell* fin;
int length;
}liste;

void init (liste* listea);

bool testlscvide (liste* lsc);

void Afficher(liste* lsc);

void newcell(liste* lsc, cell* nouveau);

void verifpremier(liste* lsc,int borne);



#endif // LISTE_H_INCLUDED

