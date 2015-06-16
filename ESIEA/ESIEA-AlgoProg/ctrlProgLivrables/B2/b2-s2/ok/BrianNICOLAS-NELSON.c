#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    int info;
    struct maillon * succ;
} t_maillon;


t_maillon * allocation()
{
    t_maillon * maillon;    
    maillon = malloc(sizeof(t_maillon));
    maillon->succ=NULL;
    return maillon;
}

void remplir(t_maillon * maillon)
{
    printf("Entrez une valeur pour le maillon :\n");
    scanf("%d", &maillon->info);
}


void ajout(t_maillon * maillon, t_maillon ** liste)
{
    t_maillon * queue=*liste;
    if(*liste==NULL)
        *liste=maillon;
    else
    {
        while(queue->succ!=NULL)
        {
            queue=queue->succ;
        }
        queue->succ=maillon;
    }
}

void affichage(t_maillon * liste,int n)
{
    printf("\nLes elements de la liste sont : \n");
    int i;
    for(i=0;i<n;i++)
	{
        printf("%d\n", liste->info);
        liste=liste->succ;
	}

}

void creer(t_maillon ** liste, int n)
{
	t_maillon * maillon;
	int i;
	for(i=0;i<n;i++)
	{
		t_maillon * liste=NULL;
	        maillon=allocation();
	        remplir(maillon);
		ajout(maillon, &liste);
	}
}

int parfait(int n)
{
	int j;
	int i;
	int compteur=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i%j==0);	// Signifie si j est diviseur de i
				compteur=compteur+j;				
		}
		//if(i==j) si nbre parfait
		//{ }
			
	}
	return 0;
}
    
int main()
{
	int n;
	printf("Entrez la taille souhaite :\n");
	scanf("%d",&n);
	t_maillon * liste=NULL;
	creer(&liste,n);
	affichage(liste,n);
	
	return 0;
}













