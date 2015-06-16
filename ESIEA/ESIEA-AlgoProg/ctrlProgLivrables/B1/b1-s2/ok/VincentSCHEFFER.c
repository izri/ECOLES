#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
	int info;
	struct maillon* suivant;
}maillon;

typedef maillon* liste;

liste creerMaillon()
{

	liste maillon = (liste)malloc(sizeof (liste));
	maillon->suivant= NULL;

	return maillon;

}

liste creerListe ( liste l, int n)
{
	int i =1;
	while ( i != n )
	{

		l = creerMaillon();
		l = l->suivant;
		l->info = i;
		i++;
	}
}
void afficherListe ( liste l, int n )
{
	int i;
	liste p =NULL;
	if ( l == NULL)
		return 0;
	while ( l != p )
	{
		printf("%d \t", l->info);
		l= l->suivant;
	}

}

int main()
{
	liste l;
	int n;
	printf(" quelle valeur de n ?" );
	scanf("%d", &n);
	l =creerListe ( l, n );
	afficherListe(l, n);
	return 0;
}
