
#include <iostream>
#include <fstream>
#include <String>
#define N 20

class Grammaire
{
public:
    String startsymbol;
    String terminal[N];
    String nonterminal[N];
    String gauche[N];
    String droite[N];
    String I0[N];
    int num;
    int numsym;

    Grammaire();
    void affiche();
    void consI0();
};

Grammaire()
{
    ifstream sourceGrammaire ("Grammaire.txt");
    sourceGrammaire >> startsymbol;
    do
    {
        for(int i=0;i<N;i++)
        {
            sourceGrammaire >> terminal[i];
        }
    }
    while (terminal[i] != "#")
    do
    {
        for(int i=0;i<N;i++)
        {
            sourceGrammaire >> nonterminal[i];
        }
    }
    while (nonterminal[i] != "#")
    sourceGrammaire >> num;
    numsym = 1;
    while ( num!=-1 )
    {
        sourceGrammaire >> gauche[num];
        sourceGrammaire >> droite[num];
        sourceGrammaire >> num;
        numsym++;
    }
    sourceGrammaire.close();
}

void affiche()
{

}

void consI0()
{
    String s;
    for(int i=0;i<N;i++)
    {
        if(gauche[i]==startsymbol)
        {
            s = gauche[i];
            gauche[i]="";
            gauche[i+1]=s;
            s = droite[i];
            droite[i]=
        }
    }

}
