#include <stdlib.h>
#include <stdio.h>

typedef struct list{
	int entier;
	struct list *succ;
}list;



list remplirLaListe(list *liste, int N){
	
	int i=1;
	list *elem=malloc(sizeof(list));
	list *l=liste;
	for(i=1;i<=N;i++){		
				
		while(liste -> succ!=NULL){
			liste = liste -> succ;
		}			
		liste -> succ = elem;
		elem -> entier = i;
	}
		elem->succ=l;
	return *liste;
}


void afficherLaListe(list *liste, int N){

	int i=1;
	if(liste==NULL){
		printf("La liste est vide.");
	}else{	
		for(i=1;i<=N;i++){
			printf("%d ", liste -> entier);
			liste = liste -> succ;
		}
	}
}	

int main() {
	
	int var;
	do{
		if(scanf("%d", &var)!=1){
			printf("Input error");
		}
	}while(var<0);
	list *liste=NULL;	
	remplirLaListe(liste, var);
	afficherLaListe(liste, var);
	
	return 0;

}
