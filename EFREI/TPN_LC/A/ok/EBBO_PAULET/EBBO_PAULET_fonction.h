#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <vector>
#include <string>

using namespace std;


struct etat
{
public : 
	vector <vector <string> > suivant;
	vector <vector < string> >gramm; // la grammaire de l'etat
	bool finie;
};

//////////////////////////////////////////////////////////////////////////////////////////

class grammaire
{
private :
	vector < vector < string > > magrammaire;


public :
	grammaire();
	bool need_factorisation();
	void show();
	char getExpression_char(int X, int Y);
	int getSize_int(int X);
	int getSize_int();
    vector <char> premier(char expression, grammaire &magrammaire);
	string getExpression_string (int X, int Y);

	vector <etat> creation_automate();

};

string avance_point(string monslip);

#endif // FONCTIONS_H_INCLUDED
