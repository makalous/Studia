CREATE TABLE emp_gotrich ( emp_id NUMBER(6), raise_date DATE, old_sal NUMBER(8,2), new_sal NUMBER(8,2) );
CREATE TABLE emp_count ( ilosc NUMBER(5), data DATE );
CREATE TABLE emp_promoted ( emp_id NUMBER(6), prom_date DATE );
CREATE TABLE dept_changes ( data DATE, akcja VARCHAR2(16) );



-----------------------------3
-----Utw�rz trigger, kt�ry wprowadza do tabeli dept_changes dat� oraz informacj� 
--o typie zmiany wprowadzonej na tabeli departments poprzez UPDATE, INSERT lub DELETE (wpisuj�c w kolumnie akcja warto�� upd, ins lub del).
CREATE OR REPLACE TRIGGER cokis AFTER UPDATE OR INSERT OR DELETE ON departments
DECLARE
  akcja VARCHAR2(16);
BEGIN
  IF UPDATING THEN
    akcja:='upd';
  END IF;
  IF INSERTING THEN
    akcja:='ins';
  END IF;
  IF DELETING THEN
    akcja:='del';
  END IF;
  INSERT INTO dept_changes VALUES( SYSDATE, akcja );
END;


