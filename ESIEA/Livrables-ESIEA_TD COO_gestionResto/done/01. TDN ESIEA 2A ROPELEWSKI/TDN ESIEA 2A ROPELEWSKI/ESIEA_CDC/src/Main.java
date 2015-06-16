import java.util.*;

public class Main {
	public static void main(String[] args) {
		System.out.println("Restaurant 5 étoiles - Chez Roploplo !");
		System.out.println("Bienvenue dans le centre de gestion des commandes !");

		// Fonctionnalités du menu
		String reponse_utilisateur = new String();
		Scanner scan_commande = new Scanner(System.in);
		scan_commande.useDelimiter("\r\n");

		while(true){
			System.out.println();
			System.out.println("1 - Prendre une commande");
			System.out.println("2 - Afficher la dernière commande");
			System.out.println("3 - Historique des 5 dernières commandes");
			System.out.println("4 - Historique des 5 meilleures commandes");
			System.out.println("5 - Afficher le dernier client");
			System.out.println("6 - Historique des 5 derniers clients");
			System.out.println("7 - Historique des 5 meilleurs clients");
			System.out.println("8 - Historique des 5 clients les plus fidèles");
			System.out.println("9 - Afficher toutes les commandes d'un client");
			System.out.println("10 - Afficher les meilleures ventes");
			System.out.println("Que souhaitez-vous faire ?");
			
			int choix = 0;
			try{
				choix = Integer.parseInt(scan_commande.next());
			}
			catch (NumberFormatException e) {
				e.printStackTrace();
			}
	
			switch (choix) {
			// Inserer de nouvelles commandes
			case 1:
				do {
					// Carte fidélité
					System.out.println("Bonjour, possédez-vous la carte fidélité ? (Oui/Non)");
	
					// NON -> Création de la commande et d'un nouveau client
					reponse_utilisateur = scan_commande.next();
					if (reponse_utilisateur.equalsIgnoreCase("Non")|| reponse_utilisateur.equalsIgnoreCase("N")|| reponse_utilisateur.equalsIgnoreCase("No")) {
						System.out.println("Quel est votre nom ?");
						String nom_utilisateur = scan_commande.next();
						
						System.out.println("Quel est votre adresse ?");
						String adresse_utilisateur = scan_commande.next();
						
						System.out.println("Quel est votre email ?");
						String email_utilisateur = scan_commande.next();
	
						// On crée le nouveau client
						Client.setId_incremente(GestionSQL.selectIDClientSQL() + 1);
						Client nouveauClient = new Client(nom_utilisateur, adresse_utilisateur,email_utilisateur);
	
						// Mise a jour de l'id commande
						Commande.setId_incremente(GestionSQL.selectIDCommandeSQL() + 1);
	
						System.out.println("Commande pour combien de personnes ? (Entier)");
						int nombre_de_clients = scan_commande.nextInt();
						List<Plat> listePlats = new ArrayList<Plat>();
						String plat_a_servir = new String();
	
						while (!plat_a_servir.equalsIgnoreCase("Fin")) {
							// Récupère le plat demandé
							System.out.println("Quel plat souhaitez-vous commander ? (\"Fin\" pour terminer la commande)");
							plat_a_servir = scan_commande.next();
	
							// Condition pour sortir de la boucle quand
							// l'utilisateur a fini sa commande
							if (plat_a_servir.equalsIgnoreCase("Fin"))
								break;
	
							// Si on est pas sorti on récupère la quantité de plat
							System.out.println("\tEn quelle quantité ?");
							int quantite_a_servir = scan_commande.nextInt();
	
							// On crée un plat dans la liste avec la quantité
							// désirée
							if (quantite_a_servir != 0)
								listePlats.add(new Plat(quantite_a_servir, plat_a_servir));
						}
						// Crée la commande avec les plats choisis
						Commande cmd = new Commande(nombre_de_clients, listePlats);
	
						// On met à jour les informations sur le client
						nouveauClient.setDerniereCommande(cmd.getId());
						nouveauClient.setHistoriqueCommande(cmd.getId() + "|");
						nouveauClient.setNbreDeCommande(1);
						nouveauClient.setPtFidelite(1);
						nouveauClient.setTotalDepenses(cmd.getPrix_commande());
	
						// Affiche la commande
						Utility.afficheCommandes(cmd);
	
						// Ajoute la commande dans la bdd
						GestionSQL.insererNouvelleCommandeSQL(cmd);
	
						// Ajout du client dans la base de données
						GestionSQL.insererNouveauClientSQL(nouveauClient);
	
						// Affichage de l'identifiant
						System.out.println("Votre identifiant fidelité client est : "+ nouveauClient.getId());
	
						System.out.println("Souhaitez-vous passer une autre commande ? (Oui/Non)");
						reponse_utilisateur = scan_commande.next();
					}
	
					// OUI -> Création de la commande et attribution au client
					else {
						// Récupérer l'identifiant du client
						System.out.println("Quel est votre identifiant ?");
						int client_id = scan_commande.nextInt();
	
						// Recupérer un objet provenant de la BDD
						Client regulier = GestionSQL.clientFromSQL(client_id);
	
						// Mise a jour de l'id commande
						Commande.setId_incremente(GestionSQL.selectIDCommandeSQL() + 1);
	
						System.out.println("Commande pour combien de personnes ? (Entier)");
						int nombre_de_clients = scan_commande.nextInt();
						List<Plat> listePlats = new ArrayList<Plat>();
						String plat_a_servir = new String();
	
						while (!plat_a_servir.equalsIgnoreCase("Fin")) {
							// Récupère le plat demandé
							System.out.println("Quel plat souhaitez-vous commander ? (\"Fin\" pour terminer la commande)");
							plat_a_servir = scan_commande.next();
	
							// Condition pour sortir de la boucle quand l'utilisateur a fini sa commande
							if (plat_a_servir.equalsIgnoreCase("Fin"))
								break;
	
							// Si on est pas sorti on récupère la quantité de plat
							System.out.println("\tEn quelle quantité ?");
							int quantite_a_servir = scan_commande.nextInt();
	
							// On crée un plat dans la liste avec la quantitédésirée
							if (quantite_a_servir != 0)
								listePlats.add(new Plat(quantite_a_servir,plat_a_servir));
						}
						// Crée la commande avec les plats choisis
						Commande cmd = new Commande(nombre_de_clients, listePlats);
						
						//Gestion de la carte fidélité
						if(regulier.getPtFidelite()+1 == 10){
							System.out.println("Vous avez 10 points fidélité, merci d'être un si bon client, votre commande est offerte par la maison !");
						}
	
						// On met à jour les informations sur le client
						GestionSQL.updateClientSQL(regulier, cmd);
	
						// Affiche la commande
						Utility.afficheCommandes(cmd);
	
						// Ajoute la commande dans la bdd
						GestionSQL.insererNouvelleCommandeSQL(cmd);
	
						System.out.println("Souhaitez-vous passer une autre commande ? (Oui/Non)");
						reponse_utilisateur = scan_commande.next();
					}
				} while (reponse_utilisateur.equalsIgnoreCase("Yes")|| reponse_utilisateur.equalsIgnoreCase("Y")
						|| reponse_utilisateur.equalsIgnoreCase("O")|| reponse_utilisateur.equalsIgnoreCase("Oui"));
				break;
	
			// Afficher la dernière commande
			case 2:
				GestionSQL.historiqueCommande();
				break;
	
			// Historique des 5 dernières commandes
			case 3:
				GestionSQL.historiqueCommande(5);
				break;
	
			// Historique des 5 meilleures commandes
			case 4:
				GestionSQL.historiqueCommande(5, "total");
				break;
	
			// Affiche le dernier client
			case 5:
				GestionSQL.historiqueClient();
				break;
	
			// Historique des 5 derniers clients
			case 6:
				GestionSQL.historiqueClient(5);
				break;
				
			// Historique des meilleurs clients à partir de leurs dépenses
			case 7:
				GestionSQL.historiqueClient(5,"TotalDepenses");
				break;
				
			// Historique des meilleurs clients à partir de leur nombre de commandes	
			case 8:
				GestionSQL.historiqueClient(5,"NbreDeCommandes");
				break;
			
			//Affiche toutes les commandes d'un client
			case 9:
				System.out.println("Quel est le numéro client ?");
				if(scan_commande.hasNextInt()){
					GestionSQL.commandesDuClient(scan_commande.nextInt());
				}
				break;
				
			case 10:
				GestionSQL.meilleursVentes();
				break;
				
			default:
				break;
			}
		}
	}
}
