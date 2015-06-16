@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@if(!empty($shortage))
			<div class="panel panel-danger">
				<div class="panel-heading">Produit{{ (count($shortage) > 1) ? 's' : '' }} en rupture de stock</div>
				<div class="panel-body">
					<ul>
					@foreach($shortage as $s)
						<li>{{ $s }}</li>
					@endforeach
					</ul>
				</div>
			</div>
			@endif
		</div>
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
				<div class="panel-heading">Produits</div>
				<div class="panel-body">
					Nombre de produit{{ ($produits > 1) ? 's' : '' }} : {{ $produits }}
				</div>
			</div>
			<div class="panel panel-default">
				<div class="panel-heading">Commandes</div>
				<div class="panel-body">
					Nombre de commande{{ ($commandes > 1) ? 's' : '' }} : {{ $commandes }}
				</div>
			</div>
			<div class="panel panel-default">
				<div class="panel-heading">Clients</div>
				<div class="panel-body">
					Nombre de client{{ ($clients > 1) ? 's' : '' }} : {{ $clients }}
				</div>
			</div>
		</div>
	</div>
</div>
@endsection
