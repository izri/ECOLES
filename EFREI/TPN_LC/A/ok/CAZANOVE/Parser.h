#ifndef PARSER_H
#define PARSER_H

#include <set>

#include "Rule.h"
#include "Grammar.h"
#include "Item.h"

struct ItemRule
{
    Rule rule;
    Item *item;
};

class Parser
{
    public:
        Parser();
        virtual ~Parser();

        void load_grammar(const std::string&);
        void make_items();
        Item* has_rule(const Rule&) const;

        std::set<std::string> firsts_of(const std::string&) const;
        void make_firsts();

        std::set<std::string> follows_of(const std::string&) const;
        void make_follows();

        void analysis_table();

    private:
        Grammar _grammar;
        std::vector<Item*> _items;
        std::vector<ItemRule> _rules;
        std::map<std::string, std::set<std::string>> _firsts;
        std::map<std::string, std::set<std::string>> _follows;
        std::map<Item*, std::map<std::string, Item*>> _analysis_table;
};

#endif // PARSER_H
