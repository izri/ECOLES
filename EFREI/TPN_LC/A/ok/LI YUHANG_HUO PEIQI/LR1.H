#include <iostream>
#include <string>
#include <windows.h>
#include <stack>
using namespace std;


#define MAXSGram   100   //文法最大数量
#define MAXSItems  100  //项目集的最大数
#define MAXSItem   100  //一个项目集的最大式子数





/*
存放文法式子的结构体
*/
struct GrammarFormulas
{
	string left; 
	string right; 
}; 



struct  SKIP
{
	char  skipStr;   //输入字符
	int   ToState;   //跳转到的状态
};

struct  ITEM
{ 
	int n;                //式子集合数目
	string  I[MAXSItem];  //式子集合
	string  ForwardSet[MAXSItem];   //向前搜索集

	SKIP    skip[MAXSItems]; //跳转状态
	int     nSkipNum;  //跳转状态数目
	ITEM()
	{
		n = 0;
		nSkipNum = 0;
	}
};

/*------辅助函数-----------------------------------*/
int   IsIncludeItems(ITEM item, ITEM *items);
int   IsIncludeItem(string s, ITEM item);
int   IsIncludeStr(char c, string p);

void  PrintGram(GrammarFormulas *p);
void  PrintItems(ITEM *item);
void  PrintAnalyTable();

/*--------文法输入处理函数-------------------------*/
char  GetNewNon_Ter();
void  StrToGram(GrammarFormulas *p, string str);
void  GetGrammer(GrammarFormulas *grams);
int   GetGramFromFile(GrammarFormulas *grams, char *FileName);

/*-------向前搜索集处理函数---------------------------------*/
void    GetFirstSet(GrammarFormulas *p, string FirsetSet[]);
string  GetForwardSet(string expression, string OldForwardSet, GrammarFormulas *p);

/*-------项目集族处理函数------------------------------*/
int   CLOSURE(ITEM  &item, GrammarFormulas  *p);
ITEM  Go(ITEM  item, char  X, GrammarFormulas  *p);
int   GetItem(ITEM  *items, GrammarFormulas  *p);

/*---------获取分析表-----------------------------*/
void GetAnalyTable(ITEM  *items,GrammarFormulas  *p);


/*---------LR1分析----------------------------------*/
void  LR1Analy(GrammarFormulas  *p);