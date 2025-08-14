-- link : https://leetcode.com/problems/exchange-seats/submissions/1735237089/?envType=study-plan-v2&envId=top-sql-50
-- Write your PostgreSQL query statement below
select case 
when id%2=1 and id+1 in (select id from Seat) then id+1
when id%2=0 then id-1
else id
end as id,student
from seat
order by id;
