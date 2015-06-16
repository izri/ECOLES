#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
	int nombre;
	struct maillon *succ;
}maillon;
typedef struct maillon *LSCcirc;

LSCcirc creer_element()
{
	int premier;
	premier=2;
	LSCcirc element;
	element=(LSCcirc)malloc(sizeof(struct maillon));
	printf("Entrer un entier supérieur à 2:\n");
	scanf("%d",&element->nombre);
	element->next=premier;
	return element;
}

void creer_liste(int N)
{
	int i;
	LSCcirc element,ptr;
	for(i=1;i<N;i++)
	{
		ptr=creer_element;
		element->next=ptr;
		element=ptr;
	}
}

void afficher(LSCcirc liste)
	LSCcirc element=liste;
	if(element==NULL)printf("Liste Vide\n");
	while(element!=NULL)
	{
		printf("Le contenu de la liste est: %d\n",element->nombre);
	}
}

LSCcirc calcul(LSCcirc liste,int element)
{
	int i;
	while(liste!=NULL)
	{
		for(i=2,i<N,i++){
			element=(i)^3;
		}


