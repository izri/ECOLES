<?php
//EXERCIE 2
class Vehicule
{
	var $marque;
	var $couleur;
	var $kilometre;
	var $qdtCarbu;
	var $mouv=false;

	function __construct ()
	{
		$num=func_num_args();
		$args=func_get_args();
		switch($num)
		{
			case 0: $this->marque="toyota";
					$this->couleur="b";
					$this->kilometre="0";
					$this->qdtCarbu="0";

			case 5:	$this->marque=$args[0];
					$this->couleur=$args[1];

					$this->kilometre=$args[2];
					$this->qdtCarbu=$args[3];
					$this->mouv=$args[4];
			break;

			default: echo "erreur";
			break;
		}
	}

	
    function Arret ()
    {
        echo"Le véhicule est à l'arrêt.</br>";
        $this->mouv=0;
    }
    function Roule($kmroule,$litrekm)
    {
        $carbu_utilise = $kmroule*$litrekm;
		$this->roule=1;
		$this->kilometre=$this->kilometre+=$kmroule;
		$this->kilometre++;
		$this->qdtCarbu=$this->qdtCarbu-=$carbu_utilise;
        
	}
	function Affichage(){
		
		echo"Marque du véhicule: ".$this->marque."<br>";
		echo"Couleur du véhicule: ".$this->couleur."<br>";
		echo"Kilométrage du véhicule: ".$this->kilometre."<br>";
	
		if ($this->qdtCarbu > 20) 
		{
			echo "Quantité de carburant: ".$this->qdtCarbu."km <br>";
		} 
		elseif (($this->qdtCarbu < 20) && ($this->qdtCarbu > 0)) 
		{
			echo "Quantité de carburant: Le véhicule n'a plus que ".$this->qdtCarbu." litres de carburant <br>";
		}
		elseif ($this->qdtCarbu <= 0) 
		{
			echo "Quantité de carburant: Le véhicule n'a plus de carburant! <br>";
		}  
		else 
		{
			echo"Quantité de carburant: Le véhicule n'a plus de carburant <br>";
		}
		
	}
}

$voiture = new Vehicule("Renault","rouge",25678,60,1);
$voiture->Roule(20,1);
$voiture->Arret();
$voiture->Affichage();

echo"<br>";

//EXERCICE 3
class Voiture extends Vehicule
{
	var $type_carbu;
	var $nb_portes;
	
	function __construct ()
	{
		parent::Vehicule();
		$num=func_num_args();
		$args=func_get_args();
		switch ($num) 
		{
			case 0: $this->marque="";
					$this->couleur="";
					$this->kilometre="";
					$this->qdtCarbu="";
					$this->type_carbu="";
					$this->nb_portes="";
			
			case 5:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->type_carbu=$args[3];
					$this->mouv=$args[4];
					break;
			case 7:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qdtCarbu=$args[3];
					$this->roule=$args[4];
					$this->type_carbu=$args[5];
					$this->nb_portes=$args[6];
					break;
					
			
				
			default: echo"erreur";
			break;
		}
	}


	function Affichage()
	{
		parent::Affichage();
		
			echo"Type de carburant : ".$this->type_carbu."<br>";
			echo"Nombre de portes : ".$this->nb_portes."<br>";

	}
	
     
}

class Train extends Vehicule
{
	var $type;
	var $nb_wagons;

	function __construct ()
	{
		parent::Vehicule();
		$num=func_num_args();
		$args=func_get_args();
		switch ($num) 
		{
			case 0: $this->marque="";
					$this->couleur="";
					$this->kilometre="";
					$this->qdtCarbu="";
					$this->type="";
					$this->nb_wagons="";
					break;
			case 5:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qdtCarbu=$args[3];
					$this->mouv=$args[4];
					break;

			case 7:
					$this->marque=$args[0];
					$this->couleur=$args[1];
					$this->kilometre=$args[2];
					$this->qdtCarbu=$args[3];
					$this->mouv=$args[4];
					$this->type=$args[5];
					$this->nb_wagons=$args[6];
					break;

				
			default: echo "Error"; 
			break;
		}
	}
	
	function Affichage()
	{
		parent::Affichage();
		echo"Type de train : ".$this->type."<br>";
			echo"Nombre de wagons : ".$this->nb_wagons."<br>";
	}	
	
}
// EXERCICE 4

$Voiture1 = new Vehicule("Mercedes", "noire", 60, 85, "essence", 5, false);
$Voiture1->Affichage();
echo "</br></br>";

 
$Train1 = new Train("RER",13);
$Train1->Affichage();
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
}

?> 