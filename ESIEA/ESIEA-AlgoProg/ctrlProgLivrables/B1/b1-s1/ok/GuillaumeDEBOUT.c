#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct typedef element element;

struct element 
{
	int info;
	struct element* succ;
};

typedef element* llist;


llist creatCell () {

	int a;
	a=2;

	llist list = malloc(sizeof(element));
	list->info = a;
	list->succ = NULL;
	a++;
	return list;

}


llist firstCell (llist*list) {

	llist p;

	p=creatCell();
	*list = p;
	return p;

}


void creatList (llist*list, int n) {

	llist cellule,ptr;
	int i;

	if (n>0) {
		cellule = firstCell(list);

		for(i=0; i<n; i++) {
			ptr = creatCell ();
			cellule->succ = ptr;
			cellule = ptr;
		}
	}

}


void afficherList (llist list) {

	int i;
	llist temp = list;

	if (list == NULL) {
		exit(-1);
	}

	else {

		while(temp != NULL) {
			printf("%d->" , temp->info);
			temp = temp->succ;
		}
	}

}

int main () {

	llist *list = NULL;
	int n;
	printf("entrer le nombre de cellules:\n");
	scanf("%d" , & n);

	creatList(&list, n);
	afficherList(list);


	return 0;



}





