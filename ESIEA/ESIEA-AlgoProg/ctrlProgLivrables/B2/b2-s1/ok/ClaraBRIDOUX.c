#include<stdio.h>
#include<stdlib.h>

typedef struct list{ //boite

	int info;
	struct list *next;

}list;

typedef struct list * l; //adresse memoire de la boite


//CREATION D'UNE CELLULE
l create_cell(int i){

l cellule;
cellule = (l)malloc(sizeof(struct list));

cellule->info=i;

cellule->next=NULL;

return cellule;

}

//CREATION DU PREMIER ELEMENT
l premier_elt(l *deb){

l elt;
elt = create_cell(2);
*deb = elt;

return elt;

}

//CREATION DE LA LISTE CIRCULAIRE
void create_liste(int N, l *liste) {

l elt;
//l elt1;
l tmp;
int i;

	if (N>0){

		elt = premier_elt(liste);
//		elt1 = premier_elt(liste);


		for(i = 3; i<=N; i++) {

			tmp = create_cell(i);
			elt->next=tmp;
			elt=tmp;

		}
		
		elt->next = *liste;


	}


}

void afficher(l *liste) {

l elt, elt1;
elt = *liste;
elt1 = *liste;

	if(elt == NULL) {

		printf("La liste est vide!");

	}

	else{

		printf("La liste contient: ");

		
		printf("%d ",elt->info);
		elt=elt->next;
		
		while(elt->info!=elt1->info) {

			printf("%d ",elt->info);
			elt=elt->next;

		}

		printf("\n");

	}

}


/*void parfait(int n, l *liste, l *liste1){

int i;
l elt=*liste; // je stock mes diviseurs
l elt1 = *liste1; //liste de depart

while(elt1 != NULL) {

	for(i = 2; i<=n; i++) {

		if(n%i == 0) {

			elt =create_cell(i);
			elt= elt->next;

		}

	}
elt1=elt1->next;
}




}
*/
int main(){


l liste;
int N;

printf("Veuillez entrer un nombre >2 : ");

if(scanf("%d", &N) != 1) {

	exit(1);

}

create_liste(N, &liste);
afficher(&liste);

return 0;
}
