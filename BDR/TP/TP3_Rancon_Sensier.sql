/* Rendu du tp3 de MIF37 */

/* Marie Rancon p1309458 */
/* Antoine Sensier p1208892 */

/* Importation de la base de données de Belfort */
/* Sur Orapeda 3 */
create table B_Service as
(select * from BDENS.B_Service);

create table B_Salle as
(select * from BDENS.B_Salle);

create table B_Infirmier as
(select * from BDENS.B_Infirmier);

create table B_Docteur as
(select * from BDENS.B_Docteur);

create table B_Patient as
(select * from BDENS.B_Patient);

create table B_Acte as
(select * from BDENS.B_Acte);

create table B_Hospi as
(select * from BDENS.B_Hospi);

create table B_Frais as
(select * from BDENS.B_Frais);

/* Question 1 */
/* Sur Orapeda 3 */
create view Service4 (Snum,Nom,hopital,bat,tel,directeur) as
(select cast(Snum as NUMBER)+10000,Nom,'Belfort',Batiment as bat,null,null from B_Service);

create view Salle4(Snum,SAnum,surveillant,nblits) as
(select cast(Snum as NUMBER)+10000,cast(Sanum as NUMBER), null,nblits from B_Salle);

create view Infirmier4(inum,snum,rotation,salaire) as
(select cast(substr(icode,instr(icode,'_')+1) as NUMBER)+25000 as inum,cast(snum as NUMBER)+10000,null,salaire/1000.0 from B_Infirmier);

create view Docteur4(dnum,spec) as
(select cast(substr(dcode,instr(dcode,'_')+1) as NUMBER)+30000 as dnum,specialite as spec from B_Docteur);

create view Employe4(Enum,nom,adr,tel) as
(select cast(substr(icode,instr(icode,'_')+1) as NUMBER)+25000 as enum, nom,adr, tel from b_infirmier
union 
select cast(substr(dcode,instr(dcode,'_')+1) as NUMBER)+30000 as enum, nom,adr,tel from b_docteur);

create view Patient4 (Pnum,nom,prenom,adr,tel,mutuelle,priseencharge) as
(select p.pnum*(-1),substr(nomprenom,0,instr(nomprenom,' ')-1) as nom, substr(nomprenom,instr(nomprenom,' ')+1) as prenom , adresse as adr, telephone as tel, f.mutuelle,f.pcharge 
from B_Patient p, B_Frais f
where p.pnum=f.pnum);

create view Hospi4(pnum,snum,datedebut,nbjours,sanum,lit,cout) as
(select h.pnum*(-1), h.snum+10000, h.datesortie-h.nbjours, h.nbjours, h.sanum,h.numlit, f.cout
from B_Hospi h , B_Frais f
where h.pnum=f.pnum
and h.snum = f.snum
and h.datesortie= f.datesortie);

create view acte4 (dnum,pnum,dateacte,description,cat) as
(select cast(substr(dcode,instr(dcode,'_')+1) as NUMBER)+30000 as dnum,pnum*(-1), dateacte,description,code
from B_Acte);

/* Question 2 */
/* Sur Orapeda 2 */
create view VSalle as
(select * from Salle3@lien23)
union
(select snum,sanum,cast(surveillant as NUMBER),nblits from Salle4@lien23);

create view VService as
(select * from Service3@lien23)
union
(select snum,nom,hopital,bat,cast(tel as NUMBER),directeur from Service4@lien23);

create view VEmploye as
(select * from Employe3@lien23)
union
(select * from Employe3@lien23);

create view VDocteur as
(select * from Docteur3@lien23)
union
(select * from Docteur4@lien23);

create view VInfirmier as
(select * from Infirmier3@lien23)
union
(select * from Infirmier4@lien23);

create view VPatient as
(select i.*,f.mutuelle, f.priseencharge from InfosPatient3@lien23 i, FactPatient3@lien23 f where i.pnum=f.pnum)
union
(select * from Patient4@lien23);

create view VHospi as
(select g.pnum,g.snum, g.datedebut, g.nbjours, g.sanum, g.lit,f.cout from GestionHospi3@lien23 g, FactHospi3@lien23 f where g.pnum=f.pnum and g.snum=f.snum and g.datedebut=f.datedebut)
union
(select pnum,snum,datedebut,nbjours,cast(sanum as number),lit,cout from Hospi4@lien23);

create view VActe (dnum,pnum,dateacte,description,cat) as
(select dnum, pnum, dateacte, description, cat from Acte3@lien23)
union
(select dnum, pnum, cast(dateacte as timestamp), description,cat from Acte4@lien23);





