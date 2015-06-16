#include <iostream>

using namespace std;

typedef struct nombre
{
    int n;
    nombre *next;
}nombre;

void initialiserlist(nombre **liste, int n)
{
    int x;
    nombre *temp = NULL;
    *liste = ((nombre*)malloc(sizeof(nombre)));
    temp = *liste;
    temp->n = 2;
    for(x=3; x<=n; x++)
    {
        temp->next = ((nombre*)malloc(sizeof(nombre)));
        temp = temp->next;
        temp->n = x;
    }
    temp->next = NULL;
}

void afficher(nombre **liste)
{

    nombre *temp;
    temp = *liste;
    do
    {
        cout << temp->n << endl;
        temp = temp->next;
    }while (temp->next != NULL);
    cout << temp->n << endl;
}

void nparfait(nombre **liste)
{
     int x, i, test,test2;
     x = 0;
    nombre *temp, *temp2;
    temp = *liste;
    temp2 = *liste;

    do
    {
        test = temp->n;
        test2 = temp->n;
        for (i=1; i<(temp->n)-1; i++)
        {

           if((test2%i) == 0)
            {
                test = test - i;
            }


        }

        if (test == 0)
        {
             temp = temp->next;
             temp2 = temp2->next;
        }
        else
        {
            temp2->next = temp->next;
            temp = temp->next;
        }
        i=0;

        x = x + 1;
    }while (temp->next != NULL);
    temp2->next = NULL;
}




int main()
{
    int n;
    n=500;
    nombre *liste, *temp;
    initialiserlist( &liste,n);
    cout << "la liste de depart est:"<<endl;
    afficher(&liste);
    nparfait(&liste);
    cout << "les nombres parfait sont:"<<endl;
    afficher(&liste);

    return 0;
}



