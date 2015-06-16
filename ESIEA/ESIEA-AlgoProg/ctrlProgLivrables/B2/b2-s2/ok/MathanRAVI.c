#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct maillon{
int nbr;

struct maillon *next;

}maillon;

typedef maillon *liste;

void afficher(liste l){
maillon *tmp=l;

if(tmp==NULL){

printf("la liste circulaire est vide\n");
exit(-1);
}else{

while(tmp->next!=l){
printf("%d ",tmp->nbr);
tmp=tmp->next;
}
printf("NULL\n");
}}

liste ajouter(int val,liste l){

maillon *nouveau=malloc(sizeof(*nouveau));
    nouveau->nbr=val;
    nouveau->next=NULL;
    if(l==NULL){
        return nouveau;
    }
    else{
        maillon *nouveau=l;
        while(nouveau->next!=NULL){
            nouveau=nouveau->next;
        }
        nouveau->next=nouveau;
        return l;
    }
}

int main(){

int i;
liste l=NULL;

int var;
scanf("%d ",&var);
for(i=0;i<3;i++){
l=(ajouter(i,l));
}
afficher(l);

return 0;

}
