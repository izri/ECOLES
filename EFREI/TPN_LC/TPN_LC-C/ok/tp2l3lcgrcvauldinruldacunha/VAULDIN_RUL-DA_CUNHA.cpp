#include <iostream>
#include <fstream>

using namespace std;

int main()
{

     char lecture[50];
     char car=' ';
     char nonterm[50];//non termianux en général
     char term[50];//terminaux
     char nontermgauche[50];//non terminaux des parties gauches des règles
     char nontermdroite[50];//non terminaux des parties gauches des règles
     for (int cpt = 0; cpt < 50; cpt++)
     {
         nonterm[cpt] = 'z';
         term[cpt] = 'z';
         lecture[cpt] = 'z';
         nontermgauche[cpt] = 'z';
         nontermdroite[cpt] = 'z';
     }




    // std::string ligne;

     ifstream lectureFichier("VAULDIN_RUL-DA_CUNHA.txt");
     int cpt = 0, i=0;
     lectureFichier >> car;//nombre de lignes
     cout << "La grammaire G consideree est composee des " << car << " regles suivantes:" << endl;



     while( !lectureFichier.eof() )
     {  i++;



              lectureFichier>>car;//premier caract


                    {
                        lecture[cpt]=car;

                        cpt++;
                     }



             }
             for(int c=0; c<50; c++)
     {
         if(c< (cpt-1))
            {
                if (lecture[c] == '!'){cout << endl;}
                else{cout<<lecture[c] << " ";
            }

         }

     }
     cout << endl;
     cout << endl;


    for (int p = 0; p < 50; p++)
     {
         if(lecture[p] >= 'A' &&  lecture[p] <= 'Z'  || lecture[p] == '!')
         {
           nonterm[p] = lecture[p];
         }
         else if (lecture[p] != '!'  && lecture[p] != ' ')
         {
             term[p] = lecture[p];
         }
     }


    cout << "Liste des non terminaux: " << endl;
     for (int p = 0; p < 50; p++)
     {
         if (nonterm[p] != 'z'  &&  nonterm[p] != '!')
         {
            cout << nonterm[p] << " ";
         }

     }

     cout << endl;
     cout << endl;

    cout << "Liste des terminaux: " << endl;
     for (int p = 0; p < 50; p++)
     {
         if (term[p] != 'z')
         {
             cout << term[p] << " ";
         }
     }
     cout << endl;
     cout << endl;


//////////////////////////
//création tableau des non terminaux des règles de gauche

    cout << "Non terminaux des membres de gauche: " << endl;

    nontermgauche[0] = nonterm[0];
    cout << nontermgauche[0] << " ";

    for (int p = 1; p < 50; p++)
     {
         if (nonterm[p] != 'z')
         {
             if (nonterm[p-1] == '!' )
             {
                nontermgauche[p] = nonterm[p];
             }
                 if (nontermgauche[p] != '!'  && nontermgauche[p] != 'z')
                    {cout << nontermgauche[p] << " ";}


         }
     }


     cout << endl;
     cout << endl;

//////////////////////////
//création tableau des non terminaux des règles de droite
     /*cout << "Non terminaux des membres de droite: " << endl;

     char temp;
     for (int cpt = 1; cpt < 15; cpt++)
     {
         if (nonterm[cpt] == '!')//si on est sur une case '!'
         {
             temp = nonterm[cpt+1];//le caractère suivant est le membre gauche


             if (nonterm[cpt+2] < 'Z'  &&  nonterm[cpt+2] > 'A')//si après le membre de gauche
             {                                              //on rencontre un non terminal, on le stocke
                for (int i = 0; i < 15; i++)
                {
                    nontermdroite[i] = nonterm[cpt+2];
                    cout << nontermdroite[i];
                }
             }
         }
         else
         {
             if (nonterm[cpt-1] == '!')
             {

             }
         }

     }*/


     cout << endl;
     cout << endl;

    ///////////////////////////////////////////////////////
    //les suivants

    cout << "Les suivants:" << endl;
    int c = 1;
    int temp = 0;

    for (int cpt = 0; cpt < 50; cpt++)
    {
        if (nontermgauche[cpt] != '!'  &&  nontermgauche[cpt] != 'z')
        {
            cout << "Suivants(" << nontermgauche[cpt] << ") = ";

            while (term[c] != 'z')
            {
                c++;
            }
            //term[c] == 'z'
            temp = c;
            c++;

            while (term[temp] != 'z' || term[c] != 'z')
            {
                c++;
                temp = c;
            }
            cout << term[temp-1] << endl;
                cout << endl;

            c++;
            temp = c;

        }




    }
    cout << endl;



 return 0;




}






