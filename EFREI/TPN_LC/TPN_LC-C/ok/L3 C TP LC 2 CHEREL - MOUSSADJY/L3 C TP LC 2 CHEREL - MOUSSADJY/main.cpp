#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct{
    char nom; // non-terminal à gauche [S] -> Sa
    std::string symboles; // règle de production S -> [Sa]
    int curseur; // positionnement du "."
} t_regle;

struct s_item;

typedef struct{
    struct s_item * itemCible;
    char symbole;
} t_transition;

typedef struct s_item{
    unsigned int numero;
    std::vector<t_regle> regles; // règles de prod
    std::vector<t_transition> transitions; // lien symbole - item
} t_item, *t_graphe;

typedef struct {
    char symbole;
    std::vector<char> firsts;
} t_first;

typedef struct {
    char symbole;
    std::vector<char> follows;
} t_follow;

struct s_mot;
typedef struct {
    std::vector<struct s_mot*> mots;
    unsigned int numero;
} t_etat;

typedef struct s_mot{
    char symbole;
    t_item* item;
    std::vector<t_regle*> regles;
} t_mot;

typedef struct {
    char pile[2];
} t_pile;

vector<t_regle> grammaire;
vector<t_first*> first;
vector<t_follow*> follow;
vector<t_etat*> tableAnalyse;
t_graphe graphe;

// lecture de fichier et création de graphe
void afficheItem(t_item * item);
void lireFichier(std::ifstream &fichier);
void creerGraphe(std::vector<t_item*> &listeItems);
bool comparerItems (const t_item * item1, const t_item * item2);
bool comparerRegles (const t_regle &regle1, const t_regle &regle2);
void creationTransitions(t_item * itemCourant, std::vector<t_item*> &listeItems);
void ajoutReglesEnFonctionDuSymbole (const char symbole, std::vector<t_regle> &listeRegles);
t_item * creationItem(const t_item * itemPrec, const char symbole, std::vector<t_item*> &listeItems);

// first
void ajouterFirst(t_first * ff, char symbole);
void trouverFirsts(char regleChoisie);
void affichageFirsts();

// follow
void trouverFollows();
void remplirFollows(int curseurGrammaire, int curseurSymboles, char symboleOrigine, bool auBout);
void remplirFollows(int curseurGrammaire, int curseurSymboles, char symboleOrigine);
void affichageFollows();

// fonctions usuelles
bool estTerminal (const char S);
bool estNonTerminal (const char S);
bool estVide(const t_regle * regle);

// table d'analyse
void creationTableAnalyse();
void affichageTableAnalyse();

// execution
bool execution(std::string mot);
bool etapeExecution(std::string mot, int cursEtat, std::vector<t_pile> pile, std::string affichage, bool &impasse);


bool execution(string mot){

    vector<t_pile> pile;
    cout << "Pile\t\tEntree\t\tSortie" << endl;
    bool impasse = false;
    return etapeExecution(mot, 0, pile, "", impasse);
}

