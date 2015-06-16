#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ifstream grammaire;
    ofstream zero_recursivite;
    vector <string> Gram;
    vector <string> newGram;
    char variable[10];
    int i = 0;
    int nb_line = 0;
    int var1 = 0;
    string Test;
    vector <char> carac;
    vector <char> first;
    vector <char> follow;
    bool compare = false;
    vector<string>::iterator it;


    grammaire.open("grammaire_donnee.txt", ios::in);

    int var_gram = 0;

    for(int i=0; i<10; i++){
        variable[i] = '-';
    }
    if(grammaire){
        string word;
        //récupération des lignes de la grammaire
        while(getline(grammaire, word)){
            Gram.push_back(word);
            i++;
        }
        grammaire.close();
        //Traitement des lignes

       while(nb_line != Gram.size()){
            Test = Gram.at(nb_line);
            // on récupère dans le tableau variable la variable de la ligne courante
            if((variable[var1] != Test.at(0)) && (nb_line > 0)){
                var1++;
            }

            variable[var1] = Test.at(0);

            int a = 0;
            while(a != Test.size()){
                compare = false;
                //On rempli le vector carac de tous les éléments de la grammaire en évitant les doublons
                if((Test.at(a)) != ' '){
                    for(int u = 0; u < carac.size(); u++){
                        if(Test.at(a) == carac.at(u)){
                            compare = true;
                        }
                    }
                    if(!compare){
                        carac.push_back(Test.at(a));
                        // on reconnait si une variable dérive le mot vide
                        if(Test.at(a) == '@'){
                            cout << "la variable: " << variable[var1] << " derive le mot vide" << endl;
                        }
                    }
                }
                a++;
            }
            // on supprime tous les espaces du vector carac pour ne garder que
            // les symboles terminaux et non terminaux de la grammaire
            for(int u = 0; u < Test.size(); u++){
                while(Test.at(u) == ' '){
                    Test.erase(u,1);
                };
            }

            for(int u = 0; u < carac.size(); u++){
                for(int j=0; j < 10; j++){
                    if(carac.at(u) == variable[j]){
                        carac.at(u) = '#';
                    }
                }
            }

            newGram.push_back(Test);
            nb_line++;
        }

        //on ajoute le symbole de fin de lecture à la grammaire
        carac.push_back('$');

        cout << "\nElements terminaux de la grammaire: ";
        for(int u = 0; u < carac.size(); u++){
            if((carac.at(u) != '#') && (carac.at(u) != '@')){
                cout << carac.at(u) << "  ";
            }
        }
        cout << "\nElements non terminaux de la grammaire: ";
        for(int i=0; i<10; i++){
            if(variable[i] != '-'){
               cout << variable[i] <<"  ";
            }
        }
        cout << endl;
        it = newGram.begin();
        while(it != newGram.end()){
            int taille;
        taille = (*it).size();
          cout << *it << endl;
          for(int i=0; i<10; i++){
            if(variable[i] != '-'){
               if((*it).at(0) == variable[i])
                    cout << "First " << variable[i] << " : ";
            }
          }


            first.push_back((*it).at(1));
            cout << (*it).at(1)<< endl;


            for(int u = 0; u < carac.size(); u++){
                if((carac.at(u) != '#') && (carac.at(u) != '@')){
                    if((*it).at(taille-1) == carac.at(u)){
                        follow.push_back((*it).at(taille-1));
                        cout << "Follow : " << (*it).at(taille-1) << endl;
                    }
            //bloc qui devrait contenir le code des follow dans le cas
            //où l'élément final n'est pas terminal, mais ne fonctionne pas
                    /*else{
                        follow.push_back(first.at());
                        cout << "Follow du first: " << first.at() << endl;
                    }*/
                }
            }
            ++it;
        };

    }
    else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
    return 0;
}
