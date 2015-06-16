#ifndef HISTORIQUE_HPP
#define HISTORIQUE_HPP

#include "commande.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

typedef struct histo {
    std::string nomC;
    std::string prenomC;
    int fidelite;
    struct histo* suivant;
}histo;

typedef struct prod {
    std::string nomP;
    int nombre;
    struct prod* succ;
}prod;

typedef histo* listo;
typedef prod* liprod;

class historique
{
    public:

        historique(Command commande);

        listo stockageC(listo malisteC, Command m_commande);
        liprod stockageP(liprod malisteP, Command m_commande);
        listo rechercheListo(listo malisteC, Command m_commande);
        void rechercheProd(liprod malisteP, Command m_commande);
        int occurenceC(listo malisteC, std::string Nom, std::string Prenom);
        int occurenceP(liprod malisteP, std::string NomProduit);

    private:

        Command m_commande;

};

#endif // HISTORIQUE_HPP
