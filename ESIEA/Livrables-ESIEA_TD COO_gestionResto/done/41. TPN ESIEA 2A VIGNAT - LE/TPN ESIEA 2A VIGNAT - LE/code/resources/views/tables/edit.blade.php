@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Création d'une table</div>
            <div class="panel-body">
                {!! Form::open(['method' => 'put', 'url' => route('tables.update', $table)]) !!}
                <div class="form-group">
                    {!! Form::label('Numéro') !!}
                    {!! Form::text('number', $table->number, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Info') !!}
                    {!! Form::text('info', $table->info, ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Modifier</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