bool etapeExecution(string mot, int cursEtat, vector<t_pile> pile, string affichage, bool &impasse) {

    /*** Début affichage ***/
    if(affichage != "")
        cout << affichage;
    if(impasse){
        cout << "[IMPASSE]" << endl << "------------" << endl;
        impasse = false;
    }
    else {
        cout << endl;
    }
    cout << "0";
    for(int k=0;k<pile.size();k++){
        cout << pile[k].pile[1] << ((int)pile[k].pile[0]);
    }
    cout << "\t\t" << mot << "\t";
    /*** Fin affichage ***/

    if(mot.size() == 1 && mot[0] == '$' && cursEtat == 1){
        cout << "On est arrivés à la 1ere regle" << endl;
        return true;
    }

    int cursLettre = 0, cursRegle = 0, cursEtatRegle = 0;
    bool itemTeste = false;
    t_pile transition;
    string motEnvoye = "";

    // on parcourt l'état de notre table d'analyse à la recherche du mot correspondant à la lettre sous le curseur
    // si le mot n'est pas vide
    if(mot.length() > 0){ /// si le mot lu n'est pas vide
        for(int i=0;i<tableAnalyse[cursEtat]->mots.size();i++){ /// on parcourt les symboles qui ont soit une regle soit un item cible associés
            if(tableAnalyse[cursEtat]->mots[i]->symbole == mot[0]){ /// quand la première lettre du mot lu correspond à un symbole pré-cité, alors:
                /// si notre symbole a un item cible associé(!= vide) alors on execute la même fonction pour le mot moins la première lettre
                if(tableAnalyse[cursEtat]->mots[i]->item != NULL){
                    if(mot.length() > 1){                           /// si notre mot lu a une longueur <= 1, on le laisse tel quel (pour le $)
                        motEnvoye = mot.substr(1);                  /// sinon, on lui enlève sa première lettre
                    }
                    else {
                        motEnvoye = mot;
                    }

                    /// on ajoute à la pile le mot de sortie + l'état courant ex: a1
                    transition.pile[0] = tableAnalyse[cursEtat]->mots[i]->item->numero;
                    transition.pile[1] = mot[0];
                    pile.push_back(transition);
                    affichage = "s";
                    affichage += ((char)(transition.pile[0]+48));
                    itemTeste = true;
                }
                if(tableAnalyse[cursEtat]->mots[i]->item != NULL && etapeExecution(motEnvoye,tableAnalyse[cursEtat]->mots[i]->item->numero, pile, affichage, impasse)){
                    /// si ce mot a été complété par l'execution de cette fonction alors on renvoie true
                    return true;
                }
                else {
                    /// si on n'a pas réussi à finir le mot via la sortie précédente ou qu'on pas de sortie (item cible) associé,
                    /// alors on dépile la dernière occurence (a1)
                    if(itemTeste){
                        if(pile.size() > 0)
                            pile.pop_back();
                        itemTeste = false;
                    }
                    // si aller vers l'itemCible n'a pas marché, on tente les règles
                    // on parcourt donc toutes les règles liées à notre symbole
                    for(int j=0;j<tableAnalyse[cursEtat]->mots[i]->regles.size();j++){
                        /// on met le curseur de notre règle à droite de la règle, pour revenir progressivement vers la gauche
                        cursRegle = tableAnalyse[cursEtat]->mots[i]->regles[j]->symboles.size();
                        /// tant qu'on est pas revenus tout à gauche, on parcourt la règle etababa on dépile
                        for(int m=cursRegle;m>0;m--) {
                            if(pile.size() > 0)
                                pile.pop_back();
                        }
                        /// l'état d'où on vient est donc celui juste avant le dernier qu'on a dépilé

                        if((int)pile.size() > 0){
                            cursEtatRegle = pile[(int)pile.size()-1].pile[0];
                        }
                        else {
                            cursEtatRegle = 0;
                        }

                        /// on parcourt tous les symboles liés à cet état (si on a S -> ab, et 0a1b2, on dépile a1b2 et on cherche S dans les possibilités)
                        for(int k=0;k<tableAnalyse[cursEtatRegle]->mots.size();k++){
                            /// lorsqu'on tombe sur le mot associé au non terminal à gauche de notre règle que l'on vient de dépiler
                            /// --> on execute la meme fonction pour ce mot
                            if(tableAnalyse[cursEtatRegle]->mots[k]->symbole == tableAnalyse[cursEtat]->mots[i]->regles[j]->nom){
                                /// on ajoute à la pile le mot de sortie + l'état courant ex: a1

                                transition.pile[0] = tableAnalyse[cursEtatRegle]->mots[k]->item->numero;
                                transition.pile[1] = tableAnalyse[cursEtat]->mots[i]->regles[j]->nom;
                                pile.push_back(transition);


                                affichage = tableAnalyse[cursEtat]->mots[i]->regles[j]->nom;
                                affichage += " => `";
                                affichage += tableAnalyse[cursEtat]->mots[i]->regles[j]->symboles;
                                affichage += "`";



                                if(etapeExecution(mot,tableAnalyse[cursEtatRegle]->mots[k]->item->numero,pile,affichage, impasse)){
                                    return true;
                                }
                                else {
                                    if(pile.size() > 0)
                                        pile.pop_back();
                                }
                            }
                        }
                    }
                }
                return false;
            }
        }
        impasse = true;
        return false;
    }
    return false;
}
/*
    tableAnalyse:
        - des états
            - des mots
                - un symbole cible
                - des sommets atteignables (t_item)
                - des règles valides
                    - les symboles qui la composent
                    - un curseur de position
                    - un nom "non terminal à gauche"

*/
void creationEtatTableAnalyse(vector<int> &dejaPasses, t_item * itemCourant){

    for(int i=0;i<dejaPasses.size();i++){
        if(dejaPasses[i] == itemCourant->numero)
            return;
    }

    t_etat * etatCourant = new t_etat();
    etatCourant->numero = itemCourant->numero;
    dejaPasses.push_back(itemCourant->numero);
    tableAnalyse.push_back(etatCourant);

    t_mot * motCourant;
    t_regle * regleCourante;
    t_follow * followsRegle;


    // on commence par recenser les transitions qui partent de notre état
    for(int i=0;i<itemCourant->transitions.size(); i++){
        motCourant = new t_mot();
        motCourant->symbole = itemCourant->transitions[i].symbole;
        motCourant->item = itemCourant->transitions[i].itemCible;
        etatCourant->mots.push_back(motCourant);
        creationEtatTableAnalyse(dejaPasses,itemCourant->transitions[i].itemCible);
    }

    // on continue en recensant les réductions dans notre état
    bool motExiste = false;
    for(int i=0;i<itemCourant->regles.size(); i++){
        if(itemCourant->regles[i].curseur == itemCourant->regles[i].symboles.size()){
            regleCourante = new t_regle();
            regleCourante->curseur = itemCourant->regles[i].curseur;
            regleCourante->symboles = itemCourant->regles[i].symboles;
            regleCourante->nom = itemCourant->regles[i].nom;

            followsRegle = NULL;
            for(int j=0;j<follow.size();j++){
                if(follow[j]->symbole == regleCourante->nom){
                    followsRegle = follow[j];
                    break;
                }
            }
            if(followsRegle != NULL){
                for(int j=0;j<followsRegle->follows.size(); j++){
                    for(int k=0;k<etatCourant->mots.size(); k++){
                        motCourant = etatCourant->mots[k];
                        if(motCourant->symbole == followsRegle->follows[j]){
                            motCourant->regles.push_back(regleCourante);
                            motExiste = true;
                        }
                    }
                    if(!motExiste){
                        motCourant = new t_mot();
                        motCourant->item = NULL;
                        motCourant->symbole = followsRegle->follows[j];
                        motCourant->regles.push_back(regleCourante);
                        etatCourant->mots.push_back(motCourant);
                    }
                }
            }
            else {
                for(int k=0;k<etatCourant->mots.size(); k++){
                    motCourant = etatCourant->mots[k];
                    if(motCourant->symbole == '$'){
                        motCourant->regles.push_back(regleCourante);
                        motExiste = true;
                    }
                }
                if(!motExiste){
                    motCourant = new t_mot();
                    motCourant->item = NULL;
                    motCourant->symbole = '$';
                    motCourant->regles.push_back(regleCourante);
                    etatCourant->mots.push_back(motCourant);
                }
            }
        }
    }
}

