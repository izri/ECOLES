#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <map>

#include "Grammar.h"

class Item
{
    public:
        Item(const Grammar&);
        Item(const Item&, std::string last_read_symb);
        Item(const Item&);
        virtual ~Item();
        Item& operator=(const Item&);

        friend ostream& operator<<(ostream& os, const Item&);

        bool is_parsed() const;
        void check_parsing();

        std::vector<Rule> get_rules() const;
        void set_transition(const std::string, Item* const);
        Item* get_transition(const std::string) const;
        Grammar get_source_grammar() const;

        int number() const { return _number; }
        const Grammar& grammar() { return _grammar; }

    protected:
        static int _counter;
        int _number;
        Grammar _grammar;
        std::map<std::string, Item*>  _transitions;
        std::string _last_read_symb;
        const Item* _parent;
        bool _parsed;

};

#endif // ITEM_H
