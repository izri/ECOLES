#include "LR1.h"

string   non_ter, termin; //���ս���� �ս��
string   AllChar;   //�����ķ�����
int      GramCount=0 ;    //�ķ���Ŀ
int      ItemsCout=0;    //��Ŀ����Ŀ


string  **AnalyTable;
int     MapTable[128];

/*
*  item �Ƿ�����Ŀ��items��
*/
int  IsIncludeItems(ITEM item, ITEM *items)
{
	int i=0, j=0;
	for (i=0; i<ItemsCout; i++)
	{
		if ( (item.I[0].compare(items[i].I[0]) ==0) &&(item.ForwardSet[0].compare(items[i].ForwardSet[0]) ==0))
		{
			return i;
		}
	}
	return -1;
}


/*
*   ʽ���Ƿ�����Ŀitem��ʽ�Ӽ���
*/
int  IsIncludeItem(string s, ITEM item)
{
	int i=0;
	for (i=0; i<item.n; i++)
	{
        if (item.I[i].compare(s) == 0)
        {
			return i;
        }
	}
	return -1;
}

/*
*�ַ�c�Ƿ�����ַ���p��
**/
int IsIncludeStr(char c, string p)
{
   	int i;
	if(p.length()==0)
		return -1;
	for (i=0;i<p.length() ;i++)
	{
		if (p[i]==c)
		{
			return i;
		}
	}
	return -1;
}


/*
* ��ӡ�ķ�
*/
void PrintGram(GrammarFormulas *p)
{
   	int i;
	cout<<endl<<"G=��{"<<non_ter<<"},{"<<termin<<"},P,"<<non_ter[0]<<"����SLR��"<<endl;
	for(i=0;i<GramCount;i++)
		cout<<p[i].left<<"->"<<p[i].right<<endl;
}

/*
*��ӡ��Ŀ����
*/
void PrintItems(ITEM *item)
{
	int i=0, j=0;
	cout<<endl<<"================================"<<endl;;
	for (i=0; i<ItemsCout; i++)
	{
		cout<<"--------------------------------"<<endl;
		cout<<"I:"<<i<<endl;
		for (j=0; j<item[i].n; j++)
		{
			cout<<item[i].I[j]<<" , "<<item[i].ForwardSet[j]<<endl;
		}
		cout<<"ת����"<<endl;
		for (j=0; j<item[i].nSkipNum; j++)
		{
			cout<<i<<"---"<<item[i].skip[j].skipStr<<"--->"<<item[i].skip[j].ToState<<endl;
		}
		cout<<"--------------------------------"<<endl;
	}
}

/*
*��ӡLR1������
*/
void  PrintAnalyTable()
{
	int i=0, j=0;
	cout<<'\t';
	for (i=0; i<AllChar.length(); i++)
	{
		cout<<AllChar[i]<<'\t';
	}
	cout<<endl;
     for (i=0; i<ItemsCout; i++)
     {
		 cout<<i<<'\t';
		 for (j=0; j<AllChar.length();j++)
		 {
			 cout<<AnalyTable[i][j]<<'\t';
		 }
		 cout<<endl;
     }
}

/*
���﷨p��First����
������
p�����﷨
FirstSet  ���ص�p��First����
*/
void  GetFirstSet(GrammarFormulas *p, string FirsetSet[])
{
	int i=0,j=0;

	int IsChange;  //�ж�First���Ƿ��б仯

	while (IsChange)
	{
		IsChange = false;
		for (i=0 ; i<GramCount; i++)  //����ÿ��ʽ��
		{
            for (j=0; j<p[i].right.length(); j++)
            {
				//���ʽ���ұߵĵ�һ���Ƿ��ս��
				if (IsIncludeStr(p[i].right[j], non_ter) !=-1) //���p[i].right[0]�Ƿ��ս����� p[i].right[0] ��First������ First[i]��
				{
					int a = IsIncludeStr(p[i].left[0], non_ter); //ʽ������ڷ��ս�����е�λ��
					int b = IsIncludeStr(p[i].right[j], non_ter);//ʽ���ұ��ڷ��ս�����е�λ��

					for (int k=0; k<FirsetSet[b].length(); k++)  //�����ұ߷��ս����First��
					{
						if (IsIncludeStr( FirsetSet[b][k],  FirsetSet[a]) == -1)//�����First�������ڵ��ս���ӽ���
						{
							if (FirsetSet[b][k] != '$')
							{
								FirsetSet[a] += FirsetSet[b][k];
								IsChange = true;   //First���б仯
							}
						}
					}

					if (IsIncludeStr('$', FirsetSet[b]) ==-1)  //b��First�����ɿ�
					{
						break;
					}
					else if (j == p[i].right.length()-1)
					{
						if (IsIncludeStr('$', FirsetSet[a])== -1)
						{
							FirsetSet[a] += '$';
						}
					}
				}
				else 	//���ʽ���ұߵĵ�һ�����ս��
				{
					int b= IsIncludeStr(p[i].left[0], non_ter);
					int a = IsIncludeStr(p[i].right[j],FirsetSet[b]);
					if (a == -1)  //���p[i].right���ս�����Ҳ���ʽ����߷��ŵ�First���а�������
					{
						int a = IsIncludeStr(p[i].left[0], non_ter);
						FirsetSet[a] += p[i].right[j];
						IsChange = true;    //First���б仯
					}
					break;
				}
            }
		}
	}
}


