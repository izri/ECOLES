#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct lien{
    map< char, vector<string> > source;
    map< char, vector<string> > destination;
    char caractere;
};

void charger(map< char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux);
void premier(map<char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux, vector<char>& premier, const char& car);
void suivant(map<char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux, vector<char>& suivant, const char& car);
void automate(map<char, vector<string> >& grammaire,
               vector<char>& terminaux,
                vector<char>& non_terminaux,
                 vector< map<char, vector<string> > >& I,
                  vector<lien>& liens_automate);
bool comparerGrammaire( map< char, vector<string> >& g1, map< char, vector<string> >& g2);


int main()
{
    map< char, vector<string> > g; // grammaire
    vector<char> t; // terminaux
    vector<char> nt; // non terminaux
    vector<char> pr; // premiers
    vector<char> sv; // suivants
    vector< map<char, vector<string> > > a; // automate
    vector<lien> la; // lien entre les etats

    charger(g, t, nt);
    premier(g, t, nt, pr, nt[0]);
    suivant(g, t, nt, sv, nt[0]);
    automate(g, t, nt, a, la);

    cout << "P(" << nt[0] << "): " ;
    for(int i=0; i < pr.size(); i++){
        cout << pr[i] << " ";
    }

    cout << endl << endl << "S(" << nt[0] <<"): " ;
    for(int i=0; i < sv.size(); i++){
        cout << sv[i] << " ";
    }

    cout << endl << endl <<  "Automate :" << endl << endl;

    for(int k=0; k < a.size(); k++){
        if(k!=0){
            bool estEgale = false;
            int p;
            for(p=0 ; p < a.size(); p++){
                estEgale = comparerGrammaire(a[p],la[k].source);
                if(estEgale) break;
            }
            if(estEgale) cout << "< I" << p << " > ";
            cout << "==[" << la[k].caractere << "]==> " ;
        }
        cout << "< I" << k << " >" << endl << endl;
        for(int i=0; i < a[k].size(); i++){
            for(int j=0; j < a[k][i].size(); j++){
                cout << a[k].find(i)->first << " -> " << a[k][i][j] << endl;
            }
        }
        cout << endl << endl;
    }

    cout << endl << endl << "Table d'analyse :" << endl << endl;

    for(int i=0; i < sv.size(); i++){
        cout << '\t' << sv[i];
    }

    cout << endl;

    for(int i=0; i < a.size(); i++){
        cout << endl << i;
        for(int j=0; j < sv.size(); j++){
            cout << '\t' << "-";
        }
    }

    cout << endl << endl;

    return 0;
}


void charger(map< char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux){
    ifstream fichier("SLR.txt", ios::in);
    string contenu, regle;

    if(fichier){
        while( getline(fichier,contenu) ){
            regle = contenu.substr(2);
            grammaire[ contenu[0] ].push_back( regle ); // obtenir la règle après "->"
            /*
                On cherche si le non terminal existe déjà, auquel cas on l'ajoute.
            */
            if( find(non_terminaux.begin(), non_terminaux.end(), contenu[0]) == non_terminaux.end() ){
                non_terminaux.push_back(contenu[0]);
            }

            for(int i=0; i < regle.size() ; i++){
                if( regle[i] != ' ' ){
                    if( (regle[i] >= 'A') && (regle[i] <= 'Z') ){}
                    else{
                        if( find(terminaux.begin(), terminaux.end(), regle[i]) == terminaux.end() )
                            terminaux.push_back(regle[i]);
                    }
                }
            }

        }
        fichier.close();
    }

    return;
}

void premier(map<char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux, vector<char>& premiers, const char& car){
    for(int i=0; i < grammaire[ car ].size() ; i++){
        if( find(non_terminaux.begin(), non_terminaux.end(), grammaire[ car ][i][0] ) == non_terminaux.end() )
            if( grammaire[ car ][i][0] != ' ' ){
                if( find(non_terminaux.begin(), non_terminaux.end(), grammaire[car][i][0]) == non_terminaux.end() )
                    premiers.push_back( grammaire[ car ][i][0] );
                else premier(grammaire,terminaux,non_terminaux,premiers,grammaire[car][i][0]);
            }
    }
    return ;
}

void suivant(map<char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux, vector<char>& suivant, const char& car){
    for(int i=0; i < grammaire[ car ].size() ; i++){
        for(int j=0; j < grammaire[ car ][i].size(); j++){
            if( j > 0 ){
                if( grammaire[ car ][i][j-1] ==  car ){
                    if( grammaire[ car ][i][j] == ' ' ){
                        if( find(suivant.begin(), suivant.end(), grammaire[ car ][i][j+1]) == suivant.end() ){
                            if( find(non_terminaux.begin(), non_terminaux.end(), grammaire[ car ][i][j+1]) == non_terminaux.end() )
                                suivant.push_back( grammaire[ car ][i][j+1] );
                            else
                                premier(grammaire,terminaux,non_terminaux,suivant,grammaire[car][i][j+1]);
                        }
                    } else {
                        if( find(suivant.begin(), suivant.end(), grammaire[ car ][i][j]) == suivant.end() ){
                            if( find(non_terminaux.begin(), non_terminaux.end(), grammaire[ car ][i][j]) == non_terminaux.end() )
                                suivant.push_back( grammaire[ car ][i][j] );
                            else
                                premier(grammaire,terminaux,non_terminaux,suivant,grammaire[car][i][j]);
                        }
                    }
                }
            }
        }
    }    suivant.push_back('$');
    return;
}

