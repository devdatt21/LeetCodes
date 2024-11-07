-- Write your PostgreSQL query statement below

select e.name, b.bonus
from Employee as e 
FULL JOIN Bonus as b 
on e.empId=b.empId
where b.bonus IS NULL or b.bonus<1000;