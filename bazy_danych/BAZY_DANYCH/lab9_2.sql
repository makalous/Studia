------9.1. Utwórz trigger, który wpisuje do tabeli emp_gotrich numer pracownika, datê zmiany, star¹ wyp³atê oraz
------now¹ wyp³atê kiedy nowa wyp³ata (salary) pracownika przekroczy 5000 (a poprzednia by³a mniejsza lub równa). 

CREATE OR REPLACE TRIGGER zad1 AFTER UPDATE of salary ON employees FOR EACH ROW
BEGIN
  IF (:NEW.salary>5000 and :OLD.salary<=5000) THEN
  INSERT INTO EMP_GOTRICH VALUES(:OLD.employee_id,SYSDATE,:OLD.salary,:NEW.salary);
  END IF;
END;

