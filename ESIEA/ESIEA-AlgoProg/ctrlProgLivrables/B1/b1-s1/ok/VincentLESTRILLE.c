#include<stdio.h>
#include<stdlib.h>


typedef struct maillon{
	int info;
	struct maillon*succ;
}maillon;

typedef maillon*liste;


int Nbize(){         //Fonction nous permettant d'entrer la taille de notre liste
	int var;
	do{
		printf("Donnez moi une taille:\n");
		if(scanf("%d",&var)!=1) {
			exit(-1);
		}
	}while(var<2);
	return var;
}

liste CreerEnTete(liste l, int x){    //Fonction permettant de creer la tete de liste
	liste nouveau = malloc(sizeof(maillon));   //On reserve le maillon
	nouveau->info=x;			//On affecte le nouveau maillon a la valeur x
	nouveau->succ=l;			//On affecte le nouveau maillon a son successeur
	return nouveau;
}

liste CreerQueue(liste l,int x) {	//Fonction permettant de creer la queue de la liste
	liste queue;
	queue=CreerEnTete(l,x);
	return queue;
}

liste CreerListe(liste l,int size) {    //Fonction permettant de creer notre liste grace a la fonction CreeEnTete
	liste tmp=l;
	int count;
	for(count=size;count>=2;count--) {    //On reutilise la fonction jusqu'a arriver a la taille donnee en entree
		tmp=CreerEnTete(tmp,count);
	}
	return tmp;
}


liste Cube(liste l) {		//Fonction permettant de modifie notre liste afin d'avoir les cubes de chacunes des valeurs de notre liste
	liste tmp=l;
	int var;
	while(tmp!=NULL) {
		var=tmp->info;
		var=var*var*var;
		tmp->info=var;
		tmp=tmp->succ;
	}
	return l;
}

void AffichCube(liste l){		//Fonction permettant d'afficher notre liste avec les cubes de chacunes des valeurs
	liste tmp=l;
		printf("Voici la liste des cubes des valeurs inferieures ou egaux a 150\n");
	while(tmp!=NULL) {
		if(tmp->info<=150){
		printf("%d ",tmp->info);
		}
		tmp=tmp->succ;
	}
	printf("\n");
}

void Affich(liste l) {		//Fonction permettan d'afficher notre liste
	liste tmp=l;
		printf("Voici le contenu de la liste:\n");
	while(tmp!=NULL){
		printf("%d ",tmp->info);
		tmp=tmp->succ;
	}
	printf("\n");
}

int main() {
	liste l1=NULL;
	liste queue=NULL;
	int size=Nbize();
	queue = CreerQueue(l1,2);	//On cree notre queue de liste
	l1=CreerListe(l1,size);		//On cree notre liste
	queue->succ=l1;
	Affich(l1);
	l1=Cube(l1);
	AffichCube(l1);
	return 0;
}