/*
�����µķ��ս��
*/
char GetNewNon_Ter()
{
	char c='A';
    while(IsIncludeStr(c,non_ter) != -1)  //���c�Ƿ��ս��c++
		c++;
	return c;
}




/*
�ֽ����ʽ���Ҳ�, �������ַ���ת����GrammarFormulas�ṹ  �� E->E+T|T �ֳ�  E->E+T  ��  E->T ����ʽ��
*/
void  StrToGram(GrammarFormulas *p, string str)
{
	int j=0;
    string  temp;

	for(j=3;j<=str.length()-1;j++)
	{
		if(str[j]!='|')
			temp +=str[j];
		else
		{
			p[GramCount].left  = str[0];
			p[GramCount].right = temp;
			temp = "";
			GramCount++;
		}
	}
	p[GramCount].left  = str[0];
	p[GramCount].right = temp;
	temp = "";
	GramCount++;
}



/*
��������ķ����г�������
*/
void  GetGrammer(GrammarFormulas *grams)
{
	int i=0, N=0;
	string   str[50];
	GrammarFormulas p[MAXSGram];
	cout<<"˵�������Ҳ�֮����'->'��ʾ������'$'��ʾ, ���ս����һ��Ϊ��ʼ��"<<endl;
	cout<<"�������ķ��ķ��ս���Ŵ���";
	cin>>non_ter;
	cout<<"�������ķ����ս���Ŵ���";
	cin>>termin;
	termin +="#";

	cout<<"�������ķ�����ʽ��������";
	cin>>N;

	for(i=0;i<N;i++)
	{
		cout<<"�������ķ��ĵ�"<<i+1<<"������"<<N<<"��������ʽ��";
		cin>>str[i];
	}
	for(i=0;i<N;i++)
	{
		if(str[i][1]!='-'||str[i][2]!='>')/*����������*/
		{
			cout<<endl<<"����ʽ�Ӹ�ʽ�д�!"<<endl;
			return ;
        }
		StrToGram(p,str[i]);  //�ֽ�����ĸ�����ʽ
	}

	/*���ķ���ͷǰ���һ��ʽ��*/
	char c = GetNewNon_Ter();
	non_ter +=c;
	grams[0].left = c;
	grams[0].right= p[0].left;
	for (i=0;i<GramCount; i++)
	{
		grams[i+1].left = p[i].left;
		grams[i+1].right = p[i].right;
	}
    GramCount++;
}


/*
*���ļ��ж�ȡ�ķ�
*
*������
*     grams  ���ص��ķ�
*     FileName �ļ���
*/
int  GetGramFromFile(GrammarFormulas *grams, char *FileName)
{
	int i=0, N=0;
	string   str[50];
	GrammarFormulas p[MAXSGram];
	FILE   *file = fopen(FileName, "r+");

	if (file == NULL)
	{
		return -1;
	}

	char  buff[256];
	fscanf(file, "%s", buff);
	non_ter = buff;
	fscanf(file, "%s", buff);
	termin = buff;
	termin +="#";

	fscanf(file, "%d", &N);

	for(i=0;i<N;i++)
	{
		fscanf(file, "%s", buff);
		str[i] = buff;
	}
	for(i=0;i<N;i++)
	{
		if(str[i][1]!='-'||str[i][2]!='>')/*����������*/
		{
			cout<<endl<<"����ʽ�Ӹ�ʽ�д�!"<<endl;
			return -1;
        }
		StrToGram(p,str[i]);  //�ֽ�����ĸ�����ʽ
	}

	/*���ķ���ͷǰ���һ��ʽ��*/
	char c = GetNewNon_Ter();
	non_ter +=c;
	grams[0].left = c;
	grams[0].right= p[0].left;
	for (i=0;i<GramCount; i++)
	{
		grams[i+1].left = p[i].left;
		grams[i+1].right = p[i].right;
	}
    GramCount++;

	fclose(file);
	return 0;
}


