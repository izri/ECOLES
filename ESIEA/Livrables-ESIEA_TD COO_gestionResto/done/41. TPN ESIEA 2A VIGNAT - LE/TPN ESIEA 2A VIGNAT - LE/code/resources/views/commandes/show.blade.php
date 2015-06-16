@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			<div class="panel panel-default">
                <div class="panel-heading">Commande de la table n° {{ $commandes->first()->table->number }} du {{ $commandes->first()->table->created_at }}</div>
                <div class="panel-body">
					{{--*/ $total = 0 /*--}}
					@foreach($commandes as $commande)
						<p class="lead">Commande n°{{ $commande->id }} :</p>
						{{--*/ $total += $commande->total /*--}}
						<p class="pull-right">{{ $commande->total }}€</p>
						<p>{{ $commande->produit->name }} x {{ $commande->quantity }}</p>
						<hr>
					@endforeach
					<p class="pull-right lead">Total : {{ $total }}€</p>
                </div>
			</div>
		</div>
	</div>
</div>
@endsection
