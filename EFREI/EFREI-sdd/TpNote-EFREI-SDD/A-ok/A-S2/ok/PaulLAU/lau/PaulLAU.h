#ifndef PAULLAU_H_INCLUDED
#define PAULLAU_H_INCLUDED

typedef struct maillon
{
    int info;
    struct maillon *succ;
}maillon;

typedef maillon *liste;

int saisirN();
void creerLSC(liste, int);
void afficherLSC(liste);

liste calculParfait(liste);
#endif // PAULLAU_H_INCLUDED

