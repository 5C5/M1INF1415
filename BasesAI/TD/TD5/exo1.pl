% Question 1
aime(marie, vin).
estVoleur(pierre).
aime(pierre, X):- aime (X, vin).
vole(X, Y):- estVoleur(X), aime(X, Y).
vole(X, Y).

% Question 2
enfant(X, Y):- pere(Y, X).
fils(X, Y) :- enfant(X, Y), homme(X).
fille(X, Y) :-enfant(X, Y), femme(X).
frere-ou-soeur(X, Y):- enfant(X, Z), enfant(Y, Z), X\==Y.

% Question 3

element(X,[X| L]).
element(X, [_|L]):- element(X, L).

nombre_occurence(_, [], 0).
nombre_occurence(X, [X|L], M):- nombre_occurence(X, L, N), M is N+1.
nombre_occurence(X, [_|L], N) =- nombre_occurence(X, L, N).

% Question 4
inverse([X], [X|L2]).
inerse([X|L], L2):- inverse(L, [X|L2]).

% Question 5
compresse([], []).
compresse([X], [X]).
compresse([X, X|L], H):-!, compresse([X|L], H).
compresse([X, Y|L], [X|H]):- compresse([Y|L], H).

% Question 6
couleur(vert).
couleur(rouge).
couleur(jaune).
coloriage(C1, C2, C3, C4):- couleur(C1), couleur(C2), couleur(C3), couleur(C4), C1\= C2, C1 \= C3, C1 \=C4, C2\= C3, C3 \= C4.
