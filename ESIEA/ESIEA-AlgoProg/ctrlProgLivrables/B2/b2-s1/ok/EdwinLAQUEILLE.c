#include <stdio.h>
#include <stdlib.h>

typedef struct elem elem;
struct elem{
	int info;
	struct* elem suivant;
};

typedef elem* list;


int donnemoiunchiffre(){

	int val;

do{
	if(scanf("%d", &val)!=1){
		exit(-1);
	}
}while(val>=2);

return val;

}


list addtete(list maliste, int valeur){
	elem* new = malloc(sizeof(elem));
	new -> info = valeur;
	new -> suivant = maliste;
return new;
}


list queuedeliste(list maliste){
	elem* q;
	
	q = addtete(maliste,valeur);

return q;
}


list creationdeliste(list maliste, int chiffre){
	for(int var = chiffre-1; var >= 2; var--){
			maliste = addtete(maliste, var);
	}
return maliste;
}


void afficherlaliste(list maliste){
	elem* tmp = maliste;
	while(tmp!=0){
	printf("%d ", tmp -> info);
	}
tmp= tmp -> suivant;
}



int nombreparfait(){
	elem* tmp = maliste;
	
}



int main(){
list maliste = NULL;
chiffre=donnemoiunchiffre();
queueliste = queuedeliste(maliste);
list creationdeliste(maliste,chiffre)
queueliste -> suivant = maliste;
afficherlaliste(maliste)
return 0;
}

