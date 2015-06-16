#include "LR1.h"

string   non_ter, termin; //非终结符， 终结符
string   AllChar;   //所有文法符号
int      GramCount=0 ;    //文法数目
int      ItemsCout=0;    //项目集数目


string  **AnalyTable;
int     MapTable[128];

/*
*  item 是否在项目集items里
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
*   式子是否在项目item的式子集里
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
*字符c是否存在字符串p中
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
* 打印文法
*/
void PrintGram(GrammarFormulas *p)
{
   	int i;
	cout<<endl<<"G=（{"<<non_ter<<"},{"<<termin<<"},P,"<<non_ter[0]<<"），SLR："<<endl;
	for(i=0;i<GramCount;i++)
		cout<<p[i].left<<"->"<<p[i].right<<endl;
}

/*
*打印项目集族
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
		cout<<"转换表："<<endl;
		for (j=0; j<item[i].nSkipNum; j++)
		{
			cout<<i<<"---"<<item[i].skip[j].skipStr<<"--->"<<item[i].skip[j].ToState<<endl;
		}
		cout<<"--------------------------------"<<endl;
	}
}

/*
*打印LR1分析表
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
求语法p的First集合
参数：
p输入语法
FirstSet  返回的p的First集合
*/
void  GetFirstSet(GrammarFormulas *p, string FirsetSet[])
{
	int i=0,j=0;

	int IsChange;  //判断First集是否还有变化

	while (IsChange)
	{
		IsChange = false;
		for (i=0 ; i<GramCount; i++)  //遍历每条式子
		{
            for (j=0; j<p[i].right.length(); j++)
            {
				//如果式子右边的第一个是非终结符
				if (IsIncludeStr(p[i].right[j], non_ter) !=-1) //如果p[i].right[0]是非终结符则把 p[i].right[0] 的First集加入 First[i]中
				{
					int a = IsIncludeStr(p[i].left[0], non_ter); //式子左边在非终结符串中的位置
					int b = IsIncludeStr(p[i].right[j], non_ter);//式子右边在非终结符串中的位置

					for (int k=0; k<FirsetSet[b].length(); k++)  //遍历右边非终结符的First集
					{
						if (IsIncludeStr( FirsetSet[b][k],  FirsetSet[a]) == -1)//把左边First集不存在的终结符加进来
						{
							if (FirsetSet[b][k] != '$')
							{
								FirsetSet[a] += FirsetSet[b][k];
								IsChange = true;   //First集有变化
							}
						}
					}

					if (IsIncludeStr('$', FirsetSet[b]) ==-1)  //b的First集不可空
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
				else 	//如果式子右边的第一个是终结符
				{
					int b= IsIncludeStr(p[i].left[0], non_ter);
					int a = IsIncludeStr(p[i].right[j],FirsetSet[b]);
					if (a == -1)  //如果p[i].right是终结符并且不在式子左边符号的First集中把它加入
					{
						int a = IsIncludeStr(p[i].left[0], non_ter);
						FirsetSet[a] += p[i].right[j];
						IsChange = true;    //First集有变化
					}
					break;
				}
            }
		}
	}
}


/*
返回新的非终结符
*/
char GetNewNon_Ter()
{
	char c='A';
    while(IsIncludeStr(c,non_ter) != -1)  //如果c是非终结符c++
		c++;
	return c;
}




/*
分解产生式左右部, 把输入字符串转换成GrammarFormulas结构  把 E->E+T|T 分成  E->E+T  和  E->T 两条式子
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
对输入的文法进行初步处理
*/
void  GetGrammer(GrammarFormulas *grams)
{
	int i=0, N=0;
	string   str[50];
	GrammarFormulas p[MAXSGram];
	cout<<"说明：左右部之间用'->'表示，空用'$'表示, 非终结符第一个为开始符"<<endl;
	cout<<"请输入文法的非终结符号串：";
	cin>>non_ter;
	cout<<"请输入文法的终结符号串：";
	cin>>termin;
	termin +="#";

	cout<<"请输入文法产生式的条数：";
	cin>>N;

	for(i=0;i<N;i++)
	{
		cout<<"请输入文法的第"<<i+1<<"条（共"<<N<<"条）产生式：";
		cin>>str[i];
	}
	for(i=0;i<N;i++)
	{
		if(str[i][1]!='-'||str[i][2]!='>')/*检测输入错误*/
		{
			cout<<endl<<"输入式子格式有错!"<<endl;
			return ;
        }
		StrToGram(p,str[i]);  //分解输入的各产生式
	}

	/*在文法开头前多加一条式子*/
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
*从文件中读取文法
*
*参数：
*     grams  返回的文法
*     FileName 文件名
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
		if(str[i][1]!='-'||str[i][2]!='>')/*检测输入错误*/
		{
			cout<<endl<<"输入式子格式有错!"<<endl;
			return -1;
        }
		StrToGram(p,str[i]);  //分解输入的各产生式
	}

	/*在文法开头前多加一条式子*/
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
*获取由expression式子生成新的式子的向前搜索集
*
*参数:
*    expression 输入的式子
*    OldForwardSet  expression式子对就的向前搜索集
*    p  文法
*    返回值：
*        expression 式子能导出的新的向前搜索集
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
*求项目item的闭包
*
*参数：
*   item  输入的项目集
*
*返回值：
*
*/
int  CLOSURE(ITEM  &item, GrammarFormulas  *p)
{
	int i=0, j =0, k=0;

	string  *FirstSet = new string[non_ter.length()];
	GetFirstSet(p,FirstSet);

	for (i=0; i<item.n; i++)  //项目集
	{
		for (j=0; j<item.I[i].length()-1; j++)  //对项目每个符号都遍历一次
		{
			if (item.I[i][j] == '.')
			{
				if (IsIncludeStr(item.I[i][j+1], non_ter) !=-1)   // . 后面是非终结符
				{
					/*--------------计算向前搜索集---------------------------------*/
					string  ForwardSet;
					ForwardSet  = GetForwardSet(item.I[i], item.ForwardSet[i], p);
					/*--------------------------------------------------*/

					for (k=0; k<GramCount; k++)
					{
						if (p[k].left[0] == item.I[i][j+1])
						{
							//a用来表示式子在项目中的索引nForwardIndex 表示向前搜索符的当前式子索引
							int   a =0, nForwardIndex = 0;
							string s;

							if (p[k].right[0] == '$')      //如果式子为  A->$则为  A->.
							{
								s = p[k].left + "->." + '\0';
							}
							else     //如果式子不为空 A->B~~ 则  A->.B~~
							{
								s = p[k].left + "->." + p[k].right + '\0';
							}

							a = IsIncludeItem( s,  item);
							if (a ==-1)   //如果s不存在项目集中则加入
							{
								item.I[item.n] = s;
								nForwardIndex = item.n;
								item.n++;
							}
							else
							{
								nForwardIndex = a;
							}
							/*---------------把向前搜索集加入新的式子中-----------------------------*/
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
*构造转换函数
*
*参数：
*   item 输入的项目集
*   X    文法符号
*   p    文法
*
*返回值：
*   返回item状态遇到文法符号X，后转到的新项目集状态，如果没有跳转状态返回值itemBuf.n=0
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

					char   c = itemBuf.I[itemBuf.n][j];   // . 向前移动一位 也就是 . 与它前一位交换位置
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
*获取跳转状态表
*
*参数：
*    items  项目集族
*    p    文法，跳转时用到
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
*取得所有的项目集
*
*参数：
* items  返回的项目集
* p  文法
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

				if ( IsIncludeItems(itemBuf, items) == -1)  //项目集里没有时才加进来(也就是跳转)
				{
					items[ItemsCout] = itemBuf;
					ItemsCout++;
				}
			}
		}
	}
	GetSkipState(items, p);  //记录下跳转状态
    return 0;
}



/*
初始化映射表
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
*根据项目集族获取LR1分析表
*
*参数：
*   items 项目集族
*   p   文法
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

	/*------动态申请分析表空间----------------*/
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
				if (b.compare(items[i].I[j])== 0) //S'->S, #   接受
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

			if (IsIncludeStr(input, termin) !=-1)  //G0(Ik， a) = Ij    a ->Vt    a = input    Action表
			{
				AnalyTable[i][inputType]  = 'S' + s;// + StateAft;
			}
			else   //  G0(Ik， A) = Ij    A ->Vn    A = input    GoTo表
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

	cout<<"please input w：";
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

		 if (stateBuf.compare("acc")==0) //接受
		 {
			 cout<<"le mot w est correct"<<endl;
			 break;
		 }

		 if (stateBuf.empty())  //出错
		 {
			 cout<<"le mot w est faux"<<endl;
			 break;
		 }

		 switch (stateBuf[0])
		 {
		 case 'S':  //移进
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

		 case 'R':  //归约
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
