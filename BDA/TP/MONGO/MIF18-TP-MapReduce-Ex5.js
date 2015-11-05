/*** EXO 5: Q1 ***************************************************************/

var exo5q1map = function () {
  /*TODO*/
}

var exo5q1red = function (key, values) {
  /*TODO*/
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
  /*TODO*/
};

var exo5q2red = function (key, values) {
  /*TODO*/
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
  /*TODO*/
}

var exo5q3red = function (key, values) {
  /*TODO*/
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
  emit("most_crowded", null /*TODO*/);
}

var exo5q4red = function (key, values) {
  /*TODO*/
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
  emit("most_crowded", null /*TODO*/);
}

var exo5q5red = function (key, values) {
  /*TODO*/
}

var exo5q5fin = function (key, values) {
  /*TODO*/
};

var exo5q5 = db.zips.mapReduce(exo5q5map, exo5q5red, {out : {inline : 1}, finalize : exo5q5fin});

// ATTENDU : exactement le meme resultat que la question precedente

/*** EXO 5: Q6 ***************************************************************/

exo5q6map = function () {
  /*TODO*/
}

exo5q6red = function (key, values) {
  /*TODO*/
}

exo5q6fin = function (key, val) {
 /*TODO*/
};

var exo5q6 = db.zips.mapReduce(exo5q6map, exo5q6red, {out : {inline : 1}, finalize : exo5q6fin});
// ATTENDU : exo5q6 est un objet json dont le champs results contient 51 resultats avec la structure suivante
//{
//		"_id" : "WY",
//		"value" : {
//			"w" : 96,
//			"p" : 453528,
//			"avg" : 4724.25
//		}
//	}


