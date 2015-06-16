#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{

int info;
struct maillon* next;

}maillon;
typedef maillon* liste;





liste create(liste l, int i){

liste k = l;

maillon* new = malloc(sizeof(maillon));
new -> info = i;
new -> next = NULL;

if(l == NULL){

return new;

}

else{

while(k->next != NULL){

k = k->next;

}

k->next = new;
return l;

}
return NULL;
}


liste last(liste l, int i){

liste k = l;

maillon* new = malloc(sizeof(maillon));
new -> info = i;
new -> next = l;

while (k->next != NULL){

k=k->next;
}

k->next = new;
return l;
}


void afficher(liste l, int i){

liste k = l;
int n = 1;
for(n = 1 ; n<= i; n++){

printf("%d ", k->info);
k=k->next;

}
}

liste parcours(liste l, int i){

liste k = l;
int n = 1;


for(n = 1 ; n<= i ; n++){

k -> info = k-> info * k->info * k -> info;

k = k-> next;

}
return l;
}



int main(){

int n;
int i = 1;

liste l = NULL;

scanf("%d", &n);

for(i = 1 ; i <= n-1 ; i++){
l = create(l, i);
}
l = last(l, n);
afficher(l,n);
l = parcours(l,n);
afficher(l,n);
return 0;
}
