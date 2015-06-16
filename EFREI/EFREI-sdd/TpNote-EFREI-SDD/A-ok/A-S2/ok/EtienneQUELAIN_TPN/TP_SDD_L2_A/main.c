#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int n;
    liste p;
    printf("jusqu'a quel nombre ?");
    scanf("%d",&n);
   p = creation_cellule_et_liste(n);

     while(p!=NULL)
        {

        printf("%d \t ", p->nombre);
        p=p->succ;
        }
    //affiche_liste(p)*/
    fonction_compare_result(n);
    return 0;
}
