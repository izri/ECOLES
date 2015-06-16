#include "grammaire.h"
#include "Automate_lr.h"
using namespace std;

int main()
{
    grammaire* g(NULL);
    g = new grammaire[1];
    ifstream fichier("grammaire.txt");
    vector <string> pile;
    vector <string*> *first_follow = new vector<string *>;

    //calcul
    int nombre_ligne(0);
    string ligne;
    while(getline(fichier,ligne))
    {
        nombre_ligne++;
    }
    fichier.close();


    lecturefichier(g);

    lecturegrammaire(*g);//affichage de la grammaire stockée
    creationvariable_first_follow(*g,first_follow);
    Automate_lr(g);



//désallocation
    for(std::vector<string*>::iterator it = first_follow->begin(); it != first_follow->end(); ++it)
    {
        delete *it;
    }

    for(int i=0; i<nombre_ligne; i++)
    {
        delete g->production[i];
    }
    delete g->production;
    delete g;
    return 0;
}
