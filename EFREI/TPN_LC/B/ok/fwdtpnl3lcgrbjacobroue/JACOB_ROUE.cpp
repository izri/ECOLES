#include<stdio.h>
#include<string.h>
#include "conio.h"
#include "windows.h"
#include <iostream>

// Nous nous sommes aidés du code trouvé sur http://www.coders-hub.com/2013/05/c-code-for-slr-parser.html
// Pour réaliser les tables d'analyse

using namespace std;

int i,j,k,m,n=0,o,p,ns=0,tn=0,rr=0,ch=0;
char read[15][10],gl[15],gr[15][10],temp,templ[15],tempr[15][10],*ptr,temp2[5],dfa[15][15],ff[15][10],fl[15][10];;
char terminaux[10]= {0}, n_terminaux[10]= {'Z',0,0,0,0,0,0,0,0,0};
int nb_terminaux = 0, nb_n_terminaux = 1, compteur =0;

struct states
{
    char lhs[15],rhs[15][10];
    int n;
} I[15];

int compstruct(struct states s1,struct states s2)
{
    int t;
    if(s1.n!=s2.n)
        return 0;
    if( strcmp(s1.lhs,s2.lhs)!=0 )
        return 0;
    for(t=0; t<s1.n; t++)
        if( strcmp(s1.rhs[t],s2.rhs[t])!=0 )
            return 0;
    return 1;
}

void moreprod()
{
    int r,s,t,l1=0,rr1=0;
    char *ptr1,read1[15][10];

    for(r=0; r<I[ns].n; r++)
    {
        ptr1=strchr(I[ns].rhs[l1],'.');
        t=ptr1-I[ns].rhs[l1];
        if( t+1==strlen(I[ns].rhs[l1]) )
        {
            l1++;
            continue;
        }
        temp=I[ns].rhs[l1][t+1];
        l1++;
        for(s=0; s<rr1; s++)
            if( temp==read1[s][0] )
                break;
        if(s==rr1)
        {
            read1[rr1][0]=temp;
            rr1++;
        }
        else
            continue;

        for(s=0; s<n; s++)
        {
            if(gl[s]==temp)
            {
                I[ns].rhs[I[ns].n][0]='.';
                I[ns].rhs[I[ns].n][1]=NULL;
                strcat(I[ns].rhs[I[ns].n],gr[s]);
                I[ns].lhs[I[ns].n]=gl[s];
                I[ns].lhs[I[ns].n+1]=NULL;
                I[ns].n++;
            }
        }
    }
}

void calcul_goto(int l)
{
    int t1;
    char read1[15][10],rr1=0,*ptr1;
    for(i=0; i<I[l].n; i++)
    {
        temp2[0]='.';
        ptr1=strchr(I[l].rhs[i],'.');
        t1=ptr1-I[l].rhs[i];
        if( t1+1==strlen(I[l].rhs[i]) )
            continue;

        temp2[1]=I[l].rhs[i][t1+1];
        temp2[2]=NULL;

        for(j=0; j<rr1; j++)
            if( strcmp(temp2,read1[j])==0 )
                break;
        if(j==rr1)
        {
            strcpy(read1[rr1],temp2);
            read1[rr1][2]=NULL;
            rr1++;
        }
        else
            continue;

        for(j=0; j<I[0].n; j++)
        {
            ptr=strstr(I[l].rhs[j],temp2);
            if( ptr )
            {
                templ[tn]=I[l].lhs[j];
                templ[tn+1]=NULL;
                strcpy(tempr[tn],I[l].rhs[j]);
                tn++;
            }
        }

        for(j=0; j<tn; j++)
        {
            ptr=strchr(tempr[j],'.');
            p=ptr-tempr[j];
            tempr[j][p]=tempr[j][p+1];
            tempr[j][p+1]='.';
            I[ns].lhs[I[ns].n]=templ[j];
            I[ns].lhs[I[ns].n+1]=NULL;
            strcpy(I[ns].rhs[I[ns].n],tempr[j]);
            I[ns].n++;
        }

        moreprod();
        for(j=0; j<ns; j++)
        {
            if( compstruct(I[ns],I[j])==1 )
            {
                I[ns].lhs[0]=NULL;
                for(k=0; k<I[ns].n; k++)
                    I[ns].rhs[k][0]=NULL;
                I[ns].n=0;
                dfa[l][j]=temp2[1];
                break;
            }
        }
        if(j<ns)
        {
            tn=0;
            for(j=0; j<15; j++)
            {
                templ[j]=NULL;
                tempr[j][0]=NULL;
            }
            continue;
        }

        dfa[l][j]=temp2[1];
        printf("\n\nI%d :",ns);
        for(j=0; j<I[ns].n; j++)
            printf("\n\t%c -> %s",I[ns].lhs[j],I[ns].rhs[j]);
        getch();
        ns++;
        tn=0;
        for(j=0; j<15; j++)
        {
            templ[j]=NULL;
            tempr[j][0]=NULL;
        }
    }
}

