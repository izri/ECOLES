#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FirstFollow{
private:
    string NT;
    vector<string> First;
    vector<string> Follow;
    
public:
    vector<string> getFirst(){return this->First;}
    vector<string> getFollow(){return this->Follow;}
    string getNT(){return this->NT;}
    
    FirstFollow(string s){this->NT = s;}
    
    bool setFirst(string s){
        int cpt = 0;
        while(cpt < First.size()){
            if(First[cpt] == s) return false;
            else cpt++;
        }
        
        this->First.push_back(s);
        return true;
    }
    
    bool setFollow(string s){
        int cpt = 0;
        while(cpt < Follow.size()){
            if(Follow[cpt] == s) return false;
            else cpt++;
        }
        this->Follow.push_back(s);
        return true;
    }
    
    bool copyFirst(FirstFollow f){
        bool element_add = false;
        for(int cpt = 0; cpt < f.getFirst().size(); cpt++){
            int cpt1 = 0;
            bool trouve = false;
            while(cpt1 < this->First.size() && trouve == false){
                if(this->First[cpt1] == f.getFirst()[cpt]) trouve = true;
                else cpt1++;
            }
            if(trouve == false){
                this->First.push_back(f.getFirst()[cpt]);
                element_add = true;
            }
        }
        return element_add;
    }
    bool detient_mot_vide(){
        int cpt = 0;
        while(cpt < First.size()){
            if(First[cpt] == "") return true;
            cpt++;
        }
        return false;
    }
    void setNT(string s){this->NT = s;}
};

class Regle{
    
private:
    string NT;
    string deriv;
    
public:
    Regle(const string p_NT, const string p_deriv){ this->NT = p_NT; this->deriv = p_deriv; }
    Regle(const Regle& e){ this->NT = e.NT; this->deriv = e.deriv; }
    
    string getNT(){return this->NT;}
    string getDeriv(){ return this->deriv;}
    
    void setNT(const string p_NT){ this->NT = p_NT; }
    void setDeriv(const string p_deriv){ this->deriv = p_deriv; }
    
    string toString(){ return "Etat : " + (this->NT) + " -> " + (this->deriv);}
};
class Grammaire{
    
private:
    vector<Regle> mesRegles;
    vector<string> mesNT;
    vector<string> mesT;
    vector<FirstFollow> FF;
    
    
public:
    Grammaire(string);
    
    vector<Regle> getMesRegles(){ return this->mesRegles; }
    vector<string> getMesNonTerminaux(){ return this->mesNT; }
    vector<string> getMesTerminaux(){ return this->mesT; }
    bool est_non_term(string);
    int ind_NT_FF(string);
    
    void CalculFirstFollow();
    void eliminer();
    void transformer();
    void factoriser();
    void afficher();
    void afficher_first();
    void afficher_NT();
    void afficher_T();
};

int Grammaire::ind_NT_FF(string nt){
    int cpt = 0;
    do{
        if(FF[cpt].getNT() == nt) return cpt;
        else cpt++;
    }while(cpt < FF.size());
    return cpt;
}

void Grammaire::afficher(){
    for(long cpt = 0; cpt < mesRegles.size(); cpt++){
        cout << mesRegles[cpt].getNT() << "-->" << mesRegles[cpt].getDeriv() << endl;
    }
    cout << endl << endl;
}

void Grammaire::afficher_NT(){
    cout << endl << "Ensemble des etats non-terminaux  = { ";
    for(int cpt = 0; cpt < mesNT.size(); cpt++){
        cout << mesNT[cpt] << " ";
    }
    cout << "}" << endl;
}
void Grammaire::afficher_T(){
    cout << endl << "Ensemble des etats terminaux  = { ";
    for(int cpt = 0; cpt < mesT.size(); cpt++){
        if(mesT[cpt] == "") cout << "MotVide ";
        else cout << mesT[cpt] << " ";
    }
    cout << "}" << endl;
}

