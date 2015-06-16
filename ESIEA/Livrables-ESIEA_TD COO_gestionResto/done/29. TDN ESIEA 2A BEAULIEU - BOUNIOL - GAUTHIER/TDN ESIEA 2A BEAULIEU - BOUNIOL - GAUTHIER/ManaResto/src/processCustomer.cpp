#include <iostream>
#include <fstream>
#include <string>
#include "processCustomer.h"

using namsepace std;


bool isNew(string name)
{

	if(std::ifstream(name+".txt")) // Customer already exists
		return false;
	else
		return true;

}

Customer newCustomer()
{


}

Customer loadCustomer(string name)
{
	unsigned int *id, *age, *totalExepense, *totalVisit;
	bool *gender;

	readCustomer(&id, &name, &gender, &age, &totalExpense, &totalVisit);

	Customer client(*id, name, *gender, *age, *totalExpense, *totalVisit);

	return client;
}

void readCustomer(unsigned int *id, string name, bool *gender, unsigned int *age, unsigned int *totalExpense, unsigned int *totalVisit)
{

	ifstream file("client/" + name + ".txt", ios::in); // Opening file 'name'.txt

	getline(file, &id);
	getline(file, &name);
	getline(file, &gender);
	getline(file, &age);
	getline(file, &totalExpense);
	getline(file, &totalVisit);

	file.close();

}
