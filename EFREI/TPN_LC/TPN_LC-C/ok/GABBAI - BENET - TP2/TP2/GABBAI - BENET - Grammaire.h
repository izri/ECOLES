#ifndef GRAMMAIRE_H_INCLUDED
#define GRAMMAIRE_H_INCLUDED

#include <vector>
#include "GABBAI - BENET - Regle.h"
#include "GABBAI - BENET - Ensemble.h"

using namespace std;

class Grammaire
{
private:
    vector<Regle> _listeRegles;
    vector<unsigned int> _successeurs;
public:
    Grammaire() {}
    Grammaire(const Grammaire& g) : _listeRegles(g._listeRegles) {}
    ~Grammaire() {}

    vector<Regle> getRegles() { return _listeRegles; }
    vector<unsigned int> getSucc() { return _successeurs; }

    void ajouter(char, string);
    void modifierRegles();
    void afficher();
    vector<Grammaire> calculItems(vector<Grammaire> listeItems, vector<Regle>);
    vector<Ensemble> calculPremiers();
    vector<Ensemble> calculSuivants(vector<Ensemble>);

    friend ostream & operator<< (ostream & os, Grammaire & g)
	{
	    vector<Regle> listeRegles = g.getRegles();
	    for(vector<Regle>::iterator it = listeRegles.begin(); it != listeRegles.end(); ++it)
        {
            os << *it << endl;
        }
	    return os;
	}
};

Grammaire lireFichier();
bool dejaPresent(vector<char>, char);
bool dejaPresent(vector<Ensemble>, char);

#endif // GRAMMAIRE_H_INCLUDED
