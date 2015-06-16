#include <iostream>
#include <string>

#include "TicketCaisse.h"

using namespace std;

TicketCaisse::TicketCaisse() : m_nomResto("Mefisto"),m_telResto("001125478"),m_nomServeur("Mario"),m_chiffreServeur("666")
{

}

TicketCaisse::TicketCaisse(string c) : m_nomResto(""),m_telResto(""),m_nomServeur(""),m_chiffreServeur("")
{

}

int m_stockPizza(200),m_stockPj(200),m_stockPv(200),m_stockBoisson(200),m_stockDessert(200);
int vente=0;
unsigned int TicketCaisse::resumeTicket()
{

int prix;
int reponse;
int com_pizza;
int com_pv;
int com_pj;
int com_boisson;
int com_dessert;


int recette;
    cout << "commande du client : " << endl;

    cout << "nombre de pizza: " << endl;
    int nbPizza,nbDessert,nbVegetarien,nbJour,nbBoisson;
    //getline(cin,nbPizza);
    cin >> nbPizza;

    cout << "nombre de plat vegetarien : " << endl;
    //getline(cin,nbVegetarien);
    cin >> nbVegetarien;

    cout << "nombre du plat du jour : " << endl;
    //getline(cin,nbJour);
    cin >> nbJour;

    cout << "nombre de boisson : " << endl;
    //getline(cin,nbBoisson);
    cin >> nbBoisson;

    cout << " nombre de dessert : " << endl;
    //getline(cin,nbDessert);
    cin >> nbDessert;

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " RESUME DE LA COMMANDE" << endl;
    cout << "  " << endl;

    cout << "Pizza : " << nbPizza << endl;
    cout << "Plat du Jour : " << nbJour << endl;
    cout << "Plat Vegetarien : " << nbVegetarien << endl;
    cout << "Boisson : " << nbBoisson << endl;
    cout << "Dessert : " << nbDessert << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " " << endl;
    prix = nbPizza*6+nbDessert*5+nbJour*8+nbVegetarien*10+nbBoisson*2;
    cout << "Prix total : " << prix << " euros" << endl;

    cout << " voulez voir le stock ? " << endl;
    cout << "1.oui 2.non " << endl;
    cin >> reponse;
    m_stockPizza-= nbPizza;
    m_stockPj-= nbJour;
    m_stockPv-= nbVegetarien;
    m_stockBoisson-= nbBoisson;
    m_stockDessert-= nbDessert;
    if(reponse == 1){
    cout << "---------------------------------------------------------------------------------" << endl;
        cout<< "en debut de journee vous avez assez d'ingredient pour servir: "<< endl;
        cout<<" "<<endl;

        cout<<"200 pizzas, plats du jour ,boissons ,desserts ,plats vegetariens"<<endl;
        cout << "-----------------------------------------------------------------------------" << endl;



cout<<" "<<endl;
cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Il vous reste : " << m_stockPizza << " Pizza " << endl;
    cout << "Il vous reste : " << m_stockPj << " Plat du jour " << endl;
    cout << "Il vous reste : " << m_stockPv << " plat vegetarien " << endl;
    cout << "Il vous reste : " << m_stockBoisson << " boisson " << endl;
    cout << "Il vous reste : " << m_stockDessert << " dessert " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    }


 if (m_stockPizza<20){
        cout<<"ATTENTION! vous pourrez faire que "<<m_stockPizza<<" pizzas "<<endl;
        cout<<" "<<endl;
        cout<<"combien de pizzas allez vous commander?"<<endl;
        cin>>com_pizza;
        m_stockPizza+=com_pizza;
    }
     if (m_stockPj<20){
        cout<<"ATTENTION! vous pourrez faire que "<<m_stockPj<<" plat du jour"<<endl;
        cout<<" "<<endl;
        cout<<"combien de plat du jour allez vous commander?"<<endl;
        cin>>com_pj;
        m_stockPj+=com_pj;
    }
     if (m_stockPv<20){
        cout<<"ATTENTION! vous pourrez faire que "<<m_stockPv<<" plat vegetarien"<<endl;
        cout<<" "<<endl;
        cout<<"combien de plat vegetarien allez vous commander?"<<endl;
        cin>>com_pv;
        m_stockPv+=com_pv;
    }
     if (m_stockBoisson<20){
        cout<<"ATTENTION! vous avez que "<<m_stockBoisson<<" boisson en stock"<<endl;
        cout<<" "<<endl;
        cout<<"combien de boissons allez vous commander?"<<endl;
        cin>>com_boisson;
        m_stockBoisson+=com_boisson;
    }
     if (m_stockDessert<20){
        cout<<"ATTENTION! vous pourrez faire que "<<m_stockDessert<<" dessert en stock"<<endl;
        cout<<" "<<endl;
        cout<<"combien de dessert allez vous commander?"<<endl;
        cin>>com_dessert;
        m_stockDessert+=com_dessert;
    }
    vente+=prix;
    cout<<" "<<endl;
 cout << " voulez voir la recette  ? " << endl;
    cout << "1.oui 2.non " << endl;
    cin >> recette;
    if(recette==1){
        cout<<" "<<endl;
    cout << "-----------------------------------------------------------------------" << endl;
       cout << "votre recette actuel est " << vente << " euros " << endl;
cout << "--------------------------------------------------------------------" << endl;
    }
return prix;
    }

void TicketCaisse::Ticket(){
int prix;
prix =resumeTicket();

cout << "votre recette actuel est " << prix << " euros " << endl;

}

/*void TicketCaisse::faireStock()
{
    int m_stockPizza(200),m_stockPj(200),m_stockPv(200),m_stockBoisson(200),m_stockDessert(100);


    m_stockPizza-= nbPizza;
    m_stockPj-= nbJour;
    m_stockPv-= nbVegetarien;
    m_stockBoisson-= nbBoisson;
    m_stockDessert-= nbDessert;
}*/






