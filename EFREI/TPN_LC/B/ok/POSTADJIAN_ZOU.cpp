#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

class Grammaire{

private :

string axiome;  /// premier ÈlÈment
string deriv;   /// Symbole derivant

public :

    Grammaire(){
        this->axiome = -1;
        this->deriv = -1;
    };

    Grammaire (string p_axiome, string p_deriv){
        this->axiome = p_axiome;
        this->deriv = p_deriv;
    };

    string getAxiome(){
        return this->axiome;
    };

    string getDeriv(){
        return this->deriv;
    };

    void setAxiome(string p_axiome){
        this->axiome = p_axiome;
    };

    void setDeriv(string p_deriv){
        this->deriv = p_deriv;
    };
};


class Etat{

private :
    string term; /// Symboles terminaux
    string non; /// symboles dérivant
    vector<Grammaire> monEtat;

public :

    Etat();
    Etat(string p_term, string p_non){
        this->term = p_term;
        this->non = p_non;
    }

    string getTerm(){
        return this->term;
    };
    string getNon(){
        return this->non;
    };

   void setTerm(string p_term){
       this->term = p_term;
   };
   void setNon(string p_non){
        this->non = p_non;
   };

   vector<Grammaire>* getEtat(){
   return &(this->monEtat);
   };

};


int main(){

    string ligne;

    ifstream lecture("SLR_Postadjian_Zou.txt");
    cout << "Lecture du fichier" <<endl;
    if (lecture){

        while(getline(lecture, ligne))
        {
            cout << ligne << endl;
        }
        lecture.close();
    }
    else cout << " erreur " << endl;
}
