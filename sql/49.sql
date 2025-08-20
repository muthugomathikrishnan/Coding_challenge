-- link : https://leetcode.com/problems/list-the-products-ordered-in-a-period/submissions/1742002400/?envType=study-plan-v2&envId=top-sql-50

-- Write your PostgreSQL query statement below
select product_name ,sum(unit) as unit
from Products p 
join Orders o
on p.product_id=o.product_id
 where o.order_date between '2020-02-01' and 
 '2020-02-29'
 group by product_name
 having sum(o.unit)>=100
 order by unit desc;
