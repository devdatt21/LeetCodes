-- Write your PostgreSQL query statement below

select s.student_id, s.student_name,su.subject_name, COUNT(e.student_id) as attended_exams
from Students s
cross join Subjects su
LEFT JOIN Examinations e
ON s.student_id = e.student_id and 
su.subject_name = e.subject_name

GROUP by s.student_id, su.subject_name, s.student_name
order by s.student_id, s.student_name, su.subject_name;