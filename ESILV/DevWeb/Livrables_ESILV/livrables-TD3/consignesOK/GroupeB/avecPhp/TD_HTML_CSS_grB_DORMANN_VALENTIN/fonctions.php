<?PHP
	/* 	Fonction:	verifie qu'une chaine est un nom
	 *	Entree:		le nom de l'utilisateur (string $nom)
	 *  Sortie:		un boolen (bool $result) TRUE: nom valide; FALSE: non invalide
	 *  Type: 		bool $result(string $nom) 
	 *	Mecanisme:
	 *  I.			Verification succesive de condition entrainant/ excluant la validite du nom  */
	function IsNom($nom)
	{
		$result=false;
		$lettre="abcdefghijklmnopqrstuvwxyz-";
		// si vide alors nom pas valide 
		if($nom==""){$result=false;}
		/* strspn(): renvoie le nombre de caracteres dans une chaine jusqu'a ce 
		             qu'il rencontre un caractere abscent de la seconde chaine
		   strlen(): renvoie la longueur d'une chaine
		   strtolower(): met une chaine en minuscule
		   si presence de caracteres non autorise alors nom pas valide */
		elseif(strspn(strtolower($nom),$lettre)<strlen($nom)){$result=false;}
		// un nom doit mesurer entre 3 et 30 caracteres 
		elseif((strlen($nom)<3)||(strlen($nom)>=30)){$result=false;}
		// si presence de "--" alors nom non valide 
		elseif(strpos($nom,"--")!==false){$result=false;}
		// sinon il est valide 
		else{$result=true;}
		return $result;
	}
	/* 	Fonction:	verifie qu'une chaine est un e-mail
	 *	Entree:		l'e-mail de l'utilisateur (string $mail)
	 *  Sortie:		un boolen (bool $result) TRUE: nom valide; FALSE: non invalide
	 *  Type: 		bool $result(string $mail) 
	 *	Mecanisme:
	 *  I.			Verification succesive de condition entrainant/ excluant la validite de l'e-mail  */
	function IsMail($mail)
	{
		$result=false;
		$caractereAutorise="abcdefghijklmnopqrstuvwxyz0123456789-_@.";
		$lettre="abcdefghijklmnopqrstuvwxyz";
		// si vide alors mail pas valide
		if($mail==""){$result=false;}
		// si presence de caracteres non autorise alors mail pas valide 
		elseif(strspn(strtolower($mail),$caractereAutorise)<strlen($mail)){$result=false;}
		// si plusieurs "@" alors mail non valide
		elseif(substr_count($mail,"@")!=1){$result=false;}
		// si "@" se trouve a l'une des extremites alors mail non valide
		elseif((strpos($mail,"@")==0)||(strpos($mail,"@")==(strlen($mail)-1))){$result=false;}
		// si abscence de "." a la 4eme ou 3eme position avant la fin alors mail non valide
		elseif(!(($mail[strlen($mail)-3]==".")||($mail[strlen($mail)-4]=="."))){$result=false;}
		// un mail doit mesurer entre 6 et 50 caracteres
		elseif((strlen($mail)<6)||(strlen($mail)>=50)){$result=false;}
		// les extremites d'un mail doivent etre une lettre
		elseif((strspn(strtolower($mail[0]),$lettre)==0)||(strspn(strtolower($mail[strlen($mail)-1]),$lettre)==0)){$result=false;}
		// si presence de "..", "@.", ".@" alors mail non valide
		elseif((strpos($mail,"..")!==false)||(strpos($mail,".@")!==false)||(strpos($mail,"@.")!==false)){$result=false;}
		// sinon elle est valide */
		else{$result=true;}
		return $result;
	}
	/*  Fonction:	verifie qu'une chaine est un numero de carte 
	 *	Entree:		le numero de carte de l'utilisateur (string $noCarte)
	 *  Sortie:		un boolen (bool $result) TRUE: nom valide; FALSE: non invalide
	 *  Type: 		bool $result(string $noCarte) 
	 *	Mecanisme:
	 *  I.			Verification succesive de condition entrainant/ excluant la validite du numero de carte  */
	function IsNoCarte($noCarte)
	{
		$result=false;
		$chiffre="0123456789";
		// si vide alors numero de carte non valide
		if($noCarte==""){$result=false;}
		// si presence de caracteres non autorise alors nom pas valide
		elseif(strspn(strtolower($noCarte),$chiffre)<strlen($noCarte)){$result=false;}
		// un numero de carte doit mesurer 16 caracteres
		elseif(strlen($noCarte)!=16){$result=false;}
		// sinon il est valide
		else{$result=true;}
		return $result;
	}
	/*  Fonction:	verifie qu'une chaine est une date au format mm/aa
	 *	Entree:		la date d'expiration dela carte bancaire de l'utilisateur (string $date)
	 *  Sortie:		un boolen (bool $result) TRUE: nom valide; FALSE: non invalide
	 *  Type: 		bool $result(string $date) 
	 *	Mecanisme:
	 *  I.			Verification succesive de condition entrainant/ excluant la validite du numero de carte  */
	function IsDate($date)
	{
		$result=false;
		$caractereAutorise="0123456789/";
		// si vide alors date non valide
		if($date==""){$result=false;}
		// si presence de caracteres non autorise alors date pas valide
		elseif(strspn($date,$caractereAutorise)<strlen($date)){$result=false;}
		// si plusieurs "/" alors date non valide
		elseif(substr_count($date,"/")!=1){$result=false;}
		// une date doit mesurer 5 caracteres
		elseif(strlen($date)!=5){$result=false;}
		// si abscence du caractere central "/" alors c'est pas une date
		elseif($date[2]!="/"){$result=false;}
		// si le mois n'est pas compris entre 1 et 12 inclus alors ce n'est pas une date
		elseif((substr($date,0,2)<1)||(substr($date,0,2)>12)){$result=false;}
		// sinon elle est valide
		else{$result=true;}
		return $result;
	}
?>