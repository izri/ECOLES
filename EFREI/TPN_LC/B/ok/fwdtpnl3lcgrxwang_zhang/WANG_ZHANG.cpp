#include <iostream>
#include <string>
#include <windows.h>
#include <stack>
#include<stdio.h>
using namespace std;


#define MG   100
#define MSS  100
#define MS   100

string   non_terminal, terminal;
string   Caracteres;
string  **TableDAnalyse;
int NombreDeGrammaire=0 ;
int NombreDeEtat=0;
int Table[100];



struct Grammaires
{
    string gauche;
    string droite;
};


struct  Shift
{
    char  shiftCaractere;
    int   aEtat;
};

struct  Etat
{
    int n;
    string  I[MS];
    string  ForwardSet[MS];

    Shift    shift[MSS];
    int     numDeShift;
    Etat()
    {
        n = 0;
        numDeShift = 0;
    }
};




void  Transfomer(Grammaires *p, string str);
int    ControleCaractere(char c, string p);







void AfficherLaGrammaire(Grammaires *p)
{
    int i;
    for(i=0; i<NombreDeGrammaire; i++)
        cout<<"                                   "<<p[i].gauche<<"->"<<p[i].droite<<endl;
}



void  AfficherTableDAnalyse()
{
    int i=0, j=0;
    cout<<'\t';
    for (i=0; i<Caracteres.length()-1; i++)
    {
        cout<<""<<Caracteres[i]<<'\t';
    }
    cout<<endl;
    for (i=0; i<NombreDeEtat; i++)
    {
        cout<<i<<'\t';
        for (j=0; j<Caracteres.length(); j++)
        {
            cout<<TableDAnalyse[i][j]<<'\t';
        }
        cout<<endl;
    }
}




char ObtenirNouveauNon_Terminal()
{
    char c='E';
    while(ControleCaractere(c,non_terminal) != -1)
        c++;
    return c;
}




int  LectureDeFichier(Grammaires *grams, char *FileName)
{
    int i=0, N=0;
    string   str[50];
    Grammaires p[MG];
    FILE   *file = fopen(FileName, "r+");

    if (file == NULL)
    {
        return -1;
    }

    char  buff[256];
    fscanf(file, "%s", buff);
    non_terminal = buff;
    fscanf(file, "%s", buff);
    terminal = buff;
    terminal +="#";

    fscanf(file, "%d", &N);

    for(i=0; i<N; i++)
    {
        fscanf(file, "%s", buff);
        str[i] = buff;
    }
    for(i=0; i<N; i++)
    {
        if(str[i][1]!='-'||str[i][2]!='>')
        {
            cout<<endl<<"erreur!"<<endl;
            return -1;
        }
      Transfomer(p,str[i]);
    }



    char c = ObtenirNouveauNon_Terminal();
    non_terminal +=c;
    grams[0].gauche = c;
    grams[0].droite= p[0].gauche;
    for (i=0; i<NombreDeGrammaire; i++)
    {
        grams[i+1].gauche = p[i].gauche;
        grams[i+1].droite = p[i].droite;
    }
    NombreDeGrammaire++;

    fclose(file);
    return 0;
}




int  ControleEtat(string s, Etat symbole)
{
    int i=0;
    for (i=0; i<symbole.n; i++)
    {
        if (symbole.I[i].compare(s) == 0)
        {
            return i;
        }
    }
    return -1;
}




int  ControleEtat(Etat symbole, Etat *symboles)
{
    int i=0, j=0;
    for (i=0; i<NombreDeEtat; i++)
    {
        if ( (symbole.I[0].compare(symboles[i].I[0]) ==0) &&(symbole.ForwardSet[0].compare(symboles[i].ForwardSet[0]) ==0))
        {
            return i;
        }
    }
    return -1;
}



int  ControleCaractere(char c, string p)
{
    int i;
    if(p.length()==0)
        return -1;
    for (i=0; i<p.length() ; i++)
    {
        if (p[i]==c)
        {
            return i;
        }
    }
    return -1;
}





