@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Création d'une table</div>
            <div class="panel-body">
                {!! Form::open(['method' => 'put', 'url' => route('tables.assignupdate', $table)]) !!}
                <div class="form-group">
                    {!! Form::label('Client') !!}
                    {!! Form::select('client_id', $clients, key($clients), ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Assigner</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
