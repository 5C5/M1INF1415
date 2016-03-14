/*** EXO 6: Q1 ***************************************************************/
// donner la population totale de chaque ville avec l'aggregation pipeline

var exo6q1 = db.zips.aggregate({$group : {_id : {city: "$city", state: "$state"}, totalPop : {$sum : "$pop"}}});
// ATTENDU : exo6qA est un curseur mongo DB qui affichera :
//{ "_id" : { "city" : "POINT BAKER", "state" : "AK" }, "pop" : 426 }
//{ "_id" : { "city" : "KLAWOCK", "state" : "AK" }, "pop" : 851 }
//{ "_id" : { "city" : "HYDABURG", "state" : "AK" }, "pop" : 891 }
//{ "_id" : { "city" : "CRAIG", "state" : "AK" }, "pop" : 1398 }
// ...


/*** EXO 6: Q2 ***************************************************************/

// comparer la vitesse d'execution entre les deux pipelines sur la collection zips.

var exo6q2map = function() {
	emit({city: this.city, state: this.state}, this.pop);
}

var exo6q2red = function(k,vs) {
	var population = 0;
	vs.forEach( function (value)
	{
		population += value;
	});
	return population;
}

var exo6q2mapreduce = function(){
  var debut  = Date.now();
  var resultat = db.zips.mapReduce(exo6q2map,exo6q2red, {out : {inline : 1}});
  var fin  = Date.now();
  return (fin - debut);
}

// ATTENDU : exo6q2mapreduce retourne la duree dexecution du job map/reduce

var exo6q2aggregate = function(){
  var debut  = Date.now();
  var resultat = db.zips.aggregate({$group : {_id : {city: "$city", state: "$state"}, totalPop : {$sum : "$pop"}}});
  var fin  = Date.now();
  return (fin - debut);
}
// ATTENDU : exo6q2aggregate retourne la duree dexecution du job avec l'agregation pipeline

var NB_RUNS = 3;

var exo6q2bench = function(f){
	var somme = 0;
	for (var i=0 ; i<NB_RUNS ; i++)
	{
		somme += f();
	}
	return somme/NB_RUNS;
}

// ATTENDU : exo6q2bench(f) renvoie le temps moyen d'execution de f sur NB_RUNS essais

//var exo6q2aggregate_bench = exo6q2bench(exo6q2aggregate); 
//var exo6q2mapreduce_bench = exo6q2bench(exo6q2mapreduce);


/*** EXO 6: Q3 ***************************************************************/

// REPONSE

/*

*/
