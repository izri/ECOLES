<!DOCTYPE HTML>
<HTML lang="fr">
	<HEAD>
		<META charset="character_set"> </META>
		<TITLE>TD Seance 7 & 8</TITLE>
	</HEAD>
	<BODY>
		<?PHP
			class Vehicule{
				// attributs 
				public $_marque;        // marque
				public $_couleur;       // couleur
				public $_nbKm;          // distance parcourue totale
				public $_qteReservoir;  // quantite de carvurant disponible dans reservoir
				public $_etat;          // true: en mouvement, false: a l'arret
				public $_litreParKm;    // consommation de carburant par kilometre parcourue
				// constructeur
				public function __construct(){
					$nbarg = func_num_args(); 	// recuperation du nombre d'arguments
					$arg = func_get_args();		// recuperation des arguments
					switch($nbarg){
						case 0:
							$this->_marque = "NC";
							$this->_couleur = "NC";
							$this->_nbKm = 0;
							$this->_qteReservoir = 0;
							$this->_etat = false;
							$this->_litreParKm = 0.0;
							break;
						case 4:
							$this->_marque = $arg[0];
							$this->_couleur = $arg[1];
							$this->_nbKm = $arg[2];
							$this->_qteReservoir = $arg[3];
							$this->_etat = false;
							$this->_litreParKm = 0.01;
							break;
						case 6:
							$this->_marque = $arg[0];
							$this->_couleur = $arg[1];
							$this->_nbKm = $arg[2];
							$this->_qteReservoir = $arg[3];
							$this->_etat = $arg[4];
							$this->_litreParKm = $arg[5];
							break;
						default:
							echo "ERREUR: nombre d'arguments incorrect! <BR />";
							break;
					}
				}
				// accesseurs
				// getter Lecture
				public function GetMarque(){
					return $this->_marque;
				}
				public function GetCouleur(){
					return $this->_couleur;
				}
				public function GetNbKm(){
					return $this->_nbKm;
				}
				public function GetQteReservoir(){
					return $this->_qteReservoir;
				}
				public function GetLitreParKm(){
					return $this->_litreParKm;
				}
				// setter Ecriture
				public function SetMarque($val){
					$this->_marque = $val;
				}
				public function SetCouleur($val){
					$this->_couleur = $val;
				}
				public function SetNbKm($val){
					$this->_nbKm = $val;
				}
				public function SetQteReservoir($val){
					$this->_qteReservoir = $val;
				}
				public function SetLitreParKm($val){
					$this->_litreParKm = $val;
				}
				// fonctions
				public function Resume(){
					echo "<FONT color='blue'>Véhicule</FONT>"."<BR />";
					echo "Marque: ".$this->GetMarque()."<BR />";
					echo "Couleur: ".$this->GetCouleur()."<BR />";
					echo "Kilométrage: ".$this->GetNbKm()." Km"."<BR />";
					echo "Volume réservoir: ".$this->GetQteReservoir()." L"."<BR />";
					echo "Consommation: ".$this->GetLitreParKm()." L/Km"."<BR />";
				}
				public function Arret(){
					// si le vehicule est en mouvent alors on l'arrete
					if($this->_etat){$this->_etat = false;}
					echo "Le vehicule est à l'arret <BR />";
				}
				public function Roule($distance){
					// si le vehicule est a l'arret et peut rouler (carburant restant dans le reservoir)
					if(!$this->_etat && $this->_qteReservoir > 0){
						$this->_etat = true;
						echo "Le vehicule roule <BR />"; // de la distance $distance
						$this->_nbKm+= $distance; // distance parcourue ajouter au compteur
						$this->_qteReservoir-= $distance*$this->_litreParKm; // perte de carburant
						if($this->_qteReservoir <= 0){
							$this->_etat = false;
							echo "Le vehicule ne peut plus rouler. Faites le plein! <BR />";
						}
					}
				}
			}
			
			class Voiture extends Vehicule{
				// attributs
				private $_typeCarburant;  // type du crburant utilise
				private $_nbPorte;        // nombre de porte (portiere, coffre)
				// constructeur
				public function __construct(){
					$nbarg = func_num_args(); 	// recuperation du nombre d'arguments
					$arg = func_get_args();		// recuperation des arguments
					switch($nbarg){
						case 0:
							$this->_marque = "NC";
							$this->_couleur = "NC";
							$this->_nbKm = 0;
							$this->_qteReservoir = 0;
							$this->_litreParKm = 0.0;
							$this->_typeCarburant = "NC";
							$this->_nbPorte = 0;
							break;
						case 7:
							$this->_marque = $arg[0];
							$this->_couleur = $arg[1];
							$this->_nbKm = $arg[2];
							$this->_qteReservoir = $arg[3];
							$this->_litreParKm = $arg[4];
							$this->_typeCarburant = $arg[5];
							$this->_nbPorte = $arg[6];
							break;
						default:
							echo "ERREUR: nombre d'arguments incorrect! <BR />";
							break;
					}
				}
				// accesseurs
				// getter Lecture
				public function GetTypeCarburant(){
					return $this->_typeCarburant;
				}
				public function GetNbPorte(){
					return $this->_nbPorte;
				}
				// setter Ecriture
				public function SetTypeCarburant($val){
					$this->_typeCarburant = $val;
				}
				public function SetNbPorte($val){
					$this->_nbPorte = $val;
				}
				// fonction
				public function Resume(){
					Vehicule::Resume(); // utilisation de la fonction Resume() de la classe mere Vehicule
					echo "<FONT color='green'>Voiture</FONT>"."<BR />";
					echo "Type de carburant: ".$this->GetTypeCarburant()."<BR />";
					echo "Nombre de portes(s): ".$this->GetNbPorte()."<BR />";
				}
			}
			
			class Train extends Vehicule{
				// attributs
				private $_type;     // type de train
				private $_nbWagon;  // nombre de wagon
				// constructeur
				public function __construct(){
					$nbarg = func_num_args(); 	// recuperation du nombre d'arguments
					$arg = func_get_args();		// recuperation des arguments
					switch($nbarg){
						case 0:
							$this->_marque = "NC";
							$this->_couleur = "NC";
							$this->_nbKm = 0;
							$this->_qteReservoir = 0;
							$this->_litreParKm = 0.0;
							$this->_type = "NC";
							$this->_nbWagon = 0;
							break;
						case 7:
							$this->_marque = $arg[0];
							$this->_couleur = $arg[1];
							$this->_nbKm = $arg[2];
							$this->_qteReservoir = $arg[3];
							$this->_litreParKm = $arg[4];
							$this->_type = $arg[5];
							$this->_nbWagon = $arg[6];
							break;
						default:
							echo "ERREUR: nombre d'arguments incorrect! <BR />";
							break;
					}
				}
				// accesseurs
				// getter Lecture
				public function GetType(){
					return $this->_type;
				}
				public function GetNbWagon(){
					return $this->_nbWagon;
				}
				// setter Ecriture
				public function SetType($val){
					$this->_type = $val;
				}
				public function SetNbWagon($val){
					$this->_nbWagon = $val;
				}
				// fonction
				public function Resume(){
					Vehicule::Resume(); // utilisation de la fonction Resume() de la classe mere Vehicule
					echo "<FONT color='green'>Train</FONT>"."<BR />";
					echo "Type: ".$this->GetType()."<BR />";
					echo "Nombre de wagon(s): ".$this->GetNbWagon()."<BR />";
				}
			}
		?>
		<?PHP
			// declaration des variables en utilisant les classes ci dessus
			$v1 = new Voiture("Mercedes","Gris",1000,50,0.1,"Gazoil",5);
			$v2 = new Voiture("Bugatti","Rouge",80000,70,0.5,"Essence",2);
			$t1 = new Train("RER A","Blanc",55000,1500,1,"Electrique",25);
			$t2 = new Train("Tram 1","Orange et jaune",500000,70000,0.9,"Electrique",10);

			$v1->Roule(200);
			$v1->Arret();
			echo "<BR /><BR />";
			
			$tableau= array(0=>$v1,1=>$v2,2=>$t1,3=>$t2);
			// affichage
			for($i=0; $i < 4; $i++){ 
				echo $tableau[$i]->Resume();
				echo"<BR />";
			}
		?>
	</BODY>
<HTML>