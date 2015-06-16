#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool recudirect(vector<string> gramaire)
{
    bool recu = false;
    int i = 1;

    while(i < gramaire.size() && recu == false)
    {
        if(gramaire[0] == gramaire[i].substr(0,gramaire[0].size()))
            recu = true;
        i++;
    }
    return recu;
}

void afficher(vector<vector<string> > gramaire)
{
   for(unsigned int i = 0; i < gramaire.size();i++)
    {
        for(unsigned int j = 0; j < gramaire[i].size(); j++)
        {
            cout << " " << gramaire[i][j];
        }
        cout << endl;
    }
}

int main()
{
    ifstream fichier("test.txt");
    string nonter, ter;
    int cpt;
    vector<vector<string> > gramaire;

    if(fichier)
    {
        cpt = 0;
        fichier >> nonter;
        gramaire.push_back(vector<string>(1,nonter));
        while(nonter != "$")
        {
            fichier >> ter;
            if(nonter == gramaire[cpt][0])
            {
                gramaire[cpt].push_back(ter);
            }
            else
            {
                gramaire.push_back(vector<string>(1,nonter));
                cpt++;
                gramaire[cpt].push_back(ter);
            }
            fichier >> nonter;
        }

        afficher(gramaire);

        cout << endl;

        string prime = "'";
        string tmp;

        unsigned int i;
        i = 0;

        while(i < gramaire.size())
        {
            /*=====Suppression de la recursivité gauche indirecte=====*/
            for(unsigned int j = 0; j < i; j++)
            {
                for(unsigned int k = 1; k < gramaire[j].size(); k++)
                {
                   if(gramaire[j][0] == gramaire[i][k].substr( 0, gramaire[i][0].size()))
                   {
                       for(unsigned int l = 1; l < gramaire[j].size() ;l++)
                       {
                           if(l == 1)
                           {
                               tmp = gramaire[i][k].substr(gramaire[i][0].size() ,gramaire[i][k].size());
                               gramaire[i][k] = gramaire[j][l] + tmp;
                           }
                           else
                           {
                               gramaire[i].push_back((gramaire[j][l] + tmp));
                           }

                       }
                   }
                }
            }

            /*====Suppression de la recursivité directe=====*/
            if(recudirect(gramaire[i]))
            {
                if(i < gramaire.size() - 1 )
                    gramaire.insert(gramaire.begin() + i+1,vector<string>(1,gramaire[i][0]+prime));
                //else
                    //gramaire.push_back(vector<string>(1,gramaire[i][0]+prime));

                /*for(unsigned int j = 1; j < gramaire[i].size();j++)
                {
                    if(gramaire[i][0] == gramaire[i][j].substr(0,gramaire[i][0].size()))
                    {
                        //gramaire[i+1].push_back(gramaire[i][j].substr(gramaire[i][0].size(),gramaire[i][j].size()) + gramaire[i][0] + prime);
                        //j--;
                        //gramaire[i].erase(gramaire[i].begin() +j+1);
                    }
                    else
                    {
                        gramaire[i][j] = gramaire[i][j] + gramaire[i][0] + prime;
                    }
                }*/
            }
            i++;
        }
        afficher(gramaire);
    }
    else
        cout << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}
