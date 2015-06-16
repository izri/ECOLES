@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading"><b>ID Produit : {{ $produit->id }}</b> <p class="pull-right">Dernière modification : {{ $produit->updated_at }}</p></div>
            <div class="panel-body">
                {!! Form::open(['method' => 'put', 'url' => route('produits.update', $produit)]) !!}
                <div class="form-group">
                    {!! Form::label('Nom') !!}
                    {!! Form::text('name', $produit->name, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Prix') !!}
                    {!! Form::text('price', $produit->price, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Quantité') !!}
                    {!! Form::text('quantity', $produit->quantity, ['class' => 'form-control']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Description') !!}
                    {!! Form::textarea('description', $produit->description, ['class' => 'form-control', 'placeholder' => '(Description facultative)']) !!}
                </div>
                <button class="btn btn-primary pull-right">Modifier</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
