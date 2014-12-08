# TD sur les MetaHeuristiques
(notation mathématique laTex)
## Exercice 1

## Exercice 2



x_i .. X = ABCDEF
f(x_i) = 21

y ... X` = ACFBE
f(y) = 30


p ≤ 0.5
exp(-∆f/t_k) = 0.5

∆f = f(y) - f(x_i) = 9
<=> exp(-9/t_k) = 0.5
<=> -9/t_k = ln(0.5)
<=> -9/ln(0.5) = t_k
<=> t_k ≃ 12.98

2.
0.5
0.001
µ

exp(-9/µ^n * 12.98) = 0.001
-9/(µ^n * 12.98) = ln(0.001)
9/ln(1000) = µ^n * 12.98
9/(ln(1000) * 12.98) = µ^n
n = \frac{1}{ln(0.µ)} * ln(\frac{∆f}{12.98/ln(1000)}
n = \frac{ln(\frac{ln2(p)}{ln 1000(p')}}{ln(µ)}
Application numérique :

µ |0.85	0.9	0.95 0.99
---------------------
k |14	22	45	 229

Le rapport des temperatures est de 10% =>
µ^k = e^{k ln(µ)} = \frac{ln 2}{ln(1000)}

## Exercice 3

1.
On part de 1111, et on se déplace vers la transformation la plus petite :
Trajet : [1111|1110|1010|1011|1111|0111|0101]
On s interdit la transformation inverse (pas de modification du Tn^x eme bit selon x)
T = {t4^⁰¹; t2⁰¹;t4¹⁰;t1⁰¹}

2.
Pour t=2 on trouve également la solution optimale

3.