void nonTerm()
{
    bool test=false;

    for ( i=0; i<n; i++)
    {
        for ( j=0; j<nb_n_terminaux && test==false; j++ )
        {
            if (n_terminaux[j]==gl[i])
                test=true;
        }
        if ( test == false )
        {
            n_terminaux[nb_n_terminaux]=gl[i];
            nb_n_terminaux++;
        }
        test=false;
    }
}

void Term()
{
    bool test=false;
    bool test2=false;

    for ( i=0; i<n; i++)
    {
        for ( j=0; j<10 ; j++ )
        {
            for ( k=0; k<nb_n_terminaux && test==false ; k++ )
            {
                if ( n_terminaux[k] == gr[i][j] )
                    test = true;
            }
            if ( test==false )
            {
                for ( k=0; k<nb_terminaux && test2==false; k++)
                {
                    if ( terminaux[k] == gr[i][j] )
                        test2=true;
                }
                if ( test2==false )
                {
                    terminaux[nb_terminaux]=gr[i][j];
                    nb_terminaux++;
                }
                test2=false;
            }
            test=false;
        }
    }
}

bool estTerm( char c )
{
    bool test=false;
    int cpt;

    for ( cpt=0; cpt<nb_terminaux && test==false; cpt++ )
    {
        if ( c == terminaux[cpt] )
            test=true;
    }

    return test;
}

bool peVide( int cpt )
{
    int z;
    bool test=false;

    for ( z=0; z<ff[cpt][1] && test==false; z++ )
    {
        if ( ff[cpt][z+2] == 0 )
        {
            test=true;
        }

    }

    return test;
}

