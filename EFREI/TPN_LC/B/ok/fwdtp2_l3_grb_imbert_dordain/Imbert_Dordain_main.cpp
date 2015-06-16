#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <set>
#include <queue>
#include <windows.h>
#include <string>

using namespace std;

class Grammar{
	public:
	vector<vector<vector<string>>> regles; // Creation d'un tableau a trois dimensions afin de stocker les règles d'un Même NT au même ndroit
	map<string, int> NT_string_to_int; // tableau des non terminaux
	vector<string> NT_int_to_string;
	set<string> Terminaux; // tableaux des terminaux
	map<string,int> symboles; // tableaux de tous les symboles
	map<int,string> symboles_int_string;
	set<string> Nullable; // Tous les NT donnant epsilon
	vector<set<string>> premiers; // tableau de premiers
	vector<set<string>> suivants; // tableau des suivants

    /**Lors de la lecture des régles, on a besoin de savoir si la regle est issu
    d'un NT connu ou non si le NT (non terminal) est connu alors on utilise la fonction
    ajouter_regles_pour_NT sinon get_regles_pour_NT*/
	vector<vector<string>>& ajouter_regles_pour_NT(string nt){
		regles.emplace_back();
		NT_string_to_int[nt] = regles.size()-1;
		NT_int_to_string.push_back(nt);
		return regles[regles.size()-1];
	}

	vector<vector<string>>& get_regles_pour_NT(string nt){
		for(auto& p : NT_string_to_int)
		{
			if(p.first == nt)
				return regles[p.second];
		}
	}

    /**Permet de vérifier qu'un NT existe déjà dans le tableau des NT*/
	bool exist(string chaine){
		for(auto& p : NT_string_to_int)
		{
			if(p.first == chaine)
				return true;
		}return false;
	}

    /**Permet de déterminer si un symbole est un Terminal*/
	bool est_un_terminal(string nt)
	{
		if(Terminaux.find(nt) != Terminaux.end())
			return true;
		else
			return false;
	}

    /**Permet de déterminer si un symbole est un non_terminal*/
	bool est_un_non_terminal(string nt){
		return !est_un_terminal(nt);
	}


	friend ostream& operator<<(ostream& os, Grammar& g);
};

/**On surcharge l'opérateur << pour pouvoir afficher la grammaire*/
ostream& operator<<(ostream& os, Grammar& g){
	for(int ligne=0; ligne<g.regles.size();++ligne){
		vector<vector<string>>& regles_de_NTi = g.regles[ligne];
		for(int prod=0; prod<regles_de_NTi.size(); ++prod){
			os << g.NT_int_to_string[ligne] << " ->";
			vector<string>& production = regles_de_NTi[prod];
			for(string& chaine : production){
				os << ' ' << chaine;
			}
			os<< endl;
		}
	}
	return os;
}

/**Affiche les non-terminaux*/
void affiche_non_terminaux(Grammar& g)
{
	cout << endl << "Les non-terminaux sont : ";
	for(string s : g.NT_int_to_string)
		cout << s << " ";
}

/**Recupere les terminaux à partir de la grammaire g*/
void recup_terminaux(Grammar& g)
{
	set<string> tmp_NT;
	set<string> ensemble;

	for(string s : g.NT_int_to_string)
		tmp_NT.insert(s);

	for(vector<vector<string>>& a : g.regles)
		for(vector<string>& se : a)
			for(string& ss : se)
				ensemble.insert(ss);

	set_difference(ensemble.begin(), ensemble.end(), tmp_NT.begin(), tmp_NT.end(),
		inserter(g.Terminaux, g.Terminaux.end()));
}

/*Affiche les terminaux*/
void affiche_terminaux(Grammar& g)
{
	cout << endl << "Les terminaux sont : ";
	for(string s : g.Terminaux)
		cout << s << " ";
}

