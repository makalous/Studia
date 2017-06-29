CREATE TABLE uprawnienia
(
typ NUMBER (1,0) primary key,
grupa VARCHAR2(16) not null,
poziom_dostepu VARCHAR2(16) not null
);
CREATE TABLE motywy
(
styl NUMBER (1,0) primary key,
grafika VARCHAR2(16) not null,
kolor VARCHAR2(16) not null
);
CREATE TABLE uzytkownicy
(
ID NUMBER (5,0) primary key,
nazwa VARCHAR2(32) not null,
haslo VARCHAR2(32) not null,
styl NUMBER (1,0),
typ NUMBER (1,0)
);

insert into uprawnienia
(typ,grupa,poziom_dostepu)
values (9,'OP_RST','P_DW');
insert into uprawnienia
(typ,grupa,poziom_dostepu)
values (7,'FH_ISK','P_CZ');
insert into uprawnienia
(typ,grupa,poziom_dostepu)
values (5,'AB_BA','P_PI');

insert into motywy
(styl,grafika,kolor)
values (0,'INK_G','ZIELONY');
insert into motywy
(styl,grafika,kolor)
values (8,'MET_G','NIEBIESKI');
insert into motywy
(styl,grafika,kolor)
values (2,'OFF_G','ZIELONY');

insert into uzytkownicy
(ID,nazwa,haslo,styl,typ)
values (20201,'AESCOB','qwerty1',0,1);
insert into uzytkownicy
(ID,nazwa,haslo,styl,typ)
values (20987,'SOUKEN','ahljob0',8,5);
insert into uzytkownicy
(ID,nazwa,haslo,styl,typ)
values (19800,'BERNA','1ajden9',2,2);

------------------------------------------

CREATE INDEX ind_nazwa ON uzytkownicy(nazwa);
CREATE SYNONYM s_uz FOR uzytkownicy;
CREATE SYNONYM s_mo FOR motywy;
CREATE SYNONYM s_up FOR uprawnienia;

CREATE SEQUENCE sekwencja_1
INCREMENT BY 5
START WITH 10
MAXVALUE 9000
NOCACHE
NOCYCLE;

ALTER SEQUENCE sekwencja_1
INCREMENT BY 15
;
DROP TABLE motywy;
DROP table uprawnienia;
DROP TABLE uzytkownicy;
DROP SEQUENCE sekwencja_1;
DROP INDEX ind_nazwa;
drop SYNONYM s_uz;
drop SYNONYM s_up;
drop SYNONYM s_mo;

