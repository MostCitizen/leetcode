/* Write your T-SQL query statement below */
select machine_id, ROUND(sum(a.timestamp) / count(a.timestamp), 3) processing_time
from (select a.machine_id, b.timestamp - a.timestamp timestamp
    from Activity a
    join Activity b
    on a.machine_id = b.machine_id
        and a.process_id = b.process_id
    where a.activity_type = 'start'
        and b.activity_type = 'end'
) a
group by machine_id