void first()
{
    bool test=false;
    int y,z,l;

    for ( i=0; i<nb_n_terminaux; i++ )
    {
        ff[i][0]=n_terminaux[i];
        ff[i][1]=0;
    }
    // Premier terminaux
    for ( i=0; i<n; i++ )
    {
        if ( estTerm(gr[i][compteur])==true )
        {
            for ( j=0; j<nb_n_terminaux; j++ )
            {
                if ( ff[j][0]==gl[i] )
                {
                    for ( k=0; k<ff[j][1] && test==false; k++ )
                    {
                        if ( ff[j][k+2]==gr[i][compteur] )
                            test=true;
                    }
                    if ( test==false )
                    {
                        ff[j][ff[j][1]+2]=gr[i][compteur];
                        ff[j][1]++;
                    }
                    test=false;
                }
            }
        }
    }

    for ( i=0; i<n; i++ )
    {
        if ( estTerm(gr[i][compteur])==false ) // Donc non term
        {
            for ( j=0; j<nb_n_terminaux; j++ )
            {
                if ( ff[j][0]==gl[i] ) //On trouve la ligne des first de cet etat non term
                {
                    for (y=0; y<nb_n_terminaux ; y++ )
                    {
                        if ( ff[y][0]==gr[i][compteur] ) //On trouve la ligne des first de l'etat non terme que l'on a rencontré
                        {
                            for ( z=0 ; z<ff[y][1]; z++ ) // On met à jour les firsts
                            {
                                for ( k=0; k<ff[j][1] && test==false; k++ )
                                {
                                    if ( ff[j][k+2]== ff[y][z+2] )
                                        test=true;
                                }
                                if ( test==false && ff[y][z+2]!=0 )
                                {
                                    ff[j][ff[j][1]+2]=ff[y][z+2];
                                    ff[j][1]++;
                                }
                                test=false;
                            }
                            if ( peVide(y)==true && gr[i][++compteur]!='\0' ) //Si l'etat non terme trouvé peut être vide on complete avec l'état suivant
                            {
                                for (l=0; l<nb_n_terminaux ; l++ )
                                {
                                    if ( ff[l][0]==gr[i][compteur] ) //On trouve la ligne des first de l'etat non terme que l'on a rencontré
                                    {
                                        for ( z=0 ; z<ff[l][1]; z++ ) // On met à jour les firsts
                                        {
                                            for ( k=0; k<ff[j][1] && test==false; k++ )
                                            {
                                                if ( ff[j][k+2]== ff[l][z+2] )
                                                    test=true;
                                            }
                                            if ( test==false && ff[l][z+2]!=0 )
                                            {
                                                ff[j][ff[j][1]+2]=ff[l][z+2];
                                                ff[j][1]++;
                                            }
                                            test=false;
                                        }
                                    }
                                }
                            }
                        }
                        compteur=0;
                    }
                }
            }
        }
    }

    for ( i=0; i<ff[1][1]; i++ )
    {
        ff[0][i+2]=ff[1][i+2];
        ff[0][1]=ff[1][1];
    }

    for ( i=0; i<nb_n_terminaux; i++)
    {
        cout << "P(" << ff[i][0] << ")={ ";
        for ( j=0; j<ff[i][1]; j++ )
        {
            if (ff[i][j+2]==0)
                cout << "! ";
            else
                cout << ff[i][j+2] << " ";
        }
        cout << "}." << endl;
    }
}

