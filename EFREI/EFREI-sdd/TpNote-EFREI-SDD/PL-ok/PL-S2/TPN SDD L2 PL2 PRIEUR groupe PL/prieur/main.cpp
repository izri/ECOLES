
#include "liste.h"

using namespace std;

int main()
{
    fifo liste;
    int val_max=0;
    int i=2;

    init_liste(&liste); // initialisation liste

    while (val_max<2)
    {
    printf ("Saisir la valeur max de la liste (sup ou egale a 2): "); // saisie N
    scanf("%d", &val_max);
    };

    for(i; i<=val_max; i++) //remplissage de la liste de 2 à N
    {
        if(push_liste(i, &liste)==0)
        {
            printf("ERROR");
        }
    }

    print_liste(&liste);


system("PAUSE");
return 0;
}



