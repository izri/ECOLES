<?php 

//Exercice 2


class Vehicule
{
	var $marque;
	var $couleur;
	var $kilomètres;
	var $qtecarburant;
	


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
				$this->qtecarburant="";
				break;

			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			default:
				echo"Erreur";
				break;
		}
	}

    
	function arret(){	//méthode "arret"
		
		$this->roule=0;
	}
	

	
	function roule($kmroule,$litreaukm){
		
		$carbu_used=$kmroule*$litreaukm;
		
		$this->roule=1;
	
		$this->kilomètres=$this->kilomètres+=$kmroule;
		
		$this->kilomètres++;
	
		$this->qtecarburant=$this->qtecarburant-=$carbu_used;
	}


	function Affichage(){
		
		echo"<font color=black>Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->kilomètres."<br>";
		echo"Quantité de carburant : " .$this->qtecarburant."<br>";
		
	}}

echo"<h3><u>EXERCICE II</u></h3>";


$voiture = new Vehicule("Audi","Noir",50,60,0);
$voiture->roule(20,1);
$voiture->arret();
$voiture->Affichage();



//Exercice 3


class Voiture extends Vehicule{

	var $typecarburant;
	var $nbporte;

	function __construct()
	{
		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
			
			
			
			
			case 0:
				$this->marque="";
				$this->couleur="";
				$this->kilomètres="";
				$this->qtecarburant="";
				$this->typecarburant="";
				$this->nbporte="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				$this->typecarburant=$args[5];
				$this->nbporte=$args[6];
				break;

			default:
				echo"Erreur";
				break;
		}

	}
			
			function Affichage(){
				parent::Affichage();
		echo"<font color=red>Type de carburant : ".$this->typecarburant."<br>";
		echo"Nombre de portes : ".$this->nbporte."</font><br>";
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
				$this->qtecarburant="";
				$this->type="";
				$this->nbwagon="";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kilomètres=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"Erreur<br>";
				break;
		}

	}

	     
			function Affichage(){
			Vehicule::Affichage();
		echo"<font color=green>Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon."</font><br>";
		
		
	}}

echo"<h3><u>EXERCICE III</u></h3>";

echo"<h4>Voiture</h4>";
$V1 = new Voiture("BMW","X6",3000,95,0,"Essence",5);
$V1->roule(70,0.6);
$V1->Affichage();
echo"<h4>Train</h4>";
$T1 = new Train("Thalys","Bleu, Blanc, Violet",38000,2500,0,"Electrique",8);
$T1->roule(3700,0.5);
$T1->Affichage();



//Exercice 4

 echo"<h3><u>EXERCICE IV</u></h3>";



$V2 = new Voiture("Porsche","Cayenne",200000,120,0,"Diesel",5);
$V2->roule(115,1.8);

$T2 = new Train("T.E.R.","Rouge, Bleu, Blanc",900000,70000,0,"Electrique",10);
$T2->roule(3000,0.4);



$tableau= array(1=>$V2,2=>$T2);


for ($i=1; $i < 2; $i++) { 
echo"<h4>Voiture</h4>";
	echo $tableau[1]->Affichage();
	echo"<br>";
	echo"<h4>Train</h4>";
	echo $tableau[2]->Affichage();
	echo"<br>";
}
?> 