#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// CLASSES & FONCTIONS

  // Structures simples

struct rules{ // Structure associant une regle a son numero
    int num;
    string r;
};

struct execution{ // Stucture reprensetan un element de la pile d'execution lors de la lecture d'un mot
    int etat;
    char trans;
};

  // Classe variable

class variable{
private :
    char name;
    vector<string> regles;
public :
    variable(char a){
        name = a;
    }
    bool operator==(char s){
        return (name==s);
    }
    bool operator==(variable s){
        return (name==s.name);
    }
    string operator[](int &a){
        return regles[a];
    }
    void push_back(string s){
        regles.push_back(s);
    }
    char get_name(){
        return name;
    }
    int get_nb_rules(){
        return regles.size();
    }
    bool contient_e() // Verification de la presence de epsilon dans les regl de cette classe
    {
        bool ok = 0;
        for(int i=0;i<regles.size();i++){
            if(regles[i].size()==0){
                ok = 1;
            }
        }
        return ok;
    }
    bool contient(char a){
        bool verif = 0;
        for(int i=0;i<regles.size();i++){
            for(int j=0;j<regles[i].size();j++){
                if(regles[i].at(j)==a){
                    verif = 1;
                }
            }
        }
        return verif;
    }
    vector<char> suivants(vector<variable> var, char a); // Methodes utilisant une fonction  decrite plus tard, le code de ces methodes est donc encore apres
    vector<char> premier(vector<char> visites, vector<variable> var);
    void dernier(vector<char> visites,vector<vector<char> > &prems, vector<variable> var);
    bool lit_mot_vide(vector<char> visites, vector<variable> b);
    void affiche(){
        cout << name;
        if(regles.size()!=0)
        {
            cout << "->" << regles[0];
            for(int i = 1;i<regles.size();i++){
                cout << "|" << regles[i];
            }
        }
    }
};

  // Classe de modelisation de l'automate

    // Classe representant une ligne d'un etat de l'automate
class line_etat{
private :
    string rule;
    int point;
    int regle;
public :
    line_etat(char s){
        regle = 0;
        point = 3;
        rule = "S->";
        rule = rule + s;
    }
    line_etat(string s, vector<variable> a, int p = 0){
        regle = 0;
        rule = s;
        int cpt = 0;
        string ss;
        point = 0;
        if(p == 0){
            point = 3;
            if(point == s.size()){ // Verification de la position du point
                for(int i=0;i<a.size();i++){
                    for(int j = 0;j<a[i].get_nb_rules();j++){
                        cpt ++;
                        ss = a[i].get_name();
                        ss = ss + "->";
                        ss = ss + a[i][j];
                        if(s == ss){
                            regle = cpt; // S'il est completement a droite completion avec nom de la regle
                        }
                    }
                }
            }
        }
        else{ // Cas particulir de epsilon
            point = p;
            if((p == s.size())&&(rule.at(0)=='S')){
                regle = -1;
            }
            else if(p == s.size()){
                for(int i=0;i<a.size();i++){
                    for(int j = 0;j<a[i].get_nb_rules();j++){
                        cpt ++;
                        ss = a[i].get_name();
                        ss = ss + "->";
                        ss = ss + a[i][j];
                        if(s == ss){
                            regle = cpt;
                        }
                    }
                }
            }
        }
    }
    line_etat(line_etat &b, vector<variable> a){ // Meme methode de construction mais avance d'un point
        regle = 0;
        int cpt = 0;
        string s;
        rule = b.rule;
        point = b.point + 1;
        if((point == rule.size())&&(rule.at(0)=='S')){
            regle = -1;
        }
        else if(point == rule.size()){
            for(int i=0;i<a.size();i++){
                for(int j = 0;j<a[i].get_nb_rules();j++){
                    cpt ++;
                    s = a[i].get_name();
                    s = s + "->";
                    s = s + a[i][j];
                    if(rule == s){
                        regle = cpt;
                    }
                }
            }
        }
    }
    char access(){
        return rule.at(0);
    }
    int position(){
        return rule.size()-point;
    }
    bool operator==(line_etat a){
        return((rule==a.rule)&&(regle==a.regle)&&(point==a.point));
    }
    char return_trans(){
        if(this->position() != 0){
            return rule.at(point);
        }
        else{
            return '$';
        }
    }
    rules return_rule(){
        rules r;
        r.num = regle;
        r.r = rule;
        return r;
    }
    void affiche(){
        int i;
        for(i=0;i<point;i++){
            cout << rule.at(i);
        }
        cout << ".";
        for(i=point;i<rule.size();i++){
            cout << rule.at(i);
        }
        if(regle > 0){
            cout << "  R" << regle;
        }
        else if(regle == -1){
            cout << "  axiome";
        }
        cout << endl;
    }
};
     // Classe representant les transitions entre les etats
