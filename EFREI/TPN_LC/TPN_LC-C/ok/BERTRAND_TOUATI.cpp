#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Grammaire
{
private:
    vector<string> terminaux;
    vector<string> non_terminaux;
    map<string, vector< vector<string> > > derivations;
    map<string, vector< vector<string> > > firsts;
    map<string, vector< vector<string> > > follow;
    bool fin;
public:
    Grammaire();
    map<string, vector< vector<string> > > getDerivations();
    vector<string> getNon_terminaux();
    vector<string> getTerminaux();
    bool getFin();
    void setFin();
    void copie_NT(vector<string> a);
    void push_b_deriv(unsigned int index, vector<string> b, vector<string> c);
    void lire_fichier();
    bool contain(string a,vector<string> b);
    bool contain_v(vector<string>a,vector <vector<string> > b);
    void afficher_grammaire();
    void afficher_precedents();
    void afficher_suivants();
    void insert_dot();
    bool equals(Grammaire gram);
    Grammaire nouveau_noeud(string x, vector<string> NT);
    bool final_dot();
    void precedents();
    bool derivation_nul(string NT);
    void suivant();
};

class Automate
{
private:
    vector<Grammaire> automates;
public:
    Automate(Grammaire grammaire);
};

int main()
{
    cout << "Grammaire: " << endl;
    Grammaire grammaire;
    grammaire.lire_fichier();
    grammaire.afficher_grammaire();
    grammaire.precedents();
    grammaire.afficher_precedents();
   // grammaire.suivant(); // ne fonctionne pas
    //grammaire.afficher_suivants();
    cout << endl << " Automate" << endl;
    Automate automate(grammaire);
    return 0;
}
Grammaire::Grammaire()
{
}
map<string, vector< vector<string> > > Grammaire::getDerivations()
{
    return derivations;
}
vector<string> Grammaire::getNon_terminaux()
{
    return non_terminaux;
}
vector<string> Grammaire::getTerminaux()
{
    return terminaux;
}
bool Grammaire::getFin()
{
    return fin;
}
void Grammaire::setFin()
{
    fin = 1;
}
void Grammaire::copie_NT(vector<string> a)
{
    non_terminaux.assign(a.begin(),a.end());
}
void Grammaire::push_b_deriv(unsigned int index, vector<string> b, vector<string> c)
{
    derivations[c[index]].push_back(b);
    non_terminaux.push_back(c[index]);
}
bool Grammaire::final_dot() // retourne faux si au moin une derivation ne finit pas par un point.
{
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
        {
            if (derivations[non_terminaux[i]][j].back() != ".") return 0;
        }
    }
    return 1;
}
bool Grammaire::equals(Grammaire gram)
{
    if (derivations.size() != gram.getDerivations().size()) return 0;
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < non_terminaux[i].size(); j++)
        {
            if (!contain_v(derivations[non_terminaux[i]][j],gram.getDerivations()[non_terminaux[i]])) return 0;
        }
    }
    return 1;
}
void Grammaire::insert_dot()
{
    string NT = non_terminaux[0] + '*';
    vector<string> regle;
    regle.push_back(non_terminaux[0]);
    derivations[NT].push_back(regle);
    non_terminaux.insert(non_terminaux.begin(),NT);
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
        {
            derivations[non_terminaux[i]][j].insert(derivations[non_terminaux[i]][j].begin(),".") ;
        }
    }
}
void Grammaire::lire_fichier()
{
    ifstream file("gram.txt");
    if (!file)
    {
        cout << "\nfichier introuvable\n";
        return ;
    }

    string line;
    string NT, regle;
    vector<string> reg;
    unsigned int i;
    while(getline(file,line))
    {
        NT.erase();
        regle.erase();
        for(i = 0; line[i] != ' ' && i < line.size(); i++)
        {
            NT = NT + line[i];
        }
        if(!contain(NT,non_terminaux)) non_terminaux.push_back(NT);
        for(i = i + 1; i < line.size(); i++ )
        {
            regle =  line[i];
            if (line[i] != ' ')reg.push_back(regle);
        }
        derivations[NT].push_back(reg);
        reg.clear();
    }
    for (i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
        {
            for (unsigned int k = 0; k < derivations[non_terminaux[i]][j].size(); k++)
            {
                if ( (!contain(derivations[non_terminaux[i]][j][k],terminaux)) && (!contain(derivations[non_terminaux[i]][j][k],non_terminaux)))
                {
                    terminaux.push_back(derivations[non_terminaux[i]][j][k]);
                }
            }
        }

    }
}

