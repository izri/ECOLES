<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use App\Produit;

use Illuminate\Http\Request;
use Illuminate\Support\Str;

class ProduitsController extends Controller {

	public function index()
	{
		$produits = Produit::get();
		return view('produits.index', compact('produits'));
	}

	public function create()
	{
		return view('produits.create');
	}

	public function store(Request $req)
	{
		$this->validate($req, Produit::$rules);

		$produit = new Produit($req->all());
		$produit->slug = Str::slug($req->input('name'));

		$r = Produit::where('slug', $produit->slug)->get()->first();

		if($r)
			return redirect(route('produits.create'))->with('error', 'Produit déjà existant !')->withInput();

		if($produit->save())
			return redirect(route('produits.index'))->with('success', 'Produit créé avec succès');
		else
			return redirect(route('produits.create'))->with('error', 'Erreur lors de la sauvegarde !')->withInput();
	}

	public function edit($id)
	{
		$produit = Produit::find($id);

		if($produit)
			return view('produits.edit', compact('produit'));
		else
			return view('produits.index')->with('error', 'Produit introuvable !');
	}

	public function update($id, Request $req)
	{
		$produit = Produit::find($id);

		if($produit)
		{
			$this->validate($req, Produit::$rules);

			$produit->update($req->all());
			$produit->slug = Str::slug($req->input('name'));

			$req = Produit::where('slug', $produit->slug)->get()->first();

			if($req)
				return redirect(route('produits.create'))->with('error', 'Produit déjà existant !')->withInput();

			if($produit->save())
				return redirect(route('produits.edit', $id))->with('success', 'Mis à jour avec succès');
			else
				return redirect(route('produits.edit', $id))->with('error', 'Erreur lors de la sauvegarde !')->withInput();
		}
		else
			return view('produits.index')->with('error', 'Produit introuvable !');
	}
}
