#include <stdlib.h>
#include <string.h>
#include <stdio.h>



typedef struct element element;
struct element{

	int val;
	struct element* nxt;
	
};



typedef element* llist;

void init_liste(llist liste, int N)
{
	element* tmp;
	tmp=liste; 
	int i;
	
	for(i=1;i<=N;i++)
	{
		tmp->val=i;
		tmp->nxt= tmp;
	}
}

void afficherliste(llist liste)
{
	element* tmp;
	tmp=liste;
	while(liste!=NULL)
	{
		printf("%d",tmp->val);
		tmp->nxt=tmp;
	}
}
void parcour_liste(llist liste)
{
	int i,valeur,valcube;
	element* tmp=liste;
	while ( liste != NULL)
	{
		tmp->val= valeur;
		valeur*valeur=valcube;
		tmp->nxt=tmp;
		return valcube;
	}
} 
int main()
{
	llist maliste1= NULL;
	init_liste(maliste1,100);
	afficherliste(maliste1);
	return 0;
}

		


