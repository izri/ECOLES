#include "SLR.H"
#include<stack>

extern  string   non_ter, termin;


int main()
{

    GrammairesFormes    GrammairesFormes[MAXSGram];

    if (ReadFromFile(GrammairesFormes, "testgrammaire.txt") == -1)
    {
        cout<<"erreur"<<endl;
        return -1;
    }

    AfficheGram(GrammairesFormes);

    ITEM  items[MAXSItems];

    GetItem(items, GrammairesFormes);

    PrintItems(items);

    GetAnalyTable(items, GrammairesFormes);

    PrintAnalyTable();






    return 0;
}
