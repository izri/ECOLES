#include "SLR.h"

string   non_ter, termin;
string   AllChar;

int      GramNombre=0 ;
int      ItemsNombres=0;


string  **AnalyTable;
int     MapTable[128];




void AfficheGram(GrammairesFormes *p)
{
    int i;
    for(i=0; i<GramNombre; i++)
        cout<<p[i].gauche<<"->"<<p[i].droite<<endl;
}



void  PrintAnalyTable()
{
    int i=0, j=0;
    cout<<'\t';
    for (i=0; i<AllChar.length(); i++)
    {
        cout<<AllChar[i]<<'\t';
    }
    cout<<endl;
    for (i=0; i<ItemsNombres; i++)
    {
        cout<<i<<'\t';
        for (j=0; j<AllChar.length(); j++)
        {
            cout<<AnalyTable[i][j]<<'\t';
        }
        cout<<endl;
    }
}




char GetNewNon_Ter()
{
    char c='E';
    while(IsIncludeStr(c,non_ter) != -1)
        c++;
    return c;
}




int  ReadFromFile(GrammairesFormes *grams, char *FileName)
{
    int i=0, N=0;
    string   str[50];
    GrammairesFormes p[MAXSGram];
    FILE   *file = fopen(FileName, "r+");

    if (file == NULL)
    {
        return -1;
    }

    char  buff[256];
    fscanf(file, "%s", buff);
    non_ter = buff;
    fscanf(file, "%s", buff);
    termin = buff;
    termin +="#";

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
        StrToGram(p,str[i]);
    }



    char c = GetNewNon_Ter();
    non_ter +=c;
    grams[0].gauche = c;
    grams[0].droite= p[0].gauche;
    for (i=0; i<GramNombre; i++)
    {
        grams[i+1].gauche = p[i].gauche;
        grams[i+1].droite = p[i].droite;
    }
    GramNombre++;

    fclose(file);
    return 0;
}




int  IsIncludeItem(string s, ITEM item)
{
    int i=0;
    for (i=0; i<item.n; i++)
    {
        if (item.I[i].compare(s) == 0)
        {
            return i;
        }
    }
    return -1;
}




int  IsIncludeItems(ITEM item, ITEM *items)
{
    int i=0, j=0;
    for (i=0; i<ItemsNombres; i++)
    {
        if ( (item.I[0].compare(items[i].I[0]) ==0) &&(item.ForwardSet[0].compare(items[i].ForwardSet[0]) ==0))
        {
            return i;
        }
    }
    return -1;
}



int IsIncludeStr(char c, string p)
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





void PrintItems(ITEM *item)
{
    int i=0, j=0;
    cout<<endl<<"　　　　　　　　　　　　　　　　　　　"<<endl;;
    for (i=0; i<ItemsNombres; i++)
    {
        cout<<"　　　　　　　　　　　　　　　　　　　　　　"<<endl;
        cout<<"I:"<<i<<endl;
        for (j=0; j<item[i].n; j++)
        {
            cout<<item[i].I[j]<<" , "<<item[i].ForwardSet[j]<<endl;
        }
        cout<<"Table SLR��"<<endl;
        for (j=0; j<item[i].nSkipNum; j++)
        {
            cout<<i<<"　　　"<<item[i].skip[j].skipStr<<"--->"<<item[i].skip[j].ToState<<endl;
        }
        cout<<"　　　　　　　　　　　　　　　　　　　　　　"<<endl;
    }
}




void  GetFirstSet(GrammairesFormes *p, string FirsetSet[])
{
    int i=0,j=0;

    int IsChange;

    while (IsChange)
    {
        IsChange = false;
        for (i=0 ; i<GramNombre; i++)
        {
            for (j=0; j<p[i].droite.length(); j++)
            {

                if (IsIncludeStr(p[i].droite[j], non_ter) !=-1)
                {
                    int a = IsIncludeStr(p[i].gauche[0], non_ter);
                    int b = IsIncludeStr(p[i].droite[j], non_ter);

                    for (int k=0; k<FirsetSet[b].length(); k++)
                    {
                        if (IsIncludeStr( FirsetSet[b][k],  FirsetSet[a]) == -1)
                        {
                            if (FirsetSet[b][k] != '$')
                            {
                                FirsetSet[a] += FirsetSet[b][k];
                                IsChange = true;
                            }
                        }
                    }

                    if (IsIncludeStr('$', FirsetSet[b]) ==-1)
                    {
                        break;
                    }
                    else if (j == p[i].droite.length()-1)
                    {
                        if (IsIncludeStr('$', FirsetSet[a])== -1)
                        {
                            FirsetSet[a] += '$';
                        }
                    }
                }
                else
                {
                    int b= IsIncludeStr(p[i].gauche[0], non_ter);
                    int a = IsIncludeStr(p[i].droite[j],FirsetSet[b]);
                    if (a == -1)
                    {
                        int a = IsIncludeStr(p[i].gauche[0], non_ter);
                        FirsetSet[a] += p[i].droite[j];
                        IsChange = true;
                    }
                    break;
                }
            }
        }
    }
}






