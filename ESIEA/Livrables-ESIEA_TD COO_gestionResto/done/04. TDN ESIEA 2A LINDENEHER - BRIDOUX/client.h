#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include <ctime>

#include "command.h"

using namespace std;

class Client {

private:
    vector<Command*> commands;
    string firstName, name;
    signed int nbVisit;
    time_t lastVisit;

public:
    /// === Constructors / destructor ===
    Client(string firstName, string name); // init nom et prenom
    ~Client(); // libere commandes de la memoire

    /// === Methods ===
    bool addCmd(Command *cmd); // ajoute commande
    bool deleteCmd(int index); // supprime commande
    void showCmd(); // affiche les commandes
    void showInfo(); // afiche les infos de bases

    /// === setter / getter / print ===
    void printNames() {cout << this->firstName << " " << this->name;} // print prenom et nom dans la console

    void setNames(string firstName, string name) {this->firstName = firstName; this->name = name;}

    string getName() {return this->name;}
    string getFirstName() {return this->firstName;}
    vector<Command*> getCmds() {return this->commands;}
    Command* getCmdAt(int i) {return (i >= 0 && i < (signed) this->commands.size())? this->commands.at(i):NULL;}
};

#endif // CLIENT_H

