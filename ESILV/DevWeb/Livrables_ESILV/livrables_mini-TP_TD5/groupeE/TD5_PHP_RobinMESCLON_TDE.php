<?php 

//Exercice 2


class Vehicule
{
	
	
	var $marque;
	var $couleur;
	var $kms;
	var $qtecarburant;
	


	function __construct() 
	{ 
		$args=func_get_args();
		$num=func_num_args();
		

			switch ($num) 
			{

			case 0:
				$this->marque="Marque non communiquée";
				$this->couleur="Couleur non communiquée";
				$this->kms=0;
				$this->qtecarburant="Non communiquée";
				break;

			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kms=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			default:
				echo"Pas d'argument";
				break;
		}
	}

    
	function arret(){
		$this->roule=0;
	}
	


	function roule($kmroule,$litreaukm){
		
		$this->kms=$this->kms+=$kmroule;
		
		$consommer=$kmroule*$litreaukm;
		
		$this->roule=1;
		
		$this->kms++;
		
		$this->qtecarburant=$this->qtecarburant=-$consommer;
	}
	

	
	function Affichage(){
		
		echo "Informations sur le véhicule demandé";
		echo"Marque du véhicule : ".$this->marque."<br>";
		echo"Couleur du véhicule : ".$this->couleur."<br>";
		echo"Kilométrage du véhicule : ".$this->kms."km <br>";
		echo "Carburant restant : ".$this->consommer. "L<br>";
	}
	

} 

//Exercice 3


class Voiture extends Vehicule{

	
	var $typeCarburant;
	var $nbPortes;

	function __construct()
	{
		$num=func_num_args();
		$args=func_get_args();
						
		switch ($num) {
			
			
			
			
			case 0:
				$this->marque="Marque non communiquée";
				$this->couleur="Couleur non communiquée";
				$this->kms=0;
				$this->qtecarburant="";
				$this->typeCarburant="";
				$this->nbPortes="Nombre de portes non communqué";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kms=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kms=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				$this->typeCarburant=$args[5];
				$this->nbPortes=$args[6];
				break;

			default:
				echo"Sans arguments";
				break;
		}

	}
			
			function Affichage(){
				parent::Affichage();
		echo"Type de carburant : ".$this->typeCarburant."<br>";
		echo"Nombre de portes : ".$this->nbPortes." Portes<br>";
	}
	
}




class Train extends Vehicule{

    
	var $type;
	var $nbwagons;



	function __construct()
	{
		

		$num=func_num_args();
		$args=func_get_args();

		switch ($num) 
		{
			
			
			
			case 0:
				$this->marque="Marque non communiquée";
				$this->couleur="Couleur non communiquée";
				$this->kms="";
				$this->qtecarburant="";
				$this->type="Type Non défini";
				$this->nbwagon="Nombre de wagons non communiqué";
				break;
			
			case 5:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kms=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				break;

			case 7:
				$this->marque=$args[0];
				$this->couleur=$args[1];
				$this->kms=$args[2];
				$this->qtecarburant=$args[3];
				$this->roule=$args[4];
				$this->type=$args[5];
				$this->nbwagon=$args[6];
				break;

			default:
				echo"pas d'arguments <br>";
				break;
		}

	}

			function Affichage(){
			Vehicule::Affichage();
		echo"Type de train : ".$this->type."<br>";
		echo"Nombre de wagons : ".$this->nbwagon." wagons<br>";
		
	}
}

//Exercice 4
 
echo"<br>";
echo"<br>";
echo"<br>";
echo"<br>";
echo"<h3><u>Implémentation de l'exercice 4</u></h3>";


$V2 = new Voiture("Renault","Twingo",123000,80,0,"Essence",3);
$V2->roule(115,1.8);

$T2 = new Train("T3","Vert et Blanc",600000,50000,0,"Electrique",8);
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

