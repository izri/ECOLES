#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct elem
{
    int val;
    struct elem *droite;
    struct elem *gauche;
}elem;

typedef struct elem *arbre;

void initA (arbre *liste);
void affichageA(arbre *liste);
void constrA(arbre *liste);

#endif // HEADER_H_INCLUDED
