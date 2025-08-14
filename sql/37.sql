-- Link :https://leetcode.com/problems/employees-whose-manager-left-the-company/submissions/1735227898/?envType=study-plan-v2&envId=top-sql-50
-- Write your MySQL query statement below
select employee_id 
from Employees
where salary<30000
and manager_id is not null
and manager_id not in (select employee_id from Employees)
order by employee_id;