void affiche_nullable(Grammar& g)
{
	cout << endl << "Les elements nullables sont : ";
	for(string s : g.Nullable)
		cout << s << " ";
}

/**Permet de détecter si un NT produit une règle contenant epsilon, si c'est le cas, on le met dans Nullable*/
void detection_epsilon(Grammar& g)
{
    string element;

    for(int i= 0; i<g.regles.size(); i++)
        for(int j=0; j<g.regles[i].size(); j++)
            for(int k=0; k<g.regles[i][j].size(); k++)
                if(g.regles[i][j][k] == "epsilon")
                    g.Nullable.insert(g.NT_int_to_string[i]);


    int cpt = 0;
    do{
        for(int i= 0; i<g.regles.size(); i++)
             for(int j=0; j<g.regles[i].size(); j++)
             {
                if(find(g.Nullable.begin(), g.Nullable.end(), g.regles[i][j][0]) != g.Nullable.end())
                    g.Nullable.insert(g.NT_int_to_string[i]);

                cpt++;
             }
    }while(cpt < g.regles.size()*g.Nullable.size());

     affiche_nullable(g);
}

    // créer un graphe ayant pour dimension le nombre de symboles
    // on crée un graphe ex : A -> B A B, on relit la ligne correspondant au NT A à la colonne correspondant au NT B
    // il en va de même pour les Terminaux
    // Pour les NT etant dans la liste des Nullables, relie le NT au terminal d'après et ainsi de suite
    // On effecture la fermeture transitive
    // Si sur la ligne des NT, il y a un 1 sur un T alors T permiers de NT

void detect_premier(Grammar& g)
{
    bool graphe[g.symboles.size()][g.symboles.size()];

     for(int i= 0; i<g.symboles.size(); i++)
        for(int j=0; j<g.symboles.size(); j++)
            graphe[i][j] = false;

    for(int i= 0; i<g.NT_int_to_string.size(); i++)
        for(int j=0; j<g.regles[i].size(); j++)
            for(int k=0; k<g.regles[i][j].size(); ++k)
            {
                string symb = g.regles[i][j][k];
                graphe[g.symboles[g.NT_int_to_string[i]]][g.symboles[g.regles[i][j][k]]] = true;
                if(g.est_un_terminal(symb) || g.Nullable.find(symb) == g.Nullable.end())
                    break;
            }

    int i, j, k;

    for(k = 0; k < g.symboles.size(); k++)
       for(i = 0; i < g.symboles.size(); i++)
          for(j = 0; j < g.symboles.size(); j++)
             graphe[i][j] = graphe[i][j] || (graphe[i][k] && graphe[k][j]);


    cout << endl << endl << "Calcul des premiers " << endl;

    g.premiers.resize(g.NT_int_to_string.size());
    int a = 0;

    for(k = 0; k < g.symboles.size(); k++)
    {
        if(g.est_un_non_terminal(g.symboles_int_string[k]))
        {
           for(i = 0; i < g.symboles.size(); i++)
           {
                if((graphe[k][i] == true)&&(g.est_un_terminal(g.symboles_int_string[i])))
                {
                    g.premiers[a].insert(g.symboles_int_string[i]);
                }
            }
            a++;
        }
    }


    for(k = 0; k < g.premiers.size(); k++)
    {
        cout << "P(" << g.NT_int_to_string[k] << ") = ";
        for(string i : g.premiers[k])
            cout << i << " ";

        cout << endl;
    }

}
 /**Même chose que pour les premiers
 On relie l'axiome à $, et on ne prend pas en compte epsilon
 Pour des raisons de praticité, on gardera epsilon à la place de $, et on changera son nom*/
