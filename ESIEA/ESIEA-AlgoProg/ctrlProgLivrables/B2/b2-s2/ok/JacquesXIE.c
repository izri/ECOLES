#include <stdio.h>
#include <stdlib.h>

typedef struct Liste
{
	int info;
	struct Liste *next;

}Liste;

struct Liste *element; 


void circulaire(Liste *Element)
{
	//Liste *Element = NULL;

	if(Element == NULL)
	{
		exit(-1);
	}
	else{
		while(Element != NULL)
		{
			//boite suivante
			Element = Element->next;

		}
		
	}

}

void afficherListe(Liste *element)
{
	if(element == NULL)
	{
		exit(-1);
	}

	Liste *cour = element;

	while(cour != NULL)
	{
		printf("%d ->", cour->info);
		cour = cour->next;

	}
	printf("NULL\n");
}


int main(int argc, char const *argv[])
{
	/*for(i=0; i<20; i++)
	{

	}*/
	Liste *maliste = NULL;

	circulaire(maliste);
	afficherListe(maliste);


	return 0;
}