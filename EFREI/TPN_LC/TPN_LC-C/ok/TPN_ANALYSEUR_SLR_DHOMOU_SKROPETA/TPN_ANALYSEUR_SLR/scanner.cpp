#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "scanner.hpp"

#define GRAMMARTABLESIZE 10

#define ANALYSETABLESIZE 10

using namespace std;

vector<string> analyseTable;

vector<string> grammarTable;

// Nombre de ligne
Ushort line_read_nbr = 0;

unsigned short cpt = 0;

char axiome;

string rule;

Ushort a_t_c = 0;

Ushort c_t = 0;

Ushort c_n_t = 0;

// Table des terminaux
vector<char> terminal;

// Table des non terminaux
vector<char> nonTerminal;

// Table des premiers
vector<char> first;

// Table des suivant
vector<char> follow;


char fetch_first(char c) {
    for(vector<char>::iterator i = first.begin(); i != first.end(); i++) {

        if(*i == c){
            i++;
            return *i;
        }
    }
}

void createFirstAndFollow() {
    //Liste des firsts
    createFirst();

    //Liste des follows
    createFollow();
}

void createFirst() {
    char axiome;
    char left_element;
    char right_element;
    string grammar;
    char tmp;

    for(Ushort i = 0; i < grammarTable.size(); i++) {
        grammar = grammarTable[i];

        left_element = grammar[0];
        right_element = grammar[3];

        if( i == 0) {
            first.push_back(left_element);
            axiome = left_element;
            tmp = left_element;
        }

        if(tmp == left_element && isTerminal(right_element)) {
            first.push_back(right_element);
        } else if(isNonTerminal(right_element) && left_element == axiome) {
            grammar = grammarTable[++i];
            if(grammar[0] == tmp && isTerminal(grammar[3])) {
                first.push_back(grammar[3]);
            }
        } else if(left_element != axiome) {
            tmp = left_element;
            first.push_back(left_element);
            if(isTerminal(right_element)) {
                first.push_back(right_element);
            }
        }
    }
}

void createFollow() {
    string grammar;
    char axiome;
    char left_element;
    char right_element;
    Ushort grammarSize = 0;
    Ushort longString = 6;
    Ushort shortString = 4;
    char tmp;

    for(int i = 0; i < grammarTable.size(); i++) {
        grammar = grammarTable[i];
        grammarSize = grammar.size();
        left_element = grammar[0];
        right_element = grammar[3];

        if(i == 0) {
            axiome = grammar[0];
            follow.push_back(axiome);
            follow.push_back('$');
        }

        for(int j = 3; j < grammar.size(); j++) {
            char re = grammar[j];
            if(re == left_element) {
                continue;
            }

            if(re != left_element && isNonTerminal(re)) {
                if(left_element != axiome)
                    follow.push_back(left_element);
                follow.push_back(fetch_first(re));
            }
        }
    }
}

void readFile(char* fileToRead) {
    ifstream reader(fileToRead, ios::in);

    if(reader) {
        string contenu;
        while(getline(reader, contenu)) {
            grammarTable.push_back(contenu);
            //cout << contenu <<endl;
            line_read_nbr++;
        }
        reader.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier" << endl;
    }
}

void createAnalyseTable() {
    stringstream ss;
    char a = grammarTable[0][0];
    string tmp;
    ss << a;
    ss >> tmp;
    tmp = tmp + "'->" + a;
    analyseTable.push_back(tmp);


    for(vector<string>::iterator i = grammarTable.begin(); i != grammarTable.end(); i++) {
        analyseTable.push_back(*i);
    }

    int cpt = 0;
    for(vector<string>::iterator i = analyseTable.begin(); i < analyseTable.end(); i++) {
        string str = *i;
        string f = "";

        for(Ushort i = 0; i < str.size(); i++) {
                if(str[i] == '>'){
                    f += str[i];
                    f += '.';
                    continue;
                }
                f += str[i];
        }
        *i = f;
    }
}

void splitGrammar() {
//    for (int i = 0; i < line_read_nbr; i++) {
//            //cout << grammarTable[i];
//        for(int j = 0; j < grammarTable[i].size(); j++) {
//            axiome = grammarTable[i][0];
//
//            char tmp = grammarTable[i][j];
//
//            if(tmp != '|') {
//                rule += tmp;
//            } else if (tmp == '|') {
//                analyseTable[a_t_c] = rule;
//                a_t_c++;
//                rule = axiome;
//                rule += ' ';
//                rule += '-';
//                rule += '>';
//
//            }
//        }
//    }
//    analyseTable[a_t_c] = rule;

}

void display() {
    cout << "AFFICHAGE DE LA GRAMMAIRE" << endl;
    for(vector<string>::iterator i = grammarTable.begin(); i != grammarTable.end(); i++) {
        cout << *i <<endl;
    }

    cout << "" << endl;
    cout << "AFFICHAGE DES FIRSTS" << endl;
    for(vector<char>::iterator i = first.begin(); i != first.end(); i++) {
        if(i == first.begin())
            cout << *i << "'=> " << fetch_first(*i) << endl;

        if(isNonTerminal(*i)){
            cout << *i << " => ";
        }

        if(isTerminal(*i)) {
            cout << *i  << endl;
        }
    }

    cout << "" << endl;
    cout << "AFFICHAGE DES FOLLOWS" << endl;
    for(vector<char>::iterator i = follow.begin(); i != follow.end(); i++) {
        if(i == follow.begin())
            cout << *i << "'=> $" << endl;
        if(*i == '$') {
            cout << *i << " ";
        }
        if(isNonTerminal(*i)){
            cout << *i << " => ";
        }

        if(isTerminal(*i)) {
            cout << *i  << endl;
        }
    }

    cout << "" << endl;
    cout << "AFFICHAGE DE L'ITEM O" << endl;
    for(vector<string>::iterator i = analyseTable.begin(); i != analyseTable.end(); i++) {
        cout << *i <<endl;
    }
}

void checkTerminaux() {

    for(vector<string>::iterator i = analyseTable.begin(); i < analyseTable.end(); i++) {
        string str = *i;

        for(Ushort i = 0; i < str.size(); i++) {
            if(str[i] >= 65 && str[i] <= 92){
                if(!isNonTerminal(str[i])) {
                    nonTerminal.push_back(str[i]);
                }
            } else if(str[i] >= 97 && str[i] <= 123){
                if(!isTerminal(str[i])) {
                    terminal.push_back(str[i]);
                }
            }
        }
    }
}

bool isTerminal(char c) {
    for(vector<char>::iterator i = terminal.begin(); i < terminal.end(); i++) {
            if(*i == c)
                return true;
    }
    return false;
}

bool isNonTerminal(char c) {
    for(vector<char>::iterator i = nonTerminal.begin(); i < nonTerminal.end(); i++) {
            if(*i == c)
                return true;
    }
    return false;
}
