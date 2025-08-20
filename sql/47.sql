-- link : https://leetcode.com/problems/second-highest-salary/?envType=study-plan-v2&envId=top-sql-50
 
select (select distinct salary 
from Employee
order by salary DESC
offset 1 limit 1) as SecondHighestSalary
