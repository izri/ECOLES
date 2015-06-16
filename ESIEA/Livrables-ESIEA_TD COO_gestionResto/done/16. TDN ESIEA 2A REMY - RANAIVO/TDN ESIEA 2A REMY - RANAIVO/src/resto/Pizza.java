package resto;


public class Pizza extends Plats{
	int fromage, marguarita, sicilienne, paysanne;
	
	public Pizza(){
		fromage = 10;
		marguarita = 8;
		sicilienne = 9;
		paysanne = 10;
	}
	void affichageP(){
		System.out.println("******PIZZA******");
		System.out.println("1 - 4 fromages : "+fromage+"€");
		System.out.println("2 - Marguarita : "+marguarita+"€");
		System.out.println("3 - Sicilienne : "+sicilienne+"€");
		System.out.println("4 - Paysanne : "+paysanne+"€");
	}
}