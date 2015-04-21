<?php

class Vehicule
	{
		var $marque;
		var $couleur;
		var $km;
		var $qteCarburant;
		var $typeCarburant;
		var $nbPortes;
		
		
		function Vehicule()
		{
			$num=func_num_args();
			$arguments=func_get_args();
			
			switch($num)
			{
				case 0 : $this->marque="t";
						 $this->couleur="b";
						 $this->km=0;
						 $this->qteCarburant=0;
						 $this->typeCarburant="c";
						 $this->nbPortes=3;
						 break;
				
				case 4 : $this->marque = $arguments[0];
						 $this->couleur = $arguments[1];
						 $this->km = $arguments[2];
						 $this->qteCarburant = $arguments[3];
						 $this->typeCarburant = $arguments[4];
						 $this->nbPortes = $arguments[5];
						 break;
				default : echo "erreur "; break;				
			}
		}
		
		
		
		function arret()
		{
			echo "le vehicule est à l'arret </br>";
			$this->mouvement=0;
		}
		
		function roule()
		{
			$this->km++;
			$this->qteCarburant--;
			$this->mouvement=1;
			echo "le vehicule est en marche </br>";
			
		}
        function affichage()
		{
			echo "Véhicule : </br>";
			echo "Marque :" .$this->$marque ."</br>";
			echo "couleur :" .$this->$couleur ."</br>";
			echo "kilometarge :" .$this->$km ."</br>";
            echo "quantité de carburant :" .$this->$qteCarburant ."</br>";
			echo "type de carburant :" .$this->$typeCarburant ."</br>";
			echo "nombre de portes :" .$this->$nbPortes ."</br>";
			
			if($this->qteCarburant = 50)
			{
			echo "Quantité de carburant: ".$this->qteCarburant."</br>";
            } 
			elseif (($this->qteCarburant < 50) && ($this->qteCarburant > 0)) 
			{
            echo "Le véhicule n'a plus que ".$this->qteCarburant." litres de carburant</br>";
            }  
			elseif ($this->qteCarburant = 0) 
			{
            echo "Le véhicule n'a plus de carburant.<br>";
            }  
		}			
	}
	echo"Exercice 2";
	
	$voiture = new Vehicule("McLaren P1", "orange", 10000, 72, "diesel",2);
    $voiture->roule(100,8.3);
    $voiture->arret();
    $voiture->affichage();	
	
	//Exercice 3.
	
    class Voiture extends Vehicule
	{
		var $type_carbu;
		var $nb_portes;
		
		function __construct()
		{
			parent::Vehicule();
			$num = func_num_args();
			$arguments=func_get_arg();
			switch($num)
			{
				case 0:
				$this->marque="";
				$this->couleur="";
				$this->km="";
				$this->qteCarburant="";
				$this->type_carbu="";
				$this->nb_portes="";
				break;
				
				case 6:
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->km=$arguments[2];
				$this->qteCarburant=$arguments[3];
				$this->roule=$arguments[4];
				$this->type_carbu=$arguments[5];
				$this->nb_portes=$arguments[6];
				break;
				
				defaut: echo "erreur";
				break;				
			}
		}
		function affichage()
		{
			parent::affichage();
			echo"la voiture fonctionne grace au
			carburant suivant :".$this->type_carbu. "et possede" .$this->nb_portes. "</br>";
		}
	}

	class Train extends Vehicule
	{
		var $type;
		var $nbWagon;
	
		function __construct()
		{
			$num=func_num_args();
			$arguments=func_get_args();
			
			switch($num)
			{
				case 0 : 
				$this->type="";
				$this->couleur="";
				$this->km="";
				$this->qteCarburant="";
				$this->type_carbu="";
				$this->nb_wagon="";
				break;
				
				case 4 : 
				$this->type=$argument[0];
				$this->couleur=$argument[1];
				$this->km=$argument[2];
				$this->qteCarburant=$argument[3];
				$this->type_carbu=$argument[4];
				$this->nb_wagon=$argument[5];
				break;
				
				default : echo "erreur "; break;				
			}	
		}
		
		function affichage()
		{
			echo "Type de train : " . $this->type . "</br>";
			echo "Nombre de wagons du train : " . $this->nbWagon . "</br>";
			
		}	
	}
	echo"Exercice3,voiture";
		$MyCar = new Voiture("Peugeot 206 hdi =)", "gris antracite", 149000, 50, "disel", 3);
        $MyCar->roule(100, 4);
		$MyCar->affichage();
		
	echo"Exercice3,train"
    	$Train = new Train("TGV", "gris", 300000, 2000, "Electrique", 15);
		$Train->roule(4000,1);
		$Train->affichage();
		
		//Exercice4.
		$tab=array(1->$MyCar, 2->$Train);
		for ($i=1; $i<2; $i++)
		{
			echo"voiture";
			echo $tab[1]->affichage();
			echo"</br>";
			echo"Train";
            echo $tab[2]->affichage();			
		}
?>


