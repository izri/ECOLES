#include <iostream>

#include "Parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    Parser parser;
    string path;
    cout << "File name: ";
    cin >> path;

    parser.load_grammar(path);

    parser.make_items();

    parser.make_firsts();

    parser.make_follows();

    parser.analysis_table();
}
