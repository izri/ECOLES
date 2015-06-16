#include <stdio.h>

typedef struct liste
{
    struct liste * tete;
    struct liste * suivant;
    long nombre;
}liste;

liste * premier_elt ();
int nbre_premier (liste*nombre);
