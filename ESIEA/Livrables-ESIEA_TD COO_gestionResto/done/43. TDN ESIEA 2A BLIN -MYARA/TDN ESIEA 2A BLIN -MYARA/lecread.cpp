#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){


 int nb;
 string nom;

 ofstream outFile;

 outFile.open("liste.txt",ios::out| ios::app);

	cout<<"Rentres numéro"<< endl;

 cin>>nb;
 cin.ignore();

 if(nb==1){
	nom="Samuel";

 }


 if(nb==2){
	nom="Jeremie";

 }

 outFile<<nom<<endl;


/************Lecture*********/



 ifstream inFile;

 inFile.open("liste.txt");



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


	 if(commande=="Samuel"){
		count++;

	 }


	 if(commande=="Jeremie"){
		count1++;
	 }



	 if(commande=="Louise"){
		count2++;

	 }



	 if(commande=="Gaelle"){
		count3++;

	 }

	}



	cout<<"Il y a "<<count<<" samuel dans la liste"<< endl;
	cout<<"Il y a "<<count1<<" jeremie dans la liste"<< endl;
	cout<<"Il y a "<<count2<<"louise dans la liste"<< endl;
	cout<<"Il y a "<<count3<<" gaelle dans la liste"<< endl;




	inFile.close();

return 0;
}
