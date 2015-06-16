import java.util.Scanner;

public class main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String saisie;
		int reponse;
		
		System.out.println("   Langages et compilation : TP 2");
		System.out.println("Guillaume Andre - Charles Milléquant");
		System.out.println(" ---------------------------------- ");
		System.out.println("But : Réaliser un désambigueur grammatical");
		
		System.out.println("Charger une grammaire : saisir le nom du fichier");
		saisie = sc.nextLine();
		grammar grammaire = new grammar(saisie);
		System.out.println(grammaire);
		
		if(grammaire.detectLeftRecursion() == true){
			System.out.println("La grammaire possède une récursivité gauche directe. Voulez-vous la lever ? (1-oui 2-non)");
			do{
				reponse = sc.nextInt();
			}while(reponse < 1 || reponse > 2);
			if(reponse == 1){
				grammaire.eliminateLeftRecursion();
				System.out.println(grammaire.displayRules());
				System.out.println("La récursivité gauche directe de cette grammaire a étée levée.");
				System.out.println("Voulez-vous exporter la grammaire transformée ? (1-oui 2-non)");
				do{
					reponse = sc.nextInt();
				}while(reponse < 1 || reponse > 2);
				if(reponse == 1)
					grammaire.export();
			}
		}
		if(grammaire.estFactorisable() == true)
			System.out.println("Cette grammaire est factorisable");
	}
}