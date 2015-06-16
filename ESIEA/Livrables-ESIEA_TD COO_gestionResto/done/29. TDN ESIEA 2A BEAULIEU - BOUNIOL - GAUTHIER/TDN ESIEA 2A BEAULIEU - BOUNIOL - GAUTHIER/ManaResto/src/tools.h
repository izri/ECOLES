#ifndef DEF_TOOLS
#define DEF_TOOLS

#include <dirent.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

#ifndef WIN32
    #include <sys/types.h>
#endif

int getInt();
std::string getString();
void printFolder(std::string FName);
std::string mostOrderStarter();
std::string mostOrderMain();
std::string mostOrderDesert();
std::string mostOrderBeverage();
std::string lessOrderStarter();
std::string lessOrderMain();
std::string lessOrderDesert();
std::string lessOrderBeverage();
unsigned long int totalIncome();
std::string fidelityCustomer();

#endif
