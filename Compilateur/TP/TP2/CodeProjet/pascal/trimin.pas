Program TriMin;
const
		TAILLE = 25;
type
		tab = array [ 1 .. TAILLE ] of integer ;
var
		tableau : tab ;

(*
*)
PROCEDURE permuter (var t : tab ; indice1 : integer ; indice2 : integer ) ;
Var
		aux : integer ;
Begin
	Aux := t [ indice1 ] ;
	t [ indice1 ] := t [ indice2 ] ;
	t [ indice2 ] := aux ;
End ;

(*
*)
FUNCTION recherchePositionMin ( t : tab ; i : integer ) : integer ;
var
		posMin , j : integer ;
begin
	posMin:= i ;
	for j := i+1 to n do
		if ( t [ j ] < t [ posMin ] ) then
			posMin:= j ;
	recherchePositionMin := posMin ;
end ;

(*
*)
PROCEDURE triSelection(VAR t : tab );
Var
		i , iMin : integer;
begin
	For i :=1 to n do
	Begin
		iMin := recherchePositionMin ( t , i ) ;
		permuter ( t , i , iMin ) ;
	end;
end;

(*
*)
begin
	for i := 1 to TAILLE do
	begin
		write ( 'Saisir t[', i, '] :' );
		read ( t [ i ] );
	end;
	triSelection ( tableau ) ;
	write ( 'tableau trie : ' );
	for i := 1 to TAILLE do
	begin
		write ( ' ', t [ i ] )
	end;
	writeln;
end.


