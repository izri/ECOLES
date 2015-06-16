<?php namespace App;

use Illuminate\Database\Eloquent\Model;

use Carbon\Carbon;

class Commande extends Model {

	protected $fillable = ['client_id', 'produit_id', 'quantity', 'total'];

	public static $rules = [
		'quantity' => 'required|integer|min:1',
	];

	public function client()
	{
		return $this->belongsTo('App\Client');
	}

	public function produit()
	{
		return $this->belongsTo('App\Produit');
	}

	public function table()
	{
		return $this->belongsTo('App\Table');
	}

	public function scopeClientTables($query, $client_id)
	{
		return $query->where('client_id', $client_id)->orderBy('created_at', 'desc')->groupBy('table_slug');
	}

	public function getCreatedAtAttribute($value)
    {
		return Carbon::parse($value)->format('d/m/Y H:i');
    }
}
