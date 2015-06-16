#include "tree.h"

#include <stdlib.h>
#include <stdio.h>

BTreeNode* BTreeNode_create(int n)
{
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->n = n;

    return node;
}

BTree BTree_fromList(List* l)
{
    // Ne fonctionne que pour le cas de l'exercice.
    if(*l == NULL)
    {
        return NULL;
    }

    BTree tree = BTreeNode_create((*l)->n);

    if((*l)->next)
    {
        tree->right = BTree_fromList(&(*l)->next->next);
        List_remove(l, (*l)->next->next);
    }

    tree->left = BTree_fromList(&(*l)->next);


    return tree;
}

int BTree_size(BTree btree)
{
    if(btree == NULL)
    {
        return 0;
    }
    else
    {
        int left_size = BTree_size(btree->left);
        int right_size = BTree_size(btree->right);

        int max = (left_size >= right_size) ? left_size : right_size;
        return 1 + max;
    }
}

void BTree_display(BTree btree)
{
    if(btree == NULL)
    {
        return;
    }

    printf("BTreeNode: %d\n", btree->n);

    BTree_display(btree->left);
    BTree_display(btree->right);
}

void BTree_destroy(BTree* btree)
{
    if(*btree == NULL)
    {
        return;
    }

    BTree_destroy(&(*btree)->left);
    BTree_destroy(&(*btree)->right);

    free(*btree);
    *btree = NULL;
}