void creationTableAnalyse() {
    vector<int> itemsPasses;
    t_item * itemCourant = graphe;

    creationEtatTableAnalyse(itemsPasses,itemCourant);
}

void affichageTableAnalyse() {
    cout << endl << endl << "Table d'analyse: " << endl;

    for(int i=0;i<tableAnalyse.size();i++) {
        cout << "etat " << tableAnalyse[i]->numero << ":" << endl;
        for(int j=0;j<tableAnalyse[i]->mots.size();j++){
            cout << "  " << tableAnalyse[i]->mots[j]->symbole << ": ";
            if(tableAnalyse[i]->mots[j]->item != NULL){
                cout << tableAnalyse[i]->mots[j]->item->numero << "/";
            }
            cout << "{" ;
            for(int k=0; k<tableAnalyse[i]->mots[j]->regles.size(); k++){
                cout  << tableAnalyse[i]->mots[j]->regles[k]->nom << " => ";
                if(tableAnalyse[i]->mots[j]->regles[k]->symboles.size() == 0){
                    cout << "epsilon";
                }
                else {
                    cout << tableAnalyse[i]->mots[j]->regles[k]->symboles;
                }
                if(k<tableAnalyse[i]->mots[j]->regles.size()-1)
                    cout << ", ";
            }
            cout << "}" << endl;
        }
    }

}

