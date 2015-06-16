#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Maillon{
	int info;
	struct Maillon *next;
}Maillon;
typedef Maillon *Liste;

int EnterSize(){
	printf("Entrer la taille :\n");
	int size;
	do{
		if(scanf("%d", &size)!=1){
			exit(-1);
		}
	}while(size<0);
	return size;
}

void AfficherTaille(Liste LSC, int size){
	Maillon *tmp = LSC;
	int i=0;
	while(i<size){
		if(tmp != NULL){
			printf("%d ", tmp->info);
			tmp = tmp->next;
		}
		i++;
	}
}

void AfficherList(Liste LSC){    //Affiche les nombres de la liste
	if(LSC == NULL){
		printf("Liste Vide \n");
		exit(-1);
	}
	else{   int i=0;
		Maillon *temp=LSC;
		while(i<size){
			if(temp!=NULL){
				printf("%d -> ",temp->info);
				temp=temp->next;
			}}
		printf("NULL\n");
	}
}

void ChangeCirculaire(Liste LSC,Liste* premier, Liste* queue){

	while(LSC->next != NULL){
		LSC=LSC->next;
	}
	queue=LSC;
	queue->next=premier;
}


int main() {
	Liste ma_LSC=NULL;
	int i=0;
	Taille= EnterSize();
	AfficherList(ma_LSC,Taille);



	return 0;
}
