/*** EXO 5: Q1 ***************************************************************/

var exo5q1map = function () {
	emit(this.state, {cities : this.city});
}

var exo5q1red = function (key, values) {
	var resultats = {cities : ""};
	values.forEach( function (value)
	{
		resultats.cities += value.cities;
		if (values.indexOf(value) != values.length-1)
			resultats.cities += ", ";
	});
	return resultats;
}

var exo5q1 = db.zips.mapReduce(exo5q1map, exo5q1red, {out : {inline : 1}});

// ATTENDU : exo5q1 est un objet json dont le champs results contient 51 resultats avec la structure suivante
//  {
//			"_id" : "WY",
//			"value" : {
//				"cities" : [
//					"AFTON",
//					"THAYNE",
//          ...
//					"CHEYENNE"
//				]
//			}


/*** EXO 5: Q2 ***************************************************************/

var exo5q2map = function () {
	emit(this.state, {city: this.city});
};

var exo5q2red = function (key, values) {
	var resultats = {};
	values.forEach(function (value)
	{
		resultats[value.city] = 0;
	});
	return resultats;
}

var exo5q2 = db.zips.mapReduce(exo5q2map, exo5q2red, {out : {inline : 1}});
// ATTENDU : exo5q1 est un objet json dont le champs results contient 51 resultats avec la structure suivante
//  {
//			"_id" : "WY",
//			"value" : {
//				  "AFTON" : 0,
//					"THAYNE" : 0,
//          ...
//					"CHEYENNE" :0
//				}
//			}


/*** EXO 5: Q3 ***************************************************************/

var exo5q3map = function () {
	emit(this.state, {pop: this.pop, id: this._id});
}

var exo5q3red = function (key, values) {
	var resultats;
	var minimum = values[1];
	var maximum = values[1];
	values.forEach(function (value)
	{
		if (value.pop > maximum.pop)
			maximum = value;
		if (value.pop < minimum.pop)
			minimum = value;
	});
	resultats = {min: {pop : minimum.pop, id: minimum.id}, max: {pop: maximum.pop, id: maximum.id}};
	return resultats;
}

var exo5q3 = db.zips.mapReduce(exo5q3map, exo5q3red, {out : {inline : 1}});

// ATTENDU : exo5q3 est un objet json dont le champs results contient 51 resultats avec la structure suivante
//{
//		"_id" : "WY",
//		"value" : {
//			"min" : {
//				"pop" : ...,
//				"id" : ...
//			},
//			"max" : {
//				"pop" : ...,
//				"id" : ...
//			}
//		}
//	}


/*** EXO 5: Q4 ***************************************************************/

var exo5q4map = function () {
  emit("most_crowded", {state: this._id, pop: this.value});
}

var exo5q4red = function (key, values) {
	var maximum = values[0];
	values.forEach(function(value){
		if (value.pop > maximum.pop)
			maximum = value;
		});
	return {state: maximum.state, pop: maximum.pop};
}

var exo5q4 = db.states.mapReduce(exo5q4map, exo5q4red, {out : {inline : 1}});

// ATTENDU : exo5q4 est un objet json dont le champs results contient un seul resultat avec la structure suivante
//	{
//		"_id" : "most_crowded",
//		"value" : {
//			"state" : ...,
//			"pop" : ...
//		}
//	}



/*** EXO 5: Q5 ***************************************************************/

var exo5q5map = function () {
	emit("most_crowded", {state: this.state, pop: this.pop});
};

var exo5q5red = function (key, values) {

	var newValue = [];
	var maximum;
	values.foreach(function(value){
		maximum = value;
		values.foreach(function(valeur){
			if(maximum.state == valeur.state && valeur.pop > maximum.pop)
				maximum = valeur;
		});
		newValue.push({state : maximum.state, pop : maximum.pop});
	});	
	emit(key, newValue);
};

var exo5q5fin = function (key, values) {
	var maximum = values[0];
	values.forEach(function(value){
		if (value.pop > maximum.pop)
			maximum = value;
		});
	return {state: maximum.state, pop: maximum.pop};
};

var exo5q5 = db.zips.mapReduce(exo5q5map, exo5q5red, {out : {inline : 1}, finalize : exo5q5fin});

// ATTENDU : exactement le meme resultat que la question precedente

/*** EXO 5: Q6 ***************************************************************/

exo5q6map = function () {
	emit(this.state, {w: 1, p: this.pop, avg: 0});
}

exo5q6red = function (key, values) {
	var resultat = {w: 0, p: 0, avg: 0};
	values.forEach(function (value){
		resultat.p += value.p;
		resultat.w += value.w;
	});
	return resultat;
}

exo5q6fin = function (key, val) {
	return {w: val.w, p: val.p, avg: val.p/val.w};
};

var exo5q6 = db.zips.mapReduce(exo5q6map, exo5q6red, {out : {inline : 1}, finalize : exo5q6fin});
// ATTENDU : exo5q6 est un objet json dont le champs results contient 51 resultats avec la structure suivante
//  {
//    "_id" : "WY",
//    "value" : {
//      "w" : 140,
//      "p" : 453528,
//      "avg" : 3239.4857142857145
//      }
//  }