void Grammaire::precedents()
{
    vector<string> regle;
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
        {
            if (derivations[non_terminaux[i]][j].size() > 0)
            {
                if (!derivation_nul(derivations[non_terminaux[i]][j][0]))
                {
                    regle.push_back(derivations[non_terminaux[i]][j][0]);
                }
                else
                {
                    regle.push_back(derivations[non_terminaux[i]][j][1]);
                }
            }
            if (regle[0] != non_terminaux[i]) firsts[non_terminaux[i]].push_back(regle);
            regle.clear();
        }
    }
    for (unsigned int m = 0; m < non_terminaux.size(); m++)
    {
        for (unsigned int i = 0; i < non_terminaux.size(); i++)
        {
            for (unsigned int j = 0; j < firsts[non_terminaux[i]].size(); j++)
            {
                for (unsigned int k = 0; k < non_terminaux.size(); k++)
                {
                    if (firsts[non_terminaux[i]][j].size() > 0 && firsts[non_terminaux[i]][j][0] == non_terminaux[k])
                    {
                        firsts[non_terminaux[i]].erase(firsts[non_terminaux[i]].begin() + j);
                        for (unsigned int l = 0; l < firsts[non_terminaux[k]].size(); l++)
                        {
                            firsts[non_terminaux[i]].push_back(firsts[non_terminaux[k]][l]);
                        }
                    }
                }
            }
        }
    }
}

void Grammaire::suivant()
{
    vector<string> regle;
    for (unsigned int m = 0; m < non_terminaux.size(); m++)
    {
        for (unsigned int i = 0; i < non_terminaux.size(); i++)
        {
            for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
            {
                for (unsigned int k = 0; k < derivations[non_terminaux[i]][j].size(); k++)
                {
                   if (non_terminaux[m] == derivations[non_terminaux[i]][j][k] &&( (k + 1) < derivations[non_terminaux[i]][j].size()))
                   {
                       for (unsigned int l = 0; l < firsts[derivations[non_terminaux[i]][j][k + 1]].size(); l++)
                       {
                           cout << regle.size();
                           if (firsts[non_terminaux[m]][l].size() > 0) regle.push_back(firsts[derivations[non_terminaux[i]][j][k + 1]][l][0]);
                            if (!contain_v(regle,follow[non_terminaux[m]]) )follow[non_terminaux[m]].push_back(regle);
                           regle.clear();
                       }
                   }
                }
            }
        }
    }
}
bool Grammaire::derivation_nul(string NT)
{
    for(unsigned int i = 0; i < derivations[NT].size(); i++)
    {
        if (derivations[NT][i].size() == 0) return 1;
    }
    return 0;
}



bool Grammaire::contain(string a,vector<string> b)
{
    for (unsigned int j = 0; j < b.size(); j++)
    {
        if (a == b[j]) return true;
    }
    return false;
}

bool Grammaire::contain_v(vector<string>a,vector <vector<string> > b)
{
    for (unsigned int i = 0; i < b.size(); i++ )
    {
        for (unsigned int j = 0; j < b.size(); j++ )
        {
            if (!contain(a[j], b[i])) return 0;
        }
    }
}

void Grammaire::afficher_grammaire()
{
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[non_terminaux[i]].size(); j++)
        {
            cout <<endl<< non_terminaux[i] << " -> " ;
            for (unsigned int k = 0; k < derivations[non_terminaux[i]][j].size(); k++)
            {
                cout << derivations[non_terminaux[i]][j][k] ;
            }
        }
    }
    cout << endl;
}

