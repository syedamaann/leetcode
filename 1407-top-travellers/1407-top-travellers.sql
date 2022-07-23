# Write your MySQL query statement below

select users.name as name, ifnull(sum(rides.distance),0) as travelled_distance from users left join rides on users.id = rides.user_id group by user_id order by sum(rides.distance) desc,users.name asc; 

