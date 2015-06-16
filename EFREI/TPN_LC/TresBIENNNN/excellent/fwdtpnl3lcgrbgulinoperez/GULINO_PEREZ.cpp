#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include <vector>
#include <sstream>
#include <stack>

int i, j, k, m, n = 0, o, p, ns = 0, tn = 0, rr = 0, ch = 0;
char read[15][10], gl[15][10], gr[15][10], temp, templ[15], tempr[15][10], *ptr, temp2[5], dfa[15][15];

using namespace std;

struct states
{
    char lhs[15], rhs[15][10];
    int n;
}I[15];

string string_to_char(char t)
{
    string test;
    stringstream ss;
    ss << t;
    ss >> test;

    return test;
}

int compstruct(struct states s1,struct states s2)
{
    int t;
    if(s1.n!=s2.n)
        return 0;
    if( strcmp(s1.lhs,s2.lhs)!=0 )
        return 0;
    for(t=0;t<s1.n;t++)
        if( strcmp(s1.rhs[t],s2.rhs[t])!=0 )
            return 0;
    return 1;
}

void moreprod()
{
    int r,s,t,l1=0,rr1=0;
    char *ptr1,read1[15][10];

    for(r=0;r<I[ns].n;r++)
    {
        ptr1=strchr(I[ns].rhs[l1],'.');
        t=ptr1-I[ns].rhs[l1];
        if( t+1==strlen(I[ns].rhs[l1]) )
        {
            l1++;
            continue;
        }
        temp=I[ns].rhs[l1][t+1];
        l1++;
        for(s=0;s<rr1;s++)
            if( temp==read1[s][0] )
                break;
        if(s==rr1)
        {
            read1[rr1][0]=temp;
            rr1++;
        }
        else
            continue;

        for(s=0;s<n;s++)
        {
            if(gl[s][0]==temp)
            {
                I[ns].rhs[I[ns].n][0]='.';
                I[ns].rhs[I[ns].n][1]=NULL;
                strcat(I[ns].rhs[I[ns].n],gr[s]);
                I[ns].lhs[I[ns].n]=gl[s][0];
                I[ns].lhs[I[ns].n+1]=NULL;
                I[ns].n++;
            }
        }
    }
}

void canonical(int l)
{
    int t1;
    char read1[15][10],rr1=0,*ptr1;
    for(i=0;i<I[l].n;i++)
    {
        temp2[0]='.';
        ptr1=strchr(I[l].rhs[i],'.');
        t1=ptr1-I[l].rhs[i];
        if( t1+1==strlen(I[l].rhs[i]) )
            continue;

        temp2[1]=I[l].rhs[i][t1+1];
        temp2[2]=NULL;

        for(j=0;j<rr1;j++)
            if( strcmp(temp2,read1[j])==0 )
                break;
        if(j==rr1)
        {
            strcpy(read1[rr1],temp2);
            read1[rr1][2]=NULL;
            rr1++;
        }
        else
            continue;

        for(j=0;j<I[0].n;j++)
        {
            ptr=strstr(I[l].rhs[j],temp2);
            if( ptr )
            {
                templ[tn]=I[l].lhs[j];
                templ[tn+1]=NULL;
                strcpy(tempr[tn],I[l].rhs[j]);
                tn++;
            }
        }

        for(j=0;j<tn;j++)
        {
            ptr=strchr(tempr[j],'.');
            p=ptr-tempr[j];
            tempr[j][p]=tempr[j][p+1];
            tempr[j][p+1]='.';
            I[ns].lhs[I[ns].n]=templ[j];
            I[ns].lhs[I[ns].n+1]=NULL;
            strcpy(I[ns].rhs[I[ns].n],tempr[j]);
            I[ns].n++;
        }

        moreprod();
        for(j=0;j<ns;j++)
        {

            if( compstruct(I[ns],I[j])==1 )
            {
                I[ns].lhs[0]=NULL;
                for(k=0;k<I[ns].n;k++)
                    I[ns].rhs[k][0]=NULL;
                I[ns].n=0;
                dfa[l][j]=temp2[1];
                break;
            }
        }
        if(j<ns)
        {
            tn=0;
            for(j=0;j<15;j++)
            {
                templ[j]=NULL;
                tempr[j][0]=NULL;
            }
            continue;
        }

        dfa[l][j]=temp2[1];
        printf("\n\nI%d :",ns);
        for(j=0;j<I[ns].n;j++)
            printf("\n\t%c -> %s",I[ns].lhs[j],I[ns].rhs[j]);
        //getch();
        ns++;
        tn=0;
        for(j=0;j<15;j++)
        {
            templ[j]=NULL;
            tempr[j][0]=NULL;
        }
    }
}

