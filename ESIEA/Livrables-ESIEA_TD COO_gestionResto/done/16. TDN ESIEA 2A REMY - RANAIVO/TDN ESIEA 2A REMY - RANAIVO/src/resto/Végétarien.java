package resto;

public class V�g�tarien extends Plats{
	int lasagne, salade, tofu;
	
	public V�g�tarien(){
		lasagne = 10;
		salade = 8;
		tofu = 9;
	}
	void affichageV(){
		System.out.println("******PLAT VEGETARIEN******");
		System.out.println("1 - Salade verte au noix : "+salade+"�");
		System.out.println("2 - Lasagne v�g�tarienne : "+lasagne+"�");
		System.out.println("3 - Tofu au curry et riz : "+tofu+"�");
	}
}