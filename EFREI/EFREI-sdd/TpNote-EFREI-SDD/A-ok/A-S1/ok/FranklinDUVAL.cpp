#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Lst
{
    int val;
    struct Lst *suivant;
}Lst;

typedef struct Lst *LSC;

LSC creationL(int nb);
void nombre_premier (LSC liste);

LSC creationL()
{
    LSC nouveau;
    int cpt = 3;
    nouveau = (LSC)malloc(sizeof(Lst));
    nouveau->suivant = NULL;
    nouveau->val = 2;

    return nouveau;
}

void constrL (LSC *liste, int nb)
{
    int cpt;
    cpt = 0;
    LSC tmp;
    *liste = creationL();
    tmp = *liste;
    cpt++;

    LSC nouveau;

    while (cpt < nb)
    {
        nouveau = creationL();
        tmp->suivant = nouveau;
        tmp = nouveau;
        nouveau->val = cpt + 3;
        cpt ++;
    }
}



void nombre_premier (LSC *liste)
{
    int cpt = 0;
    int premier;
    LSC nouveau;
    LSC tmp;
    nouveau = *liste;
    tmp = nouveau;
    /*


*/
}


int main()
{

    return 0;
}
