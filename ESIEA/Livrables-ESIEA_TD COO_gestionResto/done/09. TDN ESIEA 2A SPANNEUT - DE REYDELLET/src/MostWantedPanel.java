import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;


public class MostWantedPanel extends JPanel{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Object[][] donnees = null;
	private JTable tableau = null;
	private String[] entetes = {"Nom", "Quantité"};
	
	
	
	public MostWantedPanel() {
		
		try {
			getMostWanted();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 
        
 
        tableau = new JTable(donnees, entetes);
        JButton refresh = new JButton("Rafraichir");
        refresh.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent arg0) {
				try {
					
					getMostWanted();
					tableau.repaint();	
					//tableau = new JTable(donnees, entetes);
					//System.out.println("called");
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
        refresh.setVisible(false);
        add(refresh);
        add(new JScrollPane(tableau));
	}
	
	private void getMostWanted() throws SQLException {
		ArrayList<Produits> map = dbConnector.getMostWanted();
		
		donnees = new Object[][]{
				{map.get(0).getName(), map.get(0).getNbre()},
				{map.get(1).getName(), map.get(1).getNbre()},
				{map.get(2).getName(), map.get(2).getNbre()}
		};

	}
	
}
