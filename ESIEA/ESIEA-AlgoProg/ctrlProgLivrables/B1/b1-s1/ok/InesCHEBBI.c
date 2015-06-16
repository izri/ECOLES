#include <stdlib.h>
#include <stdio.h>

typedef struct element
element;
struct element {
	int val;
	struct element *nxt;
}
typedef element *llist;

void afficherListe (llist liste, int element) {
	element *tmp=liste;
	while(tmp!=NULL){
		printf("%d", tmp->val);
		tmp=tmp->nxt;
	}
}

void parcourirListe (llist liste, int element) {
	if (liste!=NULL){
		while((liste->val)!=element && liste!=NULL) {
			compteur++;
			element=element*element*element;
			liste=liste->nxt;
			}
	else {
	printf ("La liste est vide");
	}
}

int main () {
N=100;
afficherListe (liste, N);
parcourirListe (liste, N);
} return 0;



