@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Table n°{{ $table->number }} assigné le {{$table->updated_at}}</div>
            <div class="panel-body">
                <p>Client : <a href="{{ route('clients.show', $table->client) }}" class="btn btn-primary btn-sm">Fiche client</a> </p>
                <hr>
                @if(count($commandes) > 0)
                    {{--*/ $total = 0 /*--}}
                    @foreach($commandes as $commande)
                        <p class="lead">Commande n°{{ $commande->id }} :</p>
                        {{--*/ $total += $commande->total /*--}}
                        <p class="pull-right">{{ $commande->total }}€</p>
                        <p>{{ $commande->produit->name }} x {{ $commande->quantity }}</p>
                        <hr>
                    @endforeach
                <p class="pull-right lead">Total : {{ $total }}€</p>
                @else
                    <p>Aucune commande pour cette table pour l'instant.</p>
                @endif
            </div>
        </div>
    </div>
</div>
@endsection
