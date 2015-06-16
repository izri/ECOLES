<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

use App\Client;
use App\Commande;
use DB;

class ClientsController extends Controller {

	public function index()
	{
		$clients = Client::get();
		return view('clients.index', compact('clients'));
	}

	public function show($id)
	{
		$client = Client::find($id);
		$tables_list = $created_at = null;

		if($client)
			$commandes = Commande::clienttables($id)->get();
		else
			return redirect(route('clients.index'))
			->with('error', 'L\'utilisateur que vous voulez voir n\'existe pas !');

		return view('clients.show', compact('client', 'commandes'));
	}

	public function create()
	{
		return view('clients.create');
	}

	public function store(Request $req)
	{
		$this->validate($req, Client::$rules);
		$client = new Client($req->all());

		if($req->input('age') === "")
			$client->age = 0;

		if($client->save())
			return redirect(route('clients.index'))
			->with('success', 'Utilisateur correctement créé !');

		return redirect(route('clients.create'))
		->with('error', 'Problème lors de la création de l\'utilisateur !')
		->withInput();
	}

	public function edit($id)
	{
		$client = Client::find($id);

		if(!$client)
			return redirect(route('clients.index'))
			->with('error', 'L\'utilisateur que vous essayez de modifier n\'existe pas !');

		return view('clients.edit', compact('client'));
	}

	public function update($id, Request $r)
	{
		$client = Client::find($id);

		if(!$client)
			return redirect(route('clients.index'))
			->with('error', 'L\'utilisateur que vous essayez de modifier n\'existe pas !');

		$this->validate($r, Client::$rules);

		if($client->update($r->all()))
			return redirect(route('clients.edit', $id))
			->with('success', 'Modifications sauvegardées avec succès !');

		return redirect(route('clients.edit', $id))
		->with('error', 'Problème lors de la sauvegarde des modifications !');
	}
}
