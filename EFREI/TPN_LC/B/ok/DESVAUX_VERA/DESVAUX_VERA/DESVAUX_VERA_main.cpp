#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Index.h"

using namespace std;

int main()
{

    vector< vector<string> > tab;
    vector < string > A;
    vector <string> terminaux;
    vector <string> non_terminaux;
    vector< vector<string> > P;
    vector < string > prem;
    vector< vector<string> > S;
    vector < string > suiv;
    string a;
    bool non_terminal=false, terminal_exist=false, non_terminal_exist=false;
    ifstream fichier("DESVAUX_VERA_langage.txt");  //Ouverture d'un fichier en lecture


    if(fichier)
        {
            string ligne;
            while(getline(fichier, ligne))
            {
                    stringstream ss;
                    string fin;
                    string test;
                    ss << ligne;
                    ss >> test;
                    do{
                         A.push_back(test);
                        ss >> test;
                    }while(ss.tellp()!=-1);
                    tab.push_back(A);
                A.clear();
            }
        }
    else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }


    for(int cpt=0;cpt<tab.size();cpt++)
    {
        cout << tab[cpt][0] << " -> ";
        for(int cpt2=1;cpt2<tab[cpt].size();cpt2++)
        {
            cout << tab[cpt][cpt2] <<" ";
        }
        cout << endl;
    }


    // Automate

    vector<Index> Automate;
    Index ind;

    ind.setI(tab[0][0]+"' -> . " + tab[0][0]);
    string regle;
    for(int cpt=0;cpt<tab.size();cpt++)
    {
        regle = tab[cpt][0] + " -> ." ;
        for(int cpt2=1;cpt2<tab[cpt].size();cpt2++)
        {
            regle = regle + " " + tab[cpt][cpt2];
        }
        ind.setI(regle);
    }
    ind.setNom("I0");
    Automate.push_back(ind);
    ind.clear();

    // obtenir les premiers nexts

    vector <string> next;
    bool ok = 0;
    for(int cpt = 0;cpt< Automate.size(); cpt++)
    {
        for(int cpt2=0;cpt2<Automate[cpt].getTaille();cpt2++)
        {
            for(int cpt3=0;cpt3<Automate[cpt].getI(cpt2).length();cpt3++)
            {
                if(Automate[cpt].getI(cpt2).at(cpt3) == '.')
                {
                    ok = 0;
                        for(int cpt4=(cpt3+2);cpt4<Automate[cpt].getI(cpt2).length();cpt4++)
                        {
                            if((Automate[cpt].getI(cpt2).at(cpt4)==' ')&&(ok==0))
                            {
                                next.push_back(Automate[cpt].getI(cpt2).substr(cpt3+2, cpt4-cpt3-2));
                                ok = 1;
                            }
                            if((cpt4==Automate[cpt].getI(cpt2).length()-1)&&(ok==0))
                            {
                                next.push_back(Automate[cpt].getI(cpt2).substr(cpt3+2, Automate[cpt].getI(cpt2).length()-1));
                            }
                        }
                }
            }
        }
    }
    ok = 0;
    for(int cpt=0;cpt<next.size();cpt++)
    {
        for(int cpt2=cpt+1;cpt2<next.size();cpt2++)
        {
            if(next[cpt]==next[cpt2])
            {
                next[cpt2].erase();
            }
        }
    }
    vector < vector<string> > nextall;
    nextall.push_back(next);

    // obtenir les premiers suivants

    ind.clear();
    int compteur = 0;
    for(int cpt=0;cpt<nextall.size();cpt++)
    {
        for(int cpt2 = 0;cpt2<nextall[cpt].size();cpt2++)
            {
                if((nextall[cpt][cpt2]!=" ")&&(nextall[cpt][cpt2].length()!=0))
                {
                    for(int cpt3=0;cpt3<Automate[cpt].getTaille();cpt3++)
                    {
                        for(int cpt4=0;cpt4<Automate[cpt].getI(cpt3).length();cpt4++)
                        {
                            if((Automate[cpt].getI(cpt3).at(cpt4)=='.')&&(Automate[cpt].getI(cpt3).length()-1!=cpt4))
                            {
                                if(Automate[cpt].getI(cpt3).substr(cpt4 + 2, nextall[cpt][cpt2].length())==nextall[cpt][cpt2])
                                {
                                    string i = Automate[cpt].getI(cpt3).substr(0 , cpt4) + Automate[cpt].getI(cpt3).substr(cpt4 + 2, nextall[cpt][cpt2].length()) + "." + Automate[cpt].getI(cpt3).substr(cpt4 + 2 + nextall[cpt][cpt2].length(), Automate[cpt].getI(cpt3).length()- cpt4 - 2 - nextall[cpt][cpt2].length());
                                    ind.setI(i);
                                }
                            }
                        }
                    }
                }
                if(ind.getTaille()!=0)
                {
                    int a = Automate.size();
                    stringstream ss;
                    ss << a;
                    string str = ss.str();
                    ind.setNom("I" + str);
                    ind.setPreviousindex(Automate[cpt].getNom());
                    ind.setPreviousletter(nextall[cpt][cpt2]);
                    Automate.push_back(ind);
                    ind.clear();
                    compteur ++;
                }
            }
    }
    string test;





    int finish = 0;


    do{



        //obtenir les symboles suivants

    next.clear();
    for(int cpt = 1;cpt<compteur;cpt++)
    {
        for(int cpt2=0;cpt2<Automate[cpt].getTaille();cpt2++)
        {
            for(int cpt3=0;cpt3<Automate[cpt].getI(cpt2).length();cpt3++)
            {
                if(Automate[cpt].getI(cpt2).at(cpt3) == '.')
                {
                    ok = 0;
                    for(int cpt4=(cpt3+2);cpt4<Automate[cpt].getI(cpt2).length();cpt4++)
                    {
                        if((Automate[cpt].getI(cpt2).at(cpt4)==' ')&&(ok==0))
                        {
                            next.push_back(Automate[cpt].getI(cpt2).substr(cpt3+2, cpt4-cpt3-2));
                            ok = 1;
                        }
                        if((cpt4==Automate[cpt].getI(cpt2).length()-1)&&(ok==0))
                        {
                            next.push_back(Automate[cpt].getI(cpt2).substr(cpt3+2, Automate[cpt].getI(cpt2).length()-1));
                        }
                    }
                }
            }
            for(int cpt5=0;cpt5<next.size();cpt5++)
            {
                for(int cpt6=cpt5+1;cpt6<next.size();cpt6++)
                {
                    if(next[cpt5]==next[cpt6])
                    {
                        next[cpt6].erase();
                    }
                }
            }
        }
        nextall.push_back(next);
        next.clear();
    }

    // Ajouter regle suivante

    for(int cpt = 1 ; cpt<compteur;cpt++)
    {
        ok = 0;
        for(int cpt2 = 0; cpt2 < nextall[cpt].size();cpt2++)
        {
            if(ok==0)
            {
                int taille = Automate[cpt].getTaille();
                for(int cpt3 = 0 ; cpt3 < taille;cpt3++)
                {
                    if((Automate[0].getI(cpt3).substr(0 , nextall[cpt][cpt2].size())==nextall[cpt][cpt2])&&(Automate[0].getI(cpt3).substr(nextall[cpt][cpt2].size(), 1)!="'"))
                    {
                        Automate[cpt].setI(Automate[0].getI(cpt3));
                        ok = 1;
                    }
                }
            }
        }
    }


    // Nouvel index
    compteur = 0;
    for(int cpt=1;cpt<nextall.size();cpt++)
    {
        for(int cpt2 = 0;cpt2<nextall[cpt].size();cpt2++)
        {
            if((nextall[cpt][cpt2]!=" ")&&(nextall[cpt][cpt2].length()!=0))
            {
                for(int cpt3=0;cpt3<Automate[cpt].getTaille();cpt3++)
                {
                    for(int cpt4=0;cpt4<Automate[cpt].getI(cpt3).length();cpt4++)
                    {
                        if((Automate[cpt].getI(cpt3).at(cpt4)=='.')&&(Automate[cpt].getI(cpt3).length()-1!=cpt4))
                        {
                            if(Automate[cpt].getI(cpt3).substr(cpt4 + 2, nextall[cpt][cpt2].length())==nextall[cpt][cpt2])
                            {
                                string i = Automate[cpt].getI(cpt3).substr(0 , cpt4) + Automate[cpt].getI(cpt3).substr(cpt4 + 2, nextall[cpt][cpt2].length()) + "." + Automate[cpt].getI(cpt3).substr(cpt4 + 2 + nextall[cpt][cpt2].length(), Automate[cpt].getI(cpt3).length()- cpt4 - 2 - nextall[cpt][cpt2].length());
                                ind.setI(i);
                            }
                        }
                    }
                }
            }
            if(ind.getTaille()!=0)
            {
                int a = Automate.size();
                stringstream ss;
                ss << a;
                string str = ss.str();
                ind.setNom("I" + str);
                ind.setPreviousindex(Automate[cpt].getNom());
                ind.setPreviousletter(nextall[cpt][cpt2]);
                Automate.push_back(ind);
                ind.clear();
                compteur ++;
            }
        }
    }
        // Supprimer les lignes semblables

        for(int cpt = 0; cpt < Automate.size(); cpt++)
        {
            for(int cpt2 = 0 ; cpt2<Automate[cpt].getTaille();cpt2++)
            {
                for(int cpt3= cpt2+1; cpt3<Automate[cpt].getTaille();cpt3++)
                {
                    if(Automate[cpt].getI(cpt2)==Automate[cpt].getI(cpt3))
                    {
                        Automate[cpt].clear2(cpt3);
                    }
                }
            }
        }

        // Supprimer une partie des index semblables
        for(int cpt = 0; cpt < Automate.size(); cpt++)
        {
            for(int cpt2 = cpt+1;cpt2 < Automate.size();cpt2++)
            {
                ok = 0;
                if(Automate[cpt].getTaille()==Automate[cpt2].getTaille())
                {
                    for(int cpt3=0;cpt3<Automate[cpt].getTaille();cpt3++)
                    {
                        if((Automate[cpt].getI(cpt3)!=" ")&&(Automate[cpt2].getI(cpt3)!=" "))
                           {
                               if(Automate[cpt].getI(cpt3)!=Automate[cpt2].getI(cpt3))
                               {
                                   ok = 1;
                               }
                           }
                    }
                    if(ok==0)
                    {
                        Automate[cpt2].clear();
                    }
                }
            }
        }

        finish++;
    }while(finish<4);




    for(int cpt=0;cpt<Automate.size();cpt++)
    {
        if(Automate[cpt].getNom()!="Inconnu")
           {
               cout << "nom " << Automate[cpt].getNom() << " previndex " << Automate[cpt].getPreviousindex() << " prevletter " << Automate[cpt].getPreviousletter()  << endl;
               for(int cpt2=0;cpt2<Automate[cpt].getTaille();cpt2++)
               {
                   cout << Automate[cpt].getI(cpt2) << endl;
               }
           }
    }


    //RÈcupÈration des terminaux et des non terminaux

    for(int cpt=0; cpt<(int)tab.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)tab[cpt].size(); cpt2++)
        {
            for(int cpt3=0; cpt3<(int)tab.size(); cpt3++)
            {
                if(tab[cpt][cpt2]==tab[cpt3][0]) //Si ce qui est ‡ droite de la flËche = ce qui est ‡ gauche
                {
                    non_terminal=true;
                }
            }
            if(non_terminal==false) //Symboles terminaux
            {
                for(int cpt3=0; cpt3<(int)terminaux.size(); cpt3++)
                {
                    if(tab[cpt][cpt2]==terminaux[cpt3])
                    {
                        terminal_exist=true;
                    }
                }
                if(terminal_exist==false)
                {
                    terminaux.push_back(tab[cpt][cpt2]);
                }
                terminal_exist=false;
            }
            else
            {
                for(int cpt3=0; cpt3<(int)non_terminaux.size(); cpt3++)
                {
                    if(tab[cpt][cpt2]==non_terminaux[cpt3])
                    {
                        non_terminal_exist=true;
                    }
                }
                if(non_terminal_exist==false)
                {
                    non_terminaux.push_back(tab[cpt][cpt2]);
                }
                non_terminal_exist=false;
            }
            non_terminal=false;
        }
    }

    cout << endl << "TERMINAUX : ";
    for(int cpt=0; cpt<(int)terminaux.size(); cpt++)
    {
        cout << terminaux[cpt];
    }

    cout << endl << "NON TERMINAUX : ";
    for(int cpt=0; cpt<(int)non_terminaux.size(); cpt++)
    {
        cout << non_terminaux[cpt];
    }
    cout << endl << endl;

    //Calcul des Premiers

    prem.push_back(tab[0][0] + "'");
    prem.push_back(tab[0][0]);
    P.push_back(prem);
    prem.clear();
    prem.push_back(tab[0][0]);
    prem.push_back(tab[0][1]);

    for(int cpt=1; cpt<(int)tab.size(); cpt++)
    {
        if(tab[cpt].size()!=1)
        {
            if(prem[0]==tab[cpt][0])
            {
                prem.push_back(tab[cpt][1]);
            }
            else
            {
                P.push_back(prem);
                prem.clear();
                prem.push_back(tab[cpt][0]);
                prem.push_back(tab[cpt][1]);
            }
        }
        else if(tab[cpt].size()==1)
        {
            prem.push_back(" ");
        }
    }

    P.push_back(prem);
    prem.clear();

    for(int cpt=0; cpt<(int)P.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)P[cpt].size(); cpt2++)
        {
            if(P[cpt][0]==P[cpt][cpt2])
            {
                P[cpt].erase(P[cpt].begin()+ cpt2);
                cpt2--;
            }
        }
    }

    for(int cpt=0; cpt<(int)P.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)P[cpt].size(); cpt2++)
        {
            for (int cpt3=0; cpt3<(int)non_terminaux.size(); cpt3++)
            {
                if(P[cpt][cpt2]==non_terminaux[cpt3])
                {
                    for(int cpt4=0; cpt4<(int)P.size(); cpt4++)
                    {
                        if(P[cpt4][0]==P[cpt][cpt2])
                        {
                            P[cpt].erase(P[cpt].begin()+ cpt2);
                            for(int cpt5=1; cpt5<(int)P[cpt4].size(); cpt5++)
                            {
                                P[cpt].push_back(P[cpt4][cpt5]);
                            }
                        }
                    }
                }
            }
        }
    }

    for(int cpt=0; cpt<(int)P.size(); cpt++)
    {
        cout << "P(" << P[cpt][0] << ") = {" ;
        for(int cpt2=1; cpt2<(int)P[cpt].size(); cpt2++)
        {
            if(P[cpt][cpt2]==" ") cout << "Epsilon,";
            else cout << P[cpt][cpt2] << ",";
        }
        cout << "}" << endl;
    }


    //Calcul des Suivants

    cout << endl;
    suiv.push_back(tab[0][0]+"'");
    suiv.push_back("$");
    S.push_back(suiv);
    suiv.clear();
    suiv.push_back(P[1][0]);
    suiv.push_back(P[1][0] + "'");

    for(int cpt5=1; cpt5<(int)P.size(); cpt5++)
    {
        suiv.push_back(P[cpt5][0]);
        for(int cpt=0; cpt<(int)tab.size(); cpt++)
        {
            for(int cpt2=1; cpt2<(int)tab[cpt].size(); cpt2++)
            {
                if(tab[cpt][cpt2]==P[cpt5][0])
                {
                    if((cpt2+1)==(int)tab[cpt].size())
                    {
                        suiv.push_back(tab[cpt][0]);
                    }
                    else
                    {
                        for(int cpt3=0; cpt3<(int)P.size(); cpt3++)
                        {
                            if(P[cpt3][0]==tab[cpt][cpt2+1])
                            {
                                for(int cpt4=1; cpt4<(int)P[cpt3].size(); cpt4++)
                                {
                                    suiv.push_back(P[cpt3][cpt4]);
                                }
                            }
                        }
                    }
                }
            }
        }
        S.push_back(suiv);
        suiv.clear();
    }

    for(int cpt=0; cpt<(int)S.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)S[cpt].size(); cpt2++)
        {
            if((S[cpt][0]==S[cpt][cpt2])||(S[cpt][cpt2]==" "))
            {
                S[cpt].erase(S[cpt].begin()+ cpt2);
                cpt2--;
            }
        }
    }

    non_terminaux.push_back(tab[0][0]+"'");

    for(int cpt=0; cpt<(int)S.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)S[cpt].size(); cpt2++)
        {
            for (int cpt3=0; cpt3<(int)non_terminaux.size(); cpt3++)
            {
                if(S[cpt][cpt2]==non_terminaux[cpt3])
                {
                    for(int cpt4=0; cpt4<(int)S.size(); cpt4++)
                    {
                        if(S[cpt4][0]==S[cpt][cpt2])
                        {
                            S[cpt].erase(S[cpt].begin()+ cpt2);
                            for(int cpt5=1; cpt5<(int)S[cpt4].size(); cpt5++)
                            {
                                S[cpt].push_back(S[cpt4][cpt5]);
                            }
                        }
                    }
                }
            }
        }
    }

    for(int cpt=0; cpt<(int)S.size(); cpt++)
    {
        for(int cpt2=1; cpt2<(int)S[cpt].size(); cpt2++)
        {
            for(int cpt3=1; cpt3<(int)S[cpt].size(); cpt3++)
            {
                if((S[cpt][cpt2]==S[cpt][cpt3])&&(cpt2!=cpt3))
                {
                    S[cpt].erase(S[cpt].begin()+ cpt2);
                    cpt2--;
                }
            }
        }
    }

    for(int cpt=0; cpt<(int)S.size(); cpt++)
    {
        cout << "S(" << S[cpt][0] << ") = {" ;
        for(int cpt2=1; cpt2<(int)S[cpt].size(); cpt2++)
        {
            if(S[cpt][cpt2]==" ") cout << "Epsilon,";
            else cout << S[cpt][cpt2] << ",";
        }
        cout << "}" << endl;
    }

    return 0;

}
