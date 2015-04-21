//Exercice: 2
<html>
<head>
	<title>TD 5</title>
	<meta charset="utf-8">
</head>
	<?php
	class Vehicule
	{
		var $marque;
		var $couleur;
		var $kilometres;
		var $qteCarburant;
		var $etat;

		function __construct()
		{
			$num = func_num_args(); 
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->marque = "vide";
					$this->couleur = "vide";
					$this->kilometres = 0;
					$this->qteCarburant = 0;
					$this->etat = "Arret";
					break;
				case 4:
					$this->marque = $args[0];
					$this->couleur = $args[1];
					$this->kilometres = $args[2];
					$this->qteCarburant = $args[3];
					$this->etat = "Arret";
					break;
				
			}
		}

		function afficherInfo()
		{
			echo("<br>Les informations concernant le véhicule :<br>");
			echo("Marque : ".$this->marque."<br>");
			echo("Couleur : ".$this->couleur."<br>");
			echo("Kilométrage : ".$this->kilometres." km<br>");
			echo("Carburant : ".$this->qteCarburant." L<br>");
			echo("Etat : ".$this->etat."<br>");
		}
//Fonction qui nous permet de savoir que le vehicule est en mouvement
		function EtatRoule()
		{
			$this->etat = "Roule";
			$this->kilometres++;
			$this->qteCarburant--;
		}
//Fonction qui nous permet de savoir que le vehicule est a l'arret
		function EtatArret()
		{
			$this->etat = "Arret";
			echo("<br>Le véhicule est à l'arret :<br>");
		}
	}
//Exercice n:3
	class Voiture extends Vehicule
	{
		var $marque;
		var $couleur;
		var $kilometres;
		var $qteCarburant;
		var $etat;
		var $typeCarburant;
		var $nbportes;

		function __construct()
		{
			$num = func_num_args();
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->marque = "vide";
					$this->couleur = "vide";
					$this->kilometres = 0;
					$this->qteCarburant = 0;
					$this->etat = "Arret";
					$this->typeCarburant = "Aucun";
					$this->nbportes = 0;
					break;
				case 6:
					$this->marque = $args[0];
					$this->couleur = $args[1];
					$this->kilometres = $args[2];
					$this->qteCarburant = $args[3];
					$this->etat = "Arret";
					$this->typeCarburant = $args[4];
					$this->nbportes = $args[5];
					break;
				
			}
		}

		function InfoVehicule()
		{
			parent::InfoVehicule();
			echo("Le vehicule est un : ".$this->typeCarburant."<br>");
			echo("Le vehicule possede : ".$this->nbportes. " portes." "<br>");
		}

		function EtatRoule()
		{
			parent::EtatRoule();
		}

		function EtatArret()
		{
			parent::EtatArret();
		}
	}

	class Train extends Vehicule
	{

		var $marque;
		var $couleur;
		var $kilometres;
		var $qteCarburant;
		var $etat;
		var $typeTrain;
		var $nbWagons;

		function __construct()
		{
			$num = func_num_args();
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->marque = "vide";
					$this->couleur = "vide";
					$this->kilometres = 0;
					$this->qteCarburant = 0;
					$this->etat = "Arret";
					$this->typeTrain = "Aucun";
					$this->nbWagons = 0;
					break;
				case 6:
					$this->marque = $args[0];
					$this->couleur = $args[1];
					$this->kilometres = $args[2];
					$this->qteCarburant = $args[3];
					$this->etat = "Arret";
					$this->typeTrain = $args[4];
					$this->nbWagons = $args[5];
					break;
				
			}
		}

		function InfoVehicule()
		{
			parent::InfoVehicule();
			echo("Type de carburant pour le train: ".$this->typeTrain."<br>");
			echo("Il possede: ".$this->nbWagons." wagons.""<br>");
		}

		function EtatRoule()
		{
			parent::EtatRoule();
		}

		function EtatArret()
		{
			parent::EtatArret();
		}
	}

	$vehicule = new Vehicule("BMW", "Blancge", 60000, 42);
	$vehicule->InfoVehicule();
	$vehicule->EtatRoule();
	$vehicule->InfoVehicule();
	$vehicule->EtatArret();
	$voiture = new Voiture("Audi", "Grise", 75000, 40, "Diesel", 3);
	$train = new Train("TGV", "Turquoise", 100000, 0, "TGV", 28);
	$tab = array($vehicule, $voiture, $train);
	
	?>
<body>

</body>
</html>