<?php
	//Exo 2
	// classe Vehicule
	class Vehicule{
		//attributs
		var $marque;
		var $couleur;
		var $kilometre;
		var $qteCarbu;

		//constructeur
		function __construct(){
			$num=func_num_args();
			$args=func_get_args();
			switch ($num){
				//constructeur par défaut
				case 0:
					$this->marque="";
					$this->couleur="";
					$this->kilometre="";
					$this->qteCarbu="";
					break;
				case 5:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qteCarbu=$args[3];
					$this->roule=$args[4];
					break;
				default:
					echo"Erreur";
					break;
			}
		}

		// méthodes
		function arret(){
			$this->roule=0;
		}
		function roule($kmparcouru){
			for($i=0;$i<=$kmparcouru;$i++){
				$this->roule=1;
				$this->kilometre++;
				$this->qteCarbu--;
			}
		}
		function Affichage(){
			echo"La marque du véhicule est : ".$this->marque.", sa couleur est : ".$this->couleur." et son kilométrage est : ".$this->kilometre."km.<br>";
		}
	}
	
	//implémentation
	echo "<h3>exo2</h3>";
	$voiture = new Vehicule("Citröen","Grise",10000,60,0);
	$voiture->roule(15);
	$voiture->arret();
	$voiture->Affichage();
	echo"<br>";
	echo"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";
	echo"<br>";

/******************************************************************************************************************************************************/
	//Exo 3
	// classe Voiture
	class Voiture extends Vehicule{
		//attributs
		var $typeCarbu;
		var $nbPorte;
		
		//constructeur
		function __construct(){
			$num=func_num_args();
			$args=func_get_args();
			switch ($num) {
				//constructeur par défaut
				case 0:
					$this->marque="";
					$this->couleur="";
					$this->kilometre="";
					$this->qteCarbu="";
					$this->typeCarbu="";
					$this->nbPorte="";
					break;
				case 5:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qteCarbu=$args[3];
					$this->roule=$args[4];
					break;
				case 7:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qteCarbu=$args[3];
					$this->roule=$args[4];
					$this->typeCarbu=$args[5];
					$this->nbPorte=$args[6];
					break;
				default:
					echo"Erreur";
					break;
			}
		}
			
		// méthode
		function Affichage(){
			parent::Affichage();
			echo"Le type de carburant est : ".$this->typeCarbu." et la voiture a ".$this->nbPorte." portes. <br>";
		}
	}

	// classe Train
	class Train extends Vehicule{
		//attributs
		var $type;
		var $nbwagon;

		//constructeur
		function __construct(){
			$num=func_num_args();
			$args=func_get_args();
			switch ($num) {
				//constructeur par défaut
				case 0:
					$this->marque="";
					$this->couleur="";
					$this->kilometre="";
					$this->qteCarbu="";
					$this->type="";
					$this->nbwagon="";
					break;
				case 5:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qteCarbu=$args[3];
					$this->roule=$args[4];
					break;
				case 7:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qteCarbu=$args[3];
					$this->roule=$args[4];
					$this->type=$args[5];
					$this->nbwagon=$args[6];
					break;
				default:
					echo"Erreur";
					break;
			}
		}

		// méthode
		function Affichage(){
			parent::Affichage();
			echo"Le train est un ".$this->type." et il possède ".$this->nbwagon." wagons.<br>";
		}
	}
		
	//implémentation
	echo"<h3>exo3</h3>";
	echo"<h4>voiture</h4>";
	$V1 = new Voiture("Peugeot","rouge",10000,60,0,"Diesel",5);
	$V1->roule(50);
	$V1->Affichage();
		
	echo"<h4>train</h4>";
	$T1 = new Train("RER A","Bleu, Blanc, Rouge",100000,3000,0,"RER",15);
	$T1->roule(2000);
	$T1->Affichage();
	echo"<br>";
	echo"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";
	echo"<br>";
	
/******************************************************************************************************************************************************/
	//Exo 4
	//implémentation
	echo"<h3>exo4</h3>";
	//nouvelle voiture
	$V2 = new Voiture("Fiat","Bleu, Blanc",10000,60,0,"Diesel",5);
	$V2->roule(90);
	
	//nouveau train
	$T2 = new Train("U","Bleu, Rouge",100000,3000,0,"Transcilien",15);
	$T2->roule(2000);

	$tab = array(1=>$V2,2=>$T2);
	for ($i=1; $i < 2; $i++) { 
		echo $tab[1]->Affichage()."<br>";
		echo $tab[2]->Affichage()."<br>";
	}
?> 