/*
*��ȡ��expressionʽ�������µ�ʽ�ӵ���ǰ������
*
*����:
*    expression �����ʽ��
*    OldForwardSet  expressionʽ�ӶԾ͵���ǰ������
*    p  �ķ�
*    ����ֵ��
*        expression ʽ���ܵ������µ���ǰ������
*/
string  GetForwardSet(string expression, string OldForwardSet, GrammarFormulas *p)
{
	string   NewForwardSet;

	string  *FirstSet = new string[non_ter.length()];
	GetFirstSet(p,FirstSet);

	int i=0;

	for (i=0; i<expression.length(); i++)
	{
		if (expression[i] == '.')
		{
			if (i+2 <expression.length()-1)
			{
				int  a = IsIncludeStr(expression[i+2], non_ter);
				if (a != -1)
				{
					if (IsIncludeStr('$',FirstSet[a]) != -1)
					{
						NewForwardSet = FirstSet[a] + OldForwardSet;
					}
					else
					{
						NewForwardSet = FirstSet[a];
					}

				}
				else
				{
					NewForwardSet = expression[i+2];
				}
			}
			else
			{
				NewForwardSet = OldForwardSet;
			}
		}
	}

	return NewForwardSet;
}


/*
*����Ŀitem�ıհ�
*
*������
*   item  �������Ŀ��
*
*����ֵ��
*
*/
int  CLOSURE(ITEM  &item, GrammarFormulas  *p)
{
	int i=0, j =0, k=0;

	string  *FirstSet = new string[non_ter.length()];
	GetFirstSet(p,FirstSet);

	for (i=0; i<item.n; i++)  //��Ŀ��
	{
		for (j=0; j<item.I[i].length()-1; j++)  //����Ŀÿ�����Ŷ�����һ��
		{
			if (item.I[i][j] == '.')
			{
				if (IsIncludeStr(item.I[i][j+1], non_ter) !=-1)   // . �����Ƿ��ս��
				{
					/*--------------������ǰ������---------------------------------*/
					string  ForwardSet;
					ForwardSet  = GetForwardSet(item.I[i], item.ForwardSet[i], p);
					/*--------------------------------------------------*/

					for (k=0; k<GramCount; k++)
					{
						if (p[k].left[0] == item.I[i][j+1])
						{
							//a������ʾʽ������Ŀ�е�����nForwardIndex ��ʾ��ǰ�������ĵ�ǰʽ������
							int   a =0, nForwardIndex = 0;
							string s;

							if (p[k].right[0] == '$')      //���ʽ��Ϊ  A->$��Ϊ  A->.
							{
								s = p[k].left + "->." + '\0';
							}
							else     //���ʽ�Ӳ�Ϊ�� A->B~~ ��  A->.B~~
							{
								s = p[k].left + "->." + p[k].right + '\0';
							}

							a = IsIncludeItem( s,  item);
							if (a ==-1)   //���s��������Ŀ���������
							{
								item.I[item.n] = s;
								nForwardIndex = item.n;
								item.n++;
							}
							else
							{
								nForwardIndex = a;
							}
							/*---------------����ǰ�����������µ�ʽ����-----------------------------*/
							int  l=0;
							for (l=0; l<ForwardSet.length(); l++)
							{
								if (IsIncludeStr(ForwardSet[l], item.ForwardSet[nForwardIndex]) ==-1)
								{
									item.ForwardSet[nForwardIndex] +=ForwardSet[l];
								}
							}
							/*-----------------------------------------------------------*/
						}
					}
				}
			}
		}
	}
	return  true;
}


