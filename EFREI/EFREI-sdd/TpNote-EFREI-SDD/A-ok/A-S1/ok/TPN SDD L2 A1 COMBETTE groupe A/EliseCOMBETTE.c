#include <stdio.h>
#include <stdlib.h>

typedef struct liste
{
    int elt;
    struct liste* next;
} Liste;

typedef struct noeud
{
    int elt;
    struct noeud* sag;
    struct noeud* sad;
} Noeud;

typedef struct file
{
    Liste* head;
    Liste* tail;
} Fifo;

typedef Noeud* Arbre;

/** Exercice 1 */

Liste* New_node(int e);
void Affiche_liste(Liste* l);
Liste* Liste2toN(int N);
Liste* NbPremiers(Liste* l);

Liste* New_node(int e)
{
    Liste* l = NULL;
    l = (Liste*)malloc(sizeof(Liste));
    if(l == NULL)
    {
        printf("Erreur creation du maillon\n");
        return NULL;
    }
    l->elt = e;
    l->next = NULL;
    return l;
}

Liste* Liste2toN(int N)
{
    Liste* l = NULL;
    Liste* nouv = New_node(2);
    l = nouv;

    int i;
    Liste* parcours = l;
    for(i=3;i<=N;i++)
    {
        nouv = New_node(i);
        parcours->next = nouv;
        parcours = parcours->next;
    }
    Affiche_liste(l);
    return l;
}

void Affiche_liste(Liste* l)
{
    if(l == NULL)
    {
        printf("LISTE VIDE\n");
        return;
    }

    while(l != NULL)
    {
        printf("%d ",l->elt);
        l = l->next;
    }
    printf("\n");
}

Liste* NbPremiers(Liste* l)
{
    if(l == NULL)
    {
        printf("LISTE VIDE\n");
        return NULL;
    }
    Liste* parcours = l->next; /** 2 est un nombre premier et par défaut le 1er élément de la liste */
    Liste* prec = l;
    int i;
    while(parcours != NULL)
    {
        /** je ne sais pas comment prouver qu'un entier est premier donc je mets fin à la boucle, de façon à ce que le programme ne boucle pas à l'infini : */
        parcours = NULL;
    }
    return l;
}


/** Exercice 2 */

Fifo* fpush(Fifo* f, int e);
Fifo* fpop(Fifo* f);
Arbre ArbreBinaire_larg(Liste* l);

Fifo* fpush(Fifo* f, int e)
{
    Liste* p = New_node(e);

    if(f->head == NULL)
        f->head = p;
    else
    {
        Liste* parcours = f->head;
        while(parcours->next != NULL)
            parcours = parcours->next;
        parcours->next = p;
    }
    f->tail = p;

    return f;
}

Fifo* fpop(Fifo* f)
{
    if(f->head == NULL)
    {
        printf("FILE VIDE\n");
        return NULL;
    }
    Liste* p = f->head;
    f->head = p->next;
    free(p);

    if(f->head == NULL)
        f->tail = NULL;

    return f;
}

Arbre ArbreBinaire_larg(Liste* l)
{
    Arbre a = NULL;
    a = (Arbre)malloc(sizeof(Noeud));

    return a;
}


int main()
{
    Liste* l = NULL;
    l = Liste2toN(15);
    return 0;
}
