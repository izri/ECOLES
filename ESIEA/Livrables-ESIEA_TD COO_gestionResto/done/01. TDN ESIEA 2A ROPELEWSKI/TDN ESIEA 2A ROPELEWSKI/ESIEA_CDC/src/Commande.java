import java.util.List;
public class Commande {
	public static int id_incremente = 0;
	public static int getId_incremente() {
		return id_incremente;
	}

	public static void setId_incremente(int id_incremente) {
		Commande.id_incremente = id_incremente;
	}

	int id;
	String date;
	int nombreDePersonnes;
	List<Plat>plat_commande;
	double prix_commande;
	
	public Commande(){
		id++;
		date = new java.util.Date().toString();
		nombreDePersonnes = 0;
		plat_commande = null;
		prix_commande = 0;
	}
	
	public Commande(int nombreDePersonnes,List<Plat>plat_commande){
		setId();
		setDate(new java.util.Date().toString());
		setNombreDePersonnes(nombreDePersonnes);
		
		double total = 0;
		for(Plat plat_iter : plat_commande){
			total += plat_iter.prix;
		}
		setPlat_commande(plat_commande);
		setPrix_commande(total);
	}


	public double getPrix_commande() {
		return prix_commande;
	}

	public void setPrix_commande(double prix_commande) {
		this.prix_commande = prix_commande;
	}

	public List<Plat> getPlat_commande() {
		return plat_commande;
	}

	public void setPlat_commande(List<Plat> plat_commande) {
		this.plat_commande = plat_commande;
	}

	public int getId() {
		return id;
	}

	public void setId() {
		this.id = id_incremente;
		id_incremente++;
	}
	
	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public int getNombreDePersonnes() {
		return nombreDePersonnes;
	}

	public void setNombreDePersonnes(int nombreDePersonnes) {
		this.nombreDePersonnes = nombreDePersonnes;
	}
}
