# include <stdio.h>
# include <stdlib.h>

typedef struct maillon
{
	int info;
	struct maillon *succ;
}maillon;
typedef maillon *liste;


void createLSC(liste l)
{
	int x=0;
	liste queue = NULL, new = NULL;
	printf("saisir valeur entiere avec -1 fin de saisie \n");
	scanf("%d", &x);

	if(x != -1)
	{
		l=malloc(sizeof(maillon));
		l->info=x;
		l->succ=NULL;
		queue=l;
		printf("saisir valeur entiere \n");
		scanf("%d", &x);
	}


	if(x != -1)
	{
		new=malloc(sizeof(maillon));
		new->info=x;
		new->succ=NULL;
		queue->succ=new;
		queue=new;
		printf("saisir valeur entiere");
		scanf("%d", &x);
	}
}


void affichage(liste l)
{
	while(l!= NULL)
	{
		printf("l->info = %d", l->info);
		l=l->succ;
	}
}


void parcourir(liste l, int j)
{
	int i=0;
	while(l!=NULL)
	{
		if (i!=j)
			{
			i++;
			}
	}
}


void affichageCube(liste l, int x)
{
	int y;
	for(x=0;x<180;x++)
		{
		printf("le cube du nombre est : %d \n", y);
		scanf("%d", &x);
		y = x*x*x;
		}
}


int main ()
{
	liste l;
	createLSC(l);
	affichage(l);
	parcourir(l, 5);
	affichageCube(l,2);
return 0;
}
