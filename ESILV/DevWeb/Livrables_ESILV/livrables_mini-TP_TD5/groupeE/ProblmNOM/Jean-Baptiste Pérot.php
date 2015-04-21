<?php

class Vehicule
	{
		var $marque;
		var $couleur;
		var $km;
		var $qteCarburant;
		var $typeCarburant;
		var $nbPortes;
		var $mouvement;
		var $type;
		var $nbWagon;
		
		function Vehicule()
		{
			$num=func_num_args();
			$arguments=func_get_args();
			
			switch($num)
			{
					
				case 0 : 
					$this->type="Type de vehicule inconnu";
					break;
					
				case 2 :
					$this->type = $arguments[0];
					$this->nbWagon = $arguments[1];
					break;
				
				case 7: 
					$this->marque = $arguments[0];
					$this->couleur = $arguments[1];
					$this->mouvement = $arguments[6];
					$this->km = $arguments[2];
					$this->qteCarburant = $arguments[3];
					$this->typeCarburant = $arguments[4];
					$this->nbPortes = $arguments[5];
					break;
				default :
					echo "erreur ";
					break;				
			}
		}
		
		function affichage()
		{
			$num=func_num_args();
			$arguments=func_get_args();
						
			switch($num)
			{
				case 0 :
					echo "Informations du vehicule :</br></br>";
					break;
				
				case 2 :
					echo "Type de train : " . $this->type . "</br>";
					echo "Nombre de wagons du train : " . $this->nbWagon . "</br>";
					break;
					
				case 7:	
					echo "Marque : " . $this->marque . "</br>";
					echo "Couleur : " . $this->couleur . "</br>";
					echo "Kilometrage : " . $this->km . "</br>";
					echo "Carburant restant : " . $this->qteCarburant . "</br>";
					echo "Type de carburant : " . $this->typeCarburant . "</br>";
					echo "Nombre de portes : " . $this->nbPortes . "</br>";
					break;
					
			}
		}	
		
		function arret()
		{
			echo "le vehicule est à l'arret </br>";
			$this->mouvement=false;
		}
		
		function roule()
		{
			$this->km++;
			$this->qteCarburant--;
			$this->mouvement=true;
			echo "le vehicule est en marche </br>";
			
		}
	}

$Moto = new Vehicule("Kawasaki", "blanche", 17000, 15, "essence", 0, false);
$Moto->affichage();
echo "</br></br>";

$Mototo = new Vehicule();
$Mototo->affichage();
echo "</br></br>";

$Train = new Vehicule("TGV",10);
$Train->affichage();
echo "</br></br>";
?>

