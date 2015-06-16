#include <stdlib.h>
#include <stdio.h>


//definition des structures
typedef struct element {

    int var;


    struct element *succ;

} element;

typedef element *lista;



// creation de la liste

void createliste(lista *pl) {


    int vari;

    int ini;

    lista li=*pl=malloc(sizeof(element)) ;

    lista end = malloc(sizeof(element)) ;


    printf ("entrer le nombre de maillon : ");

    if (scanf("%d", &vari)! = 1 ) {

        exit(-1) ;


    }



    for (ini=1; ini <= vari; ini++) {


        end -> succ = malloc(sizeof(element));


        end -> var = ini;

        end = end -> succ ;

        end->succ = li ; // liste circulaire


    }

}


void print(lista li) {

    while (li!=NULL) {

        printf ("%d\n", li->var) ;

        li = li->succ ;

    }
}




// parcourir 

void parcour(lista *pl) {
    lista li =*pl;

    lista save =*pl=malloc(sizeof(element));

    while (li!=NULL) {

        if ((li->var)==0) { // var au cube

            save -> succ = malloc(sizeof(element));

            save -> var= li-> var;

            save = save -> succ ;

            save -> succ = save ;

        }

        li=li -> succ ;

    }
}

void print2(lista li) {

    while (li!=NULL) {

        printf ("%d\n",li->var);

        li=li->succ;

    }
}


int main () {

    lista t=malloc(sizeof(element)) ;

    createliste(&t) ;

    print(t);

    parcour(&t);

    print2(t);

    return 0;
}




