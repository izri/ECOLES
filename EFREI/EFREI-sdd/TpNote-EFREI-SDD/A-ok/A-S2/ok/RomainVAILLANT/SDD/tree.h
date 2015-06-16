#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "list.h"

typedef struct BTreeNode
{
    int n;

    struct BTreeNode* left;
    struct BTreeNode* right;
} BTreeNode;

typedef BTreeNode* BTree;

BTreeNode* BTreeNode_create(int n);
BTree BTree_fromList(List* l);
void BTree_display(BTree btree);
int BTree_size(BTree btree);
void BTree_destroy(BTree* btree);

#endif // TREE_H_INCLUDED
