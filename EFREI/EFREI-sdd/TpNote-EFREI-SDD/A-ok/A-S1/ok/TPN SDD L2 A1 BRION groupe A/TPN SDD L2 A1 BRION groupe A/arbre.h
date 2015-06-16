#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "liste_chaine.h"


typedef struct noeud
{
  int valeur;
 struct noeud* precedent;
 struct noeud* droite;
 struct noeud* gauche;
}noeud;

typedef struct arbre
{
   struct noeud* racine;

}arbre;


arbre* arbrification(liste* chaine);
noeud* ajoue_noeud(noeud* parent,int valeur);
arbre* creation_arbre();


#endif // ARBRE_H_INCLUDED