int main()
{
    FILE *f;
    int nb_etats;

    for(i = 0; i < 15; i++)
    {
        I[i].n = 0;
        I[i].lhs[0] = NULL;
        I[i].rhs[0][0] = NULL;
        dfa[i][0] = NULL;
    }

    f = fopen("GULINO_PEREZ_GRAPHE.txt", "r");
    while(!feof(f))
    {
        fscanf(f, "%c", gl[n]);
        fscanf(f, "%s\n", gr[n]);
        n++;
    }

    I[0].lhs[0] = 'Z';
    strcpy(I[0].rhs[0], ".A");
    I[0].n++;
    for(i = 0; i < n; i++)
    {
        I[0].lhs[i+1] = gl[i][0];
        strcpy(I[0].rhs[i+1], ".");
        strcat(I[0].rhs[i+1], gr[i]);
        I[0].n++;
    }

    vector<string> nonTerminaux, transformation;

    nonTerminaux.push_back("Z");
    transformation.push_back(gl[0]);
    for(int a = 0; a < n; a++)
    {
        nonTerminaux.push_back(gl[a]);
        transformation.push_back(gr[a]);
    }

    cout << "LA GRAMMAIRE EST LA SUIVANTE" << endl;
    for(i = 0; i < nonTerminaux.size(); i++)
        cout << "\t" << nonTerminaux[i] << " -> " << transformation[i] << endl;//On affiche la grammaire

    /**Premier*/

    vector< vector<string> > premier;
    int pos = 0;
    premier.push_back(vector<string>());
    premier[0].push_back(nonTerminaux[0]);
    for(i = 0; i < nonTerminaux.size(); i++)
    {
        //On mets les terminaux qui n'ont pas encore été analysés dans le tableau des premier
        bool present = false;
        for(j = 0; j < premier.size(); j++)
        {
            if(premier[j][0] == nonTerminaux[i])
            {
                present = true;
                pos = j;
            }
        }
        if(!present)
        {
            premier.push_back(vector<string>());
            pos = premier.size()-1;
            premier[pos].push_back(nonTerminaux[i]);
        }

        if(transformation[i] == "")
        {
            premier[pos].push_back("epsilon");
        }
        else
        {
            if(premier[pos][0].at(0) != transformation[i].at(0))//Si le premier caractère n'est pas le non terminal dont on cherche à trouver les premiers
            {
                premier[pos].push_back(transformation[i]);
                int pos2 = premier[pos].size()-1;
                premier[pos][pos2].erase(premier[pos][pos2].begin()+1, premier[pos][pos2].end());
            }
        }
    }
    bool nonTerminal = true;
    while(nonTerminal)
    {
        vector<int> pos_i, pos_j, pos_k;
        for(i = 0; i < premier.size(); i++)
        {
            for(j = 1; j < premier[i].size(); j++)
            {
                for(k = 0; k < premier.size(); k++)
                {
                    if(premier[i][j] == premier[k][0])
                    {
                        pos_i.push_back(i);
                        pos_j.push_back(j);
                        pos_k.push_back(k);
                    }
                }
            }
        }

        for(i = 0; i < pos_i.size(); i++)
        {
            premier[pos_i[i]].erase(premier[pos_i[i]].begin()+1);
            for(int l = 1; l < premier[pos_k[i]].size(); l++)
            {
                premier[pos_i[i]].push_back(premier[pos_k[i]][l]);
            }
        }

        nonTerminal = false;
        for(i = 0; i < premier.size(); i++)
            for(j = 1; j < premier[i].size(); j++)
                for(k = 0; k < premier.size(); k++)
                    if(premier[i][j] == premier[k][0])
                        nonTerminal = true;
    }

    cout << endl << "LES PREMIERS DE LA GRAMMAIRE SONT" << endl;
    for(i = 0; i < premier.size(); i++)
    {
        cout << "\t" << premier[i][0] << " = { ";
        for(j = 1; j < premier[i].size(); j++)
            cout << premier[i][j] << " ";//On affiche la grammaire
        cout << "}" << endl;
    }

    // Calcul des etats terminaux en anticipation de la table d'analyse
    vector<string> VAL;
    bool isTerm;
    for(int i = 0; i < transformation.size(); i ++)
    {
        for ( j = 0; j < transformation[i].size(); j ++)
        {
            isTerm = true;
            string test;
            stringstream ss;
            ss << transformation[i][j];
            ss >> test;

            for ( k = 0; k < nonTerminaux.size(); k ++)
            {
                if (test == nonTerminaux.at(k))
                {
                    isTerm = false;
                }
            }
            for ( k = 0; k < VAL.size(); k ++)
            {
                if (test == VAL.at(k))
                {
                    isTerm = false;
                }
            }
            if ( isTerm == true)
            {
                VAL.push_back(test);
            }
        }
    }

    /**Suivant*/

    vector< vector<string> > suivant;
    for(i = 0; i < premier.size(); i++)
    {
        suivant.push_back(vector<string>());
        suivant[i].push_back(premier[i][0]);
    }
    suivant[0].push_back("$");

    for(i = 1; i < suivant.size(); i++)
    {
        for(j = 0; j < transformation.size(); j++)
        {
            for(k = 0; k < transformation[j].length(); k++)
            {
                if(suivant[i][0].at(0) == transformation[j][k])
                {
                    if(k+1 == transformation[j].length())
                    {
                        bool present = false;
                        for(int unsigned l = 1; l < suivant[i].size(); l++)
                        {
                            if(suivant[i][l] == nonTerminaux[j])
                            {
                                present = true;
                            }
                        }
                        if(!present)
                        {
                            suivant[i].push_back(nonTerminaux[j]);
                        }
                    }
                    else
                    {
                        bool terminal = true;
                        for(int unsigned l = 0; l < suivant.size(); l++)
                        {
                            if(transformation[j][k+1] == suivant[l][0].at(0))
                            {
                                terminal = false;
                            }
                        }
                        if(terminal)
                        {
                            string carac = transformation[j];
                            carac.erase(carac.begin(), carac.begin()+k+1);
                            carac.erase(carac.begin()+1, carac.end());
                            bool present = false;
                            for(int unsigned l = 1; l < suivant[i].size(); l++)
                            {
                                if(carac == suivant[i][l])
                                {
                                    present = true;
                                }
                            }
                            if(!present)
                            {
                                suivant[i].push_back(carac);
                            }
                        }
                        else
                        {
                            for(int unsigned l = 0; l < premier.size(); l++)
                            {
                                if(transformation[j][k+1] == premier[l][0].at(0))
                                {
                                    for(int unsigned m = 1; m < premier[l].size(); m++)
                                    {
                                        bool present = false;
                                        for(int unsigned n = 1; n < suivant[i].size(); n++)
                                        {
                                            if(premier[l][m] == suivant[i][n])
                                            {
                                                present = true;
                                            }
                                        }
                                        if(!present)
                                        {
                                            if(premier[l][m] != "epsilon")
                                            {
                                                suivant[i].push_back(premier[l][m]);
                                            }
                                            else
                                            {
                                                suivant[i].push_back(premier[l][0]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    nonTerminal = true;
    while(nonTerminal)
    {
        int pos_i, pos_j, pos_k;
        for(i = 0; i < suivant.size(); i++)
        {
            for(j = 1; j < suivant[i].size(); j++)
            {
                for(k = 0; k < suivant.size(); k++)
                {
                    if(suivant[i][j] == suivant[k][0])
                    {
                        pos_i = i;
                        pos_j = j;
                        pos_k = k;
                    }
                }
            }
        }

        suivant[pos_i].erase(suivant[pos_i].begin()+pos_j);
        for(int l = 1; l < suivant[pos_k].size(); l++)
        {
            bool present = false;
            for(int unsigned m = 1; m < suivant[pos_i].size(); m++)
            {
                if(suivant[pos_k][l] == suivant[pos_i][m])
                {
                    present = true;

                }
            }
            if(!present)
            {
                suivant[pos_i].push_back(suivant[pos_k][l]);
            }
        }

        nonTerminal = false;
        for(i = 0; i < suivant.size(); i++)
            for(j = 1; j < suivant[i].size(); j++)
                for(k = 0; k < suivant.size(); k++)
                    if(suivant[i][j] == suivant[k][0])
                        nonTerminal = true;
    }


    cout << endl << "LES SUIVANTS DE LA GRAMMAIRE SONT" << endl;
    for(i = 0; i < suivant.size(); i++)
    {
        cout << "\t" << suivant[i][0] << " = { ";
        for(j = 1; j < suivant[i].size(); j++)
            cout << suivant[i][j] << " ";//On affiche la grammaire
        cout << "}" << endl;
    }

    VAL.push_back("$");
    // CALCUL DES NON TERMINAUX EN UN SEUL EXEMPLAIRE
    bool al;

    for(int i = 1; i < nonTerminaux.size(); i ++)
    {
        al = true;
        for( k = 0; k < VAL.size(); k ++)
        {
            if( nonTerminaux[i] == VAL[k])
                al = false;
        }
        if ( al == true)
            VAL.push_back(nonTerminaux[i]);
    }

    nb_etats = 0;
    for(i = 0; i < n; i++)
    {
        temp = I[0].rhs[nb_etats][1];
        nb_etats++;
        for(j=0;j<rr;j++)
            if(temp == read[j][0])
                break;
        if(j==rr)
        {
            read[rr][0]=temp;
            rr++;
        }
        else
            continue;
    }
    ns++;

    printf("\nI%d :\n",ns-1);
    for(i=0;i<I[0].n;i++)
        printf("\t%c -> %s\n",I[0].lhs[i],I[0].rhs[i]);

    for(nb_etats=0;nb_etats<ns;nb_etats++)
        canonical(nb_etats);

    cout << endl << "TABLE D'ANALYSE";
    // AFFICHAGE DES COLONNES DU TABLEAU
    cout << endl << endl << endl;
    cout << "ETATS |";
    for (int i = 0; i < VAL.size(); i ++)
        cout << "      " << VAL[i];
    cout << endl << endl;

    // REMPLISSAGE DU TABLEAU
    string tab[ns][VAL.size()];

    for(i=0;i<ns;i++)
    {
        for(j=0;j<VAL.size();j++)
        {
            tab[i][j] = "";
        }
    }

    for(i=0;i<ns;i++)
    {
        for(j=0;j<ns;j++)
            if(dfa[i][j]!='\0')
            {
                for (int k = 0; k < VAL.size(); k ++)
                {
                    string test;
                    stringstream ss;
                    ss << dfa[i][j];
                    ss >> test;

                    if( test == VAL[k])
                    {
                        stringstream ss;
                        ss << j;
                        tab[i][k] = ss.str(); // VALEUR A INCREMENTER PAR UN STRING SI ON A UN REDUCE
                    }
                }
            }
    }

    for(i = 0; i < nb_etats; i++)
    {
        for(j = 0; j < I[i].n; j++)
        {
            string test = I[i].rhs[j];
            if(test.at(test.size()-1) == '.')
            {
                test.erase(test.size()-1);
                for(k = 0; k < transformation.size(); k++)
                {
                    if(test == transformation[k])
                    {
                        for(int unsigned l = 0; l < suivant.size(); l++)
                        {
                            if(suivant[l][0] == nonTerminaux[k])
                            {
                                for(int unsigned m = 1; m < suivant[l].size(); m++)
                                {
                                    for(int n = 0; n < VAL.size(); n++)
                                    {
                                        if(suivant[l][m] == VAL[n])
                                        {
                                            if(tab[i][n] != "")
                                            {
                                                tab[i][n] = tab[i][n] + "/r" + (char)(k+49);
                                            }
                                            else
                                            {
                                                tab[i][n] = tab[i][n] + "r" + (char)(k+49);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }




    for(i=0;i<ns;i++)
    {
        if ( i < 10)
            cout << "I" << i << "      | ";
        else
            cout << "I" << i << "     | ";

        cout << "   ";
        for(j=0;j<VAL.size();j++)
        {
            int nbespace = 7;
            string espace;

            if( tab[i][j].size() < 7)
            {
                nbespace = nbespace - tab[i][j].size();
            }
            else
                nbespace = 1;
            for (int b = 0; b < nbespace; b ++)
                espace = " " + espace;

            // ON AFFICHE EN FONCTION DE LA TAILLE DU STRING

            cout  << tab[i][j] << espace;


        }
        printf("\n\n\n");
    }

    string mot;
    cout  << endl << "Mot du langage a executer : ";
    cin >> mot;

    stack<string> pile;
    stack<string> entre;
    stack<string> sortie[3];

    // INITIALISATION
        entre.push("$");
    for(int i = mot.size() - 1; i >= 0 ; i --)
        entre.push(string_to_char(mot[i]));

    pile.push("0");

    cout << "     Pile      |    Entree      |    Sortie"  << endl<< "               |                |        " << endl;

    cout << "     ";
    stack<string> ma_pile = pile;
    string tmp = "";
    while (!ma_pile.empty()) //tant que la pile n’est pas vide
    {
        tmp = ma_pile.top() + tmp;
        ma_pile.pop();                //puis on le supprime
    }
    cout << tmp;
    tmp = "";
    cout <<"      |    ";

    ma_pile = entre;
    while (!ma_pile.empty()) //tant que la pile n’est pas vide
    {
        tmp = tmp + ma_pile.top() ;
        ma_pile.pop();                //puis on le supprime
    }
    cout << tmp;
    tmp = "";

    cout << "      |    ";
    cout <<"  "<< endl;

    while( entre.empty() == false )
    {
        if ( pile.top() == "1" && entre.top() == "$" )
        {
            cout << "Exécution terminee";
            while( entre.empty() == false)
                entre.pop();
        }
        else
        {
            // RECUPERATION DU DERNIER CARACTERE DE LA PILE
            string lastPile = pile.top();

            // RECUPERATION DE LA LETTRE DE L'ENTRE
            string lastEntre = entre.top();


            // RECUPERATION DE LA POSITION EN FONCTION DE L'ENTREE
            int position;
            for( int i = 0; i < VAL.size(); i ++)
                if( VAL[i] == lastEntre)
                    position = i;

            // RECUPERATION DE LA REGLE DE SORTIE SI IL Y A CONFLIT

            string lastSortie = tab[atol(lastPile.c_str())][position];
            if(lastSortie.size() > 2)
            {
                string autre ="";

                string lastSortieTemp;
                bool fin = true;
                for( int i = 0; i < lastSortie.size() ; i ++)
                {
                    if( lastSortie[i] == '/' && fin == true )
                    {
                        lastSortieTemp = autre;
                        autre = "";
                        fin = false;
                    }
                    else
                    {
                        autre = autre + string_to_char(lastSortie[i]);
                    }
                }
                lastSortie = lastSortieTemp;
                sortie[3].push(autre);
            }

            if(lastSortie.size() == 0)
            {
                    cout << endl << "IMPASSE DETECTE" << endl;
                    cout << sortie[0].top() << endl;
                    system("pause");
            }

            if(lastSortie.size() == 2) // SI ON A UN REDUCE
            {
                int pozi = atoi(string_to_char(lastSortie[1]).c_str());
                bool fait = false;
                string trans = transformation[pozi - 1];

                while(trans.size() != 0)
                {
                    if (pile.top() == string_to_char(trans[trans.size() - 1]))
                    {
                        pile.pop();
                        trans.erase(trans.size()-1,1);
                    }
                    else
                    {
                        pile.pop();
                    }
                }
                string tempo = pile.top();
                pile.push(nonTerminaux[pozi - 1] );

                int position2;
                for( int i = 0; i < VAL.size(); i ++)
                    if( VAL[i] == pile.top())
                        position2 = i;

                pile.push(tab[atol(tempo.c_str())][position2]);
            }
            if(lastSortie.size() == 1) // SI ON A UN SHIFT
            {
                sortie[0].push(lastPile);
                sortie[1].push(lastEntre);
                pile.push(lastEntre);
                pile.push(lastSortie);
                entre.pop();

            }

            // AFFICHAGE
            cout << "     ";
            ma_pile = pile;
            string tmp = "";
            while (!ma_pile.empty()) //tant que la pile n’est pas vide
            {
                tmp = ma_pile.top() + tmp;
                ma_pile.pop();                //puis on le supprime
            }
            cout << tmp;
            tmp = "";
            cout <<"      |    ";

            ma_pile = entre;
            while (!ma_pile.empty()) //tant que la pile n’est pas vide
            {
                tmp = tmp + ma_pile.top() ;
                ma_pile.pop();                //puis on le supprime
            }
            cout << tmp;
            tmp = "";

            cout << "      |    ";
            cout << lastSortie;
            cout <<"  "<< endl;
        }
    }
}
