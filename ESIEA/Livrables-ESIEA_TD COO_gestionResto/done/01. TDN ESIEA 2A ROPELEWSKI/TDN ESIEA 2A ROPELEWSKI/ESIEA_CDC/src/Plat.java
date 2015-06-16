
public class Plat extends Commande {
	int quantite;
	double prix;
	String nom;
	
	public Plat(){
		super();
		quantite = 0;
		prix = 12.5;
		nom = "Inconnu";
	}
	
	public Plat(int quantite, String nom){
		switch(nom.toLowerCase()){
			case "pizza":
				this.prix = 8;
				break;
			case "boisson":
				this.prix = 3.5;
				break;
			case "dessert":
				this.prix = 4.90;
				break;
			case "plat du jour":
				this.prix = 13.5;
				break;
			case "plat végétarien":
				this.prix = 18.5;
				break;
		}
		this.nom = Character.toString(nom.charAt(0)).toUpperCase() + nom.substring(1).toLowerCase();
		this.quantite = quantite;
		this.prix = quantite*this.prix;
	}

	public int getQuantite() {
		return quantite;
	}

	public void setQuantite(int quantite) {
		this.quantite = quantite;
	}

	public double getPrix() {
		return prix;
	}

	public void setPrix(double prix) {
		this.prix = prix;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}
	
}
