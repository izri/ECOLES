#include <stdlib.h>
#include <stdio.h>

typedef struct element element; //On définit la structure de la liste chainée
struct element
{
	int info;
	struct element *next;
};

typedef element* llist;

llist AddInHead(llist list, int valeur) //Fonction pour ajouter en tete
{
	llist nouvelElement = malloc(sizeof(element));
	nouvelElement->info = valeur;
	nouvelElement->next = list;
	return nouvelElement;
}

llist BuildList(llist list, int size) //Fonction qui permet d'obtenir la liste
{
	int i;
	size--;
	for(i=size;i>=2;i--)
	{
	list=AddInHead(list,i);
	}
	return list;
}

llist BuildQueue(llist list, int size) //Fonction qui permet d'obtenir la queue de liste
{
	llist queue;
	queue=AddInHead(list,size);
	return queue;
}

int AskForNumber() //Fonction qui permet de demander 'N' a l'utilisateur
{
	printf("Entrer un nombre :\n");
	int size;
	do
	{
		if(scanf("%d", &size)!=1)
		{
		exit(-1);
		}
	}while(size<2);
	return size;
}

void ShowList(llist list, int size) //Fonction qui permet d'afficher la liste chainée
{
	int i=0;
	printf("On affiche la liste de 2 a %d:\n", size);
	element *tmp;
	tmp=list;
	while(i<size-1)
	{
	printf("%d ",tmp->info);
	tmp=tmp->next;
	i++;
	}
	printf("\n");
}

int PerfectNumbers(llist list, int isitperfect) //Fonction qui permet de tester si un nombre est parfait ou non
{
	int i;
	int sommeDiv=0;
	for(i=1;i<isitperfect;i++)
	{
		if((isitperfect%i)==0)
		{
		sommeDiv=sommeDiv+i;
		}
	}
	if(isitperfect==sommeDiv)
	{
	return sommeDiv;
	}
	else
	{
	return 0;
	}
}

void ShowPerfectNumbers(llist list, int size) //Fonction qui permet d'afficher les nombres parfaits de la liste
{
	printf("\nOn affiche les nombres parfaits inferieurs ou egaux a 800 :\n");
	int i;
	int perfectNumber;
	for(i=2;i<=size;i++)
	{
		if((perfectNumber=PerfectNumbers(list,i))!=0)
		{
		printf("%d ", perfectNumber);
		}
	}
	printf("\n\n");
}

int main()
{
	int size;
	llist queue;
	llist list=NULL; //On initialise la liste
	size=AskForNumber();
	queue=BuildQueue(list,size); //On initialise la queue de la liste
	list=BuildList(queue,size); //On remplit la liste de 2 à N
	ShowList(list, size);
	queue->next=list;
	ShowPerfectNumbers(list, 800);
	return 0;
}
