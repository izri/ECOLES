#include"iostream"
#include"stdio.h"
#include"windows.h"

using namespace std;
char G[20][20];     //use a matrix to store grammar G
int  length[20];    //length use to store each formula's length
int  number = 0;
bool tempofinput[150];  //buffer of input
char str_vn[20];        //put all vn into it
int  size_vn = 0;
char str_vt[150];       //put all vt into it
int  size_vt = 0;
bool first_vn[30][150];
char buffer[50];           //Used to store the generatedSLR
int  bsize = 0;

struct thri
{
    int beg;
    int nex;
    char ch;
};
thri trans[200];
int  size_trans = 0;

/*
definition of item sets
*/
struct proj
{
    int formula_numb;
    int part;
    char expc;
};

proj    items[100][100];
int     Ccount = 0;
int     size_item[100];

void Read_G()
{
    cout<<"input the number:"<<endl;
    cin >> number;   //user should give the number of formula first
    for(int i = 1; i <= number; i++)
    {
        cout<<"input the syntaxe:"<<endl;
        char temp;
        int j = 0;
        cin >> temp;
        while(temp != '$')
        {
            tempofinput[temp] = true;
            G[i][j++] = temp;
            cin >> temp;
        }
        length[i] = j;
    }

    G[0][0] = 'S';
    G[0][1] = G[1][0];
    length[0] = 2;

    for(int i = 0; i < 64; i++)
        if(tempofinput[i])
            str_vt[size_vt++] = i;
    for(int i = 91; i < 128; i++)
        if(tempofinput[i])
            str_vt[size_vt++] = i;
    for(int i = 65; i < 91; i++)
        if(tempofinput[i])
            str_vn[size_vn++] = i;
    /*for(int i = 0; i < size_vn; i++)
        cout << str_vn[i] << ";";
    cout << endl << endl;
    cout << "size:" << size_vt << endl;
    for(int i = 0; i < size_vt; i++)
        cout << str_vt[i] << ";";
    cout << endl;
    */

}

void get_first()
{
    bool flag1;
    do
    {
        flag1 = false;
        for(int i = 1; i <= number; i++)
        {
            int t = 1;
            bool flag2 = false;
            do
            {
                flag2 = false;
                if (G[i][t] >= 'A' && G[i][t] <= 'Z')
                {
                    for(int k = 0; k < 64; k++)
                        if(first_vn[G[i][t]-'A'][k] == true && !first_vn[G[i][0]-'A'][k])
                        {
                            first_vn[G[i][0]-'A'][k] = true;
                            flag1 = true;
                        }
                    for(int k = 91; k < 128; k++)
                        if(first_vn[G[i][t]-'A'][k] == true && !first_vn[G[i][0]-'A'][k])
                        {
                            first_vn[G[i][0]-'A'][k] = true;
                            flag1 = true;
                        }
                    if(first_vn[G[i][t]-'A'][64] == true)
                    {
                        t++;
                        flag2 = true;
                    }
                }
                else if(!first_vn[G[i][0]-'A'][ G[i][t] ])
                {
                    first_vn[G[i][0]-'A'][ G[i][t] ] = true;
                    flag1 = true;
                }
            }
            while(flag2 && t < length[i]);
            if(t == length[i])
                first_vn[G[i][0]-'A'][26] = true;
        }

    }
    while(flag1);
}
/*Determine whether the project in the project episode */
bool is_in(proj temp,int T)
{
    for(int i = 0; i < size_item[T]; i++)
        if(temp.formula_numb == items[T][i].formula_numb && temp.part == items[T][i].part && temp.expc == items[T][i].expc)
            return true;
    return false;
}

