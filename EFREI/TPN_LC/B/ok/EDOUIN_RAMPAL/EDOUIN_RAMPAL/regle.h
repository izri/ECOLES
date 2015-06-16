#ifndef REGLE_H
#define REGLE_H
#include <vector>
#include <string>

using namespace std;

class regle
{
    public:
        regle(string nT, vector<string> deriv) : nonTerminal(nT), derivation(deriv) {};
        regle(string line);
        void affichage();
        string apresLePoint();
        bool pointFinal();
        int positionPoint();
        bool operator==(regle a);
        bool operator!=(regle a);

        string nonTerminal;
        vector<string> derivation;
};
#endif // REGLE_H
