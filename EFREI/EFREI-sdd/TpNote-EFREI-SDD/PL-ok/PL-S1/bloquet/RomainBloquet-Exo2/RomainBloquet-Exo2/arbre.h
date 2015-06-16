#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

typedef struct noeud
{
    int val;
    struct noeud *sag;
    struct noeud *sad;
}noeud;

typedef noeud *Abr;

Abr creaNoeud (int val);
#endif // ARBRE_H_INCLUDED
