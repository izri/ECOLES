#include "LR1.H"

extern  string   non_ter, termin; //·ÇÖÕ½á·û£¬ ÖÕ½á·û



int main()
{

	GrammarFormulas    grammarFormulas[MAXSGram];
 //   GetGrammer(grammarFormulas);
	if (GetGramFromFile(grammarFormulas, "grammar.txt") == -1)
	{
		cout<<"cannot get bases from .txt"<<endl;
		return -1;
	}

	PrintGram(grammarFormulas);

	ITEM  items[MAXSItems];
	GetItem(items, grammarFormulas);

//	PrintItems(items);
    GetAnalyTable(items, grammarFormulas);
	PrintAnalyTable();

	LR1Analy(grammarFormulas);
	return 0;
}
