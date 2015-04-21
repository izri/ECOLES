<?php 

class Vehicule
{
	var $marque;
	var $couleur;
	var $kilometres;
	var $quantitecarburant;
	var $etat=false;
	
	function __construct()
	{
		//récuperer le nombre de paramètres en arguments
		$nb=func_num_args();
		
		//l'ensemble des arguments
		$arguments=func_get_args();
		
		switch($nb)
		{
			case 0 : //constructeur par défaut
					 $this->marque="Peugeot";
					 $this->couleur="Noir";
					 $this->kilometres=0; 
					 $this->quantitecarburant=0; break;
					 
			case 4 : //constructeur paramétré
					 $this->marque=$arguments[0];
					 $this->couleur=$arguments[1];
					 $this->kilometres=$arguments[2];
					 $this->quantitecarburant=$arguments[3]; break;
					 
			default : echo "erreur"; break;
		}
	}
	
	//méthodes getter setter 
	
	function getMarque()
	{
		return $this->marque;
	}
	
	function getCouleur()
	{
		return $this->couleur;
	}
	
	function getKilometres()
	{
		return $this->kilometres;
	}
	
	function getQuantitecarburant()
	{
		return $this->quantitecarburant;
	}
	
	function setMarque($marq)
	{
		$this->marque=$marq;
	}
	
	function setCouleur($col)
	{
		$this->couleur=$col;
	}
	
	function setKilometres($km)
	{
		$this->kilometres=$km;
	}
	
	function setQuantitecarburant($quant)
	{
		$this->quantitecarburant=$quant;
	}
	
	//méthodes 
	
	function Affichage()
	{
		echo "<strong>Vehicule :</strong>" ."<br>";
		echo "Marque : " .$this->getMarque() ."<br>";
		echo "Couleur : " .$this->getCouleur() ."<br>";
		echo "Kilometres : " .$this->getKilometres() ."<br>";
		echo "Quantite de carburant : " .$this->getQuantitecarburant() ."<br>";
		echo "<br>";
	}

	function Arret()
	{
		if($this->etat == true)
		{
			$this->etat=false;
		}
		echo "Le vehicule est a l'arret.";
		echo "<br>";
		echo "<br>";
	}
	
	function Roule()
	{
		if($this->etat == false)
		{
			$this->etat=true;
		}
		
		$this->kilometres++;
		$this->quantitecarburant--;
		echo "Le vehicule est en marche.";
		echo "<br>";
		echo "<br>";
	}
}

class Voiture extends Vehicule
{
	var $carburant;
	var $nbportes;
	
	function __construct()
	{
		//récuperer le nombre de paramètres en arguments
		$nb=func_num_args();
		
		//l'ensemble des arguments
		$arguments=func_get_args();
		
		switch($nb)
		{
			case 0 : //constructeur par défaut
					 $this->carburant="Essence"; 
					 $this->nbportes="5"; break;
					 
			case 2 : //constructeur paramétré
					 $this->carburant=$arguments[0];
					 $this->nbportes=$arguments[1]; break;
					 
			default : echo "erreur"; break;
		}
	}
	
	function getCarburant()
	{
		return $this->carburant;
	}
	
	function getNbportes()
	{
		return $this->nbportes;
	}
	
	function setCarburant($carbu)
	{
		$this->carburant=$carbu;
	}
	
	function setNbportes($nbp)
	{
		$this->nbportes=$nbp;
	}
	
	function AffichageVoiture()
	{
		echo "<strong>Voiture :</strong>" ."<br>";
		echo "Carburant : " .$this->getCarburant() ."<br>";
		echo "Nombres de portes : " .$this->getNbportes() ."<br>";
		echo "<br>";		
	}
	
	function Arret()
	{
		parent::Arret();
		echo "Ce vehicule est une voiture."; 
		echo "<br>";
		echo "<br>";
	}
	
	function Roule()
	{
		parent::Roule();
		echo "Ce vehicule est une voiture."; 
		echo "<br>";
		echo "<br>";	
	}
}

class Train extends Vehicule
{
	var $type;
	var $nbwagons;
	
	function __construct()
	{
		//récuperer le nombre de paramètres en arguments
		$nb=func_num_args();
		
		//l'ensemble des arguments
		$arguments=func_get_args();
		
		switch($nb)
		{
			case 0 : //constructeur par défaut
					 $this->type="RER";
					 $this->nbwagons="15"; break;
					 
			case 2 : //constructeur paramétré
					 $this->type=$arguments[0];
					 $this->nbwagons=$arguments[1]; break;
					 
			default : echo "erreur"; break;
		}
	}
	
	function getType()
	{
		return $this->type;
	}
	
	function getNbwagons()
	{
		return $this->nbwagons;
	}
	
	function setType($typ)
	{
		$this->type=$typ;
	}
	
	function setNbwagons($nbw)
	{
		$this->nbwagons=$nbw;
	}
	
	function AffichageTrain()
	{

		echo "<strong>Train :</strong>" ."<br>";
		echo "Type : " .$this->getType() ."<br>";
		echo "Nombres de wagons : " .$this->getNbwagons() ."<br>";
		echo "<br>";
		}
	
	function Arret()
	{
		parent::Arret();
		echo "Ce vehicule est un train.";
		echo "<br>";
		echo "<br>";
		}
	
	function Roule()
	{
		parent::Roule();
		echo "Ce vehicule est un train.";
		echo "<br>";
		echo "<br>";		
	}
}

$vehicule1 = new Vehicule("Renault","Bleu","100 000","500");
$vehicule2 = new Vehicule();

$voiture1 = new Voiture("Diesel","3");
$voiture2 = new Voiture();

$train1 = new Train("TGV","22");
$train2 = new Train();

$tabvehicule = array ($vehicule1, $vehicule2, $voiture1, $voiture2, $train1, $train2);

$tabvehicule[0]->Affichage();
$tabvehicule[0]->Roule();
$tabvehicule[0]->Affichage();

$tabvehicule[1]->Affichage();
$tabvehicule[1]->Arret();

$tabvehicule[2]->AffichageVoiture();
$tabvehicule[2]->Roule();

$tabvehicule[3]->AffichageVoiture();
$tabvehicule[3]->Arret();

$tabvehicule[4]->AffichageTrain();
$tabvehicule[4]->Roule();

$tabvehicule[5]->AffichageTrain();
$tabvehicule[5]->Arret();

?>