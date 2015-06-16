#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;



/// Verifie si le string a est dans le vecteur de string b
bool aEstDansb(string &a, vector<string> &b)
{
    for(unsigned i=0 ; i<b.size() ; i++)
    {
        if(a==b[i]) return true;
    }
    return false;
}

/// Verifie si le vecteur de string a est dans le vecteur de vecteur de string b
bool aEstDansb(vector<string> &a, vector <vector<string> > &b)
{
    bool test=true;
    for(unsigned i=0 ; i<b.size() ; i++)
    {
        if(a.size() == b[i].size())
        {
            test = true;
            for(unsigned j=0 ; j< a.size() ; j++)
            {
                if(a[j] != b[i][j]) test = false;
            }
            if(test) return true;
        }
    }
    return false;
}

/// Verifie si le vector de string a est le vecteur de string b
bool aEstDansb(vector<string> &a, vector<string> &b)
{
    bool test=true;
    if(a.size() == b.size())
    {
        test = true;
        for(unsigned j=0 ; j< a.size() ; j++)
        {
            if(a[j] != b[j]) test = false;
        }
        if(test) return true;
    }
    return false;
}


bool lectureFichier(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux, string &name)
{
    ///Creation tableau pour dire quels symbole sont terminale et non terminale dans la grammaire
    map<string, bool> existenceNT;
    map<string, bool> existenceT;

    vector<string> vide;

    ///Lecture du fichier de grammaire
    ifstream fichier(name.c_str(), ios::in);

    /// Si le fichier txt existe pas on quitte
    if(!fichier) return false;


    string contenu;
    string a, b;
    vector <string> tmp;

    string axiomeSLR = "S'";
    vector <string> tmp2;
    string symbAxiome;

    unsigned i;
    ///Tant que toute les lignes du fichier n'on pas été totalement traité et que la ligne n'est pas vide  ( la ligne est stocké dans contenu )
    while(getline(fichier,contenu) && contenu.size()>0)
    {
        a.erase();
        b.erase();

        for(i=0 ; contenu[i]!= ' ' && i<contenu.size() ; i++)
        {
            a = a + contenu[i];
        }

        for(i=i+1 ; i<contenu.size() ; i++)
        {
            if(contenu[i] == ' ')
            {
                if(b.size() > 0)
                {
                    if (!existenceT[b])
                    {
                        existenceNT[b] = true;
                        terminaux.push_back(b);
                    }
                }
                tmp.push_back(b);
                b.clear();
            }
            else
            {
                b = b + contenu[i];
            }
        }
        if(a.size()>0)
        {
            if(b.size() > 0)
            {
                if (!existenceT[b])
                {
                    existenceNT[b] = true;
                    terminaux.push_back(b);
                }
            }

            if (!existenceT[a])
            {
                existenceT[a] = true;
                non_terminaux.push_back(a);
            }
            if(b.size() == 0) b = " ";
            tmp.push_back(b);
            if( !aEstDansb(tmp, grammaire[a]))
            {
                grammaire[a].push_back(tmp);
            }
        }
        a.erase();
        b.erase();
        tmp.clear();
    }
    for(int i=terminaux.size()-1 ; i>=0 ; i--)
    {
        if(aEstDansb(terminaux[i], non_terminaux)) terminaux.erase(terminaux.begin()+i);
    }



    symbAxiome = non_terminaux[0];
    tmp2.push_back(symbAxiome);
    grammaire[axiomeSLR].push_back(tmp2);

    non_terminaux.push_back(axiomeSLR);
    terminaux.push_back(symbAxiome);

    return true;

}

void afficheGrammaire(map<string, vector< vector<string> > > &grammaire, vector<string> &terminaux, vector<string> &non_terminaux)
{
    unsigned i,j,k;
    cout << "Les terminaux sont :" << endl << "{";
    for( i=0 ; i<terminaux.size() ; i++)
    {
        if (i != terminaux.size()-1) cout << terminaux[i] << ", ";
        else cout << terminaux[i];
    }
    cout << "}" << endl << endl;
    cout << "Les non-terminaux sont :" << endl << "{";
    for( i=0 ; i<non_terminaux.size() ; i++)
    {
        if (i != non_terminaux.size()-1) cout << non_terminaux[i] << ", ";
        else cout << non_terminaux[i];
    }
    cout  << "}" << endl << endl;
    cout << "La grammaire : " << endl;
    for( i=0 ; i<non_terminaux.size() ; i++)
    {
        cout << non_terminaux[i] << " : ";
        for( j=0 ; j<grammaire[non_terminaux[i]].size() ; j++)
        {

            for ( k=0 ; k<grammaire[non_terminaux[i]][j].size() && grammaire[non_terminaux[i]][j].size() != 0; k++)
            {
                if(grammaire[non_terminaux[i]][j][k]!= " ") cout << grammaire[non_terminaux[i]][j][k] << " " ;
                else cout << "_" << " ";
            }
            if(j != grammaire[non_terminaux[i]].size()-1) cout << " | ";
        }
        cout << endl;
    }
    cout << endl << endl;
}




int main()
{

    string nomFichier;
    nomFichier = "gram1.txt";

    vector<string> terminaux;
    vector<string> non_terminaux;
    map<string, vector< vector<string> > > grammaire;

    if (!lectureFichier(grammaire, terminaux, non_terminaux, nomFichier))
    {
        cerr << "ERREUR LECTURE : ouverture fichier" << endl;
    }
    afficheGrammaire(grammaire, terminaux, non_terminaux);

    cout << endl;


   // grammaire["S'"][0].push_back("S");

    cout << grammaire["S'"][0][0];




    return 0;
}
