import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;


public class OrderPanel{
	private Clients Client = null;
	private Commandes Order = null;
	private String products[] = {"pizza", "boeuf", "poulet", "coca", "sprite", "evian", "glace", "chocolat", "salade"};
	private HashMap<String, Integer> order = new HashMap<String, Integer>();
	private JPanel pan, panName, panProduct, panInfo, panFooter;
	private JLabel labelClientName, info;
	private JTextField inputClientName;
	private String client = "";
	private JLabel infoOrder = new JLabel("<html><br /><br /><center>La commande est vide</center></html>");
	
	public OrderPanel() {
		
	}
	
	public JPanel init() {
		initHashMap();
		pan = new JPanel();
		pan.setPreferredSize(new Dimension(600, 400));
		
		panName = namePart();
		panProduct = productPart();
		panInfo = infoPart();
		panFooter = footer();
		pan.add(panName);
		pan.add(panProduct);
		pan.add(panInfo);
		pan.add(panFooter);
		
		return pan;
	}
	
	private void initHashMap() {
		for(String product : products) {
			order.put(product, 0);
		}
	}
	
	private void jbutton_action(ActionEvent e) {
		if(client.equals("")) {
			JOptionPane.showMessageDialog(null, "Veuillez sélectionner un client svp !", "Erreur", JOptionPane.ERROR_MESSAGE);
		} else {
			order.put(e.getActionCommand(), order.get(e.getActionCommand())+1);
			infoOrder.setText(order.toString()); 	
		}	
	}
	
	private void clean() {
		Client = null;
		Order = null;
		client = "";
		order = new HashMap<String, Integer>();
		initHashMap();
		info.setText("Client: N/A");
		infoOrder.setText("");
	}
	
	private void jbutton_reset() {
		clean();
	}
	
	private void jbutton_set_client() {
		dbConnector db = new dbConnector();
		String name = inputClientName.getText();
		try {
			boolean res = db.clientExist(name);
			client = name;
			if(res == true) {
				Client = db.loadClient(client);
			    JOptionPane.showMessageDialog(null, "Le client " + name + " a été chargé !", "Information", JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				Client = new Clients(client);
				Client.save();
				JOptionPane.showMessageDialog(null, "Le client " + name + " a été créé !", "Information", JOptionPane.INFORMATION_MESSAGE);
			}
			info.setText( (client.equals("")) ? "<html>Client: N/A</html>" : "<html>Client: "+client+"</html>" );
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void jbutton_save_order(ActionEvent e) throws SQLException {
		if(client.equals("")) {
			JOptionPane.showMessageDialog(null, "Veuillez sélectionner un client svp !", "Erreur", JOptionPane.ERROR_MESSAGE);
		}
		else {
			ArrayList<Produits> products = new ArrayList<Produits>();
			for(Entry<String, Integer> entry : order.entrySet() ) {
				if(entry.getValue() > 0)
					products.add(new Produits(entry.getKey(), entry.getValue()));
			}
			Order = new Commandes(Client.getId(), products);
			Order.saveOrder();
			JOptionPane.showMessageDialog(null, "La commande a bien été créée !", "Commande créée", JOptionPane.INFORMATION_MESSAGE);
			clean();
		}
	}
	
	private JPanel initButtons(JPanel pan) {
		ArrayList<JButton> buttons = new ArrayList<JButton>();
		for(String product : products) {
			buttons.add(new JButton(product));	
		}
		for(JButton button : buttons) {
			button.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					jbutton_action(e);
				}
			});
			pan.add(button);
		}
		return pan;
	}
	
	private JPanel namePart() {
		JPanel panName = new JPanel();
		panName.setPreferredSize(new Dimension(300, 100));
		panName.setBorder(BorderFactory.createTitledBorder("Nom du client"));
		labelClientName = new JLabel("Nom client ");
		
		inputClientName = new JTextField("test");
		//inputClientName.setFont(new Font("Arial", Font.BOLD, 14));
		inputClientName.setPreferredSize(new Dimension(100, 20));
		JButton select = new JButton("Sélectionner");
		select.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent arg0) {
				jbutton_set_client();
			}
		});
		
		panName.add(labelClientName);
		panName.add(inputClientName);
		panName.add(select);
		return panName;
	}
	
	private JPanel productPart() {
		panProduct = new JPanel();
		panProduct.setPreferredSize(new Dimension(400, 300));
		panProduct.setBorder(BorderFactory.createTitledBorder("Ajouter produits"));
		panProduct.setLayout(new GridLayout(3, 3));
		panProduct = initButtons(panProduct);
		return panProduct;
	}
	
	private JPanel infoPart() {
		panInfo = new JPanel();
		info = new JLabel();
		info.setText( (client.equals("")) ? "<html>Client: N/A</html>" : "<html>Client: "+client+"</html>" );
		
		panInfo.setPreferredSize(new Dimension(800, 200));
		panInfo.setBorder(BorderFactory.createTitledBorder("Commande"));
		panInfo.add(info);
		panInfo.add(infoOrder);
		return panInfo;
	}
	
	private JPanel footer() {
		panFooter = new JPanel();
		JButton save = new JButton("Enregister");
		save.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					jbutton_save_order(e);
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		});
		JButton reset = new JButton("Annuler");
		reset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				jbutton_reset();
			}
		});
		panFooter.setPreferredSize(new Dimension(400, 50));
		panFooter.add(save);
		panFooter.add(reset);
		return panFooter;
	}
	
}
