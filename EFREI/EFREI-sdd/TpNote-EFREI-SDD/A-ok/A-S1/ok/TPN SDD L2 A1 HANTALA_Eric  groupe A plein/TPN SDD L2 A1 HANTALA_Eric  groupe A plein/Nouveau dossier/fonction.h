
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "liste.h"

typedef struct utree_node
{
    int content;
    struct utree_node *sag, *sad;
} utree_node;

typedef utree_node *utree;

void Parcours_r_to_l(utree t);

utree new_perfect_tree(int n, int e);

utree new_singleton_utree(int content);

#endif // FONCTION_H_INCLUDED
