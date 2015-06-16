#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string MOT_VIDE = "e";

struct Rule
{
    string trans;
    int id;
};


struct Grammaire
{
    int NB_ETAT_MAX;
    Rule* gram;
    string axiome;
    string alphabet;
};


bool contains(char c, string s)
{
    bool b = false;

    for(int i = 0; i < s.size(); i++)
    {
        b = b || (s[i] == c);
    }
    return b;
}


string FindAllChar(string s)
{
    string alphabet = "";
    string check;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '.' && s[i] != ' ')
        {
            if(!contains(s[i], check))
            {
                alphabet = alphabet + s[i];
                check = alphabet;
            }
        }
    }
    return alphabet;
}



Rule* ReadFile(char* file, int nb_etat_max)
{
    ifstream fich(file);
    Rule* contenu = new Rule[nb_etat_max+1];// déclaration d'une chaîne qui contiendra la ligne lue

    for(int i = 1; i < nb_etat_max+1; i++)
    {
        getline(fich, contenu[i].trans);
        contenu[i].id = i;
    }

    fich.close();
    return contenu;
}

void CountEtat(char* file, Grammaire* g)
{
    ifstream fich(file);
    int i = 0;
    string s;

    while(getline(fich, s))
    {
        i++;
    }
    g->NB_ETAT_MAX = i;
    fich.close();
}


Grammaire AddDot(Grammaire g)
{
    for(int i = 0; i < g.NB_ETAT_MAX; i++)
    {
        if(g.gram[i].trans.substr((g.gram[i].trans.size() - 1), 1) == MOT_VIDE)
        {
            g.gram[i].trans = g.gram[i].trans.substr(0, 1) + " .";
        }
        else
        {
            g.gram[i].trans = g.gram[i].trans.substr(0, 2) + "." + g.gram[i].trans.substr(2, (g.gram[i].trans.size() - 2));
        }
        cout << g.gram[i].trans << endl;
    }
    return g;
}



Grammaire CreateGrammaire(char* file)
{
    Grammaire g;

    CountEtat(file, &g);

    g.gram = ReadFile(file, g.NB_ETAT_MAX);
    g.axiome = "X";
    g.gram[0].trans = g.axiome + " " + g.gram[1].trans.substr(0, 1);
    g.NB_ETAT_MAX++;
    cout << "I0 :" << endl << endl;
    g = AddDot(g);

    for(int i = 0; i < g.NB_ETAT_MAX; i++)
    {
        g.alphabet = g.alphabet + FindAllChar(g.gram[i].trans);
    }
    g.alphabet = FindAllChar(g.alphabet);
    cout << endl << "g.alphabet = " << g.alphabet << endl;
    return g;
}




int main()
{
    char* file = "grammaire.txt";
    Grammaire g = CreateGrammaire(file);

    return 0;
}