void affichageFollows(){
    cout << "Follows:" << endl;
    for(int i=0;i<follow.size();i++){
        cout << follow[i]->symbole << ": ";
        for(int j=0;j<follow[i]->follows.size();j++){
            if(follow[i]->follows[j] == '.'){
                cout << "epsilon";
            }
            else {
                cout << follow[i]->follows[j];
            }
            cout <<" ";
        }
        cout << endl;
    }
}

void ajouterFollow(t_follow * ff, char symbole) {

    for(int i=0;i<ff->follows.size();i++){
        if(ff->follows[i] == symbole){
            return;
        }
    }

    ff->follows.push_back(symbole);
    return;
}

void remplirFollowsViaFollows(char nomRegle, char symboleOrigine) {
    if(symboleOrigine==nomRegle){
        return;
    }

    t_follow * f1;
    t_follow * f2;
    for(int i=0;i<follow.size();i++){
        if(follow[i]->symbole == nomRegle){
            f1 = follow[i];
        }
        else if(follow[i]->symbole == symboleOrigine){
            f2 = follow[i];
            for(int j=0;j<f1->follows.size();j++){
                ajouterFollow(f2,f1->follows[j]);
            }
        }
    }
}

void remplirFollows(int curseurGrammaire, int curseurSymboles, char symboleOrigine){
    remplirFollows(curseurGrammaire,curseurSymboles,symboleOrigine,false);
}

void remplirFollows(int curseurGrammaire, int curseurSymboles, char symboleOrigine, bool auBout){

    if(curseurGrammaire >= grammaire.size() || curseurSymboles >= grammaire[curseurGrammaire].symboles.size())
        return;

    bool contientEpsilon = false;
    if(estNonTerminal(grammaire[curseurGrammaire].symboles[curseurSymboles])){
        if(grammaire[curseurGrammaire].symboles.size()-1 == curseurSymboles || auBout){
            if(grammaire[curseurGrammaire].nom != symboleOrigine){
                remplirFollowsViaFollows(grammaire[curseurGrammaire].nom, symboleOrigine);
            }
        }
        if(!auBout){
            for(int j=0;j<follow.size();j++){
                if(follow[j]->symbole == symboleOrigine){
                    for(int k=0;k<first.size();k++){
                        if(first[k]->symbole == grammaire[curseurGrammaire].symboles[curseurSymboles]){
                            for(int l=0;l<first[k]->firsts.size();l++){
                                if(first[k]->firsts[l] != '.'){
                                    ajouterFollow(follow[j], first[k]->firsts[l]);
                                }
                                else {
                                    contientEpsilon = true;
                                }
                            }
                            if(contientEpsilon){
                                remplirFollows(curseurGrammaire,curseurSymboles+1,symboleOrigine);
                            }
                        }
                    }
                }
            }
        }
    }
    else if(estTerminal(grammaire[curseurGrammaire].symboles[curseurSymboles]) && !auBout){
        for(int j=0;j<follow.size();j++){
            if(follow[j]->symbole == symboleOrigine){
                ajouterFollow(follow[j], grammaire[curseurGrammaire].symboles[curseurSymboles]);
            }
        }
    }
}

