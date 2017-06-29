--select * from departments;
UPDATE departments SET manager_id=121 WHERE department_id=10;
select * from dept_changes;

UPDATE employees SET salary=5001 WHERE department_id=10;
select * from EMP_GOTRICH;

select * from employees;

select salary from employees where job_id='IT_PROG';
update employees set department_id=90 where job_id='IT_PROG';
select salary from employees where job_id='IT_PROG';


----------------------------------------------------lab7
--1)
CREATE TABLE studenci
(
numer_indeksu NUMBER (6,0) primary key,
imie VARCHAR2(16) not null,
nazwisko VARCHAR2(32) not null,
data_ur DATE,
srednia_ocen number (2,1) CHECK(srednia_ocen>=2.0 and srednia_ocen<=5.5),
plec char(1) check (plec='F' or plec='M') not null
);
--2)
--------------------------------------------------------------------------
insert into studenci
(numer_indeksu,imie,nazwisko,data_ur,srednia_ocen,plec)
values (209946,'Maks','Iwanow','1994-10-08',3.7,'M');

insert into studenci
(numer_indeksu,imie,nazwisko,data_ur,srednia_ocen,plec)
values (210021,'Gra¿yna','¯arko','1995-11-18',4.0,'F');
--3)
---------------------------------------------------
ALTER TABLE studenci MODIFY srednia_ocen  DEFAULT 5.5;
------------------------------------------------------------
--4)
CREATE VIEW stud_view AS
SELECT srednia_ocen FROM studenci where plec = 'F' GROUP BY srednia_ocen;
--5)
---------------------------------
DROP TABLE studenci;
DROP VIEW stud_view;
--select * from studenci;
--select * from stud_view;
---------------------------------------------------------------------------
--insert into studenci
--(numer_indeksu,imie,nazwisko,data_ur,plec)
--values (210862,'a','b','1995-11-18','F');
--select * from studenci;














--1
SELECT last_name,salary FROM employees WHERE salary > (9/10)*(SELECT salary FROM employees WHERE last_name='Chen');
--2

SELECT distinct last_name, department_name, salary FROM employees join departments using(department_id) WHERE salary > ALL (SELECT salary FROM employees join departments using (department_id) WHERE department_name='Marketing');
--3

SELECT department_name, count(*) FROM departments join employees using(department_id) group by department_name having count (*) > (SELECT count(*) FROM employees join departments using(department_id ) where department_name='IT') ;

--4
select last_name,salary,"pracownicy" from employees join (select manager_id "kkk" ,count (*) "pracownicy" from employees group by MANAGER_ID )on (employees.employee_id="kkk");

--Wyœwietl ilu jest pracowników w ramach poszczególnych job_id. Wyœwietl tylko te job_id, gdzie jest wiêcej ni¿ 5 pracowników.
select job_id,count(*) from employees group by job_id having count(*)>5;

-----------------------------------------LAB6

--INSERT INTO employees (department_id, department_name) VALUES (280,'Studenci');
insert into employees
(EMPLOYEE_ID,LAST_NAME,EMAIL,HIRE_DATE,JOB_ID,MANAGER_ID)
values (10,'AAA','BBB','1992-10-11','SA_MAN',(SELECT manager_id from EMPLOYEES WHERE LAST_NAME='Chung'));
update employees SET SALARY=(SELECT avg(salary) FROM EMPLOYEES WHERE LAST_NAME LIKE 'K%') where EMPLOYEE_ID=10;


UPDATE EMPLOYEES SET SALARY = (SELECT AVG(SALARY)FROM EMPLOYEES WHERE LAST_NAME LIKE 'K%')WHERE EMPLOYEE_ID=10;

SELECT EMPLOYEE_ID, LAST_NAME, SALARY FROM EMPLOYEES WHERE EMPLOYEE_ID = 10;
DELETE FROM EMPLOYEES WHERE PHONE_NUMBER=NULL;

