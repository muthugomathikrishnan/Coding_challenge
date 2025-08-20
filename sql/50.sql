-- Link : https://leetcode.com/problems/find-users-with-valid-e-mails/submissions/1742009134/?envType=study-plan-v2&envId=top-sql-50

select *
from Users
where mail ~'^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$'
