#include <iostream>
#include <string>
#include <windows.h>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


#define MAXSGram   100
#define MAXSItems  100
#define MAXSItem   100




struct GrammarFormulas
{
	string left;
	string right;
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

int   IsIncludeItems(ITEM item, ITEM *items);
int   IsIncludeItem(string s, ITEM item);
int   IsIncludeStr(char c, string p);

void  PrintGram(GrammarFormulas *p);
void  PrintAnalyTable();

char  GetNewNon_Ter();
void  StrToGram(GrammarFormulas *p, string str);
int   GetGramFromFile(GrammarFormulas *grams, char *FileName);

void    GetFirstSet(GrammarFormulas *p, string FirsetSet[]);
string  GetForwardSet(string expression, string OldForwardSet, GrammarFormulas *p);

int   CLOSURE(ITEM  &item, GrammarFormulas  *p);
ITEM  Go(ITEM  item, char  X, GrammarFormulas  *p);
int   GetItem(ITEM  *items, GrammarFormulas  *p);

void GetAnalyTable(ITEM  *items,GrammarFormulas  *p);


void  LR1Analy(GrammarFormulas  *p);

