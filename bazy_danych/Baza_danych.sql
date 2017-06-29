CREATE TABLE denaci
(
pesel_denata NUMBER (11,0) primary key,
imie_denata VARCHAR2(32) not null,
nazwisko_denata VARCHAR2(32) not null,
plec_denata char(1) check (plec_denata='K' or plec_denata='M') not null,
praca_denata VARCHAR2 (32) not null,
data_ur DATE not null,
data_sm DATE not null
);
CREATE TABLE pracownicy
(
pesel_pracownika NUMBER (11,0) primary key,
imie_pracownika VARCHAR2(32) not null,
nazwisko_pracownika VARCHAR2(32) not null,
plec_pracownika char(1) check (plec_pracownika='K' or plec_pracownika='M') not null,
zarobki_pracownika NUMBER(6,2) not null,
data_zat DATE not null,
data_zwol DATE default '2055-02-01'
);
create table regiony
(
kod_pocztowy NUMBER(5,0) primary key,
miasto VARCHAR2(32) not null,
panstwo VARCHAR2(32) not null
);
create table zaklady
(
id_zakladu NUMBER (4,0) primary key,
kod_pocztowy NUMBER(5,0) not null,
CONSTRAINT kod_pocztowy FOREIGN KEY (kod_pocztowy) REFERENCES regiony (kod_pocztowy)
);
CREATE TABLE sprawy
(
id_sprawy NUMBER(5,0) primary key,
id_zakladu NUMBER (4,0) not null,
data_realizacji DATE,
czy_zakonczona char(1) check (czy_zakonczona='T' or czy_zakonczona='N') not null,
pesel_denata NUMBER (11,0) not null,
pesel_pracownika NUMBER (11,0) not null,
CONSTRAINT pesel_denata FOREIGN KEY (pesel_denata) REFERENCES denaci (pesel_denata),
CONSTRAINT pesel_pracownika FOREIGN KEY (pesel_pracownika) REFERENCES pracownicy (pesel_pracownika),
CONSTRAINT id_zakladu FOREIGN KEY (id_zakladu) REFERENCES zaklady (id_zakladu)

);
create table platnosci
(
id_rachunku NUMBER(6,0) primary key,
id_sprawy NUMBER(5,0) not null,
cena NUMBER (6,2) not null,
czy_przelewem char(1) check (czy_przelewem='T' or czy_przelewem='N') not null,
CONSTRAINT id_sprawy FOREIGN KEY (id_sprawy) REFERENCES sprawy (id_sprawy)
);

insert into denaci
(pesel_denata,imie_denata,nazwisko_denata,plec_denata,praca_denata,data_ur,data_sm)
values (94110816765,'Ryszard','Butwock','M','Lekarz','1994-11-08','2015-08-09');
insert into denaci
(pesel_denata,imie_denata,nazwisko_denata,plec_denata,praca_denata,data_ur,data_sm)
values (87060789109,'Gra¿yna','Konowal','K','Piekarz','1987-06-07','2014-11-19');
insert into denaci
(pesel_denata,imie_denata,nazwisko_denata,plec_denata,praca_denata,data_ur,data_sm)
values (43051598654,'Michal','Bialek','M','Programista','1943-05-15','2014-12-09');
insert into denaci
(pesel_denata,imie_denata,nazwisko_denata,plec_denata,praca_denata,data_ur,data_sm)
values (76081154032,'Halina','Frackowiak','K','Posel','1976-08-11','2013-02-01');


insert into pracownicy
(pesel_pracownika,imie_pracownika,nazwisko_pracownika,plec_pracownika,zarobki_pracownika,data_zat)
values (90080576143,'Karel','Onkelbaum','M',2059.76,'2000-10-15');
insert into pracownicy
(pesel_pracownika,imie_pracownika,nazwisko_pracownika,plec_pracownika,zarobki_pracownika,data_zat,data_zwol)
values (87060789654,'Dominika','Werter','K',2059.76,'2011-07-11','2012-08-09');
insert into pracownicy
(pesel_pracownika,imie_pracownika,nazwisko_pracownika,plec_pracownika,zarobki_pracownika,data_zat)
values (59080276549,'Karolina','Kowalska','K',2059.76,'2002-12-08');
insert into pracownicy
(pesel_pracownika,imie_pracownika,nazwisko_pracownika,plec_pracownika,zarobki_pracownika,data_zat)
values (68111123456,'Maciej','Kielecki','M',2059.76,'1999-06-19');


insert into regiony
(kod_pocztowy,miasto,panstwo)
values (50876,'Wroclaw','Polska');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (11876,'Bialystok','Polska');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (23675,'Warszawa','Polska');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (08976,'Praga','Czechy');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (76890,'Szczecin','Polska');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (15156,'Cieszyn','Polska');

insert into regiony
(kod_pocztowy,miasto,panstwo)
values (56098,'Wroclaw','Polska');



insert into zaklady
(id_zakladu,kod_pocztowy)
values (0076,56098);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (0054,15156);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (0187,76890);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (2034,08976);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (0011,23675);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (0099,11876);

insert into zaklady
(id_zakladu,kod_pocztowy)
values (0002,50876);



insert into sprawy
(id_sprawy,pesel_denata,pesel_pracownika,id_zakladu,data_realizacji,czy_zakonczona)
values (00435,94110816765,90080576143,0002,'2015-08-12','T');
insert into sprawy
(id_sprawy,pesel_denata,pesel_pracownika,id_zakladu,data_realizacji,czy_zakonczona)
values (01098,87060789109,90080576143,0002,'2014-11-24','T');
insert into sprawy
(id_sprawy,pesel_denata,pesel_pracownika,id_zakladu,data_realizacji,czy_zakonczona)
values (01102,43051598654,68111123456,0011,'2014-12-15','T');

insert into platnosci(id_rachunku,id_sprawy,cena,czy_przelewem)
values
(234001,00435,4500.76,'N');
insert into platnosci(id_rachunku,id_sprawy,cena,czy_przelewem)
values
(000752,01098,5270.00,'T');
insert into platnosci(id_rachunku,id_sprawy,cena,czy_przelewem)
values
(870921,01102,3298.21,'T');

CREATE TABLE zmiana_sprawy 
(  
data_zmiany DATE,
zmiana VARCHAR2(16)
);

CREATE OR REPLACE TRIGGER z_sprawy AFTER UPDATE OR INSERT OR DELETE ON sprawy
DECLARE
  akcja VARCHAR2(16);
BEGIN
  IF UPDATING THEN
    akcja:='AKTUALIZACJA';
  END IF;
  IF INSERTING THEN
    akcja:='WSTAWIENIE';
  END IF;
  IF DELETING THEN
    akcja:='USUNIÊCIE';
  END IF;
  INSERT INTO zmiana_sprawy VALUES( SYSDATE, akcja );
END;



