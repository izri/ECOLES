
public class Client {
	//Nom,Adresse,Email,PtFidelite,DerniereCommande,NbreDeCommande,TotalDepense,HistoriqueCommande(id|id|)
	public static int id_incremente = 0;
	public static int getId_incremente() {
		return id_incremente;
	}

	public static void setId_incremente(int id_incremente) {
		Client.id_incremente = id_incremente;
	}

	int id;
	String nom;
	String adresse;
	String email;
	int ptFidelite;
	int derniereCommande;
	int nbreDeCommande;
	double totalDepenses;
	String historiqueCommande;
	
	public Client(String nom, String adresse, String email){
		setId();
		setNom(nom);
		setAdresse(adresse);
		setEmail(email);
		setPtFidelite(0);
		setDerniereCommande(-1);
		setNbreDeCommande(0);
		setTotalDepenses(0.0); 
		setHistoriqueCommande("");
	}
	public Client(int id, String nom, String adresse, String email,int ptFidelite, int derniereCommande, int nbreDeCommande, double totalDepenses, String historiqueCommande){
		setId(id);
		setNom(nom);
		setAdresse(adresse);
		setEmail(email);
		setPtFidelite(ptFidelite);
		setDerniereCommande(derniereCommande);
		setNbreDeCommande(nbreDeCommande);
		setTotalDepenses(totalDepenses);
		setHistoriqueCommande(historiqueCommande);
	}

	public int getId() {
		return id;
	}

	public void setId() {
		this.id = id_incremente;
		id_incremente++;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getAdresse() {
		return adresse;
	}

	public void setAdresse(String adresse) {
		this.adresse = adresse;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public int getPtFidelite() {
		return ptFidelite;
	}

	public void setPtFidelite(int ptFidelite) {
		this.ptFidelite = ptFidelite;
	}

	public int getDerniereCommande() {
		return derniereCommande;
	}

	public void setDerniereCommande(int derniereCommande) {
		this.derniereCommande = derniereCommande;
	}

	public int getNbreDeCommande() {
		return nbreDeCommande;
	}

	public void setNbreDeCommande(int nbreDeCommande) {
		this.nbreDeCommande = nbreDeCommande;
	}

	public double getTotalDepenses() {
		return totalDepenses;
	}

	public void setTotalDepenses(double totalDepenses) {
		this.totalDepenses = totalDepenses;
	}

	public String getHistoriqueCommande() {
		return historiqueCommande;
	}

	public void setHistoriqueCommande(String historiqueCommande) {
		this.historiqueCommande = historiqueCommande;
	}
	
}
