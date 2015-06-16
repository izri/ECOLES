#include "Grammar.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

int Grammar::_rule_counter = 1;

Grammar Grammar::load(const string &path)
{
    Grammar grammar;
    string line;
    ifstream file(path);

    if (file.is_open())
    {
        while( getline(file, line))
        {
            istringstream iss(line);
            vector<string> words;
            copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
            grammar.add_rule(Rule(words));
        }
        file.close();
    }
    else
    {
        cout << "Failed to load " << path << endl;
        exit(EXIT_FAILURE);
    }
    return grammar;
}

Grammar::Grammar() : _rules(), _axiom(), _non_terminals(), _terminals()
{
}

Grammar::Grammar(const Grammar& other) : _rules(other._rules), _axiom(other._axiom), _non_terminals(other._non_terminals), _terminals(other._terminals)
{
}

Grammar::~Grammar()
{
}

ostream& operator<<(ostream& os, const Grammar& grammar)
{
    for (vector<Rule>::const_iterator it = grammar._rules.begin(); it != grammar._rules.end(); it++)
    {
        os << *it << endl;
    }
    /*cout << "Non-terminaux: ";
    for (set<string>::const_iterator it = grammar._non_terminals.begin(); it != grammar._non_terminals.end(); it++)
        cout << *it << " ";
    cout << "\nTerminaux: ";
    for (set<string>::const_iterator it = grammar._terminals.begin(); it != grammar._terminals.end(); it++)
        cout << *it << " ";*/
    return os;
}

vector<Rule> Grammar::get_rules() const
{
    return _rules;
}

string Grammar::get_axiom() const
{
    return _axiom;
}

void Grammar::set_axiom(const string& symb)
{
    _axiom = symb;
}

vector<Rule> Grammar::get_rules_for(const string& input) const
{
    vector<Rule> rules;
    if (!input.empty() and !is_terminal(input))
    {
        for (vector<Rule>::const_iterator it = _rules.begin(); it != _rules.end(); it++)
        {
            if (it->get_input() == input)
                rules.push_back(*it);
        }
    }
    return rules;
}

vector<Rule> Grammar::get_rules_with(const string& output) const
{
    vector<Rule> rules_with;
    for (vector<Rule>::const_iterator it = _rules.begin(); it != _rules.end(); it++)
    {
        vector<string> outputs = it->get_outputs();
        if (find(outputs.begin(), outputs.end(), output) != outputs.end())
        {
            rules_with.push_back(*it);
        }
    }
    return rules_with;
}

set<string> Grammar::get_language() const
{
    set<string> language = _non_terminals;
    language.insert(_terminals.begin(), _terminals.end());
    return language;
}

void Grammar::add_rule(const Rule& rule, bool front)
{
    /* Si la règle existe déjà, on ne l'ajoute pas */
    if (std::find(_rules.begin(), _rules.end(), rule) != _rules.end())
        return;
    /* S'il n'y a pas de règles, la 1ère règle devient l'axiome */
    if (_rules.empty())
        _axiom = rule.get_input();
    /* Si on veut ajouter la règle en tête du vector */
    if (front)
        _rules.insert(_rules.begin(), rule);
    else
        _rules.push_back(rule);
    /* Mise à jour des terminaux / non-terminaux */
    _non_terminals.insert(rule.get_input());
    set<string>::iterator to_delete = std::find(_terminals.begin(), _terminals.end(), rule.get_input());
    if (to_delete != _terminals.end())
        _terminals.erase(to_delete);
    vector<string> v = rule.get_outputs();
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        if (is_terminal(*it))
        {
            _terminals.insert(*it);
        }
    }
}

bool Grammar::has_epsilon(const string& symb) const
{
    for (vector<Rule>::const_iterator it = _rules.begin(); it != _rules.end(); it++)
    {
        if (it->get_input() == symb and it->has_epsilon())
        {
            return true;
        }
    }
    return false;
}

bool Grammar::is_terminal(const string& symb) const
{
    set<string>::const_iterator it = std::find(_non_terminals.begin(), _non_terminals.end(), symb);
    if (it == _non_terminals.end())
        return true;
    return false;
}

bool Grammar::is_in_language(const string& symb) const
{
    set<string>::const_iterator it = std::find(_non_terminals.begin(), _non_terminals.end(), symb);
    if (it != _non_terminals.end())
        return true;
    it = std::find(_terminals.begin(), _terminals.end(), symb);
    if (it != _terminals.end())
        return true;
    return false;
}
