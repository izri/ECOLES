#include "Carte.hpp"

using namespace std;


Carte::Carte(Command command, int PtFidelite) : command(command), PtFidelite(PtFidelite {}
const Command Carte::get_PtFidelite() { return PtFidelite++; }
const string Historique::to_string() { return command.to_string(); }
void print() {
			cout <<"Nombre de point : " << PtFidelite.to_string();
}
