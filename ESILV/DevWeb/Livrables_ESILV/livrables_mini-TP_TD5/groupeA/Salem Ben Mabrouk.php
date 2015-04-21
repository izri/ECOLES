<?php 
class Vehicule{
	var $Marque;//attributs
	var $Couleur;
	var $kilomètre;
	var $qteCarburant;
	var $marche; // 0 : Arret   1 : Marche
	function Vehicule($m,$c,$km,$qtec,$mrc) //Constructeur
	{
	$num = func_num_args(); //recupere le nombre des arguments envoyés au constructeur
	$arg= func_get_args(); // recupere leur valeurs
	switch($num)//On verifie le nb d'arguments que renvoie func_num_args 
	{
		case 0:
		$this -> Marque=$m;
		$this -> Couleur= $c;
		$this -> kilomètre = $km;
		$this -> qteCarburant = $qtec;
		$this -> marche =$mrc;
		break;
		case 5 :
		$this -> Marque= $arg[0];
		$this -> Couleur = $arg[1];
		$this -> kilomètre = $arg[2];
		$this -> qteCarburant = $arg[3];
		$this -> marche = $arg[4];
		break;
		default : echo " erreur";
	}
	
	}
	function affichage()//Methode pour afficher les caracteristiques de l'instance.
	{
		echo " Le véhicule de Marque ". $this-> Marque ." de Couleur ".$this-> Couleur ." a roulé ". $this -> kilomètre. "km, contient ". $this -> qteCarburant. " Litres d'essence.</br>";
		if($this -> marche ==1) echo " est en marche </br></br>";
	}
	function arret()
	{
		if($this -> marche==1)
			$this-> marche = 0;
		echo "Le véhicule s'arrete. </br></br>";
	}
	function roule()
	{
		$this -> marche = 1;
		echo "Le véhicule se met à rouler.";
		$this -> kilomètre +=1;
		$this -> qteCarburant-=0.2;
		echo " Il est maintenant à ".$this->kilomètre. " km, et contient maintenant ". $this->qteCarburant." litres.</br></br>";
	}
	function rooule()
	{
		echo "Le véhicule accelère !";
		$this ->kilomètre+=11;
		$this ->qteCarburant--;
		echo " Il est maintenant à ".$this->kilomètre. " km, et contient maintenant ". $this->qteCarburant." litres.</br></br>";

	}
}
//EXERCICE 3
class Voiture extends Vehicule{
	var $typeCarburant;//Voiture herite de Vehicule.
	var $nbPortes;
	function Voiture($typeCarburant1, $nbPortes1)//Création du contructeur
	{ 
		$this->typeCarburant = $typeCarburant1;
		$this->nbPortes = $nbPortes1;
	}
	public function infoVoiture()
	{
	echo "Le véhicule est un ". $this->typeCarburant. " et contient ". $this->nbPortes ." portes.</br></br>";
	}
	function roule()
	{
		Vehicule::roule();
	}
	function rooule()
	{
		Vehicule::rooule();
	}
	function arret()
	{
		Vehicule::arret();
	}

}

class Train extends Vehicule{
	var $type;
	var $nbWagon;
	function Train($type1,$nbWagon1){
		$this->type = $type1;
		$this->nbWagon = $nbWagon1;
	}
	public function infoTrain(){
		echo "Ce train est un ".$this->type." et est composé de ". $this->nbWagon." wagons.</br></br>";
	}
		function roule()
	{
		Vehicule::roule();
	}
	function rooule()
	{
		Vehicule::rooule();
	}
	function arret()
	{
		Vehicule::arret();
	}

}
//EXERCICE 4
$audi = new Voiture("diesel",5); //Instanciations (Création de nouvels objets)
$audi2 = new Voiture("essence",3);
$metro = new Train("metro",12);
$rer = new Train("RER",15);
$mercedes = new Vehicule("mercedes", "Grise",60000,70,1);

$tableau = array($audi,$audi2,$metro,$rer);//Creation du tableau
$audi->infoVoiture();
$audi2-> infoVoiture();
$metro-> infoTrain();
$rer-> infoTrain();
$mercedes->affichage();
$mercedes->arret();
$mercedes->roule();
$mercedes->roule();
$mercedes-> rooule();
$mercedes->arret();
$audi->roule();
$audi->rooule();
$audi->arret();
$rer->roule();
$rer->rooule();
$rer->arret();


?>

