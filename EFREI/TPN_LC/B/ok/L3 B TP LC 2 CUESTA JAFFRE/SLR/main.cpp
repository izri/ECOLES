#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>


using namespace std;
struct I {
    string name;
    vector< vector<string> > entree;
    vector< vector<string> > regle;
    vector<string> lu;
};
//bool operator==(vector<string> line1, vector<string> line2);
struct I premierEtat( struct I I0, string symbol );
void etat( vector<I> *SLR, I I0, I Ii );
int main()
{
    vector<string> column;
    string mem;
    string line;
    string word;
    struct I I0;
    struct I Ii;
    int i = 0;
    vector<I> SLR;
    ifstream fichier ( "grammaire.txt" ) ;
    /*
     * Lecture du fichier et stockage dans I0
     */
    if (fichier) {
        while(getline(fichier, line))
        {
            I0.entree.push_back(column);
            stringstream buffer (line);
            buffer >> word;
            /*
             * Si on débute la construction du SLR, on définit la règle aboutissant sur l'axiome
             */
            if ( i == 0 ) {
                mem = word;
                mem += "'";
                I0.entree.at(i).push_back(mem);
                I0.entree.at(i).push_back(".");
                I0.entree.at(i).push_back(word);
                i ++;
                I0.entree.push_back(column);
            }

            I0.entree.at(i).push_back(word);
            I0.entree.at(i).push_back(".");
            buffer >> word;
            while(buffer)
            {
                I0.entree.at(i).push_back(word);
                buffer >> word;

            }
            i ++;
        }
    }
    SLR.push_back(I0);


    bool bouhlait1 = false;
    for(int x = 0; x < SLR.at(0).entree.size(); x++) {
        for(int y = 0; y < SLR.at(0).entree.at(x).size() ; y ++) {
            if(SLR.at(0).entree.at(x).at(y) == ".") {
                mem = SLR.at(0).entree.at(x).at(y+1);
                for(int z = 0; z < SLR.at(0).lu.size() ; z++) {
                    if(SLR.at(0).lu[z] == mem) {
                        bouhlait1 = true;
                    }
                }
                if(bouhlait1 == false) {
                    SLR.at(0).lu.push_back(mem);
                }
                bouhlait1 = false;
            }

        }
    }

    for ( int k = 0; k < SLR.at(0).lu.size(); k++ ) {
        Ii = premierEtat(I0, SLR.at(0).lu[k]);
        SLR.push_back(Ii);
    }

    //cout << "jusqu'ici tout va bien" << endl;
    for ( int i = 1; i < SLR.size(); i ++){
        etat( &SLR, I0, SLR.at(i) );
    }
    for ( int z = 0; z < SLR.size(); z ++) {
        cout << "I" << z << endl;
        for(int x = 0; x < SLR.at(z).entree.size(); x++) {
            for(int y = 0; y < SLR.at(z).entree.at(x).size() ; y ++) {
               cout << SLR.at(z).entree.at(x).at(y) << " ";
            }
            cout << endl;
        }
        for(int x = 0; x < SLR.at(z).regle.size(); x++) {
            for(int y = 0; y < SLR.at(z).regle.at(x).size() ; y ++) {
               cout << SLR.at(z).regle.at(x).at(y) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

void etat( vector<I> *SLR, I I0, I Ii ){
    vector<string> memLine;
    string memSymbol;
    string tempSymbol;
    bool test = false;
    I Ij;

    /**
     * On met toutes les entrées et les règles de l'état précédent dans les entrée du nouvel etat
     */
    for( int x = 0; x < Ii.entree.size() ; x++) {
        for( int y = 0; y < Ii.entree.at(x).size() ; y ++) {
            if ( Ii.entree.at(x).at(y) == "." and y+1 != Ii.entree.at(x).size() ){
                memLine = Ii.entree.at(x);
                Ij.entree.push_back(memLine);
            }
        }
    }
    for( int x = 0; x < Ii.regle.size() ; x++) {
        for( int y = 0; y < Ii.regle.at(x).size() ; y ++) {
            if ( Ii.regle.at(x).at(y) == "." and y+1 != Ii.regle.at(x).size() ){
                memLine = Ii.regle.at(x);
                Ij.entree.push_back(memLine);
            }
        }
    }
    /**
     *  On déplace le curseur sur toutes les entrées et on ajoute les symboles lus dans le tableau prévu à cet effet
     */
    for( int x = 0; x < Ij.entree.size() ; x++) {
        for( int y = 0; y < Ij.entree.at(x).size() ; y ++) {
            if ( Ij.entree.at(x).at(y) == "." and y+1 != Ij.entree.at(x).size()  ){
                memSymbol = Ij.entree.at(x).at(y+1);
                Ij.entree.at(x).at(y+1) = ".";
                Ij.entree.at(x).at(y) = memSymbol;
                if ( y+2 != Ij.entree.at(x).size() and y+1 != Ij.entree.at(x).size()){
                    tempSymbol = Ij.entree.at(x).at(y+2);
                    for(int z = 0; z < Ij.lu.size(); z ++) {
                        if (Ij.lu.at(z) == tempSymbol){test = true;}
                    }
                    if ( test == false ){

                        Ij.lu.push_back(tempSymbol);
                    }
                    test = false;
                }
                break;
            }

        }
    }
    /**
     *  On va chercher toutes les règles dont on a besoins dans I0
     */
    for(int i = 0; i < Ii.lu.size(); i ++) {
        for(int j = 0; j < I0.entree.size(); j ++) {
            if( I0.entree.at(j).at(0) == Ii.lu.at(i) ) {
                Ij.regle.push_back(I0.entree.at(j));
            }
        }
    }
    /**
     *  On parcourt les règles et on regarde si nous avons besoins d'autre règles pour les lire et on les ajoute si elles ne le sont pas déjà
     */
    for( int a = 0; a < Ij.regle.size() ; a++) {
        for( int b = 0; b < Ij.regle.at(a).size() ; b ++) {
            if ( Ij.regle.at(a).at(b) == "."){
                memSymbol = Ij.regle.at(a).at(b + 1);
                for(int m = 0; m < Ij.lu.size() ; m++) {
                    if(Ij.lu[m] == memSymbol) {
                        test = true;

                    }
                }

                if( test == false ) {
                        //system("PAUSE");
                    for(int j = 0; j < I0.entree.size(); j ++) {
                        if( I0.entree.at(j).at(0) == memSymbol ) {
                            Ij.regle.push_back(I0.entree.at(j));
                        }
                    }

                    Ij.lu.push_back(memSymbol);
                }
                test = false;
            }
        }
    }
    /**
     *  On vérifie que les entrées ne sont pas déjà traité dans un autre état
     *  Si elles le sont alors on les supprimes
     */
    for(int a = 1; a < SLR->size(); a++){
        for(int b = 0; b < SLR->at(a).entree.size(); b++){
            for (int c = 0; c < Ij.entree.size(); c++){
                if (Ij.entree.at(c).size() == SLR->at(a).entree.at(b).size()){
                    if (equal(Ij.entree.at(c).begin(), Ij.entree.at(c).end(), SLR->at(a).entree.at(b).begin())){
                        Ij.entree.erase(Ij.entree.begin()+c);
                    }
                }
            }
        }
    }
    if ( Ij.entree.begin() == Ij.entree.end() ){return;}
    /**
     *  On ajoute le nouvel etat à SLR
     */
    SLR->push_back(Ij);
    for(int x = 0; x < Ij.entree.size(); x++) {
        for(int y = 0; y < Ij.entree.at(x).size() ; y ++) {
           cout << Ij.entree.at(x).at(y) << " ";
        }
        cout << endl;
    }
    cout << endl;
    //system("PAUSE");
    etat( SLR, I0, Ij );
    return;
}

struct I premierEtat( struct I I0, string symbol ) {
    struct I Ii;
    bool test = false;
    vector<string> memLine;
    string memSymbol;
    for( int x = 0; x < I0.entree.size() ; x++) {
        for( int y = 0; y < I0.entree.at(x).size() ; y ++) {
            if ( I0.entree.at(x).at(y) == "." && I0.entree.at(x).at(y + 1) == symbol ){
                memLine = I0.entree.at(x);
                memSymbol = memLine.at(y + 1);
                memLine.at(y + 1) = ".";
                memLine.at(y) = memSymbol;
                for(int z = 0; z < Ii.lu.size() ; z++) {
                    if(Ii.lu[z] == memLine.at(y + 2)) {
                        test = true;
                    }
                }
                if( y+2 != memLine.size() && test == false ) {
                    Ii.lu.push_back(memLine.at(y + 2));
                }
                test = false;

                Ii.entree.push_back(memLine);
            }
        }
    }
    for(int i = 0; i < Ii.lu.size(); i ++) {
        for(int j = 0; j < I0.entree.size(); j ++) {
            if( I0.entree.at(j).at(0) == Ii.lu.at(i) ) {
                Ii.regle.push_back(I0.entree.at(j));
            }
        }
    }
    for( int x = 0; x < Ii.regle.size() ; x++) {
        for( int y = 0; y < Ii.regle.at(x).size() ; y ++) {
            if ( Ii.regle.at(x).at(y) == "."){
                memSymbol = Ii.regle.at(x).at(y + 1);
                for(int z = 0; z < Ii.lu.size() ; z++) {
                    if(Ii.lu[z] == memSymbol) {
                        test = true;
                    }
                }
                if( test == false ) {
                    for(int j = 0; j < I0.entree.size(); j ++) {
                        if( I0.entree.at(j).at(0) == memSymbol ) {
                            Ii.regle.push_back(I0.entree.at(j));
                        }
                    }
                }
                test = false;
            }
        }
    }
    return Ii;
}
/*
void premier(vector < vector<string> > tab) {
    vector<string> premierX;
    for(int x = 0; x < tab.size(); x++) {
            if(tab.at(x).at(2)) { // si ce n'est pas epsilon
                premierX.at(x) = tab.at(x).at(2);
            }

            else {
                premierX.at(x)='epsilon';
            }
        for(int y = 0; y < tab.size(); y++) {

            if(premierX.at(x) == tab.at(y)) { //si notre premier n'est pas terminal on lui donne son premier.

                if(tab.at(y+1) { //si ce n'est pas un epsilon.
                   premierX.at(x) = tab.at(y+1);
                }
            }
        }
    }
}
*/