void AfficherEtat(Etat *symbole)
{
    int i=0, j=0;
    cout<<endl<<"　　　　　　　　　　　　　　　　　　　"<<endl;;
    for (i=0; i<NombreDeEtat; i++)
    {
        cout<<"　　　　　　　　　　　　　　　　　　　　　　"<<endl;
        cout<<"******"<<endl;
        cout<<"I:"<<i<<""<<endl;
        cout<<"******"<<endl;
        for (j=0; j<symbole[i].n; j++)
        {
            cout<<symbole[i].I[j]<<endl;
        }

    }
}




void  GFS(Grammaires *p, string FirsetSet[])
{
    int i=0,j=0;

    int IsChange;

    while (IsChange)
    {
        IsChange = false;
        for (i=0 ; i<NombreDeGrammaire; i++)
        {
            for (j=0; j<p[i].droite.length(); j++)
            {

                if ( ControleCaractere(p[i].droite[j], non_terminal) !=-1)
                {
                    int a =  ControleCaractere(p[i].gauche[0], non_terminal);
                    int b =  ControleCaractere(p[i].droite[j], non_terminal);

                    for (int k=0; k<FirsetSet[b].length(); k++)
                    {
                        if ( ControleCaractere( FirsetSet[b][k],  FirsetSet[a]) == -1)
                        {
                            if (FirsetSet[b][k] != '$')
                            {
                                FirsetSet[a] += FirsetSet[b][k];
                                IsChange = true;
                            }
                        }
                    }

                    if ( ControleCaractere('$', FirsetSet[b]) ==-1)
                    {
                        break;
                    }
                    else if (j == p[i].droite.length()-1)
                    {
                        if ( ControleCaractere('$', FirsetSet[a])== -1)
                        {
                            FirsetSet[a] += '$';
                        }
                    }
                }
                else
                {
                    int b=  ControleCaractere(p[i].gauche[0], non_terminal);
                    int a =  ControleCaractere(p[i].droite[j],FirsetSet[b]);
                    if (a == -1)
                    {
                        int a =  ControleCaractere(p[i].gauche[0], non_terminal);
                        FirsetSet[a] += p[i].droite[j];
                        IsChange = true;
                    }
                    break;
                }
            }
        }
    }
}






void  Transfomer(Grammaires *p, string str)
{
    int j=0;
    string  temp;

    for(j=3; j<=str.length()-1; j++)
    {
        if(str[j]!='|')
            temp +=str[j];
        else
        {
            p[NombreDeGrammaire].gauche  = str[0];
            p[NombreDeGrammaire].droite = temp;
            temp = "";
            NombreDeGrammaire++;
        }
    }
    p[NombreDeGrammaire].gauche  = str[0];
    p[NombreDeGrammaire].droite = temp;
    temp = "";
    NombreDeGrammaire++;
}





string  GFS(string expression, string OldForwardSet, Grammaires *p)
{
    string   NewForwardSet;

    string  *FirstSet = new string[non_terminal.length()];
    GFS(p,FirstSet);

    int i=0;

    for (i=0; i<expression.length(); i++)
    {
        if (expression[i] == '.')
        {
            if (i+2 <expression.length()-1)
            {
                int  a =  ControleCaractere(expression[i+2], non_terminal);
                if (a != -1)
                {
                    if ( ControleCaractere('$',FirstSet[a]) != -1)
                    {
                        NewForwardSet = FirstSet[a] + OldForwardSet;
                    }
                    else
                    {
                        NewForwardSet = FirstSet[a];
                    }

                }
                else
                {
                    NewForwardSet = expression[i+2];
                }
            }
            else
            {
                NewForwardSet = OldForwardSet;
            }
        }
    }

    return NewForwardSet;
}




