#!/usr/bin/env perl
use strict;
#use warnings;


sub tauxPerteUDP {
	open(FIC,"out3.tr") or die("erreur à l'ouverture: $!");

	my $line;
	my $stop = 1;
	my @liste;
	my @paquets;
	my $tauxPerte;
	my $nbrePaquet = 0;
	my $comptPerte = 0;

	while(defined($line = <FIC>) and $stop){

	   chomp $line;
	   @liste = split(' ', $line);
	   
	   if($liste[1] >=1 and $liste[1] <= 2){
		   
		   if($liste[-1] ~~ @paquets){
			   
			   #printf "Paquets $liste[-1] déjà enregistré\n";
		   }
		   else{

			   push(@paquets, $liste[-1]);
			   $nbrePaquet ++;

			   if($line =~ m/d/){

				   $comptPerte ++;
			   }
		   }
	   }
	   else {
		   $stop = 0;
	   }
	}
	$tauxPerte = $comptPerte/$nbrePaquet;
	printf " Le taux de perte vaut $tauxPerte %, en effet $comptPerte paquets ont été perdus parmi les $nbrePaquet envoyés\n";
}


sub delaiBeB {

	my ($t1, $t2, $i);
	my $stop = 1;
	my $trouve = 0;
	my $nbrePaquet = 0;
	my ($som, $moy, $line);
	my @liste;
	my @courant;
	my @paquets;

	printf "Entrez les bornes pour le calcul du delai de bout en bout moyen des paquets\n";
	printf "t1 : ";
	$t1 = <>;
	printf "t2 : ";
	$t2 = <>;
	while($t2 < $t1 or $t1 < 0 or $t2 > 5){
	
		printf "t2 doit être supérieur à t1 et tous deux compris entre 0 et 5\n";
		printf "t1 : ";
		$t1 = <>;
		printf "t2 : ";
		$t2 = <>;
	}
	chomp $t1;
	chomp $t2;

	open(FIC,"out3.tr") or die("erreur à l'ouverture: $!");
	
	while(defined( $line = <FIC>) and $stop){

	   chomp $line;
	   @liste = split(' ', $line);
	   
	   if($liste[1] >= $t1 and $liste[1] <=$t2){

		   # printf "on entre entre les bornes définies\n";

# On vérifie que ce soit un paquet UDP
		   if($liste[4] == "udp"){

# On parcours la liste des paquets reçus, en cherchant le numéro de paquet courant
			   for($i = 0; $i < @paquets; $i++){

				   if($liste[-1] ==  $paquets[$i][0]){

# Si on le trouve, on vérifie que la ligne concerne sa réception par le noeud 3, et on calcule le délai de bout en bout
					   $trouve = 1;
					   
					   if($liste[0] == 'r' and $liste[2] == 2 and $liste[3] == 3){
						
						   $paquets[$i][2] = $liste[1] - $paquets[$i][1];

						   #printf "delai de bout en bout 1  = $paquets[$i][1] - $liste[1], soit $paquets[$i][2]\n";
					   }
					   # On quitte le boucle quand on l'a trouvé
					   last;
				   }

			   }
# Si on ne le trouve pas, on vérifie que la ligne correspond bien à un envoi, et on l'ajoute à la liste des paquets.
			   if(not $trouve){
				   
				   if($liste[0] == '+' and $liste[3] == 2){
					   push(@paquets, [$liste[-1], $liste[1], 0]);
				   }
			   }
			   $trouve = 0;
		   }
	   }
	   elsif($liste[1] > $t2){
		   $stop = 0;
	   }
	
	}
	$som = 0;
	
	for($i = 0; $i < @paquets; $i++){

		#printf "delai de bout en bout = $paquets[$i][2]\n";
		if($paquets[$i][2] > 0){

			$som += $paquets[$i][2];
			$nbrePaquet ++;
		}
	}
	$moy = sprintf("%0.5f",$som/$nbrePaquet);

	printf "Le délai moyen de bout en bout entre $t1 et $t2 est de $moy, pour un total de $nbrePaquet paquets arrivés\n";

}

=for
my $choix = 0;

while(1){
	
	given($choix){

		when(0){
			printf "\tVoulez vous afficher le taux de perte des paquets UDP entre 1 et 2s ? --> 1\n\tVoulez vous afficher le délai de bout en bout moyen des paquets entre deux instants? -->2 \n\tVoulez vous quitter? -->3\n"
			print "votre choix : ";
			$choix = <>;
			chomp $choix;
			while($choix < 1 && $choix > 3){
					print"Votre choix doit être compris entre 1 et 3 : ";
					$choix = <>;
					chomp $choix;
			}
		}

		when(1){
			
			tauxPerteUDP;
			$choix = 0;
		}

		when(2){
			delaiBeB;
			$choix = 0;
		}

		when (3) {
			die "Au revoir!\n";
		}
	}
}
=cut

tauxPerteUDP;
delaiBeB;
