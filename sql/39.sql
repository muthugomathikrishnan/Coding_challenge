-- Link  : https://leetcode.com/problems/movie-rating/submissions/1735671351/?envType=study-plan-v2&envId=top-sql-50
(
select name as results
from  MovieRating
join Users
using(user_id)
group by name
order by count(*) Desc,name
limit 1
)

union all

(
select title as results
from MovieRating
join Movies 
using (movie_id)
where to_char(created_at,'YYYYMM')='202002'
group by title
order by AVG(rating) desc,title
limit 1

);
