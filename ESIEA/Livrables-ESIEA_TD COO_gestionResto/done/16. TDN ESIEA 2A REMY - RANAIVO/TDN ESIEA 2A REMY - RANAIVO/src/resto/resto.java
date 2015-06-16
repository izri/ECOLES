package resto;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;


public class resto {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		/****************************** INITIALISATION ******************************/	
		
		/* ***** ATTRIBUTS ***** */
		int cmpt = 1;
		int onglet;
		int choix;
		int entree;
		int meilleur;
		File fichierClientTest = new File("clientTest.xml");
		File fichierNbreClient = new File("nbreClient.xml");
		/* ******************** */
		
		
		/* ***** Scanner ***** */
		Scanner scan = new Scanner(System.in);
		String scanPrenom;
		String scanNom;
		/* ****************** */
		
		
		/* ***** CREATION DES OBJETS FONDAMENTAUX ***** */
		Commande commande = new Commande(); // Creation de l'objet commande (objet servant à l'utilisateur de passer une commande)
		Client [] tabClient = new Client[100]; // Notre tableau de clients servant de "base de données"
		Client clientInit = new Client("Inconnu", 0, 0, "Inconnu","Inconnu", "Inconnu", 0,0,0); //Nous permet d'initialiser notre tableau de clients
		Client clientTest = new Client(); //Nous permet de rajouter un client en remplissant la fiche client
		/* ******************************************* */
		

		/* ***** INITIALISATION DE NOTRE TABLEAU DE CLIENT ***** */
		for(int j = 0; j<100; j++)
			tabClient[j] = clientInit;
		/* **************************************************** */
		
		
		/* ***** CHARGEMENT DE NOS FICHIERS ***** */
		if(fichierNbreClient.exists())
		cmpt = (int) XMLTools.decodeFromFile("nbreClient.xml");
		if(fichierClientTest.exists())
			tabClient = (Client[]) XMLTools.decodeFromFile("clientTest.xml");
		/* ************************************** */

		/****************************************************************************/
		
		
		/************************** LANCEMENT DU PROGRAMME **************************/
		while(true){
		/* ***** MENU N°1 ***** */
		System.out.println(":******** BIENVENUE ********:");
		System.out.println("|    1- Espace Restaurant   |");
		System.out.println("|    2- Espace Classement   |");
		System.out.println("'***************************'");
		entree = scan.nextInt();
		/* ******************** */
		
		/** ***** ESPACE RESTAURANT ***** **/
		if(entree == 1){
			//Phrase de bienvenue et identification du client
			System.out.println("Bienvenue, êtes vous client?");
			System.out.println(" 1-Oui");
			System.out.println(" 2-Non");
			System.out.println(" 3-Regarder la liste des clients");
			choix = scan.nextInt();

			
			/** ***** CLIENT DEJA ENREGISTRE ***** **/
			if(choix == 1){
				System.out.print("Nom de client : ");
				scanNom = scan.next();
				System.out.print("Prenom de client : ");
				scanPrenom = scan.next();
				for(int i = 0; i< 100; i++){
					if(tabClient[i].nomClient.equals(scanNom) && tabClient[i].prenomClient.equals(scanPrenom)){
						System.out.println("1. Afficher la fiche client");
						System.out.println("2. Rajouter une visite");
						onglet = scan.nextInt();

						//Cas où on affiche la fiche du client
						if(onglet == 1){
							tabClient[i].affichageFiche();
						}
						//Cas où on rajoute une visite au client
						if(onglet == 2){
							tabClient[i].ajoutVisite();
							commande.passeCommande(tabClient[i]);
							XMLTools.encodeToFile(tabClient, "clientTest.xml");
						}
					}
				}
			}
			/** ******************************** **/
			
			/** ***** NOUVEAU CLIENT ***** **/
			else if(choix == 2){
				
				
				//Ajout des renseignements
				clientTest.creationFicheClient();
				tabClient[cmpt-1] = clientTest;
				cmpt++;
				XMLTools.encodeToFile(tabClient, "clientTest.xml");
				XMLTools.encodeToFile(cmpt, "nbreClient.xml");

				commande.passeCommande(tabClient[cmpt-2]);
				tabClient[cmpt-2].nbreDeVisite++;
				XMLTools.encodeToFile(tabClient, "clientTest.xml");
				XMLTools.encodeToFile(cmpt, "nbreClient.xml");
				
			}
			/** ************************** **/
			
			else if(choix == 3){
				System.out.println("Liste des clients : \n");
				for(int i = 0; i<100; i++){
					if(!tabClient[i].nomClient.equals("Inconnu")){
						System.out.println(tabClient[i].prenomClient+" "+tabClient[i].nomClient);
					}
				}
			}
			
			
			//XMLTools.encodeToFile(tabClient, "clientTest.xml");
			//Cas ou on affiche le meilleurs clients selon deux critères possibles
		}else if(entree == 2){
			do{	
				System.out.println("Meilleur client selon :");
				System.out.println(" 1- Le nombre de visite");
				System.out.println(" 2- La somme totale dépensé");
				choix = scan.nextInt();
				//Cas 1 pour les visites et cas 2 pour les € dépensés
				if(choix == 1){
					meilleur = 0;
					for(int i= 0; i < 99; i++){
						if(tabClient[meilleur].nbreDeVisite < tabClient[i+1].nbreDeVisite){
							meilleur = i+1;
						}
					}
					System.out.println("Le meilleur client selon le nombre de visite est :  "+tabClient[meilleur].nomClient+" "+tabClient[meilleur].prenomClient+" avec "+tabClient[meilleur].nbreDeVisite+" visites");
				}else if(choix == 2){ 			
					meilleur = 0;
					for(int i= 0; i < 99; i++){
						if(tabClient[meilleur].sommePrix < tabClient[i+1].sommePrix){
							meilleur = i+1;
						}
					}
					System.out.println("Le meilleur client selon la somme total d'euros dépensés est :  "+tabClient[meilleur].nomClient+" "+tabClient[meilleur].prenomClient+" avec "+tabClient[meilleur].sommePrix+" €");
				}
			}while(choix > 2);		
		}
		System.out.println("\n");
	}
	}
}