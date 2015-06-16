<?php namespace App;

use Illuminate\Database\Eloquent\Model;

use Carbon\Carbon;

class Table extends Model {

	protected $fillable = ['number', 'info'];

	public static $rules = [
		'number' => 'required|integer|min:0|unique:tables,number',
		'info' => 'string',
	];

	public function client()
	{
		return $this->belongsTo('App\Client');
	}

	public function scopeAvailable($query)
	{
		return $query->where('available', 1);
	}

	public function scopeNotAvailable($query)
	{
		return $query->where('available', 0);
	}

	public function getCreatedAtAttribute($value)
    {
		return Carbon::parse($value)->format('d/m/Y H:i');
    }

	public function getUpdatedAtAttribute($value)
    {
		return Carbon::parse($value)->format('d/m/Y à H:i');
    }
}
