/* TP MapReduce sur MongoDB (MIF18 BD)
 *
 *         PICARD Colas et BROU Jonathan
 *         */
/* Exercice 1
 *  Question 2)
 *          zips_index a 4 index ("_id_","city_1","state_1","pop_1") alors zips en a qu'un seul ("_id_"). */

/* Exercice 2
 * 1) db.zips.count();   Ce qui donne 29353 éléments .
 *
 * 2) db.zips.find({"city":"SPRINGFIELD"}).count();   Ce qui donne 41 éléments.
 *
 * 3) db.zips.distinct("state").length;    Ce qui nous donne 51 états.
 *
 * 4) db.zips.find({pop :  {$gt : 100000}});
 *         db.zips.find({pop : {$gt : 1000000}} , {_id:true ,  city:true});
 *
 *         5) Non, car la base de donnée est en lecture seule.
 *
 *
 **/

/* Exercice 3*/

/*Question 2 :                                                 
 * Pour afficher le résultat, il suffit de faire 
 * db.zips.mapReduce(map_ex3, red_ex3, {out : {inline :1}})
 * Pour n'afficher que le résultat, il suffit de faire
 * db.zips.mapReduce(map_ex3, red_ex3, {out : {inline : 1}}).results[0].value
 * */

var map_ex3 = function() {
	        emit(0,1);
}

var red_ex3 = function(key,values) {
	var sum = 0;
		for(var i=0;i<values.length;i++)
			sum+=values[i];
			/* // Question 3
			 *  sum=values.reduce(function(a,b){
			 *  	return a+b;
			 *  });
			 **/
		return sum;
}

db.zips.mapReduce(map_ex3,red_ex3,{out : "result"});

// Question 4
//Avec foreach :
var map_foreach = function() {
	emit(0,1);
}

var red_foreach = function(key,values) {
	var sum=0;
	values.foreach(function(element,index){
		sum+=element;
	});
	return sum;
}

/* Exercice 4*/
//Question 1
var map_ex4_1 = function(){


}

var red_ex4_1 = function(key, values){
}
