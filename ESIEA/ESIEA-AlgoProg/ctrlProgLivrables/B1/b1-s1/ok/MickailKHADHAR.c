#include <stdio.h>
#include <stdlib.h>


typedef struct Maillon{
int id;
struct Maillon*next;
}Maillon;
typedef Maillon*Liste;

void display(Liste LSC) {   // affiche le contenu



if(LSC==NULL) {
	printf("Liste vide\n");
	exit(-1);
}
else {
	Maillon*temp=LSC;
		while(temp!=NULL){
	printf("%d ->", temp->id);
	temp=temp->next;
}

	printf("NULL\n");
}
}

Liste insertion_TDL(Liste LSC, int valeur){
Maillon* new_maillon=malloc(sizeof(Maillon));
 new_maillon->id=valeur;
new_maillon->next=LSC;
	
	return new_maillon;

}

Liste insertion_QDL(Liste LSC, int valeur){
Maillon *new_maillon=malloc(sizeof(Maillon));
new_maillon->id=valeur;
new_maillon->next=NULL;
		if(LSC==NULL) {

return new_maillon;
	}
		else { Maillon*temp=LSC;

		while(temp->next != NULL ) {
	temp = temp->next;  }

temp->next=new_maillon;

return LSC;
	}
}




int main(){

int N;
scanf("%d",&N);


Liste ma_LSC=NULL;
int i=0;
for(i=2;i<=N;i++) {

	ma_LSC=(insertion_QDL(ma_LSC,i));
	} 

	display(ma_LSC);



return 0;
}
