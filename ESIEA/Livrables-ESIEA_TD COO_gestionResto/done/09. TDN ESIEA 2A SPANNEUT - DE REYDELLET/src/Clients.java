import java.sql.SQLException;
import java.util.ArrayList;


public class Clients {
	private int id;
	private String name;
	private ArrayList<String> dates = new ArrayList<String>();
	private ArrayList<Integer> id_commandes = new ArrayList<Integer>();
	
	public Clients(String pname) throws SQLException {
		dbConnector db = new dbConnector();
		id = db.getLastId("clients")+1;
		name = pname;
		dates.add(Utiles.getDate());
	}
	
	public Clients(int pid, String pname) {
		id = pid;
		name = pname;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void showClient() {
		System.out.println("[+] Information sur le client n°"+this.id);
		System.out.println("\tCommandes: "+Utiles.listToString(this.id_commandes));
	}
	
	void save() {
		dbConnector db = new dbConnector();
		db.newClient(this.name);
	}
}
