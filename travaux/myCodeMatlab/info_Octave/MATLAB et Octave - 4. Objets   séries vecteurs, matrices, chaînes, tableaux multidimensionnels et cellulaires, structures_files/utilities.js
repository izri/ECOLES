// utilities.js  -     ENAC-IT / J.-D. Bonjour


function msgto ( mailID, mailDomain, mailSubject, linkText ) {
  // EPFL-ENAC-IT / JDB / 2007
  //     rev. 19.7.2012 : ajout du champ linkText
  // 
  // Fonction d'encodage par JavaScript des adresses Email (mesure anti-spam) avec :
  //     <script>msgto('jules.dupond', 'epfl.ch' ,'sujet...', 'texte affiché...')</script>
  // 
  // Les 2 premiers paramètres sont obligatoires. Les 3e et 4e sont facultatifs, mais
  // si l'on veut utiliser le 4e il faut fournir le 3e.
  
  if ( typeof mailSubject == "undefined" ) {
    paramSubject = "" ;
  } else {
    paramSubject = "?Subject=" + mailSubject ;
  }
  
  if ( typeof linkText == "undefined" ) {
    displayedText = mailID + "@" + mailDomain ;
  } else {
    displayedText = linkText ;
  }
  
  mytxt = "<a href=\"mailto:" + mailID + "@" + mailDomain + paramSubject + "\">" + displayedText + "</a>" ;
  document.write (mytxt);
}



function showhide(id) {
  // EPFL-ENAC-IT / JDB / 12.5.2010
  // Afficher/masquer le contenu d'une division via un lien avec :
  //   <a href="javascript:showhide('div1'); ">Afficher/Masquer</a>
  //      ou avec <a href="#" onClick="showhide('div1'); ">Afficher/Masquer</a>
  //      mais cette 2e techique repositionne browser au haut de la page
  //   <div id="div1" style="display: none;"> contenu de la division ... </div>
  
  if (document.getElementById) {
    var obj = document.getElementById(id);
    if (obj.style.display == "none") {
      obj.style.display = "block";
    } else {
      obj.style.display = "none";
    }
  }
}



function showhide_button(id,bouton) {
  // EPFL-ENAC-IT / JDB / 12.5.2010
  // Afficher/masquer le contenu d'une division via un bouton avec :
  //   <input type="button" onClick="javascript:showhide_button('div2',this);" value="Afficher">
  //   <div id="div2" style="display: none;"> contenu de la division ... </div>
  
  if (document.getElementById) {
    var obj = document.getElementById(id);
    if (obj.style.display == "none") {
      obj.style.display = "block";
      bouton.value = "Masquer / Hide";
      bouton.className = "bouton_masquer";
    } else {
      obj.style.display = "none";
      bouton.value = "Afficher / View";
      bouton.className = "bouton";
    }
  }
}


