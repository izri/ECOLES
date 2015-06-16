import java.util.ArrayList;
import java.util.Map.Entry;

public class Customer {

	private String name;
	private ArrayList<Order> orders;
	private Restaurant restaurant;

	public Customer(String name, Restaurant restaurant, OrderTypes... firstOrder) {
		this.name = name;
		this.restaurant = restaurant;
		this.restaurant.addCustomer(this);
		this.orders = new ArrayList<Order>();
		if (firstOrder.length != 0)
			this.order(firstOrder);
	}

	public Customer order(OrderTypes... types) {

		orders.add(0, new Order());
		orders.get(0).addMeals(types);
		for (Entry<OrderTypes, Integer> e : orders.get(0).getMeals().entrySet()) {
			restaurant.registerSales(e.getKey(), e.getValue());
		}
		return this;

	}

	public int getNumberOfOrders() {
		return orders.size();
	}

	public String toString(int details) {

		String str = "\nThe customer " + name + " has orderded " + orders.size() + " meal" + (orders.size() > 1 ? "s" : "") + ".\n";

		if (details > 0)
			for (int i = orders.size() - 1; i >= 0; i--)
				str = str.concat("\n\tOrder n°" + (orders.size() - i) + ":" + orders.get(i).toString().replaceAll("\n", "\n\t"));

		str = str.replaceAll("Order n°" + orders.size(), "Last Order");

		return str;

	}

	public String save() {

		String str = "\n" + name;
		for (int i = orders.size() - 1; i >= 0; i--) {
			str = str.concat("\n\t" + i + orders.get(i).save().replaceAll("\n", "\n\t\t"));
		}

		return str;

	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Restaurant getRestaurant() {
		return restaurant;
	}

	public ArrayList<Order> getOrders() {
		return orders;
	}

	public Order getOrders(int i) {
		return orders.get(i);
	}

	public String getLastOrderString() {
		return orders.get(0).toString();
	}

	public void setOrders(ArrayList<Order> orders) {
		this.orders = orders;
	}

	public float getMoneySpent() {

		float m = 0f;

		for (int i = 0; i < orders.size(); i++) {
			m += orders.get(i).getPrice();
		}

		return m;
	}

}
