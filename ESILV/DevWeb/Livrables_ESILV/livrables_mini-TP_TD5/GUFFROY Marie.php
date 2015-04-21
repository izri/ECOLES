<?php 
echo "Marie GUFFROY, TDE <br>";
echo"<center><h1><bold> TD.5 PHP POO</bold></h1></center>";

//Exercice 2: 
echo"<h3>Exercice 2</h3>";

class Vehicule
{
//attributs
	var $marque;
	var $couleur;
	var $kilomètres;
	var $qteCarburant;
	
	function __construct()
	{ 
		$num=func_num_args();
		$args=func_get_args();

			switch ($num) 
			{
             //par défaut:
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilomètres="";
				$this->qteCarburant="";
				break;

			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qteCarburant=$args[3];
				$this->roule=$args[4];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect";
				break;
		}
	}

	function arret(){
		$this->roule=0;
	}
	
 
	function roule($kmroule,$litreaukm){
		$carburant=$kmroule*$litreaukm;
		$this->roule=1;
		$this->kilomètres=$this->kilomètres+=$kmroule; //augmentation du nb de km
		$this->kilomètres++;
		$this->qteCarburant=$this->qteCarburant-=$carburant;
	}
	
	function Affichage(){
	// fonction affichage des données
		echo"Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->kilomètres."<br>";

	

  if ($this->qteCarburant > 20) 
    {
    echo "Quantité de carburant: ".$this->qteCarburant." litres <br>";
    } 
elseif (($this->qteCarburant< 20) && ($this->qteCarburant > 0)) 
    {
    echo "Quantité de carburant: Attention véhicule n'a plus que ".$this->qteCarburant." litres de carburant, Pensez à faire le plein<br>";
    }
elseif ($this->qteCarburant = 0) 
    {
    echo "Quantité de carburant:  Il n'y a plus de carburant.<br> Vous devez aller faire le plein";
    } 
else 
    {
    echo"Quantité de carburant :  Le véhicule n'a plus de carburant, Vous devez aller faire le plein.<br>";
   	}
}
}

$voiture = new Vehicule("Skoda","Bleu",4000,45,0);
$voiture->roule(70,1);
$voiture->arret();
$voiture->Affichage();

echo"<br>";

//Exercice 3:

echo"<h3>Exercice 3</h3>";

//ajout de la classe voiture à la classe véhicule
class Voiture extends Vehicule{ 
//ajout des attributs supplémentaires
	var $typeCarburant;
	var $nbPorte;

	function __construct()
	{
		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
			
			//constructeur par défaut
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilomètres="";
				$this->qteCarburant="";
				$this->typeCarburant="";
				$this->nbPorte="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qteCarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qteCarburant=$args[3];
				$this->roule=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbPorte=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect";
				break;
		}

	}
			
			// ajout type de carburant et nb de portes du véhicule à la fct Affichage
			function Affichage(){
				parent::Affichage();
		echo"Type de carburant : ".$this->typeCarburant."<br>";
		echo"Nombre de portes : ".$this->nbPorte."<br>";
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
				$this->kilomètres="";
				$this->qteCarburant="";
				$this->type="";
				$this->nbwagon="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qteCarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qteCarburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"Erreur: nombre d'arguments incorrect<br>";
				break;
		}

	}
			function Affichage(){ //ajout
			Vehicule::Affichage();
		echo"Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon."<br>";

	}
}



//création des objets
echo"<u>Train:<br></u>";
$T1 = new Train("RTram","Gris, Blanc",55000,1500,0,"Electrique",7);
$T1->roule(3000,0.4);
$T1->Affichage();
echo"<br>";
echo"<u>Voiture:<br></u>";
$V1 = new Voiture("Clio","Gris",5000,80,0,"Essence",4);
$V1->roule(55,0.6);
$V1->Affichage();
echo"<br>";


//Exercice 4: 

 echo"<h3>Exercice 4</h3>";

// nouveaux objets
$Train = new Train("TGV Ouigo","Bleu et Rose",900000,90,0,"Electrique",18);
$Train->roule(3000,0);
$Voiture= new Voiture("Citroen Evasion","bordeaux",35000,170,0,"Diesel",5);
$Voiture->roule(115,1.4);
// tableau
$tableau= array(1=>$Train,2=>$Voiture);

//lecture tableau 
for ($i=1; $i < 2; $i++) { 
    echo"<u>Train:<br></u>";
	echo $tableau[1]->Affichage();
	echo"<br>";echo"<u>Voiture:<br></u>";
	echo $tableau[2]->Affichage();
	echo"<br>";
	
}

?> 