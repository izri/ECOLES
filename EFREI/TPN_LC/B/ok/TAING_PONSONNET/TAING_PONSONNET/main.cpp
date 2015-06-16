#include <iostream>
#include <fstream>
#include "Grammaire.h"
#include "Index.h"

using namespace std;

int main()
{
    // Lecture du fichier
    ifstream fichier("LC_TP1.txt", ios::in ); // Nom du fichier à lire

    string nom;
    string production;
    int i;
    string ligne;
    int cpt = 0;

    vector<Grammaire> TabGrammaire;
    Grammaire g;

    // Lecture de la grammaire depuis le fichier txt

    while(getline(fichier, ligne))
    {
        nom = ligne.at(0);

        if(nom != g.getNom())
        {
            if(cpt>0)
            {
                TabGrammaire.push_back(g);
            }
            g.setNom(nom);
            g.SupprProduction();
        }

        if(g.getNom() == nom)
        {
            if(ligne.length() == 1)
            {
                production = ' ';
            }
            else
            {
                production = ligne.substr(2, ligne.length());
            }

            g.addProduction(production);
        }

        cpt = cpt + 1;
    }

    TabGrammaire.push_back(g);

    int cpt2;

    // Affichage de la grammaire

    for(cpt=0;cpt<TabGrammaire.size();cpt++)
    {
        cout << "Nom du terminal : "<< TabGrammaire[cpt].getNom() << endl;
        cout << "Production : " << endl;
        for(cpt2=0;cpt2<TabGrammaire[cpt].tailleProduction();cpt2++)
        {
            cout << TabGrammaire[cpt].getProduction(cpt2) << endl;
        }
    }

    // Elimination de la recursivité gauche
    size_t found;
    int cpt3;
    string premierSymbole;
    for(cpt=0;cpt<TabGrammaire.size();cpt++)
    {
        for(cpt2=0;cpt2<TabGrammaire[cpt].tailleProduction();cpt2++)
        {
            nom =  (TabGrammaire[cpt].getNom());
            premierSymbole = (TabGrammaire[cpt].getProduction(cpt2)).at(0);
            if(nom == premierSymbole)
            {
                TabGrammaire[cpt].addAlpha((TabGrammaire[cpt].getProduction(cpt2)).substr(2, (TabGrammaire[cpt].getProduction(cpt2)).length()));
            }
        }

        if(TabGrammaire[cpt].tailleAlpha() > 0)
        {
            for(cpt2=0;cpt2<TabGrammaire[cpt].tailleProduction();cpt2++)
            {
                found = (TabGrammaire[cpt].getProduction(cpt2)).find(TabGrammaire[cpt].getNom());
                if (found==string::npos)
                {
                    TabGrammaire[cpt].addBeta(TabGrammaire[cpt].getProduction(cpt2));
                }
            }
        }
    }

    vector<Grammaire> TabGrammaire2;
    Grammaire Gtmp, Gtmp2;

    for(cpt=0;cpt<TabGrammaire.size();cpt++)
    {
        if(TabGrammaire[cpt].tailleAlpha() == 0)
        {
            TabGrammaire2.push_back(TabGrammaire[cpt]);
        }
        if(TabGrammaire[cpt].tailleAlpha() > 0)
        {
            Gtmp.setNom(TabGrammaire[cpt].getNom());
            for(cpt2=0;cpt2<TabGrammaire[cpt].tailleBeta();cpt2++)
            {
                Gtmp.addProduction(TabGrammaire[cpt].getBeta(cpt2)+" "+Gtmp.getNom()+"'");
            }
            TabGrammaire2.push_back(Gtmp);
            Gtmp2.setNom(Gtmp.getNom()+"'");
            for(cpt2=0;cpt2<TabGrammaire[cpt].tailleAlpha();cpt2++)
            {
                Gtmp2.addProduction(TabGrammaire[cpt].getAlpha(cpt2)+" "+Gtmp2.getNom());
            }
            Gtmp2.addProduction(" ");
            TabGrammaire2.push_back(Gtmp2);
        }
    }

    cout << endl;
    cout << "Elimination de la recursivite gauche : " << endl << endl;
    for(cpt=0;cpt<TabGrammaire2.size();cpt++)
    {
        cout << "Nom du terminal : "<<TabGrammaire2[cpt].getNom() << endl;
        cout << "Production : " << endl;
        for(cpt2=0;cpt2<TabGrammaire2[cpt].tailleProduction();cpt2++)
        {
            cout << TabGrammaire2[cpt].getProduction(cpt2) << endl;
        }
    }
    cout << endl;

    // SLR
    cout << "SLR : " << endl << endl;

    vector<Index> TabIndex;
    Index index;

    cout << "Creation de l'automate : " << endl << endl;

    // Initialisation de I0
    index.setNom(0);
    index.addRegles(TabGrammaire[0].getNom()+"' . "+TabGrammaire[0].getNom());
    for(cpt=0;cpt<TabGrammaire.size();cpt++)
    {
        for(cpt2=0;cpt2<TabGrammaire[cpt].tailleProduction();cpt2++)
        {
            index.addRegles(TabGrammaire[cpt].getNom()+" . "+TabGrammaire[cpt].getProduction(cpt2));
        }
    }
    TabIndex.push_back(index);

    for(cpt=0;cpt<TabIndex.size();cpt++)
    {
        cout << "Nom de l'index : " << TabIndex[cpt].getNom() << endl;
        cout << "Regles : " << endl;
        for(cpt2=0;cpt2<TabIndex[cpt].tailleRegles();cpt2++)
        {
            cout << TabIndex[cpt].getRegles(cpt2) << endl;
        }
    }
    cout << endl;

    size_t m;
    int verif;
    Arc a;
    cpt3=0;
    cpt=0;
    // Création des autres index a partir de I0
    // Detection du symbole apres le point
    vector<string> next;

    while(cpt<TabIndex.size())
    {
        cpt2=0;
        while(cpt2<TabIndex[cpt].tailleRegles())
        {
            found = (TabIndex[cpt].getRegles(cpt2)).find(".");

            found = found + 2;
            m = found+1;
            verif = 0;

            for(cpt3=m;cpt3<(TabIndex[cpt].getRegles(cpt2)).length();cpt3++)
            {
                if(((TabIndex[cpt].getRegles(cpt2)).at(cpt3) == ' '))
                {
                    verif = 1;
                }

                else if(verif == 0)
                {
                    m++;
                }
            }



            if((TabIndex[cpt].getRegles(cpt2)).length() > 0)
            {
                next.push_back((TabIndex[cpt].getRegles(cpt2)).substr(found, m-found)); // symbole apres le point
                cout << "Symbole apres le point : "<< next[cpt2] << endl;

                /*int verif2 = 0;

                string tmp;
                tmp = TabIndex[cpt].getRegles(cpt2);
                tmp.replace(found-2, found+1, next+". ");

                for(cpt3=0;cpt3<TabIndex[cpt].tailleArcs();cpt3++)
                {
                    if(next == TabIndex[cpt].getArc(cpt3).getType())
                    {
                        TabIndex[TabIndex[cpt].getArc(cpt3).getIndexFinal()].addRegles(tmp);
                        verif2 = 1;
                    }
                }

                if(verif2 == 0)
                {
                    Arc arc;
                    arc.setIndexInitial(TabIndex[cpt].getNom());
                    arc.setIndexFinal(TabIndex.size());
                    arc.setType(next);
                    TabIndex[cpt].addArc(arc);

                    i.setNom(TabIndex.size());
                    i.addRegles(tmp);
                    TabIndex.push_back(i);
                }

                if(next == (TabIndex[cpt].getRegles(cpt2)).substr(0, 1))
                {
                    i.setNom(TabIndex[TabIndex.size()-1].getNom()+1);
                    i.addRegles(TabIndex[cpt].getRegles(cpt2));
                    TabIndex.push_back(i);
                }*/
            }
            cpt2++;
        }
        cpt++;
    }

    // Calcul des premiers

    cout << endl;
    cout << "Calcul des premiers : " << endl;

    cout << "Premier ( "<<TabGrammaire[0].getNom()+"'" << " ) = ";
    cout << "Premier ( " << next[0] << " )" << endl;

    cpt3 = 1;
    int cpt4;
    int test;
    for(cpt=0;cpt<TabGrammaire.size();cpt=cpt++)
    {
        for(cpt2=0;cpt2<TabGrammaire[cpt].tailleProduction();cpt2++)
        {
            test = 0;
            cout << "Premier ( " << (TabGrammaire[cpt].getNom()) << " ) = ";
            for(cpt4=0;cpt4<TabGrammaire.size();cpt4++)
            {
                if(next[cpt3] == TabGrammaire[cpt4].getNom())
                {
                    test = 1;
                }
            }
            if(test == 1)
            {
                cout << "Premier ( ";
            }
            cout << next[cpt3];
            if(test == 1)
            {
                cout << " )";
            }
            cout << endl;
            cpt3++;
        }
    }

    return 0;
}
