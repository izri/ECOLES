#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

using namespace std;

/* Grammaire */
class Grammar
{
public:
	int axiom = 0;
	string epsilon = "epsi";
	vector<int> symboles_tnt;					// -1 pour T, un numero de 0 à cardinal de NT sinon
	vector<string> symboles_name;				// ecriture des symboles
	vector<int> nt_symb_id;						// Conversion de l'indice d'une regle vers l'ID du NT correspondant
	vector<vector<vector<int>>> rules;			// Règles de production pour chaque NT
	unordered_map<string, int> symboles_ids;	// Symbole -> id - accès amorti o(1)

	bool isNT(int symb_id){
		return !isT(symb_id);
	}

	bool isT(int symb_id){
		return 	(symboles_tnt[symb_id] == -1);
	}

	set<int> nullable(){
		set<int> set_nt_nullable;

		// Tous les X->epsi explicite
		for(int nt = 0; nt<rules.size(); ++nt)
			for(auto& prod : rules[nt])
				if(prod[0] == getID("epsi"))
					set_nt_nullable.insert(nt_symb_id[nt]);

		// Boucle tant qu'il reste des prods utiles
		set<int> visit = set_nt_nullable;
		int cpt = 0;
		do{
			cpt = 0;
			for(int nt = 0; nt<rules.size(); ++nt){
				int nt_id = nt_symb_id[nt];
				if(set_nt_nullable.find(nt_id) == set_nt_nullable.end()){
					for(auto& prod : rules[nt]){
						set<int> symb(prod.begin(), prod.end());
						if(includes(set_nt_nullable.begin(), set_nt_nullable.end(),
							symb.begin(), symb.end())){int rs;
							set_nt_nullable.insert(nt_id);
							cpt++;
						}
					}
				}
			}
		}while(cpt>0);

		return set_nt_nullable;
	}

	vector<vector<bool>> matrice_transitive(vector<vector<bool>>& g)
	{
		int n = g.size();
		vector<vector<bool>> m(n);

		for(int i=0; i<n; i++){
			m[i].resize(n);
			for(int j=0; j<n; j++)
				m[i][j] = false;
		}

		// Algorithme de Warshall
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				m[i][j] = g[i][j];

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(m[i][j] == false)
						m[i][j] = (m[i][k] && m[k][j])? true : false;

		return m;
	}

    pair<vector<set<int>>, vector<set<int>>> premiers_suivants(){
		set<int> annulable(nullable());

		int n = symboles_ids.size();
		vector<vector<bool>> graph(n);
		for(int i=0; i<n; ++i){
			graph[i].resize(n);
			for(int j=0; j<n; ++j){
				graph[i][j] = false;
			}
		}

		for(int r=0; r<rules.size(); ++r){
			for(auto& prod : rules[r]){
				for(int i : prod){
					graph[nt_symb_id[r]][i] = true;
					if(isT(i) || annulable.find(i) == annulable.end())
						break;
				}
			}
			if(annulable.find(nt_symb_id[r]) != annulable.end())
				graph[nt_symb_id[r]][getID("epsi")] = true;
		}

		vector<vector<bool>> m = matrice_transitive(graph);

		// Convertion
		vector<set<int>> prems(rules.size());
		for(int r=0 ; r<rules.size(); ++r)
			for(int j=0; j<m[nt_symb_id[r]].size(); j++)
				if(m[nt_symb_id[r]][j] && isT(j))
					prems[r].insert(j);

		//Suivants
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				graph[i][j] = false;

		for(int r=0; r<rules.size(); ++r){
			for(auto& prod : rules[r]){
				for(int p=0; p<prod.size(); ++p){
					int symb_id = prod[p];
					if(isNT(symb_id)){
						int pafter;
						for(pafter=p; pafter<prod.size(); ++pafter)
						{
							int symb_id_it = prod[pafter];
							// Y ajouter tous les premiers de symb_id_it
							if(isT(symb_id_it)){
								graph[symb_id][symb_id_it] = true;
							}else{
								for(int premier_ : prems[symboles_tnt[symb_id_it]]){
									graph[symb_id][premier_] = true;
								}
							}
							if(isT(symb_id_it) || annulable.find(symb_id_it) == annulable.end()){
								break;
							}
						}
						// beta annulable
						if(pafter == prod.size() || pafter == p){
							// Y ajouter Sx=Sy
							graph[symb_id][nt_symb_id[r]] = true;
						}
					}
				}
			}
		}

		// Epsi interdit
		for(int i = 0; i<n; ++i){
			graph[i][getID("epsi")] = false;
		}

		int dollar = getID("epsi"); // Ici pour les suivants epsi jou le role du dollar
		graph[getAxiomID()][dollar] = true;

		// Matrice transitive...
		m = matrice_transitive(graph);

		// Ensemble des suivants
		vector<set<int>> suivs(rules.size());
		for(int r=0 ; r<rules.size(); ++r)
			for(int j=0; j<m[nt_symb_id[r]].size(); j++)
				if(m[nt_symb_id[r]][j] && isT(j))
					suivs[r].insert(j);

		return std::make_pair(prems, suivs);
    }

