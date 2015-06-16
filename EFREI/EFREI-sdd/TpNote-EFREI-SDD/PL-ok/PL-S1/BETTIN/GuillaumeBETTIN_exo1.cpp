#include <iostream>
#include "nombre.h"

using namespace std;

LSCnombre ajouter_nb(LSCnombre liste, int nomb)
{
    nombre* nouveaunombre = new(nombre);
    nouveaunombre->nb=nomb;
    nouveaunombre->suivant=NULL;

    if(liste==NULL)
    {
        return nouveaunombre;
    }
    else
    {
        nombre* temp=liste;
        while(temp->suivant!=NULL)
        {
            temp=temp->suivant;
        }
        temp->suivant=nouveaunombre;
        return liste;
    }
}

void afficherliste(LSCnombre liste)
{
    nombre *temp = liste;
    while(temp != NULL)
    {
        cout<<temp->nb<<endl;
        temp=temp->suivant;
    }
}



int main()
{
  LSCnombre liste=NULL;
    int i, n;
    cout<<"Saisissez un entier n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        liste = ajouter_nb(liste, i);
    }
    afficherliste(liste);


    return 0;
}
