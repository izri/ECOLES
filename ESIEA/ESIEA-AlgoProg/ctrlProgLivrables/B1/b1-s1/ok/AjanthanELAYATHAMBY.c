#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*On cree un element */
typedef struct Element Element;
struct Element { int nombre; Element *suivant;
};

/*On cree la structure de controle et on lui indique le premier element de notre liste chainee*/
typedef struct Liste Liste;
struct Liste {
Element *premier;
};

/*On initialise la liste pour lui indiquer que les entiers varient de 2 a N */
Liste *initialisation() {

Liste *liste = malloc(sizeof(*liste));
Element *element = malloc(sizeof(*element));

if(liste == NULL || element == NULL) {
exit(EXIT_FAILURE);
}

element -> nombre = 2;
liste -> premier = element;


return liste;
}

/*On cree une fonction pour afficher notre liste et on verifie qu'il n'y a pas d'erreur*/
void afficherListe(Liste *liste) {

if(liste == NULL) {
exit(EXIT_FAILURE);
}

Element *present = liste;

while(present != NULL) {
printf("%d -> ", present->nombre);
present = present->suivant;
}
printf("NULL\n");
}

/*Cette fonction calcule le cube de chaque nombre et parcoure la liste */
void cubeNombre(Liste *liste, int element) {

/*On verifie qu'il n'ya pas d'erreur*/
if(liste == NULL) {
exit(EXIT_FAILURE);
}
}

int main () {

Liste *maListe = initialisation ();

afficherListe(maListe);
return 0;
}