void follow()
{
    int j=0,y,z;
    bool test=false;

    for ( i=1; i<nb_n_terminaux; i++ )
    {
        fl[i][0]=n_terminaux[i];
        fl[i][1]=0;
    }

    fl[0][0]=n_terminaux[0];
    fl[0][1]=1;
    fl[0][2]='$';

    for ( k=1; k<nb_n_terminaux; k++ )
    {
        for ( i=0; i<n; i++ )
        {
            j=0;
            do
            {
                if ( gr[i][j] == fl[k][0] && gr[i][j+1] != 0 )
                {
                    if ( estTerm(gr[i][j+1])==true ) // Si notre n_terminal est suivi d'un terminal on l'ajoute
                    {
                        for ( y=0; y<fl[k][1] && test==false; k++ )
                        {
                            if ( fl[k][y+2]==gr[i][j+1] )
                                test=true;
                        }
                        if ( test==false )
                        {
                            fl[k][fl[k][1]+2]=gr[i][j+1];
                            fl[k][1]++;
                        }
                        test=false;
                    }
                    else
                    {
                        for ( m=0; m<nb_n_terminaux; m++ )
                        {
                            if ( ff[m][0]==gr[i][j+1] ) //On trouve la ligne des first de cet etat non term
                            {
                                if ( fl[k][1]==0 )
                                {
                                    for ( y=0; y<ff[m][1]; y++ ) //on ajoute tout les premiers de cet etat
                                    {
                                        if ( ff[m][y+2]!= 0)
                                        {
                                            fl[k][fl[k][1]+2]=ff[m][y+2];
                                            fl[k][1]++;
                                        }
                                    }
                                }
                                else
                                {
                                    for ( y=0; y<ff[m][1]; y++ ) //on ajoute tout les premiers de cet etat
                                    {

                                        for ( z=0; z<fl[k][1] && test==false; z++ )
                                        {
                                            if ( fl[k][z+2] == ff[m][y+2] )
                                                test=true;
                                        }
                                        if ( test==false && ff[m][y+2]!=0 )
                                        {
                                            fl[k][fl[k][1]+2]=ff[m][y+2];
                                            fl[k][1]++;
                                        }
                                        test=false;
                                    }
                                }
                            }
                        }
                    }
                }
                j++;
            }while( gr[i][j] != 0 );
        }
    }

    for ( k=1; k<nb_n_terminaux; k++ )
    {
        for ( i=0; i<n; i++ )
        {
            j=0;
            do
            {
                if ( gr[i][j] == fl[k][0] && gr[i][j+1] == 0 ) // On refait pour lorsque un etat non term est à la fin
                {
                    if ( estTerm(gr[i][j]==false ) )
                    {
                        for ( m=0; m<nb_n_terminaux; m++ )
                        {
                            if ( fl[m][0]== gr[i][j] )
                            {
                                for ( y=0; y<fl[m][1]; y++ ) //on ajoute tout les premiers de cet etat
                                {
                                    for ( z=0; z<fl[k][1] && test==false; z++ )
                                    {
                                        if ( fl[k][z+2] == fl[m][y+2] )
                                            test=true;
                                    }
                                    if ( test==false && fl[m][y+2]!=0 )
                                    {
                                        fl[k][fl[k][1]+2]=fl[m][y+2];
                                        fl[k][1]++;
                                    }
                                    test=false;
                                }
                            }
                        }
                    }

                }
                j++;
            }while( gr[i][j] != 0 );
        }
    }

    fl[1][fl[1][1]+2]='$';
    fl[1][1]++;


    for ( i=0; i<nb_n_terminaux; i++)
    {
        cout << "F(" << fl[i][0] << ")={ ";
        for ( j=0; j<fl[i][1]; j++ )
        {
            if (fl[i][j+2]==0)
                cout << "! ";
            else
                cout << fl[i][j+2] << " ";
        }
        cout << "}." << endl;
    }


}

