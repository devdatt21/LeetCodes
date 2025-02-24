-- Write your PostgreSQL query statement below

select DISTINCT(author_id) as id
from Views as v
where v.author_id = v.viewer_id;