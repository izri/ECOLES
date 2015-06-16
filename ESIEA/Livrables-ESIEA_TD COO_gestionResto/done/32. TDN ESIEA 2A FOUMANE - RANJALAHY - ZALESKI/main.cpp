#include <iostream>
#include "resto..h"

using namespace std;
using namespace std;

int main()
{
    cout << "Bonjour cher client ";
    Produit prod1("Pizza");
    Client Client1;
    Client Client2("Jean");
    Client1.Commander(prod1);
    Client1.Payer();

    Produit prod2("Boisson");
    Client2.Commander(prod2);
    Client2.Payer();


    return 0;
}
