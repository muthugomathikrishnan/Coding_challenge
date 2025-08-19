-- Link :https://leetcode.com/problems/fix-names-in-a-table/?envType=study-plan-v2&envId=top-sql-50

select  user_id,concat(upper(left(name,1)),lower(substring(name,2))) as name
from Users 
order by user_id ASC;