/*
*����ת������
*
*������
*   item �������Ŀ��
*   X    �ķ�����
*   p    �ķ�
*
*����ֵ��
*   ����item״̬�����ķ�����X����ת��������Ŀ��״̬�����û����ת״̬����ֵitemBuf.n=0
*/
ITEM   Go(ITEM  item, char  X, GrammarFormulas  *p)
{
	ITEM  itemBuf;
	itemBuf.n =0 ;
	int i=0,j=0,k =0;

	for (i=0; i<item.n; i++)
	{
		for (j=0; j<item.I[i].length()-1; j++)
		{
			if (item.I[i][j] == '.')
			{
				if (item.I[i][j+1] == X)
				{
                    itemBuf.I[itemBuf.n] = item.I[i];
                    itemBuf.ForwardSet[itemBuf.n] = item.ForwardSet[i];

					char   c = itemBuf.I[itemBuf.n][j];   // . ��ǰ�ƶ�һλ Ҳ���� . ����ǰһλ����λ��
					itemBuf.I[itemBuf.n][j] = itemBuf.I[itemBuf.n][j+1];
					itemBuf.I[itemBuf.n][j+1] = c;

                    itemBuf.n++;
				}
			}
		}
	}
    return itemBuf;
}

/*
*��ȡ��ת״̬��
*
*������
*    items  ��Ŀ����
*    p    �ķ�����תʱ�õ�
*/
void  GetSkipState(ITEM  *items, GrammarFormulas  *p)
{
	int i=0, j = 0, k=0, l=0;

	ITEM   itemBuf;
	AllChar = termin+non_ter;
	for (i=0; i<ItemsCout; i++)
	{
		for (j=0; j<ItemsCout; j++)
		{
			for (k=0; k<AllChar.length(); k++)
			{
				itemBuf = Go(items[i], AllChar[k], p);
				int  a= IsIncludeItems(itemBuf, items);

				if (a !=-1)
				{
					for (l=0; l<=items[i].nSkipNum;l++)
					{
						if (items[i].skip[l].skipStr == AllChar[k])
						{
							break;

						}
						else if (l == items[i].nSkipNum)
						{
							items[i].skip[ items[i].nSkipNum ].skipStr = AllChar[k];
							items[i].skip[ items[i].nSkipNum ].ToState = a;
							items[i].nSkipNum++;
							break;
						}
					}
				}
			}
		}
	}
}


/*
*ȡ�����е���Ŀ��
*
*������
* items  ���ص���Ŀ��
* p  �ķ�
*/
int  GetItem(ITEM  *items, GrammarFormulas  *p)
{
	int i=0, j =0;
	AllChar = termin+non_ter;
    items[ItemsCout].n = 1;
	items[ItemsCout].I[0] =  p[0].left + "->." + p[0].right + '\0';
	items[ItemsCout].ForwardSet[0] = "#";
	ItemsCout++;

	CLOSURE(items[i], p);

	for (i=0; i<ItemsCout; i++)
	{
		for (j=0; j<AllChar.length(); j++)
		{
			ITEM  itemBuf = Go(items[i],AllChar[j], p);

			if (itemBuf.n != 0)
			{
				CLOSURE(itemBuf, p);

				if ( IsIncludeItems(itemBuf, items) == -1)  //��Ŀ����û��ʱ�żӽ���(Ҳ������ת)
				{
					items[ItemsCout] = itemBuf;
					ItemsCout++;
				}
			}
		}
	}
	GetSkipState(items, p);  //��¼����ת״̬
    return 0;
}



/*
��ʼ��ӳ���
*/
void  InitMapTable()
{
	int i=0;
	AllChar = termin + non_ter;
	for (i=0; i<AllChar.length(); i++)
	{
		MapTable[AllChar[i]] = i;
	}
}


