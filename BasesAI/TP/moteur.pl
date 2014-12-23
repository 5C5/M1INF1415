%# Projet de Bases de l intelligence artificielle
%# Moteur de chainage avant

:- dynamic vrai/1, faux/1, changement/0, marquer/1.

si([X]):-vrai(X).
si([T|R]):-vrai(T), si(R).

alors([X]):- assert(vrai(X)).
alors([T|R]):-assert(vrai(T)), alors(R).

%# Déclaration des règles
regle(r1):- si([a, b]), alors([c]).
regle(r2):- si([c, d]), alors([f]).
regle(r3):- si([f, b]), alors([e]).
regle(r4):- si([f, a]), alors([g]).
regle(r5):- si([g, f]), alors([b]).
regle(r6):- si([a, h]), alors([l]).

%# prédicat pour l'ajout des faits, ce qui est vrai et ce qui est faux
faits([X]):-assert(vrai(X)).
faits([T|R]):-assert(vrai(T)), faits(R).

mefaits([X]):-assert(faux(X)).
mefaits([T|R]):-assert(faux(T)), mefaits(R).

%# Prédicat d'effaçage des faits de prolog
raz:-retractall(vrai(_)), retractall(faux(_)), retractall(marquer(_)).

%# Affichage des faits vrai(?)
lire([X]):-write(X), nl, !.
lire([T|H]):-write(T), write(' '), lire(H).

lister([]):-vrai(X), lister([X]).
lister(L):-  vrai(X), not(member(X, L)), lister([X|L]).
lister([T|H]):- write(T), write(' '), lire(H).

%# Application des changement
application:- not(marquer(X)), regle(X), assert(marquer(X)),write(X), write(' : '),lister([]).
appliquer:- changement, retract(changement), !, application, assert(changement), fail.
appliquer:- not(changement).

%# Lancement du chainage avant
saturer:- assert(changement), !, appliquer.