Grammaire::Grammaire(string f){
    ifstream fichier(f.c_str() , ios::in) ;
    string NT="";
    string deriv="";
    
    if ( fichier ) // ce test Èchoue si le fichier n'est pas ouvert
    {
        stringstream ss;
        string ligne;
        
        while (getline (fichier, ligne)) {
            bool rajout_NT = true;
            int cpt = 0;
            
            ss.clear ();
            ss.str("");
            ss << ligne;
            
            NT = "";
            deriv = "";
            ss >> NT;
            ss >> deriv;
            
            Regle r(NT,deriv);
            
            mesRegles.push_back(r);
            
            while (cpt < mesNT.size() && rajout_NT == true){
                if(mesNT[cpt] == NT){
                    rajout_NT = false;
                }
                cpt++;
            }
            if(rajout_NT == true) mesNT.push_back(NT);
        }
        
        bool mot_vide_trouve = false;
        vector<string> find_T;
        
        for(long cpt = 0; cpt < mesRegles.size(); cpt++){
            
            if(mesRegles[cpt].getDeriv().size() == 0 && mot_vide_trouve == false){
                mesT.push_back("");
                mot_vide_trouve = true;
            }
            else{
                find_T.push_back(mesRegles[cpt].getDeriv());
            }
        }
        for(int cpt_NT = 0; cpt_NT < mesNT.size(); cpt_NT++){
            int cpt_find = 0;
            int position;
            
            do{
                position = find_T[cpt_find].find(mesNT[cpt_NT]);
                if(position != string::npos){
                    if(position+mesNT[cpt_NT].size() != find_T[cpt_find].size())find_T.insert(find_T.begin() + cpt_find + 1, find_T[cpt_find].substr(position+mesNT[cpt_NT].size()));
                    
                    if(position == 0)find_T.erase(find_T.begin() + cpt_find);
                    else find_T[cpt_find] = find_T[cpt_find].substr(0, position);
                }
                else cpt_find++;
                
            }while(cpt_find < find_T.size());
            
        }
        
        for(int cpt = 0; cpt < find_T.size(); cpt++){
            int cpt2 = 0;
            bool rajout_T = true;
            
            while(find_T[cpt].size() > 1){
                find_T.insert(find_T.begin() + cpt + 1, find_T[cpt].substr(1));
                find_T[cpt] = find_T[cpt].substr(0,1);
            }
            
            while (cpt2 < mesT.size() && rajout_T == true){
                if(mesT[cpt2] == find_T[cpt]){
                    rajout_T = false;
                }
                cpt2++;
            }
            if(rajout_T == true){
                mesT.push_back(find_T[cpt]);
            }
        }
        
        
        for(int cpt = 0; cpt < mesNT.size(); cpt++){
            FirstFollow f(mesNT[cpt]);
            FF.push_back(f);
        }
        
    }
    else cout << "Lecture du fichier impossible";
}

void Grammaire::transformer()
{
    int position;
    string tempString;
    
    for(int i = 0; i < mesRegles.size(); i++)
    {
        position = mesRegles.at(i).getDeriv().find('+');
        
        if(position != string::npos)
        {
            if(mesRegles.at(i).getDeriv().compare(mesRegles.at(i).getNT() + "+" + mesRegles.at(i).getNT()))
            {
                mesRegles.insert(mesRegles.begin() + i + 1, Regle(mesRegles.at(i).getNT(),mesRegles.at(i).getNT() + "+" + "T"));
                mesRegles.insert(mesRegles.begin() + i + 1, Regle(mesRegles.at(i).getNT(),"T"));
                mesNT.push_back("T");
                mesRegles.erase(mesRegles.begin() + i);
                
                for(int j = 0; j < mesRegles.size(); j++)
                {
                    
                    position = mesRegles.at(j).getDeriv().find('*');
                    if(position != string::npos)
                    {
                        if(mesRegles.at(j).getDeriv().compare(mesRegles.at(j).getNT() + "*" + mesRegles.at(j).getNT()))
                        {
                            mesRegles.insert(mesRegles.begin() + j + 1, Regle(mesRegles.at(j).getNT(),mesRegles.at(j).getNT() + "*" + "F"));
                            mesRegles.insert(mesRegles.begin() + j + 1, Regle(mesRegles.at(j).getNT(),"F"));
                            mesNT.push_back("F");
                            mesRegles.erase(mesRegles.begin() + j);
                            
                            return;
                        }
                    }
                }
            }
        }
    }
    
    
    for(int i = 0; i < mesRegles.size(); i++){
        
        position = mesRegles.at(i).getDeriv().find('*');
        
        if(position != string::npos)
        {
            if(mesRegles.at(i).getDeriv().compare(mesRegles.at(i).getNT() + "+" + mesRegles.at(i).getNT())){
                mesRegles.insert(mesRegles.begin() + i + 1, Regle(mesRegles.at(i).getNT(),mesRegles.at(i).getNT() + "+" + "F"));
                mesRegles.insert(mesRegles.begin() + i + 1, Regle(mesRegles.at(i).getNT(),"F"));
                mesNT.push_back("F");
                mesRegles.erase(mesRegles.begin() + i);
            }
        }
    }
    
}


