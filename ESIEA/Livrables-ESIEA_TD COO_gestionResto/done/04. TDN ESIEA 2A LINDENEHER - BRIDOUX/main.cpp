#include <iostream>
#include <stdlib.h>

#include "allclients.h"

using namespace std;


#if defined _WIN32 || defined __CYGWIN__
void clearScreen() {
	system("cls");
}
#elif defined __linux__ || defined __linux
void clearScreen() {
	printf("%c[2J", 0x1B);
	printf("%c[%d;%dH", 0x1B, 1, 1);
}
#endif


void subSelectClient(AllClients *db, Client **cl) {
    int result = 0;
    while(result == 0) {
        clearScreen();
        cout << "Listes des clients" << endl;
        cout << "------------------" << endl;

        db->showClients();
        cout << "0. Annuler" << endl;

        cout << "Quel numero de client ? "; cin >> result;
        if(result == 0) break;

        if(db->getClientAt(result-1) == NULL) result = 0;
        else *cl = db->getClientAt(result-1);
    }
}

void subAddProd(Command *cmd) {
    int choice = -1;

    while(choice != 0) {
        switch(choice) {
            case 1: cmd->addProducts(new Salade(5.0)); break;
            case 2: cmd->addProducts(new Tartare(4.5)); break;
            case 3: cmd->addProducts(new Nem(3.5)); break;
            case 4: cmd->addProducts(new Pizza(9.5)); break;
            case 5: cmd->addProducts(new Frite(2.5)); break;
            case 6: cmd->addProducts(new Burger(6.0)); break;
            case 7: cmd->addProducts(new DragonEgg(66.6)); break;
            case 8: cmd->addProducts(new Gateau(7.5)); break;
            case 9: cmd->addProducts(new Fruit(1.5)); break;
            case 10: cmd->addProducts(new Cafe(2)); break;
            case 11: cmd->addProducts(new Coca(1.5)); break;
            case 12: cmd->addProducts(new Eau(1.0)); break;
        }

        cout << "Ajout d'un produit" << endl;
        cout << "------------------" << endl;

        cmd->showInfo();

        cout << endl << "Quel produit voulez-vous ajouter ?" << endl;
        cout << "1. Salade" << endl;
        cout << "2. Tartare" << endl;
        cout << "3. Nem" << endl;
        cout << "4. Pizza" << endl;
        cout << "5. Frites" << endl;
        cout << "6. Burger" << endl;
        cout << "7. Oeuf de dragon" << endl;
        cout << "8. Gateau" << endl;
        cout << "9. Fruit" << endl;
        cout << "10. Cafe" << endl;
        cout << "11. Coca" << endl;
        cout << "12. Eau" << endl;
        cout << "0. Terminer l'ajout" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

void subDelProd(Command *cmd) {
    int choice = -1;

    while(choice != 0) {
        if(choice != -1) cmd->deleteProduct(choice-1);

        cout << "Suppression d'un produit" << endl;
        cout << "------------------------" << endl;

        cmd->showInfo();

        cout << endl << "x. Le numero du produit a supprimer" << endl;
        cout << "0. Terminer la suppression" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

void subAddCmd(Client *cl) {
    int choice = -1;
    Command *cmd = new Command();

    while(choice != 0) {
        switch(choice) {
        case 1:
            subAddProd(cmd);
            break;
        case 2:
            subDelProd(cmd);
            break;
        }

        cout << "Ajout d'une commande" << endl;
        cout << "--------------------" << endl;

        cmd->showInfo();

        cout << endl << "1. Ajouter des produits" << endl;
        cout << "2. Supprimer un produit" << endl;
        cout << "0. Terminer la commande" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }

    if(!cmd->isEmpty()) cl->addCmd(cmd);
}

void subDelCmd(Client *cl) {
    int choice = -1;

    while(choice != 0) {
        if(choice != -1) cl->deleteCmd(choice-1);

        cout << "Suppression d'une commande" << endl;
        cout << "--------------------------" << endl;

        cl->showCmd();

        cout << endl << "x. Le numero de la commande a supprimer" << endl;
        cout << "0. Terminer la suppression" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

void subNoteCmd(Client *cl) {
    int choice = -1;
    float note;
    Command *cmd = NULL;

    while(choice != 0) {
        if(choice != -1) {
            if((cmd = cl->getCmdAt(choice-1)) != NULL) {
                cmd->showInfo();
                cout << "Quelle note pour cette commande ? "; cin >> note;
                cmd->setNote(note);
                clearScreen();
            }
        }

        cout << "Notation d'une commande" << endl;
        cout << "-----------------------" << endl;

        cl->showCmd();

        cout << endl << "x. Le numero de la commande a voir / noter" << endl;
        cout << "0. Retour" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

void subCmdMenu(Client *cl) {
    int choice = -1;

    while(choice != 0) {
        switch(choice) {
        case 1:
            subAddCmd(cl);
            break;
        case 2:
            subDelCmd(cl);
            break;
        case 3:
            subNoteCmd(cl);
            break;
        }

        cl->showCmd();

        cout << endl << "1. Ajouter une commande" << endl;
        cout << "2. Supprimer une commande" << endl;
        cout << "3. Voir / noter une commande" << endl;
        cout << "0. Retour au menu principal" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

void subStatMenu(AllClients *db) {
    int choice = -1;

    while(choice != 0) {
        switch(choice) {
        case 1:
            cout << "La note moyenne de toutes les commandes est : " << db->calcAverageNote() << "/5" << endl << endl;
            break;
        case 2:
            cout << "Le produit star est : " << db->calcBestProduct() << endl << endl;
            break;
        case 3:
            cout << "Le produit pourri est : " << db->calcWorseProduct() << endl << endl;
            break;
        case 5:
            cout << "Le prix moyen de toutes les commandes est : " << db->calcAveragePrice() << " euros" << endl << endl;
            break;
        case 4:
            vector<string> prodSorted = db->sortProduct();
            cout << "Classement des produits du restaurant" << endl;
            for(unsigned int i = 0; i < prodSorted.size(); i++) cout << i+1 << ". " << prodSorted.at(i) << endl;
            cout << endl;
            break;
        }

        cout << endl << "1. Calculer la moyenne des commandes du restaurant" << endl;
        cout << "2. Voir le produit le plus populaire" << endl;
        cout << "3. Voir le pire produit" << endl;
        cout << "4. Classer les produits" << endl;
        cout << "5. Calculer le prix moyen des commandes" << endl;
        cout << "0. Retour au menu principal" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }
}

int main() {
    int choice = -1;
    AllClients *db = new AllClients();
    Client *currClient = NULL;

    while(choice != 0) {
        if(db->isEmpty() && choice == 1) {
            currClient = db->addClient();
            clearScreen();
        }
        else if(!db->isEmpty()) {
            switch(choice) {
            case 1:
                subSelectClient(db, &currClient);
                clearScreen();
                break;
            case 2:
                currClient = db->addClient();
                clearScreen();
                break;
            case 3:
                db->deleteClient(currClient);
                if(!db->isEmpty()) currClient = db->getClientAt(0);
                break;
            case 4:
                currClient->showInfo();
                break;
            case 5:
                clearScreen();
                subCmdMenu(currClient);
                break;
            case 6:
                clearScreen();
                subStatMenu(db);
                break;
            }
        }


        cout << "Menu principal" << endl;
        cout << "--------------" << endl;
        if(db->isEmpty()) cout << "1. Ajouter un nouveau client" << endl;
        else {
            cout << "Client selectionne : "; currClient->printNames(); cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "1. Selectionner un autre client" << endl;
            cout << "2. Ajouter un nouveau client" << endl;
            cout << "3. Supprimer le client selectione" << endl;
            cout << "4. Voir les informations de "; currClient->printNames(); cout << endl;
            cout << "5. Voir les commandes de "; currClient->printNames(); cout << endl;
            cout << "6. Acceder au menu statistique"; cout << endl;
        }
        cout << "0. Quitter le programme" << endl;

        cout << "Votre choix ? "; cin >> choice;
        clearScreen();
    }

    return 0;
}
