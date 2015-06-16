#include <iostream>
#include <fstream>
#include "GELBART_PEYROUTAT_Language.h"

using namespace std;

Language::Language(){

    language = 0;
    parseurSLR = 0;
    ofs.open("log.txt", ios::out | ios::trunc);
}

Language::~Language(){

    deleteLanguage(language);
    deleteParseur(parseurSLR);
}

bool Language::lectureFichier(string fichier){

    ifstream ifs;

    try{

        ifs.open(fichier.c_str(), ios::in);
    }
    catch(exception const& e){

        cerr << "ERREUR : " << e.what() << endl;
        return false;
    }

    if (ifs.is_open()){

        string a;
        string key;
        string keyTemp;
        string rules;
        unsigned int m;

        language = new map<string, set<list<string>*, setComp>*>;

        getline(ifs,a);

        while (a != "-1")
        {
            key.clear();
            m = 0;

            while ((m < a.size())&&(a.substr(m,1) != " "))
            {
                key += a.at(m);
                m++;
            }

            while(a.substr(m,1) == " ")
                m++;

            if (axiome.empty())
                axiome = key;

            if (key != keyTemp)
                (*language)[key] = new set<list<string>*, setComp>;

            pair<set<list<string>*>::iterator,bool> iS;
            iS = language->at(key)->insert(new list<string>);
            while (m < a.size()){

                rules.clear();

                while ((m < a.size())&&(a.substr(m,1) != " "))
                {
                    rules += a.at(m);
                    m++;
                }

                while(a.substr(m,1) == " ")
                    m++;

                (*iS.first)->push_back(rules);
            }

            keyTemp = key;
            getline(ifs,a);
        }

        return true;
    }

    return false;
}

void Language::removeRecG(){

    removeRecGDirect();
    removeRecGIndirect();
}

void Language::removeRecGDirect(){

    if (language == 0)
        return;

    bool hasRecG;
    set<list<string>*>* tempSet = new set<list<string>*>;

    for (map<string, set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++){

        hasRecG = false;
        tempSet->clear();

        for (set<list<string>*>::iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){

            if ((!(*iS)->empty())&&(iL->first == *((*iS)->begin()))){

                if ((*language)[iL->first+iL->first] == 0)
                    (*language)[iL->first+iL->first] = new set<list<string>*, setComp>;

                pair<set<list<string>*>::iterator,bool> iiS;

                iiS = language->at(iL->first+iL->first)->insert(new list<string>);
                for (list<string>::iterator iR = ++(*iS)->begin(); iR != (*iS)->end(); iR++)
                    (*iiS.first)->push_back(*iR);
                (*iiS.first)->push_back(iL->first + iL->first);

                hasRecG = true;

                iiS = language->at(iL->first+iL->first)->insert(new list<string>);
            }
            else{

                tempSet->insert(*iS);
            }
        }

        if (hasRecG){
            pair<set<list<string>*>::iterator,bool> iiS;
            language->at(iL->first)->clear();
            for (set<list<string>*>::iterator iS = tempSet->begin(); iS != tempSet->end(); iS++){

                iiS = language->at(iL->first)->insert(new list<string>);
                for (list<string>::iterator iR = (*iS)->begin(); iR != (*iS)->end(); iR++)
                    (*iiS.first)->push_back(*iR);
                (*iiS.first)->push_back(iL->first + iL->first);
            }
        }
    }
}

