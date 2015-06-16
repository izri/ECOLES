#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
	int a;
	struct element *nxt, *preced;
	
}element;


int cuBe(int nombre);

int main()
{
	{
	int saisie = 0, i, saisie2=0;


	printf("Veuillez saisir un N  element : ");
	scanf("%d", &saisie);



	for (i=0; i<saisie; ++i)
	{
		int saisie2=0;
		printf("%d.Saisir un nombre :  ", i+1);
		scanf("%d", &saisie2);
	}

	saisie = cuBe(saisie);
	if (saisie<180)
	{
		printf("VOtre cube est inferieur a 180");
	}
	else
	{
		printf("VOtre Cube est superieur a 180");
	}

	}

	return 0;
}


int cuBe(int nombre)
{
	int resultat=0;
	resultat=nombre*nombre*nombre;
	printf("VOtre resultat au cube est %d", resultat);
	return resultat;
}

