<?php
class Vehicule
{
	var $marque;
	var $couleur;
	var $kilometre;
	var $qteCarburant;
    var $etat;
	

function __construct2()
	{
		
		$this->etat;
		$this->qteCarburant;
		$this->marque;
		$this->couleur;
		$this->kilometre;
	}

	function __construct($iniEtat="en circulation",$iniCarb=0,$iniMarq="audi",$iniCoul="bleu",$inikilo=0)
	{
		
		$this->etat=$iniEtat;
		$this->qteCarburant=$iniCarb;
		$this->marque=$iniMarq;
		$this->couleur=$iniCoul;
		$this->kilometre=$inikilo;
	}

	function arret($etat)
	{
	switch ($etat) {
			case 0:
				$this->etat="en circulation";				
				break;
			
			case 1:
			    $this->etat= "à l'arret";  
			    break;
			
			default:
				echo "Error";
				break;
		}
	}

	
	function roule($ajout=10,$kilometre=0)
	{
		$this->kilometre=$kilometre + $ajout;
		
	}

	function afficher()
	{
		echo "<br><br> Marque du vehicule: ".$this->marque."<br><br>";
		echo "Autres informations: <br> Le vehicule est de couleur : ".$this->couleur." <br>";
		echo "Le vehicule a roulé :".$this->kilometre." kilometres <br>";
		echo "Le reservoir contient : ".$this->qteCarburant." litres <br>";
    	echo "Le vehicule est actuellement : ".$this->etat;
		 

	}
}


class Voiture extends Vehicule
{
	var $carburant="diesel";
	var $nbPorte=3;

	function __construct($iniCar,$iniPor)
	{
		$this->carburant=$iniCar;
		$this->nbPorte=$iniPor;
	}
function afficher()
	{
		
		echo "<br><br> type de carburant: ".$this->carburant."<br>";
		echo "type de nombre de porte: ".$this->nbPorte."<br>";
	}	

}


class Train extends Vehicule
{
	var $type;
	var $nbPorteVoit;

	function __construct($initype="intercite",$iniPorVoi=5)
	{
		$this->type=$initype;
		$this->nbPorteVoit=$iniPorVoi;
	}
	
function afficher()
	{
		echo "<br><br> type de train: ".$this->type."<br>";
		echo "nombre de porte par voiture: ".$this->nbPorteVoit."<br>";
	}
}

$myObjet1 = new Voiture("essence",5);
$myObjet1->afficher();
$myObjet2 = new Voiture("diesel",3);
$myObjet2->afficher();
$myObjet3 = new Voiture("sans plomb",7);
$myObjet3->afficher();
$myObjet4 = new Train("TGV",3);
$myObjet4->afficher();
$myObjet5 = new Train("intercité",5);
$myObjet5->afficher();
$myObjet6 = new Vehicule("en circulation",100,"audi","bleu",10000);
$myObjet6->afficher();
$myObjet7 = new Vehicule("en circulation",20,"ferrari","rouge",26000);
$myObjet7->afficher();

$vehicules = array();
$vehicules[0] = $myObjet1;
$vehicules[1] = $myObjet2;
$vehicules[2] = $myObjet3;
$vehicules[3] = $myObjet4;
$vehicules[4] = $myObjet5;
$vehicules[5] = $myObjet6;
$vehicules[6] = $myObjet7;


?>