void Language::removeRecGIndirect(){

    bool hasRecIndG;
    set<list<string>*>* temp = new set<list<string>*>;
    list<string>* tempString = new list<string>;
    for (map<string, set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++){
        for (set<list<string>*>::iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){
            for (map<string, set<list<string>*, setComp>*>::iterator iiL = language->begin(); iiL != iL; iiL++){

                if ((!(*iS)->empty())&&(iiL->first == *((*iS)->begin()))){

                        hasRecIndG = false;
                        temp->clear();
                        tempString->clear();

                    for (set<list<string>*>::iterator iiS = iiL->second->begin(); iiS != iiL->second->end(); iiS++){

                        if ((!(*iiS)->empty())&&(iL->first == *((*iiS)->begin()))){

                            list<string>* temp = new list<string>;

                            temp->push_back(iL->first);
                            for (list<string>::iterator iiR = ++(*iiS)->begin(); iiR != (*iiS)->end(); iiR++)
                                temp->push_back(*iiR);
                            for (list<string>::iterator iR = ++(*iS)->begin(); iR != (*iS)->end(); iR++)
                                temp->push_back(*iR);

                            tempString->assign(++(*iS)->begin(),(*iS)->end());
                            (*iS)->swap(*temp);

                            hasRecIndG = true;
                        }
                        else{

                            for (list<string>::iterator iiR = (*iS)->begin(); iiR != (*iS)->end(); iiR++)
                                ofs << *iiR << " ";
                            ofs << endl;
                            temp->insert(*iiS);

                            for (list<string>::iterator iiR = (*iiS)->begin(); iiR != (*iiS)->end(); iiR++)
                                ofs << *iiR << " ";
                            ofs << endl;
                            temp->insert(*iiS);
                        }
                    }

                    if (hasRecIndG){

                        pair<set<list<string>*>::iterator,bool> iiiiS;

                        for (set<list<string>*>::iterator iiiS = temp->begin(); iiiS != temp->end(); iiiS++){
                            iiiiS = iL->second->insert(new list<string>);
                            for (list<string>::iterator iiR = (*iiiS)->begin(); iiR != (*iiiS)->end(); iiR++)
                                (*iiiiS.first)->push_back(*iiR);
                            for (list<string>::iterator iiR = tempString->begin(); iiR != tempString->end(); iiR++)
                                (*iiiiS.first)->push_back(*iiR);

                        }
                    }
                }
            }
        }
    }

    removeRecGDirect();
}

// Affiche un language
void Language::afficher(map<string,set<list<string>*, setComp>*>* l){

    if (l == 0)
        l = language;

    for (map<string,set<list<string>*, setComp>*>::iterator iL = l->begin(); iL != l->end(); iL++){
        ofs << iL->first << " ->";
        for (set<list<string>*>:: iterator iS = l->at(iL->first)->begin(); iS != l->at(iL->first)->end(); iS++){

            if (iS != l->at(iL->first)->begin())
                ofs << " | ";

            if ((*iS)->empty())
                ofs << "e";

            for (list<string>::iterator iR = (*iS)->begin(); iR != (*iS)->end(); iR++){
                if (*iR == "")
                    ofs << ".";
                else
                    ofs << *iR << " ";
            }
         }
        ofs << endl;
    }
}

// Affiche le parseur SLR
void Language::afficherSLR(map<int, map<string, set<int>*>*>* slr){

    if (slr == 0)
        slr = parseurSLR;

    ofs << "###################################################" << endl;
    ofs << "TABLEUR LSR" << endl;
    ofs << "###################################################" << endl;

    ofs << char(9);
    for (map<string, set<int>*>::iterator ii = slr->begin()->second->begin(); ii != slr->begin()->second->end(); ii++)
        ofs << ii->first << char(9);
    ofs << endl;

    for (map<int, map<string, set<int>*>*>::iterator i = slr->begin(); i != slr->end(); i++){
        ofs << i->first << char(9);
        for (map<string, set<int>*>::iterator ii = i->second->begin(); ii != i->second->end(); ii++){

            for (set<int>::iterator iS = ii->second->begin(); iS != ii->second->end(); iS++){
                if (iS != ii->second->begin())
                    ofs << "/";
                ofs << *iS;
            }
            ofs << char(9);
        }
        ofs << endl;
    }
    ofs << "###################################################" << endl;
}

