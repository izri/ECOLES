
public class Utility {
	static void afficheCommandes(Commande cmd){
		System.out.println("Commande n° "+cmd.getId());
		System.out.println("\tLe : "+cmd.getDate());
		System.out.println("\tPour : "+cmd.getNombreDePersonnes()+" personne(s).");
		for(Plat plat_iter : cmd.getPlat_commande()){
			System.out.println("\t\t[+] Plat : "+plat_iter.getNom());
			System.out.println("\t\tQuantité : "+plat_iter.getQuantite());
			System.out.println("\t\tPrix : "+plat_iter.getPrix());
		}
		System.out.println("\tPrix Total : "+cmd.getPrix_commande()+" €");
		System.out.print("\r\n");
	}
	
}
