--Les bases
--Prof(nom, domaine)
--Enseigne(prof, n_cours, trimestre, evaluation, univ)
--Cours(n_cours, titre, univ)
--Inscrit(étudiant, n_cours, trimestre)
--Majeur(etudiant, dept)
--Exerce(prof, dept)
--Conseille(Prof, étudiant)

CREATE VIEW Cours-BD AS
SELECT Cours.titre, Enseigne.Prof, Cours.n_cours, cours.univ
FROM Enseigne, Cours
WHERE Enseigne.n_cours = Cours.n_cours 
AND Enseigne.univ = cours.univ 
AND cours.titre = "BD";

CREATE VIEW VL1_Cours_Cycle3 AS
SELECT Cours.titre, Enseigne.prof, COurs.n_cours, Cours.univ
FROM Enseigne, Cours,
WHERE Enseigne.n_cours = Cours.n_cours
AND Cours.univ = "LYON1"
AND Enseigne.univ = "LYON1"
AND Cours.n_cours >= 500;

--Q1 : qui enseigne les cours de BD à Lyon1
SELECT Prof
FROM Cours-BD
WHERE univ = "LYON1";

--Q2 : Tous les cours en cycle 2 ou plus dispensé à Lyon1, les cours de cycle 2 ayant un numéro >=400
SELECT titre
FROM Cours
WHERE univ = "LYON1"
AND n_cours >= 400;

--------------------------------------------------------------------------------------------------------

--Q1
SELECT inscrit.etudiant, Cours.titre
FROM Enseigne, Prof, Inscrit, Cours
WHERE Prof.nom = enseigne.prof 
AND Enseigne.n_cours = inscrit.n_cours
AND Enseigne.trimestre = inscrit.trimestre
AND inscrit.n_cours = Cours.n_cours
AND cours.n_cours >= 500
AND prof.domaine = "BD";

--Q2
SELECT conseille.prof, conseille.etudiant, inscrit.trimestre
FROM inscrit, enseigne, conseille
WHERE enseigne.n_cours = inscrit.n_cours
AND enseigne.trimestre ⁼ inscrit.trimestre
AND conseille.prof = enseigne.prof
AND conseille.etudiant = inscrit.etudiant
AND inscrit.etudiant = enseigne.etudiant
AND inscrit_trimestre >= "S198";


CREATE VIEW V1 AS
SELECT inscrit.etudiant, enseigne.prof, inscrit.trimestre
FROM Inscrit, Enseigne
WHERE inscrit.n_cours = enseigne.n_cours
AND inscrit.trimestre = enseigne.trimestre
AND inscrit.trimestre > "S197";

CREATE VIEW V2 AS
SELECT inscrit.etudiant, inscrit.trimestre
FROM inscrit, enseigne
WHERE inscrit.n_cours = enseigne.n_cours
AND inscrit.trimestre = enseigne.trimestre
AND inscrit.trimestre >= "S198";

CREATE VIEW V3 AS
SELECT inscrit.etudiant, enseigne.prof, inscrit.trimestre
FROM inscrit, enseigne
WHERE inscrit.n_cours = enseigne.n_cours
AND inscrit.trimestre >= "S198";

CREATE VIEW V4 AS
SELECT inscrit.etudiant, inscrit.trimestre, enseigne.prof
FROM inscrit.enseigne, conseille, prof
WHERE inscrit.n_cours = enseigne.n_cours
AND inscrit.trimestre = enseigne.trimestre
AND enseigne.prof = conseille.prof
AND enseigne.prof = prof.nom
AND inscrit.trimestre >= "S198";
--Q1 à partir des vues
--Pas possible

--Q2 à partir des vues
SELECT V1.prof, V1.etudiant, V1.trimestre
FROM V1, Conseille
WHERE conseille.etudiant =  V1.etudiant
AND conseille.prof = V1.prof



