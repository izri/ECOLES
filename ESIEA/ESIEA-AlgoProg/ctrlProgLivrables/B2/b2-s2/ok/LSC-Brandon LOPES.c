#include<stdio.h>
#include<stdlib.h>

typedef struct Maillon{

    int id;
    struct Maillon *next;

}Maillon;


typedef Maillon *Liste;


Liste insertion_QDL(Liste LSC,int valeur){

	Maillon *new_maillon=malloc(sizeof(*new_maillon));
	new_maillon->id=valeur;
	new_maillon->next=LSC;

	if(LSC==NULL){ //cas de la liste vide
        return new_maillon;
	}
	else{
        Maillon *temp=LSC;
        while(temp->next!=LSC){
            temp=temp->next;
        }
        temp->next=new_maillon;
        return LSC;
    }
}


void display(Liste LSC){ //Affiche la liste LSC

	Maillon *actuel=LSC;
	Maillon *cour=LSC;

	while(cour->next!=actuel){
		printf("%d -> ",cour->id);
		cour=cour->next;
	}
	
}


int main(){

Liste ma_LSC=NULL;
int i=1,n=0;

printf("entrer n: \n");
scanf("%d",&n);

for(i=1;i<=n;i++){
	ma_LSC=insertion_QDL(ma_LSC,i);

}
display(ma_LSC);
return 0;
}
