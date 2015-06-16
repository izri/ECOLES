#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	int val;
	struct element *succ;
}element;
typedef element *list;

list ajouterDebut(list liste, int valeur)
{
	element *nouvelElement=malloc(sizeof(element));
	nouvelElement->val=valeur;
	nouvelElement->succ=liste;
	return nouvelElement;
}

list ajouterEnfin(list liste, int valeur)
{
	element *nouvelElement=malloc(sizeof(element));
	nouvelElement->val=valeur;
	nouvelElement->succ=liste;
	return liste;
}

void afficherListe(list liste)
{
	element *tmp=liste;
	while(tmp->succ !=NULL)
	{
		printf("%d ", tmp->val);
		tmp=tmp->succ;
	}


}


void parcourirListe(list liste)
{
	

	
}

int main()
{
	int N=200;
	int i;
	list ma_liste=NULL;
	ajouterDebut(ma_liste, 2);
	ajouterEnfin(ma_liste, N);

	for(i=2;i<=N;i++);
	{
		afficherListe(ma_liste);
	}

	return 0;
}
