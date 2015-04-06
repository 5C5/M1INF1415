/*
TP1 Base de Donnees Reparties
PICARD Colas
11410822
*/

/*
Exercice 1
*/
--Question 1 (executee sur orapeda1)
SELECT table_name FROM tabs;

--Question 2 (executee sur orapeda1)
CREATE TABLE tabletest (
  A int,
  B varchar(50));

INSERT INTO tabletest (A, B)VALUES(
  (1, 'UN'),
  (2, 'DEUX')
  );
  
SELECT * FROM tabletest;

--Question 3 (executee sur orapeda2)
CREATE DATABASE LINK lien2to1 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda1;

--Question 4 (executee sur orapeda 2)
SELECT * FROM tabletest@lien2to1;

/*
Exercice 2
*/
--Question 1 (executee sur orapeda 1)
SELECT * FROM BDENS.joueur;

--Question 2 (executee sur orapeda 2)
SELECT * FROM BDENS.joueur@lien2to1;

/*
Exercice 3
*/
--QUestion 1
--6

--Question 2

--Sur orapeda 1
CREATE DATABASE LINK lien1to2 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda2;
CREATE DATABASE LINK lien1to3 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda3;

--Sur orapeda 2
CREATE DATABASE LINK lien2to3 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda3;

--sur orapeda 3
CREATE DATABASE LINK lien3to1 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda1;
CREATE DATABASE LINK lien3to2 CONNECT TO M1IF35 IDENTIFIED BY M1IF35 USING orapeda2;

/*
Exercice 4
*/
--Question 1 (executee sur orapeda1)
CREATE TABLE Joueur AS * FROM BDENS.JOUEUR;

--Question 2
CREATE TABLE Gain AS * FROM BDENS.GAIN@lien2to1;

--Question 3
CREATE TABLE Rencontre AS * FROM BDENS.RENCONTRE@lient3to1;

--Question 4
--Sur orapeda1
ALTER TABLE Joueur ADD CONSTRAINT pk_NuJoueur PRIMARY KEY (NuJoueur);

--Sur orapeda2
ALTER TABLE Gain ADD CONSTRAINT pk_NuGain PRIMARY KEY (NuJoueur, LieuTournoi, Annee);

--Sur orapeda3
ALTER TABLE Rencontre ADD CONSTRAINT pk_NuRencontre PRIMARY KEY (NuPerdant, LieuTournoi, Annee);

--Question 5
--Non

/*
Exercice 5
*/
--R1 (sur orapeda1)
SELECT DISTINCT nomsponsort FROM Joueur WHERE Nu_Joueur IN 
(SELECT Nu_Joueur FROM rencontre@lien1to3 WHERE Annee = '1992');

--R2 (sur orapeda2)
SELECT DISTINCT j.nom, t.Nb_Defaites
FROM (SELECT DISTINCT r.nuperdant,count(*) as Nb_Defaites
		FROM rencontre@lien2to3 r
		WHERE nugagnant= (SELECT nujoueur FROM joueur@lien2to1 WHERE nom='SAMPRAS')
		GROUP BY nuperdant) t, 
	joueur@lien2to1 j
WHERE j.nujoueur=t.nuperdant;

--R3 (sur orapeda3)
SELECT DISTINCT j.nom, SUM(g.Prime) AS Prime_Cumule FROM joueur@lien3to1 j, gain@lien3to2 g
WHERE j.nationalite='France'
AND j.nujoueur=g.nujoueur
GROUP BY j.nom;

/*
Exercice 6
*/
--Question 1 (sur orapeda1)
CREATE VIEW JoueurFrancais AS 
(SELECT nujoueur, nom, prenom, annaiss FROM joueur WHERE nationalite='France');

--Question 2 (sur orapeda2)
CREATE VIEW SponsoriseParPeugeot (NuJoueur, PrenomNom)
AS
(SELECT DISTINCT j.nujoueur, concat(j.nom,concat(' ',j.prenom)) FROM joueur@lien2to1 j, gain g
  WHERE j.nujoueur=g.nujoueur
  AND g.nomsponsor='Peugeot');

--Question 3 (sur orapeda3)
CREATE VIEW PrimePeugeot (Nujoueur, SPrime)
AS 
(SELECT j.nujoueur, SUM(g.prime) FROM joueur@lien3to1 j, gain@lien3to2 g
    WHERE j.nationalite='France'
    AND j.nujoueur=g.nujoueur
    GROUP BY j.nujoueur);

/*
Exercice 7
*/
--Question 1 (orapeda2)
CREATE MATERIALIZED VIEW Joueur
refresh ON DEMAND COMPLETE
AS (SELECT * FROM joueur@lien2to1);

--Question 2 (sur orapeda 3)
CREATE MATERIALIZED VIEW Joueur
refresh ON DEMAND COMPLETE
AS (SELECT * FROM joueur@lien3to1);


CREATE MATERIALIZED VIEW log ON gain WITH PRIMARY KEY;
CREATE MATERIALIZED VIEW gain2
refresh fast START WITH sysdate next sysdate+1/1440
AS SELECT * FROM gain;