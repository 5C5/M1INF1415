-- Fichier réponse TP SQL/XML MIF18 2015
-- Information sur les étudiants (compléter pour chaque membre du binôme/monôme)
-- Etudiant 1:
-- Nom: PICARD	
-- Prenom: Colas
-- Num étudiant: p1410822

--
--
-- NE PAS MODIFIER LE RESTE DES COMMENTAIRES DU FICHIER
-- Les réponses sont à saisir entre deux commentaires




/*1.
    Donner, pour chaque arbre de la parcelle 613376 (IDP), sa hauteur totale (HTOT).

    <!DOCTYPE arbre [
    <!ELEMENT arbre(hauteur)>
    <!ELEMENT hauteur (#PCDATA)>
    ]>
*/
SELECT XMLELEMENT(name "arbre", 
  XMLELEMENT(name "hauteur", HTOT)) 
  AS VXML
  FROM ARBRES a 
  WHERE a.IDP = 613376; 


/*2.
    Reprendre la question précédente et ajouter un attribut id (valeur obtenue via A) dans l'élément arbre.

    <!DOCTYPE arbre [
    <!ELEMENT arbre(hauteur)>
    <!ATTLIST arbre id CDATA #REQUIRED>
    <!ELEMENT hauteur (#PCDATA)>
    ]>
*/
SELECT XMLELEMENT(name "arbre", 
  XMLATTRIBUTES(a.A as "id"), 
  XMLELEMENT(name "hauteur", HTOT))
  AS vxml
  FROM ARBRES a 
  WHERE a.IDP = 613376; 


/*3.
    Ajouter, lorsqu'elle est disponible, le nom de l'espèce (code: ESPAR, nom obtenu via la vue documentation), toujours pour la parcelle 613376.

    <!DOCTYPE arbre [
    <!ELEMENT arbre(hauteur,espece?)>
    <!ATTLIST arbre id CDATA #REQUIRED>
    <!ELEMENT hauteur (#PCDATA)>
    <!ELEMENT espece (#PCDATA)>
    ]>
*/
SELECT XMLELEMENT(name "arbre", 
  XMLATTRIBUTES(a.A as "id"), 
  XMLELEMENT(name "hauteur", HTOT),
  XMLFOREST(libelle AS "espece"))
  AS vxml
  FROM ARBRES a LEFT OUTER JOIN  
    (SELECT libelle, code  FROM DOCUMENTATION WHERE DOCUMENTATION.DONNEE = 'ESPAR') ON a.ESPAR = code
  WHERE a.IDP = 613376;

/*4.
    Donner pour chaque espèce (valeur distincte ESPAR) son nom (si disponible) et le nombre d'arbres de cette espece.

    <!DOCTYPE espece [
    <!ELEMENT espece (nom?,quantite)>
    <!ATTLIST espece code CDATA #REQUIRED>
    <!ELEMENT nom (#PCDATA)>
    <!ELEMENT quantite (#PCDATA)>
    ]> 
*/
SELECT XMLELEMENT(name "espece", 
  XMLATTRIBUTES(a.ESPAR as "code"),
  XMLFOREST(libelle AS "nom"),
  XMLFOREST(COUNT(a.A) AS "quantite"))
  AS vxml
  FROM ARBRES a LEFT OUTER JOIN  
    (SELECT libelle, code  FROM DOCUMENTATION WHERE DOCUMENTATION.DONNEE = 'ESPAR') ON a.ESPAR = code
  GROUP BY a.ESPAR, libelle;

/*5.
    Pour chaque parcelle dont l'identifiant (IDP) est inférieur ou égal à 600200, donner l'identifiant de la parcelle et la liste des espèces présentes dans cette parcelle (son code ESPAR sous forme d'attribut XML et pour celles dont on le connait, leur nom sous forme de texte).

    <!DOCTYPE parcelle [
    <!ELEMENT parcelle (espece*)>
    <!ATTLIST parcelle id CDATA #REQUIRED>
    <!ELEMENT espece (#PCDATA)>
    <!ATTLIST espece code CDATA #REQUIRED>
    ]>
*/
SELECT XMLELEMENT(name "parcelle",
  XMLATTRIBUTES(a.IDP AS "code"),
  XMLAGG(
    XMLELEMENT(name "espece", 
    XMLATTRIBUTES(code AS "code"),
    libelle)))
FROM (SELECT DISTINCT IDP, ESPAR FROM ARBRES) a 
  LEFT OUTER JOIN 
