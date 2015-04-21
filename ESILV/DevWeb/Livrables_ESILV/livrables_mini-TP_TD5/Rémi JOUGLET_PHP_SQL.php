<?php

class Vehicule
{
	
	var $marque;
	var $couleur;
	var $km;
	var $carburant;
	


	function __construct()
	{	$num=func_num_args();
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
				echo"Erreur";
				break;
		}
	}

    
	function arret()
	{
		$this->roule=0;
	}
	

	
	function roule($kmroule,$litrekm){
		
		$carbu_utilise = $kmroule*$litrekm;
		$this->roule=1;
		$this->km=$this->km+=$kmroule;
		$this->km++;
		$this->carburant=$this->carburant-=$carbu_utilise;
	}
	
	
	function Affichage(){
		
		echo"<font color=blue>Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->km."<br>";
	
		if ($this->carburant > 20) 
		{
			echo "Quantité de carburant: ".$this->carburant."</font><br>";
		} 
		elseif (($this->carburant < 20) && ($this->carburant > 0)) 
		{
			echo "Quantité de carburant: Attention véhicule n'a plus que ".$this->carburant." litres de carburant! <br>";
		}
		elseif ($this->carburant <= 0) 
		{
			echo "Quantité de carburant: Le véhicule n'a plus de carburant! <br>";
		}  
		else 
		{
			echo"Quantité de carburant : Le véhicule n'a plus de carburant <br>";
		}
		
	}
	

} 

$voiture = new Vehicule("Peugeot","Gris",20000,60,0);
$voiture->roule(20,1);
$voiture->arret();
$voiture->Affichage();

echo"<br>";

class Voiture extends Vehicule{


	var $typeCarburant;
	var $nbPorte;

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
				echo"Erreur";
				break;
		}

	}
			
		function Affichage()
		{
			parent::Affichage();
			echo"Type de carburant : ".$this->typeCarburant."<br>";
			echo"Nombre de portes : ".$this->nbPorte."<br>";
		}
	
} 

class Train extends Vehicule
{
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
				echo"Erreur";
				break;
		}

	}

	    function Affichage()
		{
			Vehicule::Affichage();
			echo"Type de train : ".$this->type."<br>";
			echo"Nombre de wagons : ".$this->nbwagon."<br>";		
		}
}
	
$Voiture1 = new Vehicule("Peugeot", "rouge", 50, 80, "essence", 5, false);
$Voiture1->affichage();
echo "</br></br>";

 
$Train1 = new Train("RER",6);
$Train1->affichage();
echo "</br></br>";

echo"<br>";

$tableau= array(1=>$V2,2=>$T2);
 
for ($i=1; $i < 2; $i++) { 
echo"<h1>Voiture</h1>";
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h1>Train</h1>";
	echo $tableau[2]->Affichage();
	echo"<br>";

?> 