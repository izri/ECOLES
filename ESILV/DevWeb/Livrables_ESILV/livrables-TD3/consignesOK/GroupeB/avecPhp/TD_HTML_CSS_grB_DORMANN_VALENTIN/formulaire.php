<!DOCTYPE html>
<HTML lang="fr"> 
	<!-- inclusion des fonctions neccessaires au bon deroulement -->
	<?php include "fonctions.php"; ?>
    <HEAD>
		<META charset="character_set"> </META>
        <TITLE>Formulaire de paiement</TITLE>
		<LINK href="formulaire.css" rel="stylesheet" type="text/css" />
    </HEAD>
	<BODY>
		<?PHP 
			// si on a cliquer sur "Confirmer le paiement" alors on recupere les valeurs saisies
			if(isset($_POST['valider']))
			{
				$valider=$_POST['valider'];
				if(isset($_POST['civilite'])){$civilite=$_POST['civilite'];}
				$nom=$_POST['nom'];
				$courriel=$_POST['courriel'];
				$carte=$_POST['carte'];
				$noCarte=$_POST['noCarte'];
				$expirationDate=$_POST['expirationDate'];
				// si les champs obligatoires sont mal remplies
				if(!($nom <> "")||!($courriel <> "")||!($noCarte <> "")||!($expirationDate <> ""))
				{
					echo "Au moins l'un des champs est vide";
				}
			}
			else // sinon on les met a vides
			{
				$valider="";
				$civilite="";
				$nom="";
				$courriel="";
				$carte="";
				$noCarte="";
				$expirationDate="";
			}
		?>
		<H1>Formulaire de Paiement</H1>
		<FORM method="post" action="formulaire.php">
			<P class="info">Les champs obligatoires sont suivis par *</P>
			<H3 class="titre">Informations de contact</H3>
			<FIELDSET id="contact">
				<P id="civilite"><LABEL>Civilité</LABEL><BR />
					<!-- radio = 1 choix possible (selection de l'un entraine la deselection des autres) -->
					<INPUT type="radio" name="civilite" value="M" />Monsieur<BR />
					<INPUT type="radio" name="civilite" value="Mlle" />Mademoiselle<BR />
					<INPUT type="radio" name="civilite" value="Mme" />Madame
				</P>
				<LABEL>Nom: </LABEL>
					<?PHP
						// si on n'a pas appuyer sur le bouton valider alors affichage standard 
						if(!isset($_POST['valider'])){
							echo '<INPUT class="neutre" type="text" name="nom" maxlength="100"> *</INPUT><BR />'; }						}
						// sinon si on a appuyer sur valider mais oublier de remplir le champs alors affichage en rouge
						elseif(!(IsNom($nom))&&($valider <> "")){
							echo '<INPUT class="nok" type="text" name="nom" maxlength="100"> *</INPUT><BR />'; }
						// sinon champs complete et valide alors affichage en vert
						else{
							echo "<INPUT class=\"ok\" type=\"text\" name=\"nom\" value=\"".$nom."\" maxlength=\"100\"> *</INPUT><BR />"; }
					?>
				<LABEL>Courriel: </LABEL>
					<?PHP
						// si on n'a pas appuyer sur le bouton valider alors affichage standard
						if(!isset($_POST['valider'])){
							echo '<INPUT class="neutre" type="text" name="courriel" maxlength="100"> *</INPUT><BR />'; }
						// sinon si on a appuyer sur valider mais oublier de remplir le champs alors affichage en rouge
						elseif(!(IsMail($courriel))&&($valider <> "")){
							echo '<INPUT class="nok" type="text" name="courriel" maxlength="100"> *</INPUT><BR />'; }
						// sinon champs complete et valide alors affichage en vert
						else{
							echo "<INPUT class=\"ok\" type=\"text\" name=\"courriel\" value=\"".$courriel."\" maxlength=\"100\"> *</INPUT><BR />"; }
					?>
			</FIELDSET><HR />
			<H3 class="titre">Informations de paiement</H3>
			<FIELDSET id="paiement">
				<LABEL>Type de carte: </LABEL>
					<!-- Selection du type de carte parmi ceux proposes -->
					<SELECT name="carte">
						<OPTION value="visa">Visa</OPTION>
						<OPTION value="cb">CB</OPTION>
						<OPTION value="mastercard">MasterCard</OPTION>
						<OPTION value="paypal">PayPal</OPTION>
					</SELECT><BR />
					<LABEL>Numéro de carte: </LABEL>
						<?PHP
							// si on n'a pas appuyer sur le bouton valider alors affichage standard
							if(!isset($_POST['valider'])){
								echo '<INPUT class="neutre" type="text" name="noCarte" maxlength="100"> * en 16 chiffres</INPUT><BR />'; }
							// sinon si on a appuyer sur valider mais oublier de remplir le champs alors affichage en rouge
							elseif(!(IsNoCarte($noCarte))&&($valider <> "")){
								echo '<INPUT class="nok" type="text" name="noCarte" maxlength="100"> * en 16 chiffres</INPUT><BR />'; }
							//sinon champs complete et valide alors affichage en vert
							else{
								echo "<INPUT class=\"ok\" type=\"text\" name=\"noCarte\" value=\"".$noCarte."\" maxlength=\"100\"> * en 16 chiffres</INPUT><BR />"; }
						?>
					<LABEL>Date d'expiration: </LABEL>
						<?PHP
							// si on n'a pas appuyer sur le bouton valider alors affichage standard
							if(!isset($_POST['valider'])){
								echo '<INPUT class="neutre" type="text" name="expirationDate" maxlength="100"> * au format mm/aa</INPUT><BR />'; }
							// sinon si on a appuyer sur valider mais oublier de remplir le champs alors affichage en rouge
							elseif(!(IsDate($expirationDate))&&($valider <> "")){
								echo '<INPUT class="nok" type="text" name="expirationDate" maxlength="100"> * au format mm/aa</INPUT><BR />'; }
							// sinon champs complete et valide alors affichage en vert
							else{
								echo "<INPUT class=\"ok\" type=\"text\" name=\"expirationDate\" value=\"".$expirationDate."\" maxlength=\"100\"> * au format mm/aa</INPUT><BR />"; }
						?>
			</FIELDSET>
			<!-- creation du bouton submit -->
			<P id="bouton">
				<INPUT type="submit" name="valider" value="Confirmer le paiement" />
			</P>
		</FORM>
	</BODY>
</HTML>