class trans{
private :
    char A;
    int etat;
public :
    trans(char a, int b){
        A = a;
        etat = b;
    }
    char get_char(){
        return A;
    }
    int get_int(){
        return etat;
    }
    bool operator==(char a){
        return A==a;
    }
    void equilibre_transition(int a, int b){
        if(a==etat){
            etat = b;
        }
        else if(etat>a){
            etat--;
        }
    }
    void affiche(){
        cout << "---" << A << "--->I" << etat << endl;
    }
};
    //Classe representant les etats
class etat{
private :
    vector<line_etat> rule;
    vector<trans> transitions;
public :
    etat(){}
    etat(vector<variable> a, int &cpt){ // Constructeur specifique a I0
        rule.push_back(a[0].get_name()); // Constructeur de l'axiome
        int i,j;
        string s;
        for(i=0;i<a.size();i++){
            for(j = 0;j<a[i].get_nb_rules();j++){
                s = (a[i].get_name());
                s = s+ "->" ;
                s = s + a[i][j];
                rule.push_back(line_etat(s,a));
            }
        }
        bool verif;
        for(i=0;i<rule.size();i++){
              verif = 1;
              for(j = 0;j<transitions.size();j++){ // Verification que la transition n'existe pas deja
                    if(transitions[j]==rule[i].return_trans()){
                        verif = 0;
                    }
              }
              if((verif)&&(rule[i].return_trans()!='$')){
                    cpt++;
                    transitions.push_back(trans(rule[i].return_trans(),cpt)); // Creation d'une nouvelle transition
              }
        }
    }
    etat(etat e, trans b, vector<variable> a,int &cpt){ // Constructeur a partir de l'etat precedent et de sa transition vers ce nouvel etat
        int i, j ,k;
        string s;
        for(i=0;i<e.rule.size();i++){ // Creation des regles avancees de la tansition
            if(b==e.rule[i].return_trans()){
                rule.push_back(line_etat(e.rule[i],a));
            }
        }
        vector<int> controle;///// MODIFICATION : ajout d'un controle pour empecher les boucles infinies
        bool verif;
        for(i=0;i<rule.size();i++){ // Creation de regles engendrees par celles ci
                verif = 1;
                for(j=0;j<a.size();j++){ ///// MODIFICATION
                    for(k=0;k<controle.size();k++){ ///// MODIFICATION
                        if(controle[k]==j){ ///// MODIFICATION
                            verif = 0; ///// MODIFICATION
                        }
                    }
                    if((a[j]==rule[i].return_trans())&&(rule[i].position()!=0)&&(verif)){///// MODIFICATION : changement de &&(rule[i].position()==1) en &&(rule[i].position()!=0)&&(verif)
                        for(k=0;k<a[j].get_nb_rules();k++){
                            s = (a[j].get_name());
                            s = s+ "->" ;
                            s = s + a[j][k];
                            rule.push_back(line_etat(s,a));
                            controle.push_back(j);/////
                        }
                    }
                }
        }
        verif = 1; // Ajout des transitions
        for(i=0;i<rule.size();i++){
              for(j = 0;j<transitions.size();j++){
                    if(transitions[j]==rule[i].return_trans()){
                        verif = 0;
                    }
              }
              if((verif)&&(rule[i].return_trans()!='$')){
                    cpt++;
                    transitions.push_back(trans(rule[i].return_trans(),cpt));
              }
        }
    }
    trans operator[](int i){
        return transitions[i];
    }
    bool contient(line_etat a){
        bool ok = 0;
        for(int i=0;i<rule.size();i++){
            if(a == rule[i]){
                ok = 1;
            }
        }
        return ok;
    }
    bool operator==(etat a){
        bool ok = 1;
        for(int i=0;i<rule.size();i++){
            if(a.contient(rule[i])==0){
                ok = 0;
            }
        }
        if(rule.size()!=a.rule.size()){
            ok = 0;
        }
        return ok;
    }
    int nb_trans(){
        return transitions.size();
    }
    void set_transition(char a, int b){
        transitions.push_back(trans(a,b));
    }
    void equilibre_transition(int a, int b){
        for(int i=0;i<transitions.size();i++){
            transitions[i].equilibre_transition(a,b);
        }
    }
    vector<rules> return_rules(){
       vector<rules> v;
       rules r;
        for(int i=0;i<rule.size();i++){
            r = rule[i].return_rule();
            if(r.num>0){
                v.push_back(r);
            }
        }
        return v;
    }
    void affiche(){
        int i;
        for(i=0;i<rule.size();i++){
            rule[i].affiche();
        }
        cout << endl;
        for(i=0;i<transitions.size();i++){
            transitions[i].affiche();
        }
        cout << endl << endl << endl;;
    }
};
     // Classe modelisant l'automate en entier