int  CLOSURE(Etat  &symbole, Grammaires  *p)
{
    int i=0, j =0, k=0;

    string  *FirstSet = new string[non_terminal.length()];
    GFS(p,FirstSet);

    for (i=0; i<symbole.n; i++)
    {
        for (j=0; j<symbole.I[i].length()-1; j++)
        {
            if (symbole.I[i][j] == '.')
            {
                if ( ControleCaractere(symbole.I[i][j+1], non_terminal) !=-1)
                {

                    string  ForwardSet;
                    ForwardSet  = GFS(symbole.I[i], symbole.ForwardSet[i], p);


                    for (k=0; k<NombreDeGrammaire; k++)
                    {
                        if (p[k].gauche[0] == symbole.I[i][j+1])
                        {

                            int   a =0, nForwardIndex = 0;
                            string s;

                            if (p[k].droite[0] == '$')
                            {
                                s = p[k].gauche + "->." + '\0';
                            }
                            else
                            {
                                s = p[k].gauche + "->." + p[k].droite + '\0';
                            }

                            a =ControleEtat( s,  symbole);
                            if (a ==-1)
                            {
                                symbole.I[symbole.n] = s;
                                nForwardIndex = symbole.n;
                                symbole.n++;
                            }
                            else
                            {
                                nForwardIndex = a;
                            }

                            int  l=0;
                            for (l=0; l<ForwardSet.length(); l++)
                            {
                                if ( ControleCaractere(ForwardSet[l], symbole.ForwardSet[nForwardIndex]) ==-1)
                                {
                                    symbole.ForwardSet[nForwardIndex] +=ForwardSet[l];
                                }
                            }

                        }
                    }
                }
            }
        }
    }
    return  true;
}



Etat   Goto(Etat  symbole, char  X, Grammaires *p)
{
    Etat itemBuf;
    itemBuf.n =0 ;
    int i=0,j=0,k =0;

    for (i=0; i<symbole.n; i++)
    {
        for (j=0; j<symbole.I[i].length()-1; j++)
        {
            if (symbole.I[i][j] == '.')
            {
                if (symbole.I[i][j+1] == X)
                {
                    itemBuf.I[itemBuf.n] = symbole.I[i];
                    itemBuf.ForwardSet[itemBuf.n] = symbole.ForwardSet[i];

                    char   c = itemBuf.I[itemBuf.n][j];
                    itemBuf.I[itemBuf.n][j] = itemBuf.I[itemBuf.n][j+1];
                    itemBuf.I[itemBuf.n][j+1] = c;

                    itemBuf.n++;
                }
            }
        }
    }
    return itemBuf;
}


void  ObtenirLEtatShift(Etat  *symboles, Grammaires *p)
{
    int i=0, j = 0, k=0, l=0;

    Etat  itemBuf;
    Caracteres = terminal+non_terminal;
    for (i=0; i<NombreDeEtat; i++)
    {
        for (j=0; j<NombreDeEtat; j++)
        {
            for (k=0; k<Caracteres.length(); k++)
            {
                itemBuf = Goto(symboles[i], Caracteres[k], p);
                int  a= ControleEtat(itemBuf, symboles);

                if (a !=-1)
                {
                    for (l=0; l<=symboles[i].numDeShift; l++)
                    {
                        if (symboles[i].shift[l].shiftCaractere == Caracteres[k])
                        {
                            break;

                        }
                        else if (l == symboles[i].numDeShift)
                        {
                            symboles[i].shift[ symboles[i].numDeShift ].shiftCaractere = Caracteres[k];
                            symboles[i].shift[ symboles[i].numDeShift ].aEtat = a;
                            symboles[i].numDeShift++;
                            break;
                        }
                    }
                }
            }
        }
    }
}





int  ObtenirEtat(Etat *symboles, Grammaires  *p)
{
    int i=0, j =0;
    Caracteres = terminal+non_terminal;
    symboles[NombreDeEtat].n = 1;
   symboles[NombreDeEtat].I[0] =  p[0].gauche + "->." + p[0].droite + '\0';
    symboles[NombreDeEtat].ForwardSet[0] = "#";
    NombreDeEtat++;

    CLOSURE(symboles[i], p);

    for (i=0; i<NombreDeEtat; i++)
    {
        for (j=0; j<Caracteres.length(); j++)
        {
            Etat  itemBuf = Goto(symboles[i],Caracteres[j], p);

            if (itemBuf.n != 0)
            {
                CLOSURE(itemBuf, p);

                if ( ControleEtat(itemBuf, symboles) == -1)
                {
                    symboles[NombreDeEtat] = itemBuf;
                   NombreDeEtat++;
                }
            }
        }
    }
    ObtenirLEtatShift(symboles, p);
    return 0;
}






