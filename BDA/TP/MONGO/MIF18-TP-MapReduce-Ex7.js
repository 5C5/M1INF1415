/*** EXO 7: Q1 ***************************************************************/

exo7map = function () {
  emit("4stats", null /*TODO*/);
}

exo7red = function (key, values) {
  /*TODO*/
}

exo7fin = function (key, val) {
  /*TODO*/
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

