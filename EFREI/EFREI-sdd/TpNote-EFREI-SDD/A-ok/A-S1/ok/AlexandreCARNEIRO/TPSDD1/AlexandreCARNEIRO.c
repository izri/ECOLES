#include "header.h"

int main()
{
    LSCc lst;
    int n = 150;
    n--; //sinon on va jusqu'a 151
    construireliste(&lst,n);
    afficher(lst);
    return 0;
}
