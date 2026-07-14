/* Write your T-SQL query statement below */
DECLARE @count INT;
select @count = count(user_id)
from users

select r.contest_id, round(cast(count(r.user_id) as decimal(10, 2)) / @count * 100, 2) as percentage
from users u
join register r
on u.user_id = r.user_id
group by r.contest_id
order by percentage desc, r.contest_id asc