#include "automate.h"
#include "etat.h"
#include <string>
#include<vector>
#include "regle.h"
#include <queue>
#include "tableAnalyse.h"
#include "transition.h"

using namespace std;

automate::automate() {
}

automate::automate(grammaire maGrammaire) {
    queue<etat> aTraiter; //File qui permet de numéroter les état dans le bon ordre
    etat etat0;
    etat0.creationEtat0(maGrammaire);
    etats.push_back(etat0);
    aTraiter.push(etat0);
    int cptEtat = 1;
    etat0.affichage();

    while(!aTraiter.empty()) {
        etat enTraitement = aTraiter.front();
        if (!enTraitement.etatTerminal()) {
            for(unsigned int cpt = 0; cpt < maGrammaire.alphabet.size(); cpt++) {
                if(enTraitement.aUneTransition(maGrammaire.alphabet[cpt])) { // S'il existe une transition avec ce non-terminal
                    //cout << "Il existe une transition de l'etat " << enTraitement.indice << " en " << maGrammaire.alphabet[cpt] << endl;
                   etat nouvelEtat = enTraitement.goTo(maGrammaire.alphabet[cpt], maGrammaire);
                   if (!etatDejaPresent(nouvelEtat)) { // Si cet état n'existe pas dans l'automate
                        //cout << "Le nouvel etat obtenu n'existe pas encore" << endl;
                        nouvelEtat.indice = cptEtat;
                        transition nouvelleTransition(enTraitement.indice, maGrammaire.alphabet[cpt], nouvelEtat.indice);
                        cptEtat++;
                        nouvelEtat.affichage();
                        etats.push_back(nouvelEtat);
                        transitions.push_back(nouvelleTransition);
                        aTraiter.push(nouvelEtat);
                   }
                   else { // Il faut quand même sauvegarder la transition
                        //cout << "Cet etat existe deja" << endl;
                        nouvelEtat.indice = etatIdentique(nouvelEtat);
                        transition nouvelleTransition(enTraitement.indice, maGrammaire.alphabet[cpt], nouvelEtat.indice);
                        transitions.push_back(nouvelleTransition);
                   }//cout << "Fin du traitement de la transition de l'etat " << enTraitement.indice << " en " << maGrammaire.alphabet[cpt] << endl;
                } //else cout << "Pas de transition en " << maGrammaire.alphabet[cpt] << " pour l'etat " << enTraitement.indice << endl;
            }
            //cout << "Fin du traitement de l'etat " << enTraitement.indice << endl;
        }
        aTraiter.pop();
    }
}

bool automate::etatDejaPresent(etat etatEtudie) { // Verifie si un etat récupéré du goTo n'existe pas déjà
    for (unsigned int cpt = 0; cpt < etats.size(); cpt++) {
        if (etats[cpt] == etatEtudie) return true;
    }
    return false;
}

int automate::etatIdentique(etat etatEtudie) { // retourne l'indice de l'etat qui existe déjà pour pouvoir sauvegarder la transition
    for (unsigned int cpt = 0; cpt < etats.size(); cpt++) {
        if (etats[cpt] == etatEtudie) return etats[cpt].indice;
    }
}
