#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

vector<vector<char> > readFile()
{
    ifstream file("G2.txt");
    vector<vector<char> > tab;
    vector<char> row;
    char foo;
    if(file.is_open())
    {
        while(file.good())
        {
            do
            {
                file >> foo;
                if(foo != '€')
                    row.push_back(foo);
            }
            while(foo != '€');
            if(row.size()>1)tab.push_back(row);
            row.clear();
        }
    }
    return tab;
}

void vectorDisplay(vector<vector<char> > tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        for(int j =0; j < tab[i].size(); j++)
        {
            if(tab[i][j] != -1)cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

vector<char> nonTerminal(vector<vector<char> > tab)
{
    vector<char> returnTab;
    for(int i=0; i<tab.size(); i++)
    {
        returnTab.push_back(tab[i][0]);
    }
    for(int i = 0; i < returnTab.size(); i++)
    {
        for (int j = 0; j < returnTab.size()  ; j++)
        {
            if((returnTab[i] == returnTab[j]) && (i != j)) returnTab.erase(returnTab.begin()+i);
        }
    }

    return returnTab;
}

vector<char> terminal(vector<vector<char> > tab, vector<char> nonTerminal)
{
    vector<char> returnTab;
    int cpt=0;
    for (int i = 0; i < tab.size(); i++)
    {
        for (int j = 1; j < tab[i].size(); j++)
        {

            for (int k = 0; k < nonTerminal.size(); k++)
            {
                if(tab[i][j] == nonTerminal[k]) cpt++;
            }
            if(cpt == 0) returnTab.push_back(tab[i][j]);
            cpt = 0;

        }

    }
    /*for (int i = 0; i < returnTab.size()  ; i++){
        cout << returnTab[i] << " ";
    }*/
    return returnTab;

}


vector<vector<char> > first(vector<vector<char> > tab,vector<char> terminal, vector<char> nonTerminal)
{
    char nextSymb;
    int cpt=0;
    vector<char> row;
    vector<vector<char> > returnTab;
    for(int i =0; i<tab.size(); i++)    //cas ou first est terminal
    {
        for (int k = 0; k < nonTerminal.size() ; k++)
        {
            if(tab[i][1] == nonTerminal[k])
            {
                cpt++;
            }

        }
        if(cpt == 0)
        {
            row.push_back(tab[i][0]);
            row.push_back(tab[i][1]);
            returnTab.push_back(row);
        }
        cpt = 0;
        row.clear();
    }



    row.clear();
    cout<<"First  table" <<endl;
    /* do
     {*/
    for(int i =0; i<tab.size(); i++)    //cas ou first est transitoire
    {
        for(int k = 0; k < nonTerminal.size(); k++)
        {
            if(tab[i][1] != nonTerminal[k]) //si l'element appartient aux etats transitoires
            {
                /* cout << "coucou" << tab[i][1] << endl;*/
                for(int z=0; z<returnTab.size(); z++)
                {
                    if(tab[i][1] == returnTab[z][0])  // si l'element appartient aux firsts deja traites
                    {

                        row.push_back(tab[i][0]);       //ajoute l'element
                        row.push_back(returnTab[z][1]); //ajoute les first
                        returnTab.push_back(row);

                    }
                }
            }
        }

        row.clear();
    }
    /* }
     while(returnTab.size() != (terminal.size()+nonTerminal.size()) );*/

    for(int i =0; i < returnTab.size(); i++)
    {
        for(int j = 0; j < returnTab[i].size(); j++)
        {
            cout << returnTab[i][j] << " " ;
        }
        cout << endl;
    }

    return returnTab;

}


int main()
{
    vector<vector<char> >  tab, firstTab;
    vector<char> terminalTab, nonTerminalTab;
    tab = readFile();
    vectorDisplay(tab);
    nonTerminalTab = nonTerminal(tab);
    terminalTab = terminal(tab,nonTerminalTab);
    firstTab = first(tab,terminalTab, nonTerminalTab);

    return 0;
}


