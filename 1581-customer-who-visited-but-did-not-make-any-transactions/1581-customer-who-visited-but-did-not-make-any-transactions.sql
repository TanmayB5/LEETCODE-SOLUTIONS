# Write your MySQL query statement below
-- SELECT v.customer_id AS customer_id , SUM(DISTINCT t.transaction_id IS NULL) AS count_no_trans 
--     FROM visits v LEFT JOIN Transactions t 
--     ON v.visit_id = t.visit_id
--     GROUP BY v.customer_id 


SELECT v.customer_id, COUNT(DISTINCT v.visit_id) AS count_no_trans
FROM visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id;
