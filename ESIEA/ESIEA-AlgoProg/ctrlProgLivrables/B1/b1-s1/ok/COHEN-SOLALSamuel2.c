#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
struct element
{
	int val;
	struct element *nxt;
	struct element *prec;
};

typedef element* llist;
llist ajouterEnFin(llist list, int valeur)
{
	element* newList = malloc(sizeof(element));
	newList->val = valeur;
	newList->nxt = NULL;
	if(list == NULL)
	{
		return newList;
	}
	else
	{
		element* tmp=list;
		while(tmp->nxt != NULL)
		{
			tmp = tmp->nxt;
		}
		tmp->nxt =newList;
		return list;
	}
}

void AfficherListe(llist list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element* tmp=list;
	printf("Votre liste actuelle est :\n");
	while(tmp != NULL)
	{
		printf("%d ",tmp->val);
		tmp=tmp->nxt;
	}
	printf("\n");
}



int main(int argc, char **argv)
{
	llist list = NULL;
	int i;
	int n=10;
	for(i=2;i<=n;i++)
	{
		list = ajouterEnFin(list, i);
	}
	AfficherListe(list);

	return 0;
}