void detect_suivant(Grammar& g)
{
    bool graphe[g.symboles.size()][g.symboles.size()];

    for(int i= 0; i<g.symboles.size(); i++)
        for(int j=0; j<g.symboles.size(); j++)
            graphe[i][j] = false;

    graphe[0][g.symboles["epsilon"]] = true;
    graphe[1][g.symboles["epsilon"]] = true;

    int pos, pos_NT, taille, i;

    for(int i= 0; i<g.regles.size(); i++)
        for(int j=0; j<g.regles[i].size(); j++)
            for(int k=0; k<g.regles[i][j].size(); k++)
            {
                if(g.regles[i][j][k] == g.NT_int_to_string[i])
                {
                    pos_NT = k;
                    taille = g.regles[i][j].size();

                    for(pos = pos_NT+1; pos < taille; pos++)
                    {
                        string a = g.regles[i][j][pos];

                        if(g.est_un_terminal(a))
                        {
                            graphe[g.symboles[g.NT_int_to_string[i]]][g.symboles[a]] = true;
                            break;
                        }
                        else
                        {
                            int n_NT = g.NT_string_to_int[a];

                            for(string s : g.premiers[n_NT])
                            {
                                if(s != "epsilon")
                                    graphe[g.symboles[g.NT_int_to_string[i]]][g.symboles[s]] = true;
                            }

                            if(g.Nullable.find(a) == g.Nullable.end())
                               break;
                        }
                    }
                }

            }

    int j, k;

    for(k = 0; k < g.symboles.size(); k++)
       for(i = 0; i < g.symboles.size(); i++)
          for(j = 0; j < g.symboles.size(); j++)
             graphe[i][j] = graphe[i][j] || (graphe[i][k] && graphe[k][j]);

    cout << endl << endl << "Calcul des suivants " << endl;

    g.suivants.resize(g.NT_int_to_string.size());
    int a = 0;

    for(k = 0; k < g.symboles.size(); k++)
    {
        if(g.est_un_non_terminal(g.symboles_int_string[k]))
        {
           for(i = 0; i < g.symboles.size(); i++)
           {
                if((graphe[k][i] == true)&&(g.est_un_terminal(g.symboles_int_string[i])))
                {
                    g.suivants[a].insert(g.symboles_int_string[i]);
                }
            }
            a++;
        }
    }

    for(k = 0; k < g.suivants.size(); k++)
    {
        cout << "S(" << g.NT_int_to_string[k] << ") = ";
        for(string i : g.suivants[k])
        {
            if(i == "epsilon")
                cout << "$" << " ";
            else
                cout << i << " ";
        }
        cout << endl;
    }
}

/**Lecture du fichier
On met les règles dans le tableau de regles et on place le NT produisant la règle dans le
tableau de NT s'il n'y ai pas déjà*/
Grammar lecture_du_fichier(string name)
{
	// Ouverture du fichier
	int a = 2;
	string file_name = name + ".txt";
	std::ifstream file(file_name);
	Grammar g;
	bool axiome = false;
	if(file)
	{

		string ligne, chaine;
		while(getline(file, ligne))
		{
			stringstream ss(ligne);
			ss >> chaine;


            if(axiome == false)
            {
                axiome = true;
                string chaine_p = chaine + "'";
                vector<vector<string>>& regles_de_NT = (!g.exist(chaine_p)) ?
				g.ajouter_regles_pour_NT(chaine_p) : g.get_regles_pour_NT(chaine_p);

                vector<string> production;
                production.push_back(chaine);

                g.symboles[chaine_p] = 0;
                g.symboles_int_string[0] = chaine_p;
                g.symboles[chaine] = 1;
                g.symboles_int_string[1] = chaine;
                regles_de_NT.push_back(production);
            }



                vector<vector<string>>& regles_de_NT = (!g.exist(chaine)) ?
                    g.ajouter_regles_pour_NT(chaine) : g.get_regles_pour_NT(chaine);

                vector<string> production;
                while(ss >> chaine)
                {
                    production.push_back(chaine);

                    std::map<string, int>::iterator It = g.symboles.find(chaine);
                    if (It != g.symboles.end())
                    {
                        cout << "";
                    }
                    else
                    {
                        g.symboles[chaine] = a;
                        g.symboles_int_string[a] = chaine;
                        a++;
                    }
                }
                regles_de_NT.push_back(production);

		}
		file.close();
	}
	return g;
}

