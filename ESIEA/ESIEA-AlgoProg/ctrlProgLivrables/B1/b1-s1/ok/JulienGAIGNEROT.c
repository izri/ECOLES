#include <stdio.h>
#include <stdlib.h>


typedef struct maillon{
int info;
struct maillon *next;
} maillon;
typedef struct maillon *LSCmaillon;

LSCmaillon new_singleton(int x)
{
	LSCmaillon s = malloc(sizeof(maillon));
	s->info=x;
	s->next=NULL;
	
	return s;
}

void create_list(LSCmaillon *l, int N) 
{
	LSCmaillon queue=NULL;
	LSCmaillon nouveau=NULL;
	*l=NULL;
	int x=2;
	if(N<2)
	{
		return;
	}
	else
	{
		while(x<=N)
		{
			*l = new_singleton(x);
			queue=*l;
			x=x+2;
			while(x<=N)
			{
				nouveau=new_singleton(x);
				queue->next=nouveau;
				queue=nouveau;
				x=x+2;
			}
			queue->next=*l;
		
		}
	}
}

void display_list(LSCmaillon *l)
{
	LSCmaillon deb=*l;
	LSCmaillon curr=*l;
	printf("Affichage de la liste \n");
	if(*l==NULL)
	{
		printf("La liste est vide ! \n");
	}
	else
	{
		printf("%d \n",curr->info);
		curr=curr->next;
		while(curr!=*l)
		{
			printf("%d \n",curr->info);
			curr=curr->next;
		}
	}
}

void cube_list(LSCmaillon *l)
{
	LSCmaillon deb=*l;
	LSCmaillon curr=*l;
	int a;
	if(*l==NULL)
	{
		return;
	}
	else
	{
		a=curr->info;
		curr->info=a*a*a;
		curr=curr->next;
		while(curr!=*l)
		{
			a=curr->info;
			curr->info=a*a*a;			
			curr=curr->next;
		}
	}
}



int main()
{
	LSCmaillon l1;
	int taille;
	printf("Entrer le nombre N que vous souhaitez utiliser pour concevoir une liste d'entiers de 2 à N \n");
	scanf("%d",&taille);
	create_list(&l1,taille);
	display_list(&l1);
	cube_list(&l1);
	display_list(&l1);
	
	
}

