<?php
class Vehicule
	{
		var $Marque;
		var $Couleur;
		var $Kilometre;
		var $QteCarburant;
		var $etat;

		function __construct()
		{
			$num = func_num_args();
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->Marque= "vide";
					$this->Couleur = "vide";
					$this->Kilometre = 0;
					$this->QteCarburant = 0;
					$this->etat = "Arret";
					break;
				case 4:
					$this->Marque = $args[0];
					$this->Couleur = $args[1];
					$this->Kilometre = $args[2];
					$this->QteCarburant = $args[3];
					$this->etat = "Arret";
					break;
				default:
					echo("erreur");
					break;
			}
		}

		function Affichage()
		{
			echo("<br>Information sur le Véhicule :<br>");
			echo("Marque : ".$this->Marque."<br>");
			echo("Couleur : ".$this->Couleur."<br>");
			echo("Kilométrage : ".$this->Kilometre." km<br>");
			echo("Carburant : ".$this->QteCarburant." L<br>");
			echo("Etat : ".$this->etat."<br>");
		}

		function Roule()
		{
			$this->etat = "Roule";
			$this->Kilometre++;
			$this->QteCarburant--;
		}

		function Arret()
		{
			$this->etat = "Arret";
		}
	}

	class Voiture extends Vehicule
	{
		var $Marque;
		var $Couleur;
		var $Kilometre;
		var $QteCarburant;
		var $etat;
		var $TypeCarbu;
		var $NbPortes;

		function __construct()
		{
			$num = func_num_args();
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->Marque = "vide";
					$this->Couleur = "vide";
					$this->Kilometre = 0;
					$this->QteCarburant = 0;
					$this->etat = "Arret";
					$this->TypeCarbu = "Aucun";
					$this->NbPortes = 0;
					break;
				case 6:
					$this->Marque = $args[0];
					$this->Couleur = $args[1];
					$this->Kilometre = $args[2];
					$this->QteCarburant = $args[3];
					$this->etat = "Arret";
					$this->TypeCarbu = $args[4];
					$this->NbPortes = $args[5];
					break;
				default:
					echo("Erreur");
					break;
			}
		}

		function Affichage()
		{
			parent::Affichage();
			echo("Type de carburant : ".$this->TypeCarbu."<br>");
			echo("Nombre de portes : ".$this->NbPortes."<br>");
		}

		function Roule()
		{
			parent::Roule();
		}

		function Arret()
		{
			parent::Arret();
		}
	}

	class Train extends Vehicule
	{

		var $Marque;
		var $Couleur;
		var $Kilometre;
		var $QteCarburant;
		var $etat;
		var $TypeTrain;
		var $NbWagon;

		function __construct()
		{
			$num = func_num_args();
			$args = func_get_args();
			switch($num)
			{
				case 0:
					$this->Marque = "vide";
					$this->Couleur = "vide";
					$this->Kilometre = 0;
					$this->QteCarburant = 0;
					$this->etat = "Arret";
					$this->TypeTrain = "Aucun";
					$this->NbWagon = 0;
					break;
				case 6:
					$this->Marque = $args[0];
					$this->Couleur = $args[1];
					$this->Kilometre = $args[2];
					$this->QteCarburant = $args[3];
					$this->etat = "Arret";
					$this->TypeTrain = $args[4];
					$this->NbWagon = $args[5];
					break;
				default:
					echo("erreur");
					break;
			}
		}
	

		function Affichage()
		{
			parent::Affichage();
			echo("Type de carburant : ".$this->TypeTrain."<br>");
			echo("Nombre de portes : ".$this->NbWagon."<br>");
		}

		function Roule()
		{
			parent::Roule();
		}

		function Arret()
		{
			parent::Arret();
		}
	}

	$vehicule1 = new Vehicule("Alfa", "Rouge", 100, 70);
	$vehicule1->Affichage();
	$vehicule1->Roule();
	$vehicule1->Affichage();
	$vehicule1->Arret();
	$voiture1 = new Voiture("BMW", "Bleu", 4000, 30, "Diesel", 3);
	$train1 = new Train("TGV", "Bleu", 30000, 0, "TGV", 60);
	$tab = array($vehicule1, $voiture1, $train1);
	foreach ($tab as $key => $value) {
		$value->Affichage();
	}
	?>