#include "PlatJour.h"

#include <string>

using namespace std;

PlatJour::PlatJour() : m_repas("")
{

}

bool PlatJour::temperature()
{
    string un;
    cout << "Voulez vous votre plat du jour froid ou chaud ? " << " Tapez " << " un -> froid " << " ou zero -> chaud " << endl;
    cin >> m_repas;
    if(m_repas == un)
    {

        cout << "Froid devant ! Voici votre excellent plat ! " << endl;
        return true;
    }else{
        cout << "Chaud devant ! Voici votre succulent plat ! " << endl;
        return false;
    }

}

