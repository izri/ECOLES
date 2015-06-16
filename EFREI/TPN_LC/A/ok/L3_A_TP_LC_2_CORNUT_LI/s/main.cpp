#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

bool String_Non_Present(vector<string> ter, string tmp)
{
    for(unsigned int i = 0; i < ter.size(); i++)
    {
        if(tmp == ter[i])
            return false;
    }
    return true;
}

int etat_existe(vector<vector<string> > table_etat, vector<string> etat)
{
    for(unsigned int i = 0; i < table_etat.size(); i++)
        if(table_etat[i] == etat)
            return i;

    return -1;
}

bool symbole_deja_passe(vector<string> symbole, string alpha)
{
    for(unsigned int i = 0; i < symbole.size(); i++)
        if(symbole[i] == alpha)
            return true;

    return false;
}

int Non_Terminal_Present( vector<string> premier, vector<string> ter)
{

    for(unsigned int i = 0; i < premier.size(); i++)
    {
        for(unsigned int j = 0; j < ter.size(); j++)
        {
            if(premier[i] == ter[j])
                return i;
        }
    }
    return -1;

}

vector<string> premier(string A, vector<string> grammaire)
{
    istringstream iss;
    vector<string> prem;
    string tmp;

    for(unsigned int i = 0; i < grammaire.size(); i++)
    {
        iss.clear();
        iss.str(grammaire[i].c_str());
        iss >> tmp;

        if(tmp == A)
        {
            iss >> tmp;
            if(tmp != A)
                prem.push_back(tmp);
        }
    }
    return prem;
}

void calcul_first_follow(vector<string> grammaire, vector<string> ter, vector<vector<string> > &first, vector<vector<string> > &follow)
{
    ///Premier
    int pos;
    string tmp;
    vector<string> passe;
    for(unsigned int i = 0; i < ter.size(); i++)
    {
        first.push_back(premier(ter[i],grammaire));
    }

    for(unsigned int i = 0; i < first.size(); i++)
    {
        passe.clear();
        while((pos = Non_Terminal_Present(first[i],ter)) != -1)
        {
            tmp = first[i][pos];
            first[i].erase(first[i].begin() + pos);

            if(String_Non_Present(passe,tmp))
            {
                for(unsigned int j = 0; j < ter.size(); j++)
                    if(ter[j] == tmp)
                        pos = j;

                for(unsigned int j = 0; j < first[pos].size(); j++)
                    if(String_Non_Present(first[i],first[pos][j]) && first[pos][j] != tmp)
                        first[i].push_back(first[pos][j]);
            }
            passe.push_back(tmp);
        }
    }

    cout << "Premier : " << endl;
    for(unsigned int i = 0; i < first.size(); i++)
    {
        cout << ter[i] << " : ";
        for(unsigned int j = 0; j < first[i].size(); j++)
        {
            cout << first[i][j] << " ";
        }
        cout << endl;
    }

    ///Follow

    istringstream iss, ist;
    string pere;
    vector<string> suivant(1,"$");
    follow.push_back(suivant);

    for(unsigned int i = 1; i < ter.size(); i++)
    {
        suivant.clear();
        for(unsigned int j = 0; j < grammaire.size(); j++)
        {
            iss.clear();
            iss.str(grammaire[j].c_str());

            iss >> pere;
            iss >> tmp;


            while(iss)
            {
                if(tmp == ter[i])
                {
                    pos = -1;
                    if(iss >> tmp)
                    {
                        for(unsigned int k = 0; k < ter.size(); k++)
                            if(ter[k] == tmp)
                                pos = k;

                        if(pos != -1)
                        {
                            for(unsigned int k = 0; k < first[pos].size(); k++)
                            {
                                if(first[pos][k] != "vide" && String_Non_Present(suivant,first[pos][k]))
                                {
                                    suivant.push_back(first[pos][k]);
                                }
                                else if(first[pos][k] == "vide" && String_Non_Present(suivant,tmp))
                                {
                                    suivant.push_back(tmp);
                                }
                            }
                        }
                        else
                        {
                            suivant.push_back(tmp);
                        }

                    }
                    else
                    {
                        if(pere != ter[i])
                            suivant.push_back(pere);
                    }
                }
                else
                {
                    iss >> tmp;
                }
            }
        }
        follow.push_back(suivant);
    }

    for(unsigned int i = 0; i < follow.size(); i++)
    {
        while((pos = Non_Terminal_Present(follow[i],ter)) != -1)
        {
            tmp = follow[i][pos];
            follow[i].erase(follow[i].begin() + pos);

            for(unsigned int j = 0; j < ter.size(); j++)
                if(ter[j] == tmp)
                    pos = j;

            for(unsigned int j = 0; j < follow[pos].size(); j++)
                if(String_Non_Present(follow[i],follow[pos][j]) && follow[pos][j] != ter[i])
                    follow[i].push_back(follow[pos][j]);
        }
    }

    cout << endl << "Suivant : " << endl;
    for(unsigned int i = 0; i < follow.size(); i++)
    {
        cout << ter[i] << " : ";
        for(unsigned int j = 0; j < follow[i].size(); j++)
        {
            cout << follow[i][j] << " ";
        }
        cout << endl;
    }
}

