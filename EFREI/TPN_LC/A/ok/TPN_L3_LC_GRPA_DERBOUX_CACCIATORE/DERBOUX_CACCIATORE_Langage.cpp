#include "DERBOUX_CACCIATORE_Langage.h"


   char Langage :: getAxiome()
        {
            return axiome;
        }

      vector<char> Langage :: getRelation(int indice) // INDICE EST la ligne
        {
            vector<char> temp;


            for (int i=0; i<tab[indice].size(); i++)
            {
                temp.push_back(tab[indice][i]);
            }

            return temp;
        }


        int Langage :: getNbRelation()
        {
            return nbrelation;
        }

     Langage :: Langage(string nom){

        nom="langage/"+nom+".txt";//creation chemin
        ifstream fichier(nom.c_str());  // on ouvre LE FICHIER
        if (fichier)
        {
            string ligne;
            char temp;
            getline(fichier, ligne);

            temp=ligne[0]; // on recup pour la liaison avec l'axiome
            tab.push_back(vector<char>(1));
            tab[0][0]='P'; //Axiome
            axiome='P';
            tab[0].push_back(temp);

            for (int i=0; i<ligne.size(); i++) //Suprimer les espace
            {
                if(ligne[i]==' ')
                    ligne.erase(ligne.begin()+i);
            }

                tab.push_back(vector<char>(1));

                tab[1][0]=ligne[0];
            for (int i=1; i<ligne.size(); i++)
            {
                tab[1].push_back(ligne[i]);
            }



            int c=2;
            while( getline(fichier, ligne)) // tant qu'il existe des lignes
            {

                for (int i=0; i<ligne.size(); i++) //Suprimer les espace
                {
                    if(ligne[i]==' ')
                    ligne.erase(ligne.begin()+i);
                }
                //creation de la colone avec les relations
                 tab.push_back(vector<char>(1));
                 tab[c][0]=ligne[0];
                for (int i=1; i<ligne.size(); i++)
                {
                    tab[c].push_back(ligne[i]);
                }
                c++;
            }
            nbrelation=c;
            fichier.close(); // fermeture du fichier

        }
        else
        {
            cout<<"Impossible d'ouvrir le fichier"<<endl;
        }
    }

    void Langage :: afficher()
    {
        for(int i1=0; i1<tab.size(); i1++)
        {
            cout<<tab[i1][0]<<" ";
            for(int i2=1; i2<tab[i1].size();i2++)
            {
                cout<<tab[i1][i2];
            }
            cout<<endl;
        }

    cout<<" AFFICHAGE DES FIRST"<<endl;
    //cout<<"si un first contient une Etat non-terminal alors cela signifie 'les premiers de cet etat'"<<endl;
    /*
    for(int i1=0; i1<first.size(); i1++)
    {
        cout<<"P("<<first[i1][0]<<") = "<<endl;
        for (int i2=1; i2<first[i1].size(); i2++)
        {
            if (isupper(first[i1][i2]))
            {
                cout<<" P("<<first[i1][i2]<<")";

            }
            else
            {
                cout<<" "<<first[i1][i2];
            }
        }
        cout<<endl;

    }
    */

    }

    void Langage :: firstf()
    {

         for(int i1=0; i1<tab.size(); i1++)
        {
            int exist=0;
            if (isupper(tab[i1][0]))
            {
                for(int i2=0; i2<first.size();i2++)
                {
                    if(first[i2][0]==tab[i1][0])
                    {
                        first[i2].push_back(tab[i1][0]);
                        exist=1;
                    }
                }
                if(exist!=1)
                {
                    first.push_back(vector <char> (1));
                    first[first.size()].push_back(tab[i1][0]);
                }
            }
        }
    }

