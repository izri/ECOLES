#include "Parser.h"

#include <windows.h>
#include <algorithm>

using namespace std;

Parser::Parser() : _grammar(), _items(), _rules(), _firsts(), _follows(), _analysis_table()
{
}

Parser::~Parser()
{
    for (vector<Item*>::iterator it = _items.begin(); it != _items.end(); it++)
        delete *it;
}

void Parser::load_grammar(const string& path)
{
    _grammar = Grammar::load(path);
    cout << _grammar << endl;
}

void Parser::make_items()
{
    Item *item = new Item(_grammar); // Item 0
    cout << *item << endl;
    _items.push_back(item);
    unsigned int i = 0;
    do // Pour chaque item
    {
        // On récupère les règles de cet item
        vector<Rule> rules = item->get_rules();
        // Pour chaque règle de l'item courant
        for (vector<Rule>::iterator it = rules.begin(); it != rules.end(); it++)
        {
            Item *new_item = nullptr;
            if (!it->get_next_symbol().empty())
            {
                if (item->get_transition(it->get_next_symbol()) == nullptr)
                {
                    // On crée un nouvel Item à partir de l'item courant et du symbole après le parser
                    new_item = new Item(*item, it->get_next_symbol());
                    vector<Rule> new_item_rules = new_item->get_rules(); // Règles du nouvel Item
                    Item *existing_item = has_rule(new_item_rules.front());
                    if (existing_item != nullptr) // Si la première règle de l'item existe déjà
                    {
                        // On associe l'item courant à l'item existant par la transition "symbole lu"
                        item->set_transition(it->get_next_symbol(), existing_item);
                        cout << "Item " << item->number() << " to Item " << existing_item->number() << " by " << it->get_next_symbol() << endl << endl;
                        delete new_item;
                    }
                    else // Item valide
                    {
                        cout << *new_item << endl;
                        // On référence chacun des règles du nouvel Item
                        for (vector<Rule>::iterator it_rule = new_item_rules.begin(); it_rule != new_item_rules.end(); it_rule++)
                        {
                            ItemRule item_rule = {*it_rule, new_item};
                            _rules.push_back(item_rule);
                        }
                        // On associe l'item courant au nouveau par la transition "symbole lu"
                        item->set_transition(it->get_next_symbol(), new_item);
                        _items.push_back(new_item);
                    }
                }
            }
        }
        i++;
        if (i < _items.size())
        {
            item = _items[i];
        }
    }while (i < _items.size());
}

Item* Parser::has_rule(const Rule& rule) const
{
    vector<ItemRule>::const_iterator it;
    for (it = _rules.begin(); it != _rules.end(); it++)
    {
        if (it->rule == rule)
            return it->item;
    }
    return nullptr;
}

set<string> Parser::firsts_of(const string& symbol) const
{
    set<string> firsts;
    // Il est nécessaire que l'item0 soient fait
    Grammar grammar;
    vector<Rule> rules_implied;
    if (_items.empty())
        grammar = Item(_grammar).grammar();
    else
        grammar = _items.front()->grammar();
    rules_implied = grammar.get_rules_for(symbol);
    // Pour chaque règle concernant le symbole
    for (auto it_rule = rules_implied.begin(); it_rule !=  rules_implied.end(); it_rule++)
    {
        // Si la règle possède un output epsilone, on l'ajoute aux firsts
        if (it_rule->get_input() == symbol and _grammar.has_epsilon(it_rule->get_input()))
        {
            string symb("epsilone");
            firsts.insert(symb);
        }
        // On récupère la liste des "outputs" de la règle
        vector<string> outputs = it_rule->get_outputs();
        unsigned int i = 0;
        // S'il ne s'agit pas d'epsilone
        while (outputs.size() > i)
        {
            // Si le first est terminal
            if (_grammar.is_terminal(outputs[i]))
            {
                firsts.insert(outputs[i]);
                break;
            }
            else // Si le first est non-terminal
            {
                // S'il ne s'agit pas du même symbole (i.e. P(S) = P(S))
                if (outputs[i] != symbol)
                {
                    auto output_firsts = firsts_of(outputs[i]);
                    firsts.insert(output_firsts.begin(), output_firsts.end());
                    // Si ce symbole peut devenir epsilone, on regarde le symbole suivant
                    if (grammar.has_epsilon(outputs[i]))
                        i++;
                    else // Sinon on s'arrête
                        break;
                }
                else
                    break;
            }
        }
    }
    return firsts;
}

