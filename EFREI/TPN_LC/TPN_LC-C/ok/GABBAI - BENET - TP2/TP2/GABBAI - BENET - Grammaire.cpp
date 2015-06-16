#include <iostream>
#include <fstream>
#include "GABBAI - BENET - Grammaire.h"

using namespace std;

void Grammaire::ajouter(char debut, string resultat)
{
    Regle r(debut, resultat);
    _listeRegles.push_back(r);
}

void Grammaire::afficher()
{
    for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)
    {
        cout << *it << endl;
    }
}

void Grammaire::modifierRegles()
{
    for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)
    {
        string s = ".";
        s += it->getResultat();
        it->setResultat(s);
    }
    char c = 'X';   //point de départ de la nouvelle règle (équivalent du A' si A est l'axiome)
    string s = ".";
    s += (_listeRegles.begin())->getDebut();
    Regle r(c, s);
    _listeRegles.insert(_listeRegles.begin(), r);
}

vector<Grammaire> Grammaire::calculItems(vector<Grammaire> listeItems, vector<Regle> reglesI0)
{
    //On recupere tous les terminaux et non terminaux de la grammaire
    vector<char> listeElements;
    vector<Grammaire> nouvellesGrammaires;
    for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)
    {
        for(unsigned int i = 0; i < (it->getResultat()).size(); i++)
        {
            if((it->getResultat()).at(i) != '.' && !dejaPresent(listeElements, (it->getResultat()).at(i))) listeElements.push_back((it->getResultat()).at(i));
        }
    }

    for(vector<char>::iterator it2 = listeElements.begin(); it2 != listeElements.end(); ++it2)
    {
        Grammaire g2;
        for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)
        {
            unsigned int i= 0;
            while(i < (it->getResultat()).size() && (it->getResultat()).at(i) != '.')//trouve la position du point pour la regle ccnsideree
            {
                i++;
            }
            if(i != (it->getResultat()).size() - 1) //Si le point n'est pas a la fin
            {
                if((it->getResultat()).at(i + 1) == *it2)
                {
                    char debut = it->getDebut();
                    string resultat = it->getResultat();

                    //echange du point et de la valeur qui le suit dans la nouvelle regle
                    char tmp = (it->getResultat()).at(i + 1);
                    resultat[i + 1] = resultat[i];
                    resultat[i] = tmp;
                    g2.ajouter(debut, resultat); //ajout de la regle
                    if((i + 1) != (it->getResultat()).size() - 1 && ((it->getResultat()).at(i + 2) <= 'Z' && (it->getResultat()).at(i + 2) >= 'A'))
                    {
                        for(vector<Regle>::iterator it3 = reglesI0.begin(); it3 != reglesI0.end(); ++it3)
                        {
                            if((it->getResultat()).at(i + 2) == it3->getDebut() && (it->getResultat()).at(0) == '.')
                            {
                                g2.ajouter(it3->getDebut(), it3->getResultat());
                            }
                        }
                    }
                }
            }
        }
        bool regleExisteDeja = false;
        unsigned int cpt = 0;
        for(vector<Grammaire>::iterator it = listeItems.begin(); it != listeItems.end(); ++it)
        {
            if(it->getRegles() == g2.getRegles() || (g2.getRegles()).size() == 0)
            {
                regleExisteDeja = true;
                if(it->getRegles() == g2.getRegles()) _successeurs.push_back(cpt);
            }
            cpt++;
        }
        if(!regleExisteDeja) nouvellesGrammaires.push_back(g2);
    }
    for(vector<Grammaire>::iterator it = nouvellesGrammaires.begin(); it != nouvellesGrammaires.end(); ++it)
    {
        listeItems.push_back(*it);
        _successeurs.push_back(listeItems.size() - 1);
    }
    for(vector<unsigned int>::iterator ite2 = _successeurs.begin(); ite2 != _successeurs.end(); ++ite2) cout << *ite2 << " ";
    cout << endl;
    for(vector<Grammaire>::iterator it = nouvellesGrammaires.begin(); it != nouvellesGrammaires.end(); ++it)
    {
        listeItems = it->calculItems(listeItems, reglesI0);
    }
    return listeItems;
}

