#ifndef GELBART_PEYROUTAT_LANGUAGE_H_INCLUDED
#define GELBART_PEYROUTAT_LANGUAGE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <stdio.h>


#include <windows.h>
#include <stack>

using namespace std;

struct setComp{
    bool operator() (list<string>* lhs, list<string>* rhs) const{

        if ((lhs == 0)||(rhs == 0))
            return true;

        if ((lhs->empty())&&(rhs == 0))
            return false;

        if ((lhs == 0)&&(rhs->empty()))
            return true;

        if (lhs->size() == rhs->size()){
            list<string>::iterator iLhs = lhs->begin();
            list<string>::iterator iRhs = rhs->begin();

            while ((iLhs != lhs->end())&&(iRhs != rhs->end())){
                if (*iLhs < *iRhs)
                    return true;

                iLhs++;
                iRhs++;
            }
            return false;
        }

        return lhs->size() < rhs->size();
    }
};

class Language{

    map<string, set<list<string>*, setComp>*>* language;
    map<int, map<string, set<int>*>*>* parseurSLR;
    string axiome;

    ofstream ofs;

public:

    Language();
    virtual ~Language();
    bool lectureFichier(string);
    void removeRecG();
    void removeRecGDirect();
    void removeRecGIndirect();
    void afficher(map<string,set<list<string>*, setComp>*>* = 0);
    void afficherSLR(map<int, map<string, set<int>*>*>* slr = 0);
    vector<string>* nonTerminaux();
    vector<string>* annulable();
    map<string, set<string>*>* getFirstSLR();
    map<string, set<string>*>* getFollowSLR();
    void calculParseurSLR();
    map<string, set<list<string>*, setComp>*>* goTo(map<string, set<list<string>*, setComp>*>*, string);
    pair<list<string>*, list<list<string>*>*>* getEndRule(map<string, set<list<string>*, setComp>*>* i);
    int getRuleNum(string, list<string>*);
    bool testMot(list<string> mot);
    bool testMotRec(list<string>, list<string> mot);
    pair<string, list<string>*>* getRule(int);
    list<string>* copyListString(list<string>* l);
    bool compareLanguage(map<string, set<list<string>*, setComp>*>* l1, map<string, set<list<string>*, setComp>*>* l2);
    bool compareRule(list<string>* l1,list<string>* l2);

    void deleteLanguage(map<string, set<list<string>*, setComp>*>* l);
    void deleteListLanguage(list<map<string, set<list<string>*, setComp>*>*>* l);
    void deleteMapMap(map<int, map<string, int>*>* m);
    void deleteMapSet(map<string, set<string>*>* m);
    void deleteParseur(map<int, map<string, set<int>*>*>* m);
};

#endif // GELBART_PEYROUTAT_LANGUAGE_H_INCLUDED