	int getAxiomID(){
		return axiom;
	}

	string getEpsi(){
		return epsilon;
	}

	int getIDFromRuleID(int nt_id){
		return nt_symb_id[nt_id];
	}

	string getName(int symb_id){
		return symboles_name[symb_id];
	}

	int add_axiom(string axiom_name){
		int symb_id = symboles_ids.size();
		symboles_ids[axiom_name] = symb_id;
		symboles_name.push_back(axiom_name);

		int old_axiom_id = getAxiomID();
		rules.emplace(rules.begin());

		for(int& x : symboles_tnt)
			if(x != -1) ++x;

		nt_symb_id.insert(nt_symb_id.begin(), symb_id);
		symboles_tnt.push_back(0);

		axiom = symb_id;
		return symb_id;
	}

	// Retourne l'ID d'un symbole, le créer si il n'existe pas
	// TO DO : factorisation du code
	int getID(string symb, bool nt = false, int at_pos_rule = -1)
	{
		int symb_id;
		auto it = symboles_ids.find(symb);
		if(it != symboles_ids.end())
		{
			symb_id = it->second;
			if(nt && symboles_tnt[symb_id] == -1)
			{
				vector<vector<int>> a;
				if(at_pos_rule == -1)
				{
					nt_symb_id.push_back(symb_id);
					symboles_tnt[symb_id] = rules.size();
					rules.push_back(a);
				}
				else
				{
					rules.insert(rules.begin() + at_pos_rule+1, a);
					nt_symb_id.insert(nt_symb_id.begin() + at_pos_rule+1, symb_id);
					symboles_tnt[symb_id] = at_pos_rule;
					for(int p=at_pos_rule+1; p<rules.size(); ++p)
					{
						symboles_tnt[nt_symb_id[p]]++;
					}
				}
			}
		}
		else
		{
			symb_id = symboles_ids.size();
			symboles_ids[symb] = symb_id;
			symboles_name.push_back(symb);
			if(nt)
			{
				vector<vector<int>> a;
				if(at_pos_rule == -1)
				{
					nt_symb_id.push_back(symb_id);
					symboles_tnt.push_back(rules.size());
					rules.push_back(a);
				}
				else
				{
					rules.insert(rules.begin() + at_pos_rule+1, a);
					nt_symb_id.insert(nt_symb_id.begin() + at_pos_rule+1, symb_id);
					symboles_tnt.push_back(at_pos_rule);
					for(int p=at_pos_rule+1; p<rules.size(); ++p)
					{
						symboles_tnt[nt_symb_id[p]]++;
					}
				}
			}
			else
			{
				symboles_tnt.push_back(-1);
			}
		}
		return symb_id;
	}

	vector<int>& addRuleTo(int symb_id)
	{
		auto& r = rules[symboles_tnt[symb_id]];
		r.emplace_back();
		return r[r.size()-1];
	}

	vector<vector<int>>& operator[](int symb_id)
	{
		return rules[symboles_tnt[symb_id]];
	}

	vector<vector<int>> const& operator[](int symb_id) const
	{
		return rules[symboles_tnt[symb_id]];
	}

