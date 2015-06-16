#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
	int info ;
	struct maillon *succ;
} maillon ;

typedef maillon *list ;

int demandeN () {

	int N ;
	do {
	if (scanf("%d", &N) != 1) {
		printf("\nErreur d'entree\n") ;
		exit (-1) ;
	} 
		} while (N < 2 ) ;
	return N ;
}

list create(list liste, int N) {
maillon *cour= liste ;
	
	cour = malloc (sizeof(list)) ;
	cour -> info = var ;
	cour-> succ = NULL ;
	cour = cour -> succ 
	}
return cour ;
}

void afficher (list liste,int N) {
 
maillon *cour= liste ;
	while (cour != NULL) {
	
	printf("%d ", cour->info) ;
	cour = cour ->succ ;
	}
}










int main () {

int N ;
int var ;
list liste=NULL ;
N = demandeN() ;
maillon *cour= liste ;
  for(var =2, var<N, var++) {
            cour = malloc (sizeof(list)) ;
             cour -> info = var ;
              cour-> succ = NULL ;
               cour = cour -> succ
                }
afficher (liste, N) ;
return 0 ;
		}

