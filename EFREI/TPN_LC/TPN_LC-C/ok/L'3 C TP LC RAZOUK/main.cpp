#include <iostream>
#include <list>
#include <exception>
#include <algorithm>
#include <fstream>
#include "Grammaire.h"

using namespace std;


int main()
{
    Grammaire grammaire ("in.txt");
    grammaire.writeToFile("out.txt");
    return 0;
}