void  gete_expc(proj temp)
{
    bsize = 0;
    bool flag;
    int tt = temp.part;
    do
    {
        flag = false;
        if(tt+1 >= length[temp.formula_numb])
        {
            buffer[bsize++] = temp.expc;
            return;
        }
        else if(G[temp.formula_numb][tt+1] < 'A' || G[temp.formula_numb][tt+1] > 'Z')
        {
            buffer[bsize++] = G[temp.formula_numb][tt+1];
            return;
        }
        else if(G[temp.formula_numb][tt+1] >= 'A' && G[temp.formula_numb][tt+1] <= 'Z')
        {
            for(int i = 0; i < 64; i++)
            {
                if(first_vn[ G[temp.formula_numb][tt+1]-'A' ][i])
                    buffer[bsize++] = i;
            }
            for(int i = 91; i < 128; i++)
            {
                if(first_vn[ G[temp.formula_numb][tt+1]-'A' ][i])
                    buffer[bsize++] = i;
            }
            if(first_vn[ G[temp.formula_numb][tt+1]-'A' ][64])
            {
                tt++;
                flag = true;
            }
        }

    }
    while(flag);
}

void e_closure(int T)
{
    //cout << "T: " << T << "," << size_item[T] << endl;

    for(int i = 0; i < size_item[T]; i++)
    {
        proj temp;
        if(G[items[T][i].formula_numb][items[T][i].part] >= 'A' && G[items[T][i].formula_numb][items[T][i].part] <= 'Z')
        {
            for(int j = 0; j < 20; j++)
                if(G[j][0] == G[items[T][i].formula_numb][items[T][i].part])
                {
                    gete_expc(items[T][i]);
                    for(int k = 0; k < bsize; k++)
                    {
                        temp.formula_numb = j;
                        temp.part = 1;
                        temp.expc = buffer[k];
                        if(!is_in(temp,T))
                            items[T][size_item[T]++] = temp;
                    }
                    bsize = 0;
                }
        }
    }
    /*     for(int i = 0; i < size_item[T]; i++)
              printf("%d , %d , %c\n",items[T][i].formula_numb,items[T][i].part,items[T][i].expc);
         cout << "***************************************" << endl;
    */

    return ;
}

int is_contained()
{
    for(int i = 0; i < Ccount; i++)
    {
        int s = 0;        //recording how much is a matching
        if(size_item[i] == size_item[Ccount])
            for(int j = 0; j < size_item[Ccount]; j++)
            {
                for(int k = 0; k < size_item[i]; k++)
                    if((items[Ccount][j].formula_numb == items[i][k].formula_numb) && (items[Ccount][j].part == items[i][k].part) && (items[Ccount][j].expc == items[i][k].expc))
                    {
                        s++;
                        break;
                    }
            }
        if(s == size_item[Ccount])
            return i;
    }
    return 0;
}

