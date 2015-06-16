@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Création d'une table</div>
            <div class="panel-body">
                {!! Form::open(['url' => route('tables.store')]) !!}
                <div class="form-group">
                    {!! Form::label('Numéro') !!}
                    {!! Form::text('number', null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Info') !!}
                    {!! Form::text('info', null, ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Ajouter</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
