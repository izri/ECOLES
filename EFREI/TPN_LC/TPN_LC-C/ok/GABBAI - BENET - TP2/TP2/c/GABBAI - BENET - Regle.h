#ifndef REGLE_H_INCLUDED
#define REGLE_H_INCLUDED

using namespace std;

class Regle
{
private:
    char _debut;
    string _resultat;

public:
    Regle(char debut, string resultat) : _debut(debut), _resultat(resultat) {}
    ~Regle() {}

    char getDebut() const { return _debut; }
    void setDebut(char debut) { _debut = debut; }
    string getResultat() const { return _resultat; }
    void setResultat(string resultat) {_resultat = resultat; }

    friend ostream & operator<< (ostream & os, Regle & r)
	{
	    os << r.getDebut() << " -> " << r.getResultat();
	    return os;
	}
};

bool operator==(Regle const&, Regle const&);

#endif // REGLE_H_INCLUDED

