#ifndef TRANSITION_H
#define TRANSITION_H
#include "etat.h"
#include <string>
#include<vector>
#include "regle.h"
#include "grammaire.h"

using namespace std;

class transition
{
    public:
        transition();
        transition(int o, string s, int d);

        int origine;
        string symbole;
        int destination;
};

#endif // TRANSITION_H