void go()
{
    proj init;
    init.expc = '#';
    init.formula_numb = 0;
    init.part = 1;
    items[0][0] = init;
    size_item[0]++;

    e_closure(0);

    cout << "I0:" << endl;
    for(int i = 0; i < size_item[0]; i++)
        printf("%d , %d , %c\n",items[0][i].formula_numb,items[0][i].part,items[0][i].expc);
    cout << "***************************************" << endl;

    bool beginflag = true;

    for(int index = 0; (index < Ccount) || beginflag ; index++)
    {
        beginflag = false;
        for(int j = 0; j < size_vt; j++)
        {
            proj    buf[50];
            int     buf_size = 0;
            proj    tp;

            int ccc = 0;
            for(int p = 0; p < size_item[index]; p++)
            {
                if((items[index][p].part < length[ items[index][p].formula_numb ]) && ( G[ items[index][p].formula_numb ][ items[index][p].part ] == str_vt[j]) )
                {
                    tp.formula_numb = items[index][p].formula_numb;
                    tp.expc = items[index][p].expc;
                    tp.part = items[index][p].part+1;
                    buf[buf_size++] = tp;
                    //ccc++;
                }
            }
            printf("//I%d ----- %c:\n",index,str_vt[j]);

            if(buf_size  != 0)
            {
                Ccount++;
                for(int t = 0; t < buf_size; t++)
                {
                    items[Ccount][ size_item[Ccount]++ ] = buf[t];
                }

                e_closure(Ccount);

                int  next_state = is_contained();  //See item sets generated by the project is already set in the family

                if(next_state != 0)
                {
                    size_item[Ccount] = 0;
                    Ccount--;
                    trans[size_trans].beg = index;
                    trans[size_trans].nex = next_state;
                    trans[size_trans].ch = str_vt[j];
                    size_trans++;
                }
                else
                {
                    cout << "I" << Ccount << ":" << endl;
                    for(int i = 0; i < size_item[Ccount]; i++)
                        printf("%d , %d , %c\n",items[Ccount][i].formula_numb,items[Ccount][i].part,items[Ccount][i].expc);
                    cout << "***************************************" << endl;
                    trans[size_trans].beg = index;
                    trans[size_trans].nex = Ccount;
                    trans[size_trans].ch = str_vt[j];
                    size_trans++;
                }

            }

        }                //For every grammar terminator


        for(int j = 0; j < size_vn; j++)
        {
            proj    buf[50];
            int     buf_size = 0;
            proj    tp;

            int ccc = 0;
            for(int p = 0; p < size_item[index]; p++)
            {
                if((items[index][p].part < length[ items[index][p].formula_numb ]) && ( G[ items[index][p].formula_numb ][ items[index][p].part ] == str_vn[j]) )
                {
                    tp.formula_numb = items[index][p].formula_numb;
                    tp.expc = items[index][p].expc;
                    tp.part = items[index][p].part+1;
                    buf[buf_size++] = tp;
                    //ccc++;

                }
            }
            printf("//I%d ----- %c:\n",index,str_vn[j]);


            if(buf_size  != 0)
            {
                Ccount++;
                for(int t = 0; t < buf_size; t++)
                {
                    items[Ccount][ size_item[Ccount]++ ] = buf[t];
                }

                e_closure(Ccount);

                int  next_state = is_contained();    //See item sets generated by the project is already set in the family

                if(next_state != 0)
                {
                    size_item[Ccount] = 0;
                    Ccount--;
                    trans[size_trans].beg = index;
                    trans[size_trans].nex = next_state;
                    trans[size_trans].ch = str_vn[j];
                    size_trans++;
                }
                else
                {
                    cout << "I" << Ccount << ":" << endl;
                    for(int i = 0; i < size_item[Ccount]; i++)
                        printf("%d , %d , %c\n",items[Ccount][i].formula_numb,items[Ccount][i].part,items[Ccount][i].expc);
                    cout << "***************************************" << endl;
                    trans[size_trans].beg = index;
                    trans[size_trans].nex = Ccount;
                    trans[size_trans].ch = str_vn[j];
                    size_trans++;
                }
            }
        }                //For each grammar nonterminal
    }

}

int main()
{
    for(int i = 0; i< 150; i++)
        tempofinput[i] = false;
    for(int i= 0; i < 100; i++)
        size_item[i] = 0;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 150; j++)
            first_vn[i][j] = false;

    Read_G();        //read G and put the number of formula into count
    // cout << "***************************" << endl;

    get_first();     //each vn's first_set
    /*for(int i = 0; i < 128; i++)
        if(first_vn[1][i])
         printf("(B,%c)\n",i);*/

    go();
    for(int i = 0; i < size_trans; i++)
    {
        printf("(%d %c %d)\n",trans[i].beg,trans[i].ch,trans[i].nex);
    }
    /*cout << "$$$$$$$$$$$$$$$$$$$$$$$$$" <<endl;
    for(int i = 1; i <= number; i++){
        cout << length[i]  << " ";
        for(int j = 0; j < length[i]; j++){
                cout << G[i][j]<<" ";
        }
        cout << endl;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$" <<endl;*/
    cout << Ccount << endl;
    system("pause");
    return 0;
}
