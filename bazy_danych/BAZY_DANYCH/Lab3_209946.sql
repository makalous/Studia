--1,2
SELECT d.department_name,l.last_name,l.salary FROM departments d, employees l WHERE l.salary>12000 and l.department_id=d.department_id;
SELECT d.department_name,l.last_name, l.salary FROM employees l JOIN departments d ON l.salary>12000 and l.department_id=d.department_id;
--3,4
SELECT d.last_name, l.department_name, c.city FROM employees d, departments l, locations c where l.location_id=c.location_id and l.department_id=d.department_id;
SELECT d.last_name, l.department_name, c.city FROM employees d join departments l on l.department_id=d.department_id join locations c on l.location_id=c.location_id;
--5
select d.department_name, count (*)  from departments d , employees l where d.department_id=l.department_id group by d.department_name;
--6*
select d.country_name, count (*)  from countries d , employees l, departments f, locations g where l.department_id=f.department_id and f.location_id=g.location_id and g.country_id=d.country_id  group by d.country_name;
--7**
select e1.last_name "Pracownicy", e2.last_name "Kierownicy" from employees e1, employees e2 where e1.employee_id=e2.manager_id order by "Kierownicy" ASC ;

SELECT department_name,last_name,salary FROM departments d, employees l WHERE salary>12000 and d.department_id=l.department_id;

SELECT last_name, department_name, city FROM employees d, departments l, locations c 
where l.location_id=c.location_id and l.department_id=d.department_id;