void afficherpile(stack<string> pile)
{
    cout << endl << "Pile : ";
    while(!pile.empty())
    {
        cout << pile.top();
        pile.pop();
    }
}

bool Analyse(stack<string> pile, vector<vector<vector<string> > > table_analyse, vector<string> idsymbol, vector<string> grammaire, string mot)
{
    stack<string> pile_mod;
    string tmp = pile.top();
    int etat;
    istringstream ist(tmp);
    ist >> etat;

    stringstream ss;
    ss << mot[0];
    int pos = -1;

    for(unsigned int i = 0; i < idsymbol.size(); i++)
        if(idsymbol[i] == ss.str())
            pos = i;
    if(pos == -1)
        return false;

    if(!table_analyse[etat][pos].empty())
    {
        unsigned int cpt = 0;
        string mot_mod;
        do
        {
            pile_mod = pile;
            afficherpile(pile);
            cout << " Mot : " << mot;
            int shift;
            ist.clear();
            ist.str(table_analyse[etat][pos][cpt].c_str());

            if(ist >> shift)
            {
                cout << " Regle utilise : Shift " << table_analyse[etat][pos][cpt];

                mot_mod = mot.substr(1,mot.size());

                //pile.push(mot[0]);
                pile_mod.push(table_analyse[etat][pos][cpt]);
            }
            else
            {
                cout << " Regle utilise : " << table_analyse[etat][pos][cpt];

                if(table_analyse[etat][pos][cpt] == "R0")
                {
                    return true;
                }
                else
                {
                    unsigned int regle = 0, taille = 0, etat2 = 0;
                    mot_mod = mot;
                    tmp = table_analyse[etat][pos][cpt].substr(1,table_analyse[etat][pos][cpt].size());

                    ist.clear();
                    ist.str(tmp.c_str());
                    ist >> regle;

                    ist.clear();
                    ist.str(grammaire[regle].c_str());

                    ist >> tmp;

                    taille = (grammaire[regle].size() - tmp.size() - 1)/2;

                    for(unsigned int i = 0; i < taille; i++)
                    {
                        pile_mod.pop();
                    }

                    for(unsigned int i = 0; i < idsymbol.size(); i++)
                        if(idsymbol[i] == tmp)
                            taille = i;

                    tmp = pile_mod.top();
                    istringstream ist(tmp);
                    ist >> etat2;

                    pile_mod.push(table_analyse[etat2][taille][0]);
                }
            }

            if(table_analyse[etat][pos].size() != 1)
                cout << " AMBIGUITE";

            if(Analyse(pile_mod,table_analyse,idsymbol,grammaire,mot_mod))
                return true;
            else
            {
                cpt++;
            }

        }while(cpt != table_analyse[etat][pos].size());

        if(cpt == table_analyse[etat][pos].size())
        {
            return false;
        }


        return true;
    }
    else
    {
        afficherpile(pile);
        cout << " Mot : " << mot << " IMPASSE" << endl;
        return false;
    }
}


