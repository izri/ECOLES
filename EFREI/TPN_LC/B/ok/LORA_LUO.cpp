#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main() {

    ifstream fichier("grammaire.txt");
    string tab[30];
    char terminal[30];
    char non_terminal[30];
    int cpt=0;



    if ( !fichier )
        cout << "Erreur fichier inexistant";
    else
    {

        string grammaire;
        while(getline(fichier,grammaire))
        {
        tab[cpt]=grammaire;
        cpt++;
        cout << grammaire <<endl;
        }
/*
        while( !fichier.eof() )
        {
            char caractere;
            fichier.get(caractere);   // on lit caract�re par caract�re

            if(caractere>='A' && caractere<='Z') // si c'est un �tat non terminal on le stocke dans le tableau
                                                // des �tats non terminaux
                non_terminal[cpt]=caractere;
                cpt++;
            }
            else                                // sinon on le stocke dans le tableau des �tats  terminaux
            {
                terminal[cpt]=caractere;
                cpt++;
            }

        }
        for(cpt=0;cpt<30;cpt++)          // on affiche les r�sultats
        {
            cout << "Symbole non terminal :" <<endl;
            cout << non_terminal[cpt] << endl;
            cout << "Symbole terminal :"<<endl;
            cout << terminal [cpt] << endl;
        }
*/

    }
    return 0;
}