	/* Elimination d'une recursivité gauche directe cas général - TP1*/
	void eliminer_left_rec_direct()
	{
		int nb_rules = rules.size();
		for(int i=0; i<nb_rules; ++i)
		{
			set<int> alphas, betas;
			for(int r=0; r<rules[i].size(); ++r)
			{
				if(rules[i][r][0] == nt_symb_id[i])
					alphas.insert(r);
				else betas.insert(r);
			}

			// Rec gauche sur les règles de alpha
			if(alphas.size() > 0)
			{
				int new_nt = getID(symboles_name[nt_symb_id[i]] + "'", true, i); // rules modifié
				for(int r : alphas)
				{
					vector<int>& rule = addRuleTo(new_nt);
					vector<int>& old_rule = rules[i][r];
					for(int symb_i=1; symb_i<old_rule.size(); ++symb_i)
					{
						rule.push_back(old_rule[symb_i]);
					}
					rule.push_back(new_nt);
				}
				addRuleTo(new_nt).push_back(getID("epsi"));

				vector<vector<int>> beta_rules;
				for(int r : betas)
				{
					vector<int> rule;
					vector<int>& old_rule = rules[i][r];
					for(int symb_i=0; symb_i<old_rule.size(); ++symb_i)
					{
						if(old_rule[symb_i]!=getID("epsi"))
							rule.push_back(old_rule[symb_i]);
					}
					rule.push_back(new_nt);
					beta_rules.push_back(rule);
				}
				rules[i].clear();
				rules[i] = beta_rules;
				++i;
			}
		}
	}

	friend ostream& operator<<(ostream& os, Grammar const& g);
};

ostream& operator<<(ostream& os, Grammar const& g)
{
	vector<vector<vector<int>>> const& nt_set = g.rules;

	for(int i=0; i<g.rules.size(); ++i)
	{
		os << g.symboles_name[g.nt_symb_id[i]] << " ->";
		for(int r=0; r<g.rules[i].size(); ++r)
		{
			if(r>0) cout << " |";
			for(int symb=0; symb<g.rules[i][r].size(); symb++)
			{
				cout << ' ' << g.symboles_name[g.rules[i][r][symb]];
			}
		}
		cout << endl;
	}
	return os;
}

/* Item de l'automate */
class Etat
{
public:
	vector<vector<int>> rules;
	unordered_map<int, int> symb_id_next_etat_number;
	vector<int> reduces;
	vector<int>& add(vector<int>& rule){
		rules.push_back(rule);
	}

	Etat construct_etat_from(Grammar g, int symb_id)
	{
        Etat e;
        int point_id = -1;
        // Ajouter les regles .X
		for(auto& rule : rules)
		{
			vector<int> new_rule = rule;
			auto it = find(new_rule.begin(), new_rule.end(), point_id);
			auto it_point = it;
        	int symb_after_point = ((++it) != new_rule.end()) ? *it : -1;
        	if(symb_after_point != -1 && symb_after_point == symb_id)
			{
				swap(*it_point, *it); // Le point se décale d'un cran
				e.rules.push_back(new_rule);
			}
		}

		// Ajouter les regles .NT
        int line = 0;
        set<int> visit;
        while(line < e.rules.size())
		{
			auto& rule = e.rules[line];
			++line;

			// Récupération de .NT
			auto it = find(rule.begin(), rule.end(), point_id);
        	int symb_after_point = ((++it) != rule.end()) ? *it : -1;
        	if(symb_after_point != -1 && g.isNT(symb_after_point) && visit.find(symb_after_point) == visit.end())
			{
				visit.insert(symb_after_point);
				// On recopi les lignes NT -> .gamma
				int nt = g.symboles_tnt[symb_after_point];
				for(auto& rule_ : g.rules[nt])
				{
					vector<int> new_rule = rule_;
					if(new_rule[0] == g.getID("epsi")){
						new_rule.clear();
					}
					new_rule.insert(new_rule.begin(), -1);
					new_rule.insert(new_rule.begin(), symb_after_point);

					e.rules.push_back(new_rule);
				}

			}
		}
        return e;
	}

	int getXAfterPoint(int r, int point_id){
		auto& rule = rules[r];
		auto it = find(rule.begin(), rule.end(), point_id);
        return ((++it) != rule.end()) ? *it : -1;
	}

	void calculReduces(map<vector<int>, int>& reduces_rules, int point_id)
	{
		// mettre dans reduces les regles X->&alpha.
		reduces.clear();
		for(int i=0; i<rules.size(); ++i)
		{
			vector<int> rul = rules[i];
			if(rul[rul.size()-1] == point_id)
			{
				rul.pop_back();
				reduces.push_back(reduces_rules.find(rul)->second);
			}
		}

	}