/*
Créer la liste des symboles utilisées = union des T et NT
*/
vector<string> Create_symbol_list(Grammar& g)
{
    vector<string> tmp;

	for(string s : g.NT_int_to_string)
		tmp.push_back(s);

    for(string s : g.Terminaux)
        tmp.push_back(s);

        return tmp;


}
/*
Créer la liste des regles de la grammaire donnée. *
Utilisée pour créer l'état I0
*/
vector<string> Create_regle_list(Grammar& g)
{
    vector<string> tmp;
    string tm;
    for(int ligne=0; ligne<g.regles.size();++ligne)
        {
            vector<vector<string>>& regles_de_NTi = g.regles[ligne];
            for(int prod=0; prod<regles_de_NTi.size(); ++prod)
            {
                //cout << g.NT_int_to_string[ligne] << " ->";
                vector<string>& production = regles_de_NTi[prod];
                tm ="";
                for(string& chaine : production)
                {
                    tm = tm + " " + chaine;
                }
                tmp.push_back(tm);
                //cout<< endl;
            }
        }
        return tmp;
}
/*
Classe implémentant l'état de l'automate SLR.
*/
class Etat
{
public:
    int numero; // numéro de l'état
    // liste des constructeurs surchargés
    Etat(vector<string> symboles)
    {
        this->symboles = symboles;
    }
        Etat(int i)
    {
        this->numero = i;
    }
    Etat(string nom,vector<string> symboles)
    {
        //this->symboles = symboles;
        this->name = nom;
    }
        Etat(string nom)
    {
        //this->symboles = symboles;
        this->name = nom;
    }
    string name; // nom de l'état
    vector<string> symboles; // liste des NT et T de la grammar
    vector<Etat> transitions; // liste des transitions = NT + T
    vector<string> regles; // regles de cet état avec les . mais SANS les éléments à gauceh del a fleche
private:
    // tout est en publique pour simplifier l"utilisation.
};

class Graphe
{
public:
    int getValue() const;
    void setValue(int value);

private:
    int value;
    vector<Etat> listeEtats;
};

/*
Vérifie si la chaine s fournie en parametre est un reduce = elle se termine par un "." OU par "epsilon"
*/
bool isReduce(string s)
{

    string tmp;
    string tmp2;
    stringstream ss(s);
    while( ss >> tmp )
    {
        tmp2 = tmp;
    }
    if(tmp2 == "." ||tmp2 ==  " . " ||tmp2 ==  ". "|| tmp2 == " ." || tmp2 == "epsilon" ||tmp2 ==  " epsilon " ||tmp2 ==  "epsilon "|| tmp2 == " epsilon")
    {
        return true;
    }
    return false;
}

vector<string> regleTransition(vector<string> oldregles, string transition)
{
    bool modified;
    bool nogo;
    string tmp;
    string tmp2;
    vector<string> newregles;
    for(string &s : oldregles)
    {
        modified = false;
        nogo = false;
        stringstream ss(s);
        tmp2.clear();
        if(!isReduce(s))
        {
            while(ss >> tmp)
            {
                if(tmp == ".")
                {
                    ss >> tmp;
                    if(tmp == transition && tmp != "epsilon")
                   // if(tmp == transition)
                    {
                        tmp2 = tmp2 +""+ tmp +" . ";
                        modified = true;
                    }else{}
                   /* if(tmp == transition)
                    {
                    tmp2 = tmp +" " +".";
                    modified = true;
                    ss >> tmp;
                    }*/
                }else{tmp2 = tmp2 +" "+ tmp + " " ;}
                //tmp2 = tmp2 +" "+ tmp;
            }
            if(modified)
            {
                s = tmp2;
                newregles.push_back(tmp2);
            }
        }
    }
    return newregles ;
}
/*
Vérifie la présence de l'état donné dans une file.
La on considere que 2 états sont différents si leur regles sont différents.
*/
bool alreadyPresentEtat(queue<Etat> tmpfile, Etat Etattmp)
{
    while(!tmpfile.empty())
    {
        if(tmpfile.front().regles == Etattmp.regles)
        {

            return true;
        }

        tmpfile.pop();
    }
    return false;
}

