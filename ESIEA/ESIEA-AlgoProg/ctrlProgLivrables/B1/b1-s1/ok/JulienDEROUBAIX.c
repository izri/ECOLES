#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
	int element;
	struct liste * next;
}liste

typedef struct liste *LDSchaine;



LDSchaine listeCircu(LDSchaine l, int N) {
	int i;
	int lTemp;
	for(i = 0; i < N; i++) {
		int boite;
		boite = malloc(sizeof(struct l));
		l -> element = 2 + i;
		if(i == 0) {
			lTemp = l;
		}
		if(i == N - 1) {
			l -> next = lTemp;
		}
	}
}


LDSchaine parcoursIte(LDSchaine l, int N, int tab[]) {
	int i;
	int lTemp;
	int number;
	if(l == NULL) {
		return 0;
	}
	for(i = 0; i < N; i++) {
		if(i == 0) {
			lTemp = l;
		}
		number = l -> element;
		number = number*number*number;
		tab[i] = number;
		l = l -> next;
	}
	return tab;
}



int main() {
	int i;
	LDSchaine l;
	int N;
	if(scanf("%D", &N) != 1) {
		printf("error number\n");
		exit(-1);
	}
	int tab[N];
	listeCircu(l, N);
	for(i = 0; i < N; i++) {
		printf("%D ", l -> element);
		l = l -> next;
	}
	tab[N] = parcoursIte(l, N, tab[]);
	for(i = 0; i < N; i++) {
		printf("%d\n", tab);
	}
	return 0;
}
