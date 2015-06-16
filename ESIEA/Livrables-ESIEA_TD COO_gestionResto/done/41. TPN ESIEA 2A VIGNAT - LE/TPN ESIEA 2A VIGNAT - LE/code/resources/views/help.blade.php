@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Premier pas</div>
				<div class="panel-body">
					Ce programme est dédié à la gestion d'un restaurant.<br>
					Il se découpe en plusieurs menus:
					<ul>
						<li>Tables</li>
						<li>Commandes</li>
						<li>Clients</li>
						<li>Produits</li>
					</ul>
					La présentation de ces différents menus se trouve ci-dessous<br>
				</div>
			</div>
		</div>
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Table</div>
				<div class="panel-body">
					Cette section permet de gérer les tables du restaurant.<br>
					L'utilisateur peut ajouter des tables, les assigner à des clients et accéder aux informations relatives à celui-ci ainsi que les commandes passées.
				</div>
			</div>
		</div>
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Clients</div>
				<div class="panel-body">
					La section &laquo;&nbsp;Clients&nbsp;&raquo; permet de consulter la liste des clients et d'en ajouter à la base de donnée.<br>
					Il est donc possible d'accéder aux informations d'un client et de les modifier. Chaque client possède:
					<ul>
						<li>un ID</li>
						<li>un nom</li>
						<li>un prénom</li>
						<li>une adresse</li>
						<li>un numéro de téléphone</li>
						<li>une adresse mail</li>
					</ul>
					Il est possible de préciser de manière facultative sa société et son age.<br>
					&Agrave; chacun est également associé un historique des tables. Cet historique détaille à quelles tables s'est assis le client et permet de voir la ou les commandes passées.
				</div>
			</div>
		</div>
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Commandes</div>
				<div class="panel-body">
					La section &laquo;&nbsp;Commandes&nbsp;&raquo; permet de consulter la liste des Commandes et d'en ajouter à la base de donnée.<br>
					Chaque commande est associée à une table et un client et consiste d'un produit, de la quantité de celui-ci et du prix total.
					Une commande ne peut donc qu'ếtre ajoutée que s'il existe au moins un produit et qu'un client est assigné à une table.
				</div>
			</div>
		</div>
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Produits</div>
				<div class="panel-body">
					La section &laquo;&nbsp;Produits&nbsp;&raquo; permet de consulter la liste des Produits et d'en ajouter à la base de donnée.<br>
					Un produit possède un:
					<ul>
						<li>un ID</li>
						<li>un nom</li>
						<li>un prix</li>
						<li>une quantité</li>
						<li>un description facultative</li>
					</ul>
					&Agrave; la création d'un produit, il faut donc préciser son nom, son prix et sa quantité.
					Il est aussi possible d'éditer les produits déjà existant.
				</div>
			</div>
		</div>
	</div>
</div>
</div>
@endsection
