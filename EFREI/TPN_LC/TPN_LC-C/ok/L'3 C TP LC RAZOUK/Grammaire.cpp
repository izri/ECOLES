#include "Grammaire.h"




Grammaire::Grammaire(string nomFichier){
    if(!openFromFile(nomFichier)){
        ErrorWhileOpening myex;
        throw myex;
    }
}


bool Grammaire::estTerminal(char c){
    return find(non_terminaux.begin(), non_terminaux.end(), c) == non_terminaux.end();
}

bool Grammaire::openFromFile(string nomFichier){

    char line[256];

    ifstream in;
    in.open(nomFichier.c_str());
    if(!in.is_open()){
        cerr << "Grammaire::openFromFile : Erreur lors de l'ouverture de " << nomFichier << "." << endl;
        return false;
    }

    // Récupération du start symbol
    start_symbol = in.peek();
    // cout << "Start symbol : " << start_symbol << endl;

    // Lecture de la grammaire
    while(!in.eof()){
        Regle regle;
        in.getline(line, 256);

        if(line[0] < 'A' || line[0] > 'Z'){
            cerr << "Grammaire::openFromFile : le caractere " << line[0] << "n'est pas un non terminal." << endl;
            return false;
        }
        regle.part_gauche = line[0];

        if(find(non_terminaux.begin(), non_terminaux.end(), line[0]) == non_terminaux.end())
            non_terminaux.push_back(line[0]);

        for(int i = 1; line[i] != '\0' && i < 256; i++){
            if(line[i] != ' '){
                regle.part_droite.push_back(line[i]);
            }
        }

        regles.push_back(regle);
    }

    /* list<Regle>::iterator it;
    for(it = regles.begin(); it != regles.end(); it++)
        cout << (*it).part_gauche << " " << (*it).part_droite << endl;

    list<char>::iterator it2;
    for(it2 = non_terminaux.begin(); it2 != non_terminaux.end(); it2++)
        cout << (*it2);
    cout << endl;
*/
    return true;
}



bool Grammaire::writeToFile(string nomFichier){
    ofstream out;
    out.open(nomFichier.c_str());

    if(!out.is_open()){
        cerr << "Grammaire::writeToFile : Erreur lors de l'ouverture de " << nomFichier << "." << endl;
        return false;
    }


    list<Regle>::iterator it;
    string::iterator it2;
    for(it = regles.begin(); it != regles.end(); it++){
        out << (*it).part_gauche;
        for(it2 = (*it).part_droite.begin(); it2 != (*it).part_droite.end(); it2++){
            out << " " << (*it2);
        }

        out << endl;
    }

    return true;
}

int Grammaire::index(char c){
    return distance(non_terminaux.begin(), find(non_terminaux.begin(), non_terminaux.end(), c));
}

list<char> Grammaire::calculPremiers(char c, bool *visite){
    if(visite[index(c)]){
        return premiers[index(c)];
    }
    else{
        for(list<Regle>::iterator it = regles.begin(); it != regles.end(); it ++){
            if(it->part_gauche == c){
                if(estTerminal(it->part_droite[0])){
                    premiers[index(c)].push_back(it->part_droite[0]);
                }
                else{
                    list<char> tmp;
                    int i = 0;
                    do{
                        tmp = calculPremiers(it->part_droite[i], visite);
                        premiers[index(c)].insert(premiers[index(c)].end(), tmp.begin(), tmp.end());
                        i++;
                    } while (find(tmp.begin(), tmp.end(), NULL) != tmp.end()); // NULL représente epsilon
                }
            }
        }
    }

    return premiers[index(c)];
}


vector<list <char> > Grammaire::calculPremiers(){
    premiers.clear();
    premiers.reserve(non_terminaux.size());
    bool *visite = new bool[non_terminaux.size()];
    for(int i = 0; i < non_terminaux.size(); i++) visite[i] = false;

    for(list<char>::iterator it = non_terminaux.begin(); it != non_terminaux.end(); it++){
        visite[distance(non_terminaux.begin(), it)] = true;

        for(list<Regle>::iterator it2 = regles.begin(); it2 != regles.end(); it2 ++){
            visite[distance(non_terminaux.begin(), it)] = true;

            if(it2->part_gauche == *it){
                if(estTerminal(it2->part_droite[0])){
                    premiers[distance(non_terminaux.begin(), it)].push_back(it2->part_droite[0]);
                }
                else{
                    list<char> tmp;
                    int i = 0;
                    do{
                        tmp = calculPremiers(it2->part_droite[i], visite);
                        premiers[distance(non_terminaux.begin(), it)].insert(premiers[distance(non_terminaux.begin(), it)].end(), tmp.begin(), tmp.end());
                        i++;
                    } while (find(tmp.begin(), tmp.end(), NULL) != tmp.end()); // NULL représente epsilon
                }
            }
        }

    }

    return this->premiers;
}
