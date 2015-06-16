<?php namespace App;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Str;
use DB;

class Produit extends Model {

	protected $fillable = ['name', 'price', 'quantity', 'description', 'slug'];

	public static $rules = [
		'name' => 'required|min:4',
		'slug' => 'unique:produits,slug',
		'price' => 'required|regex:/^\d*(\.\d{1,2})?$/',
		'quantity' => 'required|integer|min:1',
	];

	public function commande()
	{
		return $this->belongsTo('App\Commande');
	}

	public function scopeStock($query, $id)
	{
		return $query->where('id', intval($id))->select('quantity', 'price');
	}

	public function scopeShortage($query)
	{
		return $query->where('quantity', 0);
	}

	public function scopeNameQuantity($query)
	{
		return $query->where('quantity', '>', 0)->select('id', DB::raw('CONCAT(name, " (dispo: ", quantity, ")") AS info'))->orderBy('name');
	}

	/*public function setSlugAttribute($value)
	{
		if(empty($value))
		{
			$this->attribute['slug'] = Str::slug($value);
		}
	}*/ //TODO: Fix error when using this
}