(SELECT DISTINCT libelle, code FROM DOCUMENTATION WHERE donnee = 'ESPAR') d ON a.espar = d.code
WHERE a.IDP <= 600200
GROUP BY a.IDP;
/*6.
    Pour chaque parcelle dont l'identifiant (IDP) est inférieur ou égal à 600200, donner l'identifiant de la parcelle, le nombre d'arbres de cette parcelle et la liste des espèces présentes dans cette parcelle (son code ESPAR sous forme d'attribut XML et pour celles dont on le connait, leur nom sous forme de texte).

    <!DOCTYPE parcelle [
    <!ELEMENT parcelle (nb,espece*)>
    <!ATTLIST parcelle id CDATA #REQUIRED>
    <!ELEMENT nb (#PCDATA)>
    <!ELEMENT espece (#PCDATA)>
    <!ATTLIST espece code CDATA #REQUIRED>
    ]>
*/
SELECT XMLELEMENT(name "parcelle",
  XMLATTRIBUTES(IDP AS "id"),
    XMLELEMENT(name "nb", nb),
  XMLAGG(
    XMLELEMENT(name "espece", 
    XMLATTRIBUTES(code AS "code"),
    libelle)))
FROM 
  (SELECT IDP, COUNT(A) AS nb FROM ARBRES GROUP BY IDP) nbr
  NATURAL JOIN
  ((SELECT distinct IDP, ESPAR FROM ARBRES) a 
  LEFT OUTER JOIN 
(SELECT distinct libelle, code FROM DOCUMENTATION WHERE donnee = 'ESPAR') d ON a.espar = d.code)
WHERE IDP <= 600200
GROUP BY IDP, nb;

/*7.
    Pour les espèces présentes dans entre 2 et 5 parcelles, donner leur code, leur nom et la liste des parcelles (IDP) contenant des arbres de cette espèce.

    <!DOCTYPE espece [
    <!ELEMENT espece (nom,parcelle+)>
    <!ATTLIST espece code CDATA #REQUIRED>
    <!ELEMENT nom (#PCDATA)>
    <!ELEMENT parcelle EMPTY>
    <!ATTLIST parcelle id CDATA #REQUIRED>
    ]>
*/
SELECT XMLELEMENT(name "espece",
  XMLATTRIBUTES(ar2.ESPAR AS "code"),
  XMLELEMENT(name "nom", libelle),
  XMLAGG(
    XMLELEMENT(name "parcelle",
     XMLATTRIBUTES(IDP AS "id")))
     )
AS vxml 
FROM
  (SELECT ar1.ESPAR, count(DISTINCT ar1.IDP) AS nbp
  FROM ARBRES ar1
  GROUP BY ESPAR) ar2 
  LEFT OUTER JOIN
  (SELECT code, libelle FROM DOCUMENTATION WHERE donnee = 'ESPAR')
  ON ar2.ESPAR = code
  LEFT OUTER JOIN
  ARBRES arb
  ON ar2.ESPAR = arb.ESPAR
WHERE nbp > 1 AND nbp < 6
GROUP BY ar2.ESPAR, libelle;


/*8.
    Reprendre la question précédente en ajoutant le nombre d'arbres de l'espèce concernée dans la parcelle concernée sous forme de texte dans l'élément parcelle.

    <!DOCTYPE espece [
    <!ELEMENT espece (nom,parcelle+)>
    <!ATTLIST espece code CDATA #REQUIRED>
    <!ELEMENT nom (#PCDATA)>
    <!ELEMENT parcelle (#PCDATA)>
    <!ATTLIST parcelle id CDATA #REQUIRED>
    ]>
*/
SELECT XMLELEMENT(name "espece",
  XMLATTRIBUTES(ar2.ESPAR AS "code"),
  XMLELEMENT(name "nom", libelle),
  XMLAGG(
    XMLELEMENT(name "parcelle",
     XMLATTRIBUTES(arb.IDP AS "id"),
     ar3.nbr
    )
  )
)
AS vxml 
FROM
  (SELECT ar1.ESPAR, count(DISTINCT ar1.IDP) AS nbp
  FROM ARBRES ar1
  GROUP BY ESPAR) ar2 
  LEFT OUTER JOIN
  (SELECT code, libelle FROM DOCUMENTATION WHERE donnee = 'ESPAR')
  ON ar2.ESPAR = code
  LEFT OUTER JOIN
  ARBRES arb
  ON ar2.ESPAR = arb.ESPAR
  LEFT OUTER JOIN
  (SELECT ESPAR, IDP, COUNT(*) AS nbr
  FROM ARBRES
  GROUP BY ESPAR, IDP) ar3
  ON ar3.IDP = arb.IDP
WHERE nbp > 1 AND nbp < 6
GROUP BY ar2.ESPAR, libelle;