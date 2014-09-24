# Implémentation des divers éléments du cours de logique en prologue.

# Négation 
faux(X):-not(vrai(X)).

# Et / Ou
et(X, Y):- vrai(X), vrai(Y).
ou(X, Y):- vrai(X); vrai(Y).

#implication :
implique(X, Y):-faux(X); vrai(Y).

#équivalence
equivaut(X, Y):- implique(X, Y), implique(Y, X).


# une formule F est dite satisfiable si
delta(F):-!.
# c'est à dire que pour une interprétation au moins de F, F est vraie. On dit que F est consistente

# une formule F est dite insatisfiable si
delta(_):-fail.
# c'est à dire que pour toute interprétation de F, F est fausse. On dit que F est inconsistante.
#
# Une formule F est une tautologie ssi
delta(_):-!.
# C'est à dire que pour toute interprétation de F, F est vraie. On dit aussi que F est valide


# Formes Normales
# Forme normale disjonctive : une formule F est sous FND si
