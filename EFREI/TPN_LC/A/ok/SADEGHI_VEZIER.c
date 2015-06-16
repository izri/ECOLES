#include <iostream.h>
#include <fstream.h>
#include <vector.h>
#include <sstream.h>
#include <queue.h>
#include <string.h>

using namespace std;

int main()
{
    cout << "Veuillez rentrer votre grammaire dans un fichier nomme G01.txt svp." << endl << endl;
    cout << "Dans la situation actuelle, l'automate SLR ne peut pas etre genere..." << endl;
    cout << "De meme, les First et Follow ne peuvent etre trouves... :(" << endl;
    cout << "Nous vous invitons a regarder les ebauches de code apparaissant en commentaires,";
    cout << "meme si ceux-ci ne fonctionnent pas totalement..." << endl << endl << endl;

    ifstream fichier( "G01.txt" );
    string ligne;
    vector<string> grammaire;
    vector<string> symboles;
    vector<string> symboles_diff;
    vector<string> non_terminaux;
    vector<string> non_terminaux_diff;
    vector<string> terminaux;

    cout << "Grammaire rentree:" << endl;
    while ( getline( fichier, ligne, '\n' ) )
    {
        // affichage de la ligne à l'écran
        cout << ligne << endl;

        // récupération du premier symbole de la ligne
        istringstream nt(ligne);
        string snt;
        nt >> snt;
        non_terminaux.push_back(snt);

        // remplissage du tableau de grammaire
        grammaire.push_back(ligne);
    }

    for(int i=0;i<grammaire.size();i++)
    {
        // recuperation de tous les symboles

        istringstream iss(grammaire[i]);

        while (iss)
        {
            string s;
            iss >> s;
            symboles.push_back(s);
        }
    }
    cout << endl;
    cout << endl;

/// Remplissage de la liste des symboles non terminaux différents

    for(int i=0;i<non_terminaux.size();i++)
    {
        bool existe=0;
        for(int j=0;j<non_terminaux_diff.size();j++)
        {
            if (non_terminaux.at(i)== non_terminaux_diff.at(j))
            {
                existe=1;
            }
        }
        if (existe==0)
        {
            non_terminaux_diff.push_back(non_terminaux.at(i));
        }
    }

/// Remplissage de la liste des symboles différents

    for(int i=0;i<symboles.size();i++)
    {
        bool existe=0;
        for(int j=0;j<symboles_diff.size();j++)
        {
            if (symboles.at(i)== symboles_diff.at(j))
            {
                existe=1;
            }
        }
        if (existe==0)
        {
            symboles_diff.push_back(symboles.at(i));
        }
    }

/// Remplissage de la liste des terminaux

    for(int i=0;i<symboles_diff.size();i++)
    {
        bool existe=0;
        for(int j=0;j<non_terminaux_diff.size();j++)
        {
            if (symboles_diff.at(i)== non_terminaux_diff.at(j))
            {
                existe=1;
            }
        }
        if (existe==0)
        {
            terminaux.push_back(symboles_diff.at(i));
        }
    }

/// Affichage de la liste des symboles différents

    cout << "Liste des symboles differents:" << endl;

    for(int i=0;i<symboles_diff.size();i++)
    {
        cout<<symboles_diff.at(i)<<" ";
    }

    cout << endl;
    cout << endl;


/// Affichage de la liste des symboles non terminaux différents

    cout << "Liste des symboles non terminaux differents:" << endl;

    for(int i=0;i<non_terminaux_diff.size();i++)
    {
        cout<<non_terminaux_diff.at(i)<<" ";
    }

    cout << endl;
    cout << endl;

/// Affichage de la liste des terminaux

    cout << "Liste des symboles terminaux differents:" << endl;

    for(int i=1;i<terminaux.size();i++)
    {
        cout<<terminaux.at(i)<<" ";
    }

    cout << endl;
    cout << endl;


    ///****************DEUXIEME PARTIE, AUTOMATE SLR**************************///

/// Ajout de la règle A A'


    string premier_non_terminal = non_terminaux_diff.at(0);
    string premiere_regle_SLR;
    string premier_prime;

    premier_prime = premier_non_terminal+"'";
    premiere_regle_SLR = premier_prime+" "+premier_non_terminal;

    grammaire.push_back(premiere_regle_SLR);

    terminaux.push_back(premier_prime);

    // equivalent à grammaire.insert(grammaire.begin() , premiere_regle_SLR);

/// Remplissage de tab_regle

    vector<string> tab_regle(grammaire.size());

    // Replacement de la règle A' A en début de tableau

    tab_regle[0] = grammaire.at(grammaire.size()-1);

    for(int i=1;i<grammaire.size();i++)
    {
        tab_regle[i]=grammaire.at(i-1);
    }

/// Affichage de la table de regles

    cout << "Table de regles:" << endl;

    for(int i=0;i<tab_regle.size();i++)
    {
        cout<<tab_regle.at(i)<<" --- ";
    }

    cout << endl;
    cout << endl;

/// Remplissage de tab_etat

    vector<string> etat_i;
    vector<vector<string> > tab_etat;

    /// Definition de l'etat 0
    for(int i=0;i<tab_regle.size();i++)
    {
       etat_i.push_back(tab_regle.at(i));
    }

    cout << "Etat 0:" << endl;

    // ajout du point aux bonnes positions

    for(int i=0;i<etat_i.size();i++)
    {
        if (etat_i[i].substr(1,1)!=" ")
        {
            etat_i[i].insert(etat_i[i].begin()+3,'.');
            if (etat_i[i].substr(3,etat_i[i].size())=="null")
            {
                etat_i[i]= etat_i[i].substr(0,3);
            }
            cout<<etat_i.at(i)<< endl;
        }
        else
        {
            etat_i[i].insert(etat_i[i].begin()+2,'.');
            if (etat_i[i].substr(3,etat_i[i].size())=="null")
            {
                etat_i[i]= etat_i[i].substr(0,3);
            }
            cout<<etat_i.at(i)<< endl;
        }

/// Definition des autres etats
/*
        istringstream pt(etat_i[i]);
        while (pt)
        {
                string spt;
                pt >> spt;

                vector<string> alpha;

               if(spt.at(0)=='.')
                {
                    alpha.push_back(spt.substr(1,spt.size());
                    cout << alpha << endl;
                }

        }
*/
    }

/*
    tab_etat.push_back(etat_i);


    queue <int> file;

    file.push(0);

    while(!file.empty())
    {
        int etat = file.front();

        for(unsigned int i = 0; i < tab_etat[etat].size(); i++)
        {
            int pos_point = tab_etat[etat][i].find('.');
            tab_etat[etat][i].substr(pos_point,)
        }

    }

*/

    ///****************TROISIEME PARTIE, FIRST ET FOLLOWS**************************///
/*
/// Détermination des first

    vector<vector<string> > first;
    string symbole_actuel;
    string non_terminal_actuel;
    bool terminal;

        for(int i=0;i<grammaire.size()-1;i++)  // -1 pour ne pas prendre la règle A A'
        {
            symbole_actuel=grammaire[i].substr(2,1)
            while (terminal == false)
            {

                for(int j=0;j<terminaux.size();j++)
                {
                    if (symbole_actuel == terminaux[j])
                    {
                        terminal = true;
                        first[i].push_back(symbole_actuel); // à modifier pour retomber sur la chaine correspondant au non terminal concerné
                    }
                }
                if (terminal=false)
                {
                    non_terminal_actuel = symbole_actuel;

                    for(int k=0;k<grammaire.size()-1;k++)
                    {
                        if (non_terminal_actuel==grammaire[k].substr(1,1))  // on cherche la prochaine règle commencant par notre non terminal
                        {
                            symbole_actuel=grammaire[k].substr(2,1);
                        }
                    }

                }
            }
        }
*/

}


