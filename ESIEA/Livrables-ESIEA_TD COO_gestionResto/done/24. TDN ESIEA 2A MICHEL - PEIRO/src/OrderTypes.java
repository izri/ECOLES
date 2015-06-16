
public enum OrderTypes {

	MARGHERITA(8,"Pizza Margherita"),
	PEPPERONI(8,"Pizza Pepperoni"),
	QUATRO(8,"Pizza Quatro Fromaggi"),
	GAMBERO(8,"Pizza Gambero"),
	SPECIAL(10,"Today's special"),
	VEGGIE(15, "Vegetarian dish"),
	PIE(3, "Dessert Apple Pie"),
	CAKE(3, "Dessert Chocolate Cake"),
	FRUIT(3, "Dessert Fruit Plate"),
	COCA(1.50f, "Drink Coca-Cola"),
	FANTA(1.50f, "Drink Fanta"),
	OASIS(1.50f, "Drink Oasis"),
	MOUNTAIN(1.50f, "Drink Mountain Dew");
	
	private float price;
	private String name;
	
	OrderTypes(float price,String name) {
		this.price = price;
		this.name = name;
	}
	
	public float getPrice() {
		return price;
	}
	
	public String toString() {
		return name;
	}
	
	public static OrderTypes getFromOrdinal(int ordinal) {
		
		OrderTypes r = null;
		
		switch(ordinal) {
		
			case 0 :
				r = MARGHERITA;
				break;
		
			case 1 :
				r = PEPPERONI;
				break;
		
			case 2 :
				r = QUATRO;
				break;
		
			case 3 :
				r = GAMBERO;
				break;
		
			case 4 :
				r = SPECIAL;
				break;
		
			case 5 :
				r = VEGGIE;
				break;
		
			case 6:
				r = PIE;
				break;
		
			case 7 :
				r = CAKE;
				break;
		
			case 8 :
				r = FRUIT;
				break;
		
			case 9 :
				r = COCA;
				break;
		
			case 10 :
				r = FANTA;
				break;
		
			case 11 :
				r = OASIS;
				break;
		
			case 12 :
				r = MOUNTAIN;
				break;
			
			default :
				break;
			
		}
		
		return r;
		
	}
	
}