void trouverFollows(){

    t_follow * ff;
    vector<t_follow*> followTemp;


    // on crée un t_follow par Non terminal à gauche
    bool existeDeja;
    for(int i=0;i<grammaire.size();i++){
        existeDeja = false;
        for(int j=0;j<follow.size();j++){
            if(grammaire[i].nom == follow[j]->symbole){
                existeDeja = true;
            }
        }

        if(!existeDeja){
            ff = new t_follow();
            ff->symbole = grammaire[i].nom;
            follow.push_back(ff);
            ff = new t_follow();
            ff->symbole = grammaire[i].nom;
            followTemp.push_back(ff);
        }
    }

    follow[0]->follows.push_back('$');

    bool fini = false;
    while(!fini) {
        for(int nonTerminalAGaucheEnCours = 0;nonTerminalAGaucheEnCours < grammaire.size(); nonTerminalAGaucheEnCours++) {
            for(int curseurGrammaire = 0; curseurGrammaire < grammaire.size();curseurGrammaire++){
                for(int curseurSymbole=0; curseurSymbole < grammaire[curseurGrammaire].symboles.size(); curseurSymbole++) {
                    if(grammaire[curseurGrammaire].symboles[curseurSymbole] == grammaire[nonTerminalAGaucheEnCours].nom){
                        if(curseurSymbole == grammaire[curseurGrammaire].symboles.size() -1){
                            remplirFollows(curseurGrammaire,curseurSymbole, grammaire[nonTerminalAGaucheEnCours].nom, true);
                        }
                        else {
                            remplirFollows(curseurGrammaire,curseurSymbole+1, grammaire[nonTerminalAGaucheEnCours].nom);
                        }
                    }
                }
            }
        }

        fini = true;
        for(int i=0;i<follow.size();i++){
            if(follow[i]->follows.size() != followTemp[i]->follows.size()){
                fini = false;
            }
        }

        if(!fini){
            for(int i=0;i<follow.size();i++){
                followTemp[i]->follows.clear();
                for(int j=0;j<follow[i]->follows.size();j++){
                    followTemp[i]->follows.push_back(follow[i]->follows[j]);
                }
            }
        }
    }

    while(followTemp.size()>0){
       delete(followTemp[followTemp.size()-1]);
       followTemp.pop_back();
    }
}

void ajouterFirst(t_first * ff, char symbole) {

    for(int i=0;i<ff->firsts.size();i++){
        if(ff->firsts[i] == symbole){
            return;
        }
    }

    ff->firsts.push_back(symbole);
    return;
}

