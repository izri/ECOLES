#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int val;
	struct element *succ ;
} element;
typedef element *llist;

llist Ajouterfinlist( llist liste, int n )
{
	element* nouvelelement = malloc(sizeof(element));
	nouvelelement -> val = n;
	nouvelelement -> succ = liste;

	if ( liste == NULL )
	{
		return nouvelelement;
	}

	else
	{
		element* tmp = liste;
		while (tmp!=NULL)
		{
			tmp=tmp->succ;
		};
		tmp->succ = nouvelelement;
	}
	return liste;
}

int Afficherliste( llist liste )
{
	if ( liste == NULL )
	{
		return 0;
	};

	else {	element* tmp = liste;

		printf("%d",tmp->val);

		tmp = tmp -> succ;

		while ( tmp != liste )
		{
			printf("%d",tmp->val);
			tmp = tmp -> succ;
		};
	return 0;
}

int

int main ()
{
	int N=180;
	int i;
	element* maliste = NULL;

	for (i=0;i<N;i++)
	{
		maliste=Ajouterfinlist(maliste,i);
	}

	Afficherliste ( maliste );

	return 0;
}

