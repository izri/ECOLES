#ifndef DEF_PROCESSCUSTOMER
#define DEF_PROCESSCUSTOMER

#include <iostream>
#include <string>
#include "customer.h"

bool isNew(std::string name);
Customer newCustomer();
Customer loadCustomer(std::string name);
void readCustomer(unsigned int *id, std::string name, bool *gender, unsigned int *age, unsigned int *totalExpense, unsigned int *totalVisit);

#endif