class automate{
private :
    vector<etat> etats;
public :
    automate (vector<variable> a){
        int cpt_4 = 0, k;
        etats.push_back(etat(a,cpt_4)); // Creation du premier etat I0
        etat e;
        int verif;
        int cpt = 0, cpt_2 = 1, cpt_3 = 1;
        while(cpt != cpt_2){ // A chaque nouvel etat des transition vont apparaitre on les traite comme si elle menaient a un nouvel etat qu'on cree on verifie ensuite s'il il s'agit d'un doublon qu'on supprime auquel cas
            for(int i=cpt;i<cpt_2;i++){
                for(int j=0;j<etats[i].nb_trans();j++){
                    e = etat(etats[i],etats[i][j],a,cpt_4); // Creation d'un nouvel etat
                    verif = -1;
                    for(k=0;k<etats.size();k++){ // Comparer pour verifier que l'etat n'existe pas deja
                        if(e == etats[k]){
                            verif = k;
                        }
                    }
                    if(verif==-1){
                        etats.push_back(e); // Etat unique est ajoute a l'automate
                        cpt_3++;
                    }
                    else{
                        for(k=0;k<etats.size();k++){
                            etats[k].equilibre_transition(etats.size(),verif); // Les transitions sont adaptes a l'eventuelle suppression d'un etat
                        }
                        cpt_4--;
                    }
                }
            }
            cpt = cpt_2;
            cpt_2 = cpt_3;
        }
    }
    int get_nb_etats(){
        return etats.size();
    }
    etat operator[](int i){
        return etats[i];
    }
    void affiche(){
        for(int i=0;i<etats.size();i++){
            cout << "I" << i << " :" << endl << endl;
            etats[i].affiche();
        }
    }
};


  // Classe de modelisation de la table (ici est une case)

class couple_entree_rules{
private :
    char entree;
    vector<rules> rule;
    int s;
public :
    couple_entree_rules(trans a){
        entree = a.get_char();
        s = a.get_int();
    }
    couple_entree_rules(rules r,char a){
        entree = a;
        rule.push_back(r);
        s = -1;
    }
    string operator[](int i){
        return rule[i].r;
    }
    void affiche(){
        int cpt = 0;
        cout << "Entree : " << entree << ", Sortie(s) : ";
        if(s!=-1){
            cout << "S" << s;
            cpt++;
        }
        for(int i=0;i<rule.size();i++)
        {
            if(cpt==0){
                if(rule[i].num==-1)
                {
                    cout << "ACC";
                }
                else{
                    cout << "R" << rule[i].num;
                }
                cpt++;
            }
            else{
                if(rule[i].num==-1)
                {
                    cout << "/ACC";
                }
                else{
                    cout << "/R" << rule[i].num;
                }
            }
        }
        cout << endl;
    }
    void aj_rule(rules ru){
        rule.push_back(ru);
    }
    bool operator==(char s){
        return entree==s;
    }
    int get_nb_rule(){
        return rule.size();
    }
    int get_switch(){
        return s;
    }
    int get_value_rule(int i){
        return rule[i].num;
    }
};



   // Fonctions et corps de methodes

    // Fonctions

