#include <stdio.h>
#include <stdlib.h>
#include "liste.c"




/////////////////////////////////////////





int main()
{
    Liste *maListe = initialiser();

    printf("entrez un nombre :\n");
    int n = 0;
    int a = 0;

    scanf("%d", &n);
    int i = 0;

    printf("Voulez vous afficher uniquement les nombres parfait ? (1 = oui et 0 non)\n");
    scanf("%d", &a);

    for ( i = 2 ; i <= n ; i++) {

        insererElement(maListe, i, a);
    }

    afficherListe(maListe);


    return 0;
}