void  ObtenirTableDAnalyse(Etat  *symboles,Grammaires  *p)
{
    Caracteres = terminal + non_terminal;
      int a=0;
    Caracteres = terminal + non_terminal;
    for (a=0; a<Caracteres.length(); a++)
    {
        Table[Caracteres[a]] = a;
    }

    int col = Caracteres.length();
    int raw = NombreDeEtat;
    int i=0, j=0, k=0, l=0;
    int StateAft=0, inputType=0;
    char input;


    TableDAnalyse = new string*[raw];
    for (i=0; i<raw; i++)
    {
       TableDAnalyse[i] = new string[col];
    }

    for (i=0; i<NombreDeEtat; i++)
    {
        for (j=0; j<symboles[i].n; j++)
        {
            int end = symboles[i].I[j].length() - 2;

            if (symboles[i].I[j][end] == '.')
            {
                string  b = p[0].gauche + "->" + p[0].droite +'.'+ '\0';
                if (b.compare(symboles[i].I[j])== 0)
                {
                    if (symboles[i].ForwardSet[j][0] == '#')
                    {
                        inputType =Table['#'];
                        TableDAnalyse[i][inputType] = "acc";
                    }
                }
                else
                {
                    for (k=0; k<symboles[i].ForwardSet[j].length(); k++)
                    {
                        inputType = Table[symboles[i].ForwardSet[j][k]];

                        for (l=0; l<NombreDeGrammaire; l++)
                        {

                            string  gram;

                            int a = symboles[i].I[j].length();

                            if (symboles[i].I[j].length()==5)
                            {
                                gram = p[l].gauche+ "->." + '\0';
                            }
                            else
                            {
                                gram = p[l].gauche + "->" + p[l].droite + '.' + '\0';
                            }

                            if (symboles[i].I[j].compare(gram) == 0)
                            {
                                StateAft = l;

                                string s;
                                char  buf[10];
                                _itoa(StateAft,buf, 10);
                                s = buf;

                                TableDAnalyse[i][inputType] = 'R' +s;
                            }
                        }
                    }
                }
            }
        }

        for (j=0; j<symboles[i].numDeShift; j++)
        {
            StateAft = symboles[i].shift[j].aEtat;
            input = symboles[i].shift[j].shiftCaractere;
            inputType = Table[input];

            string s;
            char  buf[10];
            _itoa(StateAft,buf, 10);
            s = buf;

            if ( ControleCaractere(input, terminal) !=-1)
            {
                TableDAnalyse[i][inputType]  = 'S' + s;
            }
            else
            {
                TableDAnalyse[i][inputType]  = 'S' + s;
            }

        }
    }

}






int main()
{   cout<<"********************************************************************************";
    cout<<"                              Analyseur SLR"<<endl;
    cout<<"********************************************************************************"<<endl;
    Grammaires  Grammaires[MG];

    LectureDeFichier(Grammaires, "WANG_ZHANG.txt");
    cout<<"                            *****************"<<endl;
    cout<<"                            *les grammaires:*"<<endl;
    cout<<"                            *****************"<<endl;
    AfficherLaGrammaire(Grammaires);

    Etat symboles[MSS];
    cout<<"********************************************************************************";
    ObtenirEtat(symboles, Grammaires);

    AfficherEtat(symboles);

    ObtenirTableDAnalyse(symboles, Grammaires);
    cout<<"********************************************************************************";
    cout<<"table d'analyse:"<<endl<<endl;
    AfficherTableDAnalyse();

    return 0;
}
