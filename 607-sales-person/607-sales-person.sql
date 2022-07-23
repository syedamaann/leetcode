# Write your MySQL query statement below

select name from salesperson where sales_id not in (select orders.sales_id from orders join company using (com_id) where company.name = "RED");

