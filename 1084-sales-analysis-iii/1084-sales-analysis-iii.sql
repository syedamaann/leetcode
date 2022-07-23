# Write your MySQL query statement below

SELECT distinct product_id, product_name
FROM product
INNER JOIN sales
using (product_id)
WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-3'
AND product_id NOT IN 
    (SELECT product_id 
     FROM sales 
     WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31')

