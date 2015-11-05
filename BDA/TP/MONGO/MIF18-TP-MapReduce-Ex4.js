/*** EXO 4 : Q1 **************************************************************/

var exo4q1map = function () {
  /*TODO*/
}

var exo4q1red = function (key, values) {
  /*TODO*/
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
  /*TODO*/
}

var exo4q2 = null /*TODO*/;
// ATTENDU : exactement le meme resultat que la question 1


/*** EXO 4 : Q3 **************************************************************/

var exo4q3map = function () {
  /*TODO*/
}

var exo4q3red = function (key, values) {
  /*TODO*/
}

var exo4q3 = db.zips.mapReduce(exo4q3map,exo4q3red, {out : {inline:1}});

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
  /*TODO*/
}

var exo4q3sort = null /*TODO*/; 
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
  /*TODO*/
}

var exo4q4red = function (key, values) {
  return 0;
}

var exo4q4 = db.zips.mapReduce(exo4q4map,exo4q4red, {out : {inline : 1}});

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


