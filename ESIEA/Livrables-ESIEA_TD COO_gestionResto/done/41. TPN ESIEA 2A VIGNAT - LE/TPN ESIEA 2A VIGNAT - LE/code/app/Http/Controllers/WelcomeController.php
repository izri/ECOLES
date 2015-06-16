<?php namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use App\Commande;
use App\Produit;
use App\Client;

class WelcomeController extends Controller {

	/**
	 * Create a new controller instance.
	 *
	 * @return void
	 */
	public function __construct()
	{
		$this->middleware('guest');
	}

	/**
	 * Show the application welcome screen to the user.
	 *
	 * @return Response
	 */
	public function index()
	{
		$clients = count(Client::get());
		$produits = count(Produit::get());
		$commandes = count(Commande::get());
		$shortage = Produit::shortage()->get()->lists('name');

		return view('welcome', compact('commandes', 'clients', 'produits', 'shortage'));
	}

	public function help()
	{
		return view('help');
	}
}