void Grammaire::eliminer(){
    string NT;
    vector<string> deriv;
    vector<Regle> mesNewRegles;
    
    for(int cpt = 0; cpt < mesRegles.size(); cpt++){
        
        NT = mesRegles[cpt].getNT();
        
        deriv.push_back(mesRegles[cpt].getDeriv());
        cpt++;
        while(cpt < mesRegles.size() && mesRegles[cpt].getNT() == NT){
            deriv.push_back(mesRegles[cpt].getDeriv());
            cpt++;
        }
        
        
        vector<int> indices_PasRecur;
        vector<int> indices_Recur;
        
        for(int cpt1 = 0; cpt1 < deriv.size(); cpt1++){
            int pos = deriv[cpt1].find(NT);
            if(pos == 0) indices_Recur.push_back(cpt1);
            else indices_PasRecur.push_back(cpt1);
        }
        
        if(indices_Recur.size() != 0){
            string new_NT = NT+"'";
            for(int cpt1 = 0; cpt1 < indices_PasRecur.size();cpt1++){
                Regle r(NT, deriv[indices_PasRecur[cpt1]] + new_NT);
                mesNewRegles.push_back(r);
            }
            
            for(int cpt1 = 0; cpt1 < indices_Recur.size();cpt1++){
                Regle r(new_NT, deriv[indices_Recur[cpt1]].erase(0,NT.size()) + new_NT);
                mesNewRegles.push_back(r);
            }
            Regle r(new_NT, "");
            mesNewRegles.push_back(r);
        }
        else{
            for(int cpt1 = 0; cpt1 < indices_PasRecur.size();cpt1++){
                Regle r(NT, deriv[indices_PasRecur[cpt1]]);
                mesNewRegles.push_back(r);
            }
        }
        
        deriv.clear();
        
        cpt--;
    }
    mesRegles = mesNewRegles;
}

void Grammaire::factoriser(){
    for(int cpt1 = 0; cpt1 < mesRegles.size(); cpt1++){
        
        string NT = mesRegles[cpt1].getNT();
        int cpt_debut = cpt1;
        
        cpt1++;
        while(cpt1 < mesRegles.size() && mesRegles[cpt1].getNT() == NT){
            cpt1++;
        }
        
        int cpt_fin = cpt1;
        
        vector<int> indices;
        
        for(int cpt = 0; cpt < mesT.size(); cpt++){
            for(int cpt3 = cpt_debut; cpt3 < cpt_fin; cpt3++){
                if(mesRegles[cpt3].getDeriv().find(mesT[cpt]) == 0){
                    indices.push_back(cpt3);
                }
            }
            if(indices.size() >= 2){
                Regle r(NT,mesT[cpt]+"X");
                mesRegles.insert(mesRegles.begin()+cpt_debut, r);
                for(int cpt4 = 0; cpt4 < indices.size(); cpt4++){
                    Regle new_r("X", mesRegles[indices[cpt4]+1].getDeriv().substr(mesT[cpt].size()));
                    mesRegles[indices[cpt4]+1] = new_r;
                }
                mesNT.push_back("X");
                cpt1++;
            }
            indices.clear();
        }
        
        cpt1--;
    }
}

