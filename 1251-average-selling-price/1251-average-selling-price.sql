/* Write your T-SQL query statement below */
select p.product_id, 
    case when count(u.product_id) = 0 then 0 
    else ROUND(CONVERT(float, sum(p.price * u.units)) / sum(u.units), 2) 
    end as average_price
from Prices p
left join UnitsSold u
    on p.product_id = u.product_id
    and p.start_date <= u.purchase_date
    and p.end_date >= u.purchase_date
group by p.product_id