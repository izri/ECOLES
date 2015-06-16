#include <iostream>
#include "GABBAI - BENET - Regle.h"

using namespace std;

bool operator==(Regle const& a, Regle const& b)
{
    if(a.getDebut() == b.getDebut() && a.getResultat() == b.getResultat()) return true;
    return false;
}