void Grammaire::afficher_first(){
    for(int cpt2 = 0; cpt2 < FF.size(); cpt2++){
        cout << "P(" << FF[cpt2].getNT() << ") = { ";
        for(int cpt = 0; cpt < FF[cpt2].getFirst().size(); cpt++){
            if(FF[cpt2].getFirst()[cpt] == "") cout << "MotVide ";
            else cout <<  FF[cpt2].getFirst()[cpt] << " ";
        }
        cout << "}" << endl;
    }
}


void Grammaire::CalculFirstFollow(){
    for(int cpt = 0; cpt < mesT.size(); cpt++){
        for(int cpt1 = 0; cpt1 < mesRegles.size(); cpt1++){
            if(mesRegles[cpt1].getDeriv().find(mesT[cpt]) == 0 && (mesT[cpt] != "" || mesRegles[cpt1].getDeriv().size() == 0)){
                int indice_nt_ff = this->ind_NT_FF(mesRegles[cpt1].getNT());
                FF[indice_nt_ff].setFirst(mesT[cpt]);
            }
        }
    }
    
    bool modif = true;
    while(modif == true){
    modif = false;
    for(int cpt = 0; cpt < mesNT.size(); cpt++){
        
            for(int cpt1 = 0; cpt1 < mesRegles.size(); cpt1++){
                if(mesRegles[cpt1].getDeriv().find(mesNT[cpt]) == 0){
                    int indice_nt_first = this->ind_NT_FF(mesNT[cpt]);
                    int indice_nt_ff = this->ind_NT_FF(mesRegles[cpt1].getNT());
                    if(mesRegles[cpt1].getNT() != mesNT[cpt]){
                        
                        modif = modif + FF[indice_nt_ff].copyFirst(FF[indice_nt_first]);
                    }
                    if(FF[indice_nt_first].detient_mot_vide()){
                        
                        int position_next_mot = mesNT[cpt1].size();
                        bool doit_aller_apres = true;
                        string new_deriv = mesRegles[cpt1].getDeriv().substr(position_next_mot);
                        position_next_mot = 0;
                        
                        while(doit_aller_apres == true){
                            new_deriv = new_deriv.substr(position_next_mot);
                            position_next_mot = 0;
                            doit_aller_apres = false;
                            bool fin = false;
                            int cpt2 = 0;
                            while(cpt2 < mesT.size() && doit_aller_apres == false){
                                if(new_deriv.find(mesT[cpt2]) == position_next_mot && mesT[cpt2] != ""){
                                    modif = modif + FF[indice_nt_ff].setFirst(mesT[cpt2]);
                                    position_next_mot += mesT[cpt2].size();
                                    fin = true;
                                }
                                cpt2++;
                            }
                            
                            cpt2 = 0;
                            while(cpt2 < mesNT.size() && fin == false && doit_aller_apres == false){
                                if(new_deriv.find(mesNT[cpt2]) == position_next_mot){
                                    int indice_nt_first = this->ind_NT_FF(mesNT[cpt2]);
                                    if(mesRegles[cpt1].getNT() != mesNT[cpt2]){
                                        modif = modif + FF[indice_nt_ff].copyFirst(FF[indice_nt_first]);
                                    }
                                    if(FF[indice_nt_first].detient_mot_vide()) {
                                        doit_aller_apres = true;
                                        position_next_mot += mesNT[cpt2].size();
                                    }
                                }
                                cpt2++;
                            }
                        }
                    }
                }
            }
        }
    }
}




int main()
{
    Grammaire g("THIVET-SEBAG-fichier.txt");
    if(g.getMesRegles().size() != 0){
        g.afficher_NT();
        g.afficher_T();
        cout << endl << "Grammaire brute" << endl;
        g.afficher();
        g.CalculFirstFollow();
        g.afficher_first();
    }
    return 0;
}
