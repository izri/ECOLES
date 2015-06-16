#include "arbre.h"



arbre* arbrification(liste* chaine)
{//bugger
    maillon* tampon=chaine->tete;
    noeud * tampon1;
    int profondeurmax,profondeur;

arbree->racine=NULL;


    while(tampon!=NULL)
    {
      if(arbree->racine=NULL)
        {
        tampon1=arbree->racine;
        tampon1->valeur=tampon->valeur;
        supprimer_un_maillon(chaine,tampon);
        tampon1->precedent=NULL;
        tampon1->droite=NULL;
        tampon1->gauche=NULL;
        profondeurmax=2;
        profondeur=1;
        }
        else
        {
         while(profondeur!=profondeurmax)
            {
             if(tampon1->gauche==NULL)
                {
                 tampon1->gauche=ajoue_noeud(tampon1,tampon);
                }
            else if(tampon1->droite==NULL)
                {
                 tampon1->droite=ajoue_noeud(tampon1,tampon);
                }
            else
                {
                 tampon1
                }

            }


        }

      tampon=tampon->suivant;
    }


}


arbre* arbrification(arbre* arbre, liste* chaine)
{//pas fini
    int test=1;
    noeud* tampon=arbre->racine;
if(chaine->tete!=NULL)
    {
       while(test==1)
           {
              if(tampon->gauche==NULL)
                {
                 tampon->gauche->valeur= chaine->tete->valeur;
                }
            else if(tampon->droite==NULL)
                {
                 tampon->droite->valeur= chaine->tete->valeur;
                }
            else
                {

                tampon=tampon->gauche;

                }


           }



     chaine->tete=supprimer_un_maillon(chaine,chaine->tete);
    }





return arbre;
}





noeud* ajoue_noeud(noeud* parent,int valeur)
{
   noeud* nouveau=(noeud*)malloc(sizeof(noeud));

    nouveau->precedent=parent;
    nouveau->valeur=valeur;
    nouveau->gauche=NULL;
    nouveau->droite=NULL;
  return nouveau;
}




arbre* creation_arbre()
{
arbre* arbree=(arbre*)malloc(sizeof(arbre));
arbree->racine=NULL;

return arbree;
}



