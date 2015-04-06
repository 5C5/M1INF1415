/*
Bases de données Déductives et réparties
TP3 - Intégration
Colas PICARD
*/

/*
Exercice 1
*/
CREATE VIEW VI_Confiserie (
	idC INTEGER PRIMARY KEY, 
	nom varchar(20), 
	typeC varchar(20), 
	desc varchar(100))
AS SELECT C.numC + 100, C.nom, typeCat.typeC, C.composition
FROM BDENS.H_CONFISERIE@lien2to1 C, typeCat
WHERE C.categorie = typeCat.typeC;

CREATE VIEW VI_Usine (
	idU INTEGER PRIMARY KEY, 
	adr varchar(100), 
	ville varchar(50), 
	dept INT, 
	resp varchar(100))
AS SELECT cast(codeU AS NUMBER) + 50, concat(numRue, concat(" ", rue)), ville, cp/1000, concat(substr(prenomNomResp, instr(prenomNomResp, " ")), left(prenomNomResp, instr(prenomNomResp, " ")))
FROM BDENS.H_USINE@lien2to1;

CREATE VIEW VI_Chaine_Prod (
	idU INT PRIMARY KEY REFERENCES Usine.idU,
	idC INT PRIMARY KEY REFERENCES Confiserie.idC,
	resp varchar(50),
	tel INT,
	prixUnit FLOAT)
AS SELECT cast(ch.codeU AS NUMBER) + 50, ch.numC+ 100, ch.nomPrenomResp, NULL, ch.prixUnit/1.6
FROM BDHENS.H_CHAINEPROD@lien2to1 ch;

CREATE VIEW VI_Stock (
  idU INT PRIMARY KEY REFERENCES Usine.idU,
  idC INT PRIMARY KEY REFERENCES Confiserie.idC,
  dateF date PRIMARY KEY,
  dateP date, 
  qte INT)
AS SELECT cast(ch.codeU AS NUMBER) + 50, ch.numC+ 100, s.dateF, add_months(s.dateF, 6), s.qte
FROM BDHENS.H_CHAINEPROD@lien2to1 ch, BDHENS.H_STOCK@lien2to1 s
WHERE ch.numCP = s.numCP;

CREATE VI_Boutique (
  idB INT PRIMARY KEY,
  nom varchar(30),
  ville varchar(50),
  typeB varchar(30),
  mail varchar(40),
  CAmoyen INT)
AS SELECT b.numB, concat(b.nom, "&cie"), b.ville