/*
Vérifie la présence de l'état donné dans un vector.
La on considere que 2 états sont différents si leur regles sont différents.
*/
bool alreadyPresentEtat(vector<Etat> tmpvector, Etat Etattmp)
{
    for(Etat vs : tmpvector )
    {
        if(Etattmp.regles == vs.regles )
            {
            return true;
            }
    }
    return false;
}
/*
Retourne l'index sous forme d'un entier dans un vector de string d'une string donnée.
*/
int getIndexVector(vector<string> source, string str)
{
    int i = 0;
    for(string s : source)
    {
        if(s == str)
            return i;

        i++;
    }
        return -1;
}

/*
Si un état est déja présent dans un vector, retourner le numéro de l'état déja rpésent
Utilisée pour savoir si un état de l'automate SLR existe déja et donc que l'état en traitement doit boucler dessus.
*/
int getAlreadyPresentEtatNumero(vector<Etat> tmpvector, Etat Etattmp)
{
    for(Etat vs : tmpvector )
    {
        if(Etattmp.regles == vs.regles )
            {
            return vs.numero;
            }
    }

    return -1;
}

/*
Retourne le numéro de regle d'origine d'un reduce donné
Utilisée pour construire la table d'analyse.
*/
int getReduceNumero(vector<string>v, string str)
{
    int i = 0;
    string tmp2;
    //cout << "str = " << str << endl;
    for(string ss : v)
    {
            ss = ss + " . ";
            //ss = ss + " . ";
        i++;
        stringstream ss1(ss);
        string tmp1;
        string tmp3;

        stringstream ss3(str);
        tmp2.clear();
        string tmp4;

        while(ss1 >> tmp1)
            tmp3 = tmp3 + tmp1;

        while(ss3 >> tmp2)
            tmp4 = tmp4 + tmp2;

           // cout << " tmp3 = " << tmp3 << endl;
            if(tmp3 == "epsilon.")
            {
                cout << "reduce en EPSILON sur la regle " << i << endl;
                return i;
            }


        if(tmp4 == tmp3)
        {
            cout << "reduce sur la regle " << i << endl;
            return i;
        }

    }
    return -1;
}


