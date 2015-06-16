import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Chain chain = Chain.restore();
		boolean exit = false;
		Scanner sc = new Scanner(System.in);
		String line;

		System.out.println("Welcome");

		while (!exit) {
			System.out.println("Choose your action :\n1. Add a restaurant\t\t2. Add a customer\t\t3. Order for a client\t\t4. See betsellers" + "\n5. See best customers\t\t6. See best customers (ratio)\t7. Review chain info\t\t8. Save and Exit");
			line = sc.nextLine();
			int choice = 0;

			try {
				choice = Integer.parseInt(line);
			} catch (NumberFormatException e) {
				System.err.println("Please enter an Integer\n");
				continue;
			}

			switch (choice) {

			case 1:
				addRestaurant(chain, sc);
				break;

			case 2:
				addCustomer(chain, sc);
				break;

			case 3:
				try {
					order(chain, sc);
				} catch (NumberFormatException e) {
					System.err.println("Please enter an integer within range\n");
					continue;
				}
				break;

			case 4:
				try {
					seeBestsellers(chain, sc);
				} catch (NumberFormatException e) {
					System.err.println("Please enter an integer within range\n");
					continue;
				}
				break;

			case 5:
				try {
					seeBestCustomers(chain, sc);
				} catch (NumberFormatException e) {
					System.err.println("Please enter an integer within range\n");
					continue;
				}
				break;

			case 6:
				try {
					seeBestCustomersRatio(chain, sc);
				} catch (NumberFormatException e) {
					System.err.println("Please enter an integer within range\n");
					continue;
				}
				break;

			case 7:
				try {
					seeChainInfo(chain, sc);
				} catch (NumberFormatException e) {
					System.err.println("Please enter an integer within range\n");
					continue;
				}
				break;

			case 8:
				System.out.println("Saving changes and exiting");
				exit = true;
				break;

			default:
				break;

			}
		}

		sc.close();
		chain.save();

		System.out.println("\n\nSee you next time.");
	}

	private static void seeChainInfo(Chain chain, Scanner sc) {

		System.out.println("Select your level of detail : \n1. Restaurants\t\t2. Customers\t\t3. Orders");
		int choice;
		try {
			choice = Integer.parseInt(sc.nextLine());
		} catch (NumberFormatException e) {
			throw e;
		}

		if (choice > 3 || choice < 1)
			throw new NumberFormatException();

		System.out.println(chain.toString(choice));

	}

	private static void seeBestCustomers(Chain chain, Scanner sc) throws NumberFormatException {
		System.out.println("Please enter the name of the new restaurant : ");
		String name = sc.nextLine();
		Restaurant r = chain.get(name);
		int choice;

		if (r == null)
			System.err.println("This restaurant doesn't exist\n");
		else {
			System.out.println("Select the number of customers to display (0 to display all) : ");
			try {
				choice = Integer.parseInt(sc.nextLine());
			} catch (NumberFormatException e) {
				throw e;
			}

			r.bestCustomers(choice);
			System.out.println("");

		}
	}

	private static void seeBestCustomersRatio(Chain chain, Scanner sc) throws NumberFormatException {
		System.out.println("Please enter the name of the new restaurant : ");
		String name = sc.nextLine();
		Restaurant r = chain.get(name);
		int choice;

		if (r == null)
			System.err.println("This restaurant doesn't exist\n");
		else {
			System.out.println("Select the number of customers to display (0 to display all) : ");
			try {
				choice = Integer.parseInt(sc.nextLine());
			} catch (NumberFormatException e) {
				throw e;
			}

			r.bestCustomersRatio(choice);
			System.out.println("");

		}
	}

	private static void seeBestsellers(Chain chain, Scanner sc) throws NumberFormatException {
		System.out.println("Please enter the name of the new restaurant : ");
		String name = sc.nextLine();
		Restaurant r = chain.get(name);
		int choice;

		if (r == null)
			System.err.println("This restaurant doesn't exist\n");
		else {
			System.out.println("Select the number of products to display (0 to display all) : ");
			try {
				choice = Integer.parseInt(sc.nextLine());
			} catch (NumberFormatException e) {
				throw e;
			}

			r.bestSellers(choice);
			System.out.println("");

		}
	}

	public static void addRestaurant(Chain chain, Scanner sc) {
		System.out.println("Please enter the name of the new restaurant : ");
		String name = sc.nextLine();
		chain.add(new Restaurant(name));
	}

	public static void addCustomer(Chain chain, Scanner sc) {

		System.out.println("Please enter the name of the new customer : ");
		String res = sc.nextLine();
		System.out.println("Please enter the name of the customer's restaurant : ");
		String cn = sc.nextLine();
		Restaurant r = chain.get(res);
		if (r == null)
			System.err.println("This restaurant doesn't exist\n");
		else
			new Customer(cn, r);
	}

	public static void order(Chain chain, Scanner sc) throws NumberFormatException {

		System.out.println("Please enter the name of the restaurant : ");
		String res = sc.nextLine();
		System.out.println("Please enter the name of the customer : ");
		String cn = sc.nextLine();
		Restaurant r = chain.get(res);
		Customer c;
		Order o = new Order();
		int choice = 0;
		boolean exit = false;

		if (r == null)
			System.err.println("This restaurant doesn't exist");
		else {
			c = r.getCustomer(cn);
			if (c == null) {
				System.out.println("This customer isn't registered yet. Do you want to register him ?\n1. Yes\t2. No");
				try {
					choice = Integer.parseInt(sc.nextLine());
				} catch (NumberFormatException e) {
					throw e;
				}
				if (choice != 1)
					return;
			}

			while (!exit) {
				System.out.println("Select the product to add (-1 to leave) : ");
				for (int i = 0; i < 7; i++)
					System.out.print((i + 1) + ". " + OrderTypes.getFromOrdinal(i).toString() + "\t");
				System.out.println("");
				for (int i = 7; i < 13; i++)
					System.out.print((i + 1) + ". " + OrderTypes.getFromOrdinal(i).toString() + "\t\t");
				System.out.println("");

				try {
					choice = Integer.parseInt(sc.nextLine());
				} catch (NumberFormatException e) {
					throw e;
				}
				if (choice == -1)
					exit = true;
				else if (choice < 0 || choice > 13)
					throw new NumberFormatException();
				else {
					System.out.println("Select quantity :");
					int q = Integer.parseInt(sc.nextLine());
					if (q < 0)
						throw new NumberFormatException();
					o.addMeals(OrderTypes.getFromOrdinal(choice), q);
				}
			}

			c.getOrders().add(0, o);

		}
	}

}
