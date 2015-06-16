#include "fonction.h"
#include <iostream>

utree new_singleton_utree(int content)
{
    utree newt = (utree) malloc(sizeof(utree_node));
    newt->content = content;
    newt->sag = NULL;
    newt->sad = NULL;
    printf("Nouveau noeud cree\n");
    return newt;
}


void Parcours_r_to_l(utree t)
{
    if (t == NULL)return;
    printf("%d",t->content);
    printf("\n");
    Parcours_r_to_l(t->sag);
    Parcours_r_to_l(t->sad);
}

utree new_perfect_tree(int n, int e)
{
    utree a;

    a = new_singleton_utree(e);

    if (n>0)
    {
        a->sag = new_perfect_tree((n-1),(2*e));
        a->sad = new_perfect_tree((n-1),(2*e+1));
    }
    return a;
}
