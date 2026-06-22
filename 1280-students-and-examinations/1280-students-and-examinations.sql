# Write your MySQL query statement below
select a.student_id, a.student_name, b.subject_name, 
COUNT(c.student_id) attended_exams
from Students a
cross join Subjects b
left join Examinations c 
    on c.student_id = a.student_id 
    and c.subject_name = b.subject_name
group by a.student_id, a.student_name, b.subject_name
order by a.student_id, b.subject_name
