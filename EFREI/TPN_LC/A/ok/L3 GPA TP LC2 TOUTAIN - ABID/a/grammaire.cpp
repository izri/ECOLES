#include <iostream>
#include <fstream>

#include "grammaire.h"
using namespace std;
Regle::Regle(string g,string d): gauche(g),droite(d)
{

}
Regle::Regle(){}

Grammaire::Grammaire()
{

}

Grammaire::Grammaire(vector<Regle> r): regles(r)
{

}

Automate::Automate(){}
Automate::Automate(Grammaire G):regles(G)
{
    int i=G.getRegle().size();
    for(int x=0;x<i;x++)
    {
        this->curseur.push_back(-1);
    }
}
Automate::Automate(Grammaire G,vector<int>c):regles(G),curseur(c)
{

}
int Automate::getCursor(int i)
{
    return this->curseur[i];
}
void Automate::Addnext(int a,string s)
{

    this->suivant.push_back(a);
    this->strsuivant.push_back(s);
}
string Automate::Getnext(int i)
{
    return this->strsuivant[i];
}
int Automate::Getnext(string i)
{
    for(int x=0;x<this->strsuivant.size();x++)
    {
        if(this->strsuivant[x]==i)
            return this->suivant[x];
    }
    return -1;
}

vector<string> Automate::Getnext()
{
    return this->strsuivant;
}
Regle Grammaire::getRegle(int i)
{
    return this->regles[i];
}
vector<Regle> Grammaire::getRegle()
{
    return this->regles;
}
string Automate::getfin()
{
    return this->fin;
}
    string Regle::getGauche()
    {
        return this->gauche;
    }
    string Regle::getDroite()
    {
        return this->droite;
    }
int Grammaire::getnbregle()
{
    return this->regles.size();
}
Grammaire Automate::getGrammaire()
{
    return this->regles;
}
void Automate::setfin(string fin)
{
    this->fin=fin;
}

PremSuiv::PremSuiv()
{

}
void PremSuiv::addPremier(char i)
{
    this->Premier.push_back(i);
}
void PremSuiv::addSuivant(char i)
{
    this->Suivant.push_back(i);
}
vector<char> PremSuiv::getPremier()
{
    return this->Premier;
}
vector<char> PremSuiv::getSuivant()
{
    return this->Suivant;
}
char PremSuiv::getPremier(int i)
{
    return this->Premier[i];
}
char PremSuiv::getSuivant(int i)
{
    return this->Suivant[i];
}







vector<Automate> creationautomate(vector<Automate>automate,Grammaire grammaire,string axiome,Automate automateprec,int nbfind)
{
    vector<Regle> regle;
    vector<int>curseur;
    cout<<grammaire.getnbregle()<<endl;
    int trouver;
    for(int i=0;i<grammaire.getnbregle();i++)
    {
        if(grammaire.getRegle(i).getGauche()==axiome)
        {
            regle.push_back(Regle(grammaire.getRegle(i)));
            int stop=0;
            int x=0;
            int first=0;
            int follow=0;
            char c=axiome[0];

            //On place le curseur au bon endroit
            int temp=-1;
            do
            {
                char s=grammaire.getRegle(i).getDroite()[0];
                if(c==s)
                {
                    int cursor=0;
                    for(int r=0;r<automateprec.getGrammaire().getRegle().size();r++)
                    {
                        if(automateprec.getGrammaire().getRegle(r).getGauche()==grammaire.getRegle(i).getGauche()&&automateprec.getGrammaire().getRegle(r).getDroite()==grammaire.getRegle(i).getDroite())
                        {
                            if(automateprec.getCursor(r)==x)
                            {
                                cursor=1;
                            }
                        }
                    }
                    if(cursor==0&&first==0)
                    {

                        first=1;
                        temp=x;
                    }
                    if(follow==1)
                    {
                        cout<<"stop"<<endl;
                        curseur.push_back(x);
                        stop=1;
                    }
                    if(cursor==1)
                    {
                        follow=1;
                    }
                }

                x++;
            }while(stop==0||x!=grammaire.getRegle(i).getDroite().size());
            cout<<"fin do...while"<<endl;

            if(stop==0)
            {
                curseur.push_back(temp);
                if(temp==grammaire.getRegle(i).getDroite().size())
                {
                    trouver=1;
                    nbfind++;
                }
            }
            string s=grammaire.getRegle(i).getDroite();
                s=s[temp+1];
            vector<Regle> nonterminal = nonterm(grammaire,s);
            for(int x=0;x<nonterminal.size();x++)
            {
                curseur.push_back(-1);
            }
            regle.insert( regle.end(), nonterminal.begin(), nonterminal.end() );
        }
    }

    Grammaire gram=Grammaire(regle);
    Automate autom=Automate(gram,curseur);
    if(trouver==1)
    {
        char *c;
        c=new char(nbfind+'0');
        autom.setfin(c);
    }
    for(int x=0;x<automate.size();x++)
    {
        int y=0;
        int egal=0;
        do
        {
            if(autom.getGrammaire().getRegle(y).getGauche()==automate[x].getGrammaire().getRegle(y).getGauche()&&autom.getGrammaire().getRegle(y).getDroite()==automate[x].getGrammaire().getRegle(y).getDroite())
            {
                egal++;
            }
            y++;
        }while(y<autom.getGrammaire().getRegle().size()||y<automate[x].getGrammaire().getRegle().size());
        if(y==egal)
        {
            cout<<"copie d'automate, pas d'automate ne sera crée"<<endl;
            //CREATION DE LIEN.
            automateprec.Addnext(x,axiome);
            return automate;
        }
    }
    automate.push_back(Automate(gram,curseur));
    automateprec.Addnext(automate.size()-1,axiome);
    for(int i=0;i<gram.getRegle().size();i++)
    {
        for(int x=curseur[i];x<gram.getRegle(i).getDroite().size();x++)
        {
            string s=gram.getRegle(i).getDroite();
            s=s[i];
            automate=creationautomate(automate,grammaire,s,autom,nbfind);
        }
    }
    return automate;



}
vector<Regle> nonterm(Grammaire grammaire,string gauche)
{
    vector<Regle>regles;
    for(int i=0;i<grammaire.getnbregle();i++)
    {
        if(gauche==grammaire.getRegle(i).getGauche())
        {
            regles.push_back(Regle(grammaire.getRegle(i).getGauche(),grammaire.getRegle(i).getDroite()));
            if(grammaire.getRegle(i).getDroite()[0]<='Z'&&grammaire.getRegle(i).getDroite()[0]>='A')
            {
                string s=grammaire.getRegle(i).getDroite();
                s=s[0];
                vector<Regle>regles2=nonterm(grammaire,s);
                regles.insert( regles.end(), regles2.begin(), regles2.end() );
            }
        }
    }
    return regles;
}