	/* Deux états sont égaux si leur règles sont égales */
	bool operator==(Etat& e)
	{
		// Evite pas mal de calcul
		if(rules.size() != e.rules.size())
			return false;

		for(vector<int>& x : rules)
		{
			int is_found = false;
			for(vector<int>& y : e.rules)
			{
				int size_x = x.size();
				int same_rule = true;
				if(size_x != y.size())
				{
					same_rule=false;
				}
				else
				{
					for(int i=0; i<size_x; ++i)
					{
						if(x[i] != y[i])
						{
							same_rule=false;
							break;
						}
					}
				}

				if(same_rule)
				{
					is_found = true;
					break;
				}
			}

			if(!is_found)
			{
				return false;
			}
		}

		return true;
	}
};

/* Permet d'enregistrer l'execution à un moment t pour faire un backtracking */
class StateExec{
public:
	vector<int> pile;
	vector<int> entree;
	int sr_it;
	int choice_new_id;

	StateExec(vector<int>& p, vector<int>& e, int pos, int id)
	: pile(p), entree(e), sr_it(pos), choice_new_id(id)
	{}
};

class SLR
{
public:
	Grammar g;
		// + item - reduce
	vector<vector<vector<int>>> table;
	vector<vector<int>> reduces;

	map<vector<int>, int> rules_reduces(){
		map<vector<int>, int> reduces_map;
		int numero = 1;
		for(int r=0; r<g.rules.size(); ++r)
		{
			for(auto rule : g.rules[r])
			{
				if(rule[0] == g.getID("epsi"))
					rule.clear();
				rule.insert(rule.begin(), g.nt_symb_id[r]);
				if(reduces_map.find(rule)==reduces_map.end())
					reduces_map[rule] = numero;
				numero++;;

				reduces.push_back(rule);
			}
		}

		return reduces_map;
	}

	Etat initialisation_item(int point){
		Etat etat_zero;
		for(vector<int>& rule : reduces)
		{
			vector<int> new_rule = rule;
			if(new_rule[1] == g.getID("epsi"))
				new_rule[1] = point;
			else
				new_rule.insert(new_rule.begin()+1, point);
			etat_zero.add(new_rule);
		}
		return etat_zero;
	}

	vector<Etat> automate()
	{
		// Initialisation du calcul de l'automate
		vector<Etat> etats;
		int id_point = -1;
		map<vector<int>, int> reduces_map = rules_reduces();
		etats.push_back(initialisation_item(id_point));
		etats[0].calculReduces(reduces_map, id_point);

		// Tant qu'il reste des états à traiter
		int etat_i = 0;
		while(etat_i < etats.size())
		{
			Etat e = etats[etat_i];
			etat_i++;

			// On parcourt les .X uniques une seule fois
			set<int> x;
            for(int rule_id=0; rule_id<e.rules.size(); ++rule_id)
			{
				int symb_id = e.getXAfterPoint(rule_id, id_point);
				if(symb_id != -1 && x.find(symb_id) == x.end())
				{
					x.insert(symb_id);
					int next_;

					Etat new_e = e.construct_etat_from(g, symb_id);
					// Si Ii n'existe pas déjà
					bool found = false;
					for(int i=0 ; i <etats.size(); ++i)
					{
						if(new_e == etats[i])
						{
							next_ = i;
							found=true;
							break;
						}
					}

					if(!found){
						next_ = etats.size();
						new_e.calculReduces(reduces_map, id_point);

						etats.push_back(new_e);
					}

					etats[etat_i-1].symb_id_next_etat_number[symb_id] = next_;
				}
			}
		}

		return etats;
	}

	void table_analyse(vector<Etat>& etats, vector<set<int>>& suivs)
	{
		table.resize(etats.size());
		for(auto& ligne : table)
		{
			ligne.resize(g.symboles_name.size());
		}

        for(int i=0; i<etats.size(); ++i)
		{
			Etat& e = etats[i];
			for(auto& p : e.symb_id_next_etat_number)
			{
				table[i][p.first].push_back(p.second);
			}

			for(int r : e.reduces)
			{
				for(int s : suivs[g.symboles_tnt[reduces[r-1][0]]])
				{
					table[i][s].push_back(-r);
				}
			}
		}

	}

