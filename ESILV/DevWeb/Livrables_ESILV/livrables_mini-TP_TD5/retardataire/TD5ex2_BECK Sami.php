<?php 

$Voiture = new Vehicule("Renault","Rouge","123432","984"); 
$Voiture->Affiche(); 

$essaiTrain= new Voiture("SNCF","Violey","6827984","100000","Electrique",2451); 
$essaiTrain->Affiche(); 


class Vehicule
{
	
	//attributs
	var $Marque;
	var $Couleur;
	var $Kilometres;
	var $qteCarburant; 
	
	
	function Vehicule(){
		$max=func_num_args();
		$args=func_get_args();
		switch($max){
			
			case 0: 
			$this->Marque="vide";
			$this->Couleur = "vide";
			$this->Kilometres = 0;
			$this->qteCarburant = 0;
			case 4:
			$this->Marque=$args[0];
			$this->Couleur=$args[1];
			$this->Kilometres=$args[2];
			$this->qteCarburant=$args[3];
			break;
			default:
			echo"error";
			break;
		}
	}
		function Affiche()
		{
			echo "<br><br>La Marque de votre vehicule ". $this->Marque ."<br>  " .
			"La couleur de la voiture choisi est  ". $this->Couleur ."<br> ".
			"Les kilometres parcouru de la voiture est de ". $this->Kilometres ." Km <br>".
			"La quantité de carburant est ". $this->qteCarburant ."" ; 
		}
		
		
		function Roule($nb)
		{	
			$this->Kilometres+=$nb; 
			$this->qteCarburant-=$nb; 
		}
		
		function Arret()
		{
			echo "<br>Le vehicule est actuellement arreté <br>"; 
		}

		
}


class Voiture extends Vehicule
{
	var $TypeCarburant;
	var $NbdePortes; 
	
	function Voiture()
	{
		$max=func_num_args();
		$args=func_get_args();
		parent::Vehicule($args[0],$args[1],$args[2],$args[3]); 
		
		echo $max; 
		switch($max)
		{
		case 6:
		$this->TypeCarburant=$args[4];
		$this->NbdePortes=$args[5]; 
		break;
		default:
		echo("error");
		break;
		}
	}
		function Affiche()
	{
		parent::Affiche(); 
		echo"<br>Type de Carburant : ". $this->TypeCarburant ."<br>".
		"Nb de Portes : ". $this->NbdePortes."<br>" ; 	
	}
		
	
	
}

class Train extends Vehicule 
{
	var $Type;
	var $Nbdewagons; 
	
	function Train()
	{
		$max=func_num_args();
		$args=func_get_args();
		parent::Vehicule($args[0],$args[1],$args[2],$args[3]); 
		
		switch($max)
		{
		case 6:
		$this->Type=$args[4];
		$this->Nbdewagons=$args[5]; 
		break; 
		default:
		break;
		}
	}
	
	function Affiche()
	{
		parent::Affiche();
        echo"<br>Type de Train : ". $this->Type ."<br>".
		"Nb de wagons : ". $this->Nbdewagons."<br>"		; 		
	}
	
}





?>