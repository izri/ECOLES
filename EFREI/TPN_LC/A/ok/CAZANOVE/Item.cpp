#include "Item.h"

int Item::_counter = 0;

Item::Item(const Grammar& source_grammar) : _number(_counter++), _grammar(), _transitions(), _last_read_symb(), _parent(nullptr), _parsed(false)
{
    /* Si on est à l'item 0 */
    if (_number == 0)
    {
        /* On évite le cas de figure où il existe déjà un symbole nommé "Axiome Prime" */
        string symb = source_grammar.get_axiom() + "'";
        while (source_grammar.is_in_language(symb))
            symb += "'";
        /* On ajoute la nouvelle règle avec un parser en position 0 */
        _grammar.add_rule(Rule(symb, source_grammar.get_axiom(), 0), true); // true pour insérer au début du vector
        _grammar.set_axiom(symb);
        vector<Rule> rules = source_grammar.get_rules();
        /* On ajoute toutes les anciennes règles avec un parser en position 0 */
        for (unsigned int i = 0; i < rules.size(); i++)
        {
            Rule rule = rules[i];
            rule.set_parser_position(0);
            _grammar.add_rule(rule);
        }
    }
}

Item::Item(const Item& parent_item, string last_read_symb) : _number(_counter++), _grammar(), _transitions(), _last_read_symb(last_read_symb),
                                                            _parent(&parent_item), _parsed(false)
{
    // _counter est forcément supérieur à 0 car on a déjà créé au moins un Item (celui passé en référence)
    vector<Rule> parent_rules = parent_item._grammar.get_rules();
    // Pour chaque règle du parent
    for (unsigned int i = 0; i < parent_rules.size(); i++)
    {
        unsigned int pos = parent_rules[i].get_parser_position();
        vector<string> outputs = parent_rules[i].get_outputs();
        if (outputs.size() != 0)
        {
            // On ajoute les règles qui concernent le dernier symbole lu
            if (pos < outputs.size() and outputs[pos] == last_read_symb)
            {
                Rule rule = parent_rules[i];
                rule.set_parser_position(rule.get_parser_position()+1);
                _grammar.add_rule(rule);
                /* was here */
            }
        }
    }
    vector<Rule> rules = _grammar.get_rules();
    Grammar item0_grammar = get_source_grammar();
    // Pour chaque règle du nouvel item
    for (vector<Rule>::iterator it_rule = rules.begin(); it_rule != rules.end(); it_rule++)
    {
        // On récupère la liste des règles de item0 pour le symbole après le parser
        vector<Rule> rules_for_symb = item0_grammar.get_rules_for(it_rule->get_next_symbol());
        // Pour chaque règle
        for (vector<Rule>::iterator it = rules_for_symb.begin(); it != rules_for_symb.end(); it++)
        {
            _grammar.add_rule(*it);
            string symb = it->get_next_symbol();
            if (!symb.empty())
            {
                vector<Rule> rules_for_symb2 = item0_grammar.get_rules_for(it->get_next_symbol());
                for (vector<Rule>::iterator it2 = rules_for_symb2.begin(); it2 != rules_for_symb2.end(); it2++)
                {
                    _grammar.add_rule(*it2);
                }
            }
        }
    }
}

Item::Item(const Item& other) : _number(other._number), _grammar(other._grammar), _transitions(other._transitions),
                                _last_read_symb(other._last_read_symb), _parent(other._parent), _parsed(other._parsed)
{
}

Item::~Item()
{
    _counter--;
}

Item& Item::operator=(const Item& other)
{
    *this = Item(other);
    return *this;
}

ostream& operator<<(ostream& os, const Item& item)
{
    os << "Item " << item._number;
    if (item._number != 0)
    {
        os << ": from Item " << item._parent->_number << " by " << item._last_read_symb;
    }
    os << endl;
    vector<Rule> rules = item._grammar.get_rules();
    for (vector<Rule>::iterator it = rules.begin(); it != rules.end(); it++)
    {
        os << *it << endl;
    }
    return os;
}

bool Item::is_parsed() const
{
    return _parsed;
}

void Item::check_parsing()
{
    bool fully_parsed = true;
    vector<Rule> rules = _grammar.get_rules();
    for (vector<Rule>::iterator it = rules.begin(); it != rules.end(); it++)
    {
        if (!it->get_next_symbol().empty())
        {
            fully_parsed = false;
            break;
        }
    }
    _parsed = fully_parsed;
}

vector<Rule> Item::get_rules() const
{
    return _grammar.get_rules();
}

void Item::set_transition(const string symbol, Item* const item)
{
    _transitions[symbol] = item;
}

Item* Item::get_transition(const string key) const
{
    if (_transitions.find(key) != _transitions.end())
        return _transitions.at(key);
    return nullptr;
}

Grammar Item::get_source_grammar() const
{
    const Item * parent = _parent;
    while (parent->_parent != nullptr)
        parent = parent->_parent;
    return parent->_grammar;
}
