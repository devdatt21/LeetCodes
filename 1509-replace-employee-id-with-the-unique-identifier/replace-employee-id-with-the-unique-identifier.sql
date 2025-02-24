-- Write your PostgreSQL query statement below
select eu.unique_id as unique_id, e.name as name 
from Employees as e
LEFT JOIN EmployeeUNI as eu
ON e.id=eu.id;