import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Chain extends ArrayList<Restaurant> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	public boolean add(Restaurant e) {
		if (get(e.getName()) != null) {
			System.err.println("There already is a restaurant with this name.\nRestaurant was not added.");
			return false;
		} else {
			super.add(e);
			return true;
		}
	}

	public static Chain restore() {

		File file = new File("save.res");
		String line;

		Chain chain = new Chain();
		Restaurant r = new Restaurant("");
		Customer c = new Customer("", r);
		Order o = new Order();
		OrderTypes t;

		if (file.exists()) {

			try {
				BufferedReader buffer = new BufferedReader(new FileReader(file));

				while ((line = buffer.readLine()) != null) {

					if (line.startsWith("*"))
						continue;
					else if (line.startsWith("\t\t\t")) {
						t = OrderTypes.getFromOrdinal(Integer.parseInt(line.substring(3, line.indexOf(' '))));
						int n = Integer.parseInt(line.substring(line.indexOf(' ') + 1));
						o.addMeals(t, n);
						r.registerSales(t, n);
					} else if (line.startsWith("\t\t")) {
						o = new Order();
						c.getOrders().add(0, o);
					} else if (line.startsWith("\t")) {
						c = new Customer(line.substring(1), r);
					} else {
						r = new Restaurant(line);
						chain.add(r);
					}

				}

				buffer.close();

			} catch (IOException e) {
				System.err.println("Couldn't access file");
				System.exit(-1);
			}

		}

		return chain;

	}

	public void save() {

		File file = new File("save.res");

		try {
			if (!file.createNewFile()) {
				if (!file.delete()) {
					System.err.println("Couldn't overwrite save file");
					System.exit(1);
				}

				file.createNewFile();
			}
		} catch (IOException e) {
			System.err.println("Couldn't create save file");
			System.exit(1);
		}

		try {

			BufferedWriter buffer = new BufferedWriter(new FileWriter(file));

			for (int i = 0; i < this.size(); i++) {

				buffer.write(this.get(i).getName());
				for (int j = 0; j < this.get(i).getCustomers().size(); j++) {
					buffer.write(this.get(i).getCustomers().get(j).save().replace("\n", "\n\t"));
				}

				buffer.write("\n");

			}

			buffer.close();

		} catch (IOException e) {
			System.err.println("Couldn't access file");
			System.exit(1);
		}

	}

	public Restaurant get(String name) {
		for (int i = 0; i < this.size(); i++) {
			if (name.matches(this.get(i).getName()))
				return this.get(i);
		}

		return null;
	}

	public String toString(int details) {

		String str = new String();

		if (details > 0)
			for (int i = 0; i < this.size(); i++)
				str = str.concat(this.get(i).toString(details - 1).concat("\n"));

		return str;

	}

}
