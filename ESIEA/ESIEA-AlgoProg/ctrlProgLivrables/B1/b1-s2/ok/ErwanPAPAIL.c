#include <stdlib.h>
#include <stdlib.h>

typedef struct maillon maillon;
struct maillon {
	int valeur;
	struct maillon* succ;
	}
typedef maillon* liste;

void creerliste(int N) {
//Tête de liste
	if(N>=1)
	{
	liste l;
	liste p;
	p=l;	
	

//Corps de la liste
	int i=1;
	while(i<=N) 
		{
		p=malloc(sizeof(maillon));
		p->valeur=i;
		p->succ=l;
		i++;
			
		}

	}
}

void afficher(liste l) {
while(l!=NULL) 
	{
	printf("%d\n", l->valeur);
	l=l->succ;
	}
}

void calculcube(liste l) {
while(l!=NULL)
	{
	int x;
	x=l->valeur*l->valeur*l->valeur
	l->valeur=x;
	printf("%d\n",&x);
	l=l->succ;
	}
}





int main() {



return 0;
}
