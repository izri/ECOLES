#include <stdio.h>
#include <stdlib.h>

typedef struct list
{

	int data;
	struct list* next;

}list;

typedef list* LSClist;

int saisie()
{
	int data;
	printf("entrez le nombre de maillons\n");

	do
	{
		if(scanf("%d", &data)!= 1)
		{
			printf("la valeur entree n'est pas valide");
			exit(-1);
		}
	}while(data<1);
	return data;
}

LSClist first(int data)
{
	LSClist head = malloc(sizeof(list));
	head -> data = data;
	head -> next = NULL;
	return head;
}

LSClist create(int lenght)
{
	LSClist before;
	LSClist head;
	int i;

	before = first(2);
	head = before;

	for(i=1; i<lenght; i++)
	{
		LSClist maillon = malloc(sizeof(list));

		maillon-> data = i+2;
		maillon -> next = head;

		before->next = maillon;
		before = before -> next;

	}

	return head;

}

void print(LSClist head)
{

	LSClist maillon = head;
	do
	{
		printf("%d ", maillon-> data);

		if(maillon->next != head)
		{
			printf("-> ");
		}

		maillon = maillon -> next;

	}while(maillon!=head);
	printf("\n");

}

int isPerfect(int value)
{
	int i;
	int sum = 1;

	for(i=2; i<value; i++)
	{
		if(value%i == 0)
		{
			sum += i;
		}

	}
	
	if(sum==value)
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

LSClist deleteUnperfections(LSClist head)
{
	LSClist prec = head;
	LSClist tmp;
	LSClist cour = head -> next;
	LSClist begin = cour;

	do
	{
	if(isPerfect(cour-> data) == 0)
	{
		if(cour == begin)
		{
			begin = cour->next;
		}

		prec->next = cour -> next;
		tmp = cour-> next;
		free(cour);
		cour = tmp;
	}
	

	}while(cour -> next == begin);
	
	return begin;
}




int main()
{
	LSClist head;
	int lenght;

	lenght = saisie();

	head = create(lenght);
	print(head);
	deleteUnperfections(head);
	print(head);
	return 0;
}
