import java.util.HashMap;
import java.util.Map.Entry;

public class Order {

	private HashMap<OrderTypes, Integer> meals;

	public Order() {
		this.meals = new HashMap<OrderTypes, Integer>();
	}

	public Order(OrderTypes... types) {
		this.meals = new HashMap<OrderTypes, Integer>();
		this.addMeals(types);
	}

	public Order addMeals(OrderTypes type, int quantity) {

		quantity = quantity < 1 ? 1 : quantity;

		if (meals.get(type) == null)
			this.meals.put(type, quantity);
		else
			this.meals.put(type, meals.get(type) + quantity);

		return this;

	}

	public Order addMeals(OrderTypes... types) {

		for (int i = 0; i < types.length; i++)
			this.addMeals(types[i], 1);

		return this;

	}

	public float getPrice() {

		float price = 0;

		for (Entry<OrderTypes, Integer> entry : meals.entrySet()) {
			OrderTypes type = entry.getKey();
			Integer quantity = entry.getValue();

			price += quantity * type.getPrice();

		}

		return price;

	}

	public String save() {

		String str = new String();

		for (Entry<OrderTypes, Integer> entry : meals.entrySet()) {
			OrderTypes type = entry.getKey();
			Integer quantity = entry.getValue();

			str = str.concat("\n" + type.ordinal() + " " + quantity);

		}

		return str;

	}

	@Override
	public String toString() {

		String str = "\nThis dish contains :";

		for (Entry<OrderTypes, Integer> entry : meals.entrySet()) {

			OrderTypes type = entry.getKey();
			Integer quantity = entry.getValue();

			str = str.concat("\n\t" + type.toString() + " : " + quantity);

		}

		return str.concat("\nIt costs $" + this.getPrice() + "0\n");

	}

	public HashMap<OrderTypes, Integer> getMeals() {
		return meals;
	}

	public void setMeals(HashMap<OrderTypes, Integer> meals) {
		this.meals = meals;
	}

}
