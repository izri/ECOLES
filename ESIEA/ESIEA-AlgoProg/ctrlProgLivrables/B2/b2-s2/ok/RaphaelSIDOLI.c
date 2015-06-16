#include<stdlib.h>
#include<stdio.h>

typedef struct llist
{
	int info;
	struct llist *next;
}llist;

void affiche(llist liste,int N)
{
	int i;
	llist tmp=liste;
	for(i=1;i<N;i++)
	{
		printf("%d",i);
		tmp->info=tmp -> next;
	}
}

llist fulfill(llist liste, int N)
{
	
	int i=0;
	for(i=1;i<N;i++)
	{
		llist info=malloc(sizeof(N));
		while(liste->next != NULL)
		{	
			liste->info=i;
			
		}
		liste=liste->next;	
	}
	return *liste;
}

int parfait(llist liste, int N)
{

}

int main()
{
	llist liste=NULL;
	int N=0;
	do
	{
		if(scanf("%d",&N)!=1)
		{
			exit (-1);
		}
	}
	while(N<1);	
	fulfill(liste,N);
	affiche(liste,N);

	return 0;
}