	SLR(Grammar& _g) : g(_g)
	{
		// Ajout de S'->S
		int old_axiom_id = g.getAxiomID();
		int axiom_id = g.add_axiom(g.getName(0) + "'");
		g.addRuleTo(axiom_id).push_back(old_axiom_id);

		cout << endl << "0) Grammaire augmentee" << endl <<g;

		// Calcul des suivants
		pair<vector<set<int>>, vector<set<int>>> ps = g.premiers_suivants();
		vector<set<int>>& prems = ps.first;
		vector<set<int>>& suivs = ps.second;

		cout<< endl << "1) Calcul des premiers et suivants" ;
		for(int i=0; i<prems.size(); i++){
			cout << endl << "P(" << g.symboles_name[g.nt_symb_id[i]] << ")=";
			for(int j : prems[i])
				cout << ' ' << g.symboles_name[j];
		}
		for(int i=0; i<suivs.size(); i++){
			cout << endl << "S(" << g.symboles_name[g.nt_symb_id[i]] << ")=";
			for(int j : suivs[i]){
				if(j == g.getID("epsi")) cout << " $";
				else cout << ' ' << g.symboles_name[j];
			}
		}
		cout << endl;

		// Calcul de l'automate
		vector<Etat> etats = automate();

		cout << endl << "2) Construction de l'automate";
		int eti = 0;
		for(Etat& et : etats)
		{
			cout << endl << "Item " << eti;
			for(auto& ru : et.rules)
			{
				cout <<endl;
				int ub = 0;
				for(int ir : ru)
				{
					if(ir==-1)cout << " .";
						else
					cout << ' ' << g.symboles_name[ir];
					if(ub==0)
						cout << " ->";
					ub++;
				}
			}

			cout << endl ;
			eti++;

			for(auto& p : et.symb_id_next_etat_number)
			{
				cout << "Le symbole " << g.symboles_name[p.first] << " vers I" << p.second << endl;
			}
			cout << "reduces :";
			for(int red : et.reduces)
			{
				cout << ' ' << red;
			}cout<< endl ;
		}

		// Table d'analyse
		table_analyse(etats, suivs);

		cout << endl <<"3) Table d'analyse" << endl;
		afficher_table();
	}

	void afficher_table()
	{
		for(int i=0; i<table[0].size(); ++i)
		{
			if(i == g.getID("epsi"))
				cout << '\t' << "$";
			else
				cout << '\t' << g.symboles_name[i];
		}

		for(int i=0; i<table.size(); ++i)
		{
			cout << endl << i;
			auto& ligne = table[i];
			for(vector<int>& sr : ligne)
			{
				cout << '\t';
				if(sr.size()>0)
				{
					if(sr[0]<0) cout << 'r' << -sr[0];
					else cout << sr[0];
				}
				for(int si=1; si<sr.size(); si++)
				{
					cout << '/' << 'r' << -sr[si];
				}
			}
		}cout << endl;
	}

