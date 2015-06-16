package resto;
import java.util.Scanner;

public class Client {
	//Attributs
	String nomClient;
	String prenomClient;
	int nbreDeVisite;
	int ageClient;
	String adresseEMail;
	String statut = new String();
	int derniereAddition;
	int pourboire;
	int sommePrix;

	//Methodes
	public Client(){
		this("Inconnu", 0, 0, "Inconnu","Inconnu", "Inconnu", 0,0,0);		
	}

	public Client(String adresseEMail1, int ageClient1, int nbreDeVisite1, String nomClient1, String prenomClient1,  String statut1, int derniereAddition1, int pourboire1, int sommePrix1){
		nomClient = nomClient1;
		prenomClient = prenomClient1;
		nbreDeVisite = nbreDeVisite1;
		ageClient = ageClient1;
		adresseEMail = adresseEMail1;
		statut = statut1;
		pourboire = pourboire1 ;
		sommePrix = sommePrix1;
		derniereAddition = derniereAddition1;
	}

	void affichageFiche(){
		System.out.println();
		System.out.println("Nom du Client : "+nomClient);
		System.out.println("Prénom du Client : "+prenomClient);
		System.out.println("Age : "+ageClient);
		System.out.println("Adresse mail : "+adresseEMail);
		System.out.println("Statut : "+statut);
		System.out.println("Nombre de visites : "+nbreDeVisite);
		System.out.println("Somme de tous le pourboires donnés : "+pourboire);
		System.out.println("Prix du dernier repas : "+derniereAddition);
		System.out.println("Somme totale des dépenses : "+sommePrix);

		System.out.println();		
	}

	void ajoutVisite(){
		nbreDeVisite++;
		System.out.println("Le nombre de visite de "+nomClient+" est maintenant de "+nbreDeVisite);
		System.out.println();
	}
	
	void creationFicheClient(){
		//Variables
		String scanPrenom;
		Scanner scan = new Scanner(System.in);
		int onglet;

		//Ajout des renseignements
		System.out.println("Veuillez entrer les renseignements suivant :");
		System.out.print("Nom : ");
		scanPrenom = scan.next();
		nomClient = scanPrenom;
		System.out.print("Prenom : ");
		scanPrenom = scan.next();
		prenomClient = scanPrenom;
		System.out.print("Adresse mail : ");
		scanPrenom = scan.next();
		adresseEMail = scanPrenom;
		System.out.print("Age : ");
		onglet = scan.nextInt();
		ageClient = onglet;
		System.out.print("Statut : ");
		scanPrenom = scan.next();
		statut = scanPrenom;
		nbreDeVisite = 0;
		pourboire = 0;
		sommePrix = 0;
	}

	//Nom client
	public String getNomClient() {
		return nomClient;
	}
	public void setNomClient(String nomClient) {
		this.nomClient = nomClient;
	}
	//Prenom client
	public String getPrenomClient() {
		return prenomClient;
	}
	public void setPrenomClient(String prenomClient) {
		this.prenomClient = prenomClient;
	}
	//Nombre de Visite
	public int getNbreDeVisite() {
		return nbreDeVisite;
	}
	public void setNbreDeVisite(int nbreDeVisite) {
		this.nbreDeVisite = nbreDeVisite;
	}
	//Age du client
	public int getAgeClient() {
		return ageClient;
	}
	public void setAgeClient(int ageClient) {
		this.ageClient = ageClient;
	}
	//Adresse mail
	public String getAdresseEMail() {
		return adresseEMail;
	}
	public void setAdresseEMail(String adresseEMail) {
		this.adresseEMail = adresseEMail;
	}
	//Statut du client
	public String getStatut() {
		return statut;
	}
	public void setStatut(String statut) {
		this.statut = statut;
	}
	//Pourboire
	public int getPourboire() {
		return pourboire;
	}
	public void setPourboire(int pourboire) {
		this.pourboire = pourboire;
	}
	//Somme total des dépense du client
	public int getSommePrix() {
		return sommePrix;
	}
	public void setSommePrix(int sommePrix) {
		this.sommePrix = sommePrix;
	}
	//Prix du dernier repas
	public int getDerniereAddition() {
		return derniereAddition;
	}
	public void setDerniereAddition(int derniereAddition) {
		this.derniereAddition = derniereAddition;
	}

}