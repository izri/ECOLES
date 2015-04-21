<?php // debut du php

//Exercice 2 : Classe Véhicule

// classe Vehicule

class Vehicule{
	
	// attributs
 var $marque;
  var $couleur;
   var $kilometre;
    var $qteCarbu;
	var $etat= false;




function Commande() {     //function__construct() permet d'ecrire d'une autre facon les constructeurs syntaxe du php 
// recuperer le nombre de parametres en arguments

// constructeur
    $nb=func_num_args();
	//l'ensemble des arguments
	$arguments=func_get_args();
	
	switch($nb)
	{
	   case 0: // constructeur par défaut
	        $this->nomClient="Jacques"; 
			$this->couleur="Jacques";
            $this->kilometre=0;
             $this-qteCarbu>=0;
			 
			break;
	   case 4 : //constructeur parametre
	        $this->marque=$arguments[0];
			$this->couleur=$arguments[1];
			$this->kilometre=$arguments[2];
			$this->qteCarbu=$arguments[3];
	   break;
	   default: echo "erreur"; // Rentre pas de case sa affiche erreur 
	   break;
	   
	}
}
//methode getter et setter 

function getMarque()
{   return $this->marque;
}

function getCouleur()  // RETOURNER LA VALEUR D'UN ATTRIBUT
{   return $this->couleur;
}
	function getKilometre()
{   return $this->kilometre;
}
	function getQteCarbu()
{   return $this->qteCarbu;
}
function setMarque($marq) 
{   $this->marque=$marq;
}

	function setCouleur($col) 
{   $this->couleur=$col;
}
	function setKilometre($kilo) 
{   $this->kilometre=$kilo;
}
function setQteCarbu($qte) 
{   $this->qteCarbu=$qte;
}

//methodes

function affichage()
{
	echo "le vehicule de marque" .$this->getMarque()
	"de couleur". $this->getCouleur().
	"ayant un kilometrage de :" . $this->getKilometre().
	"contient". $this->getQteCarbu(). "</br>";
 }

 function arret()
 {   
 if($this->etat == true) $this->etat=false;
 else
 echo " le vehicule est a l'arret </br>";
	 
 }

 function roule()
 if($this->etat == false)
 {
	 $this->etat= true;
	 $this->kilometre++;
	 $this->qteCarbu--;
 }

}
// Exercice 3 :Création classes: Voiture et Train 
 
 // creation de deux classes filles
 
// classe fille Voiture

class Voiture extends Vehicule{

	//attributs 
	var $typeCarburant;
	var $nbPorte;

	function __construct()
	{   //constructeur
		$nb=func_num_args();
		//l'ensemble des arguments
		$arguments=func_get_args();
		
						
		switch ($nb) {
			
			
			
			// constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilometre"";
				$this->qteCarbu="";
				$this->typeCarburant="";
				$this->nbPorte="";
				break;
			
			//constructeur parametre
			case 4:
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qteCarbu=$arguments[3];
				$this->roule=$args[4];
				break;
				
//constructeur parametre
			case 5 :
				$this->marque=$arguments[0];
				$this->couleur=$arguments[1];
				$this->kilometre=$arguments[2];
				$this->qteCarbu=$arguments[3];
			    $this->typeCarburant=$arguments[5];
				$this->nbPorte=$arguments[6];
				$this->roule=$args[4];
				break;

			default: echo"erreur";
				break;
		}

	}
			
			function affichage(){
				parent::affichage();
		echo"Type de carburant : "
		"<br>";
		echo"Nombre de portes : "
		"<br>";
	}
	
}//fin de la classe Voiture 

// classe  fille Train
class Train extends Vehicule{

    //attributs 
	var $type;
	var $nbwagon;



	function __construct()
	{
		//constructeur

		$nb=func_num_args();
		$args=func_get_args();

		switch ($nb) 
		{
			
			
			// constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilometre="";
				$this->qteCarbu="";
				$this->type="";
				$this->nbwagon="";
				break;
			//constructeur parametre
			case 4:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				break;
//constructeur parametre
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"erreur";
				break;
		}

	}

	    	function affichage(){
			Vehicule::affichage();
		 echo"Type de train : "
		"<br>";
		 echo"Nombre de wagons :"
		"<br>";
		
		
		
		
	}
}//fin de la classe train

// Implémentation de l'exercice 3
echo"Voiture";

$V1 = new Voiture("mercedes","peugeot",65000,50,0,"essence",6);
$V1->roule(55,0.1);
$V1->affichage();
echo"Train";

$T1 = new Train("metro 1","Rouge",30000,1000,0,"electrique",15);
$T1->roule(2000,0.2);
$T1->affichage();

//Exercice 4
 
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";

$V2 = new Voiture("bmw","citroen",100000,50,0,"gasoil",6);
$V2->roule(90,1.0);

$T2 = new Train("metro 4","rose",750000,5000,0,"electrique",10);
$T2->roule(1000,0.25);


// déclaration du tableau de véhicule

$tableau= array(1=>$V2,2=>$T2);

//boucle for 
for ($i=1; $i < 2; $i++) { 
echo"Voiture";
	echo $tableau[1]->affichage();
	echo"<br>";
	echo"Train";
	echo $tableau[2]->affichage();
	echo"<br>";
}
// fin du php
?>