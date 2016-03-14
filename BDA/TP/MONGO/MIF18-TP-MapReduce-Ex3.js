/*** EXO 3 : Q1 **************************************************************/

var exo3q1map = function () {
	emit(0,1);
};

var exo3q1red = function (key, values) {
	var somme = 0;
	for(var i=0 ; i<values.length ; i++)
		somme+=values[i];
	return somme;
};

var exo3q1 = db.zips.mapReduce(exo3q1map,exo3q1red, {out : {inline:1}});

// ATTENDU : exo3q1 est un objet json dont le champs results contient un seul resultat
//"results" : [
//		{
//			"_id" : 0,
//			"value" : 29353
//		}
//	]


/*** EXO 3 : Q2 **************************************************************/

var exo3q2red = function (key, values) {
  var somme = values.reduce(
		function(a, b)
		{
			return a + b;
		}
	);
	return somme;
};

// ATTENDU : exactement le meme resultat que la question 1

/*** EXO 3 : Q3 **************************************************************/

var exo3q3red = function (key, values) {
	var somme = 0;
	values.forEach(
		function(value)
		{
			somme += value;
		}
	);
	return somme;
};

// ATTENDU : exactement le meme resultat que la question 1
