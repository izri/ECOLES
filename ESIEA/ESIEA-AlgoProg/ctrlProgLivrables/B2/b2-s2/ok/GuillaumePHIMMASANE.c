#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
	int valeur;
	struct elem *succ;
}elem;

typedef struct elem *liste;

int giveNum() {
	int var;
	do{
	if(scanf("%d", &var) !=1) {
		exit(-1);
	}
	}while ( var <1);
	return var;
}

liste ajouterTete(liste l, int val) {
	elem *new = malloc(sizeof(elem));
	new ->valeur = val;
	new ->succ = l;
return l;
}

liste createListe(liste l, int val) {
	int count;

	for ( count = val + 1; count < val; count++) {
		l = ajouterTete(l,count);
	}
	return l;
}

liste finListe(liste l, int val) {
	liste q;
	q = ajouterTete(l,val);

	return q;
}

void afficher(liste l) {
	struct elem *tmp = l;

	do {
	printf("%d ", tmp -> valeur);
		tmp = tmp->succ;
	}while ( tmp != l);
}

int giveNum2() {
	int var;
	do{
	if(scanf("%d", &var) !=1) {
		exit(-1);
	}
	}while ( var >0);
	return var;
}

int nombreParfait ( int num , int val) {
	int count;
	int i;
	int val;

	for(count = 1; count < val; count ++) {
		if(num % count == 0) {
			i = count;
		return i;
		}
	}
return 0;
}

void afficherNbParfait ( liste l, int val) {
	elem *tmp = l;
	int count;
	int somme;

	while ( tmp->succ != l) {
		for ( count = 1; count < val; count++) {
			if ( nombreParfait(l, count) != 0) {
				somme = somme + count;
					if ( somme == val ) {
					printf("%d ", tmp -> valeur);
					}
				}
			tmp = tmp->succ;
		}
	}
}

int main () {
	int val;

	elem *maliste = NULL;
	val = giveNum();
	liste queue = finListe(maliste,val);
	maliste = createListe(queue, val);
	afficher(maliste);

	afficherNbParfait(maliste, val);
	return 0;
}
