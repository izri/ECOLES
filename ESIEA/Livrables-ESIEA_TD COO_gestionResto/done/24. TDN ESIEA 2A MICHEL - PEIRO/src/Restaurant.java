import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class Restaurant {

	private String name;
	private ArrayList<Customer> customers;
	private HashMap<OrderTypes, Integer> sales;

	public Restaurant(String name) {
		this.name = name;
		this.customers = new ArrayList<Customer>();
		this.sales = new HashMap<OrderTypes, Integer>();
	}

	public void addCustomer(Customer c) {

		if (exists(c)) {
			System.err.println("There is already a customer named " + c.getName() + " registered for restaurant " + name + ".\nCustomer was not registered");
			return;
		}

		customers.add(c);
	}

	public boolean exists(Customer c) {

		for (int i = 0; i < customers.size(); i++) {
			if (customers.get(i).getName() == c.getName())
				return true;
		}

		return false;
	}

	public void registerSales(OrderTypes type, Integer n) {

		if (this.sales.containsKey(type))
			this.sales.replace(type, this.sales.get(type) + n);
		else
			this.sales.put(type, n);
	}

	public void bestSellers(int top) {

		ArrayList<OrderTypes> o = new ArrayList<OrderTypes>();

		for (Entry<OrderTypes, Integer> e : sales.entrySet()) {

			if (o.size() == 0) {
				o.add(e.getKey());
				continue;
			}

			for (int i = 0; i < o.size(); i++)
				if (e.getValue() > sales.get(o.get(i))) {
					o.add(i, e.getKey());
					break;
				} else if (i == o.size() - 1) {
					o.add(e.getKey());
					break;
				}
		}

		System.out.println("Bestsellers for restaurant " + name + " : ");
		for (int i = 0; i < o.size(); i++) {
			System.out.println("\t" + (i + 1) + ". " + o.get(i).toString() + " (" + sales.get(o.get(i)) + ")");
			if (top == i + 1)
				break;
		}

	}

	public void bestCustomers(int top) {

		ArrayList<Customer> c = new ArrayList<Customer>();

		for (int i = 0; i < customers.size(); i++) {

			float expense = customers.get(i).getMoneySpent();

			if (c.size() == 0) {
				c.add(customers.get(i));
				continue;
			}

			for (int j = 0; j < c.size(); j++)
				if (expense > c.get(j).getMoneySpent()) {
					c.add(j, customers.get(i));
					break;
				} else if (j == c.size() - 1) {
					c.add(customers.get(i));
					break;
				}

		}

		System.out.println("Best custommers for restaurant " + name + ": ");
		for (int i = 0; i < c.size(); i++) {
			System.out.println("\t" + (i + 1) + ". " + c.get(i).getName() + " (" + c.get(i).getMoneySpent() + ")");
			if (top == i + 1)
				break;
		}

	}

	public void bestCustomersRatio(int top) {

		ArrayList<Customer> c = new ArrayList<Customer>();

		for (int i = 0; i < customers.size(); i++) {

			float expense = customers.get(i).getOrders().size() > 0 ? customers.get(i).getMoneySpent() / customers.get(i).getOrders().size() : 0;

			if (c.size() == 0) {
				c.add(customers.get(i));
				continue;
			}

			for (int j = 0; j < c.size(); j++)
				if (expense > (c.get(j).getOrders().size() > 0 ? c.get(j).getMoneySpent() / c.get(j).getOrders().size() : 0f)) {
					c.add(j, customers.get(i));
					break;
				} else if (j == c.size() - 1) {
					c.add(customers.get(i));
					break;
				}

		}

		System.out.println("Best custommers per dish for restaurant " + name + ": ");
		for (int i = 0; i < c.size(); i++) {
			System.out.println("\t" + (i + 1) + ". " + c.get(i).getName() + " (" + (c.get(i).getOrders().size() > 0 ? c.get(i).getMoneySpent() / c.get(i).getOrders().size() : 0) + ")");
			if (top == i + 1)
				break;
		}

	}

	public String toString(int details) {
		String s = "Restaurant Name : " + name + "\t\tNumber of customers : " + customers.size() + "\n";
		if (details > 0)
			for (int i = 0; i < customers.size(); i++)
				s = s.concat(customers.get(i).toString(details - 1).replaceAll("\n", "\n\t"));

		return s;
	}

	public String getName() {
		return name;
	}

	public ArrayList<Customer> getCustomers() {
		return customers;
	}

	public Customer getCustomer(String name) {

		for (int i = 0; i < customers.size(); i++) {
			if (customers.get(i).getName().matches(name))
				return customers.get(i);
		}

		return null;

	}

	public HashMap<OrderTypes, Integer> getSales() {
		return sales;
	}

}
