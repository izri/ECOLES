#include "Historique.hpp"

using namespace std;


Historique::Historique(Command command) : command(command) {}
const Command Historique::get_command() { return command; }
const string Historique::to_string() { return command.to_string(); }
void print() {
			cout <<"Historique : " << command.to_string();
}



