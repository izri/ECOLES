#include "SLR1.H"

extern  string   non_ter, termin;



int main()
{

	GrammarFormulas    grammarFormulas[MAXSGram];

	if (GetGramFromFile(grammarFormulas, "grammar.txt") == -1)
	{
		cout<<"fail loading from file "<<endl;
		return -1;
	}

	PrintGram(grammarFormulas);

	ITEM  items[MAXSItems];
	GetItem(items, grammarFormulas);

    GetAnalyTable(items, grammarFormulas);
	PrintAnalyTable();

	LR1Analy(grammarFormulas);
	return 0;
}
