#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){


 int nb;
 string nom;
 
 ofstream outFile;

 outFile.open("list.txt",ios::out| ios::app);

	cout<<"Rentres numéro"<< endl;

 cin>>nb;
 cin.ignore();
 //getline(cin, nom);
 //cin.ignore();

 if(nb==1){
	nom="Julien";

 }


 if(nb==2){
	nom="Edouard";

 }

 outFile<<nom<<endl;


/************Lecture*********/


 
 ifstream inFile;

 inFile.open("list.txt");

 

	//Check file open//

	if(inFile.fail()){

	 cerr<<"File doesn't open"<< endl;

	 exit(1);

	}


 string commande;
 int count=0;
 int count1=0;
 int count2=0;
 int count3=0;

	while(!inFile.eof()){

	 inFile>>commande;


	 if(commande=="Julien"){
		count++;

	 }

	 
	 if(commande=="Edouard"){
		count1++;
	 }


	 
	 if(commande=="Florence"){
		count2++;

	 }


	 
	 if(commande=="Leplusbeau"){
		count3++;

	 }

	}



	cout<<"Il y a "<<count<<" Julien dans la liste"<< endl;
	cout<<"Il y a "<<count1<<" Edouard dans la liste"<< endl;
	cout<<"Il y a "<<count2<<"Florence dans la liste"<< endl;
	cout<<"Il y a "<<count3<<" Le plus beau dans la liste"<< endl;

	


	inFile.close();
		
return 0;
}
