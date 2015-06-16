#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <vector>

class Rule
{
    std::string _input;
    std::vector<std::string> _outputs;

    public:

        Rule(const std::string& input, const std::string& output, int parser_position = -1);
        Rule(const std::vector<std::string>& line, int parser_position = -1);
        virtual ~Rule();

        bool operator==(const Rule&) const;
        bool operator<(const Rule&) const;

        friend std::ostream& operator<<(std::ostream& os, const Rule& rule);

        void set_parser_position(int value);
        unsigned int get_parser_position() const;
        std::string get_next_symbol() const;

        std::string get_input() const;
        std::vector<std::string> get_outputs() const;
        int get_number() const;
        bool has_epsilon() const;
        int _parser_position;
};

#endif // RULE_H