void Grammaire::afficher_precedents()
{
    cout << endl<< "Firsts: \n";
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < firsts[non_terminaux[i]].size(); j++)
        {
            cout <<endl<< "P(" << non_terminaux[i] << ") = " ;
            if (firsts[non_terminaux[i]][j].size() == 0) cout << (char)26;
            else  cout << firsts[non_terminaux[i]][j][0] ;
        }
    }
    cout << endl;
}

void Grammaire::afficher_suivants()
{
    cout << endl<< "Follows: \n";
    for (unsigned int i = 0; i < non_terminaux.size(); i++)
    {
        for (unsigned int j = 0; j < follow[non_terminaux[i]].size(); j++)
        {
            cout <<endl<< "S(" << non_terminaux[i] << ") = " ;
            if (follow[non_terminaux[i]][j].size() == 0) cout << (char)26;
            else  cout << follow[non_terminaux[i]][j][0] ;
        }
    }
    cout << endl;
}
Grammaire Grammaire::nouveau_noeud(string x, vector<string> NT)
{
    int unsigned k = 0;
    vector<string> regle;
    Grammaire gram;
    for (unsigned int i = 0; i < NT.size(); i++)
    {
        for (unsigned int j = 0; j < derivations[NT[i]].size() ; j++)
        {
            while (derivations[NT[i]][j][k] != "." )
            {
                k++;
            }
            if (k + 1 != derivations[NT[i]][j].size() )
            {
                if (derivations[NT[i]][j][k + 1] == x)
                {
                    for (unsigned l = 0; l < derivations[NT[i]][j].size(); l++)
                    {
                        if( l != k )regle.push_back(derivations[NT[i]][j][l]);
                        if (l == k +1 ) regle.push_back(".");
                    }
                    gram.push_b_deriv(i, regle, NT);
                    regle.clear();
                }
            }
        }
    }
    return gram;
}

Automate::Automate(Grammaire grammaire)
{
    Grammaire* gram_work = new Grammaire(grammaire);
    gram_work->insert_dot();
    automates.push_back(*gram_work);
    gram_work = new Grammaire();
    automates[0].afficher_grammaire();
    cout << endl;
    unsigned int cpt = 0;
    unsigned int cpt2 = 0;
    while (cpt < automates.size())
    {
        if (!automates[cpt].getFin())
        {
            for (unsigned int i = 0; i < (automates[0].getNon_terminaux().size() + automates[0].getTerminaux().size()); i++)
            {
                if (i < automates[0].getNon_terminaux().size())
                {
                    cout << endl << "automate " << cpt2 + 1 << " lecture de l'automate "<< cpt << " avec la lettre "<<automates[0].getNon_terminaux()[i] ;
                    gram_work = new Grammaire(automates[cpt].nouveau_noeud(automates[0].getNon_terminaux()[i], automates[0].getNon_terminaux()));
                }
                else
                {
                    cout << endl << "automate " << cpt2 + 1 << " lecture de l'automate "<< cpt << " avec la lettre "<<automates[0].getTerminaux()[i - automates[0].getNon_terminaux().size()] ;
                    gram_work = new Grammaire(automates[cpt].nouveau_noeud(automates[0].getTerminaux()[i - automates[0].getNon_terminaux().size()], automates[0].getNon_terminaux()));
                }

                if (!gram_work->getDerivations().empty())
                {
                    if (gram_work->final_dot()) cout << endl <<"setfin"<<endl, gram_work->setFin();
                    for (unsigned int i = 0 ; i < automates.size(); i++)
                    {
                        if(gram_work->equals(automates[i])) gram_work->setFin();
                    }
                    automates.push_back(*gram_work);
                    cpt2++;
                    automates[cpt2].afficher_grammaire();
                    gram_work = new Grammaire();
                }
            }
        }
        cpt++;
    }
}


