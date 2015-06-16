#ifndef PAFRAIT_H_INCLUDED
#define PAFRAIT_H_INCLUDED

typedef struct liste
{
    int valeur;
    struct liste *suivant;
} liste;
typedef liste* LSCMonome;

void Remplissage_LSC(LSCMonome lst);
LSCMonome Nouvel_element(LSCMonome lst, int valeur);
LSCMonome Initialisation_LSC(LSCMonome lst);


#endif // PAFRAIT_H_INCLUDED

