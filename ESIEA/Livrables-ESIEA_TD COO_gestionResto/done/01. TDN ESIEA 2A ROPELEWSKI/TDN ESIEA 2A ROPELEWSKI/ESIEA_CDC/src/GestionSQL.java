import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class GestionSQL {
	static void insererNouveauClientSQL(Client client){
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);
	      
	      stmt = c.createStatement();
	      String sql = "INSERT INTO clients (ID,NOM,ADRESSE,EMAIL,PTSFIDELITE,DERNIERECOMMANDE,NBREDECOMMANDES,TOTALDEPENSES,HISTORIQUECOMMANDE) "
	      		+ "VALUES (NULL,'"+client.getNom()+"','"+client.getAdresse()+"','"+client.getEmail()+"','"+client.getPtFidelite()+"','"+
	    		  client.getDerniereCommande()+"','"+client.getNbreDeCommande()+"','"+client.totalDepenses+"','"+client.getHistoriqueCommande()+"');"; 
	      stmt.executeUpdate(sql); 
	      stmt.close(); 
	      
	      c.commit();
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }	
	}
	
	static void insererNouvelleCommandeSQL(Commande cmd){
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);
	      
	      
	      String sql_plat_name = "";
	      String sql_plat_prix = "";
	      String sql_plat_qtt  = "";
	      for(Plat plat_iter : cmd.getPlat_commande()){
	    	  sql_plat_name += plat_iter.getNom()+"|";
	    	  sql_plat_prix += String.valueOf(plat_iter.getPrix())+"|";
	    	  sql_plat_qtt += String.valueOf(plat_iter.getQuantite())+"|";
	      }
	      
	      stmt = c.createStatement();
	      String sql = "INSERT INTO commandes (ID,REPAS,QUANTITE,PRIX,TOTAL,NBPERSONNES,DATE) " +
	                   "VALUES (NULL, '"+sql_plat_name+"', '"+sql_plat_qtt+"', '"+sql_plat_prix+"', "+cmd.getPrix_commande()+", "+cmd.getNombreDePersonnes()+", '"+cmd.getDate()+"' );"; 
	      stmt.executeUpdate(sql); 
	      stmt.close(); 
	      
	      c.commit();
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static int selectIDCommandeSQL(){
		int id = 0;
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT COUNT(*) AS COUNT FROM commandes" );
	      
	      while(rs.next()) {
	    	   id = rs.getInt("COUNT");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }	
	    return id;
	}
	
	static int selectIDClientSQL(){
		int id = 0;
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT COUNT(*) AS COUNT FROM clients" );
	      
	      while(rs.next()) {
	    	   id = rs.getInt("COUNT");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }	
	    return id;
	}
	
	static Client clientFromSQL(int id){
	    Connection c = null;
	    Statement stmt = null;
	    Client client = new Client("empty","empty","empty");
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM clients WHERE id="+id );
	      while ( rs.next() ) {
	    	 client = new Client(
	    			 rs.getInt("id"),
	    			 rs.getString("nom"),
	    			 rs.getString("adresse"),
	    			 rs.getString("email"),
	    			 rs.getInt("PtsFidelite"),
	    			 rs.getInt("DerniereCommande"),
	    			 rs.getInt("NbreDeCommandes"),
	    			 rs.getDouble("TotalDepenses"),
	    			 rs.getString("HistoriqueCommande")
	    			 );
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	    
	    return client;
	}
	
	static void afficherCommande(String id){
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM commandes WHERE id="+id );
	      while ( rs.next() ) {
	         System.out.println("Commande n°"+rs.getString("id"));
	         System.out.println("\tLe : "+rs.getString("date"));
	         System.out.println("\tPour : "+rs.getString("nbpersonnes")+" personnes");

	         String[] plats_explode = rs.getString("repas").split("\\|");
	         String[] qtt_explode = rs.getString("quantite").split("\\|");
	         String[] prix_explode = rs.getString("prix").split("\\|");
	         for(int i=0; i<plats_explode.length;i++){
		        System.out.println("\t\t[+]Plat : "+plats_explode[i]+" ("+qtt_explode[i]+")");
		        System.out.println("\t\t[+]Prix : "+prix_explode[i]+"€");
	         }	     
	         
	         System.out.println("\tTotal : "+rs.getString("total")+"€\r\n");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void historiqueCommande(){
		System.out.println("La dernière commande enregistrée est :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM commandes ORDER BY ID desc limit 0,1" );
	      while ( rs.next() ) {
	         //Qtt
	         System.out.println("Commande n°"+rs.getString("id"));
	         System.out.println("\tLe : "+rs.getString("date"));
	         System.out.println("\tPour : "+rs.getString("nbpersonnes")+" personnes");

	         String[] plats_explode = rs.getString("repas").split("\\|");
	         String[] qtt_explode = rs.getString("quantite").split("\\|");
	         String[] prix_explode = rs.getString("prix").split("\\|");
	         for(int i=0; i<plats_explode.length;i++){
		        System.out.println("\t\t[+]Plat : "+plats_explode[i]+" ("+qtt_explode[i]+")");
		        System.out.println("\t\t[+]Prix : "+prix_explode[i]+"€");
	         }	     
	         
	         System.out.println("\tTotal : "+rs.getString("total")+"€\r\n");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void historiqueCommande(int nombre){
		System.out.println("Les "+nombre+" dernières commandes enregistrées sont :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM commandes ORDER BY ID desc limit 0,"+nombre );
	      while ( rs.next() ) {
	         //Qtt
	         System.out.println("Commande n°"+rs.getString("id"));
	         System.out.println("\tLe : "+rs.getString("date"));
	         System.out.println("\tPour : "+rs.getString("nbpersonnes")+" personnes");

	         String[] plats_explode = rs.getString("repas").split("\\|");
	         String[] qtt_explode = rs.getString("quantite").split("\\|");
	         String[] prix_explode = rs.getString("prix").split("\\|");
	         for(int i=0; i<plats_explode.length;i++){
		        System.out.println("\t\t[+]Plat : "+plats_explode[i]+" ("+qtt_explode[i]+")");
		        System.out.println("\t\t[+]Prix : "+prix_explode[i]+"€");
	         }	     
	         
	         System.out.println("\tTotal : "+rs.getString("total")+"€\r\n");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void historiqueCommande(int nombre, String column){
		System.out.println("Les "+nombre+" meilleures commandes triées par "+column+" sont :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM commandes ORDER BY "+column+" desc limit 0,"+nombre );
	      while ( rs.next() ) {
	         //Qtt
	         System.out.println("Commande n°"+rs.getString("id"));
	         System.out.println("\tLe : "+rs.getString("date"));
	         System.out.println("\tPour : "+rs.getString("nbpersonnes")+" personnes");

	         String[] plats_explode = rs.getString("repas").split("\\|");
	         String[] qtt_explode = rs.getString("quantite").split("\\|");
	         String[] prix_explode = rs.getString("prix").split("\\|");
	         for(int i=0; i<plats_explode.length;i++){
		        System.out.println("\t\t[+]Plat : "+plats_explode[i]+" ("+qtt_explode[i]+")");
		        System.out.println("\t\t[+]Prix : "+prix_explode[i]+"€");
	         }	     
	         
	         System.out.println("\tTotal : "+rs.getString("total")+"€\r\n");
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void updateClientSQL(Client regulier, Commande cmd){
		Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);
	      
	      stmt = c.createStatement();
	      double total = regulier.getTotalDepenses()+cmd.getPrix_commande();
	      String sql = "UPDATE clients SET TotalDepenses="+total+", "
	      		+ "NbreDeCommandes=NbreDeCommandes+1, "
	    		+ "PtsFidelite="+(regulier.getPtFidelite()+1)%10+","
	      		+ "HistoriqueCommande='"+regulier.getHistoriqueCommande()+cmd.getId()+"|' , "
	      		+ "DerniereCommande="+cmd.getId()+" WHERE ID="+regulier.id+";";
	      stmt.executeUpdate(sql);
	      c.commit();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	}
	
	
	static void historiqueClient(){
		System.out.println("Le dernier client enregistré est :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM clients ORDER BY ID desc limit 0,1" );
	      while ( rs.next() ) {
	         System.out.println("Client n°"+rs.getString("id"));
	         System.out.println("\tNom : "+rs.getString("nom"));
	         System.out.println("\tAdresse : "+rs.getString("adresse"));
	         System.out.println("\tEmail : "+rs.getString("email"));
	         System.out.println("\tNombre de commandes : "+rs.getString("NbreDeCommandes"));
	         System.out.println("\tListes des commandes : "+rs.getString("HistoriqueCommande").replace('|', ' '));
	         System.out.println("\tCarte Fidélité : "+rs.getInt("PtsFidelite")%10);
	         System.out.println("\tDépenses totales : "+rs.getString("TotalDepenses"));
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void historiqueClient(int nombre){
		System.out.println("Les derniers clients enregistrés sont :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM clients ORDER BY ID desc limit 0,"+nombre );
	      while ( rs.next() ) {
	         System.out.println("Client n°"+rs.getString("id"));
	         System.out.println("\tNom : "+rs.getString("nom"));
	         System.out.println("\tAdresse : "+rs.getString("adresse"));
	         System.out.println("\tEmail : "+rs.getString("email"));
	         System.out.println("\tNombre de commandes : "+rs.getString("NbreDeCommandes"));
	         System.out.println("\tListes des commandes : "+rs.getString("HistoriqueCommande").replace('|', ' '));
	         System.out.println("\tCarte Fidélité : "+rs.getInt("PtsFidelite")%10);
	         System.out.println("\tDépenses totales : "+rs.getString("TotalDepenses"));
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void historiqueClient(int nombre, String categorie){
		System.out.println("Les meilleurs clients dans la catégorie '"+categorie+"' sont :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT * FROM clients ORDER BY "+categorie+" desc limit 0,"+nombre );
	      while ( rs.next() ) {
	         System.out.println("Client n°"+rs.getString("id"));
	         System.out.println("\tNom : "+rs.getString("nom"));
	         System.out.println("\tAdresse : "+rs.getString("adresse"));
	         System.out.println("\tEmail : "+rs.getString("email"));
	         System.out.println("\tNombre de commandes : "+rs.getString("NbreDeCommandes"));
	         System.out.println("\tListes des commandes : "+rs.getString("HistoriqueCommande").replace('|', ' '));
	         System.out.println("\tCarte Fidélité : "+rs.getInt("PtsFidelite")%10);
	         System.out.println("\tDépenses totales : "+rs.getString("TotalDepenses"));
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
	  }
	
	static void commandesDuClient(int id){
		System.out.println("Les commandes du client sont :");
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT HistoriqueCommande FROM clients WHERE id="+id );
	      while ( rs.next() ) {
	    	  String[] all_cmd = rs.getString("HistoriqueCommande").split("\\|");
		      for(int i=0; i<all_cmd.length;i++){
		    	  afficherCommande(all_cmd[i]);
		      }
	      }
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
		
	}
	
	static void meilleursVentes(){
	    Connection c = null;
	    Statement stmt = null;
	    try {
	      Class.forName("org.sqlite.JDBC");
	      c = DriverManager.getConnection("jdbc:sqlite:gestion.sqlite");
	      c.setAutoCommit(false);

	      stmt = c.createStatement();
	      ResultSet rs = stmt.executeQuery( "SELECT repas,quantite FROM commandes");
	      String[] repas = {"pizza","dessert","boisson","plat du jour","plat végétarien"};
	      int[] quantite = {0,0,0,0,0};
	      
	      while ( rs.next() ) {
	    	  String[] all_repas = rs.getString("repas").split("\\|");
	    	  String[] all_qtt = rs.getString("quantite").split("\\|");
	    	  	  
	    	 for(int i=0; i<all_repas.length; i++){
	    		 for(int j=0;j<repas.length;j++){ 
	    			 if(repas[j].equals(all_repas[i].toLowerCase())){
	    				 quantite[j] += Integer.parseInt(all_qtt[i]);
	    			 }
	    		 }
	    	 }
		      
	      }
	      //Little bubblesort
	      for(int i=0; i<quantite.length; i++){
	    	  for(int j=0;j<quantite.length-1;j++){ 
	    		  if(quantite[j]<quantite[j+1]){
	    			 int tmp = quantite[j];
	    			 quantite[j] = quantite[j+1];
	    			 quantite[j+1] = tmp;
	    			 
	    			 String tmpo = repas[j];
	    			 repas[j] = repas[j+1];
	    			 repas[j+1] = tmpo;
	    		  }
	    	  }
	      }
	      
	      System.out.println("\n[Nom du plat]=>[Nombre de ventes]");
	      for(int i=0;i<quantite.length;i++){
	    	  System.out.println(repas[i]+" => "+quantite[i]);
	      }
	      System.out.println();
	      rs.close();
	      stmt.close(); 
	      c.close();
	    } 
	    catch ( Exception e ) {
	      System.err.println( e.getClass().getName() + ": " + e.getMessage() );
	      System.exit(0);
	    }
		
	}
}
