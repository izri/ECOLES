import java.sql.SQLException;
import java.util.ArrayList;


public class Commandes {
	private int id;
	private int id_client;
	private ArrayList<Produits> products_list;
	private int price;
	
	/*
	 * Crée une nouvelle commande
	 */
	public Commandes(int id_client, ArrayList<Produits> products_list) throws SQLException {
		dbConnector db = new dbConnector();
		this.id = db.getLastId("commandes")+1;
		this.id_client = id_client;
		this.products_list = products_list;
	}
	
	/*
	 * Charge une commande
	 */
	public Commandes(int id, int id_client, ArrayList<Produits> products_list, int price) throws SQLException {
		this.id = id;
		this.id_client = id_client;
		this.products_list = products_list;
		this.price = price;
	}
	
	private void incrementProducts() throws SQLException {
		dbConnector db = new dbConnector();
		for(Produits products : this.products_list) {
			db.incrementProduct(products.getName(), products.getNbre());
		}
	}
	
	public void saveOrder() throws SQLException {
		dbConnector db = new dbConnector();
		db.saveOrder(this.id_client, listToString(), this.calculatePrice());
		incrementProducts();
	}
	
	
	/*
	 * Converti le tableau contenant les produits (id_produit + quantité) en string ("id_produit:quantite, id_produit:quantite, ...")
	 */
	public String listToString() {
		String str = "";
		for(int i = 0; i < this.products_list.size()-1; i++) {
			str += this.products_list.get(i).getId()+":"+this.products_list.get(i).getNbre()+",";
		}
		str += this.products_list.get(products_list.size()-1).getId() + ":" + this.products_list.get(products_list.size()-1).getNbre();
		return str;
	}
	
	public int calculatePrice() throws SQLException {
		dbConnector db = new dbConnector();
		int price = 0;
		for(int i = 0; i < products_list.size(); i++) {
			price += db.getProductPrice(products_list.get(i).getName())*products_list.get(i).getNbre();
			//System.out.println(db.getProductPrice(products_list.get(i).getName())+" * "+products_list.get(i).getNbre());
		}
		return price;
	}
	
	public int getPrice() {
		return this.price;
	}
	
	public void showOrder() throws SQLException {
		System.out.println("*** Commande n°" + this.id + " ***");
		for(int i = 0; i < this.products_list.size(); i++) {
			this.products_list.get(i).showProduct();
		}
		System.out.println("Prix total de la commande: "+this.calculatePrice());
	}
	
	/*
	 * For GUI
	 */
	public String show() {
		String str = "<html>";
		str += "<p>Commande n°"+this.id+"</p><br />";
		str += "<p>";
		for(int i = 0; i < this.products_list.size(); i++) {
			str += this.products_list.get(i).show();
		}
		str += "</html>";
		return str;
	}
}
