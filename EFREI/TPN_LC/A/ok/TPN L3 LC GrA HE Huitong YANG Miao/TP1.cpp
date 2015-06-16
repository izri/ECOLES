#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct wenfa
{
  string left;
  string right;
};

void change(wenfa *p,char *q, int n, int count)
{
  int count1 = n;
  int flag = 0;
  for(int i=0;i<n;i++)
  if(p[i].left[0] == q[0])
  if(p[i].left[0] == p[i].right[0])
     flag++;
         if(flag != 0)
         {
          for(int i=0;i<n;i++)

            if(p[i].left[0] == q[0])
            if(p[i].left[0] == p[i].right[0])
            {
              string str;
              str = p[i].right.substr(1,int(p[i].right.length()));
              string temp = p[i].left;
              string temp1 = "'";
              p[i].left = temp + temp1;
              p[i].right = str + p[i].left;    //A->Ad:A'->dA'
            }
            else
            {
              string  temp = p[i].left;
              string temp1 = "'";
              temp = temp + temp1;
              p[i].right = p[i].right + temp; //A->D:A->DA'
            }
            string str = "'";
            p[count1].left =p[0].left[0] + str;
            p[count1].right = "@";  //A->@
        }
        for(int i=0;i<=count;i++)
        {
          for(int j=0;j<i;j++)
          {
          for(int g=0;g<n;g++)
          if(q[i] == p[g].left[0])
          if(p[g].right[0] == q[j])
          {
            for(int h=0;h<n*n;h++)
            if(p[h].left[0] == q[j]&&int(p[h].left.length()) == 1)
            {
               string str;
               str = p[g].right.substr(1, int(p[g].right.length()));
               p[++count1].left = p[g].left;
               p[count1].right = p[h].right + str;
            }
            p[g].left = "'";
            p[g].right = "'";
            /*
            A->Bb;   ->  A->Bb;
            B->Aa;       B'->baB';
                         B'->@;
            */
           }
        }
       }
        for(int i=0;i<=count;i++)
        {
          flag = 0;
          for(int j=0;j<n*n;j++)
          if(p[j].left[0] == q[i])
          if(p[j].left[0] == p[j].right[0])
          flag++;
          if(flag != 0)
          {
            for(int j=0;j<=n*n;j++)
            if(p[j].left[0] == q[i])
            if(p[j].left[0] == p[j].right[0])
            {
              string str;
              str = p[j].right.substr(1,int(p[j].right.length()));
              string temp = p[j].left;
              string temp1 = "'";
              p[j].left = temp + temp1;
              p[j].right = str + p[j].left;
            }
            else
            {
              string temp = p[j].left;
              string temp1 = "'";
              temp = temp + temp1;
              p[j].right = p[j].right + temp;
            }
            string str = "'";
            p[++count1].left = q[i] + str;
            p[count1].right = "@";
          }
        }
}
int Delete(wenfa *p, int n)
{
  return 0;
}
int main()
{
    int n;
    int flag;
    int count=0;
    cout << "input the count :";
    cin   >> n;
    wenfa *p = new wenfa[60];
    cout << "input the chan sheng shi:\n";
    char ch;
    for(int i=0;i<n;i++)
    {
      cin >> p[i].left;
      ch=getchar();
      cout << "->";
      cin >> p[i].right;
      ch=getchar();
      cout << endl;
    }
    cout << "the chan sheng shi is :\n";
    for(int i=0;i<n;i++)
    {
      cout << "\t";
      cout << p[i].left << "->" << p[i].right << endl;
    }
    char q[20];
    q[0] = p[0].left[0];
    for(int i=0;i<n;i++)
    {
      flag = 0;
      for(int j=0;j<i;j++)
      if(p[i].left == p[j].left)
      flag++;
      if(flag == 0)
      q[count++] = p[i].left[0];
    }
    count--;
    change(p,q,n,count);
    cout << "after defete the left:\n";
    for(int i=0;i<=count;i++)
    {
    for(int j=0;j<=n*n;j++)
    if(p[j].left[0] == q[i] && int(p[j].left.length()) == 1)
    cout << p[j].left << "->" << p[j].right << endl;
    else
    continue;
    for(int j=0;j<n*n;j++)
    if(p[j].left[0] == q[i] && int(p[j].left.length())== 2)
    cout << p[j].left << "->" << p[j].right << endl;
    else
    continue;
    }
system("pause");
return 0;
}
