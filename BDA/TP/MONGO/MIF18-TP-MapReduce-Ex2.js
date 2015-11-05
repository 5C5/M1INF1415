var etu1Nom = "PICARD";
var etu1Prenom = "Colas";
var etu1Num = 11410822;

var etu2Nom = "VYSTAVEL";
var etu2Prenom = "PETER";
var etu2Num = 0;

/*** EXO 2 : Q1 **************************************************************/
var exo2q1 = db.zips.count();
// ATTENDU : exo2q1 = 29353;

/*** EXO 2 : Q2 **************************************************************/
var exo2q2 = db.zips.find({city: "SPRINGFIELD"}).count();
// ATTENDU : exo2q2 = 41;

/*** EXO 2 : Q3 **************************************************************/
var exo2q3 = db.zips.distinct("state").length;
// ATTENDU : exo2q3 = 51, ce qui est le bon nombdre d'etats

/*** EXO 2 : Q4 **************************************************************/
var exo2q4 = db.zips.find({pop : { $gt : 100000}},{state : 1});
// ATTENDU : exo2q4 est un curseur mongo DB qui affichera :
//{ "_id" : "10021", "state" : "NY" }
//{ "_id" : "10025", "state" : "NY" }
//{ "_id" : "11226", "state" : "NY" }
//{ "_id" : "60623", "state" : "IL" }