int main()
{
	string nom = "g";
	vector<Etat> EtatsFinaux;// tableau des étatsfinaux de l'automate.

    Grammar g = lecture_du_fichier(nom);

    cout << g;

    affiche_non_terminaux(g);

    recup_terminaux(g);

    affiche_terminaux(g);


    detection_epsilon(g);

    detect_premier(g);

    detect_suivant(g);

    vector<vector<int>> shifts;// tableau des shifts de la table d'analyse
    vector<string> SymbolesTotaux;// symboles correspondants au cologones de la table d'analyse

    //création du tableau de SymboelsTotaux
    for(string sssss : g.Terminaux)
    {
        if(sssss != "epsilon")
            SymbolesTotaux.push_back(sssss);
    }
    SymbolesTotaux.push_back("$");

    for(string sssss : g.NT_int_to_string)
        SymbolesTotaux.push_back(sssss);


    // Création manuelle de l'état I0
    Etat* Io = new Etat("Io",Create_symbol_list(g));
    Io->numero = 0;

    // donne à l'état I0 les regles de bases = sans "."
    Io->regles = Create_regle_list(g);
    EtatsFinaux.push_back(*Io);

    queue<Etat> listeAttente; // liste d'attente de traitement des états
    Etat* Etattmp;
    int position;
    bool Goon;
    int compteur = 1;
    string sttmp;
    listeAttente.push(*Io);
    // Création des nouvelles regles avec des"." au début
    for(string &s : listeAttente.front().regles)
        s = ". " + s;

    while(!listeAttente.empty())// condition d'arret de la création d'états : tant que la file de traitement n'est pas vide.
    {
        compteur = EtatsFinaux.size();

        for(string s : listeAttente.front().regles) // pour chaque regle de l'état en traitement
        {
            if(!isReduce(s)) // si cet état n'est PAS un reduce
            {
                stringstream ss(s);
                string tmp1;
                while(ss >> tmp1) // lecture de la regle
                {
                    // Décalage du "." dans la regle
                   if(tmp1 == ".")
                   {
                    ss >> tmp1;
                    if(tmp1 != ".")
                    {
                        Goon = true;
                        for(string s : listeAttente.front().symboles) // si le symbole n'est pas déja ds le tableau de symboles
                        {
                            if(tmp1 == s&& tmp1 != "")
                                Goon = false;
                        }
                    }
                        if(Goon && tmp1 != "."&& tmp1 != " . "&& tmp1 != " ."&& tmp1 != ". " && tmp1 != "epsilon")
                        {
                            listeAttente.front().symboles.push_back(tmp1); // Alors on rajoute le symbole dans la liste des symboles pour lequels il faut faire une transition
                        }
                   }
                }
                ss.clear();
            }
        }
        //cout << endl;
        vector<int> tmpshifts(SymbolesTotaux.size() + 1, 0); // vector correspondant à la ligne du tableau d'analyse des shifts de l'état en traitement
        for(string s : listeAttente.front().symboles)
            {
                Etattmp = new Etat(compteur); // Etat temporaire : on va créer l'état puis regarder si il existe déja,
                //si il existe on le push dans la file d'attente sinan on le détruit ET on fait linker l'état en traintement vers l'état identique éxistant déja
                Etattmp->regles = regleTransition(listeAttente.front().regles, s);
                tmpshifts[SymbolesTotaux.size() ] = listeAttente.front().numero ;
                tmpshifts[getIndexVector(SymbolesTotaux,s)] = Etattmp->numero;
                string tmp3;
                vector<string> reglesarecopier; // liste des regles à recopier
                reglesarecopier.clear();
                bool Goon2;
                for(string s : Etattmp->regles) // pour chauqe regle
                {
                    Goon2 = true;
                    stringstream ss(s);
                    while(ss >> tmp3)
                    {
                        if(tmp3 == ".") // re vérification de reduce
                        {
                            ss >> tmp3;
                            for(string s99 : reglesarecopier)
                            {
                                if(s99 == tmp3)
                                    Goon2 = false; // si la regle existe déja, on ne la recopie pas
                            }
                            if(Goon2 && tmp3 != "."&& tmp3 != " . "&& tmp3 != " ."&& tmp3 != ". ")
                                reglesarecopier.push_back(tmp3); // On créer la lite des états devant etre reocpuiés depuis I0
                        }
                    }

                }
                for(string s98 : reglesarecopier) // recopie des états depuis I0
                {
                    for(vector<string> s97 : g.regles[g.NT_string_to_int[s98]])
                    {
                        string tmp6;
                        tmp6.clear();
                        for(string s96 : s97) // étude de la string
                        {
                            string tmp5;
                            tmp6 = tmp6+ s96+ " "; // concatenation
                        }
                        Etattmp->regles.push_back(". "+ tmp6); // on recopie la regle avec le point au bon endroit
                    }
                }

              if(alreadyPresentEtat(EtatsFinaux, *Etattmp)) // si l'état est déja rpésent on recupere le numééro de l'état existant identique
                {
                    tmpshifts[getIndexVector(SymbolesTotaux,s)] = getAlreadyPresentEtatNumero(EtatsFinaux,*Etattmp);
                }else // si l'état n'existe pas, on le push puis on passe à la suite
                {
                    listeAttente.push(*Etattmp);
                     compteur++;
                    EtatsFinaux.push_back(*Etattmp);
                }
            }

shifts.push_back(tmpshifts); // on créer la ligen correspondant au nouvel état dans le tableau des shifts
        listeAttente.pop(); // on supprimer l'état qui vient d'etre traité de la liste
    }

cout << "Affichage de l'automate : " << endl;

int cpt = 0;

/*
Création du tableau de shhifts de la table d'analyse. -> 3D car on peut avoir plusieurs reduce / case
*/
vector<string> vtempo;

vector<vector<string>> vtempo2(SymbolesTotaux.size(),vtempo);

vector<vector<vector<string>>> reduces(EtatsFinaux.back().numero + 1,vtempo2);



    for(Etat e : EtatsFinaux) // pour chaque état on va remplir la table de shifts
    {
        int n_etat = e.numero;
        cout << endl<<"Etat I" << e.numero << endl<<endl;

        vector<string> tmp = e.regles;
        vector<vector<string>> rules;

        for(string& s : tmp)
		{
			stringstream ss(s);
			vector<string> res;
			string symbole;
			while(ss >> symbole)
				if(symbole.compare(".") != 0)
					res.push_back(symbole);
			rules.push_back(res);
		}


        for(int r=0; r<rules.size(); ++r)
        {
            for(int i= 0; i<g.regles.size(); i++)
                for(int j=0; j<g.regles[i].size(); j++)
                {
                    string vv;
                        vector<string> regle_de_g = g.regles[i][j];
						vector<string> regle_ = rules[r];
						bool same = true;
						if(regle_de_g.size() == regle_.size())
						{
							for(int p=0; p<regle_de_g.size(); ++p) // on regarde si al regle existe déja
							{
								if(regle_de_g[p].compare(regle_[p]) != 0)
								{
									same = false;
									break;
								}
							}
							}else{
								same = false;
							}

							if(same)
							{
								cout << g.NT_int_to_string[i] << " -> ";
								cout << tmp[r] << endl;

								if(isReduce(tmp[r])) // si c'est un reduce on regarder ses premiers
                                {
                                       // reduces[i][ii].push_back("r"+getReduceNumero(regle_, tmp[r]));
                                        int nb = getReduceNumero(Io->regles, tmp[r]); //recuperation du numéro de reduce pour avoir la ligne
                                        string snb;
                                        stringstream out;
                                        out << nb;
                                        snb = out.str();

                                        //remplir le tableau des reduces pr cette case
                                        vv = "r" +  snb + " ";
                                        cout << " on va place le reduce " << vv << " a la ligne " << n_etat << " et aux colones ";
                                         for(string s : g.suivants[i])
                                        {
                                            cout << s <<" " << endl;
                                            reduces[n_etat][g.symboles[s]].push_back(vv); // on push back le vector de reduce ds la bonne case
                                        }
                                }
								break;
							}
						}

					}

    	}
cout << endl<< endl<< endl;
cout << " table des shifts : " << endl<< endl;
//Affichage de la table de reduce
for (string so : SymbolesTotaux)
    cout << " " << so << " ";
cout << endl;
for(vector<int> v : shifts )
{
    for (int i : v)
        cout << " " << i << " ";

    cout << endl;
}

cout << " Table des reduces " << endl;

//Affichage du tableua de shifts
int ccc = 0;
bool premierpassage = true;
for(vector<vector<string>> vv : reduces)
{
    cout << endl;
    for( vector<string>v : vv)
    {
        if(premierpassage)
        {
            for(ccc = 0; ccc < g.symboles.size(); ccc++)
                cout << g.symboles_int_string[ccc] << "\t ";

            premierpassage = false;
            cout << endl;
        }

        for(string s : v)
        {
            cout << s << " ";

        }
        cout << " | ";

            cout << "\t";
    }
    cout << endl;
}
    return 0;
}
