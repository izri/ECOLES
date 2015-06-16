#include <stdio.h>
#include <stdlib.h>


typedef struct maillon{

	int val;
	struct maillon* next;
}maillon;

typedef struct maillon* list;

void print(list l);
list createList(int n);
list createCell(int i);
list cube(list l);
int power(int n, int b);
void printUnder180(list l);

int main(){
	list l = createList(20);

	print(l);
	list l2 = cube(l);
	print(l2);
	return 0;

}

void print(list l){
	maillon* temp;
	if(l == NULL)
		printf("List empty\n");
	else{
		temp = l;
		while(temp->next != l){
			printf("%d ", temp->val);
			temp = temp->next;
		}
		printf("%d\n", temp->val);
	}
}


list createList(int n){
	int i;
	list res = createCell(1);
	maillon* temp = res;
	for(i = 2; i <= n ; i++){
		temp->next = createCell(i);
		temp = temp->next;
	}
	temp->next = res;
	return res;

}

list createCell(int i){
	list cell = (list)malloc(sizeof(struct maillon));
	cell->val = i;
	cell->next = NULL;

	return cell;
}

list cube(list l){
	list res = (list)malloc(sizeof(struct maillon));
	maillon* temp;
	maillon* temp2;
	temp = l->next;
	res->val = power(l->val,3);
	temp2 = res;
	while(temp->next != l){
		temp2->next = createCell(power(temp->val, 3));
		temp2 = temp2->next;
		temp = temp->next;
	}
	temp2->next = res;
	return res;
}

int power(int n, int b){
	int i = 0;
	int res = n;
	int resF = 1;
	for(i = 0; i<b ;i++){
		resF = resF * res;
	}
	return resF;
}

void printUnder180(list l){
	maillon* temp;
	if(l == NULL)
		printf("List empty\n");
	else{
		temp = l;
		while(temp->next != l){
			if(temp->val <= 180){
				printf("%d ", temp->val);
				temp = temp->next;
			}
		}
		if(temp->val <= 180)
			printf("%d\n", temp->val);
	}
}



