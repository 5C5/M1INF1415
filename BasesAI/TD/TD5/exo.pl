% TD de Bases de l'Intelligence Artificielle.

% Partie 1.
aime(adam, pommes).
aime(clara, carottes).
aime(olivier, oranges).
fruits(pommes).
fruits(oranges).
legumes(carottes).
en_bonne_sante(X):-aime(X, Y), fruit(Y).

% Question 9 La requete pour savoir qui est en bonne santé est 
% en_bonne_sante(X).

% Question 10 La requete pour savoir qui aime les pommes est 
% aime(X, pommes).

% Question 11 Pour savoir quels fruits connait le programme
% fruits(X).

% Question 12
% socrate est un homme.
% les hommes sont mortels
% les chiens sont des animaux
% l'ornythorinque est un mamifère ovipare amphibie


% Partie 2
% Question 13
nbre_elem([_|[]], 1).
nbre_elem([_|Q], X) :- nbElem(Q, K), X is K+1.

% Question 14
concat([], L, L).
concat([H, L1], L2, [H, L3]):- append(L1, L2, L3).

% Question 15
inverse([], X, X).
inverse(L1, L2) :- inverse(L1, [], L2).
inverse([T|Q], Acc, L):- inverse(Q, [T|Acc], L).
palindrome(X) :- inverse(X, L), X = L.

% Question 16
rang_pair([_], [], 1).
rang_pair([X], [X], 2).
rang_pair([_|L], L1, 1):- rang_pair(L, L1, 2).
rang_pair([X|L], [X|L1], 2):- rang_pair(L, L1, 1).
rang_pair(X, Y):- rang_pair(X, Y, 1).

% Question 17
indice(X, [X|_], 1).
indice(X, [_|L], N):-indice(X, L, K), N is K+1.

% Question 18
remplace(_, _, [], []).
remplace(X, Y, [X|L1], [Y|L2]):- remplace(X, Y, L1, L2).
remplace(X1, X2, [X|L1], [X|L2]):- remplace(X1, X2, L1, L2).

% Question 19
partage([Y], X, [Y], []):- Y < X.
partage([Y], _, [], [Y]).
partage([Y|L], X, [Y|L1], L2):- Y < X, partage(L, X, L1, L2).
partage([Y|L], X, L1, [Y|L2]):- Y >=X, partage(L, X, L1, L2).
