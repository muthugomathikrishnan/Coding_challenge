-- Link : https://leetcode.com/problems/restaurant-growth/?envType=study-plan-v2&envId=top-sql-50


with daily_total as(select visited_on ,sum(amount) as amount from Customer group by visited_on )

select a.visited_on,sum(b.amount) as amount ,round(sum(b.amount)/7.0,2)as average_amount
from daily_total a
join daily_total b
on b.visited_on between a.visited_on -INTERVAL '6 days' and a.visited_on
group by a.visited_on 
having count(b.visited_on)=7
order by a.visited_on