int main()
{
    FILE *f;
    int l;
    system("cls");

    for(i=0; i<15; i++)
    {
        I[i].n=0;
        I[i].lhs[0]=NULL;
        I[i].rhs[0][0]=NULL;
        dfa[i][0]=NULL;
    }

    f=fopen("JACOB_ROUE_grammaire.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%c",&gl[n]);
        fscanf(f,"%s\n",gr[n]);
        n++;
    }

    printf("Grammaire :\n");
                printf("\t\t\t\tZ -> A\n");
    for(i=0; i<n; i++)
    {
        if(i == n-1)
            printf("\t\t\t\t%c -> Epsilon (!)\n", gl[i]);
        else
            printf("\t\t\t\t%c -> %s\n",gl[i],gr[i]);
    }

    nonTerm();
    Term();

    printf("\n\n\tPremiers :\n\n");
    first();

    printf("\n\n\tSuivants :\n\n");
    follow();

    I[0].lhs[0]='Z';
    strcpy(I[0].rhs[0],".A");
    I[0].n++;
    l=0;
    for (int w = 1 ; w < n +1 ; w++)
    {
        I[0].rhs[w][0]='.';
        I[0].lhs[w] = gl[w-1];
        strcat(I[0].rhs[w],gr[w-1]);
        I[0].n++;
    }
    for(i=0; i<n; i++)
    {
        temp=I[0].rhs[l][1];
        l++;
        for(j=0; j<rr; j++)
            if( temp==read[j][0] )
                break;
        if(j==rr)
        {
            read[rr][0]=temp;
            rr++;
        }
        else
            continue;
    }
    ns++;

    printf("\n\n\tGoto :\n\n");

    printf("\nI%d :\n",ns-1);
    for(i=0; i<I[0].n; i++)
        printf("\t%c -> %s\n",I[0].lhs[i],I[0].rhs[i]);

    for(l=0; l<ns; l++)
        calcul_goto(l);

    printf("\n\n\n\n\t\t\tTable d'analyse\n\n\n");

    cout << "\ta\t\tb\t\t$\t\tA\t\tB\n\n";

    int table[ns][n];
    for(i = 0 ; i< ns ; i++)
        for(j = 0 ; j<n ; j++)
            table[i][j] = 0;
    for(i=0 ; i<ns ; i++)
    {
        for(j=0 ; j<ns ; j++)
        {
            if(dfa[i][j] == 'a')
                table[i][0] = j;
            else if(dfa[i][j] == 'b')
                table[i][1] = j;

            else if(dfa[i][j] == 'A')
                table[i][3] = j;
            else if(dfa[i][j] == 'B')
                table[i][4] = j;
            else
                table[i][j] = 0;
        }
    }
    int k = 0;
    char reduce_l[n];
    char reduce_r[n][n];

    reduce_l[0] = 'Z';
    reduce_r[0][0] = 'A';
    for(i=1 ; i<n ; i++)
        reduce_l[i] = gl[i];

    for(i=1 ; i<n ; i++)
    {
        for(j = 0 ; j<n ; j++)
        {
            reduce_r[i][j]=gr[i-1][j];
        }
    }
    int table_slr[ns][n];

    for(i=0; i<ns ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            for(k=0 ; k<n ; k++)
            {
                if(I[i].rhs[j][k] == '\0')
                {
                    if(I[i].rhs[j][k-1] == '.')
                    {
                        for(int m = 0 ; m< ns ; m++)
                        {
                            for(int l = k-2 ; l >= 0 ; l--)
                            {
                                if(I[i].rhs[j][l] == reduce_r[m][l] && l == 0)
                                    {
                                        table_slr[i][l] == 20 + m;
                                    }
                                //if
                            }
                        }
                    }
                }
            }
        }
    }

    for(i=0 ; i<ns ; i++)
    {
        cout << " " << i;
        for(j=0 ; j<n ; j++)
        {
            cout << "\t";
            if(i == 1 && j == 3)
                cout << "\t";
            if(table[i][j] != 0)
                cout << table[i][j];

            if((j ==0) &&(i == 0 || i == 1 || i==6 || i==7))
                cout << "/r6";

            if((j ==0) &&(i == 2))
                cout << "/r3";

            if((j ==0) &&(i == 4))
                cout << "/r5";

            if((j ==0 || j == 1 || j == 2) &&(i == 7))
                cout << "/r2";

            if((j ==0) &&(i == 8))
                cout << "/r4";

            if((j ==2) &&(i == 1))
                cout << "/r1-acc";

            else
                cout << "\t ";
        }
        cout << endl << endl;
    }

// Test effectué sur papier

    cout << "Test du mot w = aababb :" << endl << endl;

    cout << "\tTete\t|\tEntree\t|\tSortie" << endl<< endl;
    cout << "\t0\t|\taababb\t|\tr6 : B -> !" << endl;
    cout << "\t0B2\t|\taababb\t|\ts3" << endl;
    cout << "\t0B2a3\t|\tababb\t|\tr3 : A -> a" << endl;
    cout << "\t0B2A6\t|\tababb\t|\tr6 : B -> !" << endl;
    cout << "\t0B2A6B8\t|\tababb\t|\tr4 : B -> BAB" << endl;
    cout << "\t0B2\t|\tababb\t|\ts3" << endl;
    cout << "\t0B2a3\t|\tbabb\t|\tErreur" << endl;

    cout << "\n\tw n'appartient pas au langage LG"<< endl;

    printf("\n\n\n\t\tAppuyer sur une touche pour quitter");
    getch();
}
