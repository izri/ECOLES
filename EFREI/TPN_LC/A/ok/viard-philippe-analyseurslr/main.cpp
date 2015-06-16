#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Regle
{
    private:
        string eNT;  // états non terminaux
        string transforme; // transformée

        bool used;
        bool axiome;

        int transform_util; // taille utile de transormée

    public :
        string getENT() { return this->eNT; }  //get & set des diverses variables
        void setENT(string x) { eNT = x; }

        bool getAxiome() { return this->axiome; }  //get & set des diverses variables
        void setAxiome(bool x) { axiome = x; }

        string getTransforme() { return this -> transforme; }
        void setTransforme(string x) { transforme = x; }

        int getTransform_util() { return this->transform_util; }
        void incTransform_util(int x) { transform_util++; }

        void setUsed(bool x) {used = x;}
        bool getUsed(){ return this->used;}

        Regle() {transforme = ""; axiome = false; used = false;}
};

class Grammaire
{
    private :
        Regle regles[100];
        int regles_util;
        int recursiv_util;

    public :

        string getReglesTransforme(int x) { return this ->regles[x].getTransforme(); }
        string getReglesENT(int x) { return this -> regles[x].getENT(); }

        void setReglesTransforme(int x, string y) { regles[x].setTransforme(y); }
        void setReglesENT(int x, string y) { regles[x].setENT(y); }

        int getRegles_util() { return this->regles_util; }
        void incRegles_util() { regles_util++; }

        void setReglesAxiome(int x, bool y) {regles[x].setAxiome(y);}
        bool getReglesAxiome(int x) {return this->regles[x].getAxiome();}

        Grammaire() { regles_util = 1;}

        void setRecursivUtil(int x) {recursiv_util = x;}
        int getRecursivUtil() {return this->recursiv_util;}
        void incRecursivUtil() { recursiv_util++; }

        void setReglesUsed(int x, bool y){regles[x].setUsed(y);}
        bool getReglesUsed(int x){return this->regles[x].getUsed();}

        Regle getRegle(int x){return regles[x];}
};

class Etat
{
    private:
    int name;
    Regle ensemble[100];
    int ensemble_util;
    char DejaTraitesParLePoint[100];
    int point_util;

    public:
    Etat(){ensemble_util = 0; point_util = 0;}
    int getName(){return this->name;}
    void setName(int x){name = x;}
    Regle getEnsemble(int x){return ensemble[x];}
    void setEnsemble(int x, Regle R){ensemble[x] = R;}
    void setEnsemble(int x, string nonterminal, string transforme){ensemble[x].setENT(nonterminal); ensemble[x].setTransforme(transforme);}
    int getEnsembleUtil(){return ensemble_util;}
    void incEnsembleUtil(){ensemble_util++;}
    string getReglesTransforme(int x) { return this ->ensemble[x].getTransforme(); }
    void setReglesTransforme(int x, string y) { ensemble[x].setTransforme(y); }
    char getDejaTraitesParLePoint(int x){return DejaTraitesParLePoint[x];}
    void setDejaTraitesParLePoint(int x, char y){DejaTraitesParLePoint[x] = y;}
    int getPoint_util(){return point_util;}
    void incPoint_util(){point_util++;}
    string getReglesENT(int x) { return this -> ensemble[x].getENT(); }
    void setReglesENT(int x, string y) { ensemble[x].setENT(y); }
    void setReglesUsed(int x, bool y){ensemble[x].setUsed(y);}
    bool getReglesUsed(int x){return this->ensemble[x].getUsed();}

};

