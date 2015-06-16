package resto;

public class Boisson extends Plats{
	public int coca, sprite, eau, jusFruit;
	
	public Boisson(){
		coca = 3;
		sprite = 3;
		eau = 2;
		jusFruit = 4;
	}
	void affichageB(){
		System.out.println("******BOISSON******");
		System.out.println("1 - Coca : "+coca+"€");
		System.out.println("2 - Sprite : "+sprite+"€");
		System.out.println("3 - Eau : "+eau+"€");
		System.out.println("4 - Jus de fruit : "+jusFruit+"€");
	}

}