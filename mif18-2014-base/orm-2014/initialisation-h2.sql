create table cinema(
	nom varchar(255) primary key,
	adresse varchar(255) );

create table salle(
	nom varchar(30) ,
	cinema varchar(255)  references cinema(nom),
	capacite integer ,
	primary key(cinema,nom) );

create table seance(
	debut timestamp ,
	fin timestamp ,
	salle varchar(30),
	cinema varchar(255),
	film varchar(255),
	foreign key (cinema,salle) references salle(cinema,nom),
	primary key(cinema,salle,debut) );

create table client(
	num_client integer primary key,
	nom varchar(255));

create table reservation(
	id integer primary key,
	seance timestamp ,
	salle varchar(30) ,
	cinema varchar(255) ,
	quantite integer ,
	client integer references client(num_client),
	foreign key (cinema,salle,seance) references seance(cinema,salle,debut));

CREATE SEQUENCE hibernate_sequence
INCREMENT 1
MINVALUE 1
MAXVALUE 9223372036854775807
START 1
CACHE 1;
