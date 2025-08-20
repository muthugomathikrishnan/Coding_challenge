-- Link : https://leetcode.com/problems/group-sold-products-by-the-date/submissions/1741525720/?envType=study-plan-v2&envId=top-sql-50

select sell_date, count(distinct product) as num_sold,
string_agg(distinct product,',')as products
from Activities 
group by sell_date
order by sell_date;
