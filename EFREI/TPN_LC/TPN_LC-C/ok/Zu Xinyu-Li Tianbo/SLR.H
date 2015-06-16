#include <iostream>
#include <string>
#include <windows.h>
#include <stack>
using namespace std;


#define MAXSGram   200
#define MAXSItems  200
#define MAXSItem   200



struct GrammairesFormes
{
    string gauche;
    string droite;
};


struct  SKIP
{
    char  skipStr;
    int   ToState;
};

struct  ITEM
{
    int n;
    string  I[MAXSItem];
    string  ForwardSet[MAXSItem];

    SKIP    skip[MAXSItems];
    int     nSkipNum;
    ITEM()
    {
        n = 0;
        nSkipNum = 0;
    }
};



char  GetNewNon_Ter();
void  StrToGram(GrammairesFormes *p, string str);
int   ReadFromFile(GrammairesFormes *grams, char *FileName);



void  AfficheGram(GrammairesFormes *p);
void  PrintItems(ITEM *item);
void  PrintAnalyTable();

int   IsIncludeItems(ITEM item, ITEM *items);
int   IsIncludeItem(string s, ITEM item);
int   IsIncludeStr(char c, string p);



void    GetFirstSet(GrammairesFormes *p, string FirsetSet[]);
string  GetForwardSet(string expression, string OldForwardSet, GrammairesFormes *p);


int   CLOSURE(ITEM  &item, GrammairesFormes  *p);
ITEM  Go(ITEM  item, char  X, GrammairesFormes  *p);
int   GetItem(ITEM  *items, GrammairesFormes  *p);


void GetAnalyTable(ITEM  *items,GrammairesFormes  *p);


void  PrintStack(stack <int> s);
void PrintStack(stack<char> s);

