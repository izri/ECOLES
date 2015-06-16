#include "liste_chaine.h"




//--------------------------------------
int test_premier(liste *chaine,int n)
{
    maillon* tampon=chaine->tete;

    while(tampon!=NULL)
    {
        if(n%tampon->valeur==0)
        {
            return 0;
        }

      tampon=tampon->suivant;
    }

    return 1;
}

liste* liste_nombre_premier1(int n)
{// cree la liste des nombres premiers directement
   liste* chaine=creation_liste();
   int i;

   for(i=2;i<n+1;i++)
    {
     if(test_premier(chaine,i))
      {
        chaine=ajouter_un_maillon(chaine,i);
        printf("\n %d",i);
      }
    }

return chaine;
}

liste* liste_nombre_premier2(int n)
{// cree la liste des n entier puis supprim les non premier
   liste* chaine=creation_liste();
   maillon* tampon1=chaine->tete;
   maillon* tampon2=chaine->tete;
   maillon* tampon3=NULL;
   int i;

   for(i=2;i<n+1;i++)
    {
    chaine=ajouter_un_maillon(chaine,i);
    }



    while(tampon1!=NULL )
        {tampon2=chaine->tete;
          while(tampon1->valeur<(tampon2->valeur/2)+1)
            {
               if(tampon1->valeur%tampon2->valeur==0)
               {tampon3=tampon1;
               tampon1=tampon1->precedent;
               chaine=supprimer_un_maillon(chaine,tampon3);
               }
            }
        tampon1=tampon1->suivant;
        }

tampon1=chaine->tete;
while(tampon1!=NULL )
        {
        printf("\n %d",tampon1->suivant->valeur);
        tampon1=tampon1->suivant;
        }

return chaine;
}



liste* creation_liste()
{
   liste* nouveau=(liste*)malloc(sizeof(liste));

    nouveau->queu=NULL;
    nouveau->tete=NULL;

   return nouveau;
}



liste* ajouter_un_maillon(liste* chaine,int valeur)
{
    maillon* nouveau=(maillon*)malloc(sizeof(maillon));

    if(chaine->tete==NULL)
        {
        chaine->queu=nouveau;
        chaine->tete=nouveau;
        nouveau->precedent=NULL;
        }
    else
        {
          nouveau->precedent=chaine->queu;
          chaine->queu->suivant=nouveau;
          chaine->queu=nouveau;

        }
        nouveau->suivant=NULL;
        nouveau->valeur=valeur;


return chaine;
}


liste* supprimer_un_maillon(liste* chaine,maillon* maillon)
{

    if(chaine==NULL )
        {
        return chaine;
        }
    else
        {
           if(chaine->tete==maillon)
                {
                 chaine->tete=maillon->suivant;
                }
            else
                {
                    maillon->precedent=maillon->suivant;
                }

         if(chaine->queu==maillon)
                {
                 chaine->queu=maillon->precedent;
                }
        else
                {
                    maillon->suivant=maillon->precedent;
                }
        }

free(maillon);

return chaine;
}

void desalouer(liste* liste)
{
    maillon* tampon1=liste->tete;
    maillon* tampon2;
    while(tampon1!=0)
        {tampon2=tampon1->suivant;
        free(tampon1);
        tampon1=tampon2;
        }
    free(liste);

}
