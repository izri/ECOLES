#ifndef DEF_COMMANDE
#define DEF_COMMANDE
#include <string>
#include "Client.h"
#include "Product.h"
#include <iostream>

class Commande
{
public:
Commande();


void progcommande();
unsigned int setcommande();
unsigned int NumCommande;
unsigned int prixtotal;

};


#endif // COMMANDE_INCLUDED
