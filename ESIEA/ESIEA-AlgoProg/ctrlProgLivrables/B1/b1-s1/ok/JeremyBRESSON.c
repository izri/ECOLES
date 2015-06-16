#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
struct element
{
int val;
struct element *nxt;
};

typedef element* llist;

llist ajouterAuDebut(llist list,int valeur) {
	
	
	element* newList=malloc(sizeof(element));
	newList->val=valeur;
	newList->nxt=list;
	
	return newList;
}

void AfficherListe(llist list) {

	if (list == NULL) {
		exit(EXIT_FAILURE);
	}

	element* temp=list;
	
	printf("Votre liste actuelle est :\n");

	while(temp != NULL) {

		printf("%d ",temp->val);

		temp=temp->nxt;
	}

	printf("\n");
}

int main() {
	
	llist list = NULL;
	int i;
	int n=50;
	
	for(i=2;i<=n;i++) {
	
	ajouterAuDebut(list,i);
	}
	AfficherListe(list);

return 0;
}
