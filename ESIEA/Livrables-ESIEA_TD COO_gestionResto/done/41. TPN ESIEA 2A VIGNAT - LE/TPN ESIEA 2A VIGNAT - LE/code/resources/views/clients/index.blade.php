@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@include('flash')
			<div class="panel panel-default">
                <div class="panel-heading"><b>Liste des clients</b></div>
				<div class="panel-body">
                    <p class="pull-right"><a class="btn btn-primary" href="{{ route('clients.create') }}">Ajouter</a></p>
				    @if(count($clients) === 0)
                        <p>Pas de clients</p>
                    @else
					<p>Nombre de clients : {{ count($clients) }}</p>
					<table class="table table-hover">
						<th>ID</th>
						<th>Société</th>
						<th>Nom, Prénom</th>
						<th>Téléphone</th>
						<th>Action</th>
                        @foreach($clients as $client)
                            <tr>
								<td>{{ $client->id }}</td>
								<td>{{ ($client->company) ? $client->company : "N/A" }}</td>
								<td>{{ $client->last_name }}, {{ $client->first_name }}</td>
								<td>{{ $client->phone }}</td>
								<td><a class="btn btn-info btn-sm" href="{{ route('clients.show', $client) }}">Voir</a>
									@if($client->email)
									<a class="btn btn-success btn-sm" href="mailto:{{ $client->email }}">Contacter</a>
									@endif
								</td>
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