/*
*������Ŀ�����ȡLR1������
*
*������
*   items ��Ŀ����
*   p   �ķ�
*/
void  GetAnalyTable(ITEM  *items,GrammarFormulas  *p)
{
    AllChar = termin + non_ter;
	InitMapTable();

	int col = AllChar.length();
	int raw = ItemsCout;
	int i=0, j=0, k=0, l=0;
	int StateAft=0, inputType=0;
	char input;

	/*------��̬���������ռ�----------------*/
	AnalyTable = new string*[raw];
	for (i=0; i<raw; i++)
	{
		AnalyTable[i] = new string[col];
	}

	for (i=0; i<ItemsCout; i++)
	{
        for (j=0; j<items[i].n; j++)
        {
			int end = items[i].I[j].length() - 2;

			if (items[i].I[j][end] == '.')
			{
				string  b = p[0].left + "->" + p[0].right +'.'+ '\0';
				if (b.compare(items[i].I[j])== 0) //S'->S, #   ����
				{
					if (items[i].ForwardSet[j][0] == '#')
					{
						inputType = MapTable['#'];
						AnalyTable[i][inputType] = "acc";
					}
				}
				else  // A->X.   , a
				{
                    for (k=0; k<items[i].ForwardSet[j].length(); k++)
                    {
						inputType = MapTable[items[i].ForwardSet[j][k]];

                        for (l=0; l<GramCount; l++)
                        {

							string  gram;

							int a = items[i].I[j].length();

							if (items[i].I[j].length()==5) //S->.
							{
                                   gram = p[l].left+ "->." + '\0';
							}
							else  //S->A.
							{
                               gram = p[l].left + "->" + p[l].right + '.' + '\0';
							}

							if (items[i].I[j].compare(gram) == 0)
							{
								StateAft = l;

								string s;
								char  buf[10];
								_itoa(StateAft,buf, 10);
								s = buf;

								AnalyTable[i][inputType] = 'R' +s;//+ buf;
							}
                        }
                    }
				}
			}
        }

		for (j=0; j<items[i].nSkipNum; j++)
		{
			StateAft = items[i].skip[j].ToState;
			input = items[i].skip[j].skipStr;
			inputType = MapTable[input];

			string s;
			char  buf[10];
			_itoa(StateAft,buf, 10);
			s = buf;

			if (IsIncludeStr(input, termin) !=-1)  //G0(Ik�� a) = Ij    a ->Vt    a = input    Action��
			{
				AnalyTable[i][inputType]  = 'S' + s;// + StateAft;
			}
			else   //  G0(Ik�� A) = Ij    A ->Vn    A = input    GoTo��
			{
				AnalyTable[i][inputType]  = 'G' + s;
			}

		}
	}

}



void  PrintStack(stack <int> s)
{
	stack <int> ss;
	int i=0, n = s.size();
	for ( i=0; i<n; i++)
	{
		ss.push(s.top());
			s.pop();
	}
	for (i=0 ; i<n; i++)
	{
		cout<<ss.top();
		ss.pop();
	}
}

void PrintStack(stack<char> s)
{

	stack <char> ss;
	int i=0, n = s.size();
	for ( i=0; i<n; i++)
	{
		ss.push(s.top());
		s.pop();
	}
	for (i=0 ; i<n; i++)
	{
		cout<<ss.top();
		ss.pop();
	}
}


void  LR1Analy(GrammarFormulas *p)
{
	InitMapTable();
	stack <char> symbolStack;
	stack <int>  stateStack;
	string   input;
	string  stateBuf, buf;
	int   inputType, stateAft, inputIndex=0;
	int i=0;

	cout<<"please input w��";
	cin>>input;
	input += '#';

	symbolStack.push('#');
	stateStack.push(0);

	while (true)
	{
         inputType = MapTable[input[inputIndex]];
		 stateBuf = AnalyTable[stateStack.top()][inputType];


		 PrintStack(stateStack);
		 cout<<"\t\t\t";
		 PrintStack(symbolStack);
		 cout<<"\t\t";
		 cout<<&input[inputIndex];
		 cout<<"\t\t";
		 cout<<stateBuf;
		 cout<<endl;

		 if (stateBuf.compare("acc")==0) //����
		 {
			 cout<<"le mot w est correct"<<endl;
			 break;
		 }

		 if (stateBuf.empty())  //����
		 {
			 cout<<"le mot w est faux"<<endl;
			 break;
		 }

		 switch (stateBuf[0])
		 {
		 case 'S':  //�ƽ�
			 {
				 stateBuf.erase(0,1);
                 stateAft = atoi(stateBuf.c_str());

				 stateStack.push(stateAft);
				 symbolStack.push(input[inputIndex]);

				 inputIndex ++;
			 }
			 break;

		 case 'G':
			 {
				 stateBuf.erase(0,1);
                 stateAft = atoi(stateBuf.c_str());

				 stateStack.push(stateAft);
			 }
			 break;

		 case 'R':  //��Լ
			 {
				 stateBuf.erase(0,1);
                 stateAft = atoi(stateBuf.c_str());
				 for (i=0 ; i<p[stateAft].right.length(); i++)
				 {
					 stateStack.pop();
					 symbolStack.pop();
				 }
				 symbolStack.push(p[stateAft].left[0]);

				 /*---------GoTo------------------------*/
				 inputType = MapTable[symbolStack.top()];
				 stateBuf = AnalyTable[stateStack.top()][inputType];
				 stateBuf.erase(0,1);
                 stateAft = atoi(stateBuf.c_str());

				 stateStack.push(stateAft);
			 }
			 break;
		 }
	}
}
