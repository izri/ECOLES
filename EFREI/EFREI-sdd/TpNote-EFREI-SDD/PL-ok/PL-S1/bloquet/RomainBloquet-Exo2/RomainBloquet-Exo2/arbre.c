#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

Abr creaNoeud (int val)
{
    Abr node=malloc(sizeof(Abr));
    node->val = val;
    node->sad = NULL;
    node->sag = NULL;
}
