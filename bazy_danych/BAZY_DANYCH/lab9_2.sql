------9.1. Utw�rz trigger, kt�ry wpisuje do tabeli emp_gotrich numer pracownika, dat� zmiany, star� wyp�at� oraz
------now� wyp�at� kiedy nowa wyp�ata (salary) pracownika przekroczy 5000 (a poprzednia by�a mniejsza lub r�wna). 

CREATE OR REPLACE TRIGGER zad1 AFTER UPDATE of salary ON employees FOR EACH ROW
BEGIN
  IF (:NEW.salary>5000 and :OLD.salary<=5000) THEN
  INSERT INTO EMP_GOTRICH VALUES(:OLD.employee_id,SYSDATE,:OLD.salary,:NEW.salary);
  END IF;
END;

