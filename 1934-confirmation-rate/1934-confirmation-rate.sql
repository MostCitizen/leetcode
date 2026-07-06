/* Write your T-SQL query statement below */
select a.user_id, ROUND(
        ISNULL(
            CAST(SUM(CASE WHEN b.action = 'confirmed' THEN 1 ELSE 0 END) AS FLOAT)
            / NULLIF(COUNT(b.user_id), 0),
            0
        ), 2
    ) AS confirmation_rate
from Signups a
left join Confirmations b
    on a.user_id = b.user_id
group by a.user_id
