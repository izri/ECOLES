#ifndef MAJSTOCK_H_INCLUDED
#define MAJSTOCK_H_INCLUDED

#include <string>
#include "TicketCaisse.h"


class MajStock : public TicketCaisse
{
    std::string m_stockRestant;

    public:
    MajStock();
    MajStock(std::string c, int nb);

    //void faireStock();








};


#endif // MAJSTOCK_H_INCLUDED
