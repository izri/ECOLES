#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

#include <string>
#include <vector>
#include "Arc.h"

class Index
{
    private:
    int nom;
    std::vector<std::string> regles;
    std::vector<Arc> arc;

    public:

    Index();
    virtual ~Index();
    int getNom();
    void setNom(int n);

    void addRegles(std::string r);
    std::string getRegles(int i);

    int tailleRegles();

    void addArc(Arc a);
    Arc getArc(int i);
    int tailleArcs();
};

#endif // INDEX_H_INCLUDED
