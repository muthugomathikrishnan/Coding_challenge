-- link :https://leetcode.com/problems/department-top-three-salaries/?envType=study-plan-v2&envId=top-sql-50
-- Write your PostgreSQL query statement below
select d.name Department,e.name Employee,e.salary
from Employee e
join Department d
on e.departmentId=d.id
where (
    select count(distinct(e2.salary))
    From Employee e2
    where e.departmentId=e2.departmentId and e2.salary>e.salary
)<3;
