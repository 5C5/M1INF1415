/*Rendu TP2 de MIF37 */
/* Marie Rancon p1309458 */
/* Antoine Sensier p1208892 */

/* Exercice 1 */
/* Sur Orapeda 1 */
create table Service1 as
(select *
from BDENS.Service
where hopital='HCL');

/* Sur Orapeda 2 */
create table Service2 as
(select *
from BDENS.Service@lien21
where hopital='Fleyriat');

/* Sur Orapeda 3 */
create table Service3 as
(select *
from BDENS.Service@lien31
where hopital<>'Fleyriat'
and hopital<>'HCL');

/* Sur Orapeda 1 */
create table Salle1 as
(select s.*
from BDENS.Salle s, Service1 v
where s.Snum=v.Snum);

/* Sur Orapeda 2 */
create table Salle2 as
(select s.*
from BDENS.Salle@lien21 s, Service2 v
where s.Snum=v.Snum);

/* Sur Orapeda 3 */
create table Salle3 as
(select s.*
from BDENS.Salle@lien31 s, Service3 v
where s.Snum=v.Snum);

/* Sur Orapeda 1 */
create table Infirmier1 as
(select i.*
from BDENS.Infirmier i, Service1 s
where i.Snum=s.Snum);

/* Sur Orapeda 2 */
create table Infirmier2 as
(select i.*
from BDENS.Infirmier@lien21 i, Service2 s
where i.Snum=s.Snum);

/* Sur Orapeda 3 */
create table Infirmier3 as
(select i.*
from BDENS.Infirmier@lien31 i, Service3 s
where i.Snum=s.Snum);

/* Sur Orapeda 1 */
create table Docteur1 as
(select *
from BDENS.Docteur);

/* Sur Orapeda 2 */
create table Docteur2 as
(select *
from BDENS.Docteur@lien21);

/* Sur Orapeda 3 */
create table Docteur3 as
(select *
from BDENS.Docteur@lien31);

/* Sur Orapeda 1 */
create table EmpInf1 as
(select e.*
from BDENS.Employe e, Infirmier1 i
where e.Enum=i.Inum);
/* Sur Orapeda 2 */
create table EmpInf2 as
(select e.*
from BDENS.Employe@lien21 e, Infirmier2 i
where e.Enum=i.Inum);
/* Sur Orapeda 3 */
create table EmpInf3 as
(select e.*
from BDENS.Employe@lien31 e, Infirmier3 i
where e.Enum=i.Inum);

/* Sur Orapeda 1 */
create table EmpDoc1 as
(select e.*
from BDENS.Employe e, Docteur1 d
where e.Enum=d.Dnum);
/* Sur Orapeda 2 */
create table EmpDoc2 as
(select e.*
from BDENS.Employe@lien21 e, Docteur2 d
where e.Enum=d.Dnum);
/* Sur Orapeda 3 */
create table EmpDoc3 as
(select e.*
from BDENS.Employe@lien31 e, Docteur3 d
where e.Enum=d.Dnum);

/* Sur Orapeda 1 */
create table Employe1 as
(select * from EmpInf1 
union select * from EmpDoc1);
/* Sur Orapeda 2 */
create table Employe2 as
(select * from EmpInf2 
union select * from EmpDoc2);
/* Sur Orapeda 3 */
create table Employe3 as
(select * from EmpInf3 
union select * from EmpDoc3);

/* Sur Orapeda 1 */
create table InfosPatient1 as
(select Pnum, nom, prenom, adr, tel
from BDENS.Patient);
/* Sur Orapeda 2 */
create table InfosPatient2 as
(select Pnum, nom, prenom, adr, tel
from BDENS.Patient@lien21);
/* Sur Orapeda 3 */
create table InfosPatient3 as
(select Pnum, nom, prenom, adr, tel
from BDENS.Patient@lien31);


/* Sur Orapeda 3*/
create table FactPatient3 as 
(select Pnum, mutuelle, priseencharge
from BDENS.Patient@lien31);
create table FactHospi3 as
(select Pnum, Snum, DateDebut, Cout
from BDENS.Hospitalisation@lien31);
create table Acte3 as
(select *
from BDENS.Acte@lien31);

/* Sur Orapeda 1 */
create table GestionHospi1 as
(select h.pnum, h.snum, h.datedebut, h.nbjours, h.sanum, h.lit
from Service1 s, BDENS.Hospitalisation h
where s.snum=h.snum);
/* Sur Orapeda 2 */
create table GestionHospi2 as
(select h.pnum, h.snum, h.datedebut, h.nbjours, h.sanum, h.lit
from Service2 s, BDENS.Hospitalisation@lien21 h
where s.snum=h.snum);
/* Sur Orapeda 3 */
create table GestionHospi3 as
(select h.pnum, h.snum, h.datedebut, h.nbjours, h.sanum, h.lit
from Service3 s, BDENS.Hospitalisation@lien31 h
where s.snum=h.snum);









