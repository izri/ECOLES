@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading"><b>ID Client : {{ $client->id }}</b> <p class="pull-right">Dernière modification : {{ $client->updated_at }}</p></div>
            <div class="panel-body">
                {!! Form::open(['method' => 'put', 'url' => route('clients.update', $client)]) !!}
                <div class="form-group">
                    {!! Form::label('Société') !!}
                    {!! Form::text('company', $client->company, ['class' => 'form-control', 'placeholder' => '(facultatif)']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Nom') !!}
                    {!! Form::text('last_name', $client->last_name, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Prénom') !!}
                    {!! Form::text('first_name', $client->first_name, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Age') !!}
                    {!! Form::text('age', ($client->age === 0) ? null : $client->age, ['class' => 'form-control', 'placeholder' => '(facultatif)']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Adresse') !!}
                    {!! Form::textarea('address', $client->address, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Téléphone') !!}
                    {!! Form::text('phone', $client->phone, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Mail') !!}
                    {!! Form::text('email', $client->email, ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Modifier</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
