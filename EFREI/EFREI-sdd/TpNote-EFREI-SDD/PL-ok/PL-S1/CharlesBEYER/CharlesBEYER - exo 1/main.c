#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int nb;
    LSC liste;
    liste = NULL;

    do
    {
        printf("\n    Saisir le nombre de valeurs souhait%c dans la liste :  ",130);
        fflush(stdin);
    }while((scanf("%d",&nb))==0);

    constrL1(&liste,nb);
    printf("\n  Affichage de la liste cr%ce :\n",130);
    affichage1(&liste);
    printf("\n");

    nbP(&liste);
    printf("\n  Affichage de la liste tri%ce ne contenant que des nombres premiers :\n",130);
    affichage1(&liste);
    printf("\n");



    LSC liste2;
    liste2 = NULL;
    constrL1(&liste2,150);
    nbP(&liste2);
    printf("\n  Affichage des 150 nombres premiers inf%crieurs ou %cgale %c 150 :\n",130,130,133);
    affichage1(&liste2);



    /* LSC NP;
    NP = nbP2(&liste);
    affichage1(&NP);*/

    printf("\n");
    return 0;
}