int main()
{
    ifstream sourceGraphe("test.txt");
    string ligne;
    Grammaire G;
    string y;
    string convert ="";

    while(getline(sourceGraphe,ligne))
    {
        convert = convert + ligne[0];
        G.setReglesENT(G.getRegles_util(), convert);
        convert = "";
        for (int i=2; i < ligne.size() ; i++)
        {
            G.setReglesTransforme(G.getRegles_util(), G.getReglesTransforme(G.getRegles_util()) + ligne[i]);
        }
        G.incRegles_util();
    }

    int temp = 1;
    G.setReglesAxiome(1,true);
    while(G.getReglesENT(temp + 1) == G.getReglesENT(1))
    {
        G.setReglesAxiome(temp + 1, true);
        temp = temp + 1;
    }

    //ajout de la regle: S'= S

    G.setReglesENT(0,G.getReglesENT(1) + "'");
    G.setReglesTransforme(0,G.getReglesENT(1));
    G.setReglesAxiome(0,true);

    for (int z=1; z < G.getRegles_util(); z++)
    {
        if(G.getReglesAxiome(z) == true)
        {
            G.setReglesAxiome(z, false);
        }
    }

    for (int z=0; z < G.getRegles_util(); z++)
    {
        cout << "etat : "<< G.getReglesENT(z) << ", transformee : " << G.getReglesTransforme(z) << ", est axiome? " << G.getReglesAxiome(z) << endl;
    }
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;
    //etape 2 construction de lautomate

    Etat etats[100];
    int nbr_etats =0;
    int nbr_reduces_trouves =0;
    bool reduce[100];
    etats[0].setName(0);
    for(int k=0; k < G.getRegles_util() - 2;k++)
    {
        etats[0].setEnsemble(k, G.getRegle(k));
        etats[0].setReglesTransforme(k, "." + etats[0].getReglesTransforme(k));
        etats[0].incEnsembleUtil();
    }


    for (int cptreduce = 0; cptreduce < etats[0].getEnsembleUtil();cptreduce++)
    {
        reduce[cptreduce] = false;
    }

    while(nbr_reduces_trouves < etats[0].getEnsembleUtil())
    {
        for(int x=0; x < etats[nbr_etats].getEnsembleUtil(); x++)
        {
            char transition;
            if (etats[nbr_etats].getReglesTransforme(x)[etats[nbr_etats].getReglesTransforme(x).size()-1] == '.')
            {
                for(int temp_point = 0; temp_point < etats[0].getEnsembleUtil(); temp_point++)
                {
                    if (etats[0].getReglesENT(temp_point) == etats[nbr_etats].getReglesENT(x) && etats[0].getReglesTransforme(temp_point).substr(1,etats[0].getReglesTransforme(temp_point).size() - 1) == etats[nbr_etats].getReglesTransforme(x).substr(0,etats[nbr_etats].getReglesTransforme(x).size() - 1) && reduce[temp_point] == false)
                    {
                        reduce[temp_point] = true;
                        nbr_reduces_trouves++;
                    }
                }
            }
            else if(etats[nbr_etats].getReglesUsed(x) == false)
            {
                 //creation du nouvel état
                etats[nbr_etats + 1].setName(nbr_etats + 1);
                etats[nbr_etats + 1].setEnsemble(etats[nbr_etats + 1].getEnsembleUtil(), etats[nbr_etats].getEnsemble(x));
                //changer le transforme de la regle exportee.
                string retemp = etats[nbr_etats + 1].getReglesTransforme(etats[nbr_etats + 1].getEnsembleUtil());

                for(int z=0; z < retemp.size() -1 ; z++)
                {
                    if(retemp[z] == '.')
                    {
                        transition = retemp[z + 1];
                        retemp[z] = retemp[z + 1];
                        retemp[z + 1] = '.';
                        z = retemp.size() -1;
                    }
                }
                etats[nbr_etats + 1].setReglesTransforme(etats[nbr_etats + 1].getEnsembleUtil(), retemp);
                etats[nbr_etats].setReglesUsed(x, true);
                etats[nbr_etats + 1].incEnsembleUtil();

                for(int x2=x; x2 < etats[nbr_etats].getEnsembleUtil(); x2++) //tous les autres elements
                {
                    if(etats[nbr_etats].getReglesUsed(x2) == false && etats[nbr_etats].getReglesTransforme(x2)[etats[nbr_etats].getReglesTransforme(x2).size()-1] != '.')
                    {
                        retemp = etats[nbr_etats].getReglesTransforme(x2);
                        for(int temppoint=0; temppoint < retemp.size() - 1; temppoint++)
                        {
                            if(retemp[temppoint] == '.' && retemp[temppoint + 1] == transition)
                            {
                                etats[nbr_etats + 1].setEnsemble(etats[nbr_etats + 1].getEnsembleUtil(), etats[nbr_etats].getEnsemble(x2));
                                retemp[temppoint] == retemp[temppoint + 1];
                                retemp[temppoint + 1] == '.';
                                etats[nbr_etats + 1].setReglesTransforme(etats[nbr_etats + 1].getEnsembleUtil(), retemp);
                                etats[nbr_etats].getReglesUsed(x2) == true;
                                etats[nbr_etats + 1].incEnsembleUtil();
                            }
                        }
                    }
                }////fin du x2

                for(int parcourssuivant=0; parcourssuivant < etats[nbr_etats + 1].getEnsembleUtil(); parcourssuivant++)
                {
                    if(etats[nbr_etats +1 ].getReglesTransforme(parcourssuivant)[etats[nbr_etats + 1].getReglesTransforme(parcourssuivant).size()-1] != '.')
                    {
                        retemp = etats[nbr_etats + 1].getReglesTransforme(parcourssuivant);
                        for(int temppoint=0; temppoint < retemp.size() - 1; temppoint++)
                        {
                            if(retemp[temppoint] == '.')
                            {
                                transition = retemp[temppoint + 1];
                                for(int tempaddregle=0; tempaddregle < etats[0].getEnsembleUtil(); tempaddregle++)
                                {
                                    string stringtransition = "" + transition;
                                    if(etats[0].getReglesENT(tempaddregle) == stringtransition)
                                    {
                                        etats[nbr_etats + 1].setEnsemble(etats[nbr_etats + 1].getEnsembleUtil(), etats[0].getEnsemble(tempaddregle));
                                        etats[nbr_etats + 1].incEnsembleUtil();
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }

        nbr_etats = nbr_etats + 1;
    }

    for (int parconame=0; parconame < nbr_etats; parconame++)
    {
        cout << "name etat" << etats[parconame].getName() << endl;
        for(int parco=0; parco < etats[parconame].getEnsembleUtil(); parco++)
        {
            cout << "ligne: " << etats[parconame].getReglesENT(parco) << ", " << etats[parconame].getReglesTransforme(parco) << endl;
        }
    }
}





