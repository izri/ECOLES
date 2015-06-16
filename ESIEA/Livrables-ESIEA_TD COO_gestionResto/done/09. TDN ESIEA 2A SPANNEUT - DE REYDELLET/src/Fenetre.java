import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

public class Fenetre {
	public Fenetre() {
		JFrame fenetre = new JFrame();
		fenetre.setTitle("Gestion restaurant");
		fenetre.setSize(800, 600);
		fenetre.setLocationRelativeTo(null);
		fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fenetre.add(getOnglets());
		fenetre.setVisible(true);
	}
	
	private JTabbedPane getOnglets() {
		JTabbedPane onglets = new JTabbedPane();
		onglets.addTab("Nouvelle commande", null, newOrder(), null);
		onglets.addTab("Info commande", null, showOrder(), null);
		onglets.addTab("Meilleures ventes", null, showMostWanted(), null);
		
		return onglets;
	}
	
	private JPanel newOrder() {
		JPanel pan = new OrderPanel().init();
		return pan;
	}
	
	private JPanel showOrder() {
		JPanel pan = new infoPanel().init();
		
		return pan;
	}
	
	private JPanel showMostWanted() {
		return new MostWantedPanel();
	}
}
