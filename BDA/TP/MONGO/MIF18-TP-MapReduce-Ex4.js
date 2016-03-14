/*** EXO 4 : Q1 **************************************************************/

var exo4q1map = function () {
	if (this.pop > 100000)
	{
		emit(this._id, this.pop);
	}
}

var exo4q1red = function (key, values) {
	return values;
}

var exo4q1 = db.zips.mapReduce(exo4q1map,exo4q1red, {out : {inline:1}});

// ATTENDU : exo4q1 est un objet json dont le champs results contient 4 resultats
//"results" : [
//		{
//			"_id" : "10021",
//			"value" : 106564
//		},
//    ...
//	]


/*** EXO 4 : Q2 **************************************************************/

var exo4q2map = function () {
	emit(this._id, this.pop);
};

var exo4q2red = function (key, values) {
	return values;
};

var exo4q2 = db.zips.mapReduce(exo4q2map, exo4q2red, { out: {inline:1}, query: {pop : { $gt : 100000 }}});
// ATTENDU : exactement le meme resultat que la question 1


/*** EXO 4 : Q3 **************************************************************/

var exo4q3map = function () {
	emit(this.state, this.pop);
}

var exo4q3red = function (key, values) {
	var somme = 0;
	values.forEach(
		function(value)
		{
			somme += value;
		}
	);
	return somme;
}

var exo4q3 = db.zips.mapReduce(exo4q3map,exo4q3red, {out : "states"});

// ATTENDU : exo4q3 est un objet json dont le champs results contient 51 resultats
//"results" : [
//		{
//			"_id" : "WA",
//			"value" : 4866692
//		},
//    ...
//	]
//
// CE RESULTAT EST ENREGISTRE DANS LA COLLECTION db.states


var sort_state = function(a, b) {
	return b.value-a.value; //permet de trier selon le champ value du résultat dans l'ordre décroissant
};

var exo4q3sort = db.zips.mapReduce(exo4q3map,exo4q3red, {out : {inline : 1}}).results.sort(sort_state).slice(0, 3); 
// ATTENDU : exo4q3sort
//[
//	{
//		"_id" : "CA",
//		"value" : ...
//	},
//	{
//		"_id" : "NY",
//		"value" : ...
//	},
//	{
//		"_id" : "TX",
//		"value" : ...
//	}
//]

/*** EXO 4: Q4 ***************************************************************/

var exo4q4map = function () {
	emit({city : this.city, state : this.state}, 0);
}

var exo4q4red = function (key, values) {
	return 0;
}

var exo4q4 = db.zips.mapReduce(exo4q4map, exo4q4red, {out : {inline : 1}});

// ATTENDU : exo4q4 est un objet json dont le champs results contient 25701 resultats (sans limite)
//"results" : [
//      {
//			"_id" : {
//				"city" : "CUSHMAN",
//				"state" : "MA"
//			},
//			"value" : 0
//		}
//    ...
//	]
