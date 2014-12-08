# Exercice 1 de prologue
# Recherche en profondeur dans un labyrinthe


# Question 1
etatInitial(entree).
etatFinal(sortie).
operateur(E1,[E1,E2],E2) :-couloir(E1,E2).
operateur(E1,[E1,E2],E2) :-couloir(E2,E1).

couloir(entree, thesee).
couloir(entree, ariane).
couloir(thesee, minotaure).
couloir(thesee,sombre).
couloir(claire, sombre).
couloir(claire, sortie).
couloir(minotaure, sortie).
couloir(ariane, claire).
couloir(sombre,sortie).

rechPF(E, E, _, []).
rechPF(Ec, Ef, L1, [Op|L2]):- ope(Ec, Op, Es), not(member(Es, L1)), rechPF(Es, Ef, [Ec|L1], L2).

# Question 2
resoudre(S):-etatInitial(Ei), etatFinal(Es), rechPF(Ei, Ef, [], S).

# Question 3
initial([h, h, h, b, b, b]).
final([b, b, b, h, h, h]).

operation(h, h, b, b).
operation(b, b, h, h).
operation(h, b, b, h).
operation(b, h, h, b).

ope([T|[H|R]], [T, H, ], [NewT|[NewH|R]]):-operation(T, H, NewT, NewH).

rempl(S1, S2, L1, L2).