bool est_terminal(char a, vector<variable> b){
    bool ok = 1;
    for(int i=0;i<b.size();i++){
        if(b[i]==a){
            ok = 0;
        }
    }
    return ok;
}

bool est_possible(char a, vector<variable> b){ // Verifie si le caracter appartient a l'alphabet
    bool verif = 0;
    for(int i=0;i<b.size();i++){
        if(b[i].contient(a)){
            verif = 1;
        }
    }
    if(verif == 1){
        if(est_terminal(a,b)==0){
            verif = 0;
        }
    }
    return verif;
}

vector<char> suppr_doublons(vector<char> a){
 vector<char> b;
 bool verif;
    for(int i=0;i<a.size();i++){
        verif = 1;
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                verif = 0;
            }
        }
        if(verif){
            b.push_back(a[i]);
        }
    }
    return b;
}

bool exe(vector<execution> pile, string mot, vector<vector<couple_entree_rules> > table, int cpt){
    int i, j, k;
    bool ok = 1, ok_2 = 0, verif, impasse;
    execution e;
    vector<execution> pile_trans;
    string transcript;
    while(((mot!="$")||(pile.size()!=1)||(pile[0].etat!=1))&&(ok)&&(ok_2==0)){
        ok = 0;
        impasse = 1;
        if(pile.size()==0){ // Si la pile est vide (meme si on part de 0 on la considere vide au debut)
            for(i=0;i<table[0].size();i++){
                if(table[0][i]==mot.at(0)){
                    if((table[0][i].get_nb_rule()>0)||(table[0][i].get_switch()!=-1)){
                        impasse = 0;
                    }
                    for(j=0;j<table[0][i].get_nb_rule();j++){ // Recherche d'une regle sur cette trasition
                        if(table[0][i].get_value_rule(j)!=-1){
                            cout << endl;
                            if((table[0][i].get_nb_rule()!=1)||(table[0][i].get_switch()!=-1)){ // Signalisation d'un conflit
                                cout << "*";
                            }
                            transcript = table[0][i][j]; // De 0 a 2 ne pas prendre en compte (A-> ne dois pas faire interferer le processus)
                            verif = 1;
                            if((transcript.size()-3)<=pile.size()){ // Verification du fait que la regle soit applicable
                                for(k=transcript.size()-1;k>2;k--){
                                    if(transcript.at(k)!=pile[pile.size()-transcript.size()+k].trans){
                                        verif = 0;
                                    }
                                }
                            }
                            else{
                                verif = 0;
                            }
                            if(verif){
                                pile_trans.clear(); // Creation d'un nouvelle pile avec les modifications appliques par la regle
                                for(k=0;k<pile.size()-(transcript.size()-3);k++){
                                    e.etat = pile[k].etat;
                                    e.trans = pile[k].trans;
                                    pile_trans.push_back(e);
                                }
                                e.trans = transcript.at(0); // instanciation de la nouvelle tete de pile
                                if(pile_trans.size()!=0){
                                    for(k=0;k<table[pile_trans[pile_trans.size()-1].etat].size();k++){
                                        if(table[pile_trans[pile_trans.size()-1].etat][k]==e.trans){
                                            e.etat = table[pile_trans[pile_trans.size()-1].etat][k].get_switch();
                                        }
                                    }
                                }
                                else{
                                    for(k=0;k<table[0].size();k++){ // Les regls peuvent etre nombreuses contrairement aux transitios, elle sont donc traites en recursif
                                        if(table[0][k]==e.trans){
                                            e.etat = table[0][k].get_switch();
                                        }
                                    }
                                }
                                pile_trans.push_back(e);
                                cout << "(" << cpt << ")   0";
                                for(k=0;k<pile_trans.size();k++){
                                    cout << pile_trans[k].trans << pile_trans[k].etat;
                                }
                                cout << "   " << mot << "   " << transcript;
                                if(exe(pile_trans, mot, table, cpt+1)){
                                    ok_2 = 1;
                                }
                            }
                            else{
                                cout << "La regle " << transcript << " n'aboutit pas";
                            }
                        }
                    }
                    if((table[0][i].get_switch()!=-1)&&(ok==0)){ // Empile
                        cout << endl;
                        if((table[0][i].get_nb_rule()!=0)){
                            cout << "*";
                        }
                        ok = 1;
                        transcript = mot;
                        mot = "";
                        for(j=1;j<transcript.size();j++){
                            mot = mot + transcript.at(j);
                        }
                        if(mot==""){
                            mot = "$";
                        }
                        e.trans = transcript.at(transcript.size()-1);
                        e.etat = table[0][i].get_switch();
                        pile.push_back(e);
                        cout << "(" << cpt << ")   0";
                        for(j=0;j<pile.size();j++){
                            cout << pile[j].trans << pile[j].etat;
                        }
                        cout << "   " << mot << "   S" <<  pile[pile.size()-1].etat;
                    }
                }
            }
        }
        else{ // Meme procede mais la reference n'est plus l'etat 0 mais la tete de pile puisque celle ci n'est plus vide
            for(i=0;i<table[pile[pile.size()-1].etat].size();i++){
                if(table[pile[pile.size()-1].etat][i]==mot.at(0)){
                    if((table[pile[pile.size()-1].etat][i].get_nb_rule()>0)||(table[pile[pile.size()-1].etat][i].get_switch()!=-1)){
                        impasse = 0;
                    }
                    for(j=0;j<table[pile[pile.size()-1].etat][i].get_nb_rule();j++){ // Regles en recursif
                        if(table[pile[pile.size()-1].etat][i].get_value_rule(j)!=-1){
                            cout << endl;
                            if((table[pile[pile.size()-1].etat][i].get_nb_rule()!=1)||(table[pile[pile.size()-1].etat][i].get_switch()!=-1)){
                                cout << "*";
                            }
                            transcript = table[pile[pile.size()-1].etat][i][j]; // De 0 a 2 ne pas prendre en compte
                            verif = 1;
                            if((transcript.size()-3)<=pile.size()){
                                for(k=transcript.size()-1;k>2;k--){
                                    if(transcript.at(k)!=pile[pile.size()-transcript.size()+k].trans){
                                        verif = 0;
                                    }
                                }
                            }
                            else{
                                verif = 0;
                            }
                            if(verif){
                                pile_trans.clear();
                                for(k=0;k<pile.size()-(transcript.size()-3);k++){
                                    e.etat = pile[k].etat;
                                    e.trans = pile[k].trans;
                                    pile_trans.push_back(e);
                                }
                                e.trans = transcript.at(0);
                                if(pile_trans.size()!=0){
                                    for(k=0;k<table[pile_trans[pile_trans.size()-1].etat].size();k++){
                                        if(table[pile_trans[pile_trans.size()-1].etat][k]==e.trans){
                                            e.etat = table[pile_trans[pile_trans.size()-1].etat][k].get_switch();
                                        }
                                    }
                                }
                                else{
                                    for(k=0;k<table[0].size();k++){
                                        if(table[0][k]==e.trans){
                                            e.etat = table[0][k].get_switch();
                                        }
                                    }
                                }
                                pile_trans.push_back(e);
                                cout << "(" << cpt << ")   0";
                                for(k=0;k<pile_trans.size();k++){
                                    cout << pile_trans[k].trans << pile_trans[k].etat;
                                }
                                cout << "   " << mot << "   " << transcript;
                                if(exe(pile_trans, mot, table, cpt+1)){
                                    ok_2 = 1;
                                }
                            }
                            else{
                                cout << "La regle " << transcript << " n'aboutit pas";
                            }
                        }
                    }
                    if((table[pile[pile.size()-1].etat][i].get_switch()!=-1)&&(ok==0)){ // Empile
                        cout << endl;
                        if(table[pile[pile.size()-1].etat][i].get_nb_rule()!=0){
                            cout << "*";
                        }
                        ok = 1;
                        transcript = mot;
                        mot = "";
                        for(j=1;j<transcript.size();j++){
                            mot = mot + transcript.at(j);
                        }
                        if(mot==""){
                            mot = "$";
                        }
                        e.trans = transcript.at(0);
                        e.etat = table[pile[pile.size()-1].etat][i].get_switch();
                        pile.push_back(e);
                        cout << "(" << cpt << ")   0";
                        for(j=0;j<pile.size();j++){
                            cout << pile[j].trans << pile[j].etat;
                        }
                        cout << "   " << mot << "   S" <<  pile[pile.size()-1].etat;
                    }
                }
            }
        }
        cpt++;
        if((impasse)&&((mot!="$")||(pile.size()!=1)||(pile[0].etat!=1))&&(ok_2!=1))
        {
            cout << endl << "Impasse";
        }
    } // Verification des coditions de sortie
    if(ok_2==1){ // La resolution s'est produite en recursif
        return 1;
    }
    else{
        if((mot=="$")&&(pile.size()==1)&&(pile[0].etat==1)){ // Resolution
            cout << endl << "Axiome";
            return 1;
        }
        else{ // Echec
            return 0;
        }
    }
}


    // Methodes de la classe variable

