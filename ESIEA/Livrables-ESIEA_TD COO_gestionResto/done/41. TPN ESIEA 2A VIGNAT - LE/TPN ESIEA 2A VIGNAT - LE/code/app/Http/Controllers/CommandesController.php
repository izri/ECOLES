<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

use App\Client;
use App\Commande;
use App\Produit;
use App\Table;

class CommandesController extends Controller {

	public function index()
	{
		$readyProduit = $readyTable = false;
		$commandes = null;

		if(!Produit::get()->isEmpty())
			$readyProduit = true;

		if(!Table::get()->isEmpty())
			$readyTable = true;

		if($readyProduit && $readyTable)
			$commandes = Commande::orderBy('created_at', 'dsc')->get();

		return view('commandes.index', compact('commandes', 'readyProduit', 'readyTable'));
	}

	public function show($slug)
	{
		$commandes = Commande::where('table_slug', $slug)->get();
		return view('commandes.show', compact('commandes'));
	}

	public function create()
	{
		$produits = Produit::namequantity()->get()->lists('info', 'id');
		$tables = Table::notavailable()->get()->lists('number', 'id');

		if(!empty($produits))
		{
			if(!empty($tables))
				return view('commandes.create', compact('tables', 'produits'));
			else
				return redirect(route('commandes.index'))->with('error', 'Aucune table n\'est occupée !');
		}
		else
			return redirect(route('commandes.index'))->with('error', 'Au moins un produit est nécessaire. Pensez aussi à verifier votre stock !');
	}

	public function store(Request $req)
	{
		$askedQuantity = intval($req->input('quantity'));
		$produit = Produit::whereId(intval($req->input('produit_id')))->get()->first();

		if(!$produit)
			return redirect(route('commandes.index'))->with('error', 'Problème lors de la récupération du produit !');

		if($produit->quantity - $askedQuantity >= 0)
		{
			Produit::where('id', $req['produit_id'])->decrement('quantity', $askedQuantity);

			$commande = new Commande;
			$commande->client_id = Table::find($req->input('table_id'))->client->id;
			$commande->produit_id = $produit->id;
			$commande->quantity = $askedQuantity;
			$commande->table_id = intval($req->input('table_id'));
			$commande->table_slug = Table::find($req->input('table_id'))->slug;
			$commande->total = $askedQuantity * $produit->price;

			$this->validate($req, Commande::$rules);

			if($commande->save())
				return redirect(route('commandes.index'))->with('success', 'Commande correctement créée !');
			else
				return redirect(route('commandes.create'))->with('error', 'Impossible de créér la commande !');
		}
		else
			return redirect(route('commandes.create'))->with('error', 'Stock insuffisant !')->withInput();
	}

}
