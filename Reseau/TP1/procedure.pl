#! bin/usr/perl

use strict;
use warnings;

open(FIC,"out3.tr") or die("erreur à l'ouverture: $!");

my $line;
my $comptPerteUdp = 0;
my $comptPerteTcp = 0;
my $comptPerteAck = 0;
my $comptPerte = 0;

while( defined( $line = <FIC> ) ) {
   
   chomp $line;
   
   if( $line =~ m/d/ && $line =~ m/tcp/) {
	   $comptPerteTcp ++;
   }
   elsif( $line =~ m/d/ && $line =~ m/udp/) {
	   $comptPerteUdp ++;
   }
   elsif( $line =~ m/d/ && $line =~ m/ack/) {
	   $comptPerteAck ++;
   }
   elsif ($line =~ m/d/){
	   $comptPerte ++;
   }
}
printf "Nombre de paquet UDP perdus = $comptPerteUdp\n";
printf "Nombre de paquet Ack perdus = $comptPerteAck\n";
printf "Nombre de paquet TCP perdus = $comptPerteTcp\n";
printf "Nombre de paquet Autres perdus = $comptPerte\n";
<>;
