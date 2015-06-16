import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;


public class infoPanel {
	JPanel pan, panSearch, panInfo;
	JTextField inputSearchClient;
	JLabel info;
	String client = "";
	Clients Client = null;
	
	public infoPanel() {
		
	}
	
	public JPanel init() {
		pan = new JPanel();
		pan.setPreferredSize(new Dimension(600, 400));
		pan.add(searchPart());
		pan.add(infoPart());
		return pan;
	}
	
	private JPanel searchPart() {
		panSearch = new JPanel();
		panSearch.setPreferredSize(new Dimension(300, 100));
		panSearch.setBorder(BorderFactory.createTitledBorder("Recherche dernière commande"));
		JLabel labelSearchClient = new JLabel("Nom du client");
		inputSearchClient = new JTextField("");
		inputSearchClient.setPreferredSize(new Dimension(200, 20));
		JButton submit = new JButton("Rechercher");
		submit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					jbutton_submit_client();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		panSearch.add(labelSearchClient);
		panSearch.add(inputSearchClient);
		panSearch.add(submit);
		return panSearch;
	}
	
	private JPanel infoPart() {
		panInfo = new JPanel();
		panInfo.setPreferredSize(new Dimension(500, 400));
		panInfo.setBorder(BorderFactory.createTitledBorder("Résultat"));
		panInfo.setVisible(false);
		info = new JLabel("En attente...");
		panInfo.add(info);
		return panInfo;
	}
	
	private void showInfo(int id_client) throws NumberFormatException, SQLException {
		Commandes order = dbConnector.getLastOrderFromClient(id_client);
		if(order == null) {
			info.setText("Aucune commande pour l'instant");
		}
		else
			info.setText(order.show());
	}
	
	private void jbutton_submit_client() throws SQLException {
		client = inputSearchClient.getText();
		if(client.equals("")) {
			JOptionPane.showMessageDialog(null, "Le champ client ne peut être vide !", "Erreur", JOptionPane.ERROR_MESSAGE);
		}
		else {
			dbConnector db = new dbConnector();
			boolean res = db.clientExist(client);
			if(!res) {
				panInfo.setVisible(false);
				JOptionPane.showMessageDialog(null, "Le client n'a pas été trouvé !", "Erreur", JOptionPane.ERROR_MESSAGE);
			}
			else {
				Client = new Clients(client);
				int id_client = db.getClientId(client);
				showInfo(id_client);
				panInfo.setVisible(true);
			}
		}
	}
}
