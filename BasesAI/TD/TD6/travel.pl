/* TD6, exercice 3, agence de voyage*/

/*1 Description des clauses*/
cout(rome, hotel, 1200).
cout(rome, camping, 850).
cout(rome, habitant, 400).
trajet(rome, 200).

cout(londres, hotel, 1000).
cout(londres, camping, 900).
cout(londres, habtiant, 380).
trajet(londres,  100).

cout(tunis, hotel, 1500).
cout(tunis, camping, 800).
cout(tunis, habitant, 420).
trajet(tunis, 250).

/* Définition du predicat voyage*/
voyage(V, S, H, C):- cout(V, H, X), trajet(V, Y), C is X * S + Y.

/* Définition du predicat voyage eco*/
voyage_eco(V, S, H, C, Cmax):- voyage(V, S, H, C), C <= Cmax.


/*
* Version 2015-2106
*/

