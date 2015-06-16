#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

typedef struct Liste Liste;
typedef struct Element Element;

struct Element{
    int nombre;
    Element *suivant;
};

struct Liste {
    Element *premier;
    Element *dernier;
};

Liste *initialiser();
void insererElement(Liste *liste, int nombre, int testParfait);
void afficherListe(Liste *liste);
int testNombreParfait(int nombre);

#endif // LISTE_H_INCLUDED
