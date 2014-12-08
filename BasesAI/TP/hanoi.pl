# Programme de résolution des tours de Hanoi

move(1,X,Y,_) :-  
	write('Deplacement du disque du socle de '), 
	write(X), 
	write(' vers '), 
	write(Y), 
	nl. 
move(N,X,Y,Z) :- 
	N>1, 
	M is N-1, 
	move(M,X,Z,Y), 
	move(1,X,Y,_), 
	move(M,Z,Y,X).
hanoi(X):- move(X, a, c, b).
