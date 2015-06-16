@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@if($client)
			<div class="panel panel-default">
                <div class="panel-heading"><b>Client ID : {{ $client->id }}</b>
                    <p class="pull-right"><a class="btn btn-warning btn-xs" href="{{ route('clients.edit', $client) }}">Modifier</a></p></div>
				<div class="panel-body">
                    <p><b>Société : </b> {{ ($client->company) ? $client->company : "N/A" }}</p>
                    <p><b>Nom : </b> {{ $client->last_name }}</p>
                    <p><b>Prénom :</b> {{ $client->first_name }}</p>
                    <p><b>Age :</b> {{ ($client->age === 0) ? "N/A" : $client->age  }}</p>
                    <p><b>Adresse :</b> {{ ($client->address) ? $client->address : "N/A" }}</p>
                    <p><b>Email :</b> {{ ($client->email) ? $client->email : "N/A" }}</p>
                </div>
			</div>
            <div class="panel panel-default">
                <div class="panel-heading"><b>Historique des tables :</b> <p class="pull-right">Nombre de tables : {{ count($commandes) }}</p></div>
                <div class="panel-body">
                    @if(count($commandes) > 0)
					<table class="table table-hover">
						<th>Numéro de la table</th>
						<th>Date</th>
						<th>Détail</th>
                        @foreach($commandes as $commande)
                            <tr>
								<td>Table n° {{ $commande->table->number }}</td>
								<td>{{ $commande->created_at }}</td>
								<td><a class="btn btn-primary btn-xs" href="{{ route('commandes.show', $commande->table_slug) }}">Voir le détail</a></td>
							</tr>
                        @endforeach
                    @endif
                </div>
			</div>
			@else
			<div class="alert alert-danger">
				L'utilisateur que vous cherchez n'existe pas !
			</div>
			@endif
		</div>
	</div>
</div>
@endsection