vector<char> variable::suivants(vector<variable> var, char a){
    vector<char> suivant, premier;
    vector<char> visites;
    bool ok;
    int l;
    for(int i=0;i<regles.size();i++){
        for(int j=0;j<regles[i].size();j++){
            l = j+1;
            ok = 1;
            while((regles[i].at(j)==a)&&(l<regles[i].size())&&(ok)){ // Enregistre ce qui suit la variable et qui est final
                if(est_terminal(regles[i].at(l),var)){
                        suivant.push_back(regles[i].at(l));
                        ok = 0;
                }
                else{
                    for(int k=0;k<var.size();k++){ // Si suivit par des variable recherche de leur premiers en recursif
                        if(var[k]==regles[i].at(l)){
                            premier =  var[k].premier(visites,var);
                            suivant.insert(suivant.end(),premier.begin(),premier.end());
                            if(var[k].contient_e()==0){
                                ok = 0;
                            }
                        }
                    }
                }
            l++;
            }
        }
    }
    return suivant;
}

vector<char> variable::premier(vector<char> visites, vector<variable> var){
    vector<char> premier, p;
    int j;
    bool ok = 1;
    for(j=0;j<visites.size();j++){ // Test de visite
        if(name==visites[j]){
            ok = 0;
        }
    }
    if(ok){
        visites.push_back(name);
        for(j=0;j<regles.size();j++){
            if(regles[j].size()!=0){
                ok = 1;
                int l = 0;
                while((l<regles[j].size())&&(ok)){
                    if(est_terminal(regles[j].at(l),var)){ // Ajoute les etats termiaux premier dans les regles
                        premier.push_back(regles[j].at(l));
                        ok = 0;
                    }
                    else{
                        for(int i=0;i<var.size();i++){ // Si certaines commencent par une variable, application en recursif
                            if(var[i]==regles[j].at(l)){
                                p = var[i].premier(visites,var);
                                premier.insert(premier.end(),p.begin(),p.end());
                                if(var[i].contient_e()==0){
                                    ok = 0;
                                }
                            }
                        }
                    }
                    l++;
                }
            }
        }
    }
    return premier;
}

