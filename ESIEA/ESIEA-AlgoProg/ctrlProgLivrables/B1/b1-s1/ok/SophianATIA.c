#include<stdio.h>
#include<stdlib.h>

typedef struct Liste liste {
	struct element{
	int l;
}
} liste ;


int display_LSC (liste l ){
	while( l!=NULL){
		printf("%d",&l);
		l->next;
		return l;}
}

void parcours_cube(liste l){
	while(l!=NULL){
		l=l*l*l;
		l<-l->next;	
				

}		
int main (){

return 0;
}
