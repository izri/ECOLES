#include "DERBOUX_CACCIATORE_Automate.h"

int  Automate :: setAutomate(Interfa inter)
    {
        for (int i=0; i<autom.size(); i++)
        {
            if(autom[i].equal(inter)) // si il existe déjà on ne le crée pas
            {
                return i;
            }
        }

        autom.push_back(inter);

        return autom.size();
    }

    Automate :: Automate(Langage *langage)
    {
        l=langage;
    }

    void Automate ::  ConstruireI0()
    {
        Interfa i0;
        for(int i=0; i<l->getNbRelation(); i++)
        {
            vector<char>temp;
            temp=l->getRelation(i);
            i0.setrelation(temp[0], i);
            i0.setrelation('.', i);

            for(int i2=1; i2<temp.size(); i2++)
            {
                i0.setrelation(temp[i2], i);
            }

        }
        autom.push_back(i0);// crzation de l'interface

    }

void Automate :: ConstruireAuto()
{
        //Interfa i0(&l);
        ConstruireI0();
        suivant(autom[0]);

        for(int i=0; i<autom.size();i++)
        {
            cout<<endl<<endl<<"I"<<i<<endl;
            autom[i].afficher();
            //suivant(autom[i]);
        }

}

    void Automate ::  suivant(Interfa inter)
    {
        for(int i1=0; i1<inter.getnbrelation(); i1++)
        {
            char precedent;
            for (int i2=1; i2<inter.getnbrelation(i1);i2++)
            {
                precedent=inter.getrelation(i1, i2-1);
                if (precedent=='.' && inter.getrelation(i1, i2)!='€' )
                {
                    //on lit le cara qui doit être lu
                   int indice=ConstruireIn(inter ,inter.getrelation(i1, i2));
                    inter.setintersuivante(inter.getrelation(i1,i2),indice);
                }
            }

        }
    }


    int Automate :: ConstruireIn(Interfa inter ,char lecture)
    {
        Interfa in;

        for(int i1=0; i1<inter.getnbrelation(); i1++)
        {
            for (int i2=1;i2< inter.getnbrelation(i1);i2++)
            {
                char precedent=inter.getrelation(i1, i2-1);
                if (precedent=='.' && inter.getrelation(i1, i2)==lecture)
                {
                    //on copie la colone et on fait avancer le point
                    vector <char> temp;
                    temp = inter.getrelation(i1);
                    in.setRelation(temp);
                }
            }
        }

        //on doit maintenant ajouter les régles des Etat non terminaux
        int nbrelationL=l->getNbRelation();
        int nbrelation= in.getnbrelation();

        for(int i1=0; i1<nbrelation; i1++)
        {

            for (int i2=1; i2<in.getnbrelation(i1);i2++)
            {

                char precedent=in.getrelation(i1, i2-1);
                if (precedent=='.' && isupper(in.getrelation(i1, i2)))//char est MAJ
                {

                    // on va chercher dans l les régles qui commence par notre relation [i1][i2]
                    for (int i3=0; i3<nbrelationL; i3++)
                    {
                        vector <char>temp;
                        temp=l->getRelation(i3);
                        if(temp[0]==in.getrelation(i1, i2))
                        {
                            in.setRelation(temp, 1);
                        }
                    }
                }
            }
        }
        int indice=setAutomate(in);
        cout<<indice<<endl;
        return indice;
    }
