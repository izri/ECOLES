@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Ajout d'un client</div>
            <div class="panel-body">
                {!! Form::open(['url' => route('clients.store')]) !!}
                <div class="form-group">
                    {!! Form::label('Société') !!}
                    {!! Form::text('company', null, ['class' => 'form-control', 'placeholder' => '(facultatif)']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Nom') !!}
                    {!! Form::text('last_name', null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Prénom') !!}
                    {!! Form::text('first_name', null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Age') !!}
                    {!! Form::text('age', null, ['class' => 'form-control', 'placeholder' => '(facultatif)']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Adresse') !!}
                    {!! Form::textarea('address', null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Téléphone') !!}
                    {!! Form::text('phone', null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Mail') !!}
                    {!! Form::text('email', null, ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Ajouter</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
