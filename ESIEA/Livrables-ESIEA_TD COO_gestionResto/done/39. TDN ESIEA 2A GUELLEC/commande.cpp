#include <iostream>
#include <string>
#include "produit.hpp"
#include "commande.hpp"
using namespace std;

commande::commande(produit c_conso, int c_quantite): c_quantite(c_quantite),c_conso(c_conso), c_suivante(0){
    }

void commande::nouvelleCommande(produit conso, int quantite){

c_suivante=new commande(conso,quantite);
//commande c_suivante(conso,quantite);
}

void commande::afficher(){
cout<<"vous avez commande";//<<;
if(c_quantite==1){
    cout<<c_quantite<<" ";//<<;
    c_conso.afficher();
    //endl;
    }
if(c_quantite>1){
    cout<<c_quantite<<" ";//<<;
    c_conso.afficher();
    //endl;
    }
if(c_quantite==0)cout<<"rien du tout"<<endl;
}


produit commande::getConso(){return c_conso;}
int commande::getQuantite(){return c_quantite;}

commande* commande::avancer(){
return c_suivante;
}
int commande::prixTotal(){
return c_conso.getPrix()*c_quantite;
}

commande* commande::retournerCommande(){
return c_suivante;

}

