#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
struct element{
int info;
struct element *succ;
};

typedef element* liste;


liste createCell(){
element* newElement=malloc(sizeof(element));
scanf("%d ", &newElement->info);
newElement->succ=NULL;
return newElement;
}

liste firstCell(liste *l){
liste p;
p=createCell();
*l=p;
return p;
}

//liste createList(liste *l, int valeur){




void afficherListe(liste l){
element* tmp=l;
element* h=l;
while(tmp->succ!=h){
printf("%d ", tmp->info);
tmp=tmp->succ;
}
}

liste cube(liste l){
element* tmp=l;
element* h=l;
while(tmp->succ!=h){
tmp->info=(tmp->info)^3;
tmp=tmp->succ;
}
return l;
}









int main(){
//liste maListe = NULL;
return 0;
}



