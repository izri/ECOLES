#include <string>
#include <vector>

#ifndef GRAMMAIRE_H_INCLUDED
#define GRAMMAIRE_H_INCLUDED

class Grammaire
{
    private:
    std::string nom;
    std::vector<std::string> production;
    std::vector<std::string> alpha;
    std::vector<std::string> beta;

    public:

    Grammaire();
    virtual ~Grammaire();

    std::string getNom();
    void setNom(std::string c);
    std::vector<std::string> getAllProduction();
    std::string getProduction(int i);

    void setProduction(std::string a, int i);

    void addProduction(std::string a);
    void SupprProduction();

    int tailleProduction();

    int tailleAlpha();
    int tailleBeta();

    void addAlpha(std::string a);
    void addBeta(std::string a);

    std::string getAlpha(int a);
    std::string getBeta(int a);
};


#endif // GRAMMAIRE_H_INCLUDED
