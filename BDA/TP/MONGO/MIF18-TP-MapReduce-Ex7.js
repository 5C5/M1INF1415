/*** EXO 7: Q1 ***************************************************************/

// REPONSE 

// 	Il est plus souhaitable d'utiliser la seconde, car elle comprend moins d'opérations

/*** EXO 7: Q2 ***************************************************************/

exo7map = function () {
  emit("4stats", {nb: 1, sum: this.value, max: this.value, avg: 0, std: 0, sq: this.value*this.value});
}

exo7red = function (key, values) {
	var resultat = {nb: 0, sum: 0, max: 0, avg: 0, std: 0, sq: 0};
	values.forEach(function (value){
		resultat.nb += value.nb;
		resultat.sum += value.sum;
		resultat.sq += value.sq;
		if (value.max >= resultat.max)
			ressultat.max = value.max;
	});
	return res;
}

exo7fin = function (key, val) {
	var resultat = {nb: val.nb, sum: val.sum, max: val.max, avg: val.sum/val.nb, std: 0};
	resultat.std = Math.sqrt((val.sq - val.nb*res.avg*resultat.avg)/(val.nb - 1));
	return res;
};

var exo7 = db.states.mapReduce(exo7map, exo7red, { out:{inline :1}, finalize:exo7fin});
// ATTENDU : exo7 est un objet json dont le champs results contient un seul resultat avec la structure suivante
//	{
//			"_id" : "4stats",
//			"value" : {
//				"nb" : 51,
//				"sum" : ...,
//				"max" : ...,
//        ...
//				"avg" : ...,
//				"std" : ...
//			}
//		}

