/* Write your T-SQL query statement below */
select today.id
from Weather yesterday
cross join Weather today
where DATEDIFF(DAY, yesterday.recordDate, today.recordDate) = 1
    and today.temperature > yesterday.temperature