void variable::dernier(vector<char> visites,vector<vector<char> > &prems, vector<variable> var){
    bool ok = 1,verif = 1;
    int i, j, cpt;
    for(j=0;j<visites.size();j++){ // Verifiction de visite
        if(name==visites[j]){
            ok = 0;
        }
    }
    if(ok){
        for(j=0;j<var.size();j++){ // S'il n'a pas deja ete visite
            if(var[j]==name){
                prems[j].push_back('$'); // Il a lui aussi $ dans ses successeurs
            }
        }
        visites.push_back(name);
        for(i=0;i<regles.size();i++){
            if(regles[i].size()!=0){
                cpt = 0;
                do{ // Si dans ses regles, certaines finissent par d'autres variables elle ont elle aussi $ pour successeur(recurssif) et si ces memes variables contiennent epsilon et sont precedes par d'autrs variables celles ci egalement possedent $ (boucle do)
                    verif = 0;
                    if(est_terminal(regles[i].at(regles[i].size()-1-cpt),var)==0){
                        for(j=0;j<var.size();j++){
                            if(var[j]==regles[i].at(regles[i].size()-1-cpt)){
                                var[j].dernier(visites,prems,var);
                                if(var[j].contient_e()){
                                    verif = 1;
                                }
                            }
                        }
                    }
                    cpt++;
                }while((verif)&&(cpt<regles[i].size()));
            }
        }
    }
}

