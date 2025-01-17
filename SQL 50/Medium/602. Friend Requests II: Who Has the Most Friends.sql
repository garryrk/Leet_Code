# Write your MySQL query statement below
with table2 as (
    select requester_id as id
    from requestAccepted
    union all
    select accepter_id as id
    from requestAccepted
)

select id,
count(id) as num
from table2
group by id
order by count(id) desc
limit 1
