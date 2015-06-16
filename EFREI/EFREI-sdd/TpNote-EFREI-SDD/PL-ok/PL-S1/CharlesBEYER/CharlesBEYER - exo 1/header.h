#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct elem
{
    int val;
    struct elem* suivant;
}elem;

typedef struct elem *LSC;

LSC nouvelE();
void constrL1 (LSC *liste,int nb);
void affichage1 (LSC *liste);
void nbP(LSC *liste);
LSC nbP2(LSC *liste);
int verifP(int nb);




#endif // HEADER_H_INCLUDED
