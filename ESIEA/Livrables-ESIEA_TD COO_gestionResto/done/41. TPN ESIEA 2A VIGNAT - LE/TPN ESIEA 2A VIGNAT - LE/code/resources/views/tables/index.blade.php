@extends('app')

@section('content')
<div class="container">
	<div class="row">
		<div class="col-md-10 col-md-offset-1">
			@include('flash')
			<div class="panel panel-default">
                <div class="panel-heading"><b>Liste des tables du restaurant</b></div>
				<div class="panel-body">
				    @if(count($tables) === 0)
                    <div class="alert alert-danger">Vous n'avez pas encore saisi la liste de vos tables !<br>
						<p><a class="btn btn-danger btn-sm" href="{{ route('tables.create') }}">Ajouter une table</a></p>
					</div>
                    @else
					<p class="pull-right"><a class="btn btn-primary" href="{{ route('tables.create') }}">Ajouter</a></p>
					<p>Nombre de tables : {{ count($tables) }}</p>
					<table class="table table-hover">
						<th>Numéro</th>
						<th>Client</th>
						<th>Info</th>
						<th>Disponibilité</th>
						<th>Action</th>
                        @foreach($tables as $table)
                            <tr>
								<td>{{ $table->number }}</td>
								<td>
									@if($table->client)
										{{ $table->client->last_name }} {{ $table->client->first_name }}
									@else
										Non assignée
									@endif
								</td>
								<td>
									@if($table->info)
										{{ $table->info }}
									@else
										N/A
									@endif
								</td>
								<td>
									@if($table->available)
										<span class="label label-success">Disponible</span>
									@else
										<span class="label label-danger">Occupée</span>
									@endif
								</td>
								<td>
									@if($table->available)
										<a href="{{ route('tables.assign', $table) }}" class="btn btn-primary btn-xs">Assigner</span></a>
									@else
										<a href="{{ route('tables.free', $table) }}" class="btn btn-warning btn-xs">Libérer</span></a>
										<a href="{{ route('tables.show', $table) }}" class="btn btn-primary btn-xs">Détail</span></a>
									@endif
									<a href="{{ route('tables.edit', $table) }}" class="btn btn-info btn-xs">Modifier</span></a>
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
