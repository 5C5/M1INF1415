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

/*2.
    Reprendre la question précédente et ajouter un attribut id (valeur obtenue via A) dans l'élément arbre.

    <!DOCTYPE arbre [
    <!ELEMENT arbre(hauteur)>
    <!ATTLIST arbre id CDATA #REQUIRED>
    <!ELEMENT hauteur (#PCDATA)>
    ]>
*/

/*3.
    Ajouter, lorsqu'elle est disponible, le nom de l'espèce (code: ESPAR, nom obtenu via la vue documentation), toujours pour la parcelle 613376.

    <!DOCTYPE arbre [
    <!ELEMENT arbre(hauteur,espece?)>
    <!ATTLIST arbre id CDATA #REQUIRED>
    <!ELEMENT hauteur (#PCDATA)>
    <!ELEMENT espece (#PCDATA)>
    ]>
*/

/*4.
    Donner pour chaque espèce (valeur distincte ESPAR) son nom (si disponible) et le nombre d'arbres de cette espece.

    <!DOCTYPE espece [
    <!ELEMENT espece (nom?,quantite)>
    <!ATTLIST espece code CDATA #REQUIRED>
    <!ELEMENT nom (#PCDATA)>
    <!ELEMENT quantite (#PCDATA)>
    ]> 
*/

/*5.
    Pour chaque parcelle dont l'identifiant (IDP) est inférieur ou égal à 600200, donner l'identifiant de la parcelle et la liste des espèces présentes dans cette parcelle (son code ESPAR sous forme d'attribut XML et pour celles dont on le connait, leur nom sous forme de texte).

    <!DOCTYPE parcelle [
    <!ELEMENT parcelle (espece*)>
    <!ATTLIST parcelle id CDATA #REQUIRED>
    <!ELEMENT espece (#PCDATA)>
    <!ATTLIST espece code CDATA #REQUIRED>
    ]>
*/


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
