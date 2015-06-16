#include <cassert>
#include <string>
#include <iostream>

using namespace std;

#include "Plat.h"


Plat::Plat (string _nom, double _prix) {
    nom = _nom;
    prix = _prix;

}

void   Plat::aff () {
    cout << "Plat : nom " << nom << " prix " << prix << endl;
}

double   Plat::getPrix () {
    return prix;
}
