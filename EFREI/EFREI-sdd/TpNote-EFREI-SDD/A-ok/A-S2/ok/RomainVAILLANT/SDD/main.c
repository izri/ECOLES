#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "tree.h"

int main()
{
    int n = 500;

    List list = NULL;
    int i;
    for(i = 2; i <= n; ++i)
    {
        List_append(&list, Node_create(i));
    }

    printf("Première liste: \n");
    List_display(list);

    List_keepPerfectNumber(&list);
    printf("\nSeconde liste: \n");
    List_display(list);

    printf("Creation de l'arbre parfait...\n");
    BTree btree = BTree_fromList(&list);

    BTree_display(btree);

    printf("\nHauteur de l'arbre: %d\n", BTree_size(btree));

    BTree_destroy(&btree);
    List_destroy(&list);
    return 0;
}
