#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct maillon{
    int info;
    struct maillon *succ;
}maillon;

typedef maillon *LSC;

void create(LSC *l){
	int n,x=1;
	printf("Veuillez inserer n:\n");
	scanf("%d",&n);

	LSC cour=NULL;

	cour=malloc(sizeof(maillon));
	cour->info=x;
	cour->succ=NULL;
	(*l)=cour;


	for(x=2;x<=n;x++)
	{
		cour->succ=malloc(sizeof(maillon));
		cour=cour->succ;
		cour->info=x;
		cour->succ=NULL;

	}
cour->succ=*l;


}

void display(LSC l)
{
	LSC first=l;
	printf("%d  ",l->info);
	l=l->succ; 

	while(l!=first){
		printf("%d  ",l->info);
		l=l->succ;
	}
}
void delete(LSC *l){
	
	LSC cour=NULL,prec=NULL;
	int perfect=0,i;
		if(l!=NULL)
		{
			for(i=((*l)->info)-1;i>0;i--){
				if(((*l)->info)%i==0) perfect+=i;
			}
			
			if(perfect!=i)
			{
				cour=(*l);
				*l=(*l)->succ;
				free(cour);
			}
		
			
			prec=*l;
			cour=(*l)->succ;
			perfect=0;
			
	
			while(cour!=*l){
				for(i=(cour->info)-1;i>0;i--){
					if(cour->info%i==0) perfect+=i;
				}

				if(perfect!=i)
				{
					prec->succ=cour->succ;
					free(cour);
					cour=prec->succ;
				}
				cour=cour->succ;
			}
		}

}


int main ( ){
	LSC l=NULL;
	create(&l);
	display(l);
printf("\nsuppresion:\n");
	delete(&l);
	display(l);
printf("\n");
	return 0;
}