void automate(map<char, vector<string> >& grammaire, vector<char>& terminaux, vector<char>& non_terminaux, vector< map<char, vector<string> > >& I, vector<lien>& liens_automate){

    queue< map<char, vector<string> > > file;
    map<char, vector<string> > i0;
    vector< vector<char> > ensemble;
    bool possedeUneRegle; // condition à l'ajout d'un nouvel état
    string regle;
    int pos, decalage;

    ensemble.push_back(non_terminaux); ensemble.push_back(terminaux);

    for(int k=0; k < non_terminaux.size(); k++){
        for(int i=0; i < grammaire[ non_terminaux[k] ].size() ; i++){
            if( find(grammaire[ non_terminaux[k] ][i].begin(), grammaire[ non_terminaux[k] ][i].end(), 'e') == grammaire[ non_terminaux[k] ][i].end() )
                i0[ non_terminaux[k] ].push_back( '.' + grammaire[ non_terminaux[k] ][i] );
            else i0[ non_terminaux[k] ].push_back( "." );
        }
    }

    regle = "."; regle.append(1,non_terminaux[0]);
    i0[ char( non_terminaux[0] + non_terminaux.size() ) ].push_back( regle ); // S' -> .S

    I.push_back(i0); // on ajoute l'état I0 à l'automate

    file.push(i0);

    while( !file.empty() ){

        for(int k=0; k < ensemble.size(); k++){

            for(int i=0; i < ensemble[k].size(); i++){

                map<char, vector<string> > in; // potentiel nouvel état
                possedeUneRegle = false;

                for(int h=0; h < file.front().size(); h++){

                    for(int j=0; j < file.front()[h].size(); j++){ // pas très bon en mémoire, si c'est faux ça crée un objet, préférer map::find
                        pos = file.front()[ h ][j].find('.');
                        decalage = pos + 1;

                        if( file.front()[h][j].size() <= pos ){ // si on est dans le cas final
                            in[ file.front().find(h)->first ].push_back(regle);
                        } else if( pos != -1 ){
                            while( file.front()[ h ][j][decalage] == ' ' ) decalage++; // si croise le caracatere '.'
                            if( file.front()[ h ][j][decalage] == ensemble[k][i] ){
                                possedeUneRegle = true;

                                /*
                                    ajout des nouvelles règles
                                */
                                regle = file.front()[ h ][j];
                                char key = file.front().find(h)->first;

                                if( find(in[key].begin(), in[key].end(), regle) == in[key].end() ){
                                    swap(regle[pos], regle[decalage]); // on modifie l'ancienne règle
                                    in[ key ].push_back(regle);

                                    lien l = {file.front(),in,ensemble[k][i]}; // nouveau lien
                                    liens_automate.push_back(l);
                                }

                                if( file.front()[h][j].size() >= (++decalage) ){
                                    while( file.front()[ h ][j][decalage] == ' ' ) decalage++;

                                    if( file.front()[ h ][j][decalage] == non_terminaux[0] ){
                                        for(int n=0; n < i0[ non_terminaux[0] ].size() ; n++){
                                            if( find(in[ non_terminaux[0] ].begin(),
                                                     in[ non_terminaux[0] ].end(),
                                                     i0[ non_terminaux[0] ][n]) == in[ non_terminaux[0] ].end() )
                                                in[ non_terminaux[0] ].push_back( i0[ non_terminaux[0] ][n] ) ;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(possedeUneRegle){
                    bool existe = false;
                    for(int f=0; f<I.size() ; f++){
                        existe = comparerGrammaire(in,I[f]);
                        if(existe) break;
                    }
                    if(!existe){
                        file.push(in); // on enfile le nouvel état
                        I.push_back(in);
                    }
                }
            }
        }
        if( !file.empty() ) file.pop();
    }
    return;
}

bool comparerGrammaire( map< char, vector<string> >& g1, map< char, vector<string> >& g2){
    int semblable = 0;

    if( g1.size() != g2.size() )
        return false;

    for(int i=0; i < g1.size() ; i++){
        for(int j=0; j < g1[i].size(); j++){
            char c = g1.find(i)->first;
            if( find(g2[c].begin(), g2[c].end(), g1[i][j]) != g2[c].end() ){}
            else return false;
        }
    }

    return true;
}


