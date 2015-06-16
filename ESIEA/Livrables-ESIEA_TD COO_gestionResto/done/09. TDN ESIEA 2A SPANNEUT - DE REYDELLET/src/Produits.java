import java.sql.SQLException;


public class Produits {
	private int id;
	private String name;
	private int nbre;
	
	public Produits(String pname, int pnbre) throws SQLException {
		dbConnector db = new dbConnector();
		id = db.getProductId(pname);
		name = pname;
		nbre = pnbre; 
	}
	
	public int getId() {
		return this.id;
	}
	
	public int getNbre() {
		return this.nbre;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String productToString() {
		String str = "";
		str += this.id+""+this.nbre;
		return str;
	}
	
	public void showProduct() {
		System.out.println("\t "+this.name+" x "+this.nbre);
	}
	/*
	 * For GUI
	 */
	public String show() {
		String str = this.name+ " x "+ this.nbre + "<br />";
		return str;
	}
	
	
}
