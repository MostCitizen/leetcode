# Write your MySQL query statement below
select a.name
from Employee a
right join Employee b
on b.managerId = a.id
where a.id is not null
group by a.id
HAVING COUNT(b.id) >=5