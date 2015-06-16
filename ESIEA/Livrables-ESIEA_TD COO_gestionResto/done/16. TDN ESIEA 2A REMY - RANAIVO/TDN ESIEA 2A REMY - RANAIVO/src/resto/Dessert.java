package resto;

public class Dessert extends Plats{
 int tarte, glace, creme, fruits;
	
	public Dessert(){
		tarte = 6;
		glace = 5;
		creme = 5;
		fruits = 4;		
	}
	void affichageD(){
		System.out.println("******DESSERT******");
		System.out.println("1 - Glace : "+glace+"€");
		System.out.println("2 - Tarte au citron : "+tarte+"€");
		System.out.println("3 - crème brûlée : "+creme+"€");
		System.out.println("4 - Salade de fruits : "+fruits+"€");
	}
}