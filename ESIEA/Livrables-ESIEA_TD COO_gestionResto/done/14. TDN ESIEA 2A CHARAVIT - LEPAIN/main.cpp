#include "main.h"

using namespace std;



Client::Client(string nom, Commande commandefaite) :
    m_nom(nom)
{
    m_commandefaite.push_back(commandefaite);
}

string Client::getNom() const
{
    return m_nom;
}

void Client::setcommandefaite(Commande nouvelleCommande)
{
    m_commandefaite.push_back(nouvelleCommande);
}

double Client::depenceTotal()
{
    double tot = 0;
    for(unsigned int i = 0; i < m_commandefaite.size(); i++)
    {
        tot += m_commandefaite[i].getprixTotal();
    }
    return tot;
}



Produit::Produit(string nom, int prix) :
    m_nom(nom),
    m_prix(prix)
{

}

int Produit::getprix() const
{
    return m_prix;
}

string Produit::getnom() const
{
    return m_nom;
}

/*
string Produit::get_class_name() {
    cout << "magic : " << magic << endl;
    string s = typeid(this).name();
    cout << "typeid(this).name : " << s << endl;
    size_t i;
    char c = '0';
    while ((i = s.find(c)) == string::npos && c < '9') c++;
    cout << "i : " << i << endl;
    if (i == string::npos) printf("Pas de chiffre dans l'expression %s\n", s.c_str());
    else s = s.substr(i + 1, s.length() - i - 1);
    cout << "typeid(this).name : " << s << endl;
    return s;
}
*/

Pate::Pate(string nom) : Produit(nom, 30)
{

}

Vegetarien::Vegetarien(string nom) : Produit(nom, 60)
{

}

Boisson::Boisson(string nom) : Produit( nom, 20)
{

}
/*
Orangina::Orangina() : Boisson("Orangina")
{

}
Vodka::Vodka() : Boisson("Vodka")
{

}
Eau::Eau () : Boisson("Eau")
{

}
*/
Pizza::Pizza(string nom) : Produit( nom, 50)
{

}
/*
Romantica::Romantica() : Pizza("Romantica")
{

}
Marguerita::Marguerita() : Pizza("Marguerita")
{

}
Reine::Reine() : Pizza("Reine")
{

}
*/



Commande::Commande(Produit produitVendu)
{
    m_produitVendu.push_back(produitVendu);
}

void Commande::setproduitVendu(Produit nouveauProduit)
{
    m_produitVendu.push_back(nouveauProduit);
}

int Commande::getnbproduitVendu() const
{
    int n = m_produitVendu.size();
    return n;
}

int Commande::getprixTotal()
{
    int tot = 0;
    for(unsigned int i = 0; i < m_produitVendu.size(); i++)
    {
        tot += m_produitVendu[i].getprix();
    }
    return tot;
}

void Commande::incrementeProduit(Produit enplus)
{
    m_produitVendu.push_back(enplus);
}

int Commande::fgetprix(int j)
{
    return m_produitVendu[j].getprix();
}

int Commande::fgetsize()
{
    return m_produitVendu.size();
}
string Commande::getNomCommande(int j) const
{
    return m_produitVendu[j].getnom();
}


/*
string Commande::getClass(int j)
{

    Orangina testOrangina;
    Eau testEau;
    Vodka testVodka;
    Marguerita testMarguerita;
    Romantica testRomantica;
    Reine testReine;

    cout << "j = " << j << "typeid(0) : " << typeid(m_produitVendu[j]).name() << " romantica" << typeid(testRomantica).name() << endl;

    if(typeid(m_produitVendu[j]) == typeid(testOrangina))
    {
        return "Orangina";
    }
    if(typeid(m_produitVendu[j]) == typeid(testEau))
    {
        return "Eau";
    }
    if(typeid(m_produitVendu[j]) == typeid(testVodka))
    {
        return "Vodka";
    }
    if(typeid(m_produitVendu[j]) == typeid(testMarguerita))
    {
        return "Marguerita";
    }
    if(typeid(m_produitVendu[j]) == typeid(testRomantica))
    {
        return "Romantica";
    }
    if(typeid(m_produitVendu[j]) == typeid(testReine))
    {
        return "Reine";
    }
    return "MOUALLEZ YA UNE ERREUR";
}
*/

