package resto;

public class PlatDuJour extends Plats{
	int blanquette;
	
	public PlatDuJour(){
		blanquette = 12;
	}
	void affichagePDJ(){
		System.out.println("******PLAT DU JOUR******");
		System.out.println("1 - Blanquette : "+blanquette+"€");
	}
}