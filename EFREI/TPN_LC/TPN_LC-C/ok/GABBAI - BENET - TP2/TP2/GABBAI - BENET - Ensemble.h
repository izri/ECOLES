#ifndef ENSEMBLE_H_INCLUDED
#define ENSEMBLE_H_INCLUDED

using namespace std;

class Ensemble
{
private:
    char _nonTerminal;
    vector<char> _elements;
public:
    Ensemble() {}
    ~Ensemble() {}

    char getNT() { return _nonTerminal; }
    void setNT(char x) { _nonTerminal = x; }
    vector<char> getElements() { return _elements; }
    void setElements(vector<char> tab) { _elements = tab; }

    friend ostream & operator<< (ostream & os, Ensemble & e)
	{
	    vector<char> listeElements = e.getElements();
	    os << e.getNT() << " :" << endl;
	    for(vector<char>::iterator it = listeElements.begin(); it != listeElements.end(); ++it)
        {
            if(*it == ' ') os << "epsilon" << endl;
            else os << *it << endl;
        }
	    return os;
	}
};

#endif // ENSEMBLE_H_INCLUDED
