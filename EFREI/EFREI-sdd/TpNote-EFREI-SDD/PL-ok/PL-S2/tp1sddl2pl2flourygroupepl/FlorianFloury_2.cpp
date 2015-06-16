#include <iostream>
#include "FlorianFloury.h"


using namespace std;


int main()
{
    int n;
    element lst;
    printf ("Saisir nombre d'element \n");
    scanf ("%d", &n);
    construireListe (&lst, n);
    Afficher(lst);
    return 0;
}