/* Exercice 2 */
create or replace 
trigger TR_SERVICE 
BEFORE INSERT OR UPDATE ON Service1
FOR EACH ROW
DECLARE
CURSOR C_NB is select count(*) as nb from M1IF35.Service2@lien12 s2,  M1IF35.Service3@lien13 s3 where :NEW.snum = s2.snum and :NEW.snum = s3.snum;
cnb integer(2);
BEGIN
open C_NB;
fetch C_NB into cnb;
  if cnb <> 0 then
    RAISE_APPLICATION_ERROR ( -20010, 'Cle deja creee' ) ;
  end if;
  NULL;
  close C_NB;
END;

CREATE OR REPLACE TRIGGER TR_HOSPI 
BEFORE INSERT OR UPDATE ON GESTIONHOSPI1 
FOR EACH ROW
DECLARE
CURSOR C_NB is select count(*) as nb from M1IF35.GestionHospi2@lien12 g2,  M1IF35.GestionHospi3@lien13 g3 where :NEW.snum = g2.snum and :NEW.snum = g3.snum
                                                                                                          and :NEW.pnum = g2.pnum and :NEW.pnum = g3.pnum
                                                                                                          and :NEW.datedebut = g2.datedebut and :NEW.datedebut = g3.datedebut;

CURSOR Cle_etr is select count(*) as nb from M1IF35.Service1 s1, M1IF35.Service2@lien12 s2,M1IF35.Service3@lien13 s3 
                where :NEW.snum = s1.snum and :NEW.snum = s2.snum and :NEW.snum = s3.snum;

CURSOR Cle_etr2 is select count(*) as nb from M1IF35.InfosPatient1 p
                where :NEW.pnum = p.pnum 
                ;
                
cnb integer(2);
ccle integer(2);
BEGIN
open C_NB;
fetch C_NB into cnb;
  if cnb <> 0 then
    RAISE_APPLICATION_ERROR ( -20010, 'Cle deja creee' ) ;
  end if;
  NULL;
  close C_NB;
  
  open Cle_etr;
  fetch Cle_etr into ccle;
  if ccle <> 1 then
        RAISE_APPLICATION_ERROR ( -20010, 'Cle etrangere service non existante' ) ;
end if;
close Cle_etr;

open Cle_etr2;
fetch Cle_etr2 into ccle;
if ccle = 0 then 
          RAISE_APPLICATION_ERROR ( -20010, 'Cle etrangere patient non existante' ) ;
end if;
END;




/* Exercice 3 */
/* Sur Orapeda 1 */
CREATE VIEW Service AS
(select * from Service1) union
(select * from Service3@lien13) union
(select * from Service2@lien12);

CREATE VIEW Salle AS
(select * from Salle1) union
(select * from Salle3@lien13) union
(select * from Salle2@lien12);

CREATE VIEW Infirmier AS
(select * from Infirmier1) union
(select * from Infirmier2@lien12) union
(select * from Infirmier3@lien13);

CREATE VIEW Docteur AS
(select * from Docteur1);

CREATE VIEW Employe AS
(select * from Employe1) union
(select * from Employe2@lien12) union
(select * from Employe3@lien13);

CREATE VIEW Patient AS
(select InfosPatient1.*, FactPatient3.mutuelle, FactPatient3.priseEnCharge from InfosPatient1, FactPatient3@lien13 WHERE InfosPatient1.Pnum=FactPatient3.Pnum) union
(select InfosPatient2.*, FactPatient3.mutuelle, FactPatient3.priseEnCharge from InfosPatient2@lien12, FactPatient3@lien13 WHERE InfosPatient2.Pnum=FactPatient3.Pnum) union
(select InfosPatient3.*, FactPatient3.mutuelle, FactPatient3.priseEnCharge from InfosPatient3@lien13, FactPatient3@lien13 WHERE InfosPatient3.Pnum=FactPatient3.Pnum) ;

CREATE VIEW Acte AS
(select * from Acte3@lien13);


CREATE VIEW Hospi AS
(select GestionHospi1.*, FactHospi3.cout from GestionHospi1, FactHospi3@lien13 where GestionHospi1.Pnum = FactHospi3.Pnum and GestionHospi1.Snum = FactHospi3.Snum and GestionHospi1.dateDebut = FactHospi3.dateDebut) union
(select GestionHospi2.*, FactHospi3.cout from GestionHospi2@lien12, FactHospi3@lien13 where GestionHospi2.Pnum = FactHospi3.Pnum and GestionHospi2.Snum = FactHospi3.Snum and GestionHospi2.dateDebut = FactHospi3.dateDebut) union
(select GestionHospi3.*, FactHospi3.cout from GestionHospi3@lien13, FactHospi3@lien13 where GestionHospi3.Pnum = FactHospi3.Pnum and GestionHospi3.Snum = FactHospi3.Snum and GestionHospi3.dateDebut = FactHospi3.dateDebut);
