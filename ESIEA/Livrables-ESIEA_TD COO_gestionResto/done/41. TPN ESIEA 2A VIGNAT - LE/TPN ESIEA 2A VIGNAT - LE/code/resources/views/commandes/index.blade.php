@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@include('flash')
			<div class="panel panel-default">
                <div class="panel-heading"><b>Liste des commandes</b></div>
				<div class="panel-body">
                    @if($readyProduit && $readyTable)
                    <p class="pull-right"><a class="btn btn-primary" href="{{ route('commandes.create') }}">Créer</a></p>
					@endif

					@if(!$readyProduit)
                    <div class="alert alert-danger" role="alert"><b>Attention ! </b><br>
                        Vous devez avoir au moins un produit pour créer une commande.<br>
                    <a class="btn btn-danger" href="{{ route('produits.create') }}">Ajouter un produit</a></div>
					@endif

					@if(!$readyTable)
                    <div class="alert alert-danger" role="alert"><b>Attention ! </b><br>
                        Vous devez avoir au moins une table pour créer une commande.<br>
                    <a class="btn btn-danger" href="{{ route('tables.create') }}">Ajouter une table</a></div>
                    @endif

					@if(count($commandes) === 0)
                        <p>Pas de commandes</p>
                    @else
					<p>Nombre de commandes : {{ count($commandes) }}</p>
					<table class="table table-hover">
						<th>Table</th>
						<th>Client</th>
						<th>Produit</th>
						<th>Quantité</th>
						<th>Total</th>
						<th>Action</th>
                        @foreach($commandes as $commande)
                            <tr>
								<td>{{ $commande->table->number }}</td>
								<td>{{ $commande->client->last_name }}, {{ $commande->client->first_name }}</td>
								<td>{{ $commande->produit->name }}</td>
								<td>{{ $commande->quantity }}</td>
								<td>{{ $commande->total }}</td>
								<td><a class="btn btn-info btn-xs" href="{{ route('clients.show', $commande->client) }}">Client</a></td>
							</tr>
                        @endforeach
					</table>
                    @endif
				</div>
			</div>
		</div>
	</div>
</div>
@endsection
