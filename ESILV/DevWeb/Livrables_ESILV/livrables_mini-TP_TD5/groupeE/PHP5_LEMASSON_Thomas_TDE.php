<?php 
header('content-type: text/html; charset=utf-8');

//Exercice 2


class Vehicule
{
	
	
	var $marque;
	var $couleur;
	var $km;
	var $carburant;
	


	function __construct()
	{ 
		$num=func_num_args();
		$args=func_get_args();

			switch ($num) 
			{

			
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				break;

			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			default:
				echo"Nombre d'arguments incorrect";
				break;
		}
	}

    
	function arret(){
		
		$this->roule=0;
	}
	

	
	function roule($kmroule,$litreaukm){
		
		$carbu_used=$kmroule*$litreaukm;
		
		$this->roule=1;
		
		$this->km=$this->km+=$kmroule;
		
		$this->km++;
		
		$this->carburant=$this->carburant-=$carbu_used;
	}
	


	function Affichage(){
		
		echo"Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->km."<br>";

	 
				if ($this->carburant > 20) {
    echo "Quantité de carburant: ".$this->carburant."<br>";
} elseif (($this->carburant < 20) && ($this->carburant > 0)) {
    echo "Quantité de carburant: <strong>".$this->carburant." litres de carburant restants</strong><br>";
}  elseif ($this->carburant <= 0) {
    echo "Quantité de carburant:  <strong><font color=black>Le véhicule n'a plus de carburant!</strong><br>";
}  else {
    echo"Quantité de carburant : <strong>Plus de carburant!</strong><br>";
}
		
	}
	

}

echo"<h3><u>Exercice 2</u></h3>";


$voiture = new Vehicule("Peugeot","Gris",20000,60,0);
$voiture->roule(20,1);
$voiture->arret();
$voiture->Affichage();



echo"<br>";
echo"<br>";
echo"<br>";


//Exercice 3


class Voiture extends Vehicule{

	var $typeCarburant;
	var $nbPorte;

	function __construct()
	{
		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
			
			
			
			
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->typeCarburant="";
				$this->nbPorte="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbPorte=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect";
				break;
		}

	}
			
			
			function Affichage(){
				parent::Affichage();
		echo"Type de carburant : ".$this->typeCarburant."<br>";
		echo"Nombre de portes : ".$this->nbPorte."</font><br>";
	}
	
}






class Train extends Vehicule{

    
	var $type;
	var $nbwagon;



	function __construct()
	{
		

		$num=func_num_args();
		$args=func_get_args();

		switch ($num) 
		{
			
			
			
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->carburant="";
				$this->type="";
				$this->nbwagon="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->km=$args[2];
				$this->carburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect<br>";
				break;
		}

	}

	       
			function Affichage(){
			Vehicule::Affichage();
		echo"Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon."<br>";
		
		
	}
}




echo"<h3><u>Exercice 3</u></h3>";

echo"<h4>Voiture</h4>";

$V1 = new Voiture("Bugatti","Veyron",80000,70,0,"Essence",2);
$V1->roule(85,0.6);
$V1->Affichage();
echo"<h4>Train</h4>";

$T1 = new Train("RER A","Rouge, Bleu, Blanc",55000,1500,0,"Electrique",25);
$T1->roule(3000,0.4);
$T1->Affichage();



//Exercice 4

 
 
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<h3><u>Exercice 4</u></h3>";



$V2 = new Voiture("Porsche","911 Carrera S",200000,120,0,"Diesel",2);
$V2->roule(115,1.8);

$T2 = new Train("Tram 1","Orange et jaune",900000,70000,0,"Electrique",10);
$T2->roule(3000,0.4);



$tableau= array(1=>$V2,2=>$T2);


for ($i=1; $i < 2; $i++) { 
echo"<h4>Voiture</h4>";
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h4>Train</h4>";
	echo $tableau[2]->Affichage();
	echo"<br>";
}


?> 