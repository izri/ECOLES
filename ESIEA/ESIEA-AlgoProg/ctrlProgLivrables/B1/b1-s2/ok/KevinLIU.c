#include <stdlib.h>
#include <stdio.h>

typedef struct element element;
struct element 
{

	int val;
	struct element *next;

};

typedef element *list;


list LSCCirc(int N){

	element *liste = NULL;
	element *headlist = malloc(sizeof(element));
	int i=0;
	
	
	while( i< N ){
		headlist->val = 1;
		liste->val = i+1;
		liste = liste -> next;
		i++;
	}
	liste->next = headlist;
	
	return liste;

}

void Printlist(list l){

	element *temp = l;
	element *headlist = l;

	while(temp != headlist){

		printf("%d", temp->val);

		temp= temp->next;
	}

}

void Calcul(list l){

	element *temp = l;
	element *headlist = l;
	element *ptemp = malloc(sizeof(element));

	while(temp != headlist){

		ptemp->val = (temp->val)*(temp->val)*(temp->val);
		temp = temp->next;
		free(ptemp);

		}

}

int main(){

	element *list = NULL;
	list = LSCCirc(180);
	Calcul(list);
	Printlist(list);
	return 0;

}


