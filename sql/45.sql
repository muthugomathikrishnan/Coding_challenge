-- link :https://leetcode.com/problems/patients-with-a-condition/submissions/1741183196/?envType=study-plan-v2&envId=top-sql-50

-- Write your PostgreSQL query statement below
select patient_id,patient_name,conditions
from Patients
where conditions like '% DIAB1%'
or conditions like 'DIAB1%';
