#include <stdlib.h>
#include <stdio.h>

// Structure $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

typedef struct maillon *maillon;
struct maillon {
	int value;
	struct maillon *succ;
};
typedef maillon *liste;

// Prototypes $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

liste create_list(liste l, int n);
void display_list(liste l);
void cube(liste l);

// Main $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

int main() {

	liste list = NULL; // Ma liste
	int n; // Valeur de N

	printf("Entrez le nombre d'éléments: ");
	scanf("%d", &n);

	list = create_list(list,n);
	display_list(list);

	return 0;
}

// Fonctions $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

liste create_list(liste l, int n) {

	int x = 1; // Valeur d'un élément de la chaine
	int i; // Variable pour la boucle
	liste first; // Premier maillon de la liste circulaire

	first = l;

	for(i=0; i<n-1; i++) {

		l = malloc(sizeof(maillon));
		l->value = x;
		l = l->succ;
	
		x++;
	}

	l = malloc(sizeof(maillon));
	l->value = x;
	l->succ = first;
	
	return l;
}

void display_list(liste l) {

	liste first;
	first = l;

	printf("%d -> ", first->value);

	while(l != first) {
		
		printf(" %d -> ", l->value);
		l = l->succ;
	}
}

void cube(liste l) {

	liste first;
	first = l;

	first->value = first->value*first->value*first->value;

	while(l != first) {
		
		l->value = l->value*l->value*l->value;
		l = l->succ;
	}
}




