void affichageFirsts(){
    cout << "Firsts:" << endl;
    for(int i=0;i<first.size();i++){
        cout << first[i]->symbole << ": ";
        for(int j=0;j<first[i]->firsts.size();j++){
            if(first[i]->firsts[j] == '.'){
                cout << "epsilon";
            }
            else {
                cout << first[i]->firsts[j];
            }
            cout <<" ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
}

void trouverFirsts(char regleChoisie) {

    for(int i=0;i<first.size();i++) {
        if(first[i]->symbole == regleChoisie){
            return;
        }
    }

    t_first * ff = new t_first();
    first.push_back(ff);

    ff->symbole = regleChoisie; // règle choisie


    int curseurSymbole = 0;
    int curseurRegle = 0;
    bool contientEpsilon;
    while(grammaire[curseurRegle].nom != regleChoisie && curseurRegle < grammaire.size()){
        curseurRegle++;
    }

    t_regle regleCourante = grammaire[curseurRegle];

    while(curseurRegle < grammaire.size()){
        regleCourante = grammaire[curseurRegle];

        if(curseurSymbole == 0 && estVide(&regleCourante)){ // quand on tombe sur un epsilon sous le curseur
            // on ajoute epsilon '.' à nos firsts
            ajouterFirst(ff,'.');
            while(grammaire[++curseurRegle].nom != regleChoisie && curseurRegle < grammaire.size()){ continue; }
            curseurSymbole=0;
        }
        else if(curseurSymbole >= regleCourante.symboles.size()){
            if(curseurRegle >= grammaire.size())
                break;
            while(grammaire[++curseurRegle].nom != regleChoisie && curseurRegle < grammaire.size()){ continue; }
            curseurSymbole=0;
        }
        else if(estTerminal(regleCourante.symboles[curseurSymbole])){ // quand on tombe sur un terminal sous le curseur
            // on ajoute notre terminal à nos firsts
            ajouterFirst(ff,regleCourante.symboles[curseurSymbole]);
            // on va à la prochaine règle de la grammaire correspondant à notre symbole
            while(grammaire[++curseurRegle].nom != regleChoisie && curseurRegle < grammaire.size()){ continue; }
            curseurSymbole=0;
        }
        else if(estNonTerminal(regleCourante.symboles[curseurSymbole])) { // quand on tombe sur un non terminal sous le curseur
            // on traite 2 cas: si le non terminal est celui qu'on traite déjà ou pas.
            if(regleChoisie == regleCourante.symboles[curseurSymbole]){
                // si on a le même symbole, on passe au suivant car on va de toute façon le traiter
                curseurSymbole++;
            }
            else {
                // si on a un non terminal sous le curseur, eh bien c'est la vie, donc on prend ses firsts comme firsts
                // on cherche les firsts du non terminal qu'on a trouvé
                trouverFirsts(regleCourante.symboles[curseurSymbole]);

                // on parcourt nos firsts pour trouver le nouveau non-terminal créé
                contientEpsilon = false;
                for(int i=0;i<first.size();i++) {

                    // quand on a trouvé, on rajoute tous ses firsts grâce à la fonction ajouterFirst
                    if(first[i]->symbole == regleCourante.symboles[curseurSymbole]){
                        for(int j=0;j<first[i]->firsts.size();j++){
                            if(first[i]->firsts[j] == '.'){
                                // si on a plus de caractère derrière notre caractère lu
                                if(regleCourante.symboles.size()-1 == curseurSymbole){
                                    ajouterFirst(ff,'.');
                                }
                                curseurSymbole++;
                                contientEpsilon = true;
                            }
                            else {
                                ajouterFirst(ff,first[i]->firsts[j]);
                            }
                        }
                    }
                }

                if(!contientEpsilon){
                    while(grammaire[++curseurRegle].nom != regleChoisie && curseurRegle < grammaire.size()){ continue; }
                    curseurSymbole=0;
                }

            }
        }
    }
}

void sleep(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void afficheItem(t_item * item){
    cout << "----" << endl;
    cout << "item " << item->numero << ":" << endl;
    cout << " - regles:" << endl;
    for(int i=0;i<item->regles.size();i++){
        cout << "\t" << i << ") " << item->regles[i].nom << " -> " << item->regles[i].symboles << endl;
        cout << "\t       ";
        for(int j=0;j<item->regles[i].curseur;j++) cout << " ";
        cout << "*" << endl;
    }
    cout << " - transitions:" << endl;
    for(int i=0;i<item->transitions.size();i++){
        cout << "\t" << i << ") lettre : '" << item->transitions[i].symbole << "' => " << item->transitions[i].itemCible->numero << endl;
    }
    cout << "----" << endl << endl;
}

void lireFichier(ifstream &fichier){
    string ligne;
    char next;
    bool dosMode = false;
    int curs_symbole = 0, curs_regle = 0;

    t_regle regle;
    regle.curseur = 0;

    while(fichier.get(next)){
        if(next == '\r' || (next == '\n' && !dosMode)){
            if(next == '\r') dosMode = true;
            curs_symbole = 0;
            curs_regle++;
            grammaire.push_back(regle);
            regle.nom = NULL;
            regle.symboles.clear();
        }
        else {
            if(curs_symbole==0){
                regle.nom = next;
            }
            else if(next != ' ' && next != '\t'){
                regle.symboles.append(1,next);
            }
            if(next != ' ' && next != '\t' && next != '\n' && next != '\r'){
                curs_symbole++;
            }
        }
    }

    for(int i=0;i<grammaire.size();i++){
        //cout << grammaire[i].nom << " -> " << grammaire[i].symboles << endl;
    }
}

bool estNonTerminal (const char S){
    return isupper(S) && S != '.';
}

bool estTerminal (const char S){
    return !estNonTerminal(S) && S != '.';
}

bool estVide(const t_regle * regle){
    return regle->symboles.size()==0;
}

bool comparerRegles (const t_regle &regle1, const t_regle &regle2){
    if(regle1.curseur == regle2.curseur && regle1.nom == regle2.nom && regle1.symboles == regle2.symboles){
        return true;
    }
    return false;
}

bool comparerItems (const t_item * item1, const t_item * item2){
    if(item1->regles.size() != item2->regles.size()){
        return false;
    }

    int reglesEgales = 0;
    for(int i=0;i<item1->regles.size();i++){
        for(int j=0;j<item2->regles.size();j++){
            if(comparerRegles(item1->regles[i],item2->regles[j])){
                reglesEgales++;
            }
        }
    }
    if(reglesEgales != item1->regles.size()){
        return false;
    }
    return true;
}

void ajoutReglesEnFonctionDuSymbole (const char symbole, vector<t_regle> &listeRegles){
    bool estIdentique = false;
    for(int i=0;i<grammaire.size();i++){
        if(symbole == grammaire[i].nom){
            //vérifier que la règle que l'on ajoute n'existe pas déjà dans l'item
            estIdentique = false;
            for(int j=0;j<listeRegles.size() && !estIdentique;j++){
                if(comparerRegles(grammaire[i],listeRegles[j])){
                    estIdentique = true;
                }
            }
            if(!estIdentique && (grammaire[i].curseur < grammaire[i].symboles.size() || grammaire[i].symboles.size() == 0 )){

                listeRegles.push_back(grammaire[i]);
            }
        }
    }
}

void creationTransitions(t_item * itemCourant, vector<t_item*> &listeItems){
    // on crée les transitions entre items
    int curseur;
    bool transitionExisteDeja;
    for(int i=0;i<itemCourant->regles.size();i++){

        curseur = itemCourant->regles[i].curseur;
        if(curseur >= itemCourant->regles[i].symboles.size()) continue;

        transitionExisteDeja = false;
        // on parcourt les transitions déjà créees pour l'item
        for(int j=0; j < itemCourant->transitions.size() && !transitionExisteDeja;j++){
            // si une transition a déjà été créee pour le symbole courant, on ne la traite pas et on passe au suivant
            if(itemCourant->regles[i].symboles[curseur] == itemCourant->transitions[j].symbole){
                transitionExisteDeja = true;
            }
        }

        // on a trouvé un symbole pas traité donc on le traite
        if(!transitionExisteDeja){
            t_transition trans;
            trans.symbole = itemCourant->regles[i].symboles[curseur];
            // on crée le nouvel item
            trans.itemCible = creationItem(itemCourant, trans.symbole, listeItems);
            itemCourant->transitions.push_back(trans);
        }
    }
}

t_item * creationItem(const t_item * itemPrec, const char symbole, vector<t_item*> &listeItems){
    static int cptItems=1;

    t_item * itemCourant = new t_item();
    t_regle nouvRegle;
    int posNouvRegle, nouvCurseur;
    //on parcourt l'item précédent
    int curseur;

    for(int i=0;i<itemPrec->regles.size();i++){
        //on prend le curseur de la règle en cours
        curseur = itemPrec->regles[i].curseur;
        //quand on trouve un . précédant le symbole on copie la règle dans le nouvel item
        if(curseur < itemPrec->regles[i].symboles.size() && itemPrec->regles[i].symboles[curseur]==symbole){
            t_regle regleTemp;
            //on décale le . dans cette nouvelle règle
            regleTemp.curseur = curseur+1;
            regleTemp.nom = itemPrec->regles[i].nom;
            regleTemp.symboles = itemPrec->regles[i].symboles;
            itemCourant->regles.push_back(regleTemp);
            if(regleTemp.curseur >= regleTemp.symboles.size()) continue;
            //si on a un non terminal après le . on recopie les règles découlant de ce non terminal à partir de la grammaire
            posNouvRegle = itemCourant->regles.size()-1;
            nouvRegle = itemCourant->regles[posNouvRegle];
            nouvCurseur = nouvRegle.curseur;
            if(estNonTerminal(nouvRegle.symboles[nouvCurseur])){
                ajoutReglesEnFonctionDuSymbole(itemCourant->regles[posNouvRegle].symboles[nouvCurseur], itemCourant->regles);
            }
        }
    }


    //on compare l'item créé aux autres items et on le rajoute à la liste d'item s'il est différent

    for(int i=0;i<listeItems.size();i++){
        if(comparerItems(itemCourant,listeItems[i])){
            delete(itemCourant);
            return listeItems[i];
        }
    }

    itemCourant->numero = cptItems;
    cptItems++;
    listeItems.push_back(itemCourant);


    creationTransitions(itemCourant, listeItems);

    afficheItem(itemCourant);
    return itemCourant;
}

// graphe
//       -> 1er item (I0)
//          -> liste de règles
//              -> nom [S] -> Sa
//              -> règle S -> [Sa]
//              -> curseur sur le symbole S -> .Sa
//          -> liste de transitions
//              -> symbole S -> [S]a
//              -> l'item vers lequel on pointe (I1)

// création du graphe SLR
void creerGraphe(vector<t_item*> &listeItems){

    // creer le 1er item
    graphe = new t_item();
    graphe->regles.resize(grammaire.size()+1);
    graphe->numero = 0;

    // créer une nouvelle regle A' -> A, ou A' est remplacé par sa lettre minuscule a;
    graphe->regles[0].nom = tolower(grammaire[0].nom);
    graphe->regles[0].symboles = grammaire[0].nom;

    // pour le 1er item, créer une règle par règle de la grammaire
    for(int i=0;i<grammaire.size();i++){
        graphe->regles[i+1].nom = grammaire[i].nom;
        graphe->regles[i+1].symboles = grammaire[i].symboles;
        graphe->regles[i+1].curseur = 0;
    }

    creationTransitions(graphe, listeItems);

    afficheItem(graphe);


}





int main()
{
    ifstream fichier("grammaire.txt");

    lireFichier(fichier);
    // on crée le vecteur liste d'items avant d'appeler la fonction
    vector<t_item*> listeItems;

    creerGraphe(listeItems);

    for(int i=0;i<grammaire.size();i++){
        trouverFirsts(grammaire[i].nom);
    }
    affichageFirsts();

    trouverFollows();
    affichageFollows();

    creationTableAnalyse();
    affichageTableAnalyse();

    string entree;
    while(1){
        cout << endl << endl << "entrez un mot:";
        cin >> entree;
        entree.append("$");
        if(execution(entree)){
            cout << endl << "Fait partie du langage." << endl;
        }
        else {
            cout << endl << "Ne fait pas partie du langage." << endl;
        }
    }
    return 0;
}



