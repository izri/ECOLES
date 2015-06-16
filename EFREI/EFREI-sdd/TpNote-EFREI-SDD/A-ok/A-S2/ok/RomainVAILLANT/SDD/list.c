#include "list.h"

#include <stdlib.h>
#include <stdio.h>

Node* Node_create(int n)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->n = n;

    return node;
}

Node* List_append(List* l, Node* node)
{
    if(*l == NULL)
    {
        *l = node;
        return node;
    }
    else
    {
        Node* current = *l;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;

        return node;
    }
}

void List_display(List l)
{
    Node* current = l;
    while(current != NULL)
    {
        printf("Node: %d\n", current->n);
        current = current->next;
    }
}

void List_keepPerfectNumber(List* l)
{
    Node* current = *l;
    while(current != NULL)
    {
        Node* to_remove = NULL;
        if(Int_isPerfect(current->n) == 0)
        {
            to_remove = current;
        }

        current = current->next;

        if(to_remove != NULL)
        {
            List_remove(l, to_remove);
        }
    }
}

void List_remove(List* l, Node* node)
{
    if(*l == node)
    {
        *l = (*l)->next;
    }
    else
    {
        Node* current = *l;
        while(current != NULL)
        {
            if(current->next == node)
            {
                current->next = node->next;
                break;
            }

            current = current->next;
        }
    }

    free(node);
}

int Int_isPerfect(int n)
{
    int result = 0;
    int i;
    for(i = 1; i <= n-1; ++i)
    {
        // Si i est un diviseur on l'additionne au resultat final
        if(n % i == 0)
        {
            result += i;
        }
    }

    if(result == n)
    {
        return 1;
    }

    return 0;
}

void List_destroy(List* l)
{
    while(*l != NULL)
    {
        Node* to_remove = *l;
        *l = (*l)->next;
        free(to_remove);
    }
}
