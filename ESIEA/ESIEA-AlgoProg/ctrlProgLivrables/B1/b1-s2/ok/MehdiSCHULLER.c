#include<stdio.h>
#include<stdlib.h>

typedef struct Maillon{

	int id;
	struct *Maillon next;
}
Maillon;

typedef struct Maillon *list;

List creatlist (list(int blabla)){
	int trololo;
	list res = creatCell(1);
	maillon *temp = sol;

	for(trololo=1 ; trololo<blabla ; trololo++){
		temp->next = createCell(trololo);
		temp = temp->next;
	}
	temp -> next=sol;
	return sol;
}

List creatCell(int trololo){
	list Cell = (list)maillon(sizeof(struct maillon));
	Cell->id = trololo;
	Cell->next = NULL;
	return cell;
}

void print(list l){

	maillon *temp;
	if(l==NULL){

		printf("Liste vide\n");
		else{
			temp=l;
			while(temp->next!=NULL){
				printf("%d",(temp->id));
			}
			printf("\n");
		}
	}
}

int main() {

	list l=creatlist(30);
	print(30);


	return 0;

}
