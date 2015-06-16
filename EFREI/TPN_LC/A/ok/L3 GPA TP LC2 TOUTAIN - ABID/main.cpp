#include <iostream>
#include <fstream>

#include "grammaire.h"
using namespace std;

int main()
{
    ifstream fichier("grammaire.txt", ios::in);  // on ouvre le fichier en lecture
    vector<string> gauche;
    vector<string> droite;
    string contenu;
    int i=0;
    if(fichier)  // si l'ouverture a réussi
    {
        do
        {
            //On enregistre chaque ligne du fichier dans une variable
            getline(fichier, contenu);
            //cout<<contenu<<endl;
            gauche.push_back("#");
            //on differencie la partie de gauche et de droite de la grammaire
            gauche[i]=contenu[0];
            contenu.erase(0,1);

            string droite2;
            for(int x=0; x<contenu.size(); x++)
            {
                if(contenu[x]!=32&&contenu[x]!=9)
                {
                    droite2+=contenu[x];
                }
            }
            droite.push_back(droite2);
            cout<<gauche[i]<<" => "<<droite[i]<<"  i="<<i<<endl;
            i++;
        }
        while(!fichier.eof());
        vector<Regle> grammaire;
        //on range les variables dans une structure de grammaire
        for(i;i>-1;i++)
        {
            grammaire.push_back(Regle(gauche[i],droite[i]));
        }

        Grammaire G;
        //on créer un axiome, il ne doit correspondre a aucun autre symbole de la grammaire
        string axiome;
        cout<<"axiome?"<<endl;
        cin>>axiome;
        gauche.push_back(axiome);
        droite.push_back(gauche[0]);
        //on ajoute la nouvelle regle de l'axiome dans la grammaire
        grammaire.push_back(Regle(gauche[gauche.size()-1],droite[droite.size()-1]));
        G=Grammaire(grammaire);
        vector<Automate> automate;
        automate.push_back(G);//Creation de I0
        //ON index tout les symbole de la grammaire
        vector<char> symbole;
        for(int x=0;x<grammaire.size();x++)
        {
            string temp=grammaire[x].getGauche();
            char tempo=temp[0];
            if(symbole.size()==0)//si l'index des symbole de la grammaire est vide, pas besoin de verifier si le symbole est deja présent
            {
                symbole.push_back(tempo);
            }
            else//sinon, il faut rechercher si le symbole existe deja
            {
                int present=0;
                for(int y=0;y<symbole.size();y++)
                {
                    if(tempo==symbole[y])
                    {
                        present=1;
                        y=symbole.size();//on fait sortir de la boucle car on a trouver le symbole dans l'index
                    }
                }
                if(present==0)
                {
                    symbole.push_back(tempo);
                }

            }
        }
        symbole.push_back('$');//on ajoute un $ a la fin car il est tout de meme un symbole
        //On a rempli l'index, on va pouvoir y lié les premier et suivant de chaque non terminaux s'y trouvant.
        automate=creationautomate(automate,grammaire,axiome,G,0);//On lance une fonction recursive qui va creer les automates
        for(int i=0;i<automate.size();i++)
        {
            if(!automate[i].getfin().empty())
            {
                int z=0;
                int Rtrouver=0;
                do
                {
                    if(automate[i].getGrammaire().getRegle(z).getDroite().size()==automate[i].getCursor(z));
                    {
                        //on a retoruver une regle qui est finale
                        int x=0;
                        do
                        {
                            if(automate[i].getGrammaire().getRegle(z).getGauche()==grammaire[x].getGauche()&&automate[i].getGrammaire().getRegle(z).getDroite()==grammaire[x].getDroite())
                            {
                                //on place les regles finales dans les automates
                                string temp="R";
                                char c=x+'0';
                                temp+=c;
                                automate[i].setfin(temp);
                                Rtrouver=1;
                            }
                        }while(Rtrouver==0&&x<grammaire.size());

                    }
                    z++;
                }while(Rtrouver==0&&automate[i].getGrammaire().getRegle().size());

            }
        }
        //TOUT les R ont été placé pour trouver la fin des automates.
        //Maintenant on cherche les premier et les suivant de chaque non terminaux.
        vector<PremSuiv> premiersuivant;
        for(int x=0;x<symbole.size();x++)
        {
            premiersuivant.push_back(PremSuiv());
            if(symbole[x]<='Z'&&symbole[x]>='A')
            {
                char c=axiome[0];
                if(symbole[x]==c)
                {
                    premiersuivant[x].addSuivant('$');
                }
                for(int y=0;y<grammaire.size();y++)
                {
                    string s=grammaire[y].getGauche();
                    char* c;
                    c=(char*)s.c_str();
                    if(c[0]==symbole[x])
                    {
                        string temp=grammaire[y].getDroite();
                        char c=temp[0];
                        premiersuivant[x].addPremier(c);//On ajoute le Premier
                    }
                    for(int z=0;z<grammaire[y].getDroite().size();z++)
                    {
                        string temp=grammaire[y].getDroite();
                        char c=temp[z];
                        if(c==symbole[x]&&z<grammaire[y].getDroite().size()-1)
                        {
                            c=temp[z+1];
                            premiersuivant[x].addSuivant(c);
                        }
                        else if(c==symbole[x])
                        {
                            premiersuivant[x].addSuivant('$');
                        }
                    }
                }

            }
        }
        int counter=0;
        int modif=0;
        do
        {



        for(int x=0;x<premiersuivant.size();x++)
        {
            vector<char> s=premiersuivant[x].getPremier();
            for(int y=0;y<s.size();y++)
            {
                if(s[y]<='Z'&&s[y]>='A')//Si un des premiers est un signal non terminal, on le remplace par le ou les permier de ce symbole
                {
                    int trouver=0;
                    int z=0;
                    do
                    {
                        if(symbole[z]==s[y])
                        {
                            s.erase( s.begin() + y );
                            s.insert( s.end(), premiersuivant[z].getPremier().begin(), premiersuivant[z].getPremier().end() );
                            trouver=1;
                            modif=1;
                        }
                        z++;
                    }while(trouver==0&&z<symbole.size()-1);
                }
            }
            s=premiersuivant[x].getSuivant();
            for(int y=0;y<s.size();y++)
            {
                if(s[y]<='Z'&&s[y]>='A')//Si un des premiers est un signal non terminal, on le remplace par le ou les permier de ce symbole
                {
                    int trouver=0;
                    int z=0;
                    do
                    {
                        if(symbole[z]==s[y])
                        {
                            s.erase(s.begin()+y);
                            s.insert( s.end(), premiersuivant[z].getSuivant().begin(), premiersuivant[z].getSuivant().end() );
                            trouver=1;
                            modif=1;
                        }
                        z++;
                    }while(trouver==0&&z<symbole.size()-1);
                }
            }

        }
        counter++;
        }while(modif==1&&counter<premiersuivant.size()+100);

    //Tout les premier et les suivant de chaque symbole non terminxaux sont stocké par rapport a leurs symbole dans l'index des symboles

    //on crée la table des valeurs
    string **tableanalyse;
    *tableanalyse=new string[symbole.size()];
    for(int x=0;x<symbole.size();x++)
    {
        tableanalyse[x]=new string[automate.size()];
    }
        cout<<"..";
        for(int x=0;x<symbole.size();x++)
        {
            cout<<" | "<<symbole[x];
        }
        for(int x=0;x<automate.size();x++)
        {
            cout<<"I"<<x;

            for(int y=0;y<symbole.size();y++)
            {
                if(!automate[x].getfin().empty())
                {
                    for(int z=0;z<automate[x].getfin().size();z++)
                    {
                        string s=automate[x].Getnext(z);
                        char c=s[0];
                        if(c==symbole[y])
                        {
                            //on rempli le tableau d'analyse selon l'automates et les suivants des symboles
                            tableanalyse[y][x]="I";
                            tableanalyse[y][x]+=(char)(z);
                        }
                    }
                }
                else
                {
                    tableanalyse[y][x]="R";
                    tableanalyse[y][x]+=(char)(x+'0');
                }
                //on affiche la table d'analyse en même temps qu'elle est rempli
                cout<<tableanalyse[y][x];
                cout<<"| ";
            }

        }

        //execution non programmer

        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}
/*
PRemier et suivant :

premier = 1er membre de droite
suivant = le premier du caractere qui le suis et le membre de gauche
suivant axiome = $

table analyse :
etat en colonne
en ligne => TERMINAUX, $, NON TERMINAUX
Etat 0 =>b=>3, si on a un b en suivant de 0
matrice des automates.

Regle = les suivants,
Dans l'etat x, si il y a une regle Ry, on regarde dans l'automate, la regle correspondante
on prend le suivant du memebre de gauche

*/