void  StrToGram(GrammairesFormes *p, string str)
{
    int j=0;
    string  temp;

    for(j=3; j<=str.length()-1; j++)
    {
        if(str[j]!='|')
            temp +=str[j];
        else
        {
            p[GramNombre].gauche  = str[0];
            p[GramNombre].droite = temp;
            temp = "";
            GramNombre++;
        }
    }
    p[GramNombre].gauche  = str[0];
    p[GramNombre].droite = temp;
    temp = "";
    GramNombre++;
}





string  GetForwardSet(string expression, string OldForwardSet, GrammairesFormes *p)
{
    string   NewForwardSet;

    string  *FirstSet = new string[non_ter.length()];
    GetFirstSet(p,FirstSet);

    int i=0;

    for (i=0; i<expression.length(); i++)
    {
        if (expression[i] == '.')
        {
            if (i+2 <expression.length()-1)
            {
                int  a = IsIncludeStr(expression[i+2], non_ter);
                if (a != -1)
                {
                    if (IsIncludeStr('$',FirstSet[a]) != -1)
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




int  CLOSURE(ITEM  &item, GrammairesFormes  *p)
{
    int i=0, j =0, k=0;

    string  *FirstSet = new string[non_ter.length()];
    GetFirstSet(p,FirstSet);

    for (i=0; i<item.n; i++)
    {
        for (j=0; j<item.I[i].length()-1; j++)
        {
            if (item.I[i][j] == '.')
            {
                if (IsIncludeStr(item.I[i][j+1], non_ter) !=-1)
                {

                    string  ForwardSet;
                    ForwardSet  = GetForwardSet(item.I[i], item.ForwardSet[i], p);


                    for (k=0; k<GramNombre; k++)
                    {
                        if (p[k].gauche[0] == item.I[i][j+1])
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

                            a = IsIncludeItem( s,  item);
                            if (a ==-1)
                            {
                                item.I[item.n] = s;
                                nForwardIndex = item.n;
                                item.n++;
                            }
                            else
                            {
                                nForwardIndex = a;
                            }

                            int  l=0;
                            for (l=0; l<ForwardSet.length(); l++)
                            {
                                if (IsIncludeStr(ForwardSet[l], item.ForwardSet[nForwardIndex]) ==-1)
                                {
                                    item.ForwardSet[nForwardIndex] +=ForwardSet[l];
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



ITEM   Go(ITEM  item, char  X, GrammairesFormes  *p)
{
    ITEM  itemBuf;
    itemBuf.n =0 ;
    int i=0,j=0,k =0;

    for (i=0; i<item.n; i++)
    {
        for (j=0; j<item.I[i].length()-1; j++)
        {
            if (item.I[i][j] == '.')
            {
                if (item.I[i][j+1] == X)
                {
                    itemBuf.I[itemBuf.n] = item.I[i];
                    itemBuf.ForwardSet[itemBuf.n] = item.ForwardSet[i];

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


void  GetSkipState(ITEM  *items, GrammairesFormes  *p)
{
    int i=0, j = 0, k=0, l=0;

    ITEM   itemBuf;
    AllChar = termin+non_ter;
    for (i=0; i<ItemsNombres; i++)
    {
        for (j=0; j<ItemsNombres; j++)
        {
            for (k=0; k<AllChar.length(); k++)
            {
                itemBuf = Go(items[i], AllChar[k], p);
                int  a= IsIncludeItems(itemBuf, items);

                if (a !=-1)
                {
                    for (l=0; l<=items[i].nSkipNum; l++)
                    {
                        if (items[i].skip[l].skipStr == AllChar[k])
                        {
                            break;

                        }
                        else if (l == items[i].nSkipNum)
                        {
                            items[i].skip[ items[i].nSkipNum ].skipStr = AllChar[k];
                            items[i].skip[ items[i].nSkipNum ].ToState = a;
                            items[i].nSkipNum++;
                            break;
                        }
                    }
                }
            }
        }
    }
}





int  GetItem(ITEM  *items, GrammairesFormes  *p)
{
    int i=0, j =0;
    AllChar = termin+non_ter;
    items[ItemsNombres].n = 1;
    items[ItemsNombres].I[0] =  p[0].gauche + "->." + p[0].droite + '\0';
    items[ItemsNombres].ForwardSet[0] = "#";
    ItemsNombres++;

    CLOSURE(items[i], p);

    for (i=0; i<ItemsNombres; i++)
    {
        for (j=0; j<AllChar.length(); j++)
        {
            ITEM  itemBuf = Go(items[i],AllChar[j], p);

            if (itemBuf.n != 0)
            {
                CLOSURE(itemBuf, p);

                if ( IsIncludeItems(itemBuf, items) == -1)
                {
                    items[ItemsNombres] = itemBuf;
                    ItemsNombres++;
                }
            }
        }
    }
    GetSkipState(items, p);
    return 0;
}



void  InitMapTable()
{
    int i=0;
    AllChar = termin + non_ter;
    for (i=0; i<AllChar.length(); i++)
    {
        MapTable[AllChar[i]] = i;
    }
}



void  GetAnalyTable(ITEM  *items,GrammairesFormes  *p)
{
    AllChar = termin + non_ter;
    InitMapTable();

    int col = AllChar.length();
    int raw = ItemsNombres;
    int i=0, j=0, k=0, l=0;
    int StateAft=0, inputType=0;
    char input;


    AnalyTable = new string*[raw];
    for (i=0; i<raw; i++)
    {
        AnalyTable[i] = new string[col];
    }

    for (i=0; i<ItemsNombres; i++)
    {
        for (j=0; j<items[i].n; j++)
        {
            int end = items[i].I[j].length() - 2;

            if (items[i].I[j][end] == '.')
            {
                string  b = p[0].gauche + "->" + p[0].droite +'.'+ '\0';
                if (b.compare(items[i].I[j])== 0)
                {
                    if (items[i].ForwardSet[j][0] == '#')
                    {
                        inputType = MapTable['#'];
                        AnalyTable[i][inputType] = "acc";
                    }
                }
                else
                {
                    for (k=0; k<items[i].ForwardSet[j].length(); k++)
                    {
                        inputType = MapTable[items[i].ForwardSet[j][k]];

                        for (l=0; l<GramNombre; l++)
                        {

                            string  gram;

                            int a = items[i].I[j].length();

                            if (items[i].I[j].length()==5)
                            {
                                gram = p[l].gauche+ "->." + '\0';
                            }
                            else
                            {
                                gram = p[l].gauche + "->" + p[l].droite + '.' + '\0';
                            }

                            if (items[i].I[j].compare(gram) == 0)
                            {
                                StateAft = l;

                                string s;
                                char  buf[10];
                                _itoa(StateAft,buf, 10);
                                s = buf;

                                AnalyTable[i][inputType] = 'R' +s;
                            }
                        }
                    }
                }
            }
        }

        for (j=0; j<items[i].nSkipNum; j++)
        {
            StateAft = items[i].skip[j].ToState;
            input = items[i].skip[j].skipStr;
            inputType = MapTable[input];

            string s;
            char  buf[10];
            _itoa(StateAft,buf, 10);
            s = buf;

            if (IsIncludeStr(input, termin) !=-1)
            {
                AnalyTable[i][inputType]  = 'S' + s;
            }
            else
            {
                AnalyTable[i][inputType]  = 'G' + s;
            }

        }
    }

}



void  PrintStack(stack <int> s)
{
    stack <int> ss;
    int i=0, n = s.size();
    for ( i=0; i<n; i++)
    {
        ss.push(s.top());
        s.pop();
    }
    for (i=0 ; i<n; i++)
    {
        cout<<ss.top();
        ss.pop();
    }
}

void PrintStack(stack<char> s)
{

    stack <char> ss;
    int i=0, n = s.size();
    for ( i=0; i<n; i++)
    {
        ss.push(s.top());
        s.pop();
    }
    for (i=0 ; i<n; i++)
    {
        cout<<ss.top();
        ss.pop();
    }
}

