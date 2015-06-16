#ifndef DEF_MAIN
#define DEF_MAIN

#include<iostream>
#include "Restaurant.hpp"

Client createClient();
bool alreadyHere(vector<string> tab, string element);
void addProduct ();
void initialisation();
void actions();
void dataWatching();
void productsReading();
void printVector(vector<string> tab);
void globalHistoryReading();
void writingFromVector(vector<string> tab, string filePath);
int convertStringToInt(string toConvert);
void updateGlobalHistory();
void getClientHistory();
void clientHistoryReading(int id);
void makeCommand();
int addProductToCommand(Command command);
void printClient(vector<string> client);
void printGlobal(vector<string> global);
string convertIntToString(int toConvert);
void commandAdded(int nbProducts, int totalCost);


#endif
