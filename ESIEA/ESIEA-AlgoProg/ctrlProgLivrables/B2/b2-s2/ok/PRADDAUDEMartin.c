#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
   int var;
   struct element *nxt;
} element;
// Declaration liste chainee simple

typedef element* llist;


llist add_end(llist list, int val)
{
    llist maillon=NULL;
    llist tmp=list;
    maillon=malloc(sizeof(element));
    maillon->var=val;
    maillon->nxt=list;

    if (tmp == NULL) 
    { 
        maillon->nxt=maillon;
        return maillon;
    }
    else
    {
        do
	{
	    tmp=tmp->nxt;
	}while(tmp->nxt != list);
	tmp->nxt=maillon;
    }

    return list;
}

void afficherCirc(llist list)
{
   llist tmp=list;
   do
   {
      printf("%d ", list->var);
      list=list->nxt;
   }while(list != tmp);
   printf("\n");
}

llist initLSCirc(llist list)
{
   int i,t;
   printf("Selectionnez un N entier : ");
   if (scanf("%d", &t)!=1) exit(-1);
   for (i=1;i<=t;i++)
   {
      list=add_end(list, i);
   }
   return list;
}

int nbParfaitCalcul(int o)
{
   // o comme objectif
   int i,total=0;
   for (i=1;i<=o/2;i++)
   {
      if (o%i==0) // si o divisible par i
      {
         total+=i;
      }
   }
   return total;
}

llist nbParfait(llist list)
{
   llist tmp=list;
   llist ptmp=NULL;

   while (tmp->nxt != list)
   {
      tmp=tmp->nxt;
   }

   ptmp=tmp; // on recupere le dernier de la liste
   tmp=list;

   do
   {
      if (nbParfaitCalcul(tmp->var)!=tmp->var) // Si le nombre n'est pas parfait
      {
         ptmp->nxt=tmp->nxt;
	 free(tmp);
      }
      ptmp=tmp;
      tmp=tmp->nxt;
   }while(list!=tmp);

   return list;
}

int main(void)
{
  llist liste=NULL;

  liste=initLSCirc(liste);

  afficherCirc(liste);
  
  liste=nbParfait(liste);

  afficherCirc(liste);

  return 1;
}
