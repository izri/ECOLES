#ifndef REGLE_H
#define REGLE_H
#include <vector>
#include <string>

using namespace std;

class regle
{
    public:
        string noTerm;
        vector<string> derivations;

        //Constructeurs
        regle(string nT, string deriv);
        regle(string nT, vector<string> deriv) : noTerm(nT), derivations(deriv) {};
        regle(string line);

        //Methodes
        void display();
    protected:
    private:

};

#endif // REGLE_H
