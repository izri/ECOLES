#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DERBOUX_CACCIATORE_Langage.h"
#include "DERBOUX_CACCIATORE_Interfa.h"
#include "DERBOUX_CACCIATORE_Automate.h"

using namespace std;

int main()
{

    string fichier;
    cout<<"BIENVENUE DANS LE DESAMBIGUEUR GRAMMATICAL"<<endl;
    cout<<"Quel fichier voulez vous ouvrir ? (exemple : 01)"<<endl;
    cin>>fichier;
     Langage l(fichier);
     l.afficher();
     cout<<endl;
        Automate a(&l);
        a.ConstruireAuto();


     /*
     Interfa i0(&l);
    cout<<endl;
    Automate a;
    i0.construireI0();
    a.setAutomate(i0);
    i0.afficher();
    */

}
