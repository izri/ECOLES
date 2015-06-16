@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@include('flash')
			<div class="panel panel-default">
                <div class="panel-heading"><b>Liste des produits</b></div>
				<div class="panel-body">
                    <p class="pull-right"><a class="btn btn-primary" href="{{ route('produits.create') }}">Ajouter</a></p>
				    @if(count($produits) === 0)
                        <p>Pas de produits</p>
                    @else
					<p>Nombre de produits : {{ count($produits) }}</p>
					<table class="table table-hover">
						<th>ID</th>
						<th>Nom</th>
						<th>Prix unitaire</th>
						<th>Quantité</th>
						<th>Action</th>
                        @foreach($produits as $produit)
                            <tr>
								<td>{{ $produit->id }}</td>
								<td>{{ $produit->name }}</td>
								<td>{{ $produit->price }}€</td>
								<td>{{ $produit->quantity }}</td>
								<td><a class="btn btn-info btn-sm" href="{{ route('produits.edit', $produit) }}">Editer</a></td>
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