	/* Reconnaitre un mot */
	bool execute(string word)
	{
		cout << endl << "Execution du mot " << word << endl;
		vector<int> pile;
		vector<int> entree, entree_inverse;

		// Initialisation de la PILE et de l'ENTREE
		pile.push_back(0);
		stringstream ss(word);
		string symbole;
		while(ss >> symbole)
		{
			auto pit = g.symboles_ids.find(symbole);
			if(pit == g.symboles_ids.end())
			{
				cout << "Erreur : le symbole " << symbole << " n'appartient pas au lexique du langage" << endl;
				return false;
			}
			int symb_id = pit->second;
			entree_inverse.push_back(symb_id);
		}
		entree_inverse.push_back(g.getID("epsi"));
		int n = entree_inverse.size();
        entree.resize(n);

        for(int i=n-1; i>=0; --i)
			entree[n-1-i] = entree_inverse[i];

		// Stocke les choix effectués, système de backtracking
		stack<StateExec> back_choice;

		// Entetes
		cout << endl << '\t' << "PILE" << '\t' << '\t' << '\t' << '\t';
		cout << "ENTREE" << '\t' << '\t' << '\t' << '\t' << "SORTIE" << endl;

		auto afficher_pile_entree = [&pile, &entree](Grammar& g)
		{
			//Afficher PILE
			string ps ="$";
			for(int i=0; i<pile.size(); ++i){
				ps += " ";
				if(i%2 == 1){
					ps += g.symboles_name[pile[i]];
				}else{
					stringstream ss;
					ss << pile[i];
					ps += ss.str();
				}
			}

			// Afficher ENTREE
			string es;
			for(int i=entree.size()-1; i>0; --i){
				es += g.symboles_name[entree[i]] + " ";
			}es += "$";

			// Mise en forme
			int tab = 8;
			int b = 6*tab + 4 + 6;
			int pw = ps.size();
			int ew = es.size();
			int d = b - pw - ew;

			cout << ps;
			while(d-- > 0)
				cout << ' ';
			cout << es << '\t';
		};

		afficher_pile_entree(g);

		bool impasse = false;
		int choice_new_id = 0;
		while(true)
		{
			int rs;
			int pile_number = pile.back();
			int entree_symb_id = entree.back();
			vector<int>& table_read = table[pile_number][entree_symb_id];

			// Gestion des cas avant d'effectuer un reduce/ un shift/ ou de marquer l'impasse
			if(impasse) // On revient sur le choix au dessus de la pile de choix
			{
				impasse = false;
				if(back_choice.empty())
				{
					cout << "Plus de choix possible";
					return false;
				}

				StateExec& e = back_choice.top();
				int pos_choice = e.sr_it + 1;
				rs = table_read[pos_choice];
				e.sr_it++;
				cout << "*" << e.choice_new_id << ' ';

				if(pos_choice == table_read.size()-1) // Dernier choix possible
					back_choice.pop();
			}
			else
			{
				if(table_read.size() == 0)
				{
					cout << "Impasse";
					if(back_choice.empty())
					{
						cout << " w not in Lg";
						return false;
					}
					StateExec& e = back_choice.top();
					pile = e.pile;
					entree = e.entree;
					impasse = true;
				}else if(table_read.size() == 1){
					rs = table_read[0];
				}else{
					cout << "*" << ++choice_new_id << ' ';
					StateExec e(pile, entree, 0, choice_new_id);
					back_choice.push(e);
					rs = table_read[0];
				}
			}

			if(!impasse)
			{
				if(rs < 0) // Reduce
				{
					rs = (-rs);
					vector<int>& rule = reduces[rs-1];

					// Sortie
					cout << 'r' << rs << " : " << g.symboles_name[rule[0]] << "->";
					if(rule.size()==1) cout << "epsi";
					for(int i=1; i<rule.size(); ++i)
						cout << ' ' << g.symboles_name[rule[i]];
					if(rs == 1){
						cout << " w in Lg";
						break;
					}

					// Un reduce fonctionne toujours si le SLR est bien construit ?
					int nb_to_remove = (rule.size()-1)*2;
					if(nb_to_remove >0)
					pile.erase(pile.begin() + (pile.size() - nb_to_remove), pile.end());
					pile.push_back(rule[0]);
					pile.push_back(table[pile[pile.size()-2]][rule[0]][0]);


				}
				else // Shift
				{
					cout <<'s'<< rs;
					int symb_id = entree[entree.size()-1];
					pile.push_back(symb_id);
					pile.push_back(rs);
					entree.resize(entree.size()-1);
				}
			}
			cout << endl;
			afficher_pile_entree(g);

		}
	}
};

/* Sauvegarde d'une grammaire */
void write(Grammar g, string gname)
{
	// Ouverture du fichier en écriture
	gname+=".txt";
	ofstream save(gname, ios::out | ios::trunc);
	if(save)
	{
		for(int i=0; i<g.rules.size(); ++i)
		{
			for(vector<int>& rule: g.rules[i])
			{
				save << g.symboles_name[g.nt_symb_id[i]];
				for(int symb_id : rule)
				{
					save << ' ' << g.symboles_name[symb_id];
				}
				save << endl;
			}
		}
		save.close();
	}
}

/* Chargement d'une grammaire */
Grammar load(string gname)
{
	// Ouverture du fichier
	string file_name = gname + ".txt";
	std::ifstream file(file_name);

	if(!file.is_open())
		throw string("impossible de lire '" + file_name + "'");

	Grammar g;
	string line, symb;
	while(getline(file, line))
	{
		stringstream ss(line);
		ss >> symb;
		auto& rule = g.addRuleTo(g.getID(symb, true));
		while(ss >> symb)
		{
			rule.push_back(g.getID(symb));
		}
	}

	file.close();
	return g;
}

/* Gestion des inputs utilisateur */
namespace input
{
    bool getString(string &i, const string &message)
    {
        while(true){
            cout << message;
            getline(cin, i);
            if(cin.bad() || cin.eof()){
                cerr << "Erreur, saisie incorrecte." << endl;
                if(cin.eof()) break;
            }
            else if(cin.fail())
            	cerr << "Erreur, saisie incorrecte." << endl;
            break;
        }
        return true;
    }

