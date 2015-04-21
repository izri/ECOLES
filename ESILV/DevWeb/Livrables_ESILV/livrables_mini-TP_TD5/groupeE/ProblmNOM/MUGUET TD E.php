<?php
class Vehicule{
	var $marque;
	var $couleur;
	var $kilometre;
	var $qteCarbu;


	function Vehicule(){
		$num=func_num_args();
		$arguments =func_get_args();
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
			default : echo "erreur";
			break ;
	}
}

function affichage() {
	echo "le vehicule de marque ".$this->marque.
	 "de couleur" .$this->couleur. 
	 "ayant roulé".$this->kilometre.
	 "contient".$this->qteCarbu.
	 "</br>" ;

}

function arret() {
	echo "le vehicule est à l'arrêt </br>";
	$this->mouv=false;

}

function roule() {
	$this->kilometre++;
	$this->qteCarbu--;
	$this->mouv= true;

	echo "le vehicule est en marche >/br>";
}








}

////EXERCICE3//////

class Train extends Vehicule{



var $typetrain;
var $nbrwagon;


function train(){
		$num=func_num_args();
		$arguments =func_get_args();


		switch($num)
		{
			case 0 :
			$this->marque="s";
			$this->couleur="";
			$this->kilometre="";
			$this->typetrain="";
			$this->nbrwagon="";
			break;


			case 4 : 
			$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->carburant=$args[3];
				$this->mouv=$args[4];
				break;


			case 6 : 
			$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->carburant=$args[3];
				$this->mouv=$args[4];
				$this->typetrain=$args[5];
				$this->nbrwagon=$args[6];
				break;	

default :
		echo"erreur";
		break;

			}
}




function affichage(){
	echo " Le train est de type de train : ".$this->typetrain.;
		"et il est composé de : ".$this->nbwagon.;
}

	


class voiture extends Vehicule{

	var $typeDeCarburant;
	var $nbrPortes;

	function Voiture {


	var $typeCarburant;
	var $nbPorte;

	function __construct()
	{


			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilometre="";
				$this->carburant="";
				$this->typeDeCarburant="";
				$this->nbrPortes="";
				break;
			
			case 4:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				$this->mouv=$args[4];
				break;

			case 6:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilometre=$args[2];
				$this->qteCarbu=$args[3];
				$this->mouv=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbrPortes=$args[6];
				break;

			default:
				echo"erreur";
				break;
		}

	}

	function affichage() {
	echo "La voiture roule au : ".$this->typeDeCarburant.
	 "et elle a " .$this->nbrPortes. 
	 ;

	}


$voiture1 = new Voiture("Lotus Exige","rouge",2000,55,0,"super95",2)
$voiture1->roule(30,40,1);
$voiture1->affichage();



$train1 = new train("TGV","Gris",13492,"’électrification ferroviaire",15)
$train1->roule(0,50,1);
$train1->affichage();




//////EXERCICE 4 //////



$voiture2 = new Voiture("Citroên picasso","grise",30348,45,5,"Diesel",2);
$Voiture2->roule(115,100,8);

$train2 = new Train("Train ExpressRégional","bleu et jaune",55000,55000,0,"électrification ferroviaire",7);
$train2->roule(3000,0.4);



$tab= array(1=>$voiture2,2=>$train2);


for ($i=1; $i < 2; $i++) { 

	echo $tab[1]->Affichage();
	

	echo $tab[2]->Affichage();
	
}
?> 


