#ifndef GRAMMAR_H_INCLUDED
#define GRAMMAR_H_INCLUDED

#include <iostream>
#include <vector>
#include <set>

#include "Rule.h"

using namespace std;

class Grammar
{
    public:
        static Grammar load(const string &path);

        Grammar();
        ~Grammar();
        Grammar(const Grammar&);

        friend ostream& operator<<(ostream& os, const Grammar& grammar);

        std::vector<Rule> get_rules() const;
        std::string get_axiom() const;
        void set_axiom(const std::string&);
        std::vector<Rule> get_rules_for(const std::string& input) const;
        std::vector<Rule> get_rules_with(const std::string& output) const;

        std::set<std::string> get_language() const;

        virtual void add_rule(const Rule& rule, bool front = false);
        bool has_epsilon(const std::string &symb) const;
        bool is_terminal(const std::string& symb) const;
        bool is_in_language(const std::string& symb) const;

    protected:
        static int _rule_counter;
        std::vector<Rule> _rules;
        std::string _axiom;
        std::set<std::string> _non_terminals, _terminals;
};

#endif // GRAMMAR_H_INCLUDED
