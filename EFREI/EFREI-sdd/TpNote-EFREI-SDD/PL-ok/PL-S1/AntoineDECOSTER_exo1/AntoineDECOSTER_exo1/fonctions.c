#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

liste *  premier_elt ()
{
    liste*elt;
    liste*tete;
    elt=(liste*)malloc(sizeof(liste));
    elt->suivant=tete;
    tete=elt;
    return elt;
}

int nbre_premier(liste*nombre)
{
    int nbre=(liste->nombre)
    for (int cptr=nbre-1, cptr>0, cptr--)
    {
        if (nbre%cptr!=0)
        {
            return nbre;
        }
        else
        {
            return 0;
        }
    }
}