int main()
{
    vector<string> grammaire;
    vector<string> idsymbol;
    vector<string> ter;

    vector<vector<string> > first;
    vector<vector<string> > follow;

    ifstream fichier("g.txt");
    string tmp;

    if(fichier)
    {
        while(getline(fichier,tmp))
        {
            grammaire.push_back(tmp);
            //cout << tmp << endl;
            istringstream iss(tmp);

            iss >> tmp;

            if(String_Non_Present(ter,tmp))
            {
                ter.push_back(tmp);
            }

            /*for(unsigned int i = 0; i <ter.size();i++)
                cout << ter[i];
            cout << endl;*/

            while(iss)
            {
                if(String_Non_Present(idsymbol,tmp) && tmp != "vide")
                {
                    idsymbol.push_back(tmp);
                }
                iss >> tmp;
            }
        }

        idsymbol.push_back("$");

        istringstream iss(grammaire[0]);
        iss >> tmp;
        grammaire.insert(grammaire.begin(),tmp + "' " + tmp);
        ter.insert(ter.begin(),tmp + "'");

        cout << "Grammaire : " << endl;
        for(unsigned int i = 0; i < grammaire.size(); i++)
        {
            cout << grammaire[i] << endl;
        }
        cout << endl;

        ///grammaire avec A' -> A Axiome

        calcul_first_follow(grammaire,ter,first,follow);

        ///Ajout des points pour l'etat 0
        for(unsigned int i = 0; i < grammaire.size();i++)
        {
            iss.clear();
            iss.str(grammaire[i].c_str());
            iss >> tmp;

            grammaire[i] = tmp + " ." + grammaire[i].substr(tmp.size()+1,grammaire[i].size());
            //grammaire[i].insert(grammaire[i].begin()+2,'.');

            if(grammaire[i].substr(tmp.size()+2,grammaire[i].size()) == "vide")
                grammaire[i] = grammaire[i].substr(0,tmp.size()+2);
        }

        cout << endl <<"Etat 0 : " << endl;
        for(unsigned int i = 0; i < grammaire.size(); i++)
        {
            cout << grammaire[i] << endl;
        }
        cout << endl;

        cout << endl << "Listes des Non terminaux : ";
        for(unsigned int i = 0; i < ter.size(); i++)
        {
            cout << endl << ter[i];
        }

        cout << endl << endl << "Liste des symboles : ";
        for(unsigned int i = 0; i < idsymbol.size(); i++)
        {
            cout << endl << idsymbol[i];
        }

        //Création de notre Etat 0 soit notre grammaire
        vector<vector<string> > table_etat(1,grammaire);

        vector<vector<vector<string> > > table_analyse(1,vector<vector<string> >(idsymbol.size()));

        queue<int> file;
        file.push(0);

        while(!file.empty())
        {
            int etat = file.front();
            vector<string> symboldejavisite;
            file.pop();

            for(unsigned int i = 0; i < table_etat[etat].size();i++)
            {
                istringstream ist(table_etat[etat][i]);
                string alpha = "";
                string nouvelle_regle;
                int pos;

                vector<string> nouvelle_etat;

                ist >> tmp;

                while(ist)
                {
                    if(!(pos = tmp.find('.')))
                    {
                        alpha = tmp.substr(pos+1,tmp.size());

                        if(!alpha.empty())
                        {
                            nouvelle_regle = nouvelle_regle + alpha + " .";
                        }
                    }
                    else
                    {
                        nouvelle_regle = nouvelle_regle + tmp + " ";
                    }
                    ist >> tmp;
                }

                if(!alpha.empty())
                {
                    if(!symbole_deja_passe(symboldejavisite,alpha))
                    {
                        symboldejavisite.push_back(alpha);
                        nouvelle_etat.push_back(nouvelle_regle);
                        //cout << endl << "Nouvelle etat : \n" << nouvelle_regle;

                        for(unsigned int j = i+1; j < table_etat[etat].size() ;j++ )
                        {
                            string beta = "";
                            nouvelle_regle.clear();
                            ist.clear();
                            ist.str(table_etat[etat][j].c_str());

                            ist >> tmp;

                            while(ist)
                            {
                                if(!(pos = tmp.find('.')))
                                {
                                    beta = tmp.substr(pos+1,tmp.size());

                                    if(!beta.empty())
                                    {
                                        nouvelle_regle = nouvelle_regle + beta + " .";
                                    }
                                    else
                                    {
                                        nouvelle_regle = nouvelle_regle + ".";
                                    }
                                }
                                else
                                {
                                    nouvelle_regle = nouvelle_regle + tmp + " ";
                                }
                                ist >> tmp;
                            }

                            if(beta == alpha)
                            {
                                nouvelle_etat.push_back(nouvelle_regle);
                                //cout << endl << nouvelle_regle;
                            }
                        }
                        //cout << endl;

                        vector<string> regle_deja_ajoute;
                        unsigned int k = 0;

                        while( k < nouvelle_etat.size())
                        {
                            string ceta = "";
                            ist.clear();
                            ist.str(nouvelle_etat[k].c_str());

                            ist >> tmp;

                            while(ist)
                            {
                                if(!(pos = tmp.find('.')))
                                {
                                    ceta = tmp.substr(pos+1,tmp.size());
                                }
                                ist >> tmp;
                            }

                            if(!ceta.empty() && !String_Non_Present(ter,ceta) && String_Non_Present(regle_deja_ajoute,ceta))
                            {
                                //cout << "Regle a ajouter : " << ceta << endl;
                                regle_deja_ajoute.push_back(ceta);

                                for(unsigned int l = 0; l < table_etat[0].size(); l++)
                                {
                                    ist.clear();
                                    ist.str(table_etat[0][l].c_str());
                                    ist >> tmp;

                                    if(ceta == tmp)
                                    {
                                        nouvelle_etat.push_back(table_etat[0][l]);
                                    }
                                }
                            }
                            k++;
                        }
                    }
                }
                else
                {
                    ist.clear();
                    ist.str(nouvelle_regle.c_str());

                    ist >> tmp;
                    nouvelle_regle = tmp + " ." + nouvelle_regle.substr(tmp.size()+1,nouvelle_regle.size());

                    if(nouvelle_regle[nouvelle_regle.size()-1] == ' ')
                        nouvelle_regle = nouvelle_regle.substr(0,nouvelle_regle.size()-1);

                    pos = -1;

                    unsigned int j = 0;
                    bool trouve = false;
                    string reduce = "";

                    ist.clear();

                    while( j < grammaire.size() && trouve == false)
                    {
                        if(nouvelle_regle == grammaire[j])
                        {
                            pos = j;
                            trouve = true;
                            ist.str(grammaire[j].c_str());
                            ist >> tmp;
                        }
                        j++;
                    }

                    if(pos != -1)
                    {
                        stringstream ss;
                        ss << pos;
                        reduce = "R" + ss.str();

                        j = 0;
                        trouve = false;
                        pos = -1;
                        while(j < ter.size() && trouve == false)
                        {
                            if(ter[j] == tmp)
                            {
                                pos = j;
                                trouve = true;
                            }
                            j++;
                        }

                        if(pos != -1)
                        {
                            for(j = 0; j < follow[pos].size(); j++)
                            {
                                int pos2;
                                for(unsigned int m = 0; m < idsymbol.size(); m++)
                                    if(idsymbol[m] == follow[pos][j])
                                        pos2 = m;

                                table_analyse[etat][pos2].push_back(reduce);
                            }
                        }
                    }
                }


                if(-1 == etat_existe(table_etat,nouvelle_etat) && !nouvelle_etat.empty())
                {
                    table_etat.push_back(nouvelle_etat);
                    file.push(table_etat.size()-1);
                    table_analyse.push_back(vector<vector<string> >(idsymbol.size()));

                    for(unsigned int m = 0; m < idsymbol.size(); m++)
                        if(idsymbol[m] == alpha)
                            pos = m;

                    stringstream ss;
                    ss << table_etat.size()-1;
                    //cout << ss.str();

                    table_analyse[etat][pos].push_back(ss.str());
                }
                else if((pos = etat_existe(table_etat,nouvelle_etat)) != -1)
                {
                    stringstream ss;
                    ss << pos;

                    for(unsigned int m = 0; m < idsymbol.size(); m++)
                        if(idsymbol[m] == alpha)
                            pos = m;

                    table_analyse[etat][pos].push_back(ss.str());
                }

            }
        }

        cout << endl << "Table des Etats : " << endl;
        for(unsigned int i = 0; i < table_etat.size(); i++)
        {
            cout << endl << "Etat : " << i << endl;
            for(unsigned int j = 0; j < table_etat[i].size(); j++)
                cout << table_etat[i][j] << endl;
        }

        cout << endl << endl << "Table d'analyse : " << endl;
        cout << endl;
        for(unsigned int i = 0; i < table_analyse.size(); i++)
        {
            cout << i << " |";
            for(unsigned int j = 0; j < table_analyse[i].size(); j++)
            {
                cout << idsymbol[j] << " : ";
                for(unsigned int l = 0; l < table_analyse[i][j].size(); l++)
                {
                    cout << table_analyse[i][j][l] << " ";
                }
                 cout << "|";
            }
            cout << endl;
        }



        ///Analyse
        cout << endl << endl;

        stack<string> pile;
        string mot = "abb";

        cout << "Saisir un mot : ";
        cin >> mot;

        pile.push("0");

        cout << "Regle : " << endl;
        for(unsigned int i = 0; i < grammaire.size(); i++)
        {
            cout << grammaire[i] << " R" << i <<endl;
        }

        if(Analyse(pile,table_analyse,idsymbol,grammaire,mot+"$"))
        {
            cout << endl << endl << "Le mot : " << mot <<" fait bien partit du Vocabulaire" << endl;
        }
        else
        {
            cout << endl << endl <<"Le mot : " << mot <<" ne fait pas partit du Vocabulaire" << endl;
        }
    }
    else
        cout << " Erreur de chargement du fichier ";

    return 0;
}
