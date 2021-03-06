--------------------------------------------------------
--  File created - czwartek-kwietnia-30-2015   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Sequence SEKWENCJA_1
--------------------------------------------------------

   CREATE SEQUENCE  "SEKWENCJA_1"  MINVALUE 1 MAXVALUE 9000 INCREMENT BY 15 START WITH 20 NOCACHE  NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table MOTYWY
--------------------------------------------------------

  CREATE TABLE "MOTYWY" 
   (	"STYL" NUMBER(1,0), 
	"GRAFIKA" VARCHAR2(16 BYTE), 
	"KOLOR" VARCHAR2(16 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Table UPRAWNIENIA
--------------------------------------------------------

  CREATE TABLE "UPRAWNIENIA" 
   (	"TYP" NUMBER(1,0), 
	"GRUPA" VARCHAR2(16 BYTE), 
	"POZIOM_DOSTEPU" VARCHAR2(16 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  DDL for Table UZYTKOWNICY
--------------------------------------------------------

  CREATE TABLE "UZYTKOWNICY" 
   (	"ID" NUMBER(5,0), 
	"NAZWA" VARCHAR2(32 BYTE), 
	"HASLO" VARCHAR2(32 BYTE), 
	"STYL" NUMBER(1,0), 
	"TYP" NUMBER(1,0)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
REM INSERTING into MOTYWY
SET DEFINE OFF;
Insert into MOTYWY (STYL,GRAFIKA,KOLOR) values ('0','INK_G','ZIELONY');
Insert into MOTYWY (STYL,GRAFIKA,KOLOR) values ('8','MET_G','NIEBIESKI');
Insert into MOTYWY (STYL,GRAFIKA,KOLOR) values ('2','OFF_G','ZIELONY');
REM INSERTING into UPRAWNIENIA
SET DEFINE OFF;
Insert into UPRAWNIENIA (TYP,GRUPA,POZIOM_DOSTEPU) values ('9','OP_RST','P_DW');
Insert into UPRAWNIENIA (TYP,GRUPA,POZIOM_DOSTEPU) values ('7','FH_ISK','P_CZ');
Insert into UPRAWNIENIA (TYP,GRUPA,POZIOM_DOSTEPU) values ('5','AB_BA','P_PI');
REM INSERTING into UZYTKOWNICY
SET DEFINE OFF;
Insert into UZYTKOWNICY (ID,NAZWA,HASLO,STYL,TYP) values ('20201','AESCOB','qwerty1','0','1');
Insert into UZYTKOWNICY (ID,NAZWA,HASLO,STYL,TYP) values ('20987','SOUKEN','ahljob0','8','5');
Insert into UZYTKOWNICY (ID,NAZWA,HASLO,STYL,TYP) values ('19800','BERNA','1ajden9','2','2');
--------------------------------------------------------
--  DDL for Index IND_NAZWA
--------------------------------------------------------

  CREATE INDEX "IND_NAZWA" ON "UZYTKOWNICY" ("NAZWA") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  Constraints for Table MOTYWY
--------------------------------------------------------

  ALTER TABLE "MOTYWY" MODIFY ("GRAFIKA" NOT NULL ENABLE);
  ALTER TABLE "MOTYWY" MODIFY ("KOLOR" NOT NULL ENABLE);
  ALTER TABLE "MOTYWY" ADD PRIMARY KEY ("STYL")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  Constraints for Table UZYTKOWNICY
--------------------------------------------------------

  ALTER TABLE "UZYTKOWNICY" MODIFY ("NAZWA" NOT NULL ENABLE);
  ALTER TABLE "UZYTKOWNICY" MODIFY ("HASLO" NOT NULL ENABLE);
  ALTER TABLE "UZYTKOWNICY" ADD PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  Constraints for Table UPRAWNIENIA
--------------------------------------------------------

  ALTER TABLE "UPRAWNIENIA" MODIFY ("GRUPA" NOT NULL ENABLE);
  ALTER TABLE "UPRAWNIENIA" MODIFY ("POZIOM_DOSTEPU" NOT NULL ENABLE);
  ALTER TABLE "UPRAWNIENIA" ADD PRIMARY KEY ("TYP")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
--------------------------------------------------------
--  DDL for Synonymn S_MO
--------------------------------------------------------

  CREATE OR REPLACE SYNONYM "S_MO" FOR "MOTYWY";
--------------------------------------------------------
--  DDL for Synonymn S_UP
--------------------------------------------------------

  CREATE OR REPLACE SYNONYM "S_UP" FOR "UPRAWNIENIA";
--------------------------------------------------------
--  DDL for Synonymn S_UZ
--------------------------------------------------------

  CREATE OR REPLACE SYNONYM "S_UZ" FOR "UZYTKOWNICY";
