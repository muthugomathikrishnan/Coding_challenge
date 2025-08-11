-- Write your PostgreSQL query statement below
select 'Low Salary' as category,count(*) as accounts_count
from Accounts
where income<20000

union 
select 'Average Salary', count(*)
from Accounts 
where income BETWEEN 20000 and 50000

union 

select 'High Salary' ,count(*)
from Accounts
where income> 50000
