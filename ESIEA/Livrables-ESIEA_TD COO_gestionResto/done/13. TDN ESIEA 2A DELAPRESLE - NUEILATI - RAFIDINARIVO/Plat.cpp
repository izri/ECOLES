#include "Plat.h"
using namespace std;
Plat::Plat (string m_nom, int m_prix): nom(m_nom), prix(m_prix) {
}

int Plat::getPrice (){
    return prix;
}

