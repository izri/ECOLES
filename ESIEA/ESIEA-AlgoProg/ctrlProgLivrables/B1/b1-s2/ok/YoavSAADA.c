#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
struct element
{
	int val;
	struct element *nxt;
	int fin;
};

typedef element* llist;

void AfficherListe(llist list) {

	int i, N;

	if (list == NULL) {
		exit(-1);
	}
	
	element* temp=list;
	
	scanf("%d", &N);

	for (i=1; i<=N; i++) {
		while(temp != NULL) { 
			printf("%d ", i);
			N = N->nxt;
		}
	}

	printf("\n");

}

int cube (int n) {
	int result;
	result = n * n * n;

	return result;
}

llist parcours (llist list) {

	int compt=1;
	int calcul,i;
	if (list != NULL) {
		for (i=1; i<=fin; i++) {
			while((list->val)!=elem &&  list!=NULL) {
				compt++;
				list = list->nxt;
				calcul = cube (list);		
			}	
		}
	}

}


int main () {

llist list = NULL;
int f;


AfficherListe(list);
list = parcours (llist list);
}
