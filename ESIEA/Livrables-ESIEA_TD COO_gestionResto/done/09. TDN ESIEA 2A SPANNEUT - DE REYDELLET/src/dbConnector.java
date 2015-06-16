import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;




public class dbConnector {
	
	/*
	 * FONCTIONS POUR LES CLIENTS
	 */
	
	
	
	/*
	 * Charge un client à partir de son nom
	 */
	public Clients loadClient(String name) throws SQLException {
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT id FROM clients WHERE nom = '"+name+"'");
		//ResultSet rs = getInfoUser(name);
		Clients client = new Clients(rs.getInt("id"), name);
		sql.close();
		rs.close();
		return client;
	}
	
	/*
	 * Retourne l'id d'un client à partir de son nom
	 */
	public int getClientId(String name) throws SQLException {
		int id = 0;
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT id FROM clients WHERE nom = '"+name+"'");
		//ResultSet rs = getInfoUser(name);
		id = rs.getInt("id");
		sql.close();
		rs.close();
		return id;
	}
	
	
	/*
	 * Retourne vrai si le client est déjà dans la bdd, faux sinon
	 */
	public boolean clientExist(String name) throws SQLException {
		boolean flag = false;
		SQLite sql = new SQLite();
		ResultSet rs = null;
		rs = sql.executeSelect("SELECT COUNT(id) as nb FROM clients WHERE nom = '"+name+"';");
		flag = (rs.getInt("nb") > 0) ? true : false;
		sql.close();
		rs.close();
		return flag;
	}
	
	/*
	 * Insère un nouveau client dans la base de données
	 */
	public void newClient(String pname) {
		SQLite sql = new SQLite();
		sql.executeInsert("INSERT INTO clients (id, nom) VALUES (NULL, '"+ pname +"')");
		System.out.println("[+] "+ pname + " saved !");
		sql.close();	
	}
	
	
	
	/*
	 * FONCTIONS POUR LES PRODUITS
	 */
	
	
	
	/*
	 * Retourne les info concernant un produit à partir de son nom
	 */
	
	
	public int getProductId(String name) throws SQLException {
		int id;
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT * FROM produits WHERE nom = '"+name+"';");
		id = rs.getInt("id");
		sql.close();
		rs.close();
		return id;
	}
	
	public int getProductPrice(String name) throws SQLException {
		int price;
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT prix FROM produits WHERE nom = '"+name+"';");
		price = rs.getInt("prix");
		sql.close();
		rs.close();
		return price;
	}
	
	/*
	 * Vrai si le nom du produit existe dans la bdd, faux sinon
	 */
	public boolean existProduct(String name) throws SQLException{
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT COUNT(id) as nb FROM produits WHERE nom = '"+ name +"'");
		if(rs.getInt("nb") == 1) {
			rs.close();
			sql.close();
			return true;
		}
		else {
			rs.close();
			sql.close();
			//System.out.println("Res: "+rs.getInt("nb"));
			
			return false;
		}
		
	}
	
	public String getProductName(int id) throws SQLException {
		SQLite sql = new SQLite();
		String name = "";
		ResultSet rs = sql.executeSelect("SELECT nom FROM produits WHERE id = "+ id);
		name = rs.getString("nom");
		rs.close();
		sql.close();
		return name;
	}
	
	public void incrementProduct(String name, int nber) throws SQLException {
		SQLite sql = new SQLite();
		sql.executeUpdate("UPDATE produits SET quantite = quantite+"+nber+" WHERE nom = '"+ name +"'");
		sql.close();
	}
	
	/*
	 * FONCTIONS POUR LES COMMANDES
	 */
	
	/*
	 * Sauvegarde une commande dans la base de données
	 */
	public void saveOrder(int id_client, String products_list, int total_price) throws SQLException {
		SQLite sql = new SQLite();
		//p = connect.prepareStatement("INSERT INTO commandes (id, id_client, produits_liste, prix_total) VALUES ('', ?, ?, ?)");
		sql.executeInsert("INSERT INTO commandes (id, id_client, produits_liste, prix_total) VALUES (NULL, '"+ id_client +"' ,'"+ products_list +"', '"+ total_price +"')");
		sql.close();
	}
	
	/*
	 * Retourne sous forme de tableau de Commandes toutes les commandes d'un client
	 */
	public ArrayList<Commandes> getAllOrdersFromClient(int id_client) throws NumberFormatException, SQLException {
		ArrayList<Commandes> orders = new ArrayList<Commandes>();
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT * FROM commandes WHERE id_client = "+id_client);
		while(rs.next()) {
			orders.add( new Commandes( rs.getInt("id"), rs.getInt("id_client"), Utiles.productsStringToList(rs.getString("produits_liste")), rs.getInt("prix_total") ) );
		}
		rs.close();
		sql.close();
		return orders;
	}
	
	/*
	 * Retourne la dernière commande d'un client
	 */
	public static Commandes getLastOrderFromClient(int id_client) throws NumberFormatException, SQLException {
		Commandes order = null;
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT COUNT(id) as nb FROM commandes WHERE id_client = "+id_client);
		if(rs.getInt("nb") > 0) {
			rs = sql.executeSelect("SELECT * FROM commandes WHERE id_client = "+ id_client + " ORDER BY id DESC LIMIT 1");
			order = new Commandes( rs.getInt("id"), rs.getInt("id_client"), Utiles.productsStringToList(rs.getString("produits_liste")), rs.getInt("prix_total") );
		}
		rs.close();
		sql.close();
		return order;
	}
	
	
	/*
	 * AUTRES FONCTIONS UTILES
	 */
	
	
	/*
	 * Retourne le dernier id d'un table
	 */
	
	public int getLastId(String table) throws SQLException {
		SQLite sql = new SQLite();
		ResultSet rs = null;
		int id;
		rs = sql.executeSelect("SELECT COUNT(id) as nb FROM "+table);
		if(rs.getInt("nb") == 0) {
			rs.close();
			sql.close();
			return 0;
		}
		rs = sql.executeSelect("SELECT id FROM "+table+" ORDER BY id DESC");
		id = rs.getInt("id");
		rs.close();
		sql.close();
		return id;
	}
	

	/*
	 * On met à jour la date à laquelle le client est venu 
	 */
	public boolean saveDate(int pid) {
		String date = Utiles.getDate();
		SQLite sql = new SQLite();
		if(sql.executeUpdate("UPDATE clients SET dates = dates || ',"+ date +"' WHERE id = "+ pid) > 0) {
			sql.close();
			return true;
		}
			
		else {
			sql.close();
			return false;
		}
			

	}
	
	/*
	 * On récupère les articles les plus vendus
	 */
	public static ArrayList<Produits> getMostWanted() throws SQLException {
		ArrayList<Produits> most = new ArrayList<Produits>();
		SQLite sql = new SQLite();
		ResultSet rs = sql.executeSelect("SELECT nom, quantite FROM produits ORDER BY quantite DESC");
		while(rs.next()){
			most.add(new Produits(rs.getString("nom"), rs.getInt("quantite")));
			//System.out.println("Nom: "+rs.getString("nom") + " Qte: "+rs.getInt("quantite"));
		}
		rs.close();
		sql.close();
		return most;
	}
	
}
