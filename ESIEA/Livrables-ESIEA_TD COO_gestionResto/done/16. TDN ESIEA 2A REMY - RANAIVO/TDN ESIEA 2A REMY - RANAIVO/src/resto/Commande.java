package resto;
import java.util.Scanner;

public class Commande {
	public Commande(){
	}

	void passeCommande(Client client){
		//Variables
		int Plat;
		int Spec;
		int quantité;
		char rep = ' ';
		int choix;
		
		//Client client = new Client();
		Scanner scan = new Scanner(System.in);


		//Rajout d'une visite = commande
		Plats p = new Plats();
		System.out.println("Voici le menu : ");
		//Affichage du Menu
		do{
			p.menu();
			//Demande au client ce qu'il veut comme plat
			do{
				System.out.print("Que voulez vous? ");
				Plat = scan.nextInt();							

				//Cas de la boisson
				Boisson b1 = new Boisson();
				if(Plat == 1 ){

					b1.affichageB();

					//Demande au client quelle boisson il veut
					do{
						System.out.print("Que voulez vous? ");
						Spec = scan.nextInt();

						//Tous les cas de boissons avec leurs prix
						if(Spec == 1){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+b1.coca);
							System.out.println("Commande : "+p.price+"€");	
						}else if(Spec == 2){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+b1.sprite);
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 3){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+b1.eau);
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 4){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+b1.jusFruit);
							System.out.println("Commande : "+p.price+"€");
						}
					}while(Spec > 4);
				}

				//Cas des pizzas
				Pizza p1 = new Pizza();
				if(Plat == 2){

					p1.affichageP();

					//Demande au client quelle pizza il veut
					do{
						System.out.print("Que voulez vous? ");
						Spec = scan.nextInt();

						//Tous les cas de pizzas avec leurs prix
						if(Spec == 1){							
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+p1.fromage);
							System.out.println("Commande : "+p.price+"€");	
						}else if(Spec == 2){								
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+p1.marguarita);
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 3){						
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+p1.sicilienne);
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 4){								
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+p1.paysanne);
							System.out.println("Commande : "+p.price+"€");
						}
					}while(Spec > 4);
				}

				//Cas du plat du jour	
				PlatDuJour pdj = new PlatDuJour();
				if(Plat == 3){

					pdj.affichagePDJ();		

					do{
						System.out.print("Que voulez vous? ");
						Spec = scan.nextInt();
						if(Spec == 1){									
							System.out.println("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+pdj.blanquette);
							System.out.println("Commande : "+p.price+"€");
						}
					}while(Spec >1);
				}

				//Cas des plats végétariens
				Végétarien v1 = new Végétarien();

				if(Plat == 4){

					v1.affichageV();

					//Demande au client quel plat il veut
					do{
						System.out.print("Que voulez vous? ");
						Spec = scan.nextInt();

						//Tous les cas de plats végétarien avec leurs prix
						if(Spec == 1){								
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+v1.salade);
							System.out.println("Commande : "+p.price+"€");	
						}else if(Spec == 2){								
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+v1.lasagne);									
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 3){
							System.out.print("Combien en voulez vous? " );
							quantité = scan.nextInt();
							p.price = quantité*(p.price+v1.tofu);
							System.out.println("Commande : "+p.price+"€");
						}
					}while(Spec > 3); 
				}

				//Cas des desserts		
				Dessert d1 = new Dessert();

				if(Plat == 5 ){

					d1.affichageD();

					//Demande au client quel dessert il veut
					do{
						System.out.print("Que voulez vous? ");
						Spec = scan.nextInt();

						//Tous les cas des desserts avec leurs prix
						if(Spec == 1){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+d1.glace);
							System.out.println("Commande : "+p.price+"€");	
						}else if(Spec == 2){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+d1.tarte);
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 3){
							p.price = p.price+d1.creme;
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							System.out.println("Commande : "+p.price+"€");
						}else if(Spec == 4){
							System.out.print("Combien en voulez vous? ");
							quantité = scan.nextInt();
							p.price = quantité*(p.price+d1.fruits);
							System.out.println("Commande : "+p.price+"€");
						}
					}while(Spec> 4);
				}
			}while(Plat > 5);

			do{
				System.out.println("Voulez-vous une autre chose? (O/N)");
				rep = scan.next().charAt(0);
			}while(rep != 'O' && rep != 'N');					
		}while(rep == 'O' );					

		//Pourboire
		do{
			System.out.println("Donnez un pourboire :");
			System.out.println("1-Oui ");
			System.out.println("2-Non ");
			choix = scan.nextInt();
			if(choix == 1){
				System.out.print("Combien donnez vous? ");
				quantité = scan.nextInt(); 
				client.pourboire = client.pourboire + quantité;
				System.out.println("Prix total de la commande : "+p.price+"€ et "+quantité+"€ de pourboire");
				
				client.derniereAddition = p.price;
				client.sommePrix = client.sommePrix + client.derniereAddition + client.pourboire;
			}else if(choix == 2){							
				System.out.println("Prix total de la commande : "+p.price+"€");
				client.derniereAddition = p.price;
				client.sommePrix = client.sommePrix + client.derniereAddition + client.pourboire;
			}
		}while(choix > 2 );
	}
}