Produit choixProduit (string typechoix, string choix)
{
    if(typechoix == "pizza")
    {
        Pizza lechoix(choix);
        return lechoix;
    }
    else if(typechoix == "pâtes")
    {
        Pate lechoix(choix);
        return lechoix;
    }
    else if(typechoix == "boisson")
    {
        Boisson lechoix(choix);
        return lechoix;
    }
    else if(typechoix == "végétarien")
    {
        Vegetarien lechoix(choix);
        return lechoix;
    }
    else 
    {
        Pizza lechoix("Romantica");
        return lechoix;
    }
}
/*
Produit choixProduit (string choix)
{
    if(choix == "Orangina")
    {
        Orangina lechoix;
        return lechoix;
    }
    else if(choix == "Vodka")
    {
        Vodka lechoix;
        return lechoix;
    }
    else if(choix == "Eau")
    {
        Eau lechoix;
        return lechoix;

    }
    else if(choix == "Reine")
    {
        Reine lechoix;
        return lechoix;
    }
    else if(choix == "Marguerita")
    {
        Marguerita lechoix;
        return lechoix;
    }
    else
    {
        Romantica lechoix;
        return lechoix;
    }
}
*/



int main()
{

    cout << "Bonjourno et bienvenuto a la pizzeria Italienne : IL SECULO. " << endl << "Vous avez une quantité phénoménale de produit a votre disposition !" << endl <<"De la pizza, de la boisson, des pâtes et même des plats végétariens !" << endl << "Ainsi donc veuillez choisir dans cette liste votre type de plat. Pour le plat végétarien, écrivez simplement végétarien. Sans majuscule s'il vous plait." << endl << "Si vous ne savez pas l'écrire ou que vous ne savez pas lire, une pizza vous sera offert ! La romantica !" << endl << "Mais vous devrez la payez." << endl << "tappez maintenant ce que vous voulez dégustez." << endl;

    string typePlatChoisit;
    cin >> typePlatChoisit;

    cout << "Très bien..." << endl << "Veuillez rentré quel plat du type " << typePlatChoisit << " vous voulez."<< endl;

    string platChoisit;
    cin >> platChoisit;

    cout << "Très bien, très bon choix..." << endl << "Ah ! suie-je bête ?! J'ai oublié de vous demander votre nom !" << endl << "Veuillez tappez votre nom maintenant." << endl;

    string nomClient;
    cin >> nomClient;

    Produit produitChoisit = choixProduit(typePlatChoisit,platChoisit);



    /*
    Produit p1("p1", 19);

    Pizza p2("Regina");

    cout << "type de p1 " << p1.get_class_name() << endl;
    cout << "type de p2 " << p2.get_class_name() << endl;
    */

    Commande laCommande(produitChoisit);

    Client leClient(nomClient, laCommande);

    Produit produitChoisi("yamero", 0);



    string reponse = "olol";
    string reponse2 = "ololo";

    cout << "Très bien très bien... Vous voulez autre chose?" << endl << "Commandez de la même manière que précédemment." << endl << "D'abord le type de plat, puis le plat en lui même." << endl << "Mais si vous ne voulez rien de plus, alors ne commandez rien !" << endl;

    while(reponse != "rien")
    {

        cin >> reponse;

        if (reponse == "rien")
        {

        }
        else
        {
            cin >> reponse2;
            Produit lenouveau("yamete", 0);
            lenouveau = choixProduit(reponse, reponse2);
            laCommande.incrementeProduit(lenouveau);
            cout << "Très bien, très bon choix... Autre chose?" << endl;
        }
    }

    cout << "Maintenant que vous avez fini de commander, voici votre Diner. Bonne Appétit !" << endl;

    cout << "Ho ho ! Vous me semblez bien repu ! Mais il va falloit payer maintenant !" << endl << "Vous avez commandé : " << laCommande.getnbproduitVendu() << " plats." << endl << "Vous devez donc payer : " <<  laCommande.getprixTotal() << " euro." << endl << "Merci d'avoir commandé chez nous ! Bonne soirée !" << endl;



    ofstream rentreNouvelleDonnee("/home/stephane/Bureau/Code/Restaurant/resultat.txt", ios::app);
    rentreNouvelleDonnee << leClient.getNom() << " : " << endl;
    for(unsigned int j = 0; j < static_cast<unsigned int>(laCommande.fgetsize()) ; j++)
    {
        rentreNouvelleDonnee << "	" << laCommande.getNomCommande(j) << "  " <<laCommande.fgetprix(j) << "." << endl;
    }
    rentreNouvelleDonnee << "	Le prix total est : " << laCommande.getprixTotal() << "." << endl;



    return 0;
}
