#!/usr/bin/env perl
use strict;

sub delaiBeB {

	my ($t1, $t2, $i, $temp);
	my $stop = 1;
	my $trouve = 0;
	my $nbrePaquet = 0;
	my $line;
	my @liste;
	my $somme = 0;
	my $moy = 0;
	my (@paquets, @gigue);

	$t1 = 1;
	$t2 = 3;

	open(FIC,"out1.tr") or die("erreur à l'ouverture: $!");

	while(defined( $line = <FIC>) and $stop){

	   chomp $line;
	   @liste = split(' ', $line);
	   
	   if($liste[1] >= $t1 and $liste[1] <=$t2){
# On vérifie que le paquet n'est pas détruit
		   if($liste[0] ne "d" and $liste[4] eq "cbr"){
			   
			   #printf "Numéro de paquet lu : $liste[-1], type d'information : $liste[0], noeuds concernés : $liste[2] et $liste[3]\n";

# On parcours la liste des paquets reçus, en cherchant le numéro de paquet courant
			   for($i = 0; $i < @paquets; $i++){
				   
				   #printf "paquet recherché : $liste[-1] et # du paquet du tableau : $paquets[$i][0]\n";
				   if($liste[-1] eq  $paquets[$i][0]){
					   
					   #printf "Paquet déjà enregistré dans le tableau\n";

# Si on le trouve, on vérifie que la ligne concerne sa réception par le noeud 3, et on calcule le délai de bout en bout
					   $trouve = 1;
					   
					   if($liste[3] eq "3" and $liste[0] eq "r"){
							$paquets[$i][2] = $liste[1] - $paquets[$i][1];
							printf "Le paquet $liste[-1] a un délai de bout en bout de $paquets[$i][2] secondes\n";
							if($liste[-1] ne "0"){
								push(@gigue, [$liste[-1], $paquets[$i][2] - $temp]);
								printf "La gigue du paquet $liste[-1] est de $gigue[-1][1]\n";
							}
							$temp = $paquets[$i][2];
								
							#splice(@paquets, $i);
							$nbrePaquet ++;
					   }
					   # On quitte le boucle quand on l'a trouvé
					   last;
				   }

			   }
# Si on ne le trouve pas, on vérifie que la ligne correspond bien à un envoi, et on l'ajoute à la liste des paquets.
			   if(not $trouve){
				   
					push(@paquets, [$liste[-1], $liste[1], 0]);
					#printf "Enregistrement du paquet $paquets[-1][0] \n";
			   }
			   $trouve = 0;
		   }
		   else{
			   #printf "Paquet $liste[-1] détruit\n";
		   }
	   }
	   elsif($liste[1] > $t2){
		   $stop = 0;
	   }
	
	}
	my $taille;
	$taille = scalar(@paquets);
	printf "Nbre de paquet analysés : $nbrePaquet, nbre de paquets enregistrés : $taille\n";
	for($i = 0; $i < $nbrePaquet; $i++){

		#printf "delai de bout en bout = $paquets[$i][2]\n";
		if($paquets[$i][2] > 0){

			$somme += $paquets[$i][2];
		}
	}
	$moy = sprintf("%0.5f",$somme/$nbrePaquet);
	printf "Délai de bout en bout moyen : $moy\n";
	$somme = 0;
	for($i = 0; $i < $nbrePaquet; $i++){

		#printf "delai de bout en bout = $paquets[$i][2]\n";
		if($gigue[$i][1] > 0){

			$somme += $gigue[$i][1];
		}
	}
	$moy = sprintf("%0.5f",$somme/$nbrePaquet);
	printf "la valeur moyenne de la gigue est de $moy\n";
	

}

delaiBeB;
