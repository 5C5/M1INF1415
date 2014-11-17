#!/usr/bin/env perl
use strict;

my $nbrepqt = 0;
	open(FIC,"out.tr") or die("erreur à l'ouverture: $!");

	while(defined( $line = <FIC>) and $stop){

	   chomp $line;
	   @liste = split(' ', $line);
	   
	   if($liste[1] > 1 and $liste[1] < 5 and $liste[8] == 0.0 and $liste[9] == 4.0){
		   if($liste[0] eq "+"){
			   $nbrepqt ++;
			   if(){
			   }
	   }
