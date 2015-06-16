#include<stdio.h>
#include<stdlib.h>

typedef struct liste liste;
struct liste
{
	int val;
	struct liste *next;
}; 
typedef liste* element;



void afficherliste(element val){

	liste *tmp=val;
	
	while(tmp!=NULL){
		printf("%d",tmp->val);
			tmp=tmp->next;
			 }
}

int main () {

element liste1= NULL;
afficherliste(liste1);
return 0;
}
