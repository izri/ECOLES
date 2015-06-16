<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.
|
*/

Route::get('/', 'WelcomeController@index');
Route::get('help', ['as' => 'help', 'uses' => 'WelcomeController@help']);

//Clients
Route::resource('clients', 'ClientsController');

//Produits
Route::resource('produits', 'ProduitsController');

//Commandes
Route::resource('commandes', 'CommandesController');

//Tables
Route::resource('tables', 'TablesController');
Route::get('tables/{id}/assign', ['as' => 'tables.assign', 'uses' => 'TablesController@assign']);
Route::put('tables/{id}/assignupdate', ['as' => 'tables.assignupdate', 'uses' => 'TablesController@assignUpdate']);
Route::get('tables/{id}/free', ['as' => 'tables.free', 'uses' => 'TablesController@free']);
