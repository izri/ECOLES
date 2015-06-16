#include<stdlib.h>


typedef struct maillon{
	int nombre;
	struct * maillon next;
}maillon;

typedef struct *maillon=LSCmaillon;

LSCmaillon createcell(int N )
 {     LSCmaillon cell;
	cell=(LSCmaillon)malloc(sizeof(maillon));
	//printf("entrer l' entier");
	//scanf("%d",&cell->nombre);
	cell->nombre=N;
	cell->next=NULL;
	return cell;

}
void createlist(int i, int N,LSCmaillon head)
{
	LSCmaillon cour;
	if(i<N)
	{
		cour=createcell(i);
		head->next=cour;
		createlist(i+1, N,cour)
	}
	if(i==N)
	{
		cour=createcell(i);
		cour->next=head;

	}


}


void showlist(LSCmaillon head,N)
{
	LSCmaillon cour;
	cour=head;
	for(i=2;i<N+1;i++)
	{
		printf("le nombre contenue dans le maillon %d est %d",i,cour->nombre);
		cour=cour->next;
	}


}
/*void nombreparfait(LSCmaillon head

*/
int main()
{
	int N;
	LSCmaillon head;
	printf("entrer le nombre N de maillon de la chaine\n");
	scanf("%d",&N);
	head=createcell(2);
	createlist(3,N,head);
	showlist(head,N);


	return 0;
}



