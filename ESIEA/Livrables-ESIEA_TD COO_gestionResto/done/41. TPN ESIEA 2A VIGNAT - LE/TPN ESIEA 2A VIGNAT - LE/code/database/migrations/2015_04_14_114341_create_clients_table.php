<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateClientsTable extends Migration {

	/**
	 * Run the migrations.
	 *
	 * @return void
	 */
	public function up()
	{
		Schema::create('clients', function(Blueprint $table)
		{
			$table->increments('id');
			$table->string('last_name', 100);
			$table->string('first_name', 100);
			$table->smallInteger('age')->unsigned();
			$table->text('address');
			$table->string('phone', 20);
			$table->string('email', 100);
			$table->string('company', 150)->nullable();
			$table->timestamps();
		});

		Schema::create('produits', function(Blueprint $table)
		{
			$table->increments('id');
			$table->string('name', 255);
			$table->float('price')->unsigned();
			$table->integer('quantity')->unsigned();
			$table->text('description');
			$table->string('slug')->unique();
			$table->timestamps();
		});

		Schema::create('tables', function(Blueprint $table)
		{
			$table->increments('id');
			$table->integer('number')->unsigned();
			$table->integer('client_id')->unsigned()->nullable()->default(null);
			$table->string('info', 255)->nullable();
			$table->boolean('available')->default(true);
			$table->string('slug', 15)->nullable();
			$table->timestamps();
			$table->foreign('client_id')->references('id')->on('clients');
		});

		Schema::create('commandes', function(Blueprint $table)
		{
			$table->increments('id');
			$table->integer('client_id')->unsigned();
			$table->integer('table_id')->unsigned();
			$table->string('table_slug', 15);
			$table->integer('produit_id')->unsigned();
			$table->integer('quantity')->unsigned();
			$table->timestamps();
			$table->foreign('produit_id')->references('id')->on('produits');
			$table->foreign('client_id')->references('id')->on('clients');
			$table->foreign('table_id')->references('id')->on('tables');
		});
	}

	/**
	 * Reverse the migrations.
	 *
	 * @return void
	 */
	public function down()
	{
		Schema::drop('clients');
		Schema::drop('commandes');
		Schema::drop('produits');
		Schema::drop('tables');
	}

}