vector<Ensemble> Grammaire::calculPremiers()
{
    vector<Ensemble> premiers;
    for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)  //pour tous les debuts de regle
    {
        if(!dejaPresent(premiers, it->getDebut()))  //s'ils n'ont pas deja été traités
        {
            Ensemble e;
            e.setNT(it->getDebut());
            vector<char> elements;
            for(vector<Regle>::iterator it2 = _listeRegles.begin(); it2 != _listeRegles.end(); ++it2) //pour chaque regle
            {
                if(it->getDebut() == it2->getDebut()) //si le debut de la regle est le meme que le premier que l'on traite
                {
                    if((it2->getResultat()).size() == 0)    //cas particulier pour epsilon : chaine vide
                    {
                        elements.push_back(' ');
                    }
                    else if((it2->getResultat()).at(0) < 'A' || (it2->getResultat()).at(0) > 'Z') //si ce n'est pas un non terminal
                    {
                        elements.push_back((it2->getResultat()).at(0)); //on ajoute
                    }
                }
            }
            e.setElements(elements);
            premiers.push_back(e);
        }
    }
    return premiers;
}

vector<Ensemble> Grammaire::calculSuivants(vector<Ensemble> premiers)
{
    vector<char> listeNonTerminaux;
    vector<Ensemble> suivants;
    for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)  //trouve et stocke tous les non terminaux
    {
        if(!dejaPresent(listeNonTerminaux, it->getDebut())) listeNonTerminaux.push_back(it->getDebut());
    }
    for(vector<char>::iterator it2 = listeNonTerminaux.begin(); it2 != listeNonTerminaux.end(); ++it2) //pour tous ceux la
    {
        Ensemble e;
        e.setNT(*it2);
        vector<char> elements;
        for(vector<Regle>::iterator it = _listeRegles.begin(); it != _listeRegles.end(); ++it)  //pour toutes les regles
        {
            string s = it->getResultat();
            for(unsigned int i = 0; i < s.size(); i++)  //pour chaque element de la partie droite d'une regle
            {
                if(s[i] == *it2) //s'il est egal a l'element dont on cherche le suivant
                {
                    bool continuer = true;
                    while(i + 1 < s.size() && continuer == true) //tant qu'on ne doit pas s'arreter et qu'on est pas a la fin
                    {
                        continuer = false;
                        if(s[i + 1] < 'A' || s[i + 1] > 'Z')    //si ce n'est pas un non terminal
                        {
                            elements.push_back(s[i + 1]);
                        }
                        else    //sinon
                        {
                            for(vector<Ensemble>::iterator it3 = premiers.begin(); it3 != premiers.end(); ++it3)    //pour les premiers
                            {
                                if(it3->getNT() == s[i + 1])
                                {
                                    vector<char> prems = it3->getElements();
                                    for(vector<char>::iterator it4 = prems.begin(); it4 != prems.end(); ++it4)  //ajout des premiers
                                    {
                                        if(!dejaPresent(elements, *it4)) elements.push_back(*it4);
                                        if(*it4 == ' ') continuer = true;   //si epsilon on regarde l'element suivant
                                    }
                                }
                            }
                        }
                        if(continuer) i++;
                    }
                }
            }
        }
        e.setElements(elements);
        suivants.push_back(e);
    }
    return suivants;
}

Grammaire lireFichier()
{
    ifstream maGrammaire("GABBAI - BENET - Grammaire.txt");
    char debut;
    char caractere;
    string resultat = "";
    Grammaire grammaire;

    maGrammaire >> debut;

    while(debut != '#')
    {
        maGrammaire >> caractere;
        while(caractere != '#')
        {
            resultat += caractere;
            maGrammaire >> caractere;
        }
        grammaire.ajouter(debut, resultat);
        resultat = "";
        maGrammaire >> debut;
    }
    maGrammaire.close();
    return grammaire;
}

bool dejaPresent(vector<char> tab, char x)
{
    for(vector<char>::iterator it = tab.begin(); it != tab.end(); ++it)
    {
        if(*it == x) return true;
    }
    return false;
}

bool dejaPresent(vector<Ensemble> tab, char x)
{
    for(vector<Ensemble>::iterator it = tab.begin(); it != tab.end(); ++it)
    {
        if(it->getNT() == x) return true;
    }
    return false;
}
