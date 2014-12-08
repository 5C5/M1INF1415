%# Projet de Bases de l intelligence artificielle
%# Moteur de chainage avant

:- dynamic vrai/1, faux/1, changement/0, marquer/1.

si([X]):-vrai(X).
si([T|R]):-vrai(T), si(R).

alors([X]):- assert(vrai(X)).
alors([T|R]):-assert(vrai(T)), alors(R).

regle(r1):- si([a, b]), alors([c]).
regle(r2):- si([c, d]), alors([f]).
regle(r3):- si([f, b]), alors([e]).
regle(r4):- si([f, a]), alors([g]).
regle(r5):- si([g, f]), alors([b]).
regle(r6):- si([a, h]), alors([l]).

faits([X]):-assert(vrai(X)).
faits([T|R]):-assert(vrai(T)), faits(R).

mefaits([X]):-assert(faux(X)).
mefaits([T|R]):-assert(faux(T)), mefaits(R).

raz:-retractall(vrai(_)), retractall(faux(_)).

saturer :- vrai(e).
saturer :- not(marquer(X)),fail.
saturer([H|Q]):- not(marquer(H)), regle(r1), assert(changement);
