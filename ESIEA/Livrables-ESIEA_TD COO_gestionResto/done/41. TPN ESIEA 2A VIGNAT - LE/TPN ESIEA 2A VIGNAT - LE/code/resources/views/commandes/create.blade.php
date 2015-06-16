@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Créer une commande :</div>
            <div class="panel-body">
                {!! Form::open(['url' => route('commandes.store')]) !!}
                <div class="form-group">
                    {!! Form::label('Table') !!}
                    {!! Form::select('table_id', $tables, null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Produit') !!}
                    {!! Form::select('produit_id', $produits, null, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Quantité') !!}
                    {!! Form::text('quantity', null, ['class' => 'form-control']) !!}
                </div>
                <button class="btn btn-primary pull-right">Créer</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>

@endsection
