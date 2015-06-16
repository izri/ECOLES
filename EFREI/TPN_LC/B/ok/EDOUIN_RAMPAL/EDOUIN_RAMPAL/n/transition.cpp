#include "transition.h"
#include "etat.h"
#include <string>
#include<vector>
#include "regle.h"
#include "grammaire.h"
#include "automate.h"

using namespace std;


transition::transition() {}
transition::transition(int o, string s, int d): origine(o), symbole(s), destination(d){}

