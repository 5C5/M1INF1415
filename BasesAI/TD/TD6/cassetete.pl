/*# Exercice 1 du TD6 de prolog
# exemple utilisé 
#  SEND
#  MORE +
# -------
# MONEY
*/

choisir(H, [H|Q], Q).
choisir(X, [H|Q], R):- X \= H, choisir(X, Q, R).

affectation([], _).
affectation([H|Q], L):- choisir(H, L, R), affectation(Q, R).

sendmore(X) :- 
	X = [S, E, N, D, M, O, R, Y], 
	Domaine = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
	affectation(X, Domaine),
	S > 0, M > 0, D + 10 * N + 100 * E + 1000* S + E + R * 10 + O * 100 + 1000 * M =:= M * 10000 + O * 1000 + N * 100 + E * 10 + Y.


/*
* 
* Correction 2015-2016
*
*/

hhs :-
	V = [H, U, I, T, S, E, Z],
	Domaine = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
	affectation(V, Domaine),
	S > 0, H > 0, (T + 10 * I + 100 * U + H * 1000) * 2 =:= E + Z * 10 + I * 100 + E * 1000 + S * 10000,
	write(V).

onze :-
	V = [U, N, E, F, O, Z ],
	Domaine = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
	affectation(V, Domaine),
	U > 0, N > 0, O>0,
	2 * U + 20 *N + F + U * 10 + E * 100 + N * 1000 =:= E + Z * 10 + N * 100 + O * 1000,
	write(V).

/*
* Definition d'un predicat crypt resolvant n'importe quel crypt et des predicats liés
*/

listeVar([U, N, E, F, O, Z]).
contraintes(V) :- N > 0.

crypt :-
	listeVar(V),
	Domaine = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
	affectation(V, D),
	contrainte(V),
	write(V).