    bool getInt(int &i, const string &message)
    {
        string tmp;
        while(getString(tmp, message)){
            istringstream stream(tmp);
            stream >> i;
            if(stream.fail() || !stream.eof())
            	cerr << "Erreur, saisie incorrecte." << endl;
            else return true;
        } return false;
    }

    void vider_buffer()
    {
        cin.clear();
        cin.seekg(0, ios::end);
        if(!cin.fail())
            cin.ignore(numeric_limits<streamsize>::max());
        else
            cin.clear();
    }

    void pause(string msg = "")
    {
        cout << msg;
        vider_buffer();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }

    void cls(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system ("clear");
    #endif
    }

    string toString(int n){
       std::ostringstream oss;
       oss << n;
       return oss.str();
    };
}

/* Gestion de l'interface utilisateur avec un système de menu basique */
namespace menu
{
	int item_select(int n)
	{
		int i = 0;
		while(i<1 || i>n) input::getInt(i,"\t\t\tSelection : ");
		return i;
	}

	string maker(vector<string> const& item_list)
	{
		string m = string("\tGrammaire et reconnaissance de mots\n")
						+ "\t\tPlease make your selection\n";
		for(int i=0; i<item_list.size(); ++i)
			m +=string("\t\t"+input::toString(i+1)
						+" - "+item_list[i]+'\n');
		return m;
	}
class GrammarMenu
	{
		Grammar& g;
		string menu;
		SLR* slr;

	public:
		GrammarMenu(Grammar& g) : g(g),
			menu(maker({
			"Construire l'analyseur SLR(1)",
			"Reconnaitre un mot",
			"Retour"
		})) {}

		~GrammarMenu()
		{
			delete slr;
		}

		void run()
		{
			bool goback = false;
			while(!goback)
			{
				input::cls();

				cout << endl << "__";
				cout << endl << "  | Grammaire :" << endl;
				cout << g << endl << endl << menu;

				switch (item_select(3))
				{
					// Constuire l'analyseur SLR
					case 1:
						slr = new SLR(g);
						cout << endl;
						input::pause("Entrer pour continuer ...");
						break;

					// Reconnaitre un mot
					case 2:
					{
						if(slr != nullptr)
						{
							input::cls();

							// Affichage
							cout  << endl << g << endl;
							cout << endl << "__";
							cout << endl << "  | Reconnaissance d'un mot :" << endl;

							string mot;
							input::getString(mot, "Veuillez entrer un mot : ");

							cout << endl << "\t__Table d'analyse__" << endl;
							slr->afficher_table();
							cout << endl;
							slr->execute(mot);

							cout << endl;
							input::pause("\nAppuyer sur une touche pour continuer ...");
						}else{
							cout << endl << "\tVeuillez d'abord construire l'analyseur SLR" << endl;
							input::pause("\nAppuyer sur une touche pour continuer ...");
						}
					}break;

					// Retour
					case 3:
						goback = true;
						break;
				}
			}
		}
	};

	class MainMenu
	{
		string menu;

	public:
		MainMenu() : menu(maker({
			"Charger une grammaire",
			"Quitter"
		})) {}

		void run()
		{
			bool goback = false;
			while(!goback)
			{
				input::cls();
				cout << endl << "__";
				cout << endl << "  | Analyseur SLR :" << endl;
				cout << endl << menu;

				switch (item_select(2))
				{
					// Charger une grammaire
					case 1:
					{
						try
						{
							string name;
							cout << endl;
							input::getString(name,
								"\tEntrez le nom de la grammaire a charger : ");
							cout << endl;
							Grammar g = load(name);
							cout << endl;
							GrammarMenu(g).run();
						}
						catch(const string& err)
						{
							cout << endl << "Erreur : " << err << endl;
							input::pause("Entrer pour continuer ...");
						}
					}
					break;

					// Retour
					case 2:
						goback = true;
						break;
				}
			}

		}
	};
}

int main()
{
	// Reglage de la console sous windows
	#ifdef _WIN32
		system("mode con cols=100");
		system("color 3F");
	#endif // _WIN32

	// Lancement du menu principal
    menu::MainMenu().run();

	return 0;
}