bool variable::lit_mot_vide(vector<char> visites, vector<variable> b){ // Mot vide traite a part du fait de la modelisation (fonction recursive)
    bool ok = 1, verif;
    int i, j;
    for(j=0;j<visites.size();j++){ // Test de visite
        if(name==visites[j]){
            ok = 0;
        }
    }
    if(ok){
        ok = 0; // Verification que cet variable possede psilon dans ses regles
        visites.push_back(name);
        for(j=0;j<regles.size();j++){
            if(regles[j].size()==0){
                ok = 1;
            }
        }
        if(ok==0){
            for(j=0;j<regles.size();j++){ // Si elle ne le possede pas on verifie si ell possede une regle ne contenant que des variables qui ont epsilon et ainsi de suite (recursivite)
                verif = 1;
                for(i=0;i<regles[j].size();i++){
                    if((est_terminal(regles[j].at(i),b))==0){
                        for(int k=0;k<b.size();k++){
                            if((b[k]==regles[j].at(i))&&(b[k].lit_mot_vide(visites,b)==0)){
                                verif = 0;
                            }
                        }
                    }
                    else{
                        verif = 0;
                    }
                }
                if(verif==1){
                    ok = 1;
                }
            }
        }
    }
    return ok;
}




// MAIN PROGRAMME

