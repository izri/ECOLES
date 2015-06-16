#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{

	int info;
	struct maillon *next;

}maillon;

maillon* create_lsc(int n){

int i = 0;

struct maillon *l=NULL, *tmp1=NULL,*tmp2=NULL;

if(n<0){

printf("Valeur invalide\n");

exit(-1);

}

if(n>0){

l=malloc(sizeof(maillon));
l->info = n;
l->next = NULL;

tmp2=l;

for(i=1;i<n;i++){

tmp1=malloc(sizeof(maillon));
tmp1->next=tmp2;
tmp1->info=n-i;
tmp2=tmp1;

}

l->next=tmp1;

}

return tmp1;

}

void afficher_lsc(maillon* l){

maillon* tmp=l;

if(l==NULL){

printf("LISTE VIDE!!!\n");

exit(-1);

}

do{

printf("%d\n",tmp->info);
tmp=tmp->next;

}while(tmp!=l);

}

int parfait(int n){

int som=0;

for(i=1,i<n,i++){

if(n%i==0){

som+=i;

}

}

if(som==n){

return 1;

}

return 0;

}







int main(){

int n;
maillon *l, *m;

if(scanf("%d",&n)!=1){

return -1;

}

l=create_lsc(n);

afficher_lsc(l);

m=create_lscp(n);

afficher_lsc(m);

return 0;

}
