#include <iostream>
#include <string>

#include "client.hpp"

using namespace std;

Client::Client(const string first_name, const string last_name)
: first_name(first_name), last_name(last_name){}
const string Client::get_first_name() { return first_name; }
const string Client::get_last_name() { return last_name; }
const string Client::to_string() { return first_name + " " + last_name; }
void Client::print() { cout << "Client : " << to_string() << endl; }
