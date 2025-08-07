-- link : https://leetcode.com/problems/product-price-at-a-given-date/?envType=study-plan-v2&envId=top-sql-50
-- Sol 1 : using Coalesce
Select distinct p.product_id,
Coalesce(
    (select sub.new_price
    from Products sub
    where sub.product_id=p.product_id
    and 
    sub.change_date <= '2019-08-16'
    order by sub.change_date Desc
    limit 1
    ),10) as price 
from Products as p;


-- Sol 2: 
