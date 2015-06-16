<?php namespace App;

use Illuminate\Database\Eloquent\Model;
use Carbon\Carbon;
use DB;

class Client extends Model {

	protected $fillable = ['first_name', 'last_name', 'age', 'address', 'phone', 'email', 'company'];

	public static $rules = [
		'last_name' => 'required|min:2',
		'first_name' => 'required|min:2',
		'email' => 'required|email',
		'address' => 'required|min:20',
		'age' => 'integer|min:1|max:100',
		'phone' => 'required|digits:10',
		'company' => 'min:2',
	];

	public function getUpdatedAtAttribute($value)
    {
		return Carbon::parse($value)->format('d/m/Y H:i');
    }

	public function commandes()
	{
		return $this->hasMany('App\Commande');
	}

	public function scopeFullName($query)
	{
		return $query->select('id', DB::raw('CONCAT(last_name, " ", first_name) AS full_name'))
		->where(DB::raw('CONCAT(last_name, " ", first_name)'), '!=', DB::raw('"Client Inconnu"'))
		->orderBy('last_name');
	}
}
