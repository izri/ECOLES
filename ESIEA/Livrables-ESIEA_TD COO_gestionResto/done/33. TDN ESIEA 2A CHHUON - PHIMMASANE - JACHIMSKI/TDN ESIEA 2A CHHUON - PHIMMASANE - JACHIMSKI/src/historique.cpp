#include "historique.h"

using namespace std;



historique::historique(Command commande): m_commande(commande) {

}

listo historique::stockageC(listo malisteC, Command m_commande) {

    histo* nouveau = (histo*)malloc(sizeof(histo));
    nouveau -> nomC = m_commande.get_clientL();
    nouveau -> prenomC = m_commande.get_clientF();
    nouveau -> fidelite = 1;
    nouveau -> suivant = malisteC;

    /*cout << "pezard" << endl;
    cout << nouveau->nomC << endl;
    cout << nouveau->prenomC << endl;
    cout << nouveau->fidelite << endl;*/

    return malisteC;

}

liprod historique::stockageP(liprod malisteP, Command m_commande) {

    prod* nouv = (prod*)malloc(sizeof(prod));
    nouv -> nomP = m_commande.get_productN();
    nouv -> succ = malisteP;
    nouv -> nombre = 1;

    return nouv;
}

listo historique::rechercheListo(listo malisteC, Command m_commande) {
    histo* tmp = malisteC;

    while ( tmp != NULL) {
        if(tmp->nomC == m_commande.get_clientL()&& tmp->prenomC==m_commande.get_clientF()) {
            tmp->fidelite= tmp->fidelite + 1;
            //cout << "blablabla" << endl;
            return malisteC;
        }
        else {
            tmp=tmp->suivant;
        }
    }
    malisteC = stockageC(malisteC, m_commande);

    return malisteC;
}

void historique::rechercheProd(liprod malisteP, Command m_commande) {
    prod* tmp = malisteP;

    while ( tmp != NULL) {
        if(tmp->nomP == m_commande.get_productN()) {
            tmp->nombre++;
        }
        else {
            tmp=tmp->succ;
        }
    }
    stockageP(malisteP, m_commande);
}

int historique::occurenceC(listo malisteC, string Nom, string Prenom){
    histo* tmp = malisteC;

    while ( tmp != NULL) {
        if(tmp->nomC == Nom && tmp->prenomC==Prenom) {

            return tmp->fidelite;
        }
        else {
            tmp=tmp->suivant;
        }
    }
    return 0;
}

int historique::occurenceP(liprod malisteP, string NomProduit){
    prod* tmp = malisteP;

    while ( tmp != NULL) {
        if(tmp->nomP == m_commande.get_productN()) {
            return tmp->nombre;
        }
        else {
            tmp=tmp->succ;
        }
    }
    return 0;
}
