CREATE OR REPLACE TRIGGER zad2 before UPDATE of department_id ON employees FOR EACH ROW
BEGIN
  :NEW.salary:=:OLD.salary*(1.1);
END;



