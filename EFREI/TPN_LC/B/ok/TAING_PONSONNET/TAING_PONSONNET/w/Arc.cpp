#include "Arc.h"
#include <iostream>

using namespace std;

Arc::Arc()
{

}

Arc::~Arc()
{

}

int Arc::getIndexInitial()
{
    return indexInitial;
}

int Arc::getIndexFinal()
{
    return indexFinal;
}

std::string Arc::getType()
{
    return type;
}

void Arc::setIndexInitial(int i)
{
    indexInitial = i;
}

void Arc::setIndexFinal(int i)
{
    indexFinal = i;
}

void Arc::setType(std::string i)
{
    type = i;
}
