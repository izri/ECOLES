<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

use App\Client;
use App\Commande;
use App\Table;

class TablesController extends Controller {

	public function index()
	{
		$tables = Table::get();
		return view('tables.index', compact('tables'));
	}

	public function create()
	{
		return view('tables.create');
	}

	public function edit($id)
	{
		$table = Table::find($id);

		if(!$table)
			return redirect(route('tables.index'))
			->with('error', 'La table que vous essayez de modifier n\'existe pas !');

		return view('tables.edit', compact('table'));
	}

	public function update($id, Request $r)
	{
		$table = Table::find($id);

		if(!$table)
			return redirect(route('table.index'))
			->with('error', 'La table que vous essayez de modifier n\'existe pas !');

		$this->validate($r, Table::$rules);

		if($table->update($r->all()))
			return redirect(route('tables.edit', $id))
			->with('success', 'Modifications sauvegardées avec succès !');

		return redirect(route('tables.edit', $id))
		->with('error', 'Problème lors de la sauvegarde des modifications !');
	}

	public function show($id)
	{
		$table = Table::find($id);

		if(!$table)
			return redirect(route('tables.index'))->with('error', 'Table introuvable !');

		$commandes = Commande::where('table_slug', $table->slug)->get();

		return view('tables.show', compact('table', 'commandes'));
	}

	public function assign($id)
	{
		$clients = Client::fullname()->get()->lists('full_name', 'id');
		$clients[] = 'Client Inconnu';
		asort($clients);
		$table = Table::find($id);

		if(!$table)
			return redirect(route('tables.index'))->with('error', 'Table introuvable !');

		return view('tables.assign', compact('clients', 'table'));
	}

	public function assignUpdate($id, Request $r)
	{
		$table = Table::find($id);

		if(!$table)
			return redirect(route('tables.index'))->with('error', 'Table introuvable !');

		$client = Client::find(intval($r->input('client_id')));

		if(!$client) //Anonyme
		{
			$client = Client::create([
				'last_name' => 'Client',
				'first_name' => 'Inconnu',
				'age' => 0,
				'address' => '',
				'phone' => '',
				'email' => '']);
		}

		$table->client_id = $client->id;
		$table->available = false;

		while(!Table::where('slug', $table->slug)->get()->isEmpty()) //Ugly but functionnal
		{
			$table->slug = strtolower(str_random(15));
		}

		if(!$table->save())
			return redirect(route('tables.index'))->with('error', 'Problème lors de l\'assignation de la table !');

		return redirect(route('tables.index'))->with('success', 'Table assignée correctement !');
	}

	public function free($id)
	{
		$table = Table::find($id);

		if(!$table)
			return redirect(route('tables.index'))->with('error', 'Table introuvable !');

		$table->available = true;
		$table->client_id = null;
		$table->slug = null;

		if($table->save())
			return redirect(route('tables.index'))->with('success', 'Table libérée !');
		else
			return redirect(route('tables.index'))->with('error', 'Impossible de libérer la table !');
	}


	public function store(Request $r)
	{
		$res = Table::where('id', intval($r->number))->get()->lists('id', 'number');

		if(!empty($res))
			return redirect(route('tables.create'))->with('error', 'Numéro de table déjà existant !')->withInput();

		$this->validate($r, Table::$rules);

		if(Table::create($r->all()))
			return redirect(route('tables.index'))->with('success', 'Table correctement créé !');

		return redirect(route('tables.create'))->with('error', 'Problème lors de la création de la table !')->withInput();
	}
}
