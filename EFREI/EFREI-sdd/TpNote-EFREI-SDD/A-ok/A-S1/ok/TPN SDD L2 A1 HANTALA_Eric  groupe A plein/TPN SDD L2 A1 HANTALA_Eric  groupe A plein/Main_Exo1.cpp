#include <iostream>
#include "liste.h"
#include <stdio.h>
using namespace std;





int main()
{
    int n=0;
    liste* lsc = (liste*) malloc(sizeof(liste));
    init(lsc);

    cell* initial = (cell*) malloc(sizeof(cell));
    initial->val=1;
    initial->next=NULL;
    newcell(lsc,initial);

    cell* initial2 = (cell*) malloc(sizeof(cell));
    initial2->val=2;
    initial2->next=NULL;
    newcell(lsc,initial2);

    printf("Veuillez entrer la borne des nombres premiers \n");
    cin>>n;
    verifpremier(lsc,n);

    Afficher(lsc);

    return 0;
}