int main()
{
    cout << "                           TP NOTE - LANGAGE & COMPILATION" << endl << endl << endl << endl << endl;
    vector<variable> gramm;
    ifstream file("TP_II1.txt");
    string line,r;
    bool verif,condition = 1;
    int i, j;
    if(file.is_open()){
        while(getline(file,line)) // Lecure du txt securisee
        {
            if((line.size()>2)&&(line.at(1)==' ')&&(line.at(1)!='S')){ // Reserve a l'axiome
                r = "";
                for(i=2;i<line.size();i++){ // Isolation de la regle
                    if((line.at(i)!='e')&&(line.at(i)!=' ')){
                        r = r + line.at(i);
                    }
                }
                verif = 0;
                for(i=0;i<gramm.size();i++){ // Verification que la variable n'existe pas deja
                    if(gramm[i]==line.at(0)){
                        verif = 1;
                        gramm[i].push_back(r); // Ajout de la regle dans la classe representant la variable
                    }
                }
                if((verif == 0)&&(line.at(0)!='e')){ // Creation d'une nouvelle variable
                    gramm.push_back(variable(line.at(0)));
                    gramm[gramm.size()-1].push_back(r);
                }
                else if(verif == 0){
                    condition = 0;
                }
            }
            else{
                condition = 0;
            }
        }
    }
    else{
        condition = 0;
    }
    if(condition){ // Test de la validite du txt
        cout << "# Automate :" << endl << endl << endl;
        automate a(gramm); // Envoie aux methodes pour creer l'automate
        a.affiche();
        vector<vector<char> > prems; // Creation d'un vecteur qui contiendra toutes les variables a travers un vecteur de caractere qui contient ses suivants les suivant
        prems.resize(gramm.size());
        vector<char> ve;
        for(i=0;i<gramm.size();i++){
           for(j=0;j<gramm.size();j++){
                ve = gramm[j].suivants(gramm,gramm[i].get_name()); // Utilisation de methode afin de recupere les premiers de chaque variable
                prems[i].insert(prems[i].end(),ve.begin(),ve.end());
           }
        }
        cout << "# Suivants :" << endl << endl << endl;
        vector<char> cha;
        gramm[0].dernier(cha,prems,gramm); // Recherche via mthode de la presence de $ chez les suivant de chaque variable
        for(i=0;i<gramm.size();i++){
            prems[i]=suppr_doublons(prems[i]); // Suppression des doublons
            cout << "S(" << gramm[i].get_name() << ") : {";
           for(j=0;j<prems[i].size();j++){
                if(j == 0){
                    cout << prems[i][0];
                }
                else{
                    cout << "," << prems[i][j];
                }
           }
           cout << "}" << endl;
        }
        cout << endl << endl << endl << endl;
        cout << "# Table d'analyse :" << endl << endl << endl;
        vector<vector<couple_entree_rules> > table(a.get_nb_etats()); // Creaton de la table
        vector<rules> v;
        for(i=0;i<a.get_nb_etats();i++){
            v = a[i].return_rules();
            for(j=0;j<a[i].nb_trans();j++){
                table[i].push_back(couple_entree_rules(a[i][j])); // Entree dans la table des transitions entre les etats
            }
            for(j=0;j<v.size();j++){ // Pour chaque regle
                for(int k=0;k<gramm.size();k++){ // On cherche sa place dans le vecteur des variables
                    if(gramm[k]==v[j].r.at(0)){
                        for(int l=0;l<prems[k].size();l++){ // Pour chaque suivant
                            verif = 1;
                            for(int m=0;m<table[i].size();m++){ // Parcours des couples deja instancies pour voir si la case existe deja
                                if(table[i][m]==prems[k][l]){
                                    verif = 0;
                                    table[i][m].aj_rule(v[j]); // Ajout des regles dans la bonne case
                                }
                            }
                            if(verif){
                                table[i].push_back(couple_entree_rules(v[j],prems[k][l])); // Constructeur depuis une regle puisque la case n'existait pas deja
                            }
                        }
                    }
                }
            }
        }
        rules rul; // Ajout de l'axiome
        rul.num = -1;
        table[1].push_back(couple_entree_rules(rul,'$'));
        for(i=0;i<table.size();i++){
            cout << i << " :" << endl << endl;
            for(j=0;j<table[i].size();j++){
                table[i][j].affiche();
            }
            cout << endl << endl;
        }
        string strans, mot = "";
        cout << endl << endl << "# Execution :";
        bool reponse;
        do{ // Boucle de test
            cout << endl << endl << "Saisir le mot a tester" << endl;
            cin >> strans;
            verif = 1;
            mot = "";
            for(i=strans.size()-1;i>=0;i--){ // Inversion du mot saisi
                mot = mot + strans.at(i);
                if(est_possible(strans.at(i),gramm)==0){
                    verif = 0;
                }
            }
            if(verif){
                vector<execution> pile;
                if(exe(pile,mot,table,0)){
                    cout << endl << endl << endl << "Le mot est reconnu par le langage";
                }
                else{
                    cout << endl << endl << endl << "Le mot n'est pas reconnu par le langage";
                }
            }
            else if (mot=="$"){ // Test de reconnaissance du mot vide
                cha.clear();
                if(gramm[0].lit_mot_vide(cha,gramm))
                {
                    cout << endl << endl << endl << "Le mot est reconnu par le langage";
                }
                else{
                    cout << endl << endl << endl << "Le mot n'est pas reconnu par le langage";
                }
            }
            else{
               cout << endl << endl << endl << "Le mot n'est pas reconnu par le langage";
            }
            cout << endl << endl << endl << "Tester un autre mot pour ce langage ? (0/1)" << endl;
            cin >> reponse;
        }while(reponse);
    }
    else{
        cout << "FICHIER TEXTE CORROMPU!";
    }
}
