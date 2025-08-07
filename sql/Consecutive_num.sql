-- Link :https://leetcode.com/problems/consecutive-numbers/?envType=study-plan-v2&envId=top-sql-50

-- Sol 1 : without joins 


Select Distinct l1.num as ConsecutiveNums
from Logs l1,Logs l2, Logs l3
where 
    l1.id=l2.id+1 and l1.num=l2.num
    and
    l1.id=l3.id+2 and l1.num=l3.num

-- Sol 2 : with Joins


Select Distinct l1.num as ConsecutiveNums
from Logs l1
left join Logs l2 on l1.id=l2.id+1 and l1.num=l2.num
left join Logs l3 on l1.id=l3.id+2 and l1.num=l3.num
where l2.id is not null and l3.id is not null;


-- Better solution : Inner Joins

Select Distinct l1.num as ConsecutiveNums
from Logs l1
join Logs l2 on l1.id=l2.id+1 and l1.num=l2.num
join Logs l3 on l1.id=l3.id+2 and l1.num=l3.num

