# TD de réécriture


# Exercice 1
V1(Y, Z):- r(X), s(Y, Z), Y =< X, X =< Z.
V2(Y, Z):- r(X), s(Y, Z), Y =< X, X < Z.

Q(A):- r(A), A < 4.

Qb(A):- V1(A, A), A<4

#Exercice 2

Q(nom):- Emp(nom, num_dept, sal, age), age < 35, Dept(num_dept, taille, 'Lyon').

# Il n'est pas possible d'optimiser cette requête en utilisant Emp_Location, car il faudrait faire un test sur age, ce qui impliquerait de faire une jointure avec emp => pas optimisé.


#Exercice 3

#Q : 
SELECT(A1, E1, COUNT(B1))
FROM R1(A1, B1, C1, D1), R2(E1, F1)
WHERE C1 = F1 AND B1 = D1
GROUP BY A1, E1;

#V1 :
SELECT A2, C2, COUNT(D2)
FROM R1(A2, B2, C2, D2), R2(E2, F2)
WHERE B2 = D2
GROUP BY A2, C2

#Q'?
SELECT A3, E3, COUNT(D3)
FROM V1(A3 C3, COUNT(D3)), R2(E3, F3)
WHERE C3 = F3
GROUP BY E3
