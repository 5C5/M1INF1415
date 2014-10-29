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
