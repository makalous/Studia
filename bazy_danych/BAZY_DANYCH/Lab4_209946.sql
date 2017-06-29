UPDATE employees SET salary=5001 WHERE department_id=10;
select * from EMP_GOTRICH;


--1
SELECT last_name,department_name,city 
from departments  
full outer join employees using (department_id)
right outer join locations using (location_id);
--2
SELECT department_name,count(*) FROM departments natural join employees group by department_name having count(*)>5 ;
--3
SELECT a.department_name,count(*) FROM departments a, employees c where a.department_id=c.department_id group by a.department_name having count(*)>5 ;
--4
SELECT last_name, ROUND( 100*(salary/((min_salary+max_salary)/2)),0) "Placa Ustalona" FROM employees natural JOIN jobs order by "Placa Ustalona" DESC;
--5
select a.department_name, count(*) from employees h natural join departments a natural join jobs c where 100*(h.salary/c.max_salary)>80  group by a.department_name;
--6
select department_name,count(*),round(100*(max(salary)-min(salary))/(avg(salary)*2),2) from departments join employees using (department_id) group by department_name;
--7
select last_name, hire_date from employees where hire_date < 
(
select hire_date from employees where employee_id=123
);
 
