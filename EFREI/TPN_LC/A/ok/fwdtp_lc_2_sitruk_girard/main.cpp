#include <iostream>
#include <fstream>
#include <vector>



using namespace std;
struct rules //Structure associant une règle à son numéro
{
    int num;
    string r;
};
struct execution  // Stucture reprensetant un element de la pile d'execution lors de la lecture d'un mot
{
    int etat;
    char trans;
};
struct variable //Structure associant une variable à toutes ses règles ex : name = A regle : A->AB
{
    char name;
    vector <string> regles;
};
struct line_etat // structure repésentant une ligne de regles dans un Item avec le numero de la regle si cest un etat terminal et un entier point pour savoir ou se positionne le point
{
    string rule;
    int point;
    int regle;
};
struct trans // regles representant un transition sur une variable vers un état
{
    char A;
    int etat;
};
struct etat // structure representant un etat avec un vector de regles et un vector de transition (en sortie de l'item)
{
    vector<line_etat> rule;
    vector<trans> transitions;
};

struct automate
{
    vector<etat> etats;
};

bool contient_e(variable AUTOMATE) // Verification de la presence de epsilon dans les regles de cette classe // type varaiable a passer en parametre
{
    bool ok = 0;
    for(int i=0; i<AUTOMATE.regles.size(); i++)
    {
        if(AUTOMATE.regles[i].size()==0)
        {
            ok = 1;
        }
    }
    return ok;
}

bool contient(char a, variable A)  //Verification de la presence d'un caractere
{
    bool verif = 0;
    for(int i=0; i<A.regles.size(); i++)
    {
        for(int j=0; j<A.regles[i].size(); j++)
        {
            if(A.regles[i].at(j)==a)
            {
                verif = 1;
            }
        }
    }
    return verif;
}

bool compare (line_etat a, line_etat b) //fonction comparant de ligne d'un etat
{
    bool ok = 1;
    if(a.rule != b.rule)
    {
        ok =0;
    }
    if (a.point != b.point)
    {
        ok = 0;
    }
    if (a.regle!= b.regle)
    {
        ok =0;
    }

    return ok;
}

bool contient(etat a, line_etat b) //fonction pour savoir si un etat contient une ligne
{
    bool ok = 0;
    for(int i=0; i<a.rule.size(); i++)
    {
        if(compare (b, a.rule[i]))
        {
            ok = 1;
        }
    }
    return ok;
}

bool compare (etat a, etat b)//fonction comparant deux etats
{
    bool ok = 1;
    for(int i=0; i<b.rule.size(); i++)
    {
        if(contient(a, b.rule[i])==0)
        {
            ok = 0;
        }
    }
    if(b.rule.size()!=a.rule.size())
    {
        ok = 0;
    }
    return ok;
}

void affiche(variable a)  //Affichage d'une variable
{
    cout << a.name;
    if(a.regles.size()!=0)
    {
        cout << "->" << a.regles[0];
        for(int i = 1; i<a.regles.size(); i++)
        {
            cout << "|" << a.regles[i];
        }
    }
}

line_etat ligne_etat(char s)  // fonction qui initialise l'axiome
{
    line_etat state_line;
    state_line.regle = 0;
    state_line.point = 3;
    state_line.rule = "S->";
    state_line.rule = state_line.rule + s;
    return state_line;
}

line_etat ligne_etat(string s, vector<variable> a, int p = 0)  // ajouter une variable line_etat
{
    line_etat state_line;
    state_line.regle = 0; //Renvoyer un ligne etat cr&er au prealable au debut de la fonction
    state_line.rule = s;
    int cpt = 0;
    string ss;
    state_line.point = 0;
    if(p == 0)
    {
        state_line.point = 3; //Si on est au debut de la regle
        if(state_line.point == s.size())  // Verification de la position du point //on regarde si on est sur une regle
        {
            for(int i=0; i<a.size(); i++)
            {
                for(int j = 0; j<a[i].regles.size(); j++)
                {
                    cpt ++;
                    ss = a[i].name; //Adaptation pour comparer deux string
                    ss = ss + "->";
                    ss = ss + a[i].regles[j];
                    if(s == ss)
                    {
                        state_line.regle = cpt; // S'il est completement a droite completion avec nom de la regle
                    }
                }
            }
        }
    }
    else  // Cas particulir de epsilon
    {
        state_line.point = p;
        if((p == s.size())&&(state_line.rule.at(0)=='S'))  //condition pour reconnaitre l'axiome
        {
            state_line.regle = -1;
        }
        else if(p == s.size())  //si on est droite la regle
        {
            for(int i=0; i<a.size(); i++)
            {
                for(int j = 0; j<a[i].regles.size(); j++) //cf plus haut
                {
                    cpt ++;
                    ss = a[i].name;
                    ss = ss + "->";
                    ss = ss + a[i].regles[j];
                    if(s == ss)
                    {
                        state_line.regle = cpt;
                    }
                }
            }
        }
    }
    return state_line;
}

