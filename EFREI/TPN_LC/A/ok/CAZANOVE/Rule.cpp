#include "Rule.h"

using namespace std;

Rule::Rule(const string& input, const string& output, int parser_position) : _input(input), _outputs(), _parser_position(parser_position)
{
    _outputs.push_back(output);
}

Rule::Rule(const vector<string>& line, int parser_position) : _input(line[0]), _outputs(line), _parser_position(parser_position)
{
    _outputs.erase(_outputs.begin());
}

Rule::~Rule()
{
}

bool Rule::operator==(const Rule& other) const
{
    return (_input == other._input and _outputs == other._outputs and _parser_position == other._parser_position);
}

bool Rule::operator<(const Rule& other) const
{
    return _input < other._input;
}

ostream& operator<<(ostream& os, const Rule& rule)
{
    os << rule._input << " ->";
    if (rule._outputs.size() == 0 and rule._parser_position >= 0)
        os << " .";
    else
    {
        int i;
        for (i = 0; i < (int) rule._outputs.size(); i++)
        {
            if (rule._parser_position == i)
                os << " .";
            os << " " << rule._outputs[i];
        }
        if (rule._parser_position == i)
            os << " .";
    }
    return os;
}

string Rule::get_input() const
{
    return _input;
}

void Rule::set_parser_position(int value)
{
    if (value < 0)
    {
        _parser_position = -1;
    }
    else
    {
        _parser_position = value;
        if (value > (int) _outputs.size())
        {
            _parser_position = _outputs.size();
        }
        if (_parser_position < 0)
            _parser_position = 0;
    }
}

unsigned int Rule::get_parser_position() const
{
    return _parser_position;
}

string Rule::get_next_symbol() const
{
    if (_parser_position >= 0 and _outputs.size() > 0 and _parser_position < (int)_outputs.size())
    {
        return _outputs[_parser_position];
    }
    return string();
}

vector<string> Rule::get_outputs() const
{
    return _outputs;
}

bool Rule::has_epsilon() const
{
    return _outputs.empty();
}
