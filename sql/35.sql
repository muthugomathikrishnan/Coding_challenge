
select q1.person_name
from Queue q1
join Queue q2
on q2.turn<=q1.turn
group by q1.person_name
having sum(q2.weight)<=1000
order by sum(q2.weight) Desc
limit 1;
