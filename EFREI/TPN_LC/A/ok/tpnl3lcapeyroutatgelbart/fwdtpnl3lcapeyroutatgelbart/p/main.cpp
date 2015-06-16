#include <iostream>
#include "GELBART_PEYROUTAT_Language.h"

using namespace std;

bool getFichier(Language*);

int main()
{
    Language* l = new Language;
    while(!getFichier(l));

    /*l->removeRecGDirect();
    l->removeRecGIndirect();
    l->afficher();*/

    l->calculParseurSLR();

    l->afficherSLR();

    list<string> mot;
    mot.push_back("a");
    mot.push_back("a");
    mot.push_back("b");
    mot.push_back("a");
    mot.push_back("b");
    mot.push_back("b");

    cout << endl;

    if (l->testMot(mot))
        cout << "Le mot aababb est reconnu" << endl;
    else
        cout << "Le mot aababb n'est pas reconnu" << endl;

    return 0;
}

bool getFichier(Language* l){

    string fileName;
    cout << "Chemin et nom du fichier : ";
    cin >> fileName;

    while ((fileName.size() < 5)||(fileName.substr(fileName.size()-4, fileName.size()) != ".txt")){

        cout << endl;
        cout << "Veuillez entrer un fichier de la forme monFichier.txt" << endl;
        cout << "Chemin et nom du fichier : ";
        fileName.clear();
        cin >> fileName;
    }

    if (l->lectureFichier(fileName)){

        l->afficher();
        return true;
    }

    cout << "Erreur fichier introuvable / impossible a ouvrir" << endl;
    return false;
}
