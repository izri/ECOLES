#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
int main()
{
    Abr a;
    int i=0;
    int b[10] = {1, 2, 3, 4, 5, 6, 7};

     a = creaNoeud(b[0]);
     a->sag = creaNoeud(b[1]);
     a->sad = creaNoeud(b[2]);


}
