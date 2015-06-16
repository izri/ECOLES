#include "DERBOUX_CACCIATORE_Interfa.h"
#include "DERBOUX_CACCIATORE_Automate.h"

void Interfa :: setrelation(char r, int indice)
{
    if(indice==relation.size())
    {
        relation.push_back(vector<char>(1));
    }
    relation[indice].push_back(r);
    //relation[indice][relation[indice].size()]=r;
}

    bool Interfa :: equal(Interfa inter)
    {
        if(relation==inter.relation)
        {
            return true;

        }
        return false;

    }

    void Interfa ::  afficher()
    {
        for(int i1=0; i1<relation.size(); i1++)
        {
            cout<<relation[i1][1]<<" ";
            for(int i2=2; i2<relation[i1].size();i2++)
            {
                cout<<relation[i1][i2];
            }
            cout<<endl;
        }

        for(int i=0; i<intersuivante.size(); i++)
        {
            cout<<intersuivante[i][0];
            cout<<intersuivante[i][1];
        }
        cout<<endl;
    }



    int Interfa :: getnbrelation()
    {
        return relation.size();
    }
    int Interfa :: getnbrelation(int indice)
    {
        return relation[indice].size();
    }

    char Interfa :: getrelation(int i1, int i2)
    {
        return relation[i1][i2];
    }
    vector <char> Interfa :: getrelation(int i1)
    {

        return relation[i1];
    }

void Interfa :: setintersuivante(char lie, int indice)
{
    intersuivante.push_back(vector<char>(1));
    intersuivante[intersuivante.size()-1][0]=lie; // notre ligne prend la lettre
    intersuivante[intersuivante.size()-1].push_back(indice); // la colonne prend l'indice
}

    void Interfa :: setRelation(vector<char> colonne)
    {
        relation.push_back(vector<char> (1));
        for (int i=1; i<colonne.size();i++)
        {
            if(colonne[i]=='.' && i+1<colonne.size()) // on permute le point
            {
                relation[relation.size()-1].push_back(colonne[i+1]);
                relation[relation.size()-1].push_back('.');
                i++;
            }
            else{
                relation[relation.size()-1].push_back(colonne[i]);
            }
        }
    }
    void Interfa :: setRelation(vector<char> colonne, int a)
    {
        relation.push_back(vector<char> (1));
        relation[relation.size()-1].push_back(colonne[0]);
        relation[relation.size()-1].push_back('.');
        for (int i=1; i<colonne.size();i++)
        {
                relation[relation.size()-1].push_back(colonne[i]);
        }
    }