void Parser::make_firsts()
{
    set<string> language;
    Grammar grammar;
    // On se base sur la grammaire de Item 0
    if (_items.empty())
        grammar = Item(_grammar).grammar();
    else
        grammar = _items.front()->grammar();
    language = grammar.get_language();
    for (auto it = language.begin(); it != language.end(); it++)
    {
        if (!grammar.is_terminal(*it))
        {
            set<string> firsts = firsts_of(*it);
            _firsts[*it] = firsts;
            cout << "Firsts of " << *it << " = { ";
            for (auto it_first = firsts.begin(); it_first != firsts.end(); it_first++)
            {
                cout << *it_first << " ";
            }
            cout << " }" << endl;
        }
    }
    cout << endl;
}

set<string> Parser::follows_of(const string& symbol) const
{
    set<string> follows;
    // Il est nécessaire que l'item0 soient fait
    Grammar grammar;
    vector<Rule> rules_implied;
    if (_items.empty())
        grammar = Item(_grammar).grammar();
    else
        grammar = _items.front()->grammar();
    // S'il s'agit de l'axiome S'
    if (symbol == grammar.get_axiom())
    {
        string ss("$tart$ymbol");
        follows.insert(ss);
        return follows;
    }
    rules_implied = grammar.get_rules_with(symbol);
    // Pour chaque règle impliquant le symbole en "output"
    for (auto it_rule = rules_implied.begin(); it_rule !=  rules_implied.end(); it_rule++)
    {
        bool start_symbol = false;
        // On récupère la liste des "outputs" de la règle
        vector<string> outputs = it_rule->get_outputs();
        for (unsigned int i = 0; i < outputs.size(); i++)
        {
            // S'il s'agit du symbole analysé
            if (outputs[i] == symbol)
            {
                // Si on est pas au dernier élément
                if (i+1 < outputs.size())
                {
                    unsigned int epsilones = 0;
                    while (i+1+epsilones < outputs.size())
                    {
                        // Si le follow est terminal
                        if (grammar.is_terminal(outputs[i+1+epsilones]))
                        {
                            follows.insert(outputs[i+1+epsilones]);
                            break;
                        }
                        else // Si le follow n'est pas terminal
                        {
                            // S'il ne s'agit pas du même symbole
                            if (outputs[i+1+epsilones] != symbol)
                            {
                                // On récupère les firsts de ce follow
                                set<string> follow_firsts = firsts_of(outputs[i+1+epsilones]);
                                follows.insert(follow_firsts.begin(), follow_firsts.end());
                                // Si le follow peut devenir epsilone
                                if (grammar.has_epsilon(outputs[i+1+epsilones]))
                                {
                                    epsilones++; // On doit regarder le symbole suivant
                                }
                                else
                                    break;
                            }
                            else
                                break;
                        }
                    }
                }
                else // Si on est dernier élément
                {
                    set<string> input_follows = follows_of(it_rule->get_input());
                    follows.insert(input_follows.begin(), input_follows.end());
                    start_symbol = true;
                    break;
                }
            }
        }
        if (start_symbol)
            break;
    }
    return follows;
}

void Parser::make_follows()
{
    set<string> language;
    Grammar grammar;
    // On se base sur la grammaire de l'Item 0
    if (_items.empty())
        grammar = Item(_grammar).grammar();
    else
        grammar = _items.front()->grammar();
    language = grammar.get_language();
    for (auto it = language.begin(); it != language.end(); it++)
    {
        if (!grammar.is_terminal(*it))
        {
            set<string> follows = follows_of(*it);
            _follows[*it] = follows;
            cout << "Follows of " << *it << " = { ";
            for (auto it_follow = follows.begin(); it_follow != follows.end(); it_follow++)
            {
                cout << *it_follow << " ";
            }
            cout << " }" << endl;
        }
    }
    cout << endl;
}

void Parser::analysis_table()
{
    cout << "Table d'analyse sans les \"reduces\"" << endl;
    if (_items.empty())
        make_items();
    for (auto it = _items.begin(); it != _items.end(); it++)
    {
        Item *src = *it;
        cout << "Item " << src->number();
        set<string> language = (*it)->grammar().get_language();
        for (auto it2 = language.begin(); it2 != language.end(); it2++)
        {
            Item *dst = (*it)->get_transition(*it2);
            if (dst == nullptr)
            {
                _analysis_table[src][*it2] = nullptr;
                cout << " " << *it2 << " impossible";
            }
            else
            {
                _analysis_table[src][*it2] = dst;
                cout << " " << *it2 << " " << dst->number();
            }
        }
        cout << endl;
    }
}
