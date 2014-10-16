program calculPGCD;

var x, y, resultat : integer;

function pgdc ( a : integer, b : integer ) : integer;
begin
	if a = b then
		pgcd := a;
	else if a > b then
		pgcd := pgcd ( a - b, b );
	else
		pgcd := pgcd ( a, b - a );
end

begin
	write ( 'Saisir la premiere valeur: ' );
	read ( x );
	write ( 'Saisir la seconde valeur: ' );
	read ( y );
	resultat := pgcd ( x, y );
	writeln ( 'le pgcd de ', x, ' et de ', y, ' est ', resultat );
end.
