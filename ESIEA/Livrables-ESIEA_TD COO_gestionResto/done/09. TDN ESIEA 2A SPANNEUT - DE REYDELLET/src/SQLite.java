import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JOptionPane;


public class SQLite {
	private Connection connect = null;
	private Statement smt = null;
	
	static {
        try {
        	Class.forName("org.sqlite.JDBC").newInstance();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
	
	
	public SQLite() {
		try
	    {
	      connect = DriverManager.getConnection("jdbc:sqlite:resto.sqlite");
	      smt = connect.createStatement();
	    }
	    catch(SQLException e)
	    {
	      // if the error message is "out of memory", 
	      // it probably means no database file is found
	    	JOptionPane.showMessageDialog(null, e.getCause(), "Erreur", JOptionPane.ERROR_MESSAGE);
	        System.err.println(e.getMessage());
	    }
	    
	}
	
	public boolean executeInsert(String query) {
        try {
            return smt.execute(query);
        } catch (SQLException e) {
            System.err.println(query);
            e.printStackTrace();
            return false;
        }
    }
	
	public int executeUpdate(String query) {
        try {
            return smt.executeUpdate(query);
        } catch (SQLException e) {
        	e.printStackTrace();
            System.err.println(e.getSQLState());
            System.err.println(e.getMessage());
            return -1;
        }
    }
	
	public ResultSet executeSelect(String query) {
        try {
            return smt.executeQuery(query);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
	
	public void close() {
	    try {

	      if (smt != null) {
	        smt.close();
	      }
	      
	      if (connect != null) {
	        connect.close();
	      }
	    } catch (Exception e) {

	    }
	  }
}
