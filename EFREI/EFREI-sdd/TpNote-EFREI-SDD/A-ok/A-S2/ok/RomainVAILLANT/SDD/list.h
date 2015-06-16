#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node
{
    int n;
    struct Node* next;
} Node;

typedef Node* List;

Node* Node_create(int n);
Node* List_append(List* l, Node* node);
void List_display(List l);
void List_keepPerfectNumber(List* l);
int Int_isPerfect(int n);
void List_remove(List* l, Node* node);
void List_destroy(List* l);

#endif // LIST_H_INCLUDED