line_etat ligne_etat(line_etat &b, vector<variable> a)  // fonction pour avancer le point
{
    line_etat state_line;
    state_line.regle = 0; //recopier une ligne en avancant le point
    int cpt = 0;
    string s;
    state_line.rule = b.rule;
    state_line.point = b.point + 1;
    if((state_line.point == state_line.rule.size())&&(state_line.rule.at(0)=='S'))
    {
        state_line.regle = -1;
    }
    else if(state_line.point == state_line.rule.size())
    {
        for(int i=0; i<a.size(); i++)
        {
            for(int j = 0; j<a[i].regles.size(); j++)
            {
                cpt ++;
                s = a[i].name;
                s = s + "->";
                s = s + a[i].regles[j];
                if(state_line.rule == s)
                {
                    state_line.regle = cpt;
                }
            }
        }
    }
    return state_line;
}

void affiche(line_etat l)   // affichage d'une ligne d'état
{
    int i;
    for(i=0; i<l.point; i++)
    {
        cout << l.rule.at(i);
    }
    cout << ".";
    for(i=l.point; i<l.rule.size(); i++)
    {
        cout << l.rule.at(i);
    }
    if(l.regle > 0)
    {
        cout << "  R" << l.regle;
    }
    else if(l.regle == -1)
    {
        cout << "  axiome";
    }
    cout << endl;
}


void affiche(trans a) //affichage d'une transition
{
    cout <<"transition sur "<< a.A << " vers I" << a.etat << endl;
}

etat state(vector<variable> a, int &cpt)  // fontion pour construire I0
{
    etat e;
    e.rule.push_back(ligne_etat(a[0].name)); // Constructeur de l'axiome
    int i,j;
    string s;
    for(i=0; i<a.size(); i++)
    {
        for(j = 0; j<a[i].regles.size(); j++)
        {
            s = (a[i].name);
            s = s+ "->" ;
            s = s + a[i].regles[j];
            e.rule.push_back(ligne_etat(s,a));
        }
    }
    bool verif;
    for(i=0; i<e.rule.size(); i++)
    {
        verif = 1;
        if (e.rule[i].point != e.rule[i].rule.size())
        {
            for(j = 0; j<e.transitions.size(); j++) // Verification que la transition n'existe pas deja
            {
                if(e.transitions[j].A==e.rule[i].rule.at(e.rule[i].point))  //on regarde si on a pas deja la transition
                {
                    verif = 0;
                }
            }

            if(verif)
            {
                cpt++;
                trans t;
                t.A = e.rule[i].rule.at(e.rule[i].point);
                t.etat = cpt;
                e.transitions.push_back(t); // Creation d'une nouvelle transition
            }
        }
    }

    return e;
}

etat state(etat e, trans b, vector<variable> a,int &cpt)  // Constructeur a partir de l'etat precedent et de sa transition vers ce nouvel etat
{
    etat E;
    int i, j ,k;
    string s;
    for(i=0; i<e.rule.size(); i++) // Creation des regles avancees de la tansition
    {
        if(e.rule[i].rule.size()!=e.rule[i].point){
            if(b.A==e.rule[i].rule.at(e.rule[i].point))
            {
                E.rule.push_back(ligne_etat(e.rule[i],a));
            }
        }
    }
    vector<int> controle;// ajout d'un controle pour empecher les boucles infinies
    bool verif;
    for(i=0; i<E.rule.size(); i++) // Creation de regles engendrees par celles ci
    {
        verif = 1;
        for(j=0; j<a.size(); j++)
        {
            for(k=0; k<controle.size(); k++)
            {
                if(controle[k]==j)
                {
                    verif = 0;
                }
            }
            if(E.rule[i].rule.size()!=E.rule[i].point){
                if((a[j].name==E.rule[i].rule.at(E.rule[i].point))&&(verif))
                {
                    for(k=0; k<a[j].regles.size(); k++)
                    {
                        s = (a[j].name);
                        s = s+ "->" ;
                        s = s + a[j].regles[k];
                        E.rule.push_back(ligne_etat(s,a));
                        controle.push_back(j);
                    }
                }
            }
        }
    }
     // Ajout des transitions
    for(i=0; i<E.rule.size(); i++)
    {
        verif = 1;
        if(E.rule[i].rule.size()!=E.rule[i].point){
        for(j = 0; j <E.transitions.size(); j++)
        {

                if(E.transitions[j].A==E.rule[i].rule.at(E.rule[i].point))
                {
                    verif = 0;
                }

        }
        if((verif))
        {
            cpt++;
            trans t;
            t.A = E.rule[i].rule.at(E.rule[i].point);
            t.etat = cpt;
            E.transitions.push_back(t);
        }
        }
    }
    return E;
}
etat equilibre_transition(int a, int b, etat e )
{
    for(int i=0; i<e.transitions.size(); i++)
    {


        if(a== e.transitions[i].etat)
        {
            e.transitions[i].etat = b;
        }
        else if(e.transitions[i].etat>a)
        {
            e.transitions[i].etat--;
        }
    }
    return e;
}

