<?php

header('content-type: text/html; charset=utf-8'); // Permet d'afficher les accents sur la page web

class Vehicule{

	// attributs

	var $marque;
	var $couleur;
	var $kilometre;
	var $qteCarbu;

//constructeur
	function Vehicule()
	{ // Début du constructeur

		$num=func_num_args();
		$arguments=func_get_args();
		
		switch($num)
		{
		
			case 0 : 
			$this->marque="t";
			$this->couleur="b";
			$this->kilometre=0;
			$this->qteCarbu=0;
			break;

			case 4 : 
			$this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qteCarbu=$arguments[3];
			break;

			default : 
				echo "Erreur : Nombre d'arguements incorrect"; 
				break;
		}
	}
	
	function Affichage() //Début de la méthode Affichage
	{
		echo "Marque du véhicule :  ". $this->marque ."<br>";
		echo "Couleur du véhicule : " . $this->couleur . "<br>";
		echo "Kilométrage du véhicule : " . $this->kilometre . "km" . "<br>";


		if ($this->qteCarbu > 20) { // Fonction permettant de prévenir l'utilisateur s'il ne reste que peu de carburant
    echo "Quantité de carburant: ".$this->qteCarbu."<br>";
} elseif (($this->qteCarbu < 20) && ($this->qteCarbu > 0)) {
    echo "Quantité de carburant: <strong> Attention véhicule n'a plus que ".$this->qteCarbu." litres de carburant!</strong></font><br>";
}  elseif ($this->qteCarbu <= 0) {
    echo "Quantité de carburant: <strong> Le véhicule n'a plus de carburant!</strong><br>";
}  else {
    echo "Quantité de carburant: <strong> Le véhicule n'a plus de carburant!</strong><br>";
}
		
	}//Fin de la méthode Affichage

	function arret()
	{//Début de la méthode arret
		echo "Le véhicule est à l'arrêt </br>";
		$this->mouv=0;
	}//Fin de la méthode arret

	function roule()
	{ //Début de la méthode roule
		$this->kilometre++;
		$this->qteCarbu--;
		$this->mouv=1;
		echo "Le véhicule est en marche </br>";
	}//Fin de la méthode roule

}
echo"<h3><u>Implémentation de l'exercice 2</u></h3>";
$voiture = new Vehicule("Peugeot ","Gris",20000,60);
$voiture->Affichage();

//Exercice 3

class Voiture extends Vehicule{

	var $typeCarburant;
	var $nbPorte;

	function __construct()//Début du constructeur
	{
		$num = func_num_args();
		$args=func_get_args();
		switch($num)
		{
			case 0 : 
				$this->marque="";
				$this->couleur="";
				$this->kilometre="";
				$this->qteCarbu="";
				$this->typeCarburant="";
				$this->nbporte="";
				break;

			case 4 : 
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qteCarbu=$arguments[3];
			break;

			case 6 :
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				$this->typeCarburant=$args[4];
				$this->nbPorte=$args[5];

			default:

				break;
			}
		}

		function Affichage(){
			Vehicule::affichage();
			echo"Type de carburant : ".$this->typeCarburant."<br>";
			echo"Nombre de portes : " .$this->nbPorte."</br>";
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
				$this->kilometre="";
				$this->qteCarbu="";
				$this->type="";
				$this->nbwagon="";
				break;
			case 4:
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qteCarbu=$arguments[3];
			break;

			case 6:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				$this->type=$args[4];
				$this->nbwagon=$args[5];
				break;

			default:
				echo "Erreur" . "<br>";
				break;

		}

	}
		function Affichage(){

			Vehicule::Affichage();
			echo"Type de train : ".$this->type."<br>";
			echo"Nombre de wagons : ".$this->nbwagon."<br>";
	}
}
echo "<h3><u> Implémentation de l'exercice 3</u></h3>"; 

echo"<h4>Voiture</h4>";
$Voiture1 = new Voiture("Lamborghini","Noir métallisé",80000,70,"Essence",4);
$Voiture1->roule();
$Voiture1->Affichage();

echo"<h4>Train</h4>";
$Train1 = new Train("Tramway T2","Blanc,Vert",27000,1500,"Electrique",25);
$Train1->roule(true);
$Train1->Affichage();


//Exercice 4



echo"<h3><u>Implémentation de l'exercice 4</u></h3>";


// Déclaration de nouveaux véhicules
$Voiture2 = new Voiture("Audi A4","Rouge Pourpre",200000,120,"Diesel",2);//Nouvelle voiture



$Train2 = new Train("Métro 14","Blanc et Vert",500000,55000,"Electrique",10);//Nouveau train

// Fin déclaration nouveaux véhicules

// Déclaration du tableau de véhicule
$tableau= array(1=>$Voiture2,2=>$Train2);
//boucle for pour faire fonctionner le tableau
for ($i=1; $i < 2; $i++) { 
	echo"<h4>Voiture</h4>";
	$Voiture2->roule(1);
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h4>Train</h4>";
	$Train2->roule(1);
	echo"<br>";
	echo $tableau[2]->Affichage();
	echo"<br>";

}//fin boucle for


//Fin du php
?> 


