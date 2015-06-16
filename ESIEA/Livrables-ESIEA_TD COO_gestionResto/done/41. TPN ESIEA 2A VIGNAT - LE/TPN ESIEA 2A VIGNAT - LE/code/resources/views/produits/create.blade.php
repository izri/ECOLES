@extends('app')

@section('content')
<div class="row">
    <div class="col-md-6 col-md-offset-3">
        @include('flash')
        <div class="panel panel-default">
            <div class="panel-heading">Ajouter un produit :</div>
            <div class="panel-body">
                {!! Form::open(['url' => route('produits.store')]) !!}
                <div class="form-group">
                    {!! Form::label('Nom') !!}
                    {!! Form::text('name', null, ['class' => 'form-control', 'placeholder' => 'Dom Perignon 1998']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Prix unitaire') !!}
                    {!! Form::text('price', null, ['class' => 'form-control', 'placeholder' => '400.5']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Quantité') !!}
                    {!! Form::text('quantity', null, ['class' => 'form-control', 'placeholder' => '10']) !!}
                </div>
                <div class="form-group">
                    {!! Form::label('Description') !!}
                    {!! Form::textarea('description', null, ['class' => 'form-control', 'placeholder' => '(Description facultative)']) !!}
                </div>
                <button class="btn btn-primary pull-right">Ajouter</button>
                {!! Form::close() !!}
            </div>
        </div>
    </div>
</div>
@endsection