vector<rules> return_rules(etat e)
{
    vector<rules> v;
    rules r;
    for(int i=0; i<e.rule.size(); i++)
    {

        r.num = e.rule[i].regle;
        r.r = e.rule[i].rule;
        if(r.num>0)
        {
            v.push_back(r);
        }
    }
    return v;
}
void affiche(etat e)//affichage d'un etat
{
    int i;
    for(i=0; i<e.rule.size(); i++)
    {
        affiche(e.rule[i]);
    }
    cout << endl;
    for(i=0; i<e.transitions.size(); i++)
    {
        affiche(e.transitions[i]);
    }
    cout << endl << endl << endl;
}

automate creation_automate(vector<variable> a)//fonction permettant la creation d'un automate
{
    int cpt_4 = 0, k;
    automate A;
    A.etats.push_back(state(a,cpt_4)); // Creation du premier etat I0
    etat e;
    int verif;
    int cpt = 0, cpt_2 = 1, cpt_3 = 1;
    while(cpt != cpt_2)  // A chaque nouvel etat des transition vont apparaitre on les traite comme si elle menaient a un nouvel etat qu'on cree on verifie ensuite s'il il s'agit d'un doublon qu'on supprime auquel cas
    {
        for(int i=cpt; i<cpt_2; i++)
        {
            for(int j=0; j<A.etats[i].transitions.size(); j++)
            {
                e = state(A.etats[i],A.etats[i].transitions[j],a,cpt_4); // Creation d'un nouvel etat
                verif = -1;
                for(k=0; k<A.etats.size(); k++) // Comparer pour verifier que l'etat n'existe pas deja
                {
                    if(compare(e, A.etats[k]))
                    {
                        verif = k;
                    }
                }
                if(verif==-1)
                {
                    A.etats.push_back(e); // Etat unique est ajoute a l'automate
                    cpt_3++;
                }
                else
                {
                    for(k=0; k<A.etats.size(); k++)
                    {
                        A.etats[k] = equilibre_transition(A.etats.size(),verif, A.etats[k]); // Les transitions sont adaptes a l'eventuelle suppression d'un etat
                    }
                    cpt_4--;
                }
            }
        }
        cpt = cpt_2;
        cpt_2 = cpt_3;
    }
    return A;
}

void affiche(automate a)//affichage d'un automate
{
    for(int i=0; i< a.etats.size(); i++)
    {
        cout << "I" << i << " :" << endl << endl;
        affiche(a.etats[i]);
    }
}

int main()
{

    vector<variable> g;
    ifstream file("SITRUK_GIRARD_test.txt");
    string line,r;
    bool verif,condition = 1;
    int i, j;
    variable v;
    if(file.is_open())
    {
        while(getline(file,line)) // Lecure du txt securisee
        {
            if((line.size()>2)&&(line.at(1)==' ')&&(line.at(0)!='S'))  // Reserve a l'axiome
            {
                r = "";
                for(i=2; i<line.size(); i++) // Isolation de la regle
                {
                    if((line.at(i)!='e')&&(line.at(i)!=' '))
                    {
                        r = r + line.at(i);
                    }
                }
                verif = 0;
                for(i=0; i<g.size(); i++) // Verification que la variable n'existe pas deja
                {
                    if(g[i].name ==line.at(0))
                    {
                        verif = 1;
                        g[i].regles.push_back(r); // Ajout de la regle dans la classe representant la variable
                    }
                }
                if((verif == 0)&&(line.at(0)!='e'))  // Creation d'une nouvelle variable
                {
                    v.name = line.at(0);
                    g.push_back(v);
                    g[g.size()-1].regles.push_back(r);
                }
                else if(verif == 0)
                {
                    condition = 0;
                }
            }
            else
            {
                condition = 0;
            }
        }
    }

    else
    {
        condition = 0;
    }
    if(condition)  // Test de la validite du txt
    {
        cout << "Automate :" << endl << endl << endl;
        automate a = creation_automate(g); // Envoie aux methodes pour creer l'automate
        affiche(a);
    }
    else
    {
        cout << "FICHIER TEXTE PAS AUX NORMES!";
    }
}
