#ifndef JE_COMMANDE
#define JE_COMMANDE

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cstdio>

typedef unsigned int uint;

// Classes

class Plat
{
public:

    std::string name;
    double price;

    Plat(int ID);
};

class Commande
{
    std::vector<uint> quantity;
    std::vector<Plat> meal;
    int day;
    int month;
    int year;


public:

    Commande(Plat eat, uint _quantity, int _day, int _month, int _year);

    void addMeal(Plat eat, uint _quantity);

    double getPriceMeal(std::string name);

    void affichage(std::string name);

    void fichierEspion (std::string name);

};

class Client
{
    std::string name;
    std::vector<Commande> command;

public:

    Client(std::string _name);

    void addCommande(Commande _command);

};

// Fonctions

void ClearScreen();

int clientExist(std::string name);

void addClient(std::string name);

void addPlat(int ID, int quantity);

void freqPlat();

void clearHisto();

void addEntrance(std::string name);

#endif // JE_COMMANDE
