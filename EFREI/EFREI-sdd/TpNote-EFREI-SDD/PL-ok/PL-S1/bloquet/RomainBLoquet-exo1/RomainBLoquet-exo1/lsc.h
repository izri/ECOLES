#ifndef LSC_H_INCLUDED
#define LSC_H_INCLUDED

typedef struct node
{
    int val;
    struct node *succ;
}node;

typedef node *Lsc;


Lsc creaNode ();
Lsc premierElt (Lsc *liste);
void creaLsc (Lsc *liste);
int taiLsc (Lsc liste);
void affichLsc (Lsc liste);
void affichePremier (Lsc liste);
void creaLsc2 (Lsc *liste, int nbcase);
Lsc creaNode2 ();
Lsc premierElt2 (Lsc *liste);

#endif // LSC_H_INCLUDED
