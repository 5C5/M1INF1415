#! bin/usr/perl

use strict;
use warnings;

open(FIC,"out3.tr") or die("erreur à l'ouverture: $!");

my $line;
my @liste;
my @listePaquet;
my $taille;
my $compteurPaquet;
my $comptPerteUdp = 0;
my $comptPerteTcp = 0;
my $comptPerteAck = 0;
my $comptPerte = 0;

while( defined( $line = <FIC> ) ) {
   
   chomp $line;
   
   if( $line =~ m/d/ and $line =~ m/tcp/) {
	   $comptPerteTcp ++;
   }
   elsif( $line =~ m/d/ and $line =~ m/udp/) {
	   $comptPerteUdp ++;
   }
   elsif( $line =~ m/d/ and $line =~ m/ack/) {
	   $comptPerteAck ++;
   }
   elsif ($line =~ m/d/){
	   $comptPerte ++;
   }
   else {

	   @liste = split(' ', $line);
	   $taille = @liste;
	   printf "Numero du paquet est : $liste[$taille -1]\n";
   }

}
printf "Nombre de paquet UDP perdus = $comptPerteUdp\n";
printf "Nombre de paquet Ack perdus = $comptPerteAck\n";
printf "Nombre de paquet TCP perdus = $comptPerteTcp\n";
printf "Nombre de paquet Autres perdus = $comptPerte\n";
<>;
