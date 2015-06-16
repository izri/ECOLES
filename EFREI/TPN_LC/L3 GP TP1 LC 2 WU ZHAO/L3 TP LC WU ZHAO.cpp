#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
const int size=10;
string gene[size],temp[size];
int main()
{
	int i=0,count=0;
	cout<<"\t\tAppuyer sur 1 pour importer un fichier!\n\t\tUne touche quelconque pour quitter!"<<endl;
	cin>>i;
	if(i==1)
	{
	  fstream fin("example.txt");
	  i=0;
	  while(fin>>gene[i])i++;
	  count=i;
	}
	else
		return 0;
	cout<<"la grammaire£º"<<endl;
	for(i=0;cout<<gene[i]<<endl,i<3;i++);

	int j=0;

	size_t start=0, end=0;
	int count2=0;

	for(i=0;i<count;i++)
	{

		for(j=0;j<i;j++)
		{
			start=2;

			char qj=gene[j][0];


			//
			bool rgt=false;

			int count1=0;

			string tt[size];

			size_t s=0;

			size_t e=0;
			do
			{
				start++;

				if(gene[i][start]==qj)
				{


					size_t es=gene[i].find_first_of("|",start+1);

					if(es==string::npos)

						es=gene[i].length();

					string te=gene[i].substr(start+1,es-start-1);


					if(!rgt)
					{
						s=gene[j].find_first_not_of("|",3);

						while(s!=string::npos)
						{
							e=gene[j].find_first_of("|",s+1);

							if(e==string::npos)

								e=gene[j].length();

							tt[count1]=gene[j].substr(s,e-s);

							count1++;

							s=gene[j].find_first_not_of("|",e+1);

						}
						rgt=true;
					}
					int k=0;

					string ttl="\0";

					for(;k<count1-1;k++)

						ttl+=tt[k]+te+"|";

					ttl+=tt[k]+te;

					//cout<<ttl<<endl;

					gene[i].replace(start,es-start,ttl);

					//cout<<gene[i]<<endl;

					//cout<<gene[i]<<endl;
				}
				start=gene[i].find_first_of("|",start+1);

			}while(start!=string::npos);
		}
		//factorisation et recursivite gauche
		string p1="",p2="";
		size_t sss=3,eee=0;
		char ch=gene[i][0];
		bool rg=false;
		while(sss!=string::npos)
		{
			eee=gene[i].find_first_of("|",sss+1);
			if(eee==string::npos)eee=gene[i].length();
			if(gene[i][sss]==ch)
			{
				rg=true;
				p1+=gene[i].substr(sss+1,eee-sss-1)+ch+"\'|";
			}
			else
			{
				p2+=gene[i].substr(sss,eee-sss)+ch+"\'|";
			}
		    sss=gene[i].find_first_not_of("|",eee+1);
		}
		p2[p2.length()-1]='\0';

		if(rg)
		{
           temp[count2]=ch+("\'->"+p1+"#");
		   count2++;
		   gene[i].replace(3,gene[i].length()-3,p2);
		}
	}
	cout<<"On obtient:"<<endl;
	for(i=0;cout<<gene[i]<<endl,i<count-1;i++);
	for(i=0;cout<<temp[i]<<endl,i<count2-1;i++);

		return 0;
}
