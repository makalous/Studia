--2.1
select distinct JOB_ID , manager_id from employees where manager_id=100 or manager_id=102;
--2.2
select last_name, salary from employees where manager_id=100 and salary>10000 order by salary DESC;
--2.3
select last_name "Nazwisko" ,salary "Zarobki" ,job_id "Numer stanowiska" from employees where job_id LIKE '%MGR' order by salary DESC;
-- 2.4
select job_id "Numer stanowiska", job_title "Nazwa stanowiska" from jobs where REGEXP_LIKE(job_title,' ');
--2.5 
-- Numerów (employee_id), wyplat (salary) oraz kodów stanowisk (job_id) pracowników, których wyp³ata wynosi ponad 3000 oraz kod stanowiska rozpoczyna siê od "ST" lub "SH", posortowanych rosn¹co pod wzglêdem numeru pracownika. (tabela employees -> 23 rows, 3 columns)
select employee_id, salary, job_id from employees where salary >3000 and (job_id LIKE 'ST%' or job_id LIKE 'SH%') order by employee_id ASC;
--2.6
select distinct job_id, count(*) from employees group by job_id order by  count (*) DESC;
--2.7
select MANAGER_ID, MAX(salary) from employees where salary >1 GROUP BY MANAGER_ID ORDER BY MAX(salary);
--2.8
SELECT job_id "numer stanowiska", AVG(salary) "œrednia wyplata" FROM employees GROUP BY job_id ORDER BY AVG(salary) DESC;
--2.9
SELECT job_id "numer stanowiska", count(*) "iloœæ pracowników", AVG(salary) "œrednia wypata", MAX(salary) "maks wypata", MIN(salary) "minim wypata" FROM employees where salary>5000 GROUP BY job_id ORDER BY MIN(salary) DESC;
--2.10
select MANAGER_ID, AVG(salary) from employees where salary >5000 and MANAGER_ID is not null GROUP BY Manager_id ORDER BY MANAGER_ID;
