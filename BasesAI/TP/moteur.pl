%# Projet de Bases de l intelligence artificielle
%# Moteur de chainage avant

:- dynamic vrai/1, faux/1, changement/0, marquer/1.

si([X]):-vrai(X), !.
si([T|R]):-vrai(T), si(R), !.

alors([X]):-vrai(X), !.
alors([X]):- assert(vrai(X)), !.
alors([T|R]):- alors([T]), alors(R), !.

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
lister:- findall(X, vrai(X), R),write(R), nl, !.

lancer:- raz, faits([a, c, d]).

%# Gestion du chainage avant

%# Application du moteur d'inférence par chainage avant

application:- regle(X), not(marquer(X)),assert(marquer(X)),write(X), write(' : ').
appliquer:- changement, retract(changement), application, lister, assert(changement), fail.
appliquer:- not(changement).

%# Lancement du chainage avant
saturer:- assert(changement),repeat, appliquer.


%# Gestion du chainage arrière
satisfait(X):- vrai(X), write(X), writeln(' dans la base de faits.').
satisfait([X]):- satisfait(X).
satisfait(X):- clause(regle(R), (si(L), alors([X]))), satisfait(L), regle(R), write(X), write(' satisfait grace à '), write(R), nl.
satisfait([T|R]):- satisfait(T), satisfait(R).

saturer(X):-satisfait(X).