vector<string>* Language::nonTerminaux(){

    vector<string>* nonT = new vector<string>;

    for (map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
    {
        nonT->push_back(iL->first);
    }

    /// Ici tu ne retournes pas un pointeur donc ton vecteur est supprimé (variable locale)
    return nonT;
}

vector<string>* Language::annulable(){

    /// Meme probleme que pour nonTerminaux()
    vector<string>* annule = new vector<string>;

    //On recupere les non terminaux ayant directement epsilon
    for(map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
    {
        for(set<list<string>*, setComp>::iterator iiL = iL->second->begin(); iiL != iL->second->end(); iiL++)
        {
            //s'il y a une liste vide, elle contien la regle epsilon
            if((*iiL)->empty())
                annule->push_back(iL->first);
        }
    }

    bool epsilon = true;
    bool cont = true;
    //On regarde pour chaque règle si les symbole sont annulable
    for(int j = 0; j < annule->size(); j++)
    {
        for(map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
        {
            /// Il faut remettre cont a true sinon pour les autres terminaux cont ne sera jamais a true
            cont = true;
            for(int k = 0; k < annule->size(); k++)
            {
                if(iL->first == annule->at(k))
                    cont = false;
            }
            if(cont)
            {

                for (set<list<string>*, setComp>:: iterator iS = (*language)[iL->first]->begin(); iS != (*language)[iL->first]->end(); iS++)
                {
                    //si chaque element de la règle font partie de l'ensemble annulable
                    // son point de départ en fait partie
                    list<string>:: iterator iR = (*iS)->begin();
                    while(iR != (*iS)->end()&&epsilon)
                    {
                        epsilon = false;
                        /// Si tu incrementes ici alors lorsque iR = --(*iS)->end(), iR deviendra (*iS)->end() et donc erreur de seg
                        //iR++;
                        for(int i = 0; i < annule->size(); i++)
                        {
                            if(*iR == annule->at(i))
                                epsilon = true;
                        }
                        /// Incrementes les iterateurs qu'a la fin de la boucle
                        iR++;
                    }
                    if(epsilon== true)
                        annule->push_back(iL->first);
                }
            }
        }
    }

    return annule;
}

map<string, set<string>*>* Language::getFirstSLR(){

    vector<string>* nonT = nonTerminaux();
    vector<string>* annule = annulable();
    map<string, set<string>* >* fSLR = new map<string, set<string>*>;
    bool cont = true;

    //on ajoute tous les premiers directe
    for(map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
    {
        (*fSLR)[iL->first] = new set<string>;

        for(set<list<string>*, setComp>::iterator iiL = iL->second->begin(); iiL != iL->second->end(); iiL++)
        {
            if (!(*iiL)->empty()){
                list<string>::iterator iiiL = (*iiL)->begin();
                cont = true;
                while(cont)
                {
                    cont = false;
                    //on ajoute le premier directe sauf lui même
                    if (iL->first != *iiiL)
                       (*fSLR)[iL->first]->insert(*iiiL);

                    /*si on peut annuler le terminaux actuellement visiter.
                    Passer à celui d'après*/

                    for(int i = 0; i < annule->size(); i++)
                    {
                        if(*iiiL == annule->at(i))
                        {
                            iiiL++;
                            if(iiiL != (*iiL)->end()){

                                cont = true;
                            }
                            else{

                                // Si nous arrivons a la fin de la regle alors "" est un first
                                (*fSLR)[iL->first]->insert("");
                            }
                        }
                    }
                }
            }
            else{
                // Si la liste est vide je rajoute "" representant epsilon dans les first
                (*fSLR)[iL->first]->insert("");
            }
        }
    }

    bool hasAdd;

    do{

        hasAdd = false;

        //verifie pour chaque ensemble de premier s'il est non terminal. Si oui. Ajout de ses premiers
        for(map<string, set<string>*>::iterator iL = fSLR->begin(); iL != fSLR->end(); iL++)
        {
            for (set<string>::iterator iS = iL->second->begin(); iS != iL->second->end(); iS++)
            {
                for(int i = 0; i < nonT->size(); i++)
                {
                    //si c'est un element non terminal
                    if(*iS == nonT->at(i)){
                           //on recupere ses premiers
                        for(set<string>::iterator iiS = ((*fSLR)[*iS])->begin(); iiS != ((*fSLR)[*iS])->end(); iiS++)
                        {
                            if((*iiS != iL->first)&&(!iiS->empty())&&(*iiS != iL->first)){
                            //verifie si ajout d'un nouveau element
                                pair<set<string>::iterator, bool> iiR = (*fSLR)[iL->first]->insert(*iiS);
                                if (iiR.second)
                                    hasAdd = true;
                            }
                        }

                        (*fSLR)[iL->first]->erase(*iS);
                    }
                }
            }
        }

    }while (hasAdd);

    ofs << "FIRST" << endl;
    ofs << "###################################################" << endl;
    for (map<string, set<string>*>::iterator i = fSLR->begin(); i != fSLR->end(); i++){
        ofs << "FIRST(" << i->first << ") = ";
        for (set<string>::iterator ii = i->second->begin(); ii != i->second->end(); ii++){
            if (*ii == "")
                ofs << "e";
            else
                ofs << *ii;

            ofs << ".";
        }
        ofs << endl;
    }
    ofs << "###################################################" << endl;

    delete nonT;
    delete annule;

    return fSLR;
}

map<string, set<string>*>* Language::getFollowSLR(){

    vector<string>* nonT = nonTerminaux();
    vector<string>* annule = annulable();
    map<string, set<string>* >* fSLR = getFirstSLR();
    map<string, set<string>* >* follSLR = new map<string, set<string>*>;
    bool cont = true;
    bool passage = false;

    for(int i = 0; i < nonT->size(); i++)
    {
        (*follSLR)[nonT->at(i)] = new set<string>;
        for(map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
        {
            for(set<list<string>*, setComp>::iterator iiL = iL->second->begin(); iiL != iL->second->end(); iiL++)
            {
                // On verifie si l'element n'est pas l'element etudie
                for(list<string>::iterator iiiL = (*iiL)->begin(); iiiL != (*iiL)->end(); iiiL++)
                {
                    list<string>::iterator iR = iiiL;
                    iR++;
                    if((*iiiL)==nonT->at(i))
                    {
                        passage = false;

                        if(iiiL == --(*iiL)->end()&& !passage)
                        {
                            passage = true;
                            //Ajouts des etats non terminaux qui devront etre traite apres
                            if(iL->first != nonT->at(i))
                                (*follSLR)[nonT->at(i)]->insert(iL->first);
                        }

                        //si les éléments suivants sont annulables
                        list<string>::iterator iM = iR;
                        while ((!passage)&&(iM != (*iiL)->end()))
                        {
                                //si c'est un element non terminal -> récupérer ses premiers
                                passage = false;

                                // Nous sommes a un symbole donne
                                // Nous ajoutons donc ces premiers ou le symbole s'il est terminaux
                                for(int j = 0; j < nonT->size(); j++)
                                {
                                    if((*iM) == nonT->at(j)&&!passage)
                                    {
                                        passage = true;
                                        (*follSLR)[nonT->at(i)]->insert((*fSLR)[nonT->at(j)]->begin(), (*fSLR)[nonT->at(j)]->end());
                                    }
                                }

                                if(!passage)
                                    (*follSLR)[nonT->at(i)]->insert(*iM);

                                passage = true;

                                // Si notre symbole actuel est annulable et n'est pas en fin de regle
                                // alors nous passons au suivant
                                for(int j = 0; j < annule->size() ; j++)
                                {
                                    if((*iM)==annule->at(j)&&!passage)
                                    {
                                        passage = false;
                                        //si c'est le dernier element on est en fin de regle
                                        if(iM == --(*iiL)->end())
                                        {
                                            if(iL->first != nonT->at(i))
                                                (*follSLR)[nonT->at(i)]->insert(iL->first);

                                            passage = true;
                                        }
                                    }
                                }
                            iM++;
                        }
                    }
                }
            }
        }
    }

    //rajout du symbol de cloture
    (*follSLR)[axiome]->insert("$");

    bool hasAdd;
    //Parcour des follows
    //tous les etats non terminaux restant sont remplace par leurs suivants
    do{
        hasAdd = false;

        for (map<string, set<string>*>::iterator i = follSLR->begin(); i != follSLR->end(); i++)
        {
            for (set<string>::iterator ii = i->second->begin(); ii != i->second->end(); ii++)
            {

                for(int j = 0; j < nonT->size(); j++)
                {
                    //On récupere les suivants du symbol
                    if(*ii == nonT->at(j))
                    {
                        for(set<string>::iterator iiS = ((*follSLR)[*ii])->begin(); iiS != ((*follSLR)[*ii])->end(); iiS++)
                        {
                            if(*iiS != i->first)
                            {
                                 pair<set<string>::iterator, bool> iR = (*follSLR)[i->first]->insert(*iiS);
                                if(iR.second)
                                    hasAdd = true;
                            }
                        }
                        //on supprime l'etat non terminal etudie
                        (*follSLR)[i->first]->erase(*ii);
                    }
                }
            }

            // Nous retirons "" des follows si jamais il y en avait dans les firsts
            (*follSLR)[i->first]->erase("");
        }

    }while (hasAdd);

    ofs << "FOLLOW" << endl;
    ofs << "###################################################" << endl;
    for (map<string, set<string>*>::iterator i = follSLR->begin(); i != follSLR->end(); i++)
    {
        ofs << "FOLLOW(" << i->first << ") = ";
        for (set<string>::iterator ii = i->second->begin(); ii != i->second->end(); ii++)
            ofs << *ii << ".";
        ofs << endl;
    }
    ofs << "###################################################" << endl;

    delete nonT;
    delete annule;
    deleteMapSet(fSLR);

    return follSLR;
}

// Cree le parseur SLR
void Language::calculParseurSLR(){

    parseurSLR = new map<int, map<string, set<int>*>*>;

    // Contient les etats terminaux sans le nouvel axiome, non terminaux et le symbole '$'
    set<string>* listTNT = new set<string>;

    // Contient tout les etats obtenus
    list<map<string, set<list<string>*, setComp>*>*>* listState = new list<map<string, set<list<string>*, setComp>*>*>;
    // Contient les etats obtenus qui n'ont pas encore ete analyses
    list<map<string, set<list<string>*, setComp>*>*>* open = new list<map<string, set<list<string>*, setComp>*>*>;

    // Calcul d'un nouvel axiome
    string newAxiome = axiome + axiome;
    while (language->find(newAxiome) != language->end())
        newAxiome += axiome;

    // Creation de la regle du nouvel axiome (nouveauAxiome->ancienAxiome)
    pair<set<list<string>*>::iterator, bool> iS;
    (*language)[newAxiome] = new set<list<string>*, setComp>;
    iS = language->at(newAxiome)->insert(new list<string>);
    (*iS.first)->push_back(axiome);

    axiome = newAxiome;

    map<string, set<string>*>* followSLR = getFollowSLR();

    // Creation de l'etat I0 en ajoutant "" (representant le ".") au debut de chaque regle
    for (map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++){

        listTNT->insert(iL->first);
        for (set<list<string>*>::iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){

            for (list<string>::iterator iR = (*iS)->begin(); iR != (*iS)->end(); iR++)
                listTNT->insert(*iR);

            (*iS)->push_front("");
        }
    }

    listTNT->insert("$");
    listTNT->erase(axiome);

    listState->push_back(language);

    // Contient les shifts pour chaque symbole et pour chaque etat
    // -1 represente une absence de shift
    map<int, map<string, int>*>* shift = new map<int, map<string, int>*>;

    // Creation de tout les etats à partir de I0
    open->push_back(language);

    int cpt1 = 0;
    while (!open->empty()){

        (*shift)[cpt1] = new map<string, int>;

        for (set<string>::iterator iTNT = listTNT->begin(); iTNT != listTNT->end(); iTNT++){

            // Si le symbole est '$' nous savons que le goTo(i, '$') ne donnera rien
            if (*iTNT != "$"){

                bool newState = true;
                map<string, set<list<string>*, setComp>*>* i = goTo(open->front(), *iTNT);

                // Si un etat a ete cree
                if (!i->empty()){

                    int cpt2 = 0;

                    // Nous testons si cet etat n'a pas deja ete cree
                    for (list<map<string,set<list<string>*, setComp>*>*>::iterator iState = listState->begin(); iState != listState->end(); iState++){

                        if ((newState)&&(compareLanguage(i, *iState))){

                            (*shift->at(cpt1))[*iTNT] = cpt2;
                            newState = false;
                        }

                        cpt2++;
                    }

                    // Si c'est un nouvel etat
                    if (newState){

                        (*shift->at(cpt1))[*iTNT] = cpt2;
                        listState->push_back(i);
                        open->push_back(i);
                    }
                }
            }
        }
        cpt1++;

        open->pop_front();
    }

    ofs << "###################################################" << endl;
    ofs << "ETAT PARSEUR LSR" << endl;
    ofs << "###################################################" << endl;
    for (list<map<string,set<list<string>*, setComp>*>*>::iterator iShift = listState->begin(); iShift != listState->end(); iShift++){
        afficher(*iShift);
        ofs << endl;
    }

    ofs << "###################################################" << endl;
    ofs << "GOTO LSR" << endl;
    ofs << "###################################################" << endl;

    for (int cpt1 = 0; cpt1 < listState->size(); cpt1++){
        for (set<string>::iterator iTNT = listTNT->begin(); iTNT != listTNT->end(); iTNT++){
            if (shift->at(cpt1)->find(*iTNT) != shift->at(cpt1)->end())
                ofs << "GOTO(I" << cpt1 << ", " << *iTNT << ") = I" << shift->at(cpt1)->at(*iTNT) << endl;
        }
    }

    ofs << "###################################################" << endl;

    // Initialisation du parseur SLR

    for (int cpt1 = 0; cpt1 < listState->size(); cpt1++){

        (*parseurSLR)[cpt1] = new map<string, set<int>*>;

        for (set<string>::iterator iTNT = listTNT->begin(); iTNT != listTNT->end(); iTNT++){
            (*parseurSLR->at(cpt1))[*iTNT] = new set<int>;
        }
    }

    // Place les shifts dans le parseur
    //iShift = shift->begin();
    for (int cpt1 = 0; cpt1 < listState->size(); cpt1++){
        for (set<string>::iterator iTNT = listTNT->begin(); iTNT != listTNT->end(); iTNT++){
            if (shift->at(cpt1)->find(*iTNT) != shift->at(cpt1)->end())
                parseurSLR->at(cpt1)->at(*iTNT)->insert(shift->at(cpt1)->at(*iTNT));
        }
        //iShift++;
    }

    // Place les reduces dans le parseur
    cpt1 = 0;
    pair<list<string>*, list<list<string>*>*>* endRule;
    for (list<map<string,set<list<string>*, setComp>*>*>::iterator iState = listState->begin(); iState != listState->end(); iState++){

        // Pour chaque etat nous cherchons les regles avec un "" a la fin
        endRule = getEndRule(*iState);

        if (!endRule->second->empty()){

            list<string>::iterator iT = endRule->first->begin();

            for (list<list<string>*>::iterator iER = endRule->second->begin(); iER != endRule->second->end(); iER++){

                // Recupere le numero de la regle concernee
                int num = getRuleNum(*iT, *iER);

                for (set<string>::iterator iTNT = listTNT->begin(); iTNT != listTNT->end(); iTNT++){

                    // Si le symbole appartient au suivant de la partie gauche de la regle
                    // alors l'etat a un reduce pour ce symbole noté -numeroDeLaRegle
                    if (followSLR->at(*iT)->find(*iTNT) != followSLR->at(*iT)->end())
                        parseurSLR->at(cpt1)->at(*iTNT)->insert(-num);
                }
                iT++;
            }
        }
        cpt1++;
    }

    listState->remove(language);

    for (map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++)
        for (set<list<string>*, setComp>::iterator iS = iL->second->begin(); iS != iL->second->end(); iS++)
                (*iS)->pop_front();

    delete listTNT;
    deleteListLanguage(listState);
    deleteMapMap(shift);
    deleteMapSet(followSLR);
}

// Retourne l'etat cree par le goTo(etat, symbole)
map<string, set<list<string>*, setComp>*>* Language::goTo(map<string, set<list<string>*, setComp>*>* i, string s){

    map<string, set<list<string>*, setComp>*>* newI = new map<string, set<list<string>*, setComp>*>;

    // Pour toutes les regles dans i
    for (map<string,set<list<string>*, setComp>*>::iterator iL = i->begin(); iL != i->end(); iL++){
        for (set<list<string>*>:: iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){

            // Cherche l'endroit ou est le ""
            list<string>::iterator iR = (*iS)->begin();
            while ((iR != --((*iS)->end()))&&(!iR->empty()))
                iR++;
            iR++;

            if (iR != (*iS)->end()){
                // Si le symbole qui est apres le "" est egal au symbole
                if (*iR == s){

                    // Ajoute une regle au nouvel etat
                    if (newI->find(iL->first) == newI->end())
                        (*newI)[iL->first] = new set<list<string>*, setComp>;

                    pair<set<list<string>*>::iterator,bool> iiS;
                    iiS = newI->at(iL->first)->insert(new list<string>);

                    // Ajoute la regle de l'etat i jusqu'au ""
                    list<string>::iterator iiR = (*iS)->begin();
                    while ((iiR != (*iS)->end())&&(!iiR->empty())){
                        (*iiS.first)->push_back(*iiR);
                        iiR++;
                    }
                    iiR++;

                    // Deplace le "" dans le nouvel etat
                    (*iiS.first)->push_back(*iiR);
                    (*iiS.first)->push_back("");

                    iiR++;

                    // Si un symbole suit le "" dans le nouvel etat
                    if (iiR != (*iS)->end()){

                        // Nous ajoutons toutes les regles de ce symbole
                        // Comme nous avons un set de regles (representes par des listes), nous n'avons pas de doublon de regle
                        if (language->find(*iiR) != language->end()){
                            for (set<list<string>*, setComp>::iterator iiiS = language->at(*iiR)->begin(); iiiS != language->at(*iiR)->end(); iiiS++){

                                    if (newI->find(*iiR) == newI->end())
                                        (*newI)[*iiR] = new set<list<string>*, setComp>;

                                    newI->at(*iiR)->insert(copyListString(*iiiS));
                            }
                        }

                        // Nous ajoutons la fin de la regle precedemment cree
                        while (iiR != (*iS)->end()){
                            (*iiS.first)->push_back(*iiR);
                            iiR++;
                        }
                    }
                }
            }
        }
    }

    bool hadAdd;

    // Verifie si une des regles que nous avons ajoutee ne contient pas un symbol non terminal au debut de la regle
    do{

        hadAdd = false;
        for (map<string,set<list<string>*, setComp>*>::iterator iL = newI->begin(); iL != newI->end(); iL++){
            for (set<list<string>*, setComp>:: iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){\

                if ((*iS)->size() > 1){

                    list<string>::iterator iR = (*iS)->begin();

                    if (*iR == ""){

                        iR++;

                        if (language->find(*iR) != language->end()){

                            for (set<list<string>*, setComp>::iterator iiS = language->at(*iR)->begin(); iiS != language->at(*iR)->end(); iiS++){

                                if (newI->find(*iR) == newI->end())
                                    (*newI)[*iR] = new set<list<string>*, setComp>;

                                pair<set<list<string>*, setComp>::iterator, bool> iiR = newI->at(*iR)->insert(copyListString(*iiS));
                                if (iiR.second)
                                    hadAdd = true;
                            }
                        }
                    }
                }
            }
        }

    }while (hadAdd);

    return newI;
}

// Retourne les regles finissant par ""
pair<list<string>*, list<list<string>*>*>* Language::getEndRule(map<string, set<list<string>*, setComp>*>* i){

    pair<list<string>*, list<list<string>*>*>* endRule = new pair<list<string>*, list<list<string>*>*>;
    endRule->first = new list<string>;
    endRule->second = new list<list<string>*>;

    for (map<string,set<list<string>*, setComp>*>::iterator iL = i->begin(); iL != i->end(); iL++){
        for (set<list<string>*>:: iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){
            if ((*iS)->back() == ""){
                endRule->second->push_back(*iS);
                endRule->first->push_back(iL->first);
            }
        }
    }

    return endRule;
}

// Retourne le numero d'une regle de la forme t->rule
int Language::getRuleNum(string t, list<string>* rule){

    int num = 1;
    for (map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++){
        if (t == iL->first){
            for (set<list<string>*>:: iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){
                if (compareRule(rule, *iS))
                    return num;
                else
                    num++;
            }
        }
        else{
            num += iL->second->size();
        }
    }

    return -1;
}

// Initialise du test de la reconnaissance d'un mot pour l'algorithme recursif
bool Language::testMot(list<string> mot){

    ofs << "###################################################" << endl;
    ofs << "LECTURE MOT" << endl;

    if (parseurSLR == 0)
        return false;

    list<string> pile;

    pile.push_front("$");
    pile.push_front("0");

    mot.push_back("$");

    return testMotRec(pile, mot);
}

// Test de la reconnaissance d'un mot
bool Language::testMotRec(list<string> pile, list<string> mot){


    ofs << "###################################################" << endl;

    ofs << "MOT : ";
    for (list<string>::iterator i = mot.begin(); i != mot.end(); i++)
        ofs << *i << ".";
    ofs << endl;

    ofs << "STACK : ";
    for (list<string>::iterator i = pile.begin(); i != pile.end(); i++)
        ofs << *i << ".";
    ofs << endl;

    char buffer[33];
    list<string> pileTemp;
    list<string> motTemp;

    // Si le symbole dans le mot n'appartient pas au langage
    if (parseurSLR->at(atoi(pile.front().c_str()))->find(mot.front()) == parseurSLR->at(atoi(pile.front().c_str()))->end())
        return false;

    // Contient les shifts et reduces en fonction de l'etat en haut de la pile et le symbole du mot a lire
    set<int>* action = parseurSLR->at(atoi(pile.front().c_str()))->at(mot.front());

    for (set<int>::iterator i = action->begin(); i != action->end(); i++){

        pileTemp = pile;
        motTemp = mot;

        // Si nous avons un shift
        if (*i > -1){

            pileTemp.push_front(motTemp.front());
            pileTemp.push_front(string(itoa(*i, buffer, 10)));

            motTemp.pop_front();
        }
        else{

            pair<string, list<string>*>* rule = getRule(-(*i));

            for (int cpt = 0; cpt < rule->second->size()*2; cpt++)
                pileTemp.pop_front();

            // Correspond a l'acc dans le parseur (nous faisons un reduce sur l'axiome)
            if ((mot.front() == "$")&&(rule->first == axiome))
                return true;

            int e = atoi(pileTemp.front().c_str());

            pileTemp.push_front(rule->first);

            // Si aucun shift pour ce symbole est present dans le parseur pour l'etat e
            if (parseurSLR->at(atoi(pileTemp.front().c_str()))->at(rule->first)->empty())
                return false;

            // Ajouter l'etat a la pile (il ne doit y en avoir qu'une sinon le parseur est mal construit)
            pileTemp.push_front(string(itoa(*parseurSLR->at(e)->at(rule->first)->begin(), buffer, 10)));

            delete rule;
        }

        if (testMotRec(pileTemp, motTemp))
            return true;
    }

    return false;
}

// Recupere une regle a partir de son numero
pair<string, list<string>*>* Language::getRule(int nb){

    pair<string, list<string>*>* rule = new pair<string, list<string>*>;

    for (map<string,set<list<string>*, setComp>*>::iterator iL = language->begin(); iL != language->end(); iL++){
        for (set<list<string>*>:: iterator iS = iL->second->begin(); iS != iL->second->end(); iS++){
            if (nb == 1){
                rule->first = iL->first;
                rule->second = *iS;
                return rule;
            }
            else{
                nb--;
            }
        }
    }

    return rule;
}

// Copie une liste de string en profondeur
list<string>* Language::copyListString(list<string>* l){

    list<string>* copyL = new list<string>;

    for (list<string>::iterator iR = l->begin(); iR != l->end(); iR++)
        copyL->push_back(*iR);

    return copyL;
}

// Compare 2 languages en prennnant en compte les ""
bool Language::compareLanguage(map<string, set<list<string>*, setComp>*>* l1, map<string, set<list<string>*, setComp>*>* l2){

    if ((l1 == 0)||(l2 == 0))
        return false;

    if (l1->size() != l2->size())
        return false;

    for (map<string,set<list<string>*, setComp>*>::iterator iL = l1->begin(); iL != l1->end(); iL++){

        if (l2->find(iL->first) == l2->end())
            return false;

        if (l1->at(iL->first)->size() != l2->at(iL->first)->size())
            return false;

        set<list<string>*>:: iterator iS = iL->second->begin();
        set<list<string>*>:: iterator iiS = l2->at(iL->first)->begin();
        while ((iS != iL->second->end())&&(iiS != l2->at(iL->first)->end())){

            if ((*iS)->size() != (*iiS)->size())
                return false;

            list<string>::iterator iiR = (*iiS)->begin();
            list<string>::iterator iR = (*iS)->begin();
            while ((iR != (*iS)->end())&&(iiR != (*iiS)->end())){

                if (*iR != *iiR)
                    return false;

                iR++;
                iiR++;
            }

            iS++;
            iiS++;
         }
    }

    return true;
}

// Compare 2 regles sans prendre en compte les ""
bool Language::compareRule(list<string>* l1,list<string>* l2){

    if ((l1 == 0)||(l2 == 0))
        return false;

    if (l1->size() != l2->size())
        return false;

    list<string>::iterator iiR = l2->begin();
    list<string>::iterator iR = l1->begin();
    while ((iR != l1->end())&&(iiR != l2->end())){

        if (*iR == "")
            iR++;

        if (iR == l1->end())
            return true;

        if (*iiR == "")
            iiR++;

        if (iiR == l2->end())
            return true;

        if (*iR != *iiR)
            return false;

        iR++;
        iiR++;
    }

    return true;
}

void Language::deleteLanguage(map<string, set<list<string>*, setComp>*>* l){

    for (map<string,set<list<string>*, setComp>*>::iterator iL = l->begin(); iL != l->end(); iL++){
        for (set<list<string>*>:: iterator iS = l->at(iL->first)->begin(); iS != l->at(iL->first)->end(); iS++){
            delete *iS;
         }

         delete iL->second;
    }

    delete l;

    l = 0;
}

void Language::deleteListLanguage(list<map<string, set<list<string>*, setComp>*>*>* l){

    for (list<map<string, set<list<string>*, setComp>*>*>::iterator i = l->begin(); i != l->end(); i++)
        delete *i;

    delete l;

    l = 0;
}

void Language::deleteMapMap(map<int, map<string, int>*>* m){

    for (map<int, map<string, int>*>::iterator i = m->begin(); i != m->end(); i++)
        delete i->second;

    delete m;

    m = 0;
}

void Language::deleteMapSet(map<string, set<string>*>* m){

    for (map<string, set<string>*>::iterator i = m->begin(); i != m->end(); i++)
        delete i->second;

    delete m;

    m = 0;
}

void Language::deleteParseur(map<int, map<string, set<int>*>*>* m){

    for (map<int, map<string, set<int>*>*>::iterator i = m->begin(); i != m->end(); i++){
        for (map<string, set<int>*>::iterator ii = i->second->begin(); ii != i->second->end(); ii++)
            delete ii->second;

        delete i->second;
    }

    delete m;

    m = 0;
}
