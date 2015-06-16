import java.sql.Date;
import java.sql.SQLException;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Locale;


public class Utiles {
	public static String listToString(ArrayList<Integer> list) {
		String str = "";
		for(int i = 0; i < list.size(); i++) {
			if(i == list.size()-1)
				str += list.get(i);
			else
				str += list.get(i)+",";
		}
		return str;
	}
	
	public static ArrayList<Integer> stringToList(String str) {
		ArrayList<Integer> array = new ArrayList<Integer>();
		String parts[] = str.split(",");
		for(int i = 0; i < parts.length;  i++) {
			array.add(Integer.parseInt(parts[i]));
		}
		return array;
	}
		
	public static String getDate() {
		Date maDate = new java.sql.Date(System.currentTimeMillis());
		Locale locale = Locale.getDefault();
		DateFormat dateFormat = DateFormat.getDateInstance(DateFormat.SHORT, locale);
		String date = (dateFormat.format(maDate));
		return date;
	}

	public static ArrayList<Produits> productsStringToList(String s_products) throws NumberFormatException, SQLException {
		dbConnector db = new dbConnector();
		ArrayList<Produits> a_order = new ArrayList<Produits>();
		String parts[] = s_products.split(",");
		String parts2[];
		for(int i = 0; i < parts.length; i++) {
			parts2 = parts[i].split(":");
			a_order.add(new Produits(db.getProductName(Integer.parseInt(parts2[0])), Integer.parseInt(parts2[1])));
		}
		return a_order;